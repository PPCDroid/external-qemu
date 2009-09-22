/* Copyright (C) 2007-2008 The Android Open Source Project
** Copyright (C) 2009 Embedded Alley Solutions Inc
**
** This software is licensed under the terms of the GNU General Public
** License version 2, as published by the Free Software Foundation, and
** may be copied, distributed, and modified under those terms.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/
#include "qemu_file.h"
#include "qemu-char.h"

enum {
    TTY_PUT_CHAR       = 0x00,
    TTY_BYTES_READY    = 0x04,
    TTY_CMD            = 0x08,

    TTY_DATA_PTR       = 0x10,
    TTY_DATA_LEN       = 0x14,

    TTY_CMD_INT_DISABLE    = 0,
    TTY_CMD_INT_ENABLE     = 1,
    TTY_CMD_WRITE_BUFFER   = 2,
    TTY_CMD_READ_BUFFER    = 3,
};

struct tty_state {
    CharDriverState *cs;
    uint32_t ptr;
    uint32_t ptr_len;
    uint32_t ready;
    uint32_t data_count;
    uint32_t base;
    int size;
    qemu_irq irq;
    int irq_count;
    uint8_t data[128];
};

static void  silverbox_tty_save(QEMUFile*  f, void*  opaque)
{
    struct tty_state*  s = opaque;

    qemu_put_be32( f, s->ptr );
    qemu_put_be32( f, s->ptr_len );
    qemu_put_byte( f, s->ready );
    qemu_put_byte( f, s->data_count );
    qemu_put_buffer( f, s->data, s->data_count );
}

static int  silverbox_tty_load(QEMUFile*  f, void*  opaque, int  version_id)
{
    struct tty_state*  s = opaque;

    if (version_id != 1)
        return -1;

    s->ptr        = qemu_get_be32(f);
    s->ptr_len    = qemu_get_be32(f);
    s->ready      = qemu_get_byte(f);
    s->data_count = qemu_get_byte(f);
    qemu_get_buffer(f, s->data, s->data_count);

    return 0;
}

static uint32_t silverbox_tty_read(void *opaque, target_phys_addr_t offset)
{
    struct tty_state *s = (struct tty_state *)opaque;
    offset -= s->base;
    int ret = 0;

    //printf("silverbox_tty_read %x %x\n", offset, size);

    switch (offset) {
        case TTY_BYTES_READY:
            ret = s->data_count;
            break;
    default:
        cpu_abort (cpu_single_env, "%s: Bad offset %x\n", __func__, offset);
        break;
    }
#ifdef TARGET_WORDS_BIGENDIAN
    ret = bswap32(ret);
#endif
    return ret;
}

static void silverbox_tty_write(void *opaque, target_phys_addr_t offset, uint32_t value)
{
    struct tty_state *s = (struct tty_state *)opaque;
    offset -= s->base;

    //printf("silverbox_tty_read %x %x %x\n", offset, value, size);
#ifdef TARGET_WORDS_BIGENDIAN
    value = bswap32(value);
#endif

    switch(offset) {
        case TTY_PUT_CHAR: {
            uint8_t ch = value;
            if(s->cs)
                qemu_chr_write(s->cs, &ch, 1);
        } break;

        case TTY_CMD:
            switch(value) {
                case TTY_CMD_INT_DISABLE:
                    if(s->ready) {
                        if(s->data_count > 0)
                            qemu_set_irq(s->irq, 0);
                        s->ready = 0;
                    }
                    break;

                case TTY_CMD_INT_ENABLE:
                    if(!s->ready) {
                        if(s->data_count > 0)
                            qemu_set_irq(s->irq, 1);
                        s->ready = 1;
                    }
                    break;

                case TTY_CMD_WRITE_BUFFER:
                    if(s->cs) {
                        int len;
                        target_ulong buf;

                        buf = s->ptr;
                        len = s->ptr_len;

                        while(len) {
                            int page_remain = TARGET_PAGE_SIZE - (buf & ~TARGET_PAGE_MASK);
                            int to_write = len;
                            uint8_t *phys = (uint8_t *)v2p(buf, 0);
                            if(to_write > page_remain)
                                to_write = page_remain;
                            qemu_chr_write(s->cs, phys, to_write);
                            buf += to_write;
                            len -= to_write;
                        }
                        //printf("silverbox_tty_write: got %d bytes from %x\n", s->ptr_len, s->ptr);
                    }
                    break;

                case TTY_CMD_READ_BUFFER:
                    if(s->ptr_len > s->data_count)
                        cpu_abort (cpu_single_env, "silverbox_tty_write: reading more data than available %d %d\n", s->ptr_len, s->data_count);
                    pmemcpy(s->ptr, s->data, s->ptr_len);
                    //printf("silverbox_tty_write: read %d bytes to %x\n", s->ptr_len, s->ptr);
                    if(s->data_count > s->ptr_len)
                        memmove(s->data, s->data + s->ptr_len, s->data_count - s->ptr_len);
                    s->data_count -= s->ptr_len;
                    if(s->data_count == 0 && s->ready)
                        qemu_set_irq(s->irq, 0);
                    break;

                default:
                    cpu_abort (cpu_single_env, "%s: Bad command %x\n",
				__func__, value);
            };
            break;

        case TTY_DATA_PTR:
            s->ptr = value;
            break;

        case TTY_DATA_LEN:
            s->ptr_len = value;
            break;

        default:
            cpu_abort (cpu_single_env, "%s: Bad offset %x\n", __func__, offset);
    }
}

static int tty_can_receive(void *opaque)
{
    struct tty_state *s = opaque;

    return (sizeof(s->data) - s->data_count);
}

static void tty_receive(void *opaque, const uint8_t *buf, int size)
{
    struct tty_state *s = opaque;

    memcpy(s->data + s->data_count, buf, size);
    s->data_count += size;
    if(s->data_count > 0 && s->ready)
        qemu_set_irq(s->irq, 1);
}

static CPUReadMemoryFunc *silverbox_tty_readfn[] = {
    silverbox_tty_read,
    silverbox_tty_read,
    silverbox_tty_read
};

static CPUWriteMemoryFunc *silverbox_tty_writefn[] = {
    silverbox_tty_write,
    silverbox_tty_write,
    silverbox_tty_write
};

int silverbox_tty_add(CharDriverState *cs, int id, uint32_t base, qemu_irq irq)
{
    int ret;
    struct tty_state *s;
    static int  instance_id = 0;
    int iomemtype;

    s = qemu_mallocz(sizeof(*s));
    s->base = base;
    s->size = 0x400;
    s->irq = irq;
    s->irq_count = 1;
    s->cs = cs;

    if(cs) {
        qemu_chr_add_handlers(cs, tty_can_receive, tty_receive, NULL, s);
    }

    iomemtype = cpu_register_io_memory(0,
                    silverbox_tty_readfn, silverbox_tty_writefn, s);
    cpu_register_physical_memory(s->base, s->size, iomemtype);
    register_savevm( "silverbox_tty", instance_id++, 1,
                     silverbox_tty_save, silverbox_tty_load, s);
    return ret;
}

