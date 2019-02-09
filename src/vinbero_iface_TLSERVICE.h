#ifndef _VINBERO_IFACE_TLSERVICE_H
#define _VINBERO_IFACE_TLSERVICE_H

#include <vinbero_common/vinbero_common_TlModule.h>

#define VINBERO_IFACE_TLSERVICE_FUNCTIONS \
int vinbero_iface_TLSERVICE_call(struct vinbero_common_TlModule* tlModule)

#define VINBERO_IFACE_TLSERVICE_FUNCTION_POINTERS \
int (*vinbero_iface_TLSERVICE_call)(struct vinbero_common_TlModule*)

struct vinbero_iface_TLSERVICE {
    VINBERO_IFACE_TLSERVICE_FUNCTION_POINTERS;
};

#define VINBERO_IFACE_TLSERVICE_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COMMON_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLSERVICE_call, ret); \
    if(*ret < 0) break; \
} while(0)

#endif
