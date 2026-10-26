/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  glld.h: OpenGL API Loader:
 *
 *      - made by: <<glld-author>>
 *      - version: <<glld-version>>
 *      - licence: <<glld-licence>>
 *
 *
 *  OpenGL settings:
 *      - profile: <<glld-gl-profile>>
 *      - version: <<glld-gl-version>> (OpenGL)
 *      - version: <<glld-gl-es-version>> (OpenGL ES)
 *      - version: <<glld-gl-sc-version>> (OpenGL SC)
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (__cplusplus)
# pragma once
#endif
#
#if !defined (_glld_h_)
# define _glld_h_ 1
#
# define GLLD_VERSION "<<glld-version>>"
# define GLLD_VERSION_MAJOR <<glld-version-major>>
# define GLLD_VERSION_MINOR <<glld-version-minor>>
#
# if defined (__gl_h_)
#  error "#include <GL/gl.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gl_h_ */
# define __gl_h_ 1
#
# if defined (__gl_glext_h_)
#  error "#include <GL/glext.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gl_glext_h_ */
# define __gl_glext_h_ 1
#
# if defined (__gl_glcorearb_h_)
#  error "#include <GL/glcorearb.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gl_glcorearb_h_ */
# define __gl_glcorearb_h_ 1
#
# if defined (__gles2_gl2_h_)
#  error "#include <GLES2/gl2.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles2_gl2_h_ */
# define __gles2_gl2_h_ 1
#
# if defined (__gles2_gl2ext_h_)
#  error "#include <GLES2/gl2ext.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles2_gl2ext_h_ */
# define __gles2_gl2ext_h_ 1
#
# if defined (__gl2platform_h_)
#  error "#include <GLES2/gl2platform.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gl2platform_h_ */
# define __gl2platform_h_ 1
#
# if defined (__gles3_gl3_h_)
#  error "#include <GLES3/gl3.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles3_gl3_h_ */
# define __gles3_gl3_h_ 1
#
# if defined (__gles3_gl31_h_)
#  error "#include <GLES3/gl31.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles3_gl31_h_ */
# define __gles3_gl31_h_ 1
#
# if defined (__gles3_gl32_h_)
#  error "#include <GLES3/gl32.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles3_gl32_h_ */
# define __gles3_gl32_h_ 1
#
# if defined (__gles3_gl3ext_h_)
#  error "#include <GLES3/gl3ext.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gles3_gl3ext_h_ */
# define __gles3_gl3ext_h_ 1
#
# if defined (__gl3platform_h_)
#  error "#include <GLES3/gl3platform.h> detected. To ensure a proper usage of this loader, remove the include."
# endif /* __gl3platform_h_ */
# define __gl3platform_h_ 1
#
# /* Define platform macros */
# if defined (__linux__) || \
     defined (__gnu_linux__)
#  define GLLD_PLATFORM "linux"
#  define GLLD_PLATFORM_LINUX 1
#
# elif defined (__APPLE__) || \
       defined (__MACH__)
#  define GLLD_PLATFORM "apple"
#  define GLLD_PLATFORM_APPLE 1
#
# elif defined (_WIN16)      || \
       defined (_WIN32)      || \
       defined (_WIN64)      || \
       defined (__MINGW32__) || \
       defined (__MINGW64__) || \
       defined (__CYGWIN__)  || \
       defined (__MSYS__)
#  define GLLD_PLATFORM "windows"
#  define GLLD_PLATFORM_WINDOWS 1
#
# elif defined (__bsdi__)       || \
       defined (__FreeBSD__)    || \
       defined (__NetBSD__)     || \
       defined (__DragonFly__)  || \
       defined (__MidnightBSD__)
#  define GLLD_PLATFORM "bsd"
#  define GLLD_PLATFORM_BSD 1
#
# else
#  error /* No valid platform found */
# endif
#
# if !defined (APIENTRY)
#  define APIENTRY
# endif /* APIENTRY */
#
# if !defined (APIENTRYP)
#  define APIENTRYP APIENTRY *
# endif /* APIENTRYP */
#
# if !defined (GLAPI)
#  define GLAPI extern
# endif /* GLAPI */
#
#if !defined (GLINT)
#  define GLINT static
# endif /* GLINT */
#
# if !defined (__cplusplus)
#   include <string.h>
#   include <stdio.h>
#   include <stdint.h>
#   include <stddef.h>
#   include <sys/types.h>
# else
#   include <cstring>
#   include <cstdio>
#   include <cstdint>
#   include <cstddef>
#   include <sys/types.h>
# endif
#
# if defined (__cplusplus)

extern "C" {

# endif

/* OpenGL */

/* {{{ */

/* OpenGL 'khrplatform.h' types */

# if !defined (__khrplatform_h_) /* {{{ */
#  define __khrplatform_h_ 1

typedef int8_t    khronos_int8_t;
typedef uint8_t   khronos_uint8_t;
typedef int16_t   khronos_int16_t;
typedef uint16_t  khronos_uint16_t;
typedef int32_t   khronos_int32_t;
typedef uint32_t  khronos_uint32_t;
typedef int64_t   khronos_int64_t;
typedef uint64_t  khronos_uint64_t;
typedef uintptr_t khronos_uintptr_t;
typedef intptr_t  khronos_intptr_t;
typedef uintptr_t khronos_usize_t;
typedef intptr_t  khronos_ssize_t;
typedef float     khronos_float_t;

# endif /* __khrplatform_h_ */ /* }}} */

/* OpenGL features */

/* {{{ */
<<glld-gl-feature>>
/* }}} */

/* OpenGL extensions */

/* {{{ */
<<glld-gl-extensions>>
/* }}} */

/* OpenGL API structure */

struct glld_glapi_s { /* {{{ */

    /* 'libGL': handle to dynamic shared OpenGL object.
     * */
    void *libGL;
        
    /* 'libEGL': handle to dynamic shared EGL object.
     * */
    void *libEGL;
    
    /* 'libGLX': handle to dynamic shared GLX object.
     * */
    void *libGLX;
    
    /* 'libWGL': handle to dynamic shared WGL object.
     * */
    void *libWGL;

    /* OpenGL functions */

/* {{{ */
<<glld-gl-glapi>>
/* }}} */

}; /* }}} */

/* OpenGL global objects */

/* {{{ */

# if !defined (GLLD_NO_GLOBAL_API)

/* 'libGL_g': handle to dynamic shared OpenGL object.
 * */
static void *libGL_g  = 0;

/* 'libEGL_g': handle to dynamic shared EGL object.
 * */
static void *libEGL_g = 0;

/* 'libGLX_g': handle to dynamic shared GLX object.
 * */
static void *libGLX_g = 0;

/* 'libWGL_g': handle to dynamic shared WGL object.
 * */
static void *libWGL_g = 0;

/* OpenGL functions */

/* {{{ */
<<glld-gl-extern>>
/* }}} */

# endif /* GLLD_NO_GLOBAL_API */

/* }}} */

/* }}} */

/* glld.h */

/* {{{ */

typedef void *(*glld_loader_t) (const char *);


GLAPI int glld_load(struct glld_glapi_s *);

GLAPI int glld_loader(struct glld_glapi_s *, glld_loader_t);

GLAPI int glld_unload(struct glld_glapi_s *);

GLAPI void *glld_get_proc_address(const char *);

/* }}} */

# if defined (__cplusplus)

}

# endif /* __cplusplus */
#endif /* _glld_h_ */
#
#if defined (GLLD_IMPLEMENTATION)
# if !defined (_glld_impl_h_)
#  define _glld_impl_h_ 1
#
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
#   include <dlfcn.h>
#  endif
#
#  if defined (GLLD_PLATFORM_WINDOWS)
#   include <libloaderapi.h>
#  endif
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */

/* OpenGL */

/* {{{ */

/* OpenGL functions */

/* {{{ */
#  if !defined (GLLD_NO_GLOBAL_API)

<<glld-gl-global>>

#  endif /* GLLD_NO_GLOBAL_API */
/* }}} */

/* }}} */

/* glld.h */

/* {{{ */

/* static API */

GLINT void *__glld_dlopen(const char *);

GLINT void *__glld_dlsym(void *, const char *);

GLINT int __glld_dlclose(void *);

GLINT int __glld_gl_handle(struct glld_glapi_s *);

GLINT int __glld_gl_loader(struct glld_glapi_s *, glld_loader_t *);

GLINT int __glld_gl_init(struct glld_glapi_s *, glld_loader_t);

GLINT int __glld_gl_bind(struct glld_glapi_s *);

/* public API */

GLAPI int glld_load(struct glld_glapi_s *pApi) {
    /* load OpenGL handles */
    struct
    glld_glapi_s glapi;
    __glld_gl_handle(&glapi);

    /* pick OpenGL loader function */
    glld_loader_t load = 0;
    __glld_gl_loader(&glapi, &load);

    /* load OpenGL API */
    __glld_gl_init(&glapi, load);
    
    /* try to bind OpenGL API */
    __glld_gl_bind(&glapi);

    /* copy 'glapi' to 'pApi' */
    if (pApi) {
        *pApi = glapi;
    }

    /* success */
    return (GL_NO_ERROR);
}


GLAPI int glld_loader(struct glld_glapi_s *pApi, glld_loader_t pLoad) {
    /* null-check */
    if (!pLoad) { return (0); }

    /* load OpenGL handles */
    struct
    glld_glapi_s glapi;
    __glld_gl_handle(&glapi);

    /* load OpenGL API */
    __glld_gl_init(&glapi, pLoad);
    
    /* try to bind OpenGL API */
    __glld_gl_bind(&glapi);

    /* copy 'glapi' to 'pApi' */
    if (pApi) {
        *pApi = glapi;
    }
    
    /* success */
    return (GL_NO_ERROR);
}


GLAPI int glld_unload(struct glld_glapi_s *pApi) {
    /* unload 'pApi' */
    if (pApi) {
        /* unload OpenGL handle */
        void *libGL = pApi->libGL;
        if (libGL) { __glld_dlclose(libGL); }
        
        /* unload OpenGL backend handles */
        void *libEGL = pApi->libEGL,
             *libGLX = pApi->libGLX,
             *libWGL = pApi->libWGL;
        if (libEGL) { __glld_dlclose(libEGL); }
        if (libGLX) { __glld_dlclose(libGLX); }
        if (libWGL) { __glld_dlclose(libWGL); }

        /* clear 'glapi' */
        memset(pApi, 0, sizeof(struct glld_glapi_s));
    }

    /* unload global API handles */
    else {
        struct
        glld_glapi_s glapi;

        /* if no global API was unloaded then '__glld_gl_handle' should return them */
        __glld_gl_handle(&glapi);

        /* call 'glld_unload' on 'glapi' recursively */
        glld_unload(&glapi);
    }

    /* success */
    return (GL_NO_ERROR);
}


GLAPI void *glld_get_proc_address(const char *pName) {
    /* load OpenGL handles */
    struct
    glld_glapi_s glapi;
    if (!__glld_gl_handle(&glapi)) {
        return (0);
    }

    /* OpenGL handle */
    void *libGL = glapi.libGL;
    if (!libGL) { return (0); }

    /* load 'pName' symbol from 'libGL' */
    void *proc = __glld_dlsym(libGL, pName);
    
    /* return 'proc' (or 'null' if failed) */
    return (proc);
}

/* static API */

GLINT void *__glld_dlopen(const char *pName) {
    /* null-check */
    if (!pName) { return (0); }

    /* platform-dependant dynamic object loading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    void *handle = dlopen(pName, RTLD_NOW | RTLD_GLOBAL);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE handle = LoadLibraryA(pName);

#  endif

    /* return 'handle' */
    return (handle);
}


GLINT void *__glld_dlsym(void *pHandle, const char *pName) {
    /* null-check */
    if (!pHandle) { return (0); }
    if (!pName)   { return (0); }

    /* platform-dependant dynamic symbol loading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    void *proc = dlsym(pHandle, pName);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE proc = GetProcAddress(pHandle, pName);

#  endif

    /* return 'proc' */
    return (proc);
}


GLINT int __glld_dlclose(void *pHandle) {
    /* null-check */
    if (!pHandle) { return (0); }

    /* platform-dependant dynamic object unloading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    dlclose(pHandle);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    FreeLibrary(pHandle);

#  endif

    /* success */
    return (GL_NO_ERROR);
}


GLINT int __glld_gl_handle(struct glld_glapi_s *pApi) {

    /* 'libEGL' handle */
#  if defined (GLLD_NO_GLOBAL_API)
    void *libEGL = 0;
#  else
    void *libEGL = libEGL_g;
#  endif
    if (!libEGL) {
        /* 'egl_path' array of paths, null-terminated */
        const char *egl_path[] = { /* unix */
                                  "libEGL.so",
                                  "libEGL.so.1",
                                  "libEGL.so.1.1.0",

                                  /* null-terminator */
                                  0 };
        
        for (size_t i = 0; egl_path[i]; i++) {
            libEGL = __glld_dlopen(egl_path[i]);
            if (libEGL) {
                break;
            }
        }

#  if defined (GLLD_NO_GLOBAL_API)
        libEGL_g = libEGL;
#  endif
    }

    /* 'libGLX' handle */
#  if defined (GLLD_NO_GLOBAL_API)
    void *libGLX = 0;
#  else
    void *libGLX = libGLX_g;
#  endif
    if (!libGLX) {
        /* 'glx_path' array of paths, null-terminated */
        const char *glx_path[] = { /* unix */
                                   "libGLX.so",
                                   "libGLX.so.0",
                                   "libGLX.so.0.0.0",

                                   /* null-terminator */
                                   0 };
        
        for (size_t i = 0; glx_path[i]; i++) {
            libGLX = __glld_dlopen(glx_path[i]);
            if (libGLX) {
                break;
            }
        }

#  if defined (GLLD_NO_GLOBAL_API)
        libGLX_g = libGLX;
#  endif
    }

    /* 'libWGL' handle */
#  if defined (GLLD_NO_GLOBAL_API)
    void *libWGL = 0;
#  else
    void *libWGL = libWGL_g;
#  endif
    if (!libWGL) {
        /* 'wgl_path' array of paths, null-terminated */
        const char *wgl_path[] = { /* Windows */
                                   "opengl32.dll",

                                   /* null-terminator */
                                   0 };

        for (size_t i = 0; wgl_path[i]; i++) {
            libWGL = __glld_dlopen(wgl_path[i]);
            if (libWGL) {
                break;
            }
        }

#  if defined (GLLD_NO_GLOBAL_API)
        libWGL_g = libWGL;
#  endif
    }
    
    /* 'libGL' handle */
#  if defined (GLLD_NO_GLOBAL_API)
    void *libGL = 0;
#  else
    void *libGL = libGL_g;
#  endif
    if (!libGL) {
        /* 'gl_path' array of paths, null-terminated */
        const char *gl_path[] = { /* unix */
                                  "libGL.so",
                                  "libGL.so.1",
                                  "libGL.so.1.7.0",

                                  /* MacOS */
                                  "/Library/Frameworks/OpenGL.framework/OpenGL",
                                  "/System/Library/Frameworks/OpenGL.framework/OpenGL",
                                  "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"

                                  /* Windows */
                                  "opengl32.dll",

                                  /* null-terminator */
                                  0 };

        for (size_t i = 0; gl_path[i]; i++) {
            libGL = __glld_dlopen(gl_path[i]);
            if (libGL) {
                break;
            }
        }

#  if defined (GLLD_NO_GLOBAL_API)
        libGL_g = libGL;
#  endif
    }

    /* return handles to 'pApi' if not null */
    if (pApi) {
        pApi->libGL  = libGL;
        pApi->libEGL = libEGL;
        pApi->libGLX = libGLX;
        pApi->libWGL = libWGL;
    }

    /* success */
    return (GL_NO_ERROR);
}


GLINT int __glld_gl_loader(struct glld_glapi_s *pApi, glld_loader_t *pLoad) {
    /* null-check */
    if (!pApi) { return (0); }
    
    /* load 'eglGetProcAddress' function */
    void *libEGL = pApi->libEGL;
    glld_loader_t egl_handle = 0;
    if (libEGL) {
        egl_handle = (glld_loader_t) __glld_dlsym(libEGL, "eglGetProcAddress");
    }

    /* load 'glXGetProcAddress'/'glXGetProcAddressARB' function */
    void *libGLX = pApi->libGLX;
    glld_loader_t glx_load = 0;
    if (libGLX) {
        glx_load = (glld_loader_t) __glld_dlsym(libGLX, "glXGetProcAddress");
        if (!glx_load) {
            glx_load = (glld_loader_t) __glld_dlsym(libGLX, "glXGetProcAddressARB");
        }
    }

    /* load 'wglGetProcAddress' function */
    void *libWGL = pApi->libWGL;
    glld_loader_t wgl_handle = 0;
    if (libWGL) {
        wgl_handle = (glld_loader_t) __glld_dlsym(libGLX, "wglGetProcAddress");
    }

    /* pick OpenGL loader */
    glld_loader_t load = 0;

    /* use 'eglGetProcAddress' if available */
    if (egl_handle) {
        load = egl_handle;

    /* use 'glXGetProcAddress'/'glXGetProcAddressARB' if available */
    } else if (glx_load) {
        load = glx_load;

    /* use 'wglGetProcAddress' if available */
    } else if (wgl_handle) {
        load = wgl_handle;

    /* use built-in loader as a fallback */
    } else {
        load = (glld_loader_t) glld_get_proc_address;
    }

    /* return 'pLoad' */
    if (pLoad) { *pLoad = load; }

    /* success */
    return (GL_NO_ERROR);
}


GLINT int __glld_gl_init(struct glld_glapi_s *pApi, glld_loader_t pLoad) {
    /* null-check */
    if (!pApi)  { return (0); }
    if (!pLoad) { return (0); }

    /* OpenGL functions */
    /* {{{ */
<<glld-gl-load>>
    /* }}} */

    /* success */
    return (GL_NO_ERROR);
}


GLINT int __glld_gl_bind(struct glld_glapi_s *pApi) {
    /* null-check */
    if (!pApi) { return (0); }

#  if defined (GLLD_NO_GLOBAL_API)

    /* global API disabled: can't bind to global API */
    return (GL_INVALID_OPERATION);

#  else    

    /* OpenGL global handles */
    /* {{{ */
    libGL_g  = pApi->libGL;
    libEGL_g = pApi->libEGL;
    libGLX_g = pApi->libGLX;
    libWGL_g = pApi->libWGL;
    /* }}} */

    /* OpenGL global API */
    /* {{{ */
<<glld-gl-bind>>
    /* }}} */

    return (GL_NO_ERROR);

#  endif

}

/* }}} */

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* _glld_impl_h_ */
#endif /* GLLD_IMPLEMENTATION */
