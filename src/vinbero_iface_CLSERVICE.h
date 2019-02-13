#ifndef _VINBERO_IFACE_CLSERVICE_H
#define _VINBERO_IFACE_CLSERVICE_H

#include <vinbero_com/vinbero_com_ClModule.h>
#include <vinbero_com/vinbero_com_Status.h>

#define VINBERO_IFACE_CLSERVICE_FUNCS \
int vinbero_iface_CLSERVICE_call(struct vinbero_com_ClModule* clModule)

#define VINBERO_IFACE_CLSERVICE_FUNC_POINTERS \
int (*vinbero_iface_CLSERVICE_call)(struct vinbero_com_ClModule*)

struct vinbero_iface_CLSERVICE {
    VINBERO_IFACE_CLSERVICE_FUNC_POINTERS;
};

#define VINBERO_IFACE_CLSERVICE_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLSERVICE_call, ret); \
    if(*ret < VINBERO_COM_STATUS_SUCCESS) break; \
} while(0);

#endif
