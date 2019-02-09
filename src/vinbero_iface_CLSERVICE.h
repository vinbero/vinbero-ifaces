#ifndef _VINBERO_IFACE_CLSERVICE_H
#define _VINBERO_IFACE_CLSERVICE_H

#include <vinbero_common/vinbero_common_ClModule.h>

#define VINBERO_IFACE_CLSERVICE_FUNCTIONS \
int vinbero_iface_CLSERVICE_call(struct vinbero_common_ClModule* clModule)

#define VINBERO_IFACE_CLSERVICE_FUNCTION_POINTERS \
int (*vinbero_iface_CLSERVICE_call)(struct vinbero_common_ClModule*)

struct vinbero_iface_CLSERVICE {
    VINBERO_IFACE_CLSERVICE_FUNCTION_POINTERS;
};

#define VINBERO_IFACE_CLSERVICE_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COMMON_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLSERVICE_call, ret); \
    if(*ret < 0) break; \
} while(0);

#endif
