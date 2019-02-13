#ifndef _VINBERO_IFACE_CLOCAL_H
#define _VINBERO_IFACE_CLOCAL_H

#include <vinbero_com/vinbero_com_ClModule.h>

#define VINBERO_IFACE_CLOCAL_FUNCS \
int vinbero_iface_CLOCAL_init(struct vinbero_com_ClModule* clModule); \
int vinbero_iface_CLOCAL_rInit(struct vinbero_com_ClModule* clModule); \
int vinbero_iface_CLOCAL_destroy(struct vinbero_com_ClModule* clModule); \
int vinbero_iface_CLOCAL_rDestroy(struct vinbero_com_ClModule* clModule)

#define VINBERO_IFACE_CLOCAL_FUNC_POINTERS \
int (*vinbero_iface_CLOCAL_init)(struct vinbero_com_ClModule*); \
int (*vinbero_iface_CLOCAL_rInit)(struct vinbero_com_ClModule*); \
int (*vinbero_iface_CLOCAL_destroy)(struct vinbero_com_ClModule*); \
int (*vinbero_iface_CLOCAL_rDestroy)(struct vinbero_com_ClModule*)

struct vinbero_iface_CLOCAL {
    VINBERO_IFACE_CLOCAL_FUNC_POINTERS;
};

#define VINBERO_IFACE_CLOCAL_DLSYM(iface, dlHandle, ret) do { \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLOCAL_init, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLOCAL_rInit, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLOCAL_destroy, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_CLOCAL_rDestroy, ret); \
    if(*ret < 0) break; \
} while(0)

#endif
