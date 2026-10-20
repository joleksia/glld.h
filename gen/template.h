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
#   include <assert.h>
#   include <string.h>
#   include <stdio.h>
#   include <stdint.h>
#   include <stddef.h>
#   include <sys/types.h>
# else
#   include <cassert>
#   include <string>
#   include <cstdio>
#   include <cstdint>
#   include <cstddef>
#   include <sys/types.h>
# endif
#
# if defined (__cplusplus)

extern "C" {

# endif

/* glld.h */

typedef void *(*glld_loader_t) (const char *);


typedef struct glld_s glld_t;

struct glld_s {
    
    /* glld version */
    
    struct {

        int major;
        int minor;

    } version;

    /* OpenGL struct */

    struct {
        
        /* OpenGL version */

        struct {

            int major;
            int minor;

        } version;

        /* OpenGL backend handle */
        
        void *libEGL,
             *libGLX,
             *libWGL;

    } gl;

};


GLAPI int glld_load(glld_t *);

GLAPI int glld_loader(glld_t *, glld_loader_t);

GLAPI int glld_unload(glld_t *);

GLAPI void *glld_get_proc_address(const char *);

/* OpenGL */

/* OpenGL versions */

/* {{{ */
<<glld-gl-macros>>
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
<<glld-gl-functions>>
/* }}} */

/* {{{ */
<<glld-gl-function-macros>>
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
#  if defined (GLLD_VERBOSE)
#   define GLLD_VERBOSE_INFO 1
#   define GLLD_VERBOSE_WARN 1
#   define GLLD_VERBOSE_ERROR 1
#  endif
#
#  if defined (__cplusplus)

extern "C" {

#  endif /* __cplusplus */
    
/* key-value pair array of OpenGL functions */
struct glld_glapi_s {

#  if !defined (__cplusplus)
    const char *name;
#  else
    const std::string &name;
#  endif /* __cplusplus */

    void **addr;
};

static struct glld_glapi_s _glld_glapi[] = {
   
    /* {{{ */ 
<<glld-gl-function-array>>
    /* }}} */

    /* ... */

    { "", 0 }
};

/* glld.h */

/* static API */

GLINT void *__glld_dlopen(const char *);

GLINT void *__glld_dlsym(void *, const char *);

GLINT int __glld_dlclose(void *);

/* public API */

GLAPI int glld_load(glld_t *glld) {
    /* null-check */
    if (!glld) { return (0); }

    /* clear 'glld' */
    memset(glld, 0, sizeof(glld_t));

    /* get the 'load' function */
    glld_loader_t load = 0;

    /* try to load EGL */
    const char *libegl[] = { "libEGL.so",
                             "libEGL.so.1",
                             "libEGL.so.1.1.0",
                             0 };

    for (const char **s = libegl; s; s++) {
        glld->gl.libEGL = __glld_dlopen(*s);
        if (glld->gl.libEGL) { break; }
    }
    
    /* try to load 'eglGetProcAddress' symbol */
    if (!load && glld->gl.libEGL) {
        load = __glld_dlsym(glld->gl.libEGL, "eglGetProcAddress");

        /* 'load' succeed */
        if (load) {
            /* load OpenGL */
            return (glld_loader(glld, load));
        }
    }

    /* try to load GLX */
    const char *libglx[] = { "libGLX.so",
                             "libGLX.so.0",
                             "libGLX.so.0.0.0",
                             0 };

    for (const char **s = libglx; s; s++) {
        glld->gl.libGLX = __glld_dlopen(*s);
        if (glld->gl.libGLX) { break; }
    }
    
    /* try to load 'glXGetProcAddress' symbol */
    if (!load && glld->gl.libGLX) {
        load = __glld_dlsym(glld->gl.libEGL, "glXGetProcAddress");
    
        /* if failed, try to load 'glXGetProcAddressARB' symbol */
        if (!load) {
            load = __glld_dlsym(glld->gl.libEGL, "glXGetProcAddressARB");
        }

        /* 'load' succeed */
        if (load) {
            /* load OpenGL */
            return (glld_loader(glld, load));
        }
    }
    
    /* try to load WGL */
    const char *opengl32[] = { "opengl32.dll",
                               0 };

    for (const char **s = opengl32; s; s++) {
        glld->gl.libWGL = __glld_dlopen(*s);
        if (glld->gl.libWGL) { break; }
    }
    
    /* try to load 'wglGetProcAddress' symbol */
    if (!load && glld->gl.libWGL) {
        load = __glld_dlsym(glld->gl.libEGL, "wglGetProcAddress");

        /* 'load' succeed */
        if (load) {
            /* load OpenGL */
            return (glld_loader(glld, load));
        }
    }
    
    /* fallback */
    return (glld_loader(glld, (glld_loader_t) glld_get_proc_address));
}


GLAPI int glld_loader(glld_t *glld, glld_loader_t load) {
    /* null-check */
    if (!glld) { return (0); }
    if (!load) { return (0); }

    /* clear version numbers */
    glld->version.major = 0;
    glld->version.minor = 0;
    glld->gl.version.major = 0;
    glld->gl.version.minor = 0;

    /* 'load' OpenGL functions */
    for (size_t i = 0; _glld_glapi[i].addr; i++) {
        /* check if 'addr' already loaded */
        if (*_glld_glapi[i].addr) { continue; }

        /* 'load' OpenGL function */
# if !defined (__cplusplus)
        *_glld_glapi[i].addr = load(_glld_glapi[i].name);

# else
        *_glld_glapi[i].addr = load(_glld_glapi[i].name.c_str());

# endif /* __cplusplus */

        /* null-check */
        if (!_glld_glapi[i].addr) { return (0); }
    } 

    /* return glld.h version */
    glld->version.major = GLLD_VERSION_MAJOR;
    glld->version.minor = GLLD_VERSION_MINOR;

    /* return OpenGL version */
    glGetIntegerv(GL_MAJOR_VERSION, &glld->gl.version.major);
    glGetIntegerv(GL_MINOR_VERSION, &glld->gl.version.minor);

    /* success */
    return (1);
}


GLAPI int glld_unload(glld_t *glld) {
    /* null-check */
    if (!glld) { return (0); }

    /* unload OpenGL backend handles */
    void *libEGL = glld->gl.libEGL,
         *libGLX = glld->gl.libGLX,
         *libWGL = glld->gl.libWGL;
    if (libEGL) { __glld_dlclose(libEGL); }
    if (libGLX) { __glld_dlclose(libGLX); }
    if (libWGL) { __glld_dlclose(libWGL); }

    /* clear 'glld' */
    memset(glld, 0, sizeof(glld_t));

    /* success */
    return (1);
}


GLAPI void *glld_get_proc_address(const char *name) {
    const char *libGL[] = { /* unix handles */
                            "libGL.so",
                            "libGL.so.1",
                            "libGL.so.1.7.0",

                            /* MacOS handles */
                            "/Library/Frameworks/OpenGL.framework/OpenGL",
                            "/System/Library/Frameworks/OpenGL.framework/OpenGL",
                            "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"

                            /* Windows handles */
                            "opengl32.dll",

                            /* null-terminator */
                            0 };
   
    /* try to load libGL */
    static void *handle = 0;
    if (!handle) {
        for (size_t i = 0; libGL[i]; i++) {
            handle = __glld_dlopen(libGL[i]);
            if (handle) {
                break;
            }
        }
    }

    /* null-check */
    if (!handle) { return (0); }
    
    /* try to load 'name' using 'handle' */
    void *proc = __glld_dlsym(handle, name);

    /* return 'proc' */
    return (proc);
}

/* static API */

GLINT void *__glld_dlopen(const char *name) {
    /* null-check */
    if (!name) { return (0); }

    /* platform-dependant dynamic object loading */
#  if defined (GLLD_PLATFORM_LINUX) || \
      defined (GLLD_PLATFORM_BSD)   || \
      defined (GLLD_PLATFORM_APPLE)
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
      defined (GLLD_PLATFORM_BSD)   || \
      defined (GLLD_PLATFORM_APPLE)
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
      defined (GLLD_PLATFORM_BSD)   || \
      defined (GLLD_PLATFORM_APPLE)
    dlclose(handle);

#  elif defined (GLLD_PLATFORM_WINDOWS)
    FreeLibrary(handle);

#  endif

    return (1);
}

/* OpenGL */

/* OpenGL functions */

/* {{{ */
<<glld-gl-function-declarations>>
/* }}} */

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* _glld_impl_h_ */
#endif /* GLLD_IMPLEMENTATION */
