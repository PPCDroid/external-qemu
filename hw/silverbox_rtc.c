#include "qemu-timer.h"
#include "cpu.h"
#include "irq.h"

struct rtc_state {
    target_phys_addr_t base;
    uint32_t alarm_low;
    int32_t alarm_high;
    int64_t now;
    qemu_irq irq;
    QEMUTimer *timer;
};

/* we save the RTC for the case where the kernel is in the middle of a rtc_read
 * (i.e. it has read the low 32-bit of s->now, but not the high 32-bits yet */
#define  SILVERBOX_RTC_SAVE_VERSION  1

static void  silverbox_rtc_save(QEMUFile*  f, void*  opaque)
{
    struct rtc_state*  s = opaque;

    qemu_put_be64(f, s->now);
}

static int  silverbox_rtc_load(QEMUFile*  f, void*  opaque, int  version_id)
{
    struct  rtc_state*  s = opaque;

    if (version_id != SILVERBOX_RTC_SAVE_VERSION)
        return -1;

    /* this is an old value that is not correct. but that's ok anyway */
    s->now = qemu_get_be64(f);
    return 0;
}

static void silverbox_rtc_tm(void *opaque)
{
    struct rtc_state *s = opaque;

    qemu_irq_raise(s->irq);
}

static uint32_t silverbox_rtc_read(void *opaque, target_phys_addr_t offset)
{
    struct rtc_state *s = (struct rtc_state *)opaque;
    uint32_t ret = 0;

    offset -= s->base;
    switch(offset) {
        case 0x0:
            s->now = (int64_t)time(NULL) * 1000000000;
            ret = s->now;
            goto out;
        case 0x4:
            ret = s->now >> 32;
            goto out;
        default:
            cpu_abort (cpu_single_env, "silverbox_rtc_read: Bad offset %x\n", offset);
    }
out:
#ifdef TARGET_WORDS_BIGENDIAN
    ret = bswap32(ret);
#endif
    return ret;
}

static void silverbox_rtc_write(void *opaque, target_phys_addr_t offset, uint32_t value)
{
    struct rtc_state *s = (struct rtc_state *)opaque;
    int64_t alarm;

#ifdef TARGET_WORDS_BIGENDIAN
    value = bswap32(value);
#endif

    offset -= s->base;
    switch(offset) {
        case 0x8:
            s->alarm_low = value;
            alarm = s->alarm_low | (int64_t)s->alarm_high << 32;
            //printf("next alarm at %lld, tps %lld\n", alarm, ticks_per_sec);
            qemu_mod_timer(s->timer, alarm);
            break;
        case 0xc:
            s->alarm_high = value;
            //printf("alarm_high %d\n", s->alarm_high);
            break;
        case 0x10:
            qemu_irq_lower(s->irq);
            //silverbox_device_set_irq(&s->dev, 0, 0);
            break;
        default:
            cpu_abort (cpu_single_env, "silverbox_rtc_write: Bad offset %x\n", offset);
    }
}

static struct rtc_state rtc_state;

static CPUReadMemoryFunc *silverbox_rtc_readfn[] = {
    silverbox_rtc_read,
    silverbox_rtc_read,
    silverbox_rtc_read
};

static CPUWriteMemoryFunc *silverbox_rtc_writefn[] = {
    silverbox_rtc_write,
    silverbox_rtc_write,
    silverbox_rtc_write
};

void silverbox_rtc_init(uint32_t base, qemu_irq irq)
{
    int iomemtype = cpu_register_io_memory(0, silverbox_rtc_readfn,
                                           silverbox_rtc_writefn, &rtc_state);
    cpu_register_physical_memory(base, 0x100, iomemtype);
    rtc_state.base = base;
    rtc_state.irq = irq;
    rtc_state.timer = qemu_new_timer(vm_clock, silverbox_rtc_tm, &rtc_state);

    register_savevm( "silverbox_rtc", 0, SILVERBOX_RTC_SAVE_VERSION,
                     silverbox_rtc_save, silverbox_rtc_load, &rtc_state);
}

