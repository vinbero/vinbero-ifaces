#ifndef _VINBERO_IFACE_MODULE_H
#define _VINBERO_IFACE_MODULE_H

#include <vinbero_com/vinbero_com_Config.h>
#include <vinbero_com/vinbero_com_Module.h>

#define VINBERO_IFACE_MODULE_FUNCTIONS \
int vinbero_iface_MODULE_init(struct vinbero_com_Module* module); \
int vinbero_iface_MODULE_rInit(struct vinbero_com_Module* module); \
int vinbero_iface_MODULE_destroy(struct vinbero_com_Module* module); \
int vinbero_iface_MODULE_rDestroy(struct vinbero_com_Module* module)

#define VINBERO_IFACE_MODULE_FUNCTION_POINTERS \
int (*vinbero_iface_MODULE_init)(struct vinbero_com_Module*); \
int (*vinbero_iface_MODULE_rInit)(struct vinbero_com_Module*); \
int (*vinbero_iface_MODULE_destroy)(struct vinbero_com_Module*); \
int (*vinbero_iface_MODULE_rDestroy)(struct vinbero_com_Module*)

struct vinbero_iface_MODULE {
    VINBERO_IFACE_MODULE_FUNCTION_POINTERS;
};

#define VINBERO_IFACE_MODULE_DLSYM(iface, dlHandle, ret) do { \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_MODULE_init, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_MODULE_rInit, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_MODULE_destroy, ret); \
    if(*ret < 0) break; \
    VINBERO_COM_MODULE_DLSYM(iface, dlHandle, vinbero_iface_MODULE_rDestroy, ret); \
    if(*ret < 0) break; \
} while(0)

#endif
