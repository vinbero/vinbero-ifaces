#ifndef _VINBERO_IFACE_TLOCAL_H
#define _VINBERO_IFACE_TLOCAL_H

#include <vinbero_com/vinbero_com_TlModule.h>

#define VINBERO_IFACE_TLOCAL_FUNCS \
int vinbero_iface_TLOCAL_init(struct vinbero_com_TlModule* tlModule); \
int vinbero_iface_TLOCAL_rInit(struct vinbero_com_TlModule* tlModule); \
int vinbero_iface_TLOCAL_destroy(struct vinbero_com_TlModule* tlModule); \
int vinbero_iface_TLOCAL_rDestroy(struct vinbero_com_TlModule* tlModule)

#define VINBERO_IFACE_TLOCAL_FUNC_PTRS \
int (*vinbero_iface_TLOCAL_init)(struct vinbero_com_TlModule*); \
int (*vinbero_iface_TLOCAL_rInit)(struct vinbero_com_TlModule*); \
int (*vinbero_iface_TLOCAL_destroy)(struct vinbero_com_TlModule*); \
int (*vinbero_iface_TLOCAL_rDestroy)(struct vinbero_com_TlModule*)

struct vinbero_iface_TLOCAL {
    VINBERO_IFACE_TLOCAL_FUNC_PTRS;
};

#define VINBERO_IFACE_TLOCAL_DLSYM(iface, dlHandle, ret) \
do { \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLOCAL_init, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLOCAL_rInit, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLOCAL_destroy, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_TLOCAL_rDestroy, ret); \
    if(*ret < 0) break; \
} while(0)

#endif
