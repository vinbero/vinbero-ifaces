#ifndef _VINBERO_IFACE_BASIC_H
#define _VINBERO_IFACE_BASIC_H

#include <vinbero_common/vinbero_common_Module.h>

#define VINBERO_IFACE_BASIC_FUNCTIONS \
int vinbero_iface_BASIC_service(struct vinbero_common_Module* module)

#define VINBERO_IFACE_BASIC_FUNCTION_POINTERS \
int (*vinbero_iface_BASIC_service)(struct vinbero_common_Module*)

struct vinbero_iface_BASIC {
    VINBERO_IFACE_BASIC_FUNCTION_POINTERS;
};

#define VINBERO_IFACE_BASIC_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COMMON_MODULE_DLSYM(iface, dlHandle, vinbero_iface_BASIC_service, ret); \
    if(*ret < 0) break; \
} while(0)

#endif
