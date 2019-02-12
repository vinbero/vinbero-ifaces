#ifndef _VINBERO_IFACE_TLSERVICE_H
#define _VINBERO_IFACE_TLSERVICE_H

#include <vinbero_com/vinbero_com_TlModule.h>
#include <vinbero_com/vinbero_com_Status.h>

#define VINBERO_IFACE_TLSERVICE_FUNCS \
int vinbero_iface_TLSERVICE_call(struct vinbero_com_TlModule* tlModule)

#define VINBERO_IFACE_TLSERVICE_FUNC_PTRS \
int (*vinbero_iface_TLSERVICE_call)(struct vinbero_com_TlModule*)

struct vinbero_iface_TLSERVICE {
    VINBERO_IFACE_TLSERVICE_FUNC_PTRS;
};

#define VINBERO_IFACE_TLSERVICE_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLSERVICE_call, ret); \
    if(*ret < VINBERO_COM_STATUA_SUCCESS) break; \
} while(0)

#endif
