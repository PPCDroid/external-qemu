/* Automatically generated by configure - do not modify */
#if defined (TARGET_ARM)
#include "config-host.h"
#define CONFIG_QEMU_PREFIX "/usr/gnemul/qemu-arm"
#define CONFIG_TRACE 1
#define CONFIG_NAND 1
#define CONFIG_SHAPER 1
#define CONFIG_SOFTMMU 1
#define CONFIG_SOFTFLOAT 1
#define CONFIG_SDL 1
#ifndef _WIN32
#define CONFIG_NAND_LIMITS 1
#endif
#elif defined(TARGET_MIPS)
#include "config-host.h"
#define CONFIG_QEMU_PREFIX "/usr/gnemul/qemu-mips"
#define CONFIG_TRACE 1
#define CONFIG_NAND 1
#define CONFIG_SHAPER 1
#define CONFIG_SOFTMMU 1
#define CONFIG_SOFTFLOAT 1
#define CONFIG_SDL 1
#ifndef _WIN32
#define CONFIG_NAND_LIMITS 1
#endif
#elif defined(TARGET_PPC)
#include "config-host.h"
#define CONFIG_QEMU_PREFIX "/usr/gnemul/qemu-ppc"
#define CONFIG_TRACE 1
#define CONFIG_NAND 1
#define CONFIG_SHAPER 1
#define CONFIG_SOFTMMU 1
#define CONFIG_SOFTFLOAT 1
#define CONFIG_SDL 1
#ifndef _WIN32
#define CONFIG_NAND_LIMITS 1
#endif
#else
#error Unsupported target architecture
#endif /* TARGET */
