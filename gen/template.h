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
# if defined (_WIN32) && !defined (APIENTRY) && !defined (__CYGWIN__) && !defined (__SCITECH_SNAP__)
#  if !defined (WIN32_LEAN_AND_MEAN)
#   define WIN32_LEAN_AND_MEAN 1
#  endif
#  include <windows.h>
# endif
#
# if !defined (APIENTRY)
#  define APIENTRY
# endif /* APIENTRY */
# if !defined (APIENTRYP)
#  define APIENTRYP APIENTRY *
# endif /* APIENTRYP */
# if !defined (GLAPI)
#  define GLAPI extern
# endif /* GLAPI */
# if !defined (GLINT)
#  define GLINT static
# endif /* GLINT */
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

/* OpenGL versions */

/* {{{ */
<<glld-gl-macros>>
/* }}} */

/* OpenGL global objects */
/* {{{ */

# if !defined (GLLD_NO_GLOBAL_API)

static void *libGL_g  = 0;
static void *libEGL_g = 0;
static void *libGLX_g = 0;
static void *libWGL_g = 0;

# endif /* GLLD_NO_GLOBAL_API */

/* }}} */

/* OpenGL types */

/* {{{ */
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef int8_t GLbyte;
typedef uint8_t GLubyte;
typedef int16_t GLshort;
typedef uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef int32_t GLclampx;
typedef int GLsizei;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
typedef void *GLhandleARB;
typedef uint16_t GLhalf;
typedef uint16_t GLhalfARB;
typedef int32_t GLfixed;
typedef intptr_t GLintptr;
typedef intptr_t GLintptrARB;
typedef ssize_t GLsizeiptr;
typedef ssize_t GLsizeiptrARB;
typedef int64_t GLint64;
typedef int64_t GLint64EXT;
typedef uint64_t GLuint64;
typedef uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef void (APIENTRY *GLVULKANPROCNV)(void);
/* }}} */

/* OpenGL enums */

/* {{{ */
<<glld-gl-enums>>
/* }}} */

/* OpenGL functions */

/* {{{ */
<<glld-gl-function-typedef>>
/* }}} */

/* OpenGL functions (extern) */

/* {{{ */
# if !defined (GLLD_NO_GLOBAL_API)
<<glld-gl-function-extern>>
# endif /* GLLD_NO_GLOBAL_API */
/* }}} */

/* 'struct glld_glapi_s': OpenGL API structure.
 * */
struct glld_glapi_s {

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

/* {{{ */
<<glld-gl-function-glapi>>
/* }}} */

};

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

<<glld-gl-function-global>>

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

GLINT int __glld_gl_api(struct glld_glapi_s *, glld_loader_t);

/* public API */

GLAPI int glld_load(struct glld_glapi_s *glapi) {
    /* load OpenGL handles */
    struct
    glld_glapi_s api;
    if (!__glld_gl_handle(&api)) {
        return (0);
    }

    /* pick OpenGL loader function */
    glld_loader_t load = 0;
    if (!__glld_gl_loader(&api, &load)) {
        glld_unload(&api);
        return (0);
    }

    /* load OpenGL API */
    int version = __glld_gl_api(&api, load);
    if (!version) {
        glld_unload(&api);
        return (0);
    }

    /* copy 'api' to 'glapi' */
    if (glapi) {
        if (!memcpy(glapi, &api, sizeof(struct glld_glapi_s))) {
            glld_unload(&api);
            return (0);
        }
    }

    /* return 'version' as success code */
    return (version);
}


GLAPI int glld_loader(struct glld_glapi_s *glapi, glld_loader_t load) {
    /* null-check */
    if (!load) { return (0); }

    /* load OpenGL handles */
    struct
    glld_glapi_s api;
    if (!__glld_gl_handle(&api)) {
        return (0);
    }

    /* load OpenGL API */
    int version = __glld_gl_api(&api, load);
    if (!version) {
        glld_unload(&api);
        return (0);
    }

    /* copy 'api' to 'glapi' */
    if (glapi) {
        if (!memcpy(glapi, &api, sizeof(struct glld_glapi_s))) {
            glld_unload(&api);
            return (0);
        }
    }

    /* return 'version' as success code */
    return (version);
}


GLAPI int glld_unload(struct glld_glapi_s *glapi) {
    /* unload 'glapi' */
    if (glapi) {
        /* unload OpenGL handle */
        void *libGL = glapi->libGL;
        if (libGL) { __glld_dlclose(libGL); }
        
        /* unload OpenGL backend handles */
        void *libEGL = glapi->libEGL,
             *libGLX = glapi->libGLX,
             *libWGL = glapi->libWGL;
        if (libEGL) { __glld_dlclose(libEGL); }
        if (libGLX) { __glld_dlclose(libGLX); }
        if (libWGL) { __glld_dlclose(libWGL); }

        /* clear 'glapi' */
        memset(glapi, 0, sizeof(struct glld_glapi_s));
    }

    /* success */
    return (1);
}


GLAPI void *glld_get_proc_address(const char *name) {
    /* load OpenGL handles */
    struct
    glld_glapi_s api;
    if (!__glld_gl_handle(&api)) {
        return (0);
    }

    /* OpenGL handle */
    void *libGL = api.libGL;
    if (!libGL) { return (0); }

    /* load 'name' symbol from 'libGL' */
    void *proc = __glld_dlsym(libGL, name);
    
    /* return 'proc' (or 'null' if failed) */
    return (proc);
}

/* static API */

GLINT void *__glld_dlopen(const char *name) {
    /* null-check */
    if (!name) { return (0); }

    /* platform-dependant dynamic object loading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    void *handle = dlopen(name, RTLD_NOW | RTLD_GLOBAL);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE handle = LoadLibraryA(handle);

#  endif

    /* return 'handle' */
    return (handle);
}


GLINT void *__glld_dlsym(void *handle, const char *symbol) {
    /* null-check */
    if (!handle) { return (0); }
    if (!symbol) { return (0); }

    /* platform-dependant dynamic symbol loading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    void *proc = dlsym(handle, symbol);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE proc = GetProcAddress(handle, symbol);

#  endif

    /* return 'proc' */
    return (proc);
}


GLINT int __glld_dlclose(void *handle) {
    /* null-check */
    if (!handle) { return (0); }

    /* platform-dependant dynamic object unloading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_APPLE) || \
      defined (GLLD_PLATFORM_BSD)
    dlclose(handle);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    FreeLibrary(handle);

#  endif

    return (1);
}


GLINT int __glld_gl_handle(struct glld_glapi_s *glapi) {

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

    /* return handles to 'glapi' if not null */
    if (glapi) {
        glapi->libGL  = libGL;
        glapi->libEGL = libEGL;
        glapi->libGLX = libGLX;
        glapi->libWGL = libWGL;
    }

    /* success */
    return (1);
}


GLINT int __glld_gl_loader(struct glld_glapi_s *glapi, glld_loader_t *result) {
    /* null-check */
    if (!glapi) { return (0); }
    
    /* load 'eglGetProcAddress' function */
    void *libEGL = glapi->libEGL;
    glld_loader_t egl_handle = 0;
    if (libEGL) {
        egl_handle = (glld_loader_t) __glld_dlsym(libEGL, "eglGetProcAddress");
    }

    /* load 'glXGetProcAddress'/'glXGetProcAddressARB' function */
    void *libGLX = glapi->libGLX;
    glld_loader_t glx_load = 0;
    if (libGLX) {
        glx_load = (glld_loader_t) __glld_dlsym(libGLX, "glXGetProcAddress");
        if (!glx_load) {
            glx_load = (glld_loader_t) __glld_dlsym(libGLX, "glXGetProcAddressARB");
        }
    }

    /* load 'wglGetProcAddress' function */
    void *libWGL = glapi->libWGL;
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

    /* return 'result' */
    if (result) { *result = load; }

    /* success */
    return (1);
}


GLINT int __glld_gl_api(struct glld_glapi_s *glapi, glld_loader_t load) {
    /* null-check */
    if (!glapi) { return (0); }
    if (!load)  { return (0); }

    /* load OpenGL functions */
    /* {{{ */
<<glld-gl-function-load>>
    /* }}} */
    
    /* return OpenGL version */
    int major = 0;
    glGetIntegerv(GL_MAJOR_VERSION, &major);

    int minor = 0;
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    /* success */
    return (major * 10 + minor);
}

/* }}} */

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* _glld_impl_h_ */
#endif /* GLLD_IMPLEMENTATION */
