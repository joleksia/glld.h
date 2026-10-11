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

/* SECTION: glld */

typedef void *(*glld_loader_t) (const char *);

GLAPI int glld_load(void);

GLAPI int glld_unload(void);

GLAPI int glld_loader(glld_loader_t);

GLAPI void *glld_get_proc_address(const char *);

/* SECTION: OpenGL */

/* OpenGL standard types */
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

/* OpenGL function declarations */
<<glld-gl-func-ptr>>

# /* OpenGL version macros */
<<glld-gl-version-macros>>
#
# /* OpenGL extension macros */
<<glld-gl-extension-macros>>
#
# /* OpenGL enums */
<<glld-gl-enums>>
#
# /* OpenGL functions */
<<glld-gl-func-macros>>

<<glld-gl-func-declr-1>>

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
struct s_nameaddr {

#  if !defined (__cplusplus)
    const char *name;
#  else
    const std::string &name;
#  endif /* __cplusplus */

    void **addr;
};

static struct s_nameaddr _nameaddr[] = {
    
<<glld-gl-func-nameaddr>>

    /* ... */

    { "", 0 }
};

/* SECTION: glld */

typedef void *(*GLLDPFNGLXGETPROCADDRESSPROC) (const char *);
GLLDPFNGLXGETPROCADDRESSPROC _glld_glXGetProcAddress = 0;

typedef void (*__glld_eglMustCastToProperFunctionPointerType)(void);
typedef __glld_eglMustCastToProperFunctionPointerType (*GLLDPFNEGLGETPROCADDRESSPROC) (const char *);
GLLDPFNEGLGETPROCADDRESSPROC _glld_eglGetProcAddress = 0;

typedef void *(*GLLDPFNWGLGETPROCADDRESSPROC) (const char *);
GLLDPFNWGLGETPROCADDRESSPROC _glld_wglGetProcAddress = 0;


GLINT void *__glld_dlopen(const char *);

GLINT void *__glld_dlsym(void *, const char *);

GLINT int __glld_dlclose(void *);

GLAPI int glld_load(void) {
    /* libGLX */
    const char *libglx[] = {
        "libGLX.so", "libGLX.so.0", "libGLX.so.0.0.0", 0
    };

    void *handle = 0;
    /* attempt to load libGLX.so */
    for (size_t i = 0; libglx[i]; i++) {
        handle = __glld_dlopen(libglx[i]);
        if (handle) {
            break;
        }
    }

    /* if libGLX.so loaded */
    if (handle) {
        _glld_glXGetProcAddress = (GLLDPFNGLXGETPROCADDRESSPROC) __glld_dlsym(handle, "glXGetProcAddress");
        if (_glld_glXGetProcAddress) {
            int status = glld_loader((glld_loader_t) _glld_glXGetProcAddress);
            if (status) {
                return (status);
            }
        }

        __glld_dlclose(handle);
    }

    /* libEGL */
    const char *libegl[] = {
        "libEGL.so", "libEGL.so.1", "libEGL.so.1.1.0", 0
    };

    handle = 0;
    /* attempt to load libEGL.so */
    for (size_t i = 0; libegl[i]; i++) {
        handle = __glld_dlopen(libegl[i]);
        if (handle) {
            break;
        }
    }

    /* if libEGL.so loaded */
    if (handle) {
        _glld_eglGetProcAddress = (GLLDPFNEGLGETPROCADDRESSPROC) __glld_dlsym(handle, "eglGetProcAddress");
        if (_glld_eglGetProcAddress) {
            int status = glld_loader((glld_loader_t) _glld_eglGetProcAddress);
            if (status) {
                return (status);
            }
        }

        __glld_dlclose(handle);
    }
    
    /* opengl32 */
    const char *opengl32[] = {
        "opengl32.dll", 0
    };
    
    handle = 0;
    /* attempt to load opengl32.dll */
    for (size_t i = 0; opengl32[i]; i++) {
        handle = __glld_dlopen(opengl32[i]);
        if (handle) {
            break;
        }
    }

    /* if opengl32.dll loaded */
    if (handle) {
        _glld_wglGetProcAddress = (GLLDPFNWGLGETPROCADDRESSPROC) __glld_dlsym(handle, "wglGetProcAddress");
        if (_glld_wglGetProcAddress) {
            int status = glld_loader((glld_loader_t) _glld_wglGetProcAddress);
            if (status) {
                return (status);
            }
        }

        __glld_dlclose(handle);
    }
    
    /* no library was loaded...
     * ...perform manual loading from existing libGL.so / opengl32.dll.
     * */
    return (glld_loader((glld_loader_t) glld_get_proc_address));
}

GLINT void *__glld_dlopen(const char *name) {
    /* null-check */
    if (!name) { return (0); }

    /* platform-dependant dynamic object loading */
#  if defined (GLLD_PLATFORM_LINUX) || defined (GLLD_PLATFORM_BSD) || defined (GLLD_PLATFORM_APPLE)
    void *handle = dlopen(name, RTLD_NOW | RTLD_GLOBAL);
#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE handle = LoadLibraryA(handle);
#  endif

    /* check if 'handle' is loaded */
    if (!handle) {
        return (0);
    }

    /* success */
    return (handle);
}

GLINT void *__glld_dlsym(void *handle, const char *symbol) {
    /* null-check */
    if (!handle) { return (0); }
    if (!symbol) { return (0); }

    /* platform-dependant dynamic symbol loading */
#  if defined (GLLD_PLATFORM_LINUX) || defined (GLLD_PLATFORM_BSD) || defined (GLLD_PLATFORM_APPLE)
    void *proc = dlsym(handle, symbol);
#  elif defined (GLLD_PLATFORM_WINDOWS)
    HMODULE proc = GetProcAddress(handle, symbol);
#  endif

    /* check if 'proc' was found */
    if (!proc) {
        return (0);
    }

    /* success */
    return (proc);
}

GLINT int __glld_dlclose(void *handle) {
    /* null-check */
    if (!handle) { return (0); }

    /* platform-dependant dynamic object unloading */
#  if defined (GLLD_PLATFORM_LINUX) || defined (GLLD_PLATFORM_BSD) || defined (GLLD_PLATFORM_APPLE)
    dlclose(handle);
#  elif defined (GLLD_PLATFORM_WINDOWS)
    FreeLibrary(handle);
#  endif

    return (1);
}


GLAPI int glld_unload(void) {
    /* unload all the handles that could've been loaded for this library */
    __glld_dlclose((void *) _glld_glXGetProcAddress), _glld_glXGetProcAddress = 0;
    __glld_dlclose((void *) _glld_eglGetProcAddress), _glld_eglGetProcAddress = 0;
    __glld_dlclose((void *) _glld_wglGetProcAddress), _glld_wglGetProcAddress = 0;

    /* success */
    return (1);
}


GLAPI int glld_loader(glld_loader_t load) {
    if (!load) { return (0); }
    for (size_t i = 0; _nameaddr[i].addr; i++) {
        /* If the function is already loaded, skip it... */
        if (*_nameaddr[i].addr) { continue; }

#  if !defined (__cplusplus)
        *_nameaddr[i].addr = load(_nameaddr[i].name);
#  else
        *_nameaddr[i].addr = load(_nameaddr[i].name.c_str());
#  endif /* __cplusplus */

        if (!*_nameaddr[i].addr) { return (0); }
    }

    return (1);
}


GLAPI void *glld_get_proc_address(const char *name) {
    const char *libgl[] = {

#  if defined (GLLD_PLATFORM_LINUX) || defined (GLLD_PLATFORM_BSD)
        "libGL.so",
        "libGL.so.1",
        "libGL.so.1.7.0",
        0
#  elif defined (GLLD_PLATFORM_APPLE)
        "../Frameworks/OpenGL.framework/OpenGL",
        "/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/OpenGL",
        "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL"
        0
#  elif defined (GLLD_PLATFORM_WINDOWS)
        "opengl32.dll",
        0
#  endif

    };
   
    /* try to load libGL.so / opengl32.dll */
    static void *handle = 0;
    for (size_t i = 0; libgl[i]; i++) {
        handle = __glld_dlopen(libgl[i]);
        if (handle) {
            break;
        }
    }

    /* check if libGL.so / opengl32.dll */
    if (!handle) {

#  if defined (GLLD_VERBOSE_ERROR)
        fprintf(stderr, "glld.h: could not load an OpenGL handle.\n");
#  endif

        return (0);
    }
    
    /* try to load 'name' symbol from 'handle' */
    void *proc = __glld_dlsym(handle, name);
    if (!proc) {

#  if defined (GLLD_VERBOSE_ERROR)
        fprintf(stderr, "glld.h: could not load a procedure: %s\n", name);
#  endif
    
        return (0);
    }

    /* success */
    return (proc);
}

/* SECTION: OpenGL */

<<glld-gl-func-declr-0>>

#  if defined (__cplusplus)

}

#  endif /* __cplusplus */
# endif /* _glld_impl_h_ */
#endif /* GLLD_IMPLEMENTATION */
