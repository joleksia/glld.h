/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  glld.h: OpenGL API Loader:
 *
 *      - made by: Jakub Oleksiak (yakubofficialmail@gmail.com)
 *      - version: 3.1
 *      - licence: GNU LESSER GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 *
 *
 *  OpenGL settings:
 *      - profile: core
 *      - version: 4.6 (OpenGL)
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
# define GLLD_VERSION "3.1"
# define GLLD_VERSION_MAJOR 3
# define GLLD_VERSION_MINOR 1
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
# if !defined (GL_VERSION_1_0) /* {{{ */
#  define GL_VERSION_1_0 1
#  define GL_DEPTH_BUFFER_BIT 0x00000100
#  define GL_STENCIL_BUFFER_BIT 0x00000400
#  define GL_COLOR_BUFFER_BIT 0x00004000
#  define GL_FALSE 0
#  define GL_TRUE 1
#  define GL_POINTS 0x0000
#  define GL_LINES 0x0001
#  define GL_LINE_LOOP 0x0002
#  define GL_LINE_STRIP 0x0003
#  define GL_TRIANGLES 0x0004
#  define GL_TRIANGLE_STRIP 0x0005
#  define GL_TRIANGLE_FAN 0x0006
#  define GL_QUADS 0x0007
#  define GL_NEVER 0x0200
#  define GL_LESS 0x0201
#  define GL_EQUAL 0x0202
#  define GL_LEQUAL 0x0203
#  define GL_GREATER 0x0204
#  define GL_NOTEQUAL 0x0205
#  define GL_GEQUAL 0x0206
#  define GL_ALWAYS 0x0207
#  define GL_ZERO 0
#  define GL_ONE 1
#  define GL_SRC_COLOR 0x0300
#  define GL_ONE_MINUS_SRC_COLOR 0x0301
#  define GL_SRC_ALPHA 0x0302
#  define GL_ONE_MINUS_SRC_ALPHA 0x0303
#  define GL_DST_ALPHA 0x0304
#  define GL_ONE_MINUS_DST_ALPHA 0x0305
#  define GL_DST_COLOR 0x0306
#  define GL_ONE_MINUS_DST_COLOR 0x0307
#  define GL_SRC_ALPHA_SATURATE 0x0308
#  define GL_NONE 0
#  define GL_FRONT_LEFT 0x0400
#  define GL_FRONT_RIGHT 0x0401
#  define GL_BACK_LEFT 0x0402
#  define GL_BACK_RIGHT 0x0403
#  define GL_FRONT 0x0404
#  define GL_BACK 0x0405
#  define GL_LEFT 0x0406
#  define GL_RIGHT 0x0407
#  define GL_FRONT_AND_BACK 0x0408
#  define GL_NO_ERROR 0
#  define GL_INVALID_ENUM 0x0500
#  define GL_INVALID_VALUE 0x0501
#  define GL_INVALID_OPERATION 0x0502
#  define GL_OUT_OF_MEMORY 0x0505
#  define GL_CW 0x0900
#  define GL_CCW 0x0901
#  define GL_POINT_SIZE 0x0B11
#  define GL_POINT_SIZE_RANGE 0x0B12
#  define GL_POINT_SIZE_GRANULARITY 0x0B13
#  define GL_LINE_SMOOTH 0x0B20
#  define GL_LINE_WIDTH 0x0B21
#  define GL_LINE_WIDTH_RANGE 0x0B22
#  define GL_LINE_WIDTH_GRANULARITY 0x0B23
#  define GL_POLYGON_MODE 0x0B40
#  define GL_POLYGON_SMOOTH 0x0B41
#  define GL_CULL_FACE 0x0B44
#  define GL_CULL_FACE_MODE 0x0B45
#  define GL_FRONT_FACE 0x0B46
#  define GL_DEPTH_RANGE 0x0B70
#  define GL_DEPTH_TEST 0x0B71
#  define GL_DEPTH_WRITEMASK 0x0B72
#  define GL_DEPTH_CLEAR_VALUE 0x0B73
#  define GL_DEPTH_FUNC 0x0B74
#  define GL_STENCIL_TEST 0x0B90
#  define GL_STENCIL_CLEAR_VALUE 0x0B91
#  define GL_STENCIL_FUNC 0x0B92
#  define GL_STENCIL_VALUE_MASK 0x0B93
#  define GL_STENCIL_FAIL 0x0B94
#  define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#  define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#  define GL_STENCIL_REF 0x0B97
#  define GL_STENCIL_WRITEMASK 0x0B98
#  define GL_VIEWPORT 0x0BA2
#  define GL_DITHER 0x0BD0
#  define GL_BLEND_DST 0x0BE0
#  define GL_BLEND_SRC 0x0BE1
#  define GL_BLEND 0x0BE2
#  define GL_LOGIC_OP_MODE 0x0BF0
#  define GL_DRAW_BUFFER 0x0C01
#  define GL_READ_BUFFER 0x0C02
#  define GL_SCISSOR_BOX 0x0C10
#  define GL_SCISSOR_TEST 0x0C11
#  define GL_COLOR_CLEAR_VALUE 0x0C22
#  define GL_COLOR_WRITEMASK 0x0C23
#  define GL_DOUBLEBUFFER 0x0C32
#  define GL_STEREO 0x0C33
#  define GL_LINE_SMOOTH_HINT 0x0C52
#  define GL_POLYGON_SMOOTH_HINT 0x0C53
#  define GL_UNPACK_SWAP_BYTES 0x0CF0
#  define GL_UNPACK_LSB_FIRST 0x0CF1
#  define GL_UNPACK_ROW_LENGTH 0x0CF2
#  define GL_UNPACK_SKIP_ROWS 0x0CF3
#  define GL_UNPACK_SKIP_PIXELS 0x0CF4
#  define GL_UNPACK_ALIGNMENT 0x0CF5
#  define GL_PACK_SWAP_BYTES 0x0D00
#  define GL_PACK_LSB_FIRST 0x0D01
#  define GL_PACK_ROW_LENGTH 0x0D02
#  define GL_PACK_SKIP_ROWS 0x0D03
#  define GL_PACK_SKIP_PIXELS 0x0D04
#  define GL_PACK_ALIGNMENT 0x0D05
#  define GL_MAX_TEXTURE_SIZE 0x0D33
#  define GL_MAX_VIEWPORT_DIMS 0x0D3A
#  define GL_SUBPIXEL_BITS 0x0D50
#  define GL_TEXTURE_1D 0x0DE0
#  define GL_TEXTURE_2D 0x0DE1
#  define GL_TEXTURE_WIDTH 0x1000
#  define GL_TEXTURE_HEIGHT 0x1001
#  define GL_TEXTURE_BORDER_COLOR 0x1004
#  define GL_DONT_CARE 0x1100
#  define GL_FASTEST 0x1101
#  define GL_NICEST 0x1102
#  define GL_BYTE 0x1400
#  define GL_UNSIGNED_BYTE 0x1401
#  define GL_SHORT 0x1402
#  define GL_UNSIGNED_SHORT 0x1403
#  define GL_INT 0x1404
#  define GL_UNSIGNED_INT 0x1405
#  define GL_FLOAT 0x1406
#  define GL_STACK_OVERFLOW 0x0503
#  define GL_STACK_UNDERFLOW 0x0504
#  define GL_CLEAR 0x1500
#  define GL_AND 0x1501
#  define GL_AND_REVERSE 0x1502
#  define GL_COPY 0x1503
#  define GL_AND_INVERTED 0x1504
#  define GL_NOOP 0x1505
#  define GL_XOR 0x1506
#  define GL_OR 0x1507
#  define GL_NOR 0x1508
#  define GL_EQUIV 0x1509
#  define GL_INVERT 0x150A
#  define GL_OR_REVERSE 0x150B
#  define GL_COPY_INVERTED 0x150C
#  define GL_OR_INVERTED 0x150D
#  define GL_NAND 0x150E
#  define GL_SET 0x150F
#  define GL_TEXTURE 0x1702
#  define GL_COLOR 0x1800
#  define GL_DEPTH 0x1801
#  define GL_STENCIL 0x1802
#  define GL_STENCIL_INDEX 0x1901
#  define GL_DEPTH_COMPONENT 0x1902
#  define GL_RED 0x1903
#  define GL_GREEN 0x1904
#  define GL_BLUE 0x1905
#  define GL_ALPHA 0x1906
#  define GL_RGB 0x1907
#  define GL_RGBA 0x1908
#  define GL_POINT 0x1B00
#  define GL_LINE 0x1B01
#  define GL_FILL 0x1B02
#  define GL_KEEP 0x1E00
#  define GL_REPLACE 0x1E01
#  define GL_INCR 0x1E02
#  define GL_DECR 0x1E03
#  define GL_VENDOR 0x1F00
#  define GL_RENDERER 0x1F01
#  define GL_VERSION 0x1F02
#  define GL_EXTENSIONS 0x1F03
#  define GL_NEAREST 0x2600
#  define GL_LINEAR 0x2601
#  define GL_NEAREST_MIPMAP_NEAREST 0x2700
#  define GL_LINEAR_MIPMAP_NEAREST 0x2701
#  define GL_NEAREST_MIPMAP_LINEAR 0x2702
#  define GL_LINEAR_MIPMAP_LINEAR 0x2703
#  define GL_TEXTURE_MAG_FILTER 0x2800
#  define GL_TEXTURE_MIN_FILTER 0x2801
#  define GL_TEXTURE_WRAP_S 0x2802
#  define GL_TEXTURE_WRAP_T 0x2803
#  define GL_REPEAT 0x2901
#  define GL_CURRENT_BIT 0x00000001
#  define GL_POINT_BIT 0x00000002
#  define GL_LINE_BIT 0x00000004
#  define GL_POLYGON_BIT 0x00000008
#  define GL_POLYGON_STIPPLE_BIT 0x00000010
#  define GL_PIXEL_MODE_BIT 0x00000020
#  define GL_LIGHTING_BIT 0x00000040
#  define GL_FOG_BIT 0x00000080
#  define GL_ACCUM_BUFFER_BIT 0x00000200
#  define GL_VIEWPORT_BIT 0x00000800
#  define GL_TRANSFORM_BIT 0x00001000
#  define GL_ENABLE_BIT 0x00002000
#  define GL_HINT_BIT 0x00008000
#  define GL_EVAL_BIT 0x00010000
#  define GL_LIST_BIT 0x00020000
#  define GL_TEXTURE_BIT 0x00040000
#  define GL_SCISSOR_BIT 0x00080000
#  define GL_ALL_ATTRIB_BITS 0xFFFFFFFF
#  define GL_QUAD_STRIP 0x0008
#  define GL_POLYGON 0x0009
#  define GL_ACCUM 0x0100
#  define GL_LOAD 0x0101
#  define GL_RETURN 0x0102
#  define GL_MULT 0x0103
#  define GL_ADD 0x0104
#  define GL_AUX0 0x0409
#  define GL_AUX1 0x040A
#  define GL_AUX2 0x040B
#  define GL_AUX3 0x040C
#  define GL_2D 0x0600
#  define GL_3D 0x0601
#  define GL_3D_COLOR 0x0602
#  define GL_3D_COLOR_TEXTURE 0x0603
#  define GL_4D_COLOR_TEXTURE 0x0604
#  define GL_PASS_THROUGH_TOKEN 0x0700
#  define GL_POINT_TOKEN 0x0701
#  define GL_LINE_TOKEN 0x0702
#  define GL_POLYGON_TOKEN 0x0703
#  define GL_BITMAP_TOKEN 0x0704
#  define GL_DRAW_PIXEL_TOKEN 0x0705
#  define GL_COPY_PIXEL_TOKEN 0x0706
#  define GL_LINE_RESET_TOKEN 0x0707
#  define GL_EXP 0x0800
#  define GL_EXP2 0x0801
#  define GL_COEFF 0x0A00
#  define GL_ORDER 0x0A01
#  define GL_DOMAIN 0x0A02
#  define GL_PIXEL_MAP_I_TO_I 0x0C70
#  define GL_PIXEL_MAP_S_TO_S 0x0C71
#  define GL_PIXEL_MAP_I_TO_R 0x0C72
#  define GL_PIXEL_MAP_I_TO_G 0x0C73
#  define GL_PIXEL_MAP_I_TO_B 0x0C74
#  define GL_PIXEL_MAP_I_TO_A 0x0C75
#  define GL_PIXEL_MAP_R_TO_R 0x0C76
#  define GL_PIXEL_MAP_G_TO_G 0x0C77
#  define GL_PIXEL_MAP_B_TO_B 0x0C78
#  define GL_PIXEL_MAP_A_TO_A 0x0C79
#  define GL_CURRENT_COLOR 0x0B00
#  define GL_CURRENT_INDEX 0x0B01
#  define GL_CURRENT_NORMAL 0x0B02
#  define GL_CURRENT_TEXTURE_COORDS 0x0B03
#  define GL_CURRENT_RASTER_COLOR 0x0B04
#  define GL_CURRENT_RASTER_INDEX 0x0B05
#  define GL_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#  define GL_CURRENT_RASTER_POSITION 0x0B07
#  define GL_CURRENT_RASTER_POSITION_VALID 0x0B08
#  define GL_CURRENT_RASTER_DISTANCE 0x0B09
#  define GL_POINT_SMOOTH 0x0B10
#  define GL_LINE_STIPPLE 0x0B24
#  define GL_LINE_STIPPLE_PATTERN 0x0B25
#  define GL_LINE_STIPPLE_REPEAT 0x0B26
#  define GL_LIST_MODE 0x0B30
#  define GL_MAX_LIST_NESTING 0x0B31
#  define GL_LIST_BASE 0x0B32
#  define GL_LIST_INDEX 0x0B33
#  define GL_POLYGON_STIPPLE 0x0B42
#  define GL_EDGE_FLAG 0x0B43
#  define GL_LIGHTING 0x0B50
#  define GL_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#  define GL_LIGHT_MODEL_TWO_SIDE 0x0B52
#  define GL_LIGHT_MODEL_AMBIENT 0x0B53
#  define GL_SHADE_MODEL 0x0B54
#  define GL_COLOR_MATERIAL_FACE 0x0B55
#  define GL_COLOR_MATERIAL_PARAMETER 0x0B56
#  define GL_COLOR_MATERIAL 0x0B57
#  define GL_FOG 0x0B60
#  define GL_FOG_INDEX 0x0B61
#  define GL_FOG_DENSITY 0x0B62
#  define GL_FOG_START 0x0B63
#  define GL_FOG_END 0x0B64
#  define GL_FOG_MODE 0x0B65
#  define GL_FOG_COLOR 0x0B66
#  define GL_ACCUM_CLEAR_VALUE 0x0B80
#  define GL_MATRIX_MODE 0x0BA0
#  define GL_NORMALIZE 0x0BA1
#  define GL_MODELVIEW_STACK_DEPTH 0x0BA3
#  define GL_PROJECTION_STACK_DEPTH 0x0BA4
#  define GL_TEXTURE_STACK_DEPTH 0x0BA5
#  define GL_MODELVIEW_MATRIX 0x0BA6
#  define GL_PROJECTION_MATRIX 0x0BA7
#  define GL_TEXTURE_MATRIX 0x0BA8
#  define GL_ATTRIB_STACK_DEPTH 0x0BB0
#  define GL_ALPHA_TEST 0x0BC0
#  define GL_ALPHA_TEST_FUNC 0x0BC1
#  define GL_ALPHA_TEST_REF 0x0BC2
#  define GL_LOGIC_OP 0x0BF1
#  define GL_AUX_BUFFERS 0x0C00
#  define GL_INDEX_CLEAR_VALUE 0x0C20
#  define GL_INDEX_WRITEMASK 0x0C21
#  define GL_INDEX_MODE 0x0C30
#  define GL_RGBA_MODE 0x0C31
#  define GL_RENDER_MODE 0x0C40
#  define GL_PERSPECTIVE_CORRECTION_HINT 0x0C50
#  define GL_POINT_SMOOTH_HINT 0x0C51
#  define GL_FOG_HINT 0x0C54
#  define GL_TEXTURE_GEN_S 0x0C60
#  define GL_TEXTURE_GEN_T 0x0C61
#  define GL_TEXTURE_GEN_R 0x0C62
#  define GL_TEXTURE_GEN_Q 0x0C63
#  define GL_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#  define GL_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#  define GL_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#  define GL_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#  define GL_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#  define GL_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#  define GL_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#  define GL_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#  define GL_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#  define GL_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#  define GL_MAP_COLOR 0x0D10
#  define GL_MAP_STENCIL 0x0D11
#  define GL_INDEX_SHIFT 0x0D12
#  define GL_INDEX_OFFSET 0x0D13
#  define GL_RED_SCALE 0x0D14
#  define GL_RED_BIAS 0x0D15
#  define GL_ZOOM_X 0x0D16
#  define GL_ZOOM_Y 0x0D17
#  define GL_GREEN_SCALE 0x0D18
#  define GL_GREEN_BIAS 0x0D19
#  define GL_BLUE_SCALE 0x0D1A
#  define GL_BLUE_BIAS 0x0D1B
#  define GL_ALPHA_SCALE 0x0D1C
#  define GL_ALPHA_BIAS 0x0D1D
#  define GL_DEPTH_SCALE 0x0D1E
#  define GL_DEPTH_BIAS 0x0D1F
#  define GL_MAX_EVAL_ORDER 0x0D30
#  define GL_MAX_LIGHTS 0x0D31
#  define GL_MAX_CLIP_PLANES 0x0D32
#  define GL_MAX_PIXEL_MAP_TABLE 0x0D34
#  define GL_MAX_ATTRIB_STACK_DEPTH 0x0D35
#  define GL_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#  define GL_MAX_NAME_STACK_DEPTH 0x0D37
#  define GL_MAX_PROJECTION_STACK_DEPTH 0x0D38
#  define GL_MAX_TEXTURE_STACK_DEPTH 0x0D39
#  define GL_INDEX_BITS 0x0D51
#  define GL_RED_BITS 0x0D52
#  define GL_GREEN_BITS 0x0D53
#  define GL_BLUE_BITS 0x0D54
#  define GL_ALPHA_BITS 0x0D55
#  define GL_DEPTH_BITS 0x0D56
#  define GL_STENCIL_BITS 0x0D57
#  define GL_ACCUM_RED_BITS 0x0D58
#  define GL_ACCUM_GREEN_BITS 0x0D59
#  define GL_ACCUM_BLUE_BITS 0x0D5A
#  define GL_ACCUM_ALPHA_BITS 0x0D5B
#  define GL_NAME_STACK_DEPTH 0x0D70
#  define GL_AUTO_NORMAL 0x0D80
#  define GL_MAP1_COLOR_4 0x0D90
#  define GL_MAP1_INDEX 0x0D91
#  define GL_MAP1_NORMAL 0x0D92
#  define GL_MAP1_TEXTURE_COORD_1 0x0D93
#  define GL_MAP1_TEXTURE_COORD_2 0x0D94
#  define GL_MAP1_TEXTURE_COORD_3 0x0D95
#  define GL_MAP1_TEXTURE_COORD_4 0x0D96
#  define GL_MAP1_VERTEX_3 0x0D97
#  define GL_MAP1_VERTEX_4 0x0D98
#  define GL_MAP2_COLOR_4 0x0DB0
#  define GL_MAP2_INDEX 0x0DB1
#  define GL_MAP2_NORMAL 0x0DB2
#  define GL_MAP2_TEXTURE_COORD_1 0x0DB3
#  define GL_MAP2_TEXTURE_COORD_2 0x0DB4
#  define GL_MAP2_TEXTURE_COORD_3 0x0DB5
#  define GL_MAP2_TEXTURE_COORD_4 0x0DB6
#  define GL_MAP2_VERTEX_3 0x0DB7
#  define GL_MAP2_VERTEX_4 0x0DB8
#  define GL_MAP1_GRID_DOMAIN 0x0DD0
#  define GL_MAP1_GRID_SEGMENTS 0x0DD1
#  define GL_MAP2_GRID_DOMAIN 0x0DD2
#  define GL_MAP2_GRID_SEGMENTS 0x0DD3
#  define GL_TEXTURE_COMPONENTS 0x1003
#  define GL_TEXTURE_BORDER 0x1005
#  define GL_AMBIENT 0x1200
#  define GL_DIFFUSE 0x1201
#  define GL_SPECULAR 0x1202
#  define GL_POSITION 0x1203
#  define GL_SPOT_DIRECTION 0x1204
#  define GL_SPOT_EXPONENT 0x1205
#  define GL_SPOT_CUTOFF 0x1206
#  define GL_CONSTANT_ATTENUATION 0x1207
#  define GL_LINEAR_ATTENUATION 0x1208
#  define GL_QUADRATIC_ATTENUATION 0x1209
#  define GL_COMPILE 0x1300
#  define GL_COMPILE_AND_EXECUTE 0x1301
#  define GL_2_BYTES 0x1407
#  define GL_3_BYTES 0x1408
#  define GL_4_BYTES 0x1409
#  define GL_EMISSION 0x1600
#  define GL_SHININESS 0x1601
#  define GL_AMBIENT_AND_DIFFUSE 0x1602
#  define GL_COLOR_INDEXES 0x1603
#  define GL_MODELVIEW 0x1700
#  define GL_PROJECTION 0x1701
#  define GL_COLOR_INDEX 0x1900
#  define GL_LUMINANCE 0x1909
#  define GL_LUMINANCE_ALPHA 0x190A
#  define GL_BITMAP 0x1A00
#  define GL_RENDER 0x1C00
#  define GL_FEEDBACK 0x1C01
#  define GL_SELECT 0x1C02
#  define GL_FLAT 0x1D00
#  define GL_SMOOTH 0x1D01
#  define GL_S 0x2000
#  define GL_T 0x2001
#  define GL_R 0x2002
#  define GL_Q 0x2003
#  define GL_MODULATE 0x2100
#  define GL_DECAL 0x2101
#  define GL_TEXTURE_ENV_MODE 0x2200
#  define GL_TEXTURE_ENV_COLOR 0x2201
#  define GL_TEXTURE_ENV 0x2300
#  define GL_EYE_LINEAR 0x2400
#  define GL_OBJECT_LINEAR 0x2401
#  define GL_SPHERE_MAP 0x2402
#  define GL_TEXTURE_GEN_MODE 0x2500
#  define GL_OBJECT_PLANE 0x2501
#  define GL_EYE_PLANE 0x2502
#  define GL_CLAMP 0x2900
#  define GL_CLIP_PLANE0 0x3000
#  define GL_CLIP_PLANE1 0x3001
#  define GL_CLIP_PLANE2 0x3002
#  define GL_CLIP_PLANE3 0x3003
#  define GL_CLIP_PLANE4 0x3004
#  define GL_CLIP_PLANE5 0x3005
#  define GL_LIGHT0 0x4000
#  define GL_LIGHT1 0x4001
#  define GL_LIGHT2 0x4002
#  define GL_LIGHT3 0x4003
#  define GL_LIGHT4 0x4004
#  define GL_LIGHT5 0x4005
#  define GL_LIGHT6 0x4006
#  define GL_LIGHT7 0x4007

typedef void GLvoid;
typedef unsigned int GLenum;
typedef khronos_float_t GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef khronos_uint8_t GLubyte;
typedef khronos_int8_t GLbyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;

typedef void (APIENTRY *PFNGLCULLFACEPROC) (GLenum);
typedef void (APIENTRY *PFNGLFRONTFACEPROC) (GLenum);
typedef void (APIENTRY *PFNGLHINTPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLLINEWIDTHPROC) (GLfloat);
typedef void (APIENTRY *PFNGLPOINTSIZEPROC) (GLfloat);
typedef void (APIENTRY *PFNGLPOLYGONMODEPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLSCISSORPROC) (GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXPARAMETERFPROC) (GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXPARAMETERFVPROC) (GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLTEXPARAMETERIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXPARAMETERIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLTEXIMAGE1DPROC) (GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXIMAGE2DPROC) (GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLDRAWBUFFERPROC) (GLenum);
typedef void (APIENTRY *PFNGLCLEARPROC) (GLbitfield);
typedef void (APIENTRY *PFNGLCLEARCOLORPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCLEARSTENCILPROC) (GLint);
typedef void (APIENTRY *PFNGLCLEARDEPTHPROC) (GLdouble);
typedef void (APIENTRY *PFNGLSTENCILMASKPROC) (GLuint);
typedef void (APIENTRY *PFNGLCOLORMASKPROC) (GLboolean, GLboolean, GLboolean, GLboolean);
typedef void (APIENTRY *PFNGLDEPTHMASKPROC) (GLboolean);
typedef void (APIENTRY *PFNGLDISABLEPROC) (GLenum);
typedef void (APIENTRY *PFNGLENABLEPROC) (GLenum);
typedef void (APIENTRY *PFNGLFINISHPROC) ();
typedef void (APIENTRY *PFNGLFLUSHPROC) ();
typedef void (APIENTRY *PFNGLBLENDFUNCPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLLOGICOPPROC) (GLenum);
typedef void (APIENTRY *PFNGLSTENCILFUNCPROC) (GLenum, GLint, GLuint);
typedef void (APIENTRY *PFNGLSTENCILOPPROC) (GLenum, GLenum, GLenum);
typedef void (APIENTRY *PFNGLDEPTHFUNCPROC) (GLenum);
typedef void (APIENTRY *PFNGLPIXELSTOREFPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLPIXELSTOREIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLREADBUFFERPROC) (GLenum);
typedef void (APIENTRY *PFNGLREADPIXELSPROC) (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, void *);
typedef void (APIENTRY *PFNGLGETBOOLEANVPROC) (GLenum, GLboolean *);
typedef void (APIENTRY *PFNGLGETDOUBLEVPROC) (GLenum, GLdouble *);
typedef GLenum (APIENTRY *PFNGLGETERRORPROC) ();
typedef void (APIENTRY *PFNGLGETFLOATVPROC) (GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETINTEGERVPROC) (GLenum, GLint *);
typedef const GLubyte * (APIENTRY *PFNGLGETSTRINGPROC) (GLenum);
typedef void (APIENTRY *PFNGLGETTEXIMAGEPROC) (GLenum, GLint, GLenum, GLenum, void *);
typedef void (APIENTRY *PFNGLGETTEXPARAMETERFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXPARAMETERIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTEXLEVELPARAMETERFVPROC) (GLenum, GLint, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXLEVELPARAMETERIVPROC) (GLenum, GLint, GLenum, GLint *);
typedef GLboolean (APIENTRY *PFNGLISENABLEDPROC) (GLenum);
typedef void (APIENTRY *PFNGLDEPTHRANGEPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVIEWPORTPROC) (GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLNEWLISTPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLENDLISTPROC) ();
typedef void (APIENTRY *PFNGLCALLLISTPROC) (GLuint);
typedef void (APIENTRY *PFNGLCALLLISTSPROC) (GLsizei, GLenum, const void *);
typedef void (APIENTRY *PFNGLDELETELISTSPROC) (GLuint, GLsizei);
typedef GLuint (APIENTRY *PFNGLGENLISTSPROC) (GLsizei);
typedef void (APIENTRY *PFNGLLISTBASEPROC) (GLuint);
typedef void (APIENTRY *PFNGLBEGINPROC) (GLenum);
typedef void (APIENTRY *PFNGLBITMAPPROC) (GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
typedef void (APIENTRY *PFNGLCOLOR3BPROC) (GLbyte, GLbyte, GLbyte);
typedef void (APIENTRY *PFNGLCOLOR3BVPROC) (const GLbyte *);
typedef void (APIENTRY *PFNGLCOLOR3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLCOLOR3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLCOLOR3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCOLOR3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLCOLOR3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLCOLOR3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLCOLOR3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLCOLOR3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLCOLOR3UBPROC) (GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLCOLOR3UBVPROC) (const GLubyte *);
typedef void (APIENTRY *PFNGLCOLOR3UIPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLCOLOR3UIVPROC) (const GLuint *);
typedef void (APIENTRY *PFNGLCOLOR3USPROC) (GLushort, GLushort, GLushort);
typedef void (APIENTRY *PFNGLCOLOR3USVPROC) (const GLushort *);
typedef void (APIENTRY *PFNGLCOLOR4BPROC) (GLbyte, GLbyte, GLbyte, GLbyte);
typedef void (APIENTRY *PFNGLCOLOR4BVPROC) (const GLbyte *);
typedef void (APIENTRY *PFNGLCOLOR4DPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLCOLOR4DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLCOLOR4FPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCOLOR4FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLCOLOR4IPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLCOLOR4IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLCOLOR4SPROC) (GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLCOLOR4SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLCOLOR4UBPROC) (GLubyte, GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLCOLOR4UBVPROC) (const GLubyte *);
typedef void (APIENTRY *PFNGLCOLOR4UIPROC) (GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLCOLOR4UIVPROC) (const GLuint *);
typedef void (APIENTRY *PFNGLCOLOR4USPROC) (GLushort, GLushort, GLushort, GLushort);
typedef void (APIENTRY *PFNGLCOLOR4USVPROC) (const GLushort *);
typedef void (APIENTRY *PFNGLEDGEFLAGPROC) (GLboolean);
typedef void (APIENTRY *PFNGLEDGEFLAGVPROC) (const GLboolean *);
typedef void (APIENTRY *PFNGLENDPROC) ();
typedef void (APIENTRY *PFNGLINDEXDPROC) (GLdouble);
typedef void (APIENTRY *PFNGLINDEXDVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLINDEXFPROC) (GLfloat);
typedef void (APIENTRY *PFNGLINDEXFVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLINDEXIPROC) (GLint);
typedef void (APIENTRY *PFNGLINDEXIVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLINDEXSPROC) (GLshort);
typedef void (APIENTRY *PFNGLINDEXSVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLNORMAL3BPROC) (GLbyte, GLbyte, GLbyte);
typedef void (APIENTRY *PFNGLNORMAL3BVPROC) (const GLbyte *);
typedef void (APIENTRY *PFNGLNORMAL3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLNORMAL3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLNORMAL3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLNORMAL3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLNORMAL3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLNORMAL3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLNORMAL3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLNORMAL3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLRASTERPOS2DPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLRASTERPOS2DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLRASTERPOS2FPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLRASTERPOS2FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLRASTERPOS2IPROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLRASTERPOS2IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLRASTERPOS2SPROC) (GLshort, GLshort);
typedef void (APIENTRY *PFNGLRASTERPOS2SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLRASTERPOS3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLRASTERPOS3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLRASTERPOS3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLRASTERPOS3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLRASTERPOS3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLRASTERPOS3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLRASTERPOS3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLRASTERPOS3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLRASTERPOS4DPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLRASTERPOS4DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLRASTERPOS4FPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLRASTERPOS4FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLRASTERPOS4IPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLRASTERPOS4IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLRASTERPOS4SPROC) (GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLRASTERPOS4SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLRECTDPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLRECTDVPROC) (const GLdouble *, const GLdouble *);
typedef void (APIENTRY *PFNGLRECTFPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLRECTFVPROC) (const GLfloat *, const GLfloat *);
typedef void (APIENTRY *PFNGLRECTIPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLRECTIVPROC) (const GLint *, const GLint *);
typedef void (APIENTRY *PFNGLRECTSPROC) (GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLRECTSVPROC) (const GLshort *, const GLshort *);
typedef void (APIENTRY *PFNGLTEXCOORD1DPROC) (GLdouble);
typedef void (APIENTRY *PFNGLTEXCOORD1DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLTEXCOORD1FPROC) (GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD1FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD1IPROC) (GLint);
typedef void (APIENTRY *PFNGLTEXCOORD1IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLTEXCOORD1SPROC) (GLshort);
typedef void (APIENTRY *PFNGLTEXCOORD1SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLTEXCOORD2DPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLTEXCOORD2DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLTEXCOORD2FPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD2FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD2IPROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLTEXCOORD2IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLTEXCOORD2SPROC) (GLshort, GLshort);
typedef void (APIENTRY *PFNGLTEXCOORD2SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLTEXCOORD3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLTEXCOORD3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLTEXCOORD3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLTEXCOORD3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLTEXCOORD3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLTEXCOORD3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLTEXCOORD4DPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLTEXCOORD4DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLTEXCOORD4FPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTEXCOORD4FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLTEXCOORD4IPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLTEXCOORD4IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLTEXCOORD4SPROC) (GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLTEXCOORD4SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLVERTEX2DPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEX2DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEX2FPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX2FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEX2IPROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEX2IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLVERTEX2SPROC) (GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEX2SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLVERTEX3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEX3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEX3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEX3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEX3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLVERTEX3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEX3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLVERTEX4DPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEX4DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEX4FPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEX4FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEX4IPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEX4IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLVERTEX4SPROC) (GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEX4SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLCLIPPLANEPROC) (GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLCOLORMATERIALPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLFOGFPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLFOGFVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLFOGIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLFOGIVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLLIGHTFPROC) (GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLLIGHTFVPROC) (GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLLIGHTIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLLIGHTIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLLIGHTMODELFPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLLIGHTMODELFVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLLIGHTMODELIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLLIGHTMODELIVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLLINESTIPPLEPROC) (GLint, GLushort);
typedef void (APIENTRY *PFNGLMATERIALFPROC) (GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLMATERIALFVPROC) (GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLMATERIALIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLMATERIALIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLPOLYGONSTIPPLEPROC) (const GLubyte *);
typedef void (APIENTRY *PFNGLSHADEMODELPROC) (GLenum);
typedef void (APIENTRY *PFNGLTEXENVFPROC) (GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXENVFVPROC) (GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLTEXENVIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXENVIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLTEXGENDPROC) (GLenum, GLenum, GLdouble);
typedef void (APIENTRY *PFNGLTEXGENDVPROC) (GLenum, GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLTEXGENFPROC) (GLenum, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXGENFVPROC) (GLenum, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLTEXGENIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXGENIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLFEEDBACKBUFFERPROC) (GLsizei, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLSELECTBUFFERPROC) (GLsizei, GLuint *);
typedef GLint (APIENTRY *PFNGLRENDERMODEPROC) (GLenum);
typedef void (APIENTRY *PFNGLINITNAMESPROC) ();
typedef void (APIENTRY *PFNGLLOADNAMEPROC) (GLuint);
typedef void (APIENTRY *PFNGLPASSTHROUGHPROC) (GLfloat);
typedef void (APIENTRY *PFNGLPOPNAMEPROC) ();
typedef void (APIENTRY *PFNGLPUSHNAMEPROC) (GLuint);
typedef void (APIENTRY *PFNGLCLEARACCUMPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCLEARINDEXPROC) (GLfloat);
typedef void (APIENTRY *PFNGLINDEXMASKPROC) (GLuint);
typedef void (APIENTRY *PFNGLACCUMPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLPOPATTRIBPROC) ();
typedef void (APIENTRY *PFNGLPUSHATTRIBPROC) (GLbitfield);
typedef void (APIENTRY *PFNGLMAP1DPROC) (GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
typedef void (APIENTRY *PFNGLMAP1FPROC) (GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
typedef void (APIENTRY *PFNGLMAP2DPROC) (GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
typedef void (APIENTRY *PFNGLMAP2FPROC) (GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
typedef void (APIENTRY *PFNGLMAPGRID1DPROC) (GLint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLMAPGRID1FPROC) (GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLMAPGRID2DPROC) (GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLMAPGRID2FPROC) (GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLEVALCOORD1DPROC) (GLdouble);
typedef void (APIENTRY *PFNGLEVALCOORD1DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLEVALCOORD1FPROC) (GLfloat);
typedef void (APIENTRY *PFNGLEVALCOORD1FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLEVALCOORD2DPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLEVALCOORD2DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLEVALCOORD2FPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLEVALCOORD2FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLEVALMESH1PROC) (GLenum, GLint, GLint);
typedef void (APIENTRY *PFNGLEVALPOINT1PROC) (GLint);
typedef void (APIENTRY *PFNGLEVALMESH2PROC) (GLenum, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLEVALPOINT2PROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLALPHAFUNCPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLPIXELZOOMPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPIXELTRANSFERFPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLPIXELTRANSFERIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLPIXELMAPFVPROC) (GLenum, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLPIXELMAPUIVPROC) (GLenum, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLPIXELMAPUSVPROC) (GLenum, GLsizei, const GLushort *);
typedef void (APIENTRY *PFNGLCOPYPIXELSPROC) (GLint, GLint, GLsizei, GLsizei, GLenum);
typedef void (APIENTRY *PFNGLDRAWPIXELSPROC) (GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLGETCLIPPLANEPROC) (GLenum, GLdouble *);
typedef void (APIENTRY *PFNGLGETLIGHTFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETLIGHTIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETMAPDVPROC) (GLenum, GLenum, GLdouble *);
typedef void (APIENTRY *PFNGLGETMAPFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETMAPIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETMATERIALFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETMATERIALIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETPIXELMAPFVPROC) (GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETPIXELMAPUIVPROC) (GLenum, GLuint *);
typedef void (APIENTRY *PFNGLGETPIXELMAPUSVPROC) (GLenum, GLushort *);
typedef void (APIENTRY *PFNGLGETPOLYGONSTIPPLEPROC) (GLubyte *);
typedef void (APIENTRY *PFNGLGETTEXENVFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXENVIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTEXGENDVPROC) (GLenum, GLenum, GLdouble *);
typedef void (APIENTRY *PFNGLGETTEXGENFVPROC) (GLenum, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXGENIVPROC) (GLenum, GLenum, GLint *);
typedef GLboolean (APIENTRY *PFNGLISLISTPROC) (GLuint);
typedef void (APIENTRY *PFNGLFRUSTUMPROC) (GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLLOADIDENTITYPROC) ();
typedef void (APIENTRY *PFNGLLOADMATRIXFPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLLOADMATRIXDPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLMATRIXMODEPROC) (GLenum);
typedef void (APIENTRY *PFNGLMULTMATRIXFPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLMULTMATRIXDPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLORTHOPROC) (GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLPOPMATRIXPROC) ();
typedef void (APIENTRY *PFNGLPUSHMATRIXPROC) ();
typedef void (APIENTRY *PFNGLROTATEDPROC) (GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLROTATEFPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLSCALEDPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLSCALEFPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLTRANSLATEDPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLTRANSLATEFPROC) (GLfloat, GLfloat, GLfloat);

# endif /* GL_VERSION_1_0 */ /* }}} */
# if !defined (GL_VERSION_1_1) /* {{{ */
#  define GL_VERSION_1_1 1
#  define GL_COLOR_LOGIC_OP 0x0BF2
#  define GL_POLYGON_OFFSET_UNITS 0x2A00
#  define GL_POLYGON_OFFSET_POINT 0x2A01
#  define GL_POLYGON_OFFSET_LINE 0x2A02
#  define GL_POLYGON_OFFSET_FILL 0x8037
#  define GL_POLYGON_OFFSET_FACTOR 0x8038
#  define GL_TEXTURE_BINDING_1D 0x8068
#  define GL_TEXTURE_BINDING_2D 0x8069
#  define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#  define GL_TEXTURE_RED_SIZE 0x805C
#  define GL_TEXTURE_GREEN_SIZE 0x805D
#  define GL_TEXTURE_BLUE_SIZE 0x805E
#  define GL_TEXTURE_ALPHA_SIZE 0x805F
#  define GL_DOUBLE 0x140A
#  define GL_PROXY_TEXTURE_1D 0x8063
#  define GL_PROXY_TEXTURE_2D 0x8064
#  define GL_R3_G3_B2 0x2A10
#  define GL_RGB4 0x804F
#  define GL_RGB5 0x8050
#  define GL_RGB8 0x8051
#  define GL_RGB10 0x8052
#  define GL_RGB12 0x8053
#  define GL_RGB16 0x8054
#  define GL_RGBA2 0x8055
#  define GL_RGBA4 0x8056
#  define GL_RGB5_A1 0x8057
#  define GL_RGBA8 0x8058
#  define GL_RGB10_A2 0x8059
#  define GL_RGBA12 0x805A
#  define GL_RGBA16 0x805B
#  define GL_CLIENT_PIXEL_STORE_BIT 0x00000001
#  define GL_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#  define GL_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#  define GL_VERTEX_ARRAY_POINTER 0x808E
#  define GL_NORMAL_ARRAY_POINTER 0x808F
#  define GL_COLOR_ARRAY_POINTER 0x8090
#  define GL_INDEX_ARRAY_POINTER 0x8091
#  define GL_TEXTURE_COORD_ARRAY_POINTER 0x8092
#  define GL_EDGE_FLAG_ARRAY_POINTER 0x8093
#  define GL_FEEDBACK_BUFFER_POINTER 0x0DF0
#  define GL_SELECTION_BUFFER_POINTER 0x0DF3
#  define GL_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#  define GL_INDEX_LOGIC_OP 0x0BF1
#  define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#  define GL_FEEDBACK_BUFFER_SIZE 0x0DF1
#  define GL_FEEDBACK_BUFFER_TYPE 0x0DF2
#  define GL_SELECTION_BUFFER_SIZE 0x0DF4
#  define GL_VERTEX_ARRAY 0x8074
#  define GL_NORMAL_ARRAY 0x8075
#  define GL_COLOR_ARRAY 0x8076
#  define GL_INDEX_ARRAY 0x8077
#  define GL_TEXTURE_COORD_ARRAY 0x8078
#  define GL_EDGE_FLAG_ARRAY 0x8079
#  define GL_VERTEX_ARRAY_SIZE 0x807A
#  define GL_VERTEX_ARRAY_TYPE 0x807B
#  define GL_VERTEX_ARRAY_STRIDE 0x807C
#  define GL_NORMAL_ARRAY_TYPE 0x807E
#  define GL_NORMAL_ARRAY_STRIDE 0x807F
#  define GL_COLOR_ARRAY_SIZE 0x8081
#  define GL_COLOR_ARRAY_TYPE 0x8082
#  define GL_COLOR_ARRAY_STRIDE 0x8083
#  define GL_INDEX_ARRAY_TYPE 0x8085
#  define GL_INDEX_ARRAY_STRIDE 0x8086
#  define GL_TEXTURE_COORD_ARRAY_SIZE 0x8088
#  define GL_TEXTURE_COORD_ARRAY_TYPE 0x8089
#  define GL_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#  define GL_EDGE_FLAG_ARRAY_STRIDE 0x808C
#  define GL_TEXTURE_LUMINANCE_SIZE 0x8060
#  define GL_TEXTURE_INTENSITY_SIZE 0x8061
#  define GL_TEXTURE_PRIORITY 0x8066
#  define GL_TEXTURE_RESIDENT 0x8067
#  define GL_ALPHA4 0x803B
#  define GL_ALPHA8 0x803C
#  define GL_ALPHA12 0x803D
#  define GL_ALPHA16 0x803E
#  define GL_LUMINANCE4 0x803F
#  define GL_LUMINANCE8 0x8040
#  define GL_LUMINANCE12 0x8041
#  define GL_LUMINANCE16 0x8042
#  define GL_LUMINANCE4_ALPHA4 0x8043
#  define GL_LUMINANCE6_ALPHA2 0x8044
#  define GL_LUMINANCE8_ALPHA8 0x8045
#  define GL_LUMINANCE12_ALPHA4 0x8046
#  define GL_LUMINANCE12_ALPHA12 0x8047
#  define GL_LUMINANCE16_ALPHA16 0x8048
#  define GL_INTENSITY 0x8049
#  define GL_INTENSITY4 0x804A
#  define GL_INTENSITY8 0x804B
#  define GL_INTENSITY12 0x804C
#  define GL_INTENSITY16 0x804D
#  define GL_V2F 0x2A20
#  define GL_V3F 0x2A21
#  define GL_C4UB_V2F 0x2A22
#  define GL_C4UB_V3F 0x2A23
#  define GL_C3F_V3F 0x2A24
#  define GL_N3F_V3F 0x2A25
#  define GL_C4F_N3F_V3F 0x2A26
#  define GL_T2F_V3F 0x2A27
#  define GL_T4F_V4F 0x2A28
#  define GL_T2F_C4UB_V3F 0x2A29
#  define GL_T2F_C3F_V3F 0x2A2A
#  define GL_T2F_N3F_V3F 0x2A2B
#  define GL_T2F_C4F_N3F_V3F 0x2A2C
#  define GL_T4F_C4F_N3F_V4F 0x2A2D

typedef khronos_float_t GLclampf;
typedef double GLclampd;

typedef void (APIENTRY *PFNGLDRAWARRAYSPROC) (GLenum, GLint, GLsizei);
typedef void (APIENTRY *PFNGLDRAWELEMENTSPROC) (GLenum, GLsizei, GLenum, const void *);
typedef void (APIENTRY *PFNGLGETPOINTERVPROC) (GLenum, void **);
typedef void (APIENTRY *PFNGLPOLYGONOFFSETPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCOPYTEXIMAGE1DPROC) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
typedef void (APIENTRY *PFNGLCOPYTEXIMAGE2DPROC) (GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
typedef void (APIENTRY *PFNGLCOPYTEXSUBIMAGE1DPROC) (GLenum, GLint, GLint, GLint, GLint, GLsizei);
typedef void (APIENTRY *PFNGLCOPYTEXSUBIMAGE2DPROC) (GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXSUBIMAGE1DPROC) (GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXSUBIMAGE2DPROC) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLBINDTEXTUREPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDELETETEXTURESPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENTEXTURESPROC) (GLsizei, GLuint *);
typedef GLboolean (APIENTRY *PFNGLISTEXTUREPROC) (GLuint);
typedef void (APIENTRY *PFNGLARRAYELEMENTPROC) (GLint);
typedef void (APIENTRY *PFNGLCOLORPOINTERPROC) (GLint, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLDISABLECLIENTSTATEPROC) (GLenum);
typedef void (APIENTRY *PFNGLEDGEFLAGPOINTERPROC) (GLsizei, const void *);
typedef void (APIENTRY *PFNGLENABLECLIENTSTATEPROC) (GLenum);
typedef void (APIENTRY *PFNGLINDEXPOINTERPROC) (GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLINTERLEAVEDARRAYSPROC) (GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLNORMALPOINTERPROC) (GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLTEXCOORDPOINTERPROC) (GLint, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLVERTEXPOINTERPROC) (GLint, GLenum, GLsizei, const void *);
typedef GLboolean (APIENTRY *PFNGLARETEXTURESRESIDENTPROC) (GLsizei, const GLuint *, GLboolean *);
typedef void (APIENTRY *PFNGLPRIORITIZETEXTURESPROC) (GLsizei, const GLuint *, const GLfloat *);
typedef void (APIENTRY *PFNGLINDEXUBPROC) (GLubyte);
typedef void (APIENTRY *PFNGLINDEXUBVPROC) (const GLubyte *);
typedef void (APIENTRY *PFNGLPOPCLIENTATTRIBPROC) ();
typedef void (APIENTRY *PFNGLPUSHCLIENTATTRIBPROC) (GLbitfield);

# endif /* GL_VERSION_1_1 */ /* }}} */
# if !defined (GL_VERSION_1_2) /* {{{ */
#  define GL_VERSION_1_2 1
#  define GL_UNSIGNED_BYTE_3_3_2 0x8032
#  define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#  define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#  define GL_UNSIGNED_INT_8_8_8_8 0x8035
#  define GL_UNSIGNED_INT_10_10_10_2 0x8036
#  define GL_TEXTURE_BINDING_3D 0x806A
#  define GL_PACK_SKIP_IMAGES 0x806B
#  define GL_PACK_IMAGE_HEIGHT 0x806C
#  define GL_UNPACK_SKIP_IMAGES 0x806D
#  define GL_UNPACK_IMAGE_HEIGHT 0x806E
#  define GL_TEXTURE_3D 0x806F
#  define GL_PROXY_TEXTURE_3D 0x8070
#  define GL_TEXTURE_DEPTH 0x8071
#  define GL_TEXTURE_WRAP_R 0x8072
#  define GL_MAX_3D_TEXTURE_SIZE 0x8073
#  define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#  define GL_UNSIGNED_SHORT_5_6_5 0x8363
#  define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#  define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#  define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#  define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#  define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#  define GL_BGR 0x80E0
#  define GL_BGRA 0x80E1
#  define GL_MAX_ELEMENTS_VERTICES 0x80E8
#  define GL_MAX_ELEMENTS_INDICES 0x80E9
#  define GL_CLAMP_TO_EDGE 0x812F
#  define GL_TEXTURE_MIN_LOD 0x813A
#  define GL_TEXTURE_MAX_LOD 0x813B
#  define GL_TEXTURE_BASE_LEVEL 0x813C
#  define GL_TEXTURE_MAX_LEVEL 0x813D
#  define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#  define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#  define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#  define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#  define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#  define GL_RESCALE_NORMAL 0x803A
#  define GL_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#  define GL_SINGLE_COLOR 0x81F9
#  define GL_SEPARATE_SPECULAR_COLOR 0x81FA
#  define GL_ALIASED_POINT_SIZE_RANGE 0x846D

typedef void (APIENTRY *PFNGLDRAWRANGEELEMENTSPROC) (GLenum, GLuint, GLuint, GLsizei, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXIMAGE3DPROC) (GLenum, GLint, GLint, GLsizei, GLsizei, GLsizei, GLint, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXSUBIMAGE3DPROC) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLCOPYTEXSUBIMAGE3DPROC) (GLenum, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);

# endif /* GL_VERSION_1_2 */ /* }}} */
# if !defined (GL_VERSION_1_3) /* {{{ */
#  define GL_VERSION_1_3 1
#  define GL_TEXTURE0 0x84C0
#  define GL_TEXTURE1 0x84C1
#  define GL_TEXTURE2 0x84C2
#  define GL_TEXTURE3 0x84C3
#  define GL_TEXTURE4 0x84C4
#  define GL_TEXTURE5 0x84C5
#  define GL_TEXTURE6 0x84C6
#  define GL_TEXTURE7 0x84C7
#  define GL_TEXTURE8 0x84C8
#  define GL_TEXTURE9 0x84C9
#  define GL_TEXTURE10 0x84CA
#  define GL_TEXTURE11 0x84CB
#  define GL_TEXTURE12 0x84CC
#  define GL_TEXTURE13 0x84CD
#  define GL_TEXTURE14 0x84CE
#  define GL_TEXTURE15 0x84CF
#  define GL_TEXTURE16 0x84D0
#  define GL_TEXTURE17 0x84D1
#  define GL_TEXTURE18 0x84D2
#  define GL_TEXTURE19 0x84D3
#  define GL_TEXTURE20 0x84D4
#  define GL_TEXTURE21 0x84D5
#  define GL_TEXTURE22 0x84D6
#  define GL_TEXTURE23 0x84D7
#  define GL_TEXTURE24 0x84D8
#  define GL_TEXTURE25 0x84D9
#  define GL_TEXTURE26 0x84DA
#  define GL_TEXTURE27 0x84DB
#  define GL_TEXTURE28 0x84DC
#  define GL_TEXTURE29 0x84DD
#  define GL_TEXTURE30 0x84DE
#  define GL_TEXTURE31 0x84DF
#  define GL_ACTIVE_TEXTURE 0x84E0
#  define GL_MULTISAMPLE 0x809D
#  define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#  define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#  define GL_SAMPLE_COVERAGE 0x80A0
#  define GL_SAMPLE_BUFFERS 0x80A8
#  define GL_SAMPLES 0x80A9
#  define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#  define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#  define GL_TEXTURE_CUBE_MAP 0x8513
#  define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#  define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#  define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#  define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#  define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#  define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#  define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#  define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#  define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#  define GL_COMPRESSED_RGB 0x84ED
#  define GL_COMPRESSED_RGBA 0x84EE
#  define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#  define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#  define GL_TEXTURE_COMPRESSED 0x86A1
#  define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#  define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#  define GL_CLAMP_TO_BORDER 0x812D
#  define GL_CLIENT_ACTIVE_TEXTURE 0x84E1
#  define GL_MAX_TEXTURE_UNITS 0x84E2
#  define GL_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#  define GL_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#  define GL_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#  define GL_TRANSPOSE_COLOR_MATRIX 0x84E6
#  define GL_MULTISAMPLE_BIT 0x20000000
#  define GL_NORMAL_MAP 0x8511
#  define GL_REFLECTION_MAP 0x8512
#  define GL_COMPRESSED_ALPHA 0x84E9
#  define GL_COMPRESSED_LUMINANCE 0x84EA
#  define GL_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#  define GL_COMPRESSED_INTENSITY 0x84EC
#  define GL_COMBINE 0x8570
#  define GL_COMBINE_RGB 0x8571
#  define GL_COMBINE_ALPHA 0x8572
#  define GL_SOURCE0_RGB 0x8580
#  define GL_SOURCE1_RGB 0x8581
#  define GL_SOURCE2_RGB 0x8582
#  define GL_SOURCE0_ALPHA 0x8588
#  define GL_SOURCE1_ALPHA 0x8589
#  define GL_SOURCE2_ALPHA 0x858A
#  define GL_OPERAND0_RGB 0x8590
#  define GL_OPERAND1_RGB 0x8591
#  define GL_OPERAND2_RGB 0x8592
#  define GL_OPERAND0_ALPHA 0x8598
#  define GL_OPERAND1_ALPHA 0x8599
#  define GL_OPERAND2_ALPHA 0x859A
#  define GL_RGB_SCALE 0x8573
#  define GL_ADD_SIGNED 0x8574
#  define GL_INTERPOLATE 0x8575
#  define GL_SUBTRACT 0x84E7
#  define GL_CONSTANT 0x8576
#  define GL_PRIMARY_COLOR 0x8577
#  define GL_PREVIOUS 0x8578
#  define GL_DOT3_RGB 0x86AE
#  define GL_DOT3_RGBA 0x86AF

typedef void (APIENTRY *PFNGLACTIVETEXTUREPROC) (GLenum);
typedef void (APIENTRY *PFNGLSAMPLECOVERAGEPROC) (GLfloat, GLboolean);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXIMAGE3DPROC) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLsizei, GLint, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXIMAGE2DPROC) (GLenum, GLint, GLenum, GLsizei, GLsizei, GLint, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXIMAGE1DPROC) (GLenum, GLint, GLenum, GLsizei, GLint, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) (GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) (GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) (GLenum, GLint, GLint, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLGETCOMPRESSEDTEXIMAGEPROC) (GLenum, GLint, void *);
typedef void (APIENTRY *PFNGLCLIENTACTIVETEXTUREPROC) (GLenum);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1DPROC) (GLenum, GLdouble);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1DVPROC) (GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1FPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1FVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1IPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1IVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1SPROC) (GLenum, GLshort);
typedef void (APIENTRY *PFNGLMULTITEXCOORD1SVPROC) (GLenum, const GLshort *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2DPROC) (GLenum, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2DVPROC) (GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2FPROC) (GLenum, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2FVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2IPROC) (GLenum, GLint, GLint);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2IVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2SPROC) (GLenum, GLshort, GLshort);
typedef void (APIENTRY *PFNGLMULTITEXCOORD2SVPROC) (GLenum, const GLshort *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3DPROC) (GLenum, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3DVPROC) (GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3FPROC) (GLenum, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3FVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3IPROC) (GLenum, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3IVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3SPROC) (GLenum, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLMULTITEXCOORD3SVPROC) (GLenum, const GLshort *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4DPROC) (GLenum, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4DVPROC) (GLenum, const GLdouble *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4FPROC) (GLenum, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4FVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4IPROC) (GLenum, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4IVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4SPROC) (GLenum, GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLMULTITEXCOORD4SVPROC) (GLenum, const GLshort *);
typedef void (APIENTRY *PFNGLLOADTRANSPOSEMATRIXFPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLLOADTRANSPOSEMATRIXDPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLMULTTRANSPOSEMATRIXFPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLMULTTRANSPOSEMATRIXDPROC) (const GLdouble *);

# endif /* GL_VERSION_1_3 */ /* }}} */
# if !defined (GL_VERSION_1_4) /* {{{ */
#  define GL_VERSION_1_4 1
#  define GL_BLEND_DST_RGB 0x80C8
#  define GL_BLEND_SRC_RGB 0x80C9
#  define GL_BLEND_DST_ALPHA 0x80CA
#  define GL_BLEND_SRC_ALPHA 0x80CB
#  define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#  define GL_DEPTH_COMPONENT16 0x81A5
#  define GL_DEPTH_COMPONENT24 0x81A6
#  define GL_DEPTH_COMPONENT32 0x81A7
#  define GL_MIRRORED_REPEAT 0x8370
#  define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#  define GL_TEXTURE_LOD_BIAS 0x8501
#  define GL_INCR_WRAP 0x8507
#  define GL_DECR_WRAP 0x8508
#  define GL_TEXTURE_DEPTH_SIZE 0x884A
#  define GL_TEXTURE_COMPARE_MODE 0x884C
#  define GL_TEXTURE_COMPARE_FUNC 0x884D
#  define GL_POINT_SIZE_MIN 0x8126
#  define GL_POINT_SIZE_MAX 0x8127
#  define GL_POINT_DISTANCE_ATTENUATION 0x8129
#  define GL_GENERATE_MIPMAP 0x8191
#  define GL_GENERATE_MIPMAP_HINT 0x8192
#  define GL_FOG_COORDINATE_SOURCE 0x8450
#  define GL_FOG_COORDINATE 0x8451
#  define GL_FRAGMENT_DEPTH 0x8452
#  define GL_CURRENT_FOG_COORDINATE 0x8453
#  define GL_FOG_COORDINATE_ARRAY_TYPE 0x8454
#  define GL_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#  define GL_FOG_COORDINATE_ARRAY_POINTER 0x8456
#  define GL_FOG_COORDINATE_ARRAY 0x8457
#  define GL_COLOR_SUM 0x8458
#  define GL_CURRENT_SECONDARY_COLOR 0x8459
#  define GL_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#  define GL_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#  define GL_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#  define GL_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#  define GL_SECONDARY_COLOR_ARRAY 0x845E
#  define GL_TEXTURE_FILTER_CONTROL 0x8500
#  define GL_DEPTH_TEXTURE_MODE 0x884B
#  define GL_COMPARE_R_TO_TEXTURE 0x884E
#  define GL_BLEND_COLOR 0x8005
#  define GL_BLEND_EQUATION 0x8009
#  define GL_CONSTANT_COLOR 0x8001
#  define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#  define GL_CONSTANT_ALPHA 0x8003
#  define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#  define GL_FUNC_ADD 0x8006
#  define GL_FUNC_REVERSE_SUBTRACT 0x800B
#  define GL_FUNC_SUBTRACT 0x800A
#  define GL_MIN 0x8007
#  define GL_MAX 0x8008

typedef void (APIENTRY *PFNGLBLENDFUNCSEPARATEPROC) (GLenum, GLenum, GLenum, GLenum);
typedef void (APIENTRY *PFNGLMULTIDRAWARRAYSPROC) (GLenum, const GLint *, const GLsizei *, GLsizei);
typedef void (APIENTRY *PFNGLMULTIDRAWELEMENTSPROC) (GLenum, const GLsizei *, GLenum, const void *const*, GLsizei);
typedef void (APIENTRY *PFNGLPOINTPARAMETERFPROC) (GLenum, GLfloat);
typedef void (APIENTRY *PFNGLPOINTPARAMETERFVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLPOINTPARAMETERIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLPOINTPARAMETERIVPROC) (GLenum, const GLint *);
typedef void (APIENTRY *PFNGLFOGCOORDFPROC) (GLfloat);
typedef void (APIENTRY *PFNGLFOGCOORDFVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLFOGCOORDDPROC) (GLdouble);
typedef void (APIENTRY *PFNGLFOGCOORDDVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLFOGCOORDPOINTERPROC) (GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3BPROC) (GLbyte, GLbyte, GLbyte);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3BVPROC) (const GLbyte *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3UBPROC) (GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3UBVPROC) (const GLubyte *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3UIPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3UIVPROC) (const GLuint *);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3USPROC) (GLushort, GLushort, GLushort);
typedef void (APIENTRY *PFNGLSECONDARYCOLOR3USVPROC) (const GLushort *);
typedef void (APIENTRY *PFNGLSECONDARYCOLORPOINTERPROC) (GLint, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLWINDOWPOS2DPROC) (GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLWINDOWPOS2DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLWINDOWPOS2FPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLWINDOWPOS2FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLWINDOWPOS2IPROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLWINDOWPOS2IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLWINDOWPOS2SPROC) (GLshort, GLshort);
typedef void (APIENTRY *PFNGLWINDOWPOS2SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLWINDOWPOS3DPROC) (GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLWINDOWPOS3DVPROC) (const GLdouble *);
typedef void (APIENTRY *PFNGLWINDOWPOS3FPROC) (GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLWINDOWPOS3FVPROC) (const GLfloat *);
typedef void (APIENTRY *PFNGLWINDOWPOS3IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLWINDOWPOS3IVPROC) (const GLint *);
typedef void (APIENTRY *PFNGLWINDOWPOS3SPROC) (GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLWINDOWPOS3SVPROC) (const GLshort *);
typedef void (APIENTRY *PFNGLBLENDCOLORPROC) (GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLBLENDEQUATIONPROC) (GLenum);

# endif /* GL_VERSION_1_4 */ /* }}} */
# if !defined (GL_VERSION_1_5) /* {{{ */
#  define GL_VERSION_1_5 1
#  define GL_BUFFER_SIZE 0x8764
#  define GL_BUFFER_USAGE 0x8765
#  define GL_QUERY_COUNTER_BITS 0x8864
#  define GL_CURRENT_QUERY 0x8865
#  define GL_QUERY_RESULT 0x8866
#  define GL_QUERY_RESULT_AVAILABLE 0x8867
#  define GL_ARRAY_BUFFER 0x8892
#  define GL_ELEMENT_ARRAY_BUFFER 0x8893
#  define GL_ARRAY_BUFFER_BINDING 0x8894
#  define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#  define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#  define GL_READ_ONLY 0x88B8
#  define GL_WRITE_ONLY 0x88B9
#  define GL_READ_WRITE 0x88BA
#  define GL_BUFFER_ACCESS 0x88BB
#  define GL_BUFFER_MAPPED 0x88BC
#  define GL_BUFFER_MAP_POINTER 0x88BD
#  define GL_STREAM_DRAW 0x88E0
#  define GL_STREAM_READ 0x88E1
#  define GL_STREAM_COPY 0x88E2
#  define GL_STATIC_DRAW 0x88E4
#  define GL_STATIC_READ 0x88E5
#  define GL_STATIC_COPY 0x88E6
#  define GL_DYNAMIC_DRAW 0x88E8
#  define GL_DYNAMIC_READ 0x88E9
#  define GL_DYNAMIC_COPY 0x88EA
#  define GL_SAMPLES_PASSED 0x8914
#  define GL_SRC1_ALPHA 0x8589
#  define GL_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#  define GL_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#  define GL_COLOR_ARRAY_BUFFER_BINDING 0x8898
#  define GL_INDEX_ARRAY_BUFFER_BINDING 0x8899
#  define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#  define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#  define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#  define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#  define GL_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#  define GL_FOG_COORD_SRC 0x8450
#  define GL_FOG_COORD 0x8451
#  define GL_CURRENT_FOG_COORD 0x8453
#  define GL_FOG_COORD_ARRAY_TYPE 0x8454
#  define GL_FOG_COORD_ARRAY_STRIDE 0x8455
#  define GL_FOG_COORD_ARRAY_POINTER 0x8456
#  define GL_FOG_COORD_ARRAY 0x8457
#  define GL_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#  define GL_SRC0_RGB 0x8580
#  define GL_SRC1_RGB 0x8581
#  define GL_SRC2_RGB 0x8582
#  define GL_SRC0_ALPHA 0x8588
#  define GL_SRC2_ALPHA 0x858A

typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;

typedef void (APIENTRY *PFNGLGENQUERIESPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLDELETEQUERIESPROC) (GLsizei, const GLuint *);
typedef GLboolean (APIENTRY *PFNGLISQUERYPROC) (GLuint);
typedef void (APIENTRY *PFNGLBEGINQUERYPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLENDQUERYPROC) (GLenum);
typedef void (APIENTRY *PFNGLGETQUERYIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETQUERYOBJECTIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETQUERYOBJECTUIVPROC) (GLuint, GLenum, GLuint *);
typedef void (APIENTRY *PFNGLBINDBUFFERPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDELETEBUFFERSPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENBUFFERSPROC) (GLsizei, GLuint *);
typedef GLboolean (APIENTRY *PFNGLISBUFFERPROC) (GLuint);
typedef void (APIENTRY *PFNGLBUFFERDATAPROC) (GLenum, GLsizeiptr, const void *, GLenum);
typedef void (APIENTRY *PFNGLBUFFERSUBDATAPROC) (GLenum, GLintptr, GLsizeiptr, const void *);
typedef void (APIENTRY *PFNGLGETBUFFERSUBDATAPROC) (GLenum, GLintptr, GLsizeiptr, void *);
typedef void * (APIENTRY *PFNGLMAPBUFFERPROC) (GLenum, GLenum);
typedef GLboolean (APIENTRY *PFNGLUNMAPBUFFERPROC) (GLenum);
typedef void (APIENTRY *PFNGLGETBUFFERPARAMETERIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETBUFFERPOINTERVPROC) (GLenum, GLenum, void **);

# endif /* GL_VERSION_1_5 */ /* }}} */
# if !defined (GL_VERSION_2_0) /* {{{ */
#  define GL_VERSION_2_0 1
#  define GL_BLEND_EQUATION_RGB 0x8009
#  define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#  define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#  define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#  define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#  define GL_CURRENT_VERTEX_ATTRIB 0x8626
#  define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#  define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#  define GL_STENCIL_BACK_FUNC 0x8800
#  define GL_STENCIL_BACK_FAIL 0x8801
#  define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#  define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#  define GL_MAX_DRAW_BUFFERS 0x8824
#  define GL_DRAW_BUFFER0 0x8825
#  define GL_DRAW_BUFFER1 0x8826
#  define GL_DRAW_BUFFER2 0x8827
#  define GL_DRAW_BUFFER3 0x8828
#  define GL_DRAW_BUFFER4 0x8829
#  define GL_DRAW_BUFFER5 0x882A
#  define GL_DRAW_BUFFER6 0x882B
#  define GL_DRAW_BUFFER7 0x882C
#  define GL_DRAW_BUFFER8 0x882D
#  define GL_DRAW_BUFFER9 0x882E
#  define GL_DRAW_BUFFER10 0x882F
#  define GL_DRAW_BUFFER11 0x8830
#  define GL_DRAW_BUFFER12 0x8831
#  define GL_DRAW_BUFFER13 0x8832
#  define GL_DRAW_BUFFER14 0x8833
#  define GL_DRAW_BUFFER15 0x8834
#  define GL_BLEND_EQUATION_ALPHA 0x883D
#  define GL_MAX_VERTEX_ATTRIBS 0x8869
#  define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#  define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#  define GL_FRAGMENT_SHADER 0x8B30
#  define GL_VERTEX_SHADER 0x8B31
#  define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#  define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#  define GL_MAX_VARYING_FLOATS 0x8B4B
#  define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#  define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#  define GL_SHADER_TYPE 0x8B4F
#  define GL_FLOAT_VEC2 0x8B50
#  define GL_FLOAT_VEC3 0x8B51
#  define GL_FLOAT_VEC4 0x8B52
#  define GL_INT_VEC2 0x8B53
#  define GL_INT_VEC3 0x8B54
#  define GL_INT_VEC4 0x8B55
#  define GL_BOOL 0x8B56
#  define GL_BOOL_VEC2 0x8B57
#  define GL_BOOL_VEC3 0x8B58
#  define GL_BOOL_VEC4 0x8B59
#  define GL_FLOAT_MAT2 0x8B5A
#  define GL_FLOAT_MAT3 0x8B5B
#  define GL_FLOAT_MAT4 0x8B5C
#  define GL_SAMPLER_1D 0x8B5D
#  define GL_SAMPLER_2D 0x8B5E
#  define GL_SAMPLER_3D 0x8B5F
#  define GL_SAMPLER_CUBE 0x8B60
#  define GL_SAMPLER_1D_SHADOW 0x8B61
#  define GL_SAMPLER_2D_SHADOW 0x8B62
#  define GL_DELETE_STATUS 0x8B80
#  define GL_COMPILE_STATUS 0x8B81
#  define GL_LINK_STATUS 0x8B82
#  define GL_VALIDATE_STATUS 0x8B83
#  define GL_INFO_LOG_LENGTH 0x8B84
#  define GL_ATTACHED_SHADERS 0x8B85
#  define GL_ACTIVE_UNIFORMS 0x8B86
#  define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#  define GL_SHADER_SOURCE_LENGTH 0x8B88
#  define GL_ACTIVE_ATTRIBUTES 0x8B89
#  define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#  define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#  define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#  define GL_CURRENT_PROGRAM 0x8B8D
#  define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#  define GL_LOWER_LEFT 0x8CA1
#  define GL_UPPER_LEFT 0x8CA2
#  define GL_STENCIL_BACK_REF 0x8CA3
#  define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#  define GL_STENCIL_BACK_WRITEMASK 0x8CA5
#  define GL_VERTEX_PROGRAM_TWO_SIDE 0x8643
#  define GL_POINT_SPRITE 0x8861
#  define GL_COORD_REPLACE 0x8862
#  define GL_MAX_TEXTURE_COORDS 0x8871

typedef char GLchar;

typedef void (APIENTRY *PFNGLBLENDEQUATIONSEPARATEPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLDRAWBUFFERSPROC) (GLsizei, const GLenum *);
typedef void (APIENTRY *PFNGLSTENCILOPSEPARATEPROC) (GLenum, GLenum, GLenum, GLenum);
typedef void (APIENTRY *PFNGLSTENCILFUNCSEPARATEPROC) (GLenum, GLenum, GLint, GLuint);
typedef void (APIENTRY *PFNGLSTENCILMASKSEPARATEPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLATTACHSHADERPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLBINDATTRIBLOCATIONPROC) (GLuint, GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLCOMPILESHADERPROC) (GLuint);
typedef GLuint (APIENTRY *PFNGLCREATEPROGRAMPROC) ();
typedef GLuint (APIENTRY *PFNGLCREATESHADERPROC) (GLenum);
typedef void (APIENTRY *PFNGLDELETEPROGRAMPROC) (GLuint);
typedef void (APIENTRY *PFNGLDELETESHADERPROC) (GLuint);
typedef void (APIENTRY *PFNGLDETACHSHADERPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLDISABLEVERTEXATTRIBARRAYPROC) (GLuint);
typedef void (APIENTRY *PFNGLENABLEVERTEXATTRIBARRAYPROC) (GLuint);
typedef void (APIENTRY *PFNGLGETACTIVEATTRIBPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (APIENTRY *PFNGLGETACTIVEUNIFORMPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLint *, GLenum *, GLchar *);
typedef void (APIENTRY *PFNGLGETATTACHEDSHADERSPROC) (GLuint, GLsizei, GLsizei *, GLuint *);
typedef GLint (APIENTRY *PFNGLGETATTRIBLOCATIONPROC) (GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLGETPROGRAMIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETPROGRAMINFOLOGPROC) (GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLGETSHADERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETSHADERINFOLOGPROC) (GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLGETSHADERSOURCEPROC) (GLuint, GLsizei, GLsizei *, GLchar *);
typedef GLint (APIENTRY *PFNGLGETUNIFORMLOCATIONPROC) (GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLGETUNIFORMFVPROC) (GLuint, GLint, GLfloat *);
typedef void (APIENTRY *PFNGLGETUNIFORMIVPROC) (GLuint, GLint, GLint *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBDVPROC) (GLuint, GLenum, GLdouble *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBFVPROC) (GLuint, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBPOINTERVPROC) (GLuint, GLenum, void **);
typedef GLboolean (APIENTRY *PFNGLISPROGRAMPROC) (GLuint);
typedef GLboolean (APIENTRY *PFNGLISSHADERPROC) (GLuint);
typedef void (APIENTRY *PFNGLLINKPROGRAMPROC) (GLuint);
typedef void (APIENTRY *PFNGLSHADERSOURCEPROC) (GLuint, GLsizei, const GLchar *const*, const GLint *);
typedef void (APIENTRY *PFNGLUSEPROGRAMPROC) (GLuint);
typedef void (APIENTRY *PFNGLUNIFORM1FPROC) (GLint, GLfloat);
typedef void (APIENTRY *PFNGLUNIFORM2FPROC) (GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLUNIFORM3FPROC) (GLint, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLUNIFORM4FPROC) (GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLUNIFORM1IPROC) (GLint, GLint);
typedef void (APIENTRY *PFNGLUNIFORM2IPROC) (GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLUNIFORM3IPROC) (GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLUNIFORM4IPROC) (GLint, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLUNIFORM1FVPROC) (GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORM2FVPROC) (GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORM3FVPROC) (GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORM4FVPROC) (GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORM1IVPROC) (GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLUNIFORM2IVPROC) (GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLUNIFORM3IVPROC) (GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLUNIFORM4IVPROC) (GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX2FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLVALIDATEPROGRAMPROC) (GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1DPROC) (GLuint, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1FPROC) (GLuint, GLfloat);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1FVPROC) (GLuint, const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1SPROC) (GLuint, GLshort);
typedef void (APIENTRY *PFNGLVERTEXATTRIB1SVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2DPROC) (GLuint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2FPROC) (GLuint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2FVPROC) (GLuint, const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2SPROC) (GLuint, GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEXATTRIB2SVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3DPROC) (GLuint, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3FPROC) (GLuint, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3FVPROC) (GLuint, const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3SPROC) (GLuint, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEXATTRIB3SVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NBVPROC) (GLuint, const GLbyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NIVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NSVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NUBPROC) (GLuint, GLubyte, GLubyte, GLubyte, GLubyte);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NUBVPROC) (GLuint, const GLubyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NUIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4NUSVPROC) (GLuint, const GLushort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4BVPROC) (GLuint, const GLbyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4DPROC) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4FPROC) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4FVPROC) (GLuint, const GLfloat *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4IVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4SPROC) (GLuint, GLshort, GLshort, GLshort, GLshort);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4SVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4UBVPROC) (GLuint, const GLubyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4UIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIB4USVPROC) (GLuint, const GLushort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBPOINTERPROC) (GLuint, GLint, GLenum, GLboolean, GLsizei, const void *);

# endif /* GL_VERSION_2_0 */ /* }}} */
# if !defined (GL_VERSION_2_1) /* {{{ */
#  define GL_VERSION_2_1 1
#  define GL_PIXEL_PACK_BUFFER 0x88EB
#  define GL_PIXEL_UNPACK_BUFFER 0x88EC
#  define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#  define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#  define GL_FLOAT_MAT2x3 0x8B65
#  define GL_FLOAT_MAT2x4 0x8B66
#  define GL_FLOAT_MAT3x2 0x8B67
#  define GL_FLOAT_MAT3x4 0x8B68
#  define GL_FLOAT_MAT4x2 0x8B69
#  define GL_FLOAT_MAT4x3 0x8B6A
#  define GL_SRGB 0x8C40
#  define GL_SRGB8 0x8C41
#  define GL_SRGB_ALPHA 0x8C42
#  define GL_SRGB8_ALPHA8 0x8C43
#  define GL_COMPRESSED_SRGB 0x8C48
#  define GL_COMPRESSED_SRGB_ALPHA 0x8C49
#  define GL_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#  define GL_SLUMINANCE_ALPHA 0x8C44
#  define GL_SLUMINANCE8_ALPHA8 0x8C45
#  define GL_SLUMINANCE 0x8C46
#  define GL_SLUMINANCE8 0x8C47
#  define GL_COMPRESSED_SLUMINANCE 0x8C4A
#  define GL_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B

typedef void (APIENTRY *PFNGLUNIFORMMATRIX2X3FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3X2FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX2X4FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4X2FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3X4FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4X3FVPROC) (GLint, GLsizei, GLboolean, const GLfloat *);

# endif /* GL_VERSION_2_1 */ /* }}} */
# if !defined (GL_VERSION_3_0) /* {{{ */
#  define GL_VERSION_3_0 1
#  define GL_COMPARE_REF_TO_TEXTURE 0x884E
#  define GL_CLIP_DISTANCE0 0x3000
#  define GL_CLIP_DISTANCE1 0x3001
#  define GL_CLIP_DISTANCE2 0x3002
#  define GL_CLIP_DISTANCE3 0x3003
#  define GL_CLIP_DISTANCE4 0x3004
#  define GL_CLIP_DISTANCE5 0x3005
#  define GL_CLIP_DISTANCE6 0x3006
#  define GL_CLIP_DISTANCE7 0x3007
#  define GL_MAX_CLIP_DISTANCES 0x0D32
#  define GL_MAJOR_VERSION 0x821B
#  define GL_MINOR_VERSION 0x821C
#  define GL_NUM_EXTENSIONS 0x821D
#  define GL_CONTEXT_FLAGS 0x821E
#  define GL_COMPRESSED_RED 0x8225
#  define GL_COMPRESSED_RG 0x8226
#  define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#  define GL_RGBA32F 0x8814
#  define GL_RGB32F 0x8815
#  define GL_RGBA16F 0x881A
#  define GL_RGB16F 0x881B
#  define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#  define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#  define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#  define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#  define GL_CLAMP_READ_COLOR 0x891C
#  define GL_FIXED_ONLY 0x891D
#  define GL_MAX_VARYING_COMPONENTS 0x8B4B
#  define GL_TEXTURE_1D_ARRAY 0x8C18
#  define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#  define GL_TEXTURE_2D_ARRAY 0x8C1A
#  define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#  define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#  define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#  define GL_R11F_G11F_B10F 0x8C3A
#  define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#  define GL_RGB9_E5 0x8C3D
#  define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#  define GL_TEXTURE_SHARED_SIZE 0x8C3F
#  define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#  define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#  define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#  define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#  define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#  define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#  define GL_PRIMITIVES_GENERATED 0x8C87
#  define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#  define GL_RASTERIZER_DISCARD 0x8C89
#  define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#  define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#  define GL_INTERLEAVED_ATTRIBS 0x8C8C
#  define GL_SEPARATE_ATTRIBS 0x8C8D
#  define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#  define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#  define GL_RGBA32UI 0x8D70
#  define GL_RGB32UI 0x8D71
#  define GL_RGBA16UI 0x8D76
#  define GL_RGB16UI 0x8D77
#  define GL_RGBA8UI 0x8D7C
#  define GL_RGB8UI 0x8D7D
#  define GL_RGBA32I 0x8D82
#  define GL_RGB32I 0x8D83
#  define GL_RGBA16I 0x8D88
#  define GL_RGB16I 0x8D89
#  define GL_RGBA8I 0x8D8E
#  define GL_RGB8I 0x8D8F
#  define GL_RED_INTEGER 0x8D94
#  define GL_GREEN_INTEGER 0x8D95
#  define GL_BLUE_INTEGER 0x8D96
#  define GL_RGB_INTEGER 0x8D98
#  define GL_RGBA_INTEGER 0x8D99
#  define GL_BGR_INTEGER 0x8D9A
#  define GL_BGRA_INTEGER 0x8D9B
#  define GL_SAMPLER_1D_ARRAY 0x8DC0
#  define GL_SAMPLER_2D_ARRAY 0x8DC1
#  define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#  define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#  define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#  define GL_UNSIGNED_INT_VEC2 0x8DC6
#  define GL_UNSIGNED_INT_VEC3 0x8DC7
#  define GL_UNSIGNED_INT_VEC4 0x8DC8
#  define GL_INT_SAMPLER_1D 0x8DC9
#  define GL_INT_SAMPLER_2D 0x8DCA
#  define GL_INT_SAMPLER_3D 0x8DCB
#  define GL_INT_SAMPLER_CUBE 0x8DCC
#  define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#  define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#  define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#  define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#  define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#  define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#  define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#  define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#  define GL_QUERY_WAIT 0x8E13
#  define GL_QUERY_NO_WAIT 0x8E14
#  define GL_QUERY_BY_REGION_WAIT 0x8E15
#  define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#  define GL_BUFFER_ACCESS_FLAGS 0x911F
#  define GL_BUFFER_MAP_LENGTH 0x9120
#  define GL_BUFFER_MAP_OFFSET 0x9121
#  define GL_DEPTH_COMPONENT32F 0x8CAC
#  define GL_DEPTH32F_STENCIL8 0x8CAD
#  define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#  define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#  define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#  define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#  define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#  define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#  define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#  define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#  define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#  define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#  define GL_FRAMEBUFFER_DEFAULT 0x8218
#  define GL_FRAMEBUFFER_UNDEFINED 0x8219
#  define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#  define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#  define GL_DEPTH_STENCIL 0x84F9
#  define GL_UNSIGNED_INT_24_8 0x84FA
#  define GL_DEPTH24_STENCIL8 0x88F0
#  define GL_TEXTURE_STENCIL_SIZE 0x88F1
#  define GL_TEXTURE_RED_TYPE 0x8C10
#  define GL_TEXTURE_GREEN_TYPE 0x8C11
#  define GL_TEXTURE_BLUE_TYPE 0x8C12
#  define GL_TEXTURE_ALPHA_TYPE 0x8C13
#  define GL_TEXTURE_DEPTH_TYPE 0x8C16
#  define GL_UNSIGNED_NORMALIZED 0x8C17
#  define GL_FRAMEBUFFER_BINDING 0x8CA6
#  define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#  define GL_RENDERBUFFER_BINDING 0x8CA7
#  define GL_READ_FRAMEBUFFER 0x8CA8
#  define GL_DRAW_FRAMEBUFFER 0x8CA9
#  define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#  define GL_RENDERBUFFER_SAMPLES 0x8CAB
#  define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#  define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#  define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#  define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#  define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#  define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#  define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#  define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#  define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#  define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#  define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#  define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#  define GL_COLOR_ATTACHMENT0 0x8CE0
#  define GL_COLOR_ATTACHMENT1 0x8CE1
#  define GL_COLOR_ATTACHMENT2 0x8CE2
#  define GL_COLOR_ATTACHMENT3 0x8CE3
#  define GL_COLOR_ATTACHMENT4 0x8CE4
#  define GL_COLOR_ATTACHMENT5 0x8CE5
#  define GL_COLOR_ATTACHMENT6 0x8CE6
#  define GL_COLOR_ATTACHMENT7 0x8CE7
#  define GL_COLOR_ATTACHMENT8 0x8CE8
#  define GL_COLOR_ATTACHMENT9 0x8CE9
#  define GL_COLOR_ATTACHMENT10 0x8CEA
#  define GL_COLOR_ATTACHMENT11 0x8CEB
#  define GL_COLOR_ATTACHMENT12 0x8CEC
#  define GL_COLOR_ATTACHMENT13 0x8CED
#  define GL_COLOR_ATTACHMENT14 0x8CEE
#  define GL_COLOR_ATTACHMENT15 0x8CEF
#  define GL_COLOR_ATTACHMENT16 0x8CF0
#  define GL_COLOR_ATTACHMENT17 0x8CF1
#  define GL_COLOR_ATTACHMENT18 0x8CF2
#  define GL_COLOR_ATTACHMENT19 0x8CF3
#  define GL_COLOR_ATTACHMENT20 0x8CF4
#  define GL_COLOR_ATTACHMENT21 0x8CF5
#  define GL_COLOR_ATTACHMENT22 0x8CF6
#  define GL_COLOR_ATTACHMENT23 0x8CF7
#  define GL_COLOR_ATTACHMENT24 0x8CF8
#  define GL_COLOR_ATTACHMENT25 0x8CF9
#  define GL_COLOR_ATTACHMENT26 0x8CFA
#  define GL_COLOR_ATTACHMENT27 0x8CFB
#  define GL_COLOR_ATTACHMENT28 0x8CFC
#  define GL_COLOR_ATTACHMENT29 0x8CFD
#  define GL_COLOR_ATTACHMENT30 0x8CFE
#  define GL_COLOR_ATTACHMENT31 0x8CFF
#  define GL_DEPTH_ATTACHMENT 0x8D00
#  define GL_STENCIL_ATTACHMENT 0x8D20
#  define GL_FRAMEBUFFER 0x8D40
#  define GL_RENDERBUFFER 0x8D41
#  define GL_RENDERBUFFER_WIDTH 0x8D42
#  define GL_RENDERBUFFER_HEIGHT 0x8D43
#  define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#  define GL_STENCIL_INDEX1 0x8D46
#  define GL_STENCIL_INDEX4 0x8D47
#  define GL_STENCIL_INDEX8 0x8D48
#  define GL_STENCIL_INDEX16 0x8D49
#  define GL_RENDERBUFFER_RED_SIZE 0x8D50
#  define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#  define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#  define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#  define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#  define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#  define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#  define GL_MAX_SAMPLES 0x8D57
#  define GL_INDEX 0x8222
#  define GL_TEXTURE_LUMINANCE_TYPE 0x8C14
#  define GL_TEXTURE_INTENSITY_TYPE 0x8C15
#  define GL_FRAMEBUFFER_SRGB 0x8DB9
#  define GL_HALF_FLOAT 0x140B
#  define GL_MAP_READ_BIT 0x0001
#  define GL_MAP_WRITE_BIT 0x0002
#  define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#  define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#  define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#  define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#  define GL_COMPRESSED_RED_RGTC1 0x8DBB
#  define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#  define GL_COMPRESSED_RG_RGTC2 0x8DBD
#  define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#  define GL_RG 0x8227
#  define GL_RG_INTEGER 0x8228
#  define GL_R8 0x8229
#  define GL_R16 0x822A
#  define GL_RG8 0x822B
#  define GL_RG16 0x822C
#  define GL_R16F 0x822D
#  define GL_R32F 0x822E
#  define GL_RG16F 0x822F
#  define GL_RG32F 0x8230
#  define GL_R8I 0x8231
#  define GL_R8UI 0x8232
#  define GL_R16I 0x8233
#  define GL_R16UI 0x8234
#  define GL_R32I 0x8235
#  define GL_R32UI 0x8236
#  define GL_RG8I 0x8237
#  define GL_RG8UI 0x8238
#  define GL_RG16I 0x8239
#  define GL_RG16UI 0x823A
#  define GL_RG32I 0x823B
#  define GL_RG32UI 0x823C
#  define GL_VERTEX_ARRAY_BINDING 0x85B5
#  define GL_CLAMP_VERTEX_COLOR 0x891A
#  define GL_CLAMP_FRAGMENT_COLOR 0x891B
#  define GL_ALPHA_INTEGER 0x8D97

typedef khronos_uint16_t GLhalf;

typedef void (APIENTRY *PFNGLCOLORMASKIPROC) (GLuint, GLboolean, GLboolean, GLboolean, GLboolean);
typedef void (APIENTRY *PFNGLGETBOOLEANI_VPROC) (GLenum, GLuint, GLboolean *);
typedef void (APIENTRY *PFNGLGETINTEGERI_VPROC) (GLenum, GLuint, GLint *);
typedef void (APIENTRY *PFNGLENABLEIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDISABLEIPROC) (GLenum, GLuint);
typedef GLboolean (APIENTRY *PFNGLISENABLEDIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLBEGINTRANSFORMFEEDBACKPROC) (GLenum);
typedef void (APIENTRY *PFNGLENDTRANSFORMFEEDBACKPROC) ();
typedef void (APIENTRY *PFNGLBINDBUFFERRANGEPROC) (GLenum, GLuint, GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLBINDBUFFERBASEPROC) (GLenum, GLuint, GLuint);
typedef void (APIENTRY *PFNGLTRANSFORMFEEDBACKVARYINGSPROC) (GLuint, GLsizei, const GLchar *const*, GLenum);
typedef void (APIENTRY *PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLsizei *, GLenum *, GLchar *);
typedef void (APIENTRY *PFNGLCLAMPCOLORPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLBEGINCONDITIONALRENDERPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLENDCONDITIONALRENDERPROC) ();
typedef void (APIENTRY *PFNGLVERTEXATTRIBIPOINTERPROC) (GLuint, GLint, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBIIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBIUIVPROC) (GLuint, GLenum, GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI1IPROC) (GLuint, GLint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI2IPROC) (GLuint, GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI3IPROC) (GLuint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4IPROC) (GLuint, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI1UIPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI2UIPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI3UIPROC) (GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4UIPROC) (GLuint, GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI1IVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI2IVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI3IVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4IVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI1UIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI2UIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI3UIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4UIVPROC) (GLuint, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4BVPROC) (GLuint, const GLbyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4SVPROC) (GLuint, const GLshort *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4UBVPROC) (GLuint, const GLubyte *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBI4USVPROC) (GLuint, const GLushort *);
typedef void (APIENTRY *PFNGLGETUNIFORMUIVPROC) (GLuint, GLint, GLuint *);
typedef void (APIENTRY *PFNGLBINDFRAGDATALOCATIONPROC) (GLuint, GLuint, const GLchar *);
typedef GLint (APIENTRY *PFNGLGETFRAGDATALOCATIONPROC) (GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLUNIFORM1UIPROC) (GLint, GLuint);
typedef void (APIENTRY *PFNGLUNIFORM2UIPROC) (GLint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLUNIFORM3UIPROC) (GLint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLUNIFORM4UIPROC) (GLint, GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLUNIFORM1UIVPROC) (GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLUNIFORM2UIVPROC) (GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLUNIFORM3UIVPROC) (GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLUNIFORM4UIVPROC) (GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLTEXPARAMETERIIVPROC) (GLenum, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLTEXPARAMETERIUIVPROC) (GLenum, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLGETTEXPARAMETERIIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTEXPARAMETERIUIVPROC) (GLenum, GLenum, GLuint *);
typedef void (APIENTRY *PFNGLCLEARBUFFERIVPROC) (GLenum, GLint, const GLint *);
typedef void (APIENTRY *PFNGLCLEARBUFFERUIVPROC) (GLenum, GLint, const GLuint *);
typedef void (APIENTRY *PFNGLCLEARBUFFERFVPROC) (GLenum, GLint, const GLfloat *);
typedef void (APIENTRY *PFNGLCLEARBUFFERFIPROC) (GLenum, GLint, GLfloat, GLint);
typedef const GLubyte * (APIENTRY *PFNGLGETSTRINGIPROC) (GLenum, GLuint);
typedef GLboolean (APIENTRY *PFNGLISRENDERBUFFERPROC) (GLuint);
typedef void (APIENTRY *PFNGLBINDRENDERBUFFERPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDELETERENDERBUFFERSPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENRENDERBUFFERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLRENDERBUFFERSTORAGEPROC) (GLenum, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLGETRENDERBUFFERPARAMETERIVPROC) (GLenum, GLenum, GLint *);
typedef GLboolean (APIENTRY *PFNGLISFRAMEBUFFERPROC) (GLuint);
typedef void (APIENTRY *PFNGLBINDFRAMEBUFFERPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDELETEFRAMEBUFFERSPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENFRAMEBUFFERSPROC) (GLsizei, GLuint *);
typedef GLenum (APIENTRY *PFNGLCHECKFRAMEBUFFERSTATUSPROC) (GLenum);
typedef void (APIENTRY *PFNGLFRAMEBUFFERTEXTURE1DPROC) (GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PFNGLFRAMEBUFFERTEXTURE2DPROC) (GLenum, GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PFNGLFRAMEBUFFERTEXTURE3DPROC) (GLenum, GLenum, GLenum, GLuint, GLint, GLint);
typedef void (APIENTRY *PFNGLFRAMEBUFFERRENDERBUFFERPROC) (GLenum, GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLenum, GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGENERATEMIPMAPPROC) (GLenum);
typedef void (APIENTRY *PFNGLBLITFRAMEBUFFERPROC) (GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
typedef void (APIENTRY *PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLFRAMEBUFFERTEXTURELAYERPROC) (GLenum, GLenum, GLuint, GLint, GLint);
typedef void * (APIENTRY *PFNGLMAPBUFFERRANGEPROC) (GLenum, GLintptr, GLsizeiptr, GLbitfield);
typedef void (APIENTRY *PFNGLFLUSHMAPPEDBUFFERRANGEPROC) (GLenum, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLBINDVERTEXARRAYPROC) (GLuint);
typedef void (APIENTRY *PFNGLDELETEVERTEXARRAYSPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENVERTEXARRAYSPROC) (GLsizei, GLuint *);
typedef GLboolean (APIENTRY *PFNGLISVERTEXARRAYPROC) (GLuint);

# endif /* GL_VERSION_3_0 */ /* }}} */
# if !defined (GL_VERSION_3_1) /* {{{ */
#  define GL_VERSION_3_1 1
#  define GL_SAMPLER_2D_RECT 0x8B63
#  define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#  define GL_SAMPLER_BUFFER 0x8DC2
#  define GL_INT_SAMPLER_2D_RECT 0x8DCD
#  define GL_INT_SAMPLER_BUFFER 0x8DD0
#  define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#  define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#  define GL_TEXTURE_BUFFER 0x8C2A
#  define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#  define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#  define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#  define GL_TEXTURE_RECTANGLE 0x84F5
#  define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#  define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#  define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#  define GL_R8_SNORM 0x8F94
#  define GL_RG8_SNORM 0x8F95
#  define GL_RGB8_SNORM 0x8F96
#  define GL_RGBA8_SNORM 0x8F97
#  define GL_R16_SNORM 0x8F98
#  define GL_RG16_SNORM 0x8F99
#  define GL_RGB16_SNORM 0x8F9A
#  define GL_RGBA16_SNORM 0x8F9B
#  define GL_SIGNED_NORMALIZED 0x8F9C
#  define GL_PRIMITIVE_RESTART 0x8F9D
#  define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#  define GL_COPY_READ_BUFFER 0x8F36
#  define GL_COPY_WRITE_BUFFER 0x8F37
#  define GL_UNIFORM_BUFFER 0x8A11
#  define GL_UNIFORM_BUFFER_BINDING 0x8A28
#  define GL_UNIFORM_BUFFER_START 0x8A29
#  define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#  define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#  define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#  define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#  define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#  define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#  define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#  define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#  define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#  define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#  define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#  define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#  define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#  define GL_UNIFORM_TYPE 0x8A37
#  define GL_UNIFORM_SIZE 0x8A38
#  define GL_UNIFORM_NAME_LENGTH 0x8A39
#  define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#  define GL_UNIFORM_OFFSET 0x8A3B
#  define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#  define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#  define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#  define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#  define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#  define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#  define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#  define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#  define GL_INVALID_INDEX 0xFFFFFFFF

typedef void (APIENTRY *PFNGLDRAWARRAYSINSTANCEDPROC) (GLenum, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLDRAWELEMENTSINSTANCEDPROC) (GLenum, GLsizei, GLenum, const void *, GLsizei);
typedef void (APIENTRY *PFNGLTEXBUFFERPROC) (GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLPRIMITIVERESTARTINDEXPROC) (GLuint);
typedef void (APIENTRY *PFNGLCOPYBUFFERSUBDATAPROC) (GLenum, GLenum, GLintptr, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLGETUNIFORMINDICESPROC) (GLuint, GLsizei, const GLchar *const*, GLuint *);
typedef void (APIENTRY *PFNGLGETACTIVEUNIFORMSIVPROC) (GLuint, GLsizei, const GLuint *, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETACTIVEUNIFORMNAMEPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
typedef GLuint (APIENTRY *PFNGLGETUNIFORMBLOCKINDEXPROC) (GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLGETACTIVEUNIFORMBLOCKIVPROC) (GLuint, GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) (GLuint, GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLUNIFORMBLOCKBINDINGPROC) (GLuint, GLuint, GLuint);

# endif /* GL_VERSION_3_1 */ /* }}} */
# if !defined (GL_VERSION_3_2) /* {{{ */
#  define GL_VERSION_3_2 1
#  define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#  define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#  define GL_LINES_ADJACENCY 0x000A
#  define GL_LINE_STRIP_ADJACENCY 0x000B
#  define GL_TRIANGLES_ADJACENCY 0x000C
#  define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#  define GL_PROGRAM_POINT_SIZE 0x8642
#  define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#  define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#  define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#  define GL_GEOMETRY_SHADER 0x8DD9
#  define GL_GEOMETRY_VERTICES_OUT 0x8916
#  define GL_GEOMETRY_INPUT_TYPE 0x8917
#  define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#  define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#  define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#  define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#  define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#  define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#  define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#  define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#  define GL_CONTEXT_PROFILE_MASK 0x9126
#  define GL_DEPTH_CLAMP 0x864F
#  define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#  define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#  define GL_LAST_VERTEX_CONVENTION 0x8E4E
#  define GL_PROVOKING_VERTEX 0x8E4F
#  define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#  define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#  define GL_OBJECT_TYPE 0x9112
#  define GL_SYNC_CONDITION 0x9113
#  define GL_SYNC_STATUS 0x9114
#  define GL_SYNC_FLAGS 0x9115
#  define GL_SYNC_FENCE 0x9116
#  define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#  define GL_UNSIGNALED 0x9118
#  define GL_SIGNALED 0x9119
#  define GL_ALREADY_SIGNALED 0x911A
#  define GL_TIMEOUT_EXPIRED 0x911B
#  define GL_CONDITION_SATISFIED 0x911C
#  define GL_WAIT_FAILED 0x911D
#  define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#  define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#  define GL_SAMPLE_POSITION 0x8E50
#  define GL_SAMPLE_MASK 0x8E51
#  define GL_SAMPLE_MASK_VALUE 0x8E52
#  define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#  define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#  define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#  define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#  define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#  define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#  define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#  define GL_TEXTURE_SAMPLES 0x9106
#  define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#  define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#  define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#  define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#  define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#  define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#  define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#  define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#  define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#  define GL_MAX_INTEGER_SAMPLES 0x9110

typedef struct __GLsync *GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;

typedef void (APIENTRY *PFNGLDRAWELEMENTSBASEVERTEXPROC) (GLenum, GLsizei, GLenum, const void *, GLint);
typedef void (APIENTRY *PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) (GLenum, GLuint, GLuint, GLsizei, GLenum, const void *, GLint);
typedef void (APIENTRY *PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) (GLenum, GLsizei, GLenum, const void *, GLsizei, GLint);
typedef void (APIENTRY *PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) (GLenum, const GLsizei *, GLenum, const void *const*, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLPROVOKINGVERTEXPROC) (GLenum);
typedef GLsync (APIENTRY *PFNGLFENCESYNCPROC) (GLenum, GLbitfield);
typedef GLboolean (APIENTRY *PFNGLISSYNCPROC) (GLsync);
typedef void (APIENTRY *PFNGLDELETESYNCPROC) (GLsync);
typedef GLenum (APIENTRY *PFNGLCLIENTWAITSYNCPROC) (GLsync, GLbitfield, GLuint64);
typedef void (APIENTRY *PFNGLWAITSYNCPROC) (GLsync, GLbitfield, GLuint64);
typedef void (APIENTRY *PFNGLGETINTEGER64VPROC) (GLenum, GLint64 *);
typedef void (APIENTRY *PFNGLGETSYNCIVPROC) (GLsync, GLenum, GLsizei, GLsizei *, GLint *);
typedef void (APIENTRY *PFNGLGETINTEGER64I_VPROC) (GLenum, GLuint, GLint64 *);
typedef void (APIENTRY *PFNGLGETBUFFERPARAMETERI64VPROC) (GLenum, GLenum, GLint64 *);
typedef void (APIENTRY *PFNGLFRAMEBUFFERTEXTUREPROC) (GLenum, GLenum, GLuint, GLint);
typedef void (APIENTRY *PFNGLTEXIMAGE2DMULTISAMPLEPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLTEXIMAGE3DMULTISAMPLEPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLGETMULTISAMPLEFVPROC) (GLenum, GLuint, GLfloat *);
typedef void (APIENTRY *PFNGLSAMPLEMASKIPROC) (GLuint, GLbitfield);

# endif /* GL_VERSION_3_2 */ /* }}} */
# if !defined (GL_VERSION_3_3) /* {{{ */
#  define GL_VERSION_3_3 1
#  define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#  define GL_SRC1_COLOR 0x88F9
#  define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#  define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#  define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#  define GL_ANY_SAMPLES_PASSED 0x8C2F
#  define GL_SAMPLER_BINDING 0x8919
#  define GL_RGB10_A2UI 0x906F
#  define GL_TEXTURE_SWIZZLE_R 0x8E42
#  define GL_TEXTURE_SWIZZLE_G 0x8E43
#  define GL_TEXTURE_SWIZZLE_B 0x8E44
#  define GL_TEXTURE_SWIZZLE_A 0x8E45
#  define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#  define GL_TIME_ELAPSED 0x88BF
#  define GL_TIMESTAMP 0x8E28
#  define GL_INT_2_10_10_10_REV 0x8D9F

typedef void (APIENTRY *PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) (GLuint, GLuint, GLuint, const GLchar *);
typedef GLint (APIENTRY *PFNGLGETFRAGDATAINDEXPROC) (GLuint, const GLchar *);
typedef void (APIENTRY *PFNGLGENSAMPLERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLDELETESAMPLERSPROC) (GLsizei, const GLuint *);
typedef GLboolean (APIENTRY *PFNGLISSAMPLERPROC) (GLuint);
typedef void (APIENTRY *PFNGLBINDSAMPLERPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERIPROC) (GLuint, GLenum, GLint);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERIVPROC) (GLuint, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERFPROC) (GLuint, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERFVPROC) (GLuint, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERIIVPROC) (GLuint, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLSAMPLERPARAMETERIUIVPROC) (GLuint, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLGETSAMPLERPARAMETERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETSAMPLERPARAMETERIIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETSAMPLERPARAMETERFVPROC) (GLuint, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETSAMPLERPARAMETERIUIVPROC) (GLuint, GLenum, GLuint *);
typedef void (APIENTRY *PFNGLQUERYCOUNTERPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLGETQUERYOBJECTI64VPROC) (GLuint, GLenum, GLint64 *);
typedef void (APIENTRY *PFNGLGETQUERYOBJECTUI64VPROC) (GLuint, GLenum, GLuint64 *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBDIVISORPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP1UIPROC) (GLuint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP1UIVPROC) (GLuint, GLenum, GLboolean, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP2UIPROC) (GLuint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP2UIVPROC) (GLuint, GLenum, GLboolean, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP3UIPROC) (GLuint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP3UIVPROC) (GLuint, GLenum, GLboolean, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP4UIPROC) (GLuint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBP4UIVPROC) (GLuint, GLenum, GLboolean, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXP2UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXP2UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXP3UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXP3UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLVERTEXP4UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXP4UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLTEXCOORDP1UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLTEXCOORDP1UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLTEXCOORDP2UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLTEXCOORDP2UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLTEXCOORDP3UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLTEXCOORDP3UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLTEXCOORDP4UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLTEXCOORDP4UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP1UIPROC) (GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP1UIVPROC) (GLenum, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP2UIPROC) (GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP2UIVPROC) (GLenum, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP3UIPROC) (GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP3UIVPROC) (GLenum, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP4UIPROC) (GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLMULTITEXCOORDP4UIVPROC) (GLenum, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLNORMALP3UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLNORMALP3UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLCOLORP3UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLCOLORP3UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLCOLORP4UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLCOLORP4UIVPROC) (GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLSECONDARYCOLORP3UIPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLSECONDARYCOLORP3UIVPROC) (GLenum, const GLuint *);

# endif /* GL_VERSION_3_3 */ /* }}} */
# if !defined (GL_VERSION_4_0) /* {{{ */
#  define GL_VERSION_4_0 1
#  define GL_SAMPLE_SHADING 0x8C36
#  define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#  define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#  define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#  define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#  define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#  define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#  define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#  define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#  define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#  define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#  define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#  define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#  define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#  define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#  define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#  define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#  define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#  define GL_MAX_VERTEX_STREAMS 0x8E71
#  define GL_DOUBLE_VEC2 0x8FFC
#  define GL_DOUBLE_VEC3 0x8FFD
#  define GL_DOUBLE_VEC4 0x8FFE
#  define GL_DOUBLE_MAT2 0x8F46
#  define GL_DOUBLE_MAT3 0x8F47
#  define GL_DOUBLE_MAT4 0x8F48
#  define GL_DOUBLE_MAT2x3 0x8F49
#  define GL_DOUBLE_MAT2x4 0x8F4A
#  define GL_DOUBLE_MAT3x2 0x8F4B
#  define GL_DOUBLE_MAT3x4 0x8F4C
#  define GL_DOUBLE_MAT4x2 0x8F4D
#  define GL_DOUBLE_MAT4x3 0x8F4E
#  define GL_ACTIVE_SUBROUTINES 0x8DE5
#  define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#  define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#  define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#  define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#  define GL_MAX_SUBROUTINES 0x8DE7
#  define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#  define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#  define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#  define GL_PATCHES 0x000E
#  define GL_PATCH_VERTICES 0x8E72
#  define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#  define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#  define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#  define GL_TESS_GEN_MODE 0x8E76
#  define GL_TESS_GEN_SPACING 0x8E77
#  define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#  define GL_TESS_GEN_POINT_MODE 0x8E79
#  define GL_ISOLINES 0x8E7A
#  define GL_FRACTIONAL_ODD 0x8E7B
#  define GL_FRACTIONAL_EVEN 0x8E7C
#  define GL_MAX_PATCH_VERTICES 0x8E7D
#  define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#  define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#  define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#  define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#  define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#  define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#  define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#  define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#  define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#  define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#  define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#  define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#  define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#  define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#  define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#  define GL_TESS_EVALUATION_SHADER 0x8E87
#  define GL_TESS_CONTROL_SHADER 0x8E88
#  define GL_TRANSFORM_FEEDBACK 0x8E22
#  define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#  define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#  define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#  define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70
#  define GL_MAX_VERTEX_STREAMS 0x8E71

typedef void (APIENTRY *PFNGLMINSAMPLESHADINGPROC) (GLfloat);
typedef void (APIENTRY *PFNGLBLENDEQUATIONIPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLBLENDEQUATIONSEPARATEIPROC) (GLuint, GLenum, GLenum);
typedef void (APIENTRY *PFNGLBLENDFUNCIPROC) (GLuint, GLenum, GLenum);
typedef void (APIENTRY *PFNGLBLENDFUNCSEPARATEIPROC) (GLuint, GLenum, GLenum, GLenum, GLenum);
typedef void (APIENTRY *PFNGLDRAWARRAYSINDIRECTPROC) (GLenum, const void *);
typedef void (APIENTRY *PFNGLDRAWELEMENTSINDIRECTPROC) (GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLUNIFORM1DPROC) (GLint, GLdouble);
typedef void (APIENTRY *PFNGLUNIFORM2DPROC) (GLint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLUNIFORM3DPROC) (GLint, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLUNIFORM4DPROC) (GLint, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLUNIFORM1DVPROC) (GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORM2DVPROC) (GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORM3DVPROC) (GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORM4DVPROC) (GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX2DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX2X3DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX2X4DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3X2DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX3X4DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4X2DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLUNIFORMMATRIX4X3DVPROC) (GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLGETUNIFORMDVPROC) (GLuint, GLint, GLdouble *);
typedef GLint (APIENTRY *PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) (GLuint, GLenum, const GLchar *);
typedef GLuint (APIENTRY *PFNGLGETSUBROUTINEINDEXPROC) (GLuint, GLenum, const GLchar *);
typedef void (APIENTRY *PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) (GLuint, GLenum, GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) (GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLGETACTIVESUBROUTINENAMEPROC) (GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLUNIFORMSUBROUTINESUIVPROC) (GLenum, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGETUNIFORMSUBROUTINEUIVPROC) (GLenum, GLint, GLuint *);
typedef void (APIENTRY *PFNGLGETPROGRAMSTAGEIVPROC) (GLuint, GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLPATCHPARAMETERIPROC) (GLenum, GLint);
typedef void (APIENTRY *PFNGLPATCHPARAMETERFVPROC) (GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLBINDTRANSFORMFEEDBACKPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDELETETRANSFORMFEEDBACKSPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENTRANSFORMFEEDBACKSPROC) (GLsizei, GLuint *);
typedef GLboolean (APIENTRY *PFNGLISTRANSFORMFEEDBACKPROC) (GLuint);
typedef void (APIENTRY *PFNGLPAUSETRANSFORMFEEDBACKPROC) ();
typedef void (APIENTRY *PFNGLRESUMETRANSFORMFEEDBACKPROC) ();
typedef void (APIENTRY *PFNGLDRAWTRANSFORMFEEDBACKPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) (GLenum, GLuint, GLuint);
typedef void (APIENTRY *PFNGLBEGINQUERYINDEXEDPROC) (GLenum, GLuint, GLuint);
typedef void (APIENTRY *PFNGLENDQUERYINDEXEDPROC) (GLenum, GLuint);
typedef void (APIENTRY *PFNGLGETQUERYINDEXEDIVPROC) (GLenum, GLuint, GLenum, GLint *);

# endif /* GL_VERSION_4_0 */ /* }}} */
# if !defined (GL_VERSION_4_1) /* {{{ */
#  define GL_VERSION_4_1 1
#  define GL_FIXED 0x140C
#  define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#  define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#  define GL_LOW_FLOAT 0x8DF0
#  define GL_MEDIUM_FLOAT 0x8DF1
#  define GL_HIGH_FLOAT 0x8DF2
#  define GL_LOW_INT 0x8DF3
#  define GL_MEDIUM_INT 0x8DF4
#  define GL_HIGH_INT 0x8DF5
#  define GL_SHADER_COMPILER 0x8DFA
#  define GL_SHADER_BINARY_FORMATS 0x8DF8
#  define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#  define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#  define GL_MAX_VARYING_VECTORS 0x8DFC
#  define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#  define GL_RGB565 0x8D62
#  define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#  define GL_PROGRAM_BINARY_LENGTH 0x8741
#  define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#  define GL_PROGRAM_BINARY_FORMATS 0x87FF
#  define GL_VERTEX_SHADER_BIT 0x00000001
#  define GL_FRAGMENT_SHADER_BIT 0x00000002
#  define GL_GEOMETRY_SHADER_BIT 0x00000004
#  define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#  define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#  define GL_ALL_SHADER_BITS 0xFFFFFFFF
#  define GL_PROGRAM_SEPARABLE 0x8258
#  define GL_ACTIVE_PROGRAM 0x8259
#  define GL_PROGRAM_PIPELINE_BINDING 0x825A
#  define GL_MAX_VIEWPORTS 0x825B
#  define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#  define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#  define GL_LAYER_PROVOKING_VERTEX 0x825E
#  define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#  define GL_UNDEFINED_VERTEX 0x8260

typedef void (APIENTRY *PFNGLRELEASESHADERCOMPILERPROC) ();
typedef void (APIENTRY *PFNGLSHADERBINARYPROC) (GLsizei, const GLuint *, GLenum, const void *, GLsizei);
typedef void (APIENTRY *PFNGLGETSHADERPRECISIONFORMATPROC) (GLenum, GLenum, GLint *, GLint *);
typedef void (APIENTRY *PFNGLDEPTHRANGEFPROC) (GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLCLEARDEPTHFPROC) (GLfloat);
typedef void (APIENTRY *PFNGLGETPROGRAMBINARYPROC) (GLuint, GLsizei, GLsizei *, GLenum *, void *);
typedef void (APIENTRY *PFNGLPROGRAMBINARYPROC) (GLuint, GLenum, const void *, GLsizei);
typedef void (APIENTRY *PFNGLPROGRAMPARAMETERIPROC) (GLuint, GLenum, GLint);
typedef void (APIENTRY *PFNGLUSEPROGRAMSTAGESPROC) (GLuint, GLbitfield, GLuint);
typedef void (APIENTRY *PFNGLACTIVESHADERPROGRAMPROC) (GLuint, GLuint);
typedef GLuint (APIENTRY *PFNGLCREATESHADERPROGRAMVPROC) (GLenum, GLsizei, const GLchar *const*);
typedef void (APIENTRY *PFNGLBINDPROGRAMPIPELINEPROC) (GLuint);
typedef void (APIENTRY *PFNGLDELETEPROGRAMPIPELINESPROC) (GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLGENPROGRAMPIPELINESPROC) (GLsizei, GLuint *);
typedef GLboolean (APIENTRY *PFNGLISPROGRAMPIPELINEPROC) (GLuint);
typedef void (APIENTRY *PFNGLGETPROGRAMPIPELINEIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLPROGRAMPARAMETERIPROC) (GLuint, GLenum, GLint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1IPROC) (GLuint, GLint, GLint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1IVPROC) (GLuint, GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1FPROC) (GLuint, GLint, GLfloat);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1FVPROC) (GLuint, GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1DPROC) (GLuint, GLint, GLdouble);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1DVPROC) (GLuint, GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1UIPROC) (GLuint, GLint, GLuint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM1UIVPROC) (GLuint, GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2IPROC) (GLuint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2IVPROC) (GLuint, GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2FPROC) (GLuint, GLint, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2FVPROC) (GLuint, GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2DPROC) (GLuint, GLint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2DVPROC) (GLuint, GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2UIPROC) (GLuint, GLint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM2UIVPROC) (GLuint, GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3IPROC) (GLuint, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3IVPROC) (GLuint, GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3FPROC) (GLuint, GLint, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3FVPROC) (GLuint, GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3DPROC) (GLuint, GLint, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3DVPROC) (GLuint, GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3UIPROC) (GLuint, GLint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM3UIVPROC) (GLuint, GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4IPROC) (GLuint, GLint, GLint, GLint, GLint, GLint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4IVPROC) (GLuint, GLint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4FPROC) (GLuint, GLint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4FVPROC) (GLuint, GLint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4DPROC) (GLuint, GLint, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4DVPROC) (GLuint, GLint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4UIPROC) (GLuint, GLint, GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORM4UIVPROC) (GLuint, GLint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLfloat *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) (GLuint, GLint, GLsizei, GLboolean, const GLdouble *);
typedef void (APIENTRY *PFNGLVALIDATEPROGRAMPIPELINEPROC) (GLuint);
typedef void (APIENTRY *PFNGLGETPROGRAMPIPELINEINFOLOGPROC) (GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL1DPROC) (GLuint, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL2DPROC) (GLuint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL3DPROC) (GLuint, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL4DPROC) (GLuint, GLdouble, GLdouble, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL1DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL2DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL3DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBL4DVPROC) (GLuint, const GLdouble *);
typedef void (APIENTRY *PFNGLVERTEXATTRIBLPOINTERPROC) (GLuint, GLint, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLGETVERTEXATTRIBLDVPROC) (GLuint, GLenum, GLdouble *);
typedef void (APIENTRY *PFNGLVIEWPORTARRAYVPROC) (GLuint, GLsizei, const GLfloat *);
typedef void (APIENTRY *PFNGLVIEWPORTINDEXEDFPROC) (GLuint, GLfloat, GLfloat, GLfloat, GLfloat);
typedef void (APIENTRY *PFNGLVIEWPORTINDEXEDFVPROC) (GLuint, const GLfloat *);
typedef void (APIENTRY *PFNGLSCISSORARRAYVPROC) (GLuint, GLsizei, const GLint *);
typedef void (APIENTRY *PFNGLSCISSORINDEXEDPROC) (GLuint, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLSCISSORINDEXEDVPROC) (GLuint, const GLint *);
typedef void (APIENTRY *PFNGLDEPTHRANGEARRAYVPROC) (GLuint, GLsizei, const GLdouble *);
typedef void (APIENTRY *PFNGLDEPTHRANGEINDEXEDPROC) (GLuint, GLdouble, GLdouble);
typedef void (APIENTRY *PFNGLGETFLOATI_VPROC) (GLenum, GLuint, GLfloat *);
typedef void (APIENTRY *PFNGLGETDOUBLEI_VPROC) (GLenum, GLuint, GLdouble *);

# endif /* GL_VERSION_4_1 */ /* }}} */
# if !defined (GL_VERSION_4_2) /* {{{ */
#  define GL_VERSION_4_2 1
#  define GL_COPY_READ_BUFFER_BINDING 0x8F36
#  define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#  define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#  define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#  define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#  define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#  define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#  define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#  define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#  define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#  define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#  define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#  define GL_NUM_SAMPLE_COUNTS 0x9380
#  define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
#  define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#  define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#  define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#  define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#  define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#  define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#  define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#  define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#  define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#  define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#  define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#  define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#  define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#  define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#  define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#  define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#  define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#  define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#  define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#  define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#  define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#  define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#  define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#  define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#  define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#  define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#  define GL_UNIFORM_BARRIER_BIT 0x00000004
#  define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#  define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#  define GL_COMMAND_BARRIER_BIT 0x00000040
#  define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#  define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#  define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#  define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#  define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#  define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#  define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#  define GL_MAX_IMAGE_UNITS 0x8F38
#  define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#  define GL_IMAGE_BINDING_NAME 0x8F3A
#  define GL_IMAGE_BINDING_LEVEL 0x8F3B
#  define GL_IMAGE_BINDING_LAYERED 0x8F3C
#  define GL_IMAGE_BINDING_LAYER 0x8F3D
#  define GL_IMAGE_BINDING_ACCESS 0x8F3E
#  define GL_IMAGE_1D 0x904C
#  define GL_IMAGE_2D 0x904D
#  define GL_IMAGE_3D 0x904E
#  define GL_IMAGE_2D_RECT 0x904F
#  define GL_IMAGE_CUBE 0x9050
#  define GL_IMAGE_BUFFER 0x9051
#  define GL_IMAGE_1D_ARRAY 0x9052
#  define GL_IMAGE_2D_ARRAY 0x9053
#  define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#  define GL_IMAGE_2D_MULTISAMPLE 0x9055
#  define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#  define GL_INT_IMAGE_1D 0x9057
#  define GL_INT_IMAGE_2D 0x9058
#  define GL_INT_IMAGE_3D 0x9059
#  define GL_INT_IMAGE_2D_RECT 0x905A
#  define GL_INT_IMAGE_CUBE 0x905B
#  define GL_INT_IMAGE_BUFFER 0x905C
#  define GL_INT_IMAGE_1D_ARRAY 0x905D
#  define GL_INT_IMAGE_2D_ARRAY 0x905E
#  define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#  define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#  define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#  define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#  define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#  define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#  define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#  define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#  define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#  define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#  define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#  define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#  define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#  define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#  define GL_MAX_IMAGE_SAMPLES 0x906D
#  define GL_IMAGE_BINDING_FORMAT 0x906E
#  define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#  define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#  define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#  define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#  define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#  define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#  define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#  define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#  define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#  define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#  define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#  define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#  define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#  define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

typedef void (APIENTRY *PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) (GLenum, GLint, GLsizei, GLsizei, GLuint);
typedef void (APIENTRY *PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) (GLenum, GLsizei, GLenum, const void *, GLsizei, GLuint);
typedef void (APIENTRY *PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) (GLenum, GLsizei, GLenum, const void *, GLsizei, GLint, GLuint);
typedef void (APIENTRY *PFNGLGETINTERNALFORMATIVPROC) (GLenum, GLenum, GLenum, GLsizei, GLint *);
typedef void (APIENTRY *PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) (GLuint, GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLBINDIMAGETEXTUREPROC) (GLuint, GLuint, GLint, GLboolean, GLint, GLenum, GLenum);
typedef void (APIENTRY *PFNGLMEMORYBARRIERPROC) (GLbitfield);
typedef void (APIENTRY *PFNGLTEXSTORAGE1DPROC) (GLenum, GLsizei, GLenum, GLsizei);
typedef void (APIENTRY *PFNGLTEXSTORAGE2DPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXSTORAGE3DPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) (GLenum, GLuint, GLsizei);
typedef void (APIENTRY *PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) (GLenum, GLuint, GLuint, GLsizei);

# endif /* GL_VERSION_4_2 */ /* }}} */
# if !defined (GL_VERSION_4_3) /* {{{ */
#  define GL_VERSION_4_3 1
#  define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#  define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
#  define GL_COMPRESSED_RGB8_ETC2 0x9274
#  define GL_COMPRESSED_SRGB8_ETC2 0x9275
#  define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#  define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#  define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#  define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#  define GL_COMPRESSED_R11_EAC 0x9270
#  define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#  define GL_COMPRESSED_RG11_EAC 0x9272
#  define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#  define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#  define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#  define GL_MAX_ELEMENT_INDEX 0x8D6B
#  define GL_COMPUTE_SHADER 0x91B9
#  define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#  define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#  define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#  define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#  define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#  define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#  define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#  define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#  define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#  define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#  define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#  define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#  define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#  define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#  define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#  define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#  define GL_COMPUTE_SHADER_BIT 0x00000020
#  define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#  define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#  define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#  define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#  define GL_DEBUG_SOURCE_API 0x8246
#  define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#  define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#  define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#  define GL_DEBUG_SOURCE_APPLICATION 0x824A
#  define GL_DEBUG_SOURCE_OTHER 0x824B
#  define GL_DEBUG_TYPE_ERROR 0x824C
#  define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#  define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#  define GL_DEBUG_TYPE_PORTABILITY 0x824F
#  define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#  define GL_DEBUG_TYPE_OTHER 0x8251
#  define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#  define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#  define GL_DEBUG_LOGGED_MESSAGES 0x9145
#  define GL_DEBUG_SEVERITY_HIGH 0x9146
#  define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#  define GL_DEBUG_SEVERITY_LOW 0x9148
#  define GL_DEBUG_TYPE_MARKER 0x8268
#  define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#  define GL_DEBUG_TYPE_POP_GROUP 0x826A
#  define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#  define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#  define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#  define GL_BUFFER 0x82E0
#  define GL_SHADER 0x82E1
#  define GL_PROGRAM 0x82E2
#  define GL_QUERY 0x82E3
#  define GL_PROGRAM_PIPELINE 0x82E4
#  define GL_SAMPLER 0x82E6
#  define GL_MAX_LABEL_LENGTH 0x82E8
#  define GL_DEBUG_OUTPUT 0x92E0
#  define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#  define GL_MAX_UNIFORM_LOCATIONS 0x826E
#  define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#  define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#  define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#  define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#  define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#  define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#  define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#  define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#  define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#  define GL_INTERNALFORMAT_SUPPORTED 0x826F
#  define GL_INTERNALFORMAT_PREFERRED 0x8270
#  define GL_INTERNALFORMAT_RED_SIZE 0x8271
#  define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#  define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#  define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#  define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#  define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#  define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#  define GL_INTERNALFORMAT_RED_TYPE 0x8278
#  define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#  define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#  define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#  define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#  define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#  define GL_MAX_WIDTH 0x827E
#  define GL_MAX_HEIGHT 0x827F
#  define GL_MAX_DEPTH 0x8280
#  define GL_MAX_LAYERS 0x8281
#  define GL_MAX_COMBINED_DIMENSIONS 0x8282
#  define GL_COLOR_COMPONENTS 0x8283
#  define GL_DEPTH_COMPONENTS 0x8284
#  define GL_STENCIL_COMPONENTS 0x8285
#  define GL_COLOR_RENDERABLE 0x8286
#  define GL_DEPTH_RENDERABLE 0x8287
#  define GL_STENCIL_RENDERABLE 0x8288
#  define GL_FRAMEBUFFER_RENDERABLE 0x8289
#  define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#  define GL_FRAMEBUFFER_BLEND 0x828B
#  define GL_READ_PIXELS 0x828C
#  define GL_READ_PIXELS_FORMAT 0x828D
#  define GL_READ_PIXELS_TYPE 0x828E
#  define GL_TEXTURE_IMAGE_FORMAT 0x828F
#  define GL_TEXTURE_IMAGE_TYPE 0x8290
#  define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#  define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#  define GL_MIPMAP 0x8293
#  define GL_MANUAL_GENERATE_MIPMAP 0x8294
#  define GL_AUTO_GENERATE_MIPMAP 0x8295
#  define GL_COLOR_ENCODING 0x8296
#  define GL_SRGB_READ 0x8297
#  define GL_SRGB_WRITE 0x8298
#  define GL_FILTER 0x829A
#  define GL_VERTEX_TEXTURE 0x829B
#  define GL_TESS_CONTROL_TEXTURE 0x829C
#  define GL_TESS_EVALUATION_TEXTURE 0x829D
#  define GL_GEOMETRY_TEXTURE 0x829E
#  define GL_FRAGMENT_TEXTURE 0x829F
#  define GL_COMPUTE_TEXTURE 0x82A0
#  define GL_TEXTURE_SHADOW 0x82A1
#  define GL_TEXTURE_GATHER 0x82A2
#  define GL_TEXTURE_GATHER_SHADOW 0x82A3
#  define GL_SHADER_IMAGE_LOAD 0x82A4
#  define GL_SHADER_IMAGE_STORE 0x82A5
#  define GL_SHADER_IMAGE_ATOMIC 0x82A6
#  define GL_IMAGE_TEXEL_SIZE 0x82A7
#  define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#  define GL_IMAGE_PIXEL_FORMAT 0x82A9
#  define GL_IMAGE_PIXEL_TYPE 0x82AA
#  define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#  define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#  define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#  define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#  define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#  define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#  define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#  define GL_CLEAR_BUFFER 0x82B4
#  define GL_TEXTURE_VIEW 0x82B5
#  define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#  define GL_FULL_SUPPORT 0x82B7
#  define GL_CAVEAT_SUPPORT 0x82B8
#  define GL_IMAGE_CLASS_4_X_32 0x82B9
#  define GL_IMAGE_CLASS_2_X_32 0x82BA
#  define GL_IMAGE_CLASS_1_X_32 0x82BB
#  define GL_IMAGE_CLASS_4_X_16 0x82BC
#  define GL_IMAGE_CLASS_2_X_16 0x82BD
#  define GL_IMAGE_CLASS_1_X_16 0x82BE
#  define GL_IMAGE_CLASS_4_X_8 0x82BF
#  define GL_IMAGE_CLASS_2_X_8 0x82C0
#  define GL_IMAGE_CLASS_1_X_8 0x82C1
#  define GL_IMAGE_CLASS_11_11_10 0x82C2
#  define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#  define GL_VIEW_CLASS_128_BITS 0x82C4
#  define GL_VIEW_CLASS_96_BITS 0x82C5
#  define GL_VIEW_CLASS_64_BITS 0x82C6
#  define GL_VIEW_CLASS_48_BITS 0x82C7
#  define GL_VIEW_CLASS_32_BITS 0x82C8
#  define GL_VIEW_CLASS_24_BITS 0x82C9
#  define GL_VIEW_CLASS_16_BITS 0x82CA
#  define GL_VIEW_CLASS_8_BITS 0x82CB
#  define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#  define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#  define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#  define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#  define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#  define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#  define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#  define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#  define GL_UNIFORM 0x92E1
#  define GL_UNIFORM_BLOCK 0x92E2
#  define GL_PROGRAM_INPUT 0x92E3
#  define GL_PROGRAM_OUTPUT 0x92E4
#  define GL_BUFFER_VARIABLE 0x92E5
#  define GL_SHADER_STORAGE_BLOCK 0x92E6
#  define GL_VERTEX_SUBROUTINE 0x92E8
#  define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#  define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#  define GL_GEOMETRY_SUBROUTINE 0x92EB
#  define GL_FRAGMENT_SUBROUTINE 0x92EC
#  define GL_COMPUTE_SUBROUTINE 0x92ED
#  define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#  define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#  define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#  define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#  define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#  define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#  define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#  define GL_ACTIVE_RESOURCES 0x92F5
#  define GL_MAX_NAME_LENGTH 0x92F6
#  define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#  define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#  define GL_NAME_LENGTH 0x92F9
#  define GL_TYPE 0x92FA
#  define GL_ARRAY_SIZE 0x92FB
#  define GL_OFFSET 0x92FC
#  define GL_BLOCK_INDEX 0x92FD
#  define GL_ARRAY_STRIDE 0x92FE
#  define GL_MATRIX_STRIDE 0x92FF
#  define GL_IS_ROW_MAJOR 0x9300
#  define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#  define GL_BUFFER_BINDING 0x9302
#  define GL_BUFFER_DATA_SIZE 0x9303
#  define GL_NUM_ACTIVE_VARIABLES 0x9304
#  define GL_ACTIVE_VARIABLES 0x9305
#  define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#  define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#  define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#  define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#  define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#  define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#  define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#  define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#  define GL_LOCATION 0x930E
#  define GL_LOCATION_INDEX 0x930F
#  define GL_IS_PER_PATCH 0x92E7
#  define GL_SHADER_STORAGE_BUFFER 0x90D2
#  define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#  define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#  define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#  define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#  define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#  define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#  define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#  define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#  define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#  define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#  define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#  define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#  define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#  define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#  define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#  define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#  define GL_TEXTURE_BUFFER_OFFSET 0x919D
#  define GL_TEXTURE_BUFFER_SIZE 0x919E
#  define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#  define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#  define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#  define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#  define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#  define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#  define GL_VERTEX_ATTRIB_BINDING 0x82D4
#  define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#  define GL_VERTEX_BINDING_DIVISOR 0x82D6
#  define GL_VERTEX_BINDING_OFFSET 0x82D7
#  define GL_VERTEX_BINDING_STRIDE 0x82D8
#  define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#  define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#  define GL_VERTEX_BINDING_BUFFER 0x8F4F
#  define GL_DISPLAY_LIST 0x82E7

typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);

typedef void (APIENTRY *PFNGLCLEARBUFFERDATAPROC) (GLenum, GLenum, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLCLEARBUFFERSUBDATAPROC) (GLenum, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLDISPATCHCOMPUTEPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLDISPATCHCOMPUTEINDIRECTPROC) (GLintptr);
typedef void (APIENTRY *PFNGLCOPYIMAGESUBDATAPROC) (GLuint, GLenum, GLint, GLint, GLint, GLint, GLuint, GLenum, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLFRAMEBUFFERPARAMETERIPROC) (GLenum, GLenum, GLint);
typedef void (APIENTRY *PFNGLGETFRAMEBUFFERPARAMETERIVPROC) (GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETINTERNALFORMATI64VPROC) (GLenum, GLenum, GLenum, GLsizei, GLint64 *);
typedef void (APIENTRY *PFNGLINVALIDATETEXSUBIMAGEPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLINVALIDATETEXIMAGEPROC) (GLuint, GLint);
typedef void (APIENTRY *PFNGLINVALIDATEBUFFERSUBDATAPROC) (GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLINVALIDATEBUFFERDATAPROC) (GLuint);
typedef void (APIENTRY *PFNGLINVALIDATEFRAMEBUFFERPROC) (GLenum, GLsizei, const GLenum *);
typedef void (APIENTRY *PFNGLINVALIDATESUBFRAMEBUFFERPROC) (GLenum, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLMULTIDRAWARRAYSINDIRECTPROC) (GLenum, const void *, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLMULTIDRAWELEMENTSINDIRECTPROC) (GLenum, GLenum, const void *, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLGETPROGRAMINTERFACEIVPROC) (GLuint, GLenum, GLenum, GLint *);
typedef GLuint (APIENTRY *PFNGLGETPROGRAMRESOURCEINDEXPROC) (GLuint, GLenum, const GLchar *);
typedef void (APIENTRY *PFNGLGETPROGRAMRESOURCENAMEPROC) (GLuint, GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLGETPROGRAMRESOURCEIVPROC) (GLuint, GLenum, GLuint, GLsizei, const GLenum *, GLsizei, GLsizei *, GLint *);
typedef GLint (APIENTRY *PFNGLGETPROGRAMRESOURCELOCATIONPROC) (GLuint, GLenum, const GLchar *);
typedef GLint (APIENTRY *PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) (GLuint, GLenum, const GLchar *);
typedef void (APIENTRY *PFNGLSHADERSTORAGEBLOCKBINDINGPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLTEXBUFFERRANGEPROC) (GLenum, GLenum, GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLTEXSTORAGE2DMULTISAMPLEPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLTEXSTORAGE3DMULTISAMPLEPROC) (GLenum, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLTEXTUREVIEWPROC) (GLuint, GLenum, GLuint, GLenum, GLuint, GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLBINDVERTEXBUFFERPROC) (GLuint, GLuint, GLintptr, GLsizei);
typedef void (APIENTRY *PFNGLVERTEXATTRIBFORMATPROC) (GLuint, GLint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBIFORMATPROC) (GLuint, GLint, GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBLFORMATPROC) (GLuint, GLint, GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXATTRIBBINDINGPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXBINDINGDIVISORPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLDEBUGMESSAGECONTROLPROC) (GLenum, GLenum, GLenum, GLsizei, const GLuint *, GLboolean);
typedef void (APIENTRY *PFNGLDEBUGMESSAGEINSERTPROC) (GLenum, GLenum, GLuint, GLenum, GLsizei, const GLchar *);
typedef void (APIENTRY *PFNGLDEBUGMESSAGECALLBACKPROC) (GLDEBUGPROC, const void *);
typedef GLuint (APIENTRY *PFNGLGETDEBUGMESSAGELOGPROC) (GLuint, GLsizei, GLenum *, GLenum *, GLuint *, GLenum *, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLPUSHDEBUGGROUPPROC) (GLenum, GLuint, GLsizei, const GLchar *);
typedef void (APIENTRY *PFNGLPOPDEBUGGROUPPROC) ();
typedef void (APIENTRY *PFNGLOBJECTLABELPROC) (GLenum, GLuint, GLsizei, const GLchar *);
typedef void (APIENTRY *PFNGLGETOBJECTLABELPROC) (GLenum, GLuint, GLsizei, GLsizei *, GLchar *);
typedef void (APIENTRY *PFNGLOBJECTPTRLABELPROC) (const void *, GLsizei, const GLchar *);
typedef void (APIENTRY *PFNGLGETOBJECTPTRLABELPROC) (const void *, GLsizei, GLsizei *, GLchar *);

# endif /* GL_VERSION_4_3 */ /* }}} */
# if !defined (GL_VERSION_4_4) /* {{{ */
#  define GL_VERSION_4_4 1
#  define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#  define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#  define GL_TEXTURE_BUFFER_BINDING 0x8C2A
#  define GL_MAP_PERSISTENT_BIT 0x0040
#  define GL_MAP_COHERENT_BIT 0x0080
#  define GL_DYNAMIC_STORAGE_BIT 0x0100
#  define GL_CLIENT_STORAGE_BIT 0x0200
#  define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#  define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#  define GL_BUFFER_STORAGE_FLAGS 0x8220
#  define GL_CLEAR_TEXTURE 0x9365
#  define GL_LOCATION_COMPONENT 0x934A
#  define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#  define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#  define GL_QUERY_BUFFER 0x9192
#  define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#  define GL_QUERY_BUFFER_BINDING 0x9193
#  define GL_QUERY_RESULT_NO_WAIT 0x9194
#  define GL_MIRROR_CLAMP_TO_EDGE 0x8743

typedef void (APIENTRY *PFNGLBUFFERSTORAGEPROC) (GLenum, GLsizeiptr, const void *, GLbitfield);
typedef void (APIENTRY *PFNGLCLEARTEXIMAGEPROC) (GLuint, GLint, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLCLEARTEXSUBIMAGEPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLBINDBUFFERSBASEPROC) (GLenum, GLuint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLBINDBUFFERSRANGEPROC) (GLenum, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizeiptr *);
typedef void (APIENTRY *PFNGLBINDTEXTURESPROC) (GLuint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLBINDSAMPLERSPROC) (GLuint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLBINDIMAGETEXTURESPROC) (GLuint, GLsizei, const GLuint *);
typedef void (APIENTRY *PFNGLBINDVERTEXBUFFERSPROC) (GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);

# endif /* GL_VERSION_4_4 */ /* }}} */
# if !defined (GL_VERSION_4_5) /* {{{ */
#  define GL_VERSION_4_5 1
#  define GL_CONTEXT_LOST 0x0507
#  define GL_NEGATIVE_ONE_TO_ONE 0x935E
#  define GL_ZERO_TO_ONE 0x935F
#  define GL_CLIP_ORIGIN 0x935C
#  define GL_CLIP_DEPTH_MODE 0x935D
#  define GL_QUERY_WAIT_INVERTED 0x8E17
#  define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#  define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#  define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#  define GL_MAX_CULL_DISTANCES 0x82F9
#  define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#  define GL_TEXTURE_TARGET 0x1006
#  define GL_QUERY_TARGET 0x82EA
#  define GL_GUILTY_CONTEXT_RESET 0x8253
#  define GL_INNOCENT_CONTEXT_RESET 0x8254
#  define GL_UNKNOWN_CONTEXT_RESET 0x8255
#  define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#  define GL_LOSE_CONTEXT_ON_RESET 0x8252
#  define GL_NO_RESET_NOTIFICATION 0x8261
#  define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#  define GL_CONTEXT_LOST 0x0507
#  define GL_COLOR_TABLE 0x80D0
#  define GL_POST_CONVOLUTION_COLOR_TABLE 0x80D1
#  define GL_POST_COLOR_MATRIX_COLOR_TABLE 0x80D2
#  define GL_PROXY_COLOR_TABLE 0x80D3
#  define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE 0x80D4
#  define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE 0x80D5
#  define GL_CONVOLUTION_1D 0x8010
#  define GL_CONVOLUTION_2D 0x8011
#  define GL_SEPARABLE_2D 0x8012
#  define GL_HISTOGRAM 0x8024
#  define GL_PROXY_HISTOGRAM 0x8025
#  define GL_MINMAX 0x802E
#  define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#  define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC

typedef void (APIENTRY *PFNGLCLIPCONTROLPROC) (GLenum, GLenum);
typedef void (APIENTRY *PFNGLCREATETRANSFORMFEEDBACKSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) (GLuint, GLuint, GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLGETTRANSFORMFEEDBACKIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTRANSFORMFEEDBACKI_VPROC) (GLuint, GLenum, GLuint, GLint *);
typedef void (APIENTRY *PFNGLGETTRANSFORMFEEDBACKI64_VPROC) (GLuint, GLenum, GLuint, GLint64 *);
typedef void (APIENTRY *PFNGLCREATEBUFFERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLNAMEDBUFFERSTORAGEPROC) (GLuint, GLsizeiptr, const void *, GLbitfield);
typedef void (APIENTRY *PFNGLNAMEDBUFFERDATAPROC) (GLuint, GLsizeiptr, const void *, GLenum);
typedef void (APIENTRY *PFNGLNAMEDBUFFERSUBDATAPROC) (GLuint, GLintptr, GLsizeiptr, const void *);
typedef void (APIENTRY *PFNGLCOPYNAMEDBUFFERSUBDATAPROC) (GLuint, GLuint, GLintptr, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLCLEARNAMEDBUFFERDATAPROC) (GLuint, GLenum, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLCLEARNAMEDBUFFERSUBDATAPROC) (GLuint, GLenum, GLintptr, GLsizeiptr, GLenum, GLenum, const void *);
typedef void * (APIENTRY *PFNGLMAPNAMEDBUFFERPROC) (GLuint, GLenum);
typedef void * (APIENTRY *PFNGLMAPNAMEDBUFFERRANGEPROC) (GLuint, GLintptr, GLsizeiptr, GLbitfield);
typedef GLboolean (APIENTRY *PFNGLUNMAPNAMEDBUFFERPROC) (GLuint);
typedef void (APIENTRY *PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) (GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLGETNAMEDBUFFERPARAMETERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) (GLuint, GLenum, GLint64 *);
typedef void (APIENTRY *PFNGLGETNAMEDBUFFERPOINTERVPROC) (GLuint, GLenum, void **);
typedef void (APIENTRY *PFNGLGETNAMEDBUFFERSUBDATAPROC) (GLuint, GLintptr, GLsizeiptr, void *);
typedef void (APIENTRY *PFNGLCREATEFRAMEBUFFERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) (GLuint, GLenum, GLenum, GLuint);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) (GLuint, GLenum, GLint);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) (GLuint, GLenum, GLuint, GLint);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) (GLuint, GLenum, GLuint, GLint, GLint);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) (GLuint, GLsizei, const GLenum *);
typedef void (APIENTRY *PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) (GLuint, GLsizei, const GLenum *);
typedef void (APIENTRY *PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) (GLuint, GLsizei, const GLenum *, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) (GLuint, GLenum, GLint, const GLint *);
typedef void (APIENTRY *PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) (GLuint, GLenum, GLint, const GLuint *);
typedef void (APIENTRY *PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) (GLuint, GLenum, GLint, const GLfloat *);
typedef void (APIENTRY *PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) (GLuint, GLenum, GLint, GLfloat, GLint);
typedef void (APIENTRY *PFNGLBLITNAMEDFRAMEBUFFERPROC) (GLuint, GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
typedef GLenum (APIENTRY *PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) (GLuint, GLenum);
typedef void (APIENTRY *PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) (GLuint, GLenum, GLenum, GLint *);
typedef void (APIENTRY *PFNGLCREATERENDERBUFFERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLNAMEDRENDERBUFFERSTORAGEPROC) (GLuint, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) (GLuint, GLsizei, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLCREATETEXTURESPROC) (GLenum, GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLTEXTUREBUFFERPROC) (GLuint, GLenum, GLuint);
typedef void (APIENTRY *PFNGLTEXTUREBUFFERRANGEPROC) (GLuint, GLenum, GLuint, GLintptr, GLsizeiptr);
typedef void (APIENTRY *PFNGLTEXTURESTORAGE1DPROC) (GLuint, GLsizei, GLenum, GLsizei);
typedef void (APIENTRY *PFNGLTEXTURESTORAGE2DPROC) (GLuint, GLsizei, GLenum, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXTURESTORAGE3DPROC) (GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) (GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) (GLuint, GLsizei, GLenum, GLsizei, GLsizei, GLsizei, GLboolean);
typedef void (APIENTRY *PFNGLTEXTURESUBIMAGE1DPROC) (GLuint, GLint, GLint, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXTURESUBIMAGE2DPROC) (GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLTEXTURESUBIMAGE3DPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) (GLuint, GLint, GLint, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) (GLuint, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLsizei, const void *);
typedef void (APIENTRY *PFNGLCOPYTEXTURESUBIMAGE1DPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei);
typedef void (APIENTRY *PFNGLCOPYTEXTURESUBIMAGE2DPROC) (GLuint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLCOPYTEXTURESUBIMAGE3DPROC) (GLuint, GLint, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERFPROC) (GLuint, GLenum, GLfloat);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERFVPROC) (GLuint, GLenum, const GLfloat *);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERIPROC) (GLuint, GLenum, GLint);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERIIVPROC) (GLuint, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERIUIVPROC) (GLuint, GLenum, const GLuint *);
typedef void (APIENTRY *PFNGLTEXTUREPARAMETERIVPROC) (GLuint, GLenum, const GLint *);
typedef void (APIENTRY *PFNGLGENERATETEXTUREMIPMAPPROC) (GLuint);
typedef void (APIENTRY *PFNGLBINDTEXTUREUNITPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLGETTEXTUREIMAGEPROC) (GLuint, GLint, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) (GLuint, GLint, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETTEXTURELEVELPARAMETERFVPROC) (GLuint, GLint, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXTURELEVELPARAMETERIVPROC) (GLuint, GLint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTEXTUREPARAMETERFVPROC) (GLuint, GLenum, GLfloat *);
typedef void (APIENTRY *PFNGLGETTEXTUREPARAMETERIIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETTEXTUREPARAMETERIUIVPROC) (GLuint, GLenum, GLuint *);
typedef void (APIENTRY *PFNGLGETTEXTUREPARAMETERIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLCREATEVERTEXARRAYSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLDISABLEVERTEXARRAYATTRIBPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLENABLEVERTEXARRAYATTRIBPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYELEMENTBUFFERPROC) (GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYVERTEXBUFFERPROC) (GLuint, GLuint, GLuint, GLintptr, GLsizei);
typedef void (APIENTRY *PFNGLVERTEXARRAYVERTEXBUFFERSPROC) (GLuint, GLuint, GLsizei, const GLuint *, const GLintptr *, const GLsizei *);
typedef void (APIENTRY *PFNGLVERTEXARRAYATTRIBBINDINGPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYATTRIBFORMATPROC) (GLuint, GLuint, GLint, GLenum, GLboolean, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYATTRIBIFORMATPROC) (GLuint, GLuint, GLint, GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYATTRIBLFORMATPROC) (GLuint, GLuint, GLint, GLenum, GLuint);
typedef void (APIENTRY *PFNGLVERTEXARRAYBINDINGDIVISORPROC) (GLuint, GLuint, GLuint);
typedef void (APIENTRY *PFNGLGETVERTEXARRAYIVPROC) (GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETVERTEXARRAYINDEXEDIVPROC) (GLuint, GLuint, GLenum, GLint *);
typedef void (APIENTRY *PFNGLGETVERTEXARRAYINDEXED64IVPROC) (GLuint, GLuint, GLenum, GLint64 *);
typedef void (APIENTRY *PFNGLCREATESAMPLERSPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLCREATEPROGRAMPIPELINESPROC) (GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLCREATEQUERIESPROC) (GLenum, GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLGETQUERYBUFFEROBJECTI64VPROC) (GLuint, GLuint, GLenum, GLintptr);
typedef void (APIENTRY *PFNGLGETQUERYBUFFEROBJECTIVPROC) (GLuint, GLuint, GLenum, GLintptr);
typedef void (APIENTRY *PFNGLGETQUERYBUFFEROBJECTUI64VPROC) (GLuint, GLuint, GLenum, GLintptr);
typedef void (APIENTRY *PFNGLGETQUERYBUFFEROBJECTUIVPROC) (GLuint, GLuint, GLenum, GLintptr);
typedef void (APIENTRY *PFNGLMEMORYBARRIERBYREGIONPROC) (GLbitfield);
typedef void (APIENTRY *PFNGLGETTEXTURESUBIMAGEPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) (GLuint, GLint, GLint, GLint, GLint, GLsizei, GLsizei, GLsizei, GLsizei, void *);
typedef GLenum (APIENTRY *PFNGLGETGRAPHICSRESETSTATUSPROC) ();
typedef void (APIENTRY *PFNGLGETNCOMPRESSEDTEXIMAGEPROC) (GLenum, GLint, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNTEXIMAGEPROC) (GLenum, GLint, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNUNIFORMDVPROC) (GLuint, GLint, GLsizei, GLdouble *);
typedef void (APIENTRY *PFNGLGETNUNIFORMFVPROC) (GLuint, GLint, GLsizei, GLfloat *);
typedef void (APIENTRY *PFNGLGETNUNIFORMIVPROC) (GLuint, GLint, GLsizei, GLint *);
typedef void (APIENTRY *PFNGLGETNUNIFORMUIVPROC) (GLuint, GLint, GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLREADNPIXELSPROC) (GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNMAPDVPROC) (GLenum, GLenum, GLsizei, GLdouble *);
typedef void (APIENTRY *PFNGLGETNMAPFVPROC) (GLenum, GLenum, GLsizei, GLfloat *);
typedef void (APIENTRY *PFNGLGETNMAPIVPROC) (GLenum, GLenum, GLsizei, GLint *);
typedef void (APIENTRY *PFNGLGETNPIXELMAPFVPROC) (GLenum, GLsizei, GLfloat *);
typedef void (APIENTRY *PFNGLGETNPIXELMAPUIVPROC) (GLenum, GLsizei, GLuint *);
typedef void (APIENTRY *PFNGLGETNPIXELMAPUSVPROC) (GLenum, GLsizei, GLushort *);
typedef void (APIENTRY *PFNGLGETNPOLYGONSTIPPLEPROC) (GLsizei, GLubyte *);
typedef void (APIENTRY *PFNGLGETNCOLORTABLEPROC) (GLenum, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNCONVOLUTIONFILTERPROC) (GLenum, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNSEPARABLEFILTERPROC) (GLenum, GLenum, GLenum, GLsizei, void *, GLsizei, void *, void *);
typedef void (APIENTRY *PFNGLGETNHISTOGRAMPROC) (GLenum, GLboolean, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLGETNMINMAXPROC) (GLenum, GLboolean, GLenum, GLenum, GLsizei, void *);
typedef void (APIENTRY *PFNGLTEXTUREBARRIERPROC) ();

# endif /* GL_VERSION_4_5 */ /* }}} */
# if !defined (GL_VERSION_4_6) /* {{{ */
#  define GL_VERSION_4_6 1
#  define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551
#  define GL_SPIR_V_BINARY 0x9552
#  define GL_PARAMETER_BUFFER 0x80EE
#  define GL_PARAMETER_BUFFER_BINDING 0x80EF
#  define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008
#  define GL_VERTICES_SUBMITTED 0x82EE
#  define GL_PRIMITIVES_SUBMITTED 0x82EF
#  define GL_VERTEX_SHADER_INVOCATIONS 0x82F0
#  define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
#  define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#  define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#  define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
#  define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
#  define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
#  define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
#  define GL_POLYGON_OFFSET_CLAMP 0x8E1B
#  define GL_SPIR_V_EXTENSIONS 0x9553
#  define GL_NUM_SPIR_V_EXTENSIONS 0x9554
#  define GL_TEXTURE_MAX_ANISOTROPY 0x84FE
#  define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
#  define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC
#  define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED

typedef void (APIENTRY *PFNGLSPECIALIZESHADERPROC) (GLuint, const GLchar *, GLuint, const GLuint *, const GLuint *);
typedef void (APIENTRY *PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) (GLenum, const void *, GLintptr, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) (GLenum, GLenum, const void *, GLintptr, GLsizei, GLsizei);
typedef void (APIENTRY *PFNGLPOLYGONOFFSETCLAMPPROC) (GLfloat, GLfloat, GLfloat);

# endif /* GL_VERSION_4_6 */ /* }}} */
/* }}} */

/* OpenGL extensions */

/* {{{ */

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
	PFNGLCULLFACEPROC glCullFace;
	PFNGLFRONTFACEPROC glFrontFace;
	PFNGLHINTPROC glHint;
	PFNGLLINEWIDTHPROC glLineWidth;
	PFNGLPOINTSIZEPROC glPointSize;
	PFNGLPOLYGONMODEPROC glPolygonMode;
	PFNGLSCISSORPROC glScissor;
	PFNGLTEXPARAMETERFPROC glTexParameterf;
	PFNGLTEXPARAMETERFVPROC glTexParameterfv;
	PFNGLTEXPARAMETERIPROC glTexParameteri;
	PFNGLTEXPARAMETERIVPROC glTexParameteriv;
	PFNGLTEXIMAGE1DPROC glTexImage1D;
	PFNGLTEXIMAGE2DPROC glTexImage2D;
	PFNGLDRAWBUFFERPROC glDrawBuffer;
	PFNGLCLEARPROC glClear;
	PFNGLCLEARCOLORPROC glClearColor;
	PFNGLCLEARSTENCILPROC glClearStencil;
	PFNGLCLEARDEPTHPROC glClearDepth;
	PFNGLSTENCILMASKPROC glStencilMask;
	PFNGLCOLORMASKPROC glColorMask;
	PFNGLDEPTHMASKPROC glDepthMask;
	PFNGLDISABLEPROC glDisable;
	PFNGLENABLEPROC glEnable;
	PFNGLFINISHPROC glFinish;
	PFNGLFLUSHPROC glFlush;
	PFNGLBLENDFUNCPROC glBlendFunc;
	PFNGLLOGICOPPROC glLogicOp;
	PFNGLSTENCILFUNCPROC glStencilFunc;
	PFNGLSTENCILOPPROC glStencilOp;
	PFNGLDEPTHFUNCPROC glDepthFunc;
	PFNGLPIXELSTOREFPROC glPixelStoref;
	PFNGLPIXELSTOREIPROC glPixelStorei;
	PFNGLREADBUFFERPROC glReadBuffer;
	PFNGLREADPIXELSPROC glReadPixels;
	PFNGLGETBOOLEANVPROC glGetBooleanv;
	PFNGLGETDOUBLEVPROC glGetDoublev;
	PFNGLGETERRORPROC glGetError;
	PFNGLGETFLOATVPROC glGetFloatv;
	PFNGLGETINTEGERVPROC glGetIntegerv;
	PFNGLGETSTRINGPROC glGetString;
	PFNGLGETTEXIMAGEPROC glGetTexImage;
	PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
	PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
	PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
	PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
	PFNGLISENABLEDPROC glIsEnabled;
	PFNGLDEPTHRANGEPROC glDepthRange;
	PFNGLVIEWPORTPROC glViewport;
	PFNGLNEWLISTPROC glNewList;
	PFNGLENDLISTPROC glEndList;
	PFNGLCALLLISTPROC glCallList;
	PFNGLCALLLISTSPROC glCallLists;
	PFNGLDELETELISTSPROC glDeleteLists;
	PFNGLGENLISTSPROC glGenLists;
	PFNGLLISTBASEPROC glListBase;
	PFNGLBEGINPROC glBegin;
	PFNGLBITMAPPROC glBitmap;
	PFNGLCOLOR3BPROC glColor3b;
	PFNGLCOLOR3BVPROC glColor3bv;
	PFNGLCOLOR3DPROC glColor3d;
	PFNGLCOLOR3DVPROC glColor3dv;
	PFNGLCOLOR3FPROC glColor3f;
	PFNGLCOLOR3FVPROC glColor3fv;
	PFNGLCOLOR3IPROC glColor3i;
	PFNGLCOLOR3IVPROC glColor3iv;
	PFNGLCOLOR3SPROC glColor3s;
	PFNGLCOLOR3SVPROC glColor3sv;
	PFNGLCOLOR3UBPROC glColor3ub;
	PFNGLCOLOR3UBVPROC glColor3ubv;
	PFNGLCOLOR3UIPROC glColor3ui;
	PFNGLCOLOR3UIVPROC glColor3uiv;
	PFNGLCOLOR3USPROC glColor3us;
	PFNGLCOLOR3USVPROC glColor3usv;
	PFNGLCOLOR4BPROC glColor4b;
	PFNGLCOLOR4BVPROC glColor4bv;
	PFNGLCOLOR4DPROC glColor4d;
	PFNGLCOLOR4DVPROC glColor4dv;
	PFNGLCOLOR4FPROC glColor4f;
	PFNGLCOLOR4FVPROC glColor4fv;
	PFNGLCOLOR4IPROC glColor4i;
	PFNGLCOLOR4IVPROC glColor4iv;
	PFNGLCOLOR4SPROC glColor4s;
	PFNGLCOLOR4SVPROC glColor4sv;
	PFNGLCOLOR4UBPROC glColor4ub;
	PFNGLCOLOR4UBVPROC glColor4ubv;
	PFNGLCOLOR4UIPROC glColor4ui;
	PFNGLCOLOR4UIVPROC glColor4uiv;
	PFNGLCOLOR4USPROC glColor4us;
	PFNGLCOLOR4USVPROC glColor4usv;
	PFNGLEDGEFLAGPROC glEdgeFlag;
	PFNGLEDGEFLAGVPROC glEdgeFlagv;
	PFNGLENDPROC glEnd;
	PFNGLINDEXDPROC glIndexd;
	PFNGLINDEXDVPROC glIndexdv;
	PFNGLINDEXFPROC glIndexf;
	PFNGLINDEXFVPROC glIndexfv;
	PFNGLINDEXIPROC glIndexi;
	PFNGLINDEXIVPROC glIndexiv;
	PFNGLINDEXSPROC glIndexs;
	PFNGLINDEXSVPROC glIndexsv;
	PFNGLNORMAL3BPROC glNormal3b;
	PFNGLNORMAL3BVPROC glNormal3bv;
	PFNGLNORMAL3DPROC glNormal3d;
	PFNGLNORMAL3DVPROC glNormal3dv;
	PFNGLNORMAL3FPROC glNormal3f;
	PFNGLNORMAL3FVPROC glNormal3fv;
	PFNGLNORMAL3IPROC glNormal3i;
	PFNGLNORMAL3IVPROC glNormal3iv;
	PFNGLNORMAL3SPROC glNormal3s;
	PFNGLNORMAL3SVPROC glNormal3sv;
	PFNGLRASTERPOS2DPROC glRasterPos2d;
	PFNGLRASTERPOS2DVPROC glRasterPos2dv;
	PFNGLRASTERPOS2FPROC glRasterPos2f;
	PFNGLRASTERPOS2FVPROC glRasterPos2fv;
	PFNGLRASTERPOS2IPROC glRasterPos2i;
	PFNGLRASTERPOS2IVPROC glRasterPos2iv;
	PFNGLRASTERPOS2SPROC glRasterPos2s;
	PFNGLRASTERPOS2SVPROC glRasterPos2sv;
	PFNGLRASTERPOS3DPROC glRasterPos3d;
	PFNGLRASTERPOS3DVPROC glRasterPos3dv;
	PFNGLRASTERPOS3FPROC glRasterPos3f;
	PFNGLRASTERPOS3FVPROC glRasterPos3fv;
	PFNGLRASTERPOS3IPROC glRasterPos3i;
	PFNGLRASTERPOS3IVPROC glRasterPos3iv;
	PFNGLRASTERPOS3SPROC glRasterPos3s;
	PFNGLRASTERPOS3SVPROC glRasterPos3sv;
	PFNGLRASTERPOS4DPROC glRasterPos4d;
	PFNGLRASTERPOS4DVPROC glRasterPos4dv;
	PFNGLRASTERPOS4FPROC glRasterPos4f;
	PFNGLRASTERPOS4FVPROC glRasterPos4fv;
	PFNGLRASTERPOS4IPROC glRasterPos4i;
	PFNGLRASTERPOS4IVPROC glRasterPos4iv;
	PFNGLRASTERPOS4SPROC glRasterPos4s;
	PFNGLRASTERPOS4SVPROC glRasterPos4sv;
	PFNGLRECTDPROC glRectd;
	PFNGLRECTDVPROC glRectdv;
	PFNGLRECTFPROC glRectf;
	PFNGLRECTFVPROC glRectfv;
	PFNGLRECTIPROC glRecti;
	PFNGLRECTIVPROC glRectiv;
	PFNGLRECTSPROC glRects;
	PFNGLRECTSVPROC glRectsv;
	PFNGLTEXCOORD1DPROC glTexCoord1d;
	PFNGLTEXCOORD1DVPROC glTexCoord1dv;
	PFNGLTEXCOORD1FPROC glTexCoord1f;
	PFNGLTEXCOORD1FVPROC glTexCoord1fv;
	PFNGLTEXCOORD1IPROC glTexCoord1i;
	PFNGLTEXCOORD1IVPROC glTexCoord1iv;
	PFNGLTEXCOORD1SPROC glTexCoord1s;
	PFNGLTEXCOORD1SVPROC glTexCoord1sv;
	PFNGLTEXCOORD2DPROC glTexCoord2d;
	PFNGLTEXCOORD2DVPROC glTexCoord2dv;
	PFNGLTEXCOORD2FPROC glTexCoord2f;
	PFNGLTEXCOORD2FVPROC glTexCoord2fv;
	PFNGLTEXCOORD2IPROC glTexCoord2i;
	PFNGLTEXCOORD2IVPROC glTexCoord2iv;
	PFNGLTEXCOORD2SPROC glTexCoord2s;
	PFNGLTEXCOORD2SVPROC glTexCoord2sv;
	PFNGLTEXCOORD3DPROC glTexCoord3d;
	PFNGLTEXCOORD3DVPROC glTexCoord3dv;
	PFNGLTEXCOORD3FPROC glTexCoord3f;
	PFNGLTEXCOORD3FVPROC glTexCoord3fv;
	PFNGLTEXCOORD3IPROC glTexCoord3i;
	PFNGLTEXCOORD3IVPROC glTexCoord3iv;
	PFNGLTEXCOORD3SPROC glTexCoord3s;
	PFNGLTEXCOORD3SVPROC glTexCoord3sv;
	PFNGLTEXCOORD4DPROC glTexCoord4d;
	PFNGLTEXCOORD4DVPROC glTexCoord4dv;
	PFNGLTEXCOORD4FPROC glTexCoord4f;
	PFNGLTEXCOORD4FVPROC glTexCoord4fv;
	PFNGLTEXCOORD4IPROC glTexCoord4i;
	PFNGLTEXCOORD4IVPROC glTexCoord4iv;
	PFNGLTEXCOORD4SPROC glTexCoord4s;
	PFNGLTEXCOORD4SVPROC glTexCoord4sv;
	PFNGLVERTEX2DPROC glVertex2d;
	PFNGLVERTEX2DVPROC glVertex2dv;
	PFNGLVERTEX2FPROC glVertex2f;
	PFNGLVERTEX2FVPROC glVertex2fv;
	PFNGLVERTEX2IPROC glVertex2i;
	PFNGLVERTEX2IVPROC glVertex2iv;
	PFNGLVERTEX2SPROC glVertex2s;
	PFNGLVERTEX2SVPROC glVertex2sv;
	PFNGLVERTEX3DPROC glVertex3d;
	PFNGLVERTEX3DVPROC glVertex3dv;
	PFNGLVERTEX3FPROC glVertex3f;
	PFNGLVERTEX3FVPROC glVertex3fv;
	PFNGLVERTEX3IPROC glVertex3i;
	PFNGLVERTEX3IVPROC glVertex3iv;
	PFNGLVERTEX3SPROC glVertex3s;
	PFNGLVERTEX3SVPROC glVertex3sv;
	PFNGLVERTEX4DPROC glVertex4d;
	PFNGLVERTEX4DVPROC glVertex4dv;
	PFNGLVERTEX4FPROC glVertex4f;
	PFNGLVERTEX4FVPROC glVertex4fv;
	PFNGLVERTEX4IPROC glVertex4i;
	PFNGLVERTEX4IVPROC glVertex4iv;
	PFNGLVERTEX4SPROC glVertex4s;
	PFNGLVERTEX4SVPROC glVertex4sv;
	PFNGLCLIPPLANEPROC glClipPlane;
	PFNGLCOLORMATERIALPROC glColorMaterial;
	PFNGLFOGFPROC glFogf;
	PFNGLFOGFVPROC glFogfv;
	PFNGLFOGIPROC glFogi;
	PFNGLFOGIVPROC glFogiv;
	PFNGLLIGHTFPROC glLightf;
	PFNGLLIGHTFVPROC glLightfv;
	PFNGLLIGHTIPROC glLighti;
	PFNGLLIGHTIVPROC glLightiv;
	PFNGLLIGHTMODELFPROC glLightModelf;
	PFNGLLIGHTMODELFVPROC glLightModelfv;
	PFNGLLIGHTMODELIPROC glLightModeli;
	PFNGLLIGHTMODELIVPROC glLightModeliv;
	PFNGLLINESTIPPLEPROC glLineStipple;
	PFNGLMATERIALFPROC glMaterialf;
	PFNGLMATERIALFVPROC glMaterialfv;
	PFNGLMATERIALIPROC glMateriali;
	PFNGLMATERIALIVPROC glMaterialiv;
	PFNGLPOLYGONSTIPPLEPROC glPolygonStipple;
	PFNGLSHADEMODELPROC glShadeModel;
	PFNGLTEXENVFPROC glTexEnvf;
	PFNGLTEXENVFVPROC glTexEnvfv;
	PFNGLTEXENVIPROC glTexEnvi;
	PFNGLTEXENVIVPROC glTexEnviv;
	PFNGLTEXGENDPROC glTexGend;
	PFNGLTEXGENDVPROC glTexGendv;
	PFNGLTEXGENFPROC glTexGenf;
	PFNGLTEXGENFVPROC glTexGenfv;
	PFNGLTEXGENIPROC glTexGeni;
	PFNGLTEXGENIVPROC glTexGeniv;
	PFNGLFEEDBACKBUFFERPROC glFeedbackBuffer;
	PFNGLSELECTBUFFERPROC glSelectBuffer;
	PFNGLRENDERMODEPROC glRenderMode;
	PFNGLINITNAMESPROC glInitNames;
	PFNGLLOADNAMEPROC glLoadName;
	PFNGLPASSTHROUGHPROC glPassThrough;
	PFNGLPOPNAMEPROC glPopName;
	PFNGLPUSHNAMEPROC glPushName;
	PFNGLCLEARACCUMPROC glClearAccum;
	PFNGLCLEARINDEXPROC glClearIndex;
	PFNGLINDEXMASKPROC glIndexMask;
	PFNGLACCUMPROC glAccum;
	PFNGLPOPATTRIBPROC glPopAttrib;
	PFNGLPUSHATTRIBPROC glPushAttrib;
	PFNGLMAP1DPROC glMap1d;
	PFNGLMAP1FPROC glMap1f;
	PFNGLMAP2DPROC glMap2d;
	PFNGLMAP2FPROC glMap2f;
	PFNGLMAPGRID1DPROC glMapGrid1d;
	PFNGLMAPGRID1FPROC glMapGrid1f;
	PFNGLMAPGRID2DPROC glMapGrid2d;
	PFNGLMAPGRID2FPROC glMapGrid2f;
	PFNGLEVALCOORD1DPROC glEvalCoord1d;
	PFNGLEVALCOORD1DVPROC glEvalCoord1dv;
	PFNGLEVALCOORD1FPROC glEvalCoord1f;
	PFNGLEVALCOORD1FVPROC glEvalCoord1fv;
	PFNGLEVALCOORD2DPROC glEvalCoord2d;
	PFNGLEVALCOORD2DVPROC glEvalCoord2dv;
	PFNGLEVALCOORD2FPROC glEvalCoord2f;
	PFNGLEVALCOORD2FVPROC glEvalCoord2fv;
	PFNGLEVALMESH1PROC glEvalMesh1;
	PFNGLEVALPOINT1PROC glEvalPoint1;
	PFNGLEVALMESH2PROC glEvalMesh2;
	PFNGLEVALPOINT2PROC glEvalPoint2;
	PFNGLALPHAFUNCPROC glAlphaFunc;
	PFNGLPIXELZOOMPROC glPixelZoom;
	PFNGLPIXELTRANSFERFPROC glPixelTransferf;
	PFNGLPIXELTRANSFERIPROC glPixelTransferi;
	PFNGLPIXELMAPFVPROC glPixelMapfv;
	PFNGLPIXELMAPUIVPROC glPixelMapuiv;
	PFNGLPIXELMAPUSVPROC glPixelMapusv;
	PFNGLCOPYPIXELSPROC glCopyPixels;
	PFNGLDRAWPIXELSPROC glDrawPixels;
	PFNGLGETCLIPPLANEPROC glGetClipPlane;
	PFNGLGETLIGHTFVPROC glGetLightfv;
	PFNGLGETLIGHTIVPROC glGetLightiv;
	PFNGLGETMAPDVPROC glGetMapdv;
	PFNGLGETMAPFVPROC glGetMapfv;
	PFNGLGETMAPIVPROC glGetMapiv;
	PFNGLGETMATERIALFVPROC glGetMaterialfv;
	PFNGLGETMATERIALIVPROC glGetMaterialiv;
	PFNGLGETPIXELMAPFVPROC glGetPixelMapfv;
	PFNGLGETPIXELMAPUIVPROC glGetPixelMapuiv;
	PFNGLGETPIXELMAPUSVPROC glGetPixelMapusv;
	PFNGLGETPOLYGONSTIPPLEPROC glGetPolygonStipple;
	PFNGLGETTEXENVFVPROC glGetTexEnvfv;
	PFNGLGETTEXENVIVPROC glGetTexEnviv;
	PFNGLGETTEXGENDVPROC glGetTexGendv;
	PFNGLGETTEXGENFVPROC glGetTexGenfv;
	PFNGLGETTEXGENIVPROC glGetTexGeniv;
	PFNGLISLISTPROC glIsList;
	PFNGLFRUSTUMPROC glFrustum;
	PFNGLLOADIDENTITYPROC glLoadIdentity;
	PFNGLLOADMATRIXFPROC glLoadMatrixf;
	PFNGLLOADMATRIXDPROC glLoadMatrixd;
	PFNGLMATRIXMODEPROC glMatrixMode;
	PFNGLMULTMATRIXFPROC glMultMatrixf;
	PFNGLMULTMATRIXDPROC glMultMatrixd;
	PFNGLORTHOPROC glOrtho;
	PFNGLPOPMATRIXPROC glPopMatrix;
	PFNGLPUSHMATRIXPROC glPushMatrix;
	PFNGLROTATEDPROC glRotated;
	PFNGLROTATEFPROC glRotatef;
	PFNGLSCALEDPROC glScaled;
	PFNGLSCALEFPROC glScalef;
	PFNGLTRANSLATEDPROC glTranslated;
	PFNGLTRANSLATEFPROC glTranslatef;
	PFNGLDRAWARRAYSPROC glDrawArrays;
	PFNGLDRAWELEMENTSPROC glDrawElements;
	PFNGLGETPOINTERVPROC glGetPointerv;
	PFNGLPOLYGONOFFSETPROC glPolygonOffset;
	PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
	PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
	PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
	PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
	PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
	PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
	PFNGLBINDTEXTUREPROC glBindTexture;
	PFNGLDELETETEXTURESPROC glDeleteTextures;
	PFNGLGENTEXTURESPROC glGenTextures;
	PFNGLISTEXTUREPROC glIsTexture;
	PFNGLARRAYELEMENTPROC glArrayElement;
	PFNGLCOLORPOINTERPROC glColorPointer;
	PFNGLDISABLECLIENTSTATEPROC glDisableClientState;
	PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer;
	PFNGLENABLECLIENTSTATEPROC glEnableClientState;
	PFNGLINDEXPOINTERPROC glIndexPointer;
	PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays;
	PFNGLNORMALPOINTERPROC glNormalPointer;
	PFNGLTEXCOORDPOINTERPROC glTexCoordPointer;
	PFNGLVERTEXPOINTERPROC glVertexPointer;
	PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident;
	PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures;
	PFNGLINDEXUBPROC glIndexub;
	PFNGLINDEXUBVPROC glIndexubv;
	PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib;
	PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib;
	PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
	PFNGLTEXIMAGE3DPROC glTexImage3D;
	PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
	PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;
	PFNGLACTIVETEXTUREPROC glActiveTexture;
	PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
	PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
	PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
	PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
	PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
	PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
	PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
	PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
	PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;
	PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d;
	PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv;
	PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f;
	PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv;
	PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i;
	PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv;
	PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s;
	PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv;
	PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d;
	PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv;
	PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f;
	PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv;
	PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i;
	PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv;
	PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s;
	PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv;
	PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d;
	PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv;
	PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f;
	PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
	PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i;
	PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv;
	PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s;
	PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv;
	PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d;
	PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv;
	PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f;
	PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv;
	PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i;
	PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv;
	PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s;
	PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv;
	PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf;
	PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd;
	PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf;
	PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd;
	PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
	PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
	PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
	PFNGLPOINTPARAMETERFPROC glPointParameterf;
	PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
	PFNGLPOINTPARAMETERIPROC glPointParameteri;
	PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
	PFNGLFOGCOORDFPROC glFogCoordf;
	PFNGLFOGCOORDFVPROC glFogCoordfv;
	PFNGLFOGCOORDDPROC glFogCoordd;
	PFNGLFOGCOORDDVPROC glFogCoorddv;
	PFNGLFOGCOORDPOINTERPROC glFogCoordPointer;
	PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b;
	PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv;
	PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d;
	PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv;
	PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f;
	PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv;
	PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i;
	PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv;
	PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s;
	PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv;
	PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub;
	PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv;
	PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui;
	PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv;
	PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us;
	PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv;
	PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer;
	PFNGLWINDOWPOS2DPROC glWindowPos2d;
	PFNGLWINDOWPOS2DVPROC glWindowPos2dv;
	PFNGLWINDOWPOS2FPROC glWindowPos2f;
	PFNGLWINDOWPOS2FVPROC glWindowPos2fv;
	PFNGLWINDOWPOS2IPROC glWindowPos2i;
	PFNGLWINDOWPOS2IVPROC glWindowPos2iv;
	PFNGLWINDOWPOS2SPROC glWindowPos2s;
	PFNGLWINDOWPOS2SVPROC glWindowPos2sv;
	PFNGLWINDOWPOS3DPROC glWindowPos3d;
	PFNGLWINDOWPOS3DVPROC glWindowPos3dv;
	PFNGLWINDOWPOS3FPROC glWindowPos3f;
	PFNGLWINDOWPOS3FVPROC glWindowPos3fv;
	PFNGLWINDOWPOS3IPROC glWindowPos3i;
	PFNGLWINDOWPOS3IVPROC glWindowPos3iv;
	PFNGLWINDOWPOS3SPROC glWindowPos3s;
	PFNGLWINDOWPOS3SVPROC glWindowPos3sv;
	PFNGLBLENDCOLORPROC glBlendColor;
	PFNGLBLENDEQUATIONPROC glBlendEquation;
	PFNGLGENQUERIESPROC glGenQueries;
	PFNGLDELETEQUERIESPROC glDeleteQueries;
	PFNGLISQUERYPROC glIsQuery;
	PFNGLBEGINQUERYPROC glBeginQuery;
	PFNGLENDQUERYPROC glEndQuery;
	PFNGLGETQUERYIVPROC glGetQueryiv;
	PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
	PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
	PFNGLBINDBUFFERPROC glBindBuffer;
	PFNGLDELETEBUFFERSPROC glDeleteBuffers;
	PFNGLGENBUFFERSPROC glGenBuffers;
	PFNGLISBUFFERPROC glIsBuffer;
	PFNGLBUFFERDATAPROC glBufferData;
	PFNGLBUFFERSUBDATAPROC glBufferSubData;
	PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
	PFNGLMAPBUFFERPROC glMapBuffer;
	PFNGLUNMAPBUFFERPROC glUnmapBuffer;
	PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
	PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
	PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
	PFNGLDRAWBUFFERSPROC glDrawBuffers;
	PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
	PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
	PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
	PFNGLATTACHSHADERPROC glAttachShader;
	PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
	PFNGLCOMPILESHADERPROC glCompileShader;
	PFNGLCREATEPROGRAMPROC glCreateProgram;
	PFNGLCREATESHADERPROC glCreateShader;
	PFNGLDELETEPROGRAMPROC glDeleteProgram;
	PFNGLDELETESHADERPROC glDeleteShader;
	PFNGLDETACHSHADERPROC glDetachShader;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
	PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
	PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
	PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
	PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
	PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
	PFNGLGETPROGRAMIVPROC glGetProgramiv;
	PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
	PFNGLGETSHADERIVPROC glGetShaderiv;
	PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
	PFNGLGETSHADERSOURCEPROC glGetShaderSource;
	PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
	PFNGLGETUNIFORMFVPROC glGetUniformfv;
	PFNGLGETUNIFORMIVPROC glGetUniformiv;
	PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
	PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
	PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
	PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
	PFNGLISPROGRAMPROC glIsProgram;
	PFNGLISSHADERPROC glIsShader;
	PFNGLLINKPROGRAMPROC glLinkProgram;
	PFNGLSHADERSOURCEPROC glShaderSource;
	PFNGLUSEPROGRAMPROC glUseProgram;
	PFNGLUNIFORM1FPROC glUniform1f;
	PFNGLUNIFORM2FPROC glUniform2f;
	PFNGLUNIFORM3FPROC glUniform3f;
	PFNGLUNIFORM4FPROC glUniform4f;
	PFNGLUNIFORM1IPROC glUniform1i;
	PFNGLUNIFORM2IPROC glUniform2i;
	PFNGLUNIFORM3IPROC glUniform3i;
	PFNGLUNIFORM4IPROC glUniform4i;
	PFNGLUNIFORM1FVPROC glUniform1fv;
	PFNGLUNIFORM2FVPROC glUniform2fv;
	PFNGLUNIFORM3FVPROC glUniform3fv;
	PFNGLUNIFORM4FVPROC glUniform4fv;
	PFNGLUNIFORM1IVPROC glUniform1iv;
	PFNGLUNIFORM2IVPROC glUniform2iv;
	PFNGLUNIFORM3IVPROC glUniform3iv;
	PFNGLUNIFORM4IVPROC glUniform4iv;
	PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
	PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
	PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
	PFNGLVALIDATEPROGRAMPROC glValidateProgram;
	PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
	PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
	PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
	PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
	PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
	PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
	PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
	PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
	PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
	PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
	PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
	PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
	PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
	PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
	PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
	PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
	PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
	PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
	PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
	PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
	PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
	PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
	PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
	PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
	PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
	PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
	PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
	PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
	PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
	PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
	PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
	PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
	PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
	PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
	PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
	PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
	PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
	PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
	PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
	PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
	PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
	PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
	PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
	PFNGLCOLORMASKIPROC glColorMaski;
	PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
	PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
	PFNGLENABLEIPROC glEnablei;
	PFNGLDISABLEIPROC glDisablei;
	PFNGLISENABLEDIPROC glIsEnabledi;
	PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
	PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
	PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
	PFNGLBINDBUFFERBASEPROC glBindBufferBase;
	PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
	PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
	PFNGLCLAMPCOLORPROC glClampColor;
	PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
	PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
	PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
	PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
	PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
	PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
	PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
	PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
	PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
	PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
	PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
	PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
	PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
	PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
	PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
	PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
	PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
	PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
	PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
	PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
	PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
	PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
	PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
	PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
	PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
	PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
	PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
	PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
	PFNGLUNIFORM1UIPROC glUniform1ui;
	PFNGLUNIFORM2UIPROC glUniform2ui;
	PFNGLUNIFORM3UIPROC glUniform3ui;
	PFNGLUNIFORM4UIPROC glUniform4ui;
	PFNGLUNIFORM1UIVPROC glUniform1uiv;
	PFNGLUNIFORM2UIVPROC glUniform2uiv;
	PFNGLUNIFORM3UIVPROC glUniform3uiv;
	PFNGLUNIFORM4UIVPROC glUniform4uiv;
	PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
	PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
	PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
	PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
	PFNGLCLEARBUFFERIVPROC glClearBufferiv;
	PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
	PFNGLCLEARBUFFERFVPROC glClearBufferfv;
	PFNGLCLEARBUFFERFIPROC glClearBufferfi;
	PFNGLGETSTRINGIPROC glGetStringi;
	PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
	PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
	PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
	PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
	PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
	PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
	PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
	PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
	PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
	PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
	PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
	PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
	PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
	PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
	PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
	PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
	PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
	PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
	PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
	PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
	PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
	PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
	PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
	PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
	PFNGLISVERTEXARRAYPROC glIsVertexArray;
	PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
	PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
	PFNGLTEXBUFFERPROC glTexBuffer;
	PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
	PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
	PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
	PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
	PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
	PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
	PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
	PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;
	PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
	PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
	PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
	PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
	PFNGLFENCESYNCPROC glFenceSync;
	PFNGLISSYNCPROC glIsSync;
	PFNGLDELETESYNCPROC glDeleteSync;
	PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
	PFNGLWAITSYNCPROC glWaitSync;
	PFNGLGETINTEGER64VPROC glGetInteger64v;
	PFNGLGETSYNCIVPROC glGetSynciv;
	PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
	PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
	PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
	PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
	PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
	PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
	PFNGLSAMPLEMASKIPROC glSampleMaski;
	PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
	PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
	PFNGLGENSAMPLERSPROC glGenSamplers;
	PFNGLDELETESAMPLERSPROC glDeleteSamplers;
	PFNGLISSAMPLERPROC glIsSampler;
	PFNGLBINDSAMPLERPROC glBindSampler;
	PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
	PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
	PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
	PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
	PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
	PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
	PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
	PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
	PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
	PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
	PFNGLQUERYCOUNTERPROC glQueryCounter;
	PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
	PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
	PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
	PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
	PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
	PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
	PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
	PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
	PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
	PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
	PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
	PFNGLVERTEXP2UIPROC glVertexP2ui;
	PFNGLVERTEXP2UIVPROC glVertexP2uiv;
	PFNGLVERTEXP3UIPROC glVertexP3ui;
	PFNGLVERTEXP3UIVPROC glVertexP3uiv;
	PFNGLVERTEXP4UIPROC glVertexP4ui;
	PFNGLVERTEXP4UIVPROC glVertexP4uiv;
	PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
	PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
	PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
	PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
	PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
	PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
	PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
	PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
	PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
	PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
	PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
	PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
	PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
	PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
	PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
	PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
	PFNGLNORMALP3UIPROC glNormalP3ui;
	PFNGLNORMALP3UIVPROC glNormalP3uiv;
	PFNGLCOLORP3UIPROC glColorP3ui;
	PFNGLCOLORP3UIVPROC glColorP3uiv;
	PFNGLCOLORP4UIPROC glColorP4ui;
	PFNGLCOLORP4UIVPROC glColorP4uiv;
	PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
	PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;
	PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
	PFNGLBLENDEQUATIONIPROC glBlendEquationi;
	PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
	PFNGLBLENDFUNCIPROC glBlendFunci;
	PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
	PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
	PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
	PFNGLUNIFORM1DPROC glUniform1d;
	PFNGLUNIFORM2DPROC glUniform2d;
	PFNGLUNIFORM3DPROC glUniform3d;
	PFNGLUNIFORM4DPROC glUniform4d;
	PFNGLUNIFORM1DVPROC glUniform1dv;
	PFNGLUNIFORM2DVPROC glUniform2dv;
	PFNGLUNIFORM3DVPROC glUniform3dv;
	PFNGLUNIFORM4DVPROC glUniform4dv;
	PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
	PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
	PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
	PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
	PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
	PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
	PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
	PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
	PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
	PFNGLGETUNIFORMDVPROC glGetUniformdv;
	PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
	PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
	PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
	PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
	PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
	PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
	PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
	PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
	PFNGLPATCHPARAMETERIPROC glPatchParameteri;
	PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
	PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
	PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
	PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
	PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
	PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
	PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
	PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
	PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
	PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
	PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;
	PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
	PFNGLSHADERBINARYPROC glShaderBinary;
	PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
	PFNGLDEPTHRANGEFPROC glDepthRangef;
	PFNGLCLEARDEPTHFPROC glClearDepthf;
	PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
	PFNGLPROGRAMBINARYPROC glProgramBinary;
	PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
	PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
	PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
	PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
	PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
	PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
	PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
	PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
	PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
	PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
	PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
	PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
	PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
	PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
	PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
	PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
	PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
	PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
	PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
	PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
	PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
	PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
	PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
	PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
	PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
	PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
	PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
	PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
	PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
	PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
	PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
	PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
	PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
	PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
	PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
	PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
	PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
	PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
	PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
	PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
	PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
	PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
	PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
	PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
	PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
	PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
	PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
	PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
	PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
	PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
	PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
	PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
	PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
	PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
	PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
	PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
	PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
	PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
	PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
	PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
	PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
	PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
	PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
	PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
	PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
	PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
	PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
	PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
	PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
	PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
	PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
	PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
	PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
	PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
	PFNGLSCISSORARRAYVPROC glScissorArrayv;
	PFNGLSCISSORINDEXEDPROC glScissorIndexed;
	PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
	PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
	PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
	PFNGLGETFLOATI_VPROC glGetFloati_v;
	PFNGLGETDOUBLEI_VPROC glGetDoublei_v;
	PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
	PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
	PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
	PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
	PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
	PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
	PFNGLMEMORYBARRIERPROC glMemoryBarrier;
	PFNGLTEXSTORAGE1DPROC glTexStorage1D;
	PFNGLTEXSTORAGE2DPROC glTexStorage2D;
	PFNGLTEXSTORAGE3DPROC glTexStorage3D;
	PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
	PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;
	PFNGLCLEARBUFFERDATAPROC glClearBufferData;
	PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
	PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
	PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
	PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
	PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
	PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
	PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
	PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
	PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
	PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
	PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
	PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
	PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
	PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
	PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
	PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
	PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
	PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
	PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
	PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
	PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
	PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
	PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
	PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
	PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
	PFNGLTEXTUREVIEWPROC glTextureView;
	PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
	PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
	PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
	PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
	PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
	PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
	PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
	PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
	PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
	PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
	PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
	PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
	PFNGLOBJECTLABELPROC glObjectLabel;
	PFNGLGETOBJECTLABELPROC glGetObjectLabel;
	PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
	PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
	PFNGLBUFFERSTORAGEPROC glBufferStorage;
	PFNGLCLEARTEXIMAGEPROC glClearTexImage;
	PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
	PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
	PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
	PFNGLBINDTEXTURESPROC glBindTextures;
	PFNGLBINDSAMPLERSPROC glBindSamplers;
	PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
	PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;
	PFNGLCLIPCONTROLPROC glClipControl;
	PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
	PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
	PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
	PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
	PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
	PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
	PFNGLCREATEBUFFERSPROC glCreateBuffers;
	PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
	PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
	PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
	PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
	PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
	PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
	PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
	PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
	PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
	PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
	PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
	PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
	PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
	PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
	PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
	PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
	PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
	PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
	PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
	PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
	PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
	PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
	PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
	PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
	PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
	PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
	PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
	PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
	PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
	PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
	PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
	PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
	PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
	PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
	PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
	PFNGLCREATETEXTURESPROC glCreateTextures;
	PFNGLTEXTUREBUFFERPROC glTextureBuffer;
	PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
	PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
	PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
	PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
	PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
	PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
	PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
	PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
	PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
	PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
	PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
	PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
	PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
	PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
	PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
	PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
	PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
	PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
	PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
	PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
	PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
	PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
	PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
	PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
	PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
	PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
	PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
	PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
	PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
	PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
	PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
	PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
	PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
	PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
	PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
	PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
	PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
	PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
	PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
	PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
	PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
	PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
	PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
	PFNGLCREATESAMPLERSPROC glCreateSamplers;
	PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
	PFNGLCREATEQUERIESPROC glCreateQueries;
	PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
	PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
	PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
	PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
	PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
	PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
	PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
	PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
	PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
	PFNGLGETNTEXIMAGEPROC glGetnTexImage;
	PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
	PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
	PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
	PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
	PFNGLREADNPIXELSPROC glReadnPixels;
	PFNGLGETNMAPDVPROC glGetnMapdv;
	PFNGLGETNMAPFVPROC glGetnMapfv;
	PFNGLGETNMAPIVPROC glGetnMapiv;
	PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
	PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
	PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
	PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
	PFNGLGETNCOLORTABLEPROC glGetnColorTable;
	PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
	PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
	PFNGLGETNHISTOGRAMPROC glGetnHistogram;
	PFNGLGETNMINMAXPROC glGetnMinmax;
	PFNGLTEXTUREBARRIERPROC glTextureBarrier;
	PFNGLSPECIALIZESHADERPROC glSpecializeShader;
	PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
	PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
	PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;
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
# if defined (GL_VERSION_1_0) /* {{{ */

extern PFNGLCULLFACEPROC glCullFace;
extern PFNGLFRONTFACEPROC glFrontFace;
extern PFNGLHINTPROC glHint;
extern PFNGLLINEWIDTHPROC glLineWidth;
extern PFNGLPOINTSIZEPROC glPointSize;
extern PFNGLPOLYGONMODEPROC glPolygonMode;
extern PFNGLSCISSORPROC glScissor;
extern PFNGLTEXPARAMETERFPROC glTexParameterf;
extern PFNGLTEXPARAMETERFVPROC glTexParameterfv;
extern PFNGLTEXPARAMETERIPROC glTexParameteri;
extern PFNGLTEXPARAMETERIVPROC glTexParameteriv;
extern PFNGLTEXIMAGE1DPROC glTexImage1D;
extern PFNGLTEXIMAGE2DPROC glTexImage2D;
extern PFNGLDRAWBUFFERPROC glDrawBuffer;
extern PFNGLCLEARPROC glClear;
extern PFNGLCLEARCOLORPROC glClearColor;
extern PFNGLCLEARSTENCILPROC glClearStencil;
extern PFNGLCLEARDEPTHPROC glClearDepth;
extern PFNGLSTENCILMASKPROC glStencilMask;
extern PFNGLCOLORMASKPROC glColorMask;
extern PFNGLDEPTHMASKPROC glDepthMask;
extern PFNGLDISABLEPROC glDisable;
extern PFNGLENABLEPROC glEnable;
extern PFNGLFINISHPROC glFinish;
extern PFNGLFLUSHPROC glFlush;
extern PFNGLBLENDFUNCPROC glBlendFunc;
extern PFNGLLOGICOPPROC glLogicOp;
extern PFNGLSTENCILFUNCPROC glStencilFunc;
extern PFNGLSTENCILOPPROC glStencilOp;
extern PFNGLDEPTHFUNCPROC glDepthFunc;
extern PFNGLPIXELSTOREFPROC glPixelStoref;
extern PFNGLPIXELSTOREIPROC glPixelStorei;
extern PFNGLREADBUFFERPROC glReadBuffer;
extern PFNGLREADPIXELSPROC glReadPixels;
extern PFNGLGETBOOLEANVPROC glGetBooleanv;
extern PFNGLGETDOUBLEVPROC glGetDoublev;
extern PFNGLGETERRORPROC glGetError;
extern PFNGLGETFLOATVPROC glGetFloatv;
extern PFNGLGETINTEGERVPROC glGetIntegerv;
extern PFNGLGETSTRINGPROC glGetString;
extern PFNGLGETTEXIMAGEPROC glGetTexImage;
extern PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
extern PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
extern PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
extern PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
extern PFNGLISENABLEDPROC glIsEnabled;
extern PFNGLDEPTHRANGEPROC glDepthRange;
extern PFNGLVIEWPORTPROC glViewport;
extern PFNGLNEWLISTPROC glNewList;
extern PFNGLENDLISTPROC glEndList;
extern PFNGLCALLLISTPROC glCallList;
extern PFNGLCALLLISTSPROC glCallLists;
extern PFNGLDELETELISTSPROC glDeleteLists;
extern PFNGLGENLISTSPROC glGenLists;
extern PFNGLLISTBASEPROC glListBase;
extern PFNGLBEGINPROC glBegin;
extern PFNGLBITMAPPROC glBitmap;
extern PFNGLCOLOR3BPROC glColor3b;
extern PFNGLCOLOR3BVPROC glColor3bv;
extern PFNGLCOLOR3DPROC glColor3d;
extern PFNGLCOLOR3DVPROC glColor3dv;
extern PFNGLCOLOR3FPROC glColor3f;
extern PFNGLCOLOR3FVPROC glColor3fv;
extern PFNGLCOLOR3IPROC glColor3i;
extern PFNGLCOLOR3IVPROC glColor3iv;
extern PFNGLCOLOR3SPROC glColor3s;
extern PFNGLCOLOR3SVPROC glColor3sv;
extern PFNGLCOLOR3UBPROC glColor3ub;
extern PFNGLCOLOR3UBVPROC glColor3ubv;
extern PFNGLCOLOR3UIPROC glColor3ui;
extern PFNGLCOLOR3UIVPROC glColor3uiv;
extern PFNGLCOLOR3USPROC glColor3us;
extern PFNGLCOLOR3USVPROC glColor3usv;
extern PFNGLCOLOR4BPROC glColor4b;
extern PFNGLCOLOR4BVPROC glColor4bv;
extern PFNGLCOLOR4DPROC glColor4d;
extern PFNGLCOLOR4DVPROC glColor4dv;
extern PFNGLCOLOR4FPROC glColor4f;
extern PFNGLCOLOR4FVPROC glColor4fv;
extern PFNGLCOLOR4IPROC glColor4i;
extern PFNGLCOLOR4IVPROC glColor4iv;
extern PFNGLCOLOR4SPROC glColor4s;
extern PFNGLCOLOR4SVPROC glColor4sv;
extern PFNGLCOLOR4UBPROC glColor4ub;
extern PFNGLCOLOR4UBVPROC glColor4ubv;
extern PFNGLCOLOR4UIPROC glColor4ui;
extern PFNGLCOLOR4UIVPROC glColor4uiv;
extern PFNGLCOLOR4USPROC glColor4us;
extern PFNGLCOLOR4USVPROC glColor4usv;
extern PFNGLEDGEFLAGPROC glEdgeFlag;
extern PFNGLEDGEFLAGVPROC glEdgeFlagv;
extern PFNGLENDPROC glEnd;
extern PFNGLINDEXDPROC glIndexd;
extern PFNGLINDEXDVPROC glIndexdv;
extern PFNGLINDEXFPROC glIndexf;
extern PFNGLINDEXFVPROC glIndexfv;
extern PFNGLINDEXIPROC glIndexi;
extern PFNGLINDEXIVPROC glIndexiv;
extern PFNGLINDEXSPROC glIndexs;
extern PFNGLINDEXSVPROC glIndexsv;
extern PFNGLNORMAL3BPROC glNormal3b;
extern PFNGLNORMAL3BVPROC glNormal3bv;
extern PFNGLNORMAL3DPROC glNormal3d;
extern PFNGLNORMAL3DVPROC glNormal3dv;
extern PFNGLNORMAL3FPROC glNormal3f;
extern PFNGLNORMAL3FVPROC glNormal3fv;
extern PFNGLNORMAL3IPROC glNormal3i;
extern PFNGLNORMAL3IVPROC glNormal3iv;
extern PFNGLNORMAL3SPROC glNormal3s;
extern PFNGLNORMAL3SVPROC glNormal3sv;
extern PFNGLRASTERPOS2DPROC glRasterPos2d;
extern PFNGLRASTERPOS2DVPROC glRasterPos2dv;
extern PFNGLRASTERPOS2FPROC glRasterPos2f;
extern PFNGLRASTERPOS2FVPROC glRasterPos2fv;
extern PFNGLRASTERPOS2IPROC glRasterPos2i;
extern PFNGLRASTERPOS2IVPROC glRasterPos2iv;
extern PFNGLRASTERPOS2SPROC glRasterPos2s;
extern PFNGLRASTERPOS2SVPROC glRasterPos2sv;
extern PFNGLRASTERPOS3DPROC glRasterPos3d;
extern PFNGLRASTERPOS3DVPROC glRasterPos3dv;
extern PFNGLRASTERPOS3FPROC glRasterPos3f;
extern PFNGLRASTERPOS3FVPROC glRasterPos3fv;
extern PFNGLRASTERPOS3IPROC glRasterPos3i;
extern PFNGLRASTERPOS3IVPROC glRasterPos3iv;
extern PFNGLRASTERPOS3SPROC glRasterPos3s;
extern PFNGLRASTERPOS3SVPROC glRasterPos3sv;
extern PFNGLRASTERPOS4DPROC glRasterPos4d;
extern PFNGLRASTERPOS4DVPROC glRasterPos4dv;
extern PFNGLRASTERPOS4FPROC glRasterPos4f;
extern PFNGLRASTERPOS4FVPROC glRasterPos4fv;
extern PFNGLRASTERPOS4IPROC glRasterPos4i;
extern PFNGLRASTERPOS4IVPROC glRasterPos4iv;
extern PFNGLRASTERPOS4SPROC glRasterPos4s;
extern PFNGLRASTERPOS4SVPROC glRasterPos4sv;
extern PFNGLRECTDPROC glRectd;
extern PFNGLRECTDVPROC glRectdv;
extern PFNGLRECTFPROC glRectf;
extern PFNGLRECTFVPROC glRectfv;
extern PFNGLRECTIPROC glRecti;
extern PFNGLRECTIVPROC glRectiv;
extern PFNGLRECTSPROC glRects;
extern PFNGLRECTSVPROC glRectsv;
extern PFNGLTEXCOORD1DPROC glTexCoord1d;
extern PFNGLTEXCOORD1DVPROC glTexCoord1dv;
extern PFNGLTEXCOORD1FPROC glTexCoord1f;
extern PFNGLTEXCOORD1FVPROC glTexCoord1fv;
extern PFNGLTEXCOORD1IPROC glTexCoord1i;
extern PFNGLTEXCOORD1IVPROC glTexCoord1iv;
extern PFNGLTEXCOORD1SPROC glTexCoord1s;
extern PFNGLTEXCOORD1SVPROC glTexCoord1sv;
extern PFNGLTEXCOORD2DPROC glTexCoord2d;
extern PFNGLTEXCOORD2DVPROC glTexCoord2dv;
extern PFNGLTEXCOORD2FPROC glTexCoord2f;
extern PFNGLTEXCOORD2FVPROC glTexCoord2fv;
extern PFNGLTEXCOORD2IPROC glTexCoord2i;
extern PFNGLTEXCOORD2IVPROC glTexCoord2iv;
extern PFNGLTEXCOORD2SPROC glTexCoord2s;
extern PFNGLTEXCOORD2SVPROC glTexCoord2sv;
extern PFNGLTEXCOORD3DPROC glTexCoord3d;
extern PFNGLTEXCOORD3DVPROC glTexCoord3dv;
extern PFNGLTEXCOORD3FPROC glTexCoord3f;
extern PFNGLTEXCOORD3FVPROC glTexCoord3fv;
extern PFNGLTEXCOORD3IPROC glTexCoord3i;
extern PFNGLTEXCOORD3IVPROC glTexCoord3iv;
extern PFNGLTEXCOORD3SPROC glTexCoord3s;
extern PFNGLTEXCOORD3SVPROC glTexCoord3sv;
extern PFNGLTEXCOORD4DPROC glTexCoord4d;
extern PFNGLTEXCOORD4DVPROC glTexCoord4dv;
extern PFNGLTEXCOORD4FPROC glTexCoord4f;
extern PFNGLTEXCOORD4FVPROC glTexCoord4fv;
extern PFNGLTEXCOORD4IPROC glTexCoord4i;
extern PFNGLTEXCOORD4IVPROC glTexCoord4iv;
extern PFNGLTEXCOORD4SPROC glTexCoord4s;
extern PFNGLTEXCOORD4SVPROC glTexCoord4sv;
extern PFNGLVERTEX2DPROC glVertex2d;
extern PFNGLVERTEX2DVPROC glVertex2dv;
extern PFNGLVERTEX2FPROC glVertex2f;
extern PFNGLVERTEX2FVPROC glVertex2fv;
extern PFNGLVERTEX2IPROC glVertex2i;
extern PFNGLVERTEX2IVPROC glVertex2iv;
extern PFNGLVERTEX2SPROC glVertex2s;
extern PFNGLVERTEX2SVPROC glVertex2sv;
extern PFNGLVERTEX3DPROC glVertex3d;
extern PFNGLVERTEX3DVPROC glVertex3dv;
extern PFNGLVERTEX3FPROC glVertex3f;
extern PFNGLVERTEX3FVPROC glVertex3fv;
extern PFNGLVERTEX3IPROC glVertex3i;
extern PFNGLVERTEX3IVPROC glVertex3iv;
extern PFNGLVERTEX3SPROC glVertex3s;
extern PFNGLVERTEX3SVPROC glVertex3sv;
extern PFNGLVERTEX4DPROC glVertex4d;
extern PFNGLVERTEX4DVPROC glVertex4dv;
extern PFNGLVERTEX4FPROC glVertex4f;
extern PFNGLVERTEX4FVPROC glVertex4fv;
extern PFNGLVERTEX4IPROC glVertex4i;
extern PFNGLVERTEX4IVPROC glVertex4iv;
extern PFNGLVERTEX4SPROC glVertex4s;
extern PFNGLVERTEX4SVPROC glVertex4sv;
extern PFNGLCLIPPLANEPROC glClipPlane;
extern PFNGLCOLORMATERIALPROC glColorMaterial;
extern PFNGLFOGFPROC glFogf;
extern PFNGLFOGFVPROC glFogfv;
extern PFNGLFOGIPROC glFogi;
extern PFNGLFOGIVPROC glFogiv;
extern PFNGLLIGHTFPROC glLightf;
extern PFNGLLIGHTFVPROC glLightfv;
extern PFNGLLIGHTIPROC glLighti;
extern PFNGLLIGHTIVPROC glLightiv;
extern PFNGLLIGHTMODELFPROC glLightModelf;
extern PFNGLLIGHTMODELFVPROC glLightModelfv;
extern PFNGLLIGHTMODELIPROC glLightModeli;
extern PFNGLLIGHTMODELIVPROC glLightModeliv;
extern PFNGLLINESTIPPLEPROC glLineStipple;
extern PFNGLMATERIALFPROC glMaterialf;
extern PFNGLMATERIALFVPROC glMaterialfv;
extern PFNGLMATERIALIPROC glMateriali;
extern PFNGLMATERIALIVPROC glMaterialiv;
extern PFNGLPOLYGONSTIPPLEPROC glPolygonStipple;
extern PFNGLSHADEMODELPROC glShadeModel;
extern PFNGLTEXENVFPROC glTexEnvf;
extern PFNGLTEXENVFVPROC glTexEnvfv;
extern PFNGLTEXENVIPROC glTexEnvi;
extern PFNGLTEXENVIVPROC glTexEnviv;
extern PFNGLTEXGENDPROC glTexGend;
extern PFNGLTEXGENDVPROC glTexGendv;
extern PFNGLTEXGENFPROC glTexGenf;
extern PFNGLTEXGENFVPROC glTexGenfv;
extern PFNGLTEXGENIPROC glTexGeni;
extern PFNGLTEXGENIVPROC glTexGeniv;
extern PFNGLFEEDBACKBUFFERPROC glFeedbackBuffer;
extern PFNGLSELECTBUFFERPROC glSelectBuffer;
extern PFNGLRENDERMODEPROC glRenderMode;
extern PFNGLINITNAMESPROC glInitNames;
extern PFNGLLOADNAMEPROC glLoadName;
extern PFNGLPASSTHROUGHPROC glPassThrough;
extern PFNGLPOPNAMEPROC glPopName;
extern PFNGLPUSHNAMEPROC glPushName;
extern PFNGLCLEARACCUMPROC glClearAccum;
extern PFNGLCLEARINDEXPROC glClearIndex;
extern PFNGLINDEXMASKPROC glIndexMask;
extern PFNGLACCUMPROC glAccum;
extern PFNGLPOPATTRIBPROC glPopAttrib;
extern PFNGLPUSHATTRIBPROC glPushAttrib;
extern PFNGLMAP1DPROC glMap1d;
extern PFNGLMAP1FPROC glMap1f;
extern PFNGLMAP2DPROC glMap2d;
extern PFNGLMAP2FPROC glMap2f;
extern PFNGLMAPGRID1DPROC glMapGrid1d;
extern PFNGLMAPGRID1FPROC glMapGrid1f;
extern PFNGLMAPGRID2DPROC glMapGrid2d;
extern PFNGLMAPGRID2FPROC glMapGrid2f;
extern PFNGLEVALCOORD1DPROC glEvalCoord1d;
extern PFNGLEVALCOORD1DVPROC glEvalCoord1dv;
extern PFNGLEVALCOORD1FPROC glEvalCoord1f;
extern PFNGLEVALCOORD1FVPROC glEvalCoord1fv;
extern PFNGLEVALCOORD2DPROC glEvalCoord2d;
extern PFNGLEVALCOORD2DVPROC glEvalCoord2dv;
extern PFNGLEVALCOORD2FPROC glEvalCoord2f;
extern PFNGLEVALCOORD2FVPROC glEvalCoord2fv;
extern PFNGLEVALMESH1PROC glEvalMesh1;
extern PFNGLEVALPOINT1PROC glEvalPoint1;
extern PFNGLEVALMESH2PROC glEvalMesh2;
extern PFNGLEVALPOINT2PROC glEvalPoint2;
extern PFNGLALPHAFUNCPROC glAlphaFunc;
extern PFNGLPIXELZOOMPROC glPixelZoom;
extern PFNGLPIXELTRANSFERFPROC glPixelTransferf;
extern PFNGLPIXELTRANSFERIPROC glPixelTransferi;
extern PFNGLPIXELMAPFVPROC glPixelMapfv;
extern PFNGLPIXELMAPUIVPROC glPixelMapuiv;
extern PFNGLPIXELMAPUSVPROC glPixelMapusv;
extern PFNGLCOPYPIXELSPROC glCopyPixels;
extern PFNGLDRAWPIXELSPROC glDrawPixels;
extern PFNGLGETCLIPPLANEPROC glGetClipPlane;
extern PFNGLGETLIGHTFVPROC glGetLightfv;
extern PFNGLGETLIGHTIVPROC glGetLightiv;
extern PFNGLGETMAPDVPROC glGetMapdv;
extern PFNGLGETMAPFVPROC glGetMapfv;
extern PFNGLGETMAPIVPROC glGetMapiv;
extern PFNGLGETMATERIALFVPROC glGetMaterialfv;
extern PFNGLGETMATERIALIVPROC glGetMaterialiv;
extern PFNGLGETPIXELMAPFVPROC glGetPixelMapfv;
extern PFNGLGETPIXELMAPUIVPROC glGetPixelMapuiv;
extern PFNGLGETPIXELMAPUSVPROC glGetPixelMapusv;
extern PFNGLGETPOLYGONSTIPPLEPROC glGetPolygonStipple;
extern PFNGLGETTEXENVFVPROC glGetTexEnvfv;
extern PFNGLGETTEXENVIVPROC glGetTexEnviv;
extern PFNGLGETTEXGENDVPROC glGetTexGendv;
extern PFNGLGETTEXGENFVPROC glGetTexGenfv;
extern PFNGLGETTEXGENIVPROC glGetTexGeniv;
extern PFNGLISLISTPROC glIsList;
extern PFNGLFRUSTUMPROC glFrustum;
extern PFNGLLOADIDENTITYPROC glLoadIdentity;
extern PFNGLLOADMATRIXFPROC glLoadMatrixf;
extern PFNGLLOADMATRIXDPROC glLoadMatrixd;
extern PFNGLMATRIXMODEPROC glMatrixMode;
extern PFNGLMULTMATRIXFPROC glMultMatrixf;
extern PFNGLMULTMATRIXDPROC glMultMatrixd;
extern PFNGLORTHOPROC glOrtho;
extern PFNGLPOPMATRIXPROC glPopMatrix;
extern PFNGLPUSHMATRIXPROC glPushMatrix;
extern PFNGLROTATEDPROC glRotated;
extern PFNGLROTATEFPROC glRotatef;
extern PFNGLSCALEDPROC glScaled;
extern PFNGLSCALEFPROC glScalef;
extern PFNGLTRANSLATEDPROC glTranslated;
extern PFNGLTRANSLATEFPROC glTranslatef;

# endif /* glTranslatef */ /* }}} */
# if defined (GL_VERSION_1_1) /* {{{ */

extern PFNGLDRAWARRAYSPROC glDrawArrays;
extern PFNGLDRAWELEMENTSPROC glDrawElements;
extern PFNGLGETPOINTERVPROC glGetPointerv;
extern PFNGLPOLYGONOFFSETPROC glPolygonOffset;
extern PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
extern PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
extern PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
extern PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
extern PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
extern PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
extern PFNGLBINDTEXTUREPROC glBindTexture;
extern PFNGLDELETETEXTURESPROC glDeleteTextures;
extern PFNGLGENTEXTURESPROC glGenTextures;
extern PFNGLISTEXTUREPROC glIsTexture;
extern PFNGLARRAYELEMENTPROC glArrayElement;
extern PFNGLCOLORPOINTERPROC glColorPointer;
extern PFNGLDISABLECLIENTSTATEPROC glDisableClientState;
extern PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer;
extern PFNGLENABLECLIENTSTATEPROC glEnableClientState;
extern PFNGLINDEXPOINTERPROC glIndexPointer;
extern PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays;
extern PFNGLNORMALPOINTERPROC glNormalPointer;
extern PFNGLTEXCOORDPOINTERPROC glTexCoordPointer;
extern PFNGLVERTEXPOINTERPROC glVertexPointer;
extern PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident;
extern PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures;
extern PFNGLINDEXUBPROC glIndexub;
extern PFNGLINDEXUBVPROC glIndexubv;
extern PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib;
extern PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib;

# endif /* glPushClientAttrib */ /* }}} */
# if defined (GL_VERSION_1_2) /* {{{ */

extern PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
extern PFNGLTEXIMAGE3DPROC glTexImage3D;
extern PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
extern PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

# endif /* glCopyTexSubImage3D */ /* }}} */
# if defined (GL_VERSION_1_3) /* {{{ */

extern PFNGLACTIVETEXTUREPROC glActiveTexture;
extern PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
extern PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
extern PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
extern PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
extern PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
extern PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;
extern PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d;
extern PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv;
extern PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f;
extern PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv;
extern PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i;
extern PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv;
extern PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s;
extern PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv;
extern PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d;
extern PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv;
extern PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f;
extern PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv;
extern PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i;
extern PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv;
extern PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s;
extern PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv;
extern PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d;
extern PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv;
extern PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f;
extern PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
extern PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i;
extern PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv;
extern PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s;
extern PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv;
extern PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d;
extern PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv;
extern PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f;
extern PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv;
extern PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i;
extern PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv;
extern PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s;
extern PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv;
extern PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf;
extern PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd;
extern PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf;
extern PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd;

# endif /* glMultTransposeMatrixd */ /* }}} */
# if defined (GL_VERSION_1_4) /* {{{ */

extern PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
extern PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
extern PFNGLPOINTPARAMETERFPROC glPointParameterf;
extern PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
extern PFNGLPOINTPARAMETERIPROC glPointParameteri;
extern PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
extern PFNGLFOGCOORDFPROC glFogCoordf;
extern PFNGLFOGCOORDFVPROC glFogCoordfv;
extern PFNGLFOGCOORDDPROC glFogCoordd;
extern PFNGLFOGCOORDDVPROC glFogCoorddv;
extern PFNGLFOGCOORDPOINTERPROC glFogCoordPointer;
extern PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b;
extern PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv;
extern PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d;
extern PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv;
extern PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f;
extern PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv;
extern PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i;
extern PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv;
extern PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s;
extern PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv;
extern PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub;
extern PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv;
extern PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui;
extern PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv;
extern PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us;
extern PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv;
extern PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer;
extern PFNGLWINDOWPOS2DPROC glWindowPos2d;
extern PFNGLWINDOWPOS2DVPROC glWindowPos2dv;
extern PFNGLWINDOWPOS2FPROC glWindowPos2f;
extern PFNGLWINDOWPOS2FVPROC glWindowPos2fv;
extern PFNGLWINDOWPOS2IPROC glWindowPos2i;
extern PFNGLWINDOWPOS2IVPROC glWindowPos2iv;
extern PFNGLWINDOWPOS2SPROC glWindowPos2s;
extern PFNGLWINDOWPOS2SVPROC glWindowPos2sv;
extern PFNGLWINDOWPOS3DPROC glWindowPos3d;
extern PFNGLWINDOWPOS3DVPROC glWindowPos3dv;
extern PFNGLWINDOWPOS3FPROC glWindowPos3f;
extern PFNGLWINDOWPOS3FVPROC glWindowPos3fv;
extern PFNGLWINDOWPOS3IPROC glWindowPos3i;
extern PFNGLWINDOWPOS3IVPROC glWindowPos3iv;
extern PFNGLWINDOWPOS3SPROC glWindowPos3s;
extern PFNGLWINDOWPOS3SVPROC glWindowPos3sv;
extern PFNGLBLENDCOLORPROC glBlendColor;
extern PFNGLBLENDEQUATIONPROC glBlendEquation;

# endif /* glBlendEquation */ /* }}} */
# if defined (GL_VERSION_1_5) /* {{{ */

extern PFNGLGENQUERIESPROC glGenQueries;
extern PFNGLDELETEQUERIESPROC glDeleteQueries;
extern PFNGLISQUERYPROC glIsQuery;
extern PFNGLBEGINQUERYPROC glBeginQuery;
extern PFNGLENDQUERYPROC glEndQuery;
extern PFNGLGETQUERYIVPROC glGetQueryiv;
extern PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
extern PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLISBUFFERPROC glIsBuffer;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLBUFFERSUBDATAPROC glBufferSubData;
extern PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
extern PFNGLMAPBUFFERPROC glMapBuffer;
extern PFNGLUNMAPBUFFERPROC glUnmapBuffer;
extern PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
extern PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

# endif /* glGetBufferPointerv */ /* }}} */
# if defined (GL_VERSION_2_0) /* {{{ */

extern PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
extern PFNGLDRAWBUFFERSPROC glDrawBuffers;
extern PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
extern PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
extern PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDETACHSHADERPROC glDetachShader;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
extern PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
extern PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETSHADERSOURCEPROC glGetShaderSource;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLGETUNIFORMFVPROC glGetUniformfv;
extern PFNGLGETUNIFORMIVPROC glGetUniformiv;
extern PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
extern PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
extern PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
extern PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
extern PFNGLISPROGRAMPROC glIsProgram;
extern PFNGLISSHADERPROC glIsShader;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLUNIFORM1FPROC glUniform1f;
extern PFNGLUNIFORM2FPROC glUniform2f;
extern PFNGLUNIFORM3FPROC glUniform3f;
extern PFNGLUNIFORM4FPROC glUniform4f;
extern PFNGLUNIFORM1IPROC glUniform1i;
extern PFNGLUNIFORM2IPROC glUniform2i;
extern PFNGLUNIFORM3IPROC glUniform3i;
extern PFNGLUNIFORM4IPROC glUniform4i;
extern PFNGLUNIFORM1FVPROC glUniform1fv;
extern PFNGLUNIFORM2FVPROC glUniform2fv;
extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;
extern PFNGLUNIFORM1IVPROC glUniform1iv;
extern PFNGLUNIFORM2IVPROC glUniform2iv;
extern PFNGLUNIFORM3IVPROC glUniform3iv;
extern PFNGLUNIFORM4IVPROC glUniform4iv;
extern PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
extern PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLVALIDATEPROGRAMPROC glValidateProgram;
extern PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
extern PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
extern PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
extern PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
extern PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
extern PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
extern PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
extern PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
extern PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
extern PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
extern PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
extern PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
extern PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
extern PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
extern PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
extern PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
extern PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
extern PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
extern PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
extern PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
extern PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
extern PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
extern PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
extern PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
extern PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
extern PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
extern PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
extern PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
extern PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
extern PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
extern PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
extern PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
extern PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
extern PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
extern PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
extern PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

# endif /* glVertexAttribPointer */ /* }}} */
# if defined (GL_VERSION_2_1) /* {{{ */

extern PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
extern PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
extern PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
extern PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
extern PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
extern PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

# endif /* glUniformMatrix4x3fv */ /* }}} */
# if defined (GL_VERSION_3_0) /* {{{ */

extern PFNGLCOLORMASKIPROC glColorMaski;
extern PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
extern PFNGLENABLEIPROC glEnablei;
extern PFNGLDISABLEIPROC glDisablei;
extern PFNGLISENABLEDIPROC glIsEnabledi;
extern PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
extern PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
extern PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
extern PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
extern PFNGLCLAMPCOLORPROC glClampColor;
extern PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
extern PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
extern PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
extern PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
extern PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
extern PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
extern PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
extern PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
extern PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
extern PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
extern PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
extern PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
extern PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
extern PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
extern PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
extern PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
extern PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
extern PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
extern PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
extern PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
extern PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
extern PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
extern PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
extern PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
extern PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
extern PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
extern PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
extern PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
extern PFNGLUNIFORM1UIPROC glUniform1ui;
extern PFNGLUNIFORM2UIPROC glUniform2ui;
extern PFNGLUNIFORM3UIPROC glUniform3ui;
extern PFNGLUNIFORM4UIPROC glUniform4ui;
extern PFNGLUNIFORM1UIVPROC glUniform1uiv;
extern PFNGLUNIFORM2UIVPROC glUniform2uiv;
extern PFNGLUNIFORM3UIVPROC glUniform3uiv;
extern PFNGLUNIFORM4UIVPROC glUniform4uiv;
extern PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
extern PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
extern PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
extern PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
extern PFNGLCLEARBUFFERIVPROC glClearBufferiv;
extern PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
extern PFNGLCLEARBUFFERFVPROC glClearBufferfv;
extern PFNGLCLEARBUFFERFIPROC glClearBufferfi;
extern PFNGLGETSTRINGIPROC glGetStringi;
extern PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
extern PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
extern PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
extern PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
extern PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
extern PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
extern PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
extern PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
extern PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
extern PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
extern PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
extern PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
extern PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
extern PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
extern PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
extern PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
extern PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
extern PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
extern PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
extern PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
extern PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLISVERTEXARRAYPROC glIsVertexArray;

# endif /* glIsVertexArray */ /* }}} */
# if defined (GL_VERSION_3_1) /* {{{ */

extern PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
extern PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
extern PFNGLTEXBUFFERPROC glTexBuffer;
extern PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
extern PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
extern PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
extern PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
extern PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
extern PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
extern PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
extern PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
extern PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;
extern PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
extern PFNGLBINDBUFFERBASEPROC glBindBufferBase;
extern PFNGLGETINTEGERI_VPROC glGetIntegeri_v;

# endif /* glGetIntegeri_v */ /* }}} */
# if defined (GL_VERSION_3_2) /* {{{ */

extern PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
extern PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
extern PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
extern PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
extern PFNGLFENCESYNCPROC glFenceSync;
extern PFNGLISSYNCPROC glIsSync;
extern PFNGLDELETESYNCPROC glDeleteSync;
extern PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
extern PFNGLWAITSYNCPROC glWaitSync;
extern PFNGLGETINTEGER64VPROC glGetInteger64v;
extern PFNGLGETSYNCIVPROC glGetSynciv;
extern PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
extern PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
extern PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
extern PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
extern PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
extern PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
extern PFNGLSAMPLEMASKIPROC glSampleMaski;

# endif /* glSampleMaski */ /* }}} */
# if defined (GL_VERSION_3_3) /* {{{ */

extern PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
extern PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
extern PFNGLGENSAMPLERSPROC glGenSamplers;
extern PFNGLDELETESAMPLERSPROC glDeleteSamplers;
extern PFNGLISSAMPLERPROC glIsSampler;
extern PFNGLBINDSAMPLERPROC glBindSampler;
extern PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
extern PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
extern PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
extern PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
extern PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
extern PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
extern PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
extern PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
extern PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
extern PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
extern PFNGLQUERYCOUNTERPROC glQueryCounter;
extern PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
extern PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
extern PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
extern PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
extern PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
extern PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
extern PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
extern PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
extern PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
extern PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
extern PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
extern PFNGLVERTEXP2UIPROC glVertexP2ui;
extern PFNGLVERTEXP2UIVPROC glVertexP2uiv;
extern PFNGLVERTEXP3UIPROC glVertexP3ui;
extern PFNGLVERTEXP3UIVPROC glVertexP3uiv;
extern PFNGLVERTEXP4UIPROC glVertexP4ui;
extern PFNGLVERTEXP4UIVPROC glVertexP4uiv;
extern PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
extern PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
extern PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
extern PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
extern PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
extern PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
extern PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
extern PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
extern PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
extern PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
extern PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
extern PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
extern PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
extern PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
extern PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
extern PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
extern PFNGLNORMALP3UIPROC glNormalP3ui;
extern PFNGLNORMALP3UIVPROC glNormalP3uiv;
extern PFNGLCOLORP3UIPROC glColorP3ui;
extern PFNGLCOLORP3UIVPROC glColorP3uiv;
extern PFNGLCOLORP4UIPROC glColorP4ui;
extern PFNGLCOLORP4UIVPROC glColorP4uiv;
extern PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
extern PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;

# endif /* glSecondaryColorP3uiv */ /* }}} */
# if defined (GL_VERSION_4_0) /* {{{ */

extern PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
extern PFNGLBLENDEQUATIONIPROC glBlendEquationi;
extern PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
extern PFNGLBLENDFUNCIPROC glBlendFunci;
extern PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
extern PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
extern PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
extern PFNGLUNIFORM1DPROC glUniform1d;
extern PFNGLUNIFORM2DPROC glUniform2d;
extern PFNGLUNIFORM3DPROC glUniform3d;
extern PFNGLUNIFORM4DPROC glUniform4d;
extern PFNGLUNIFORM1DVPROC glUniform1dv;
extern PFNGLUNIFORM2DVPROC glUniform2dv;
extern PFNGLUNIFORM3DVPROC glUniform3dv;
extern PFNGLUNIFORM4DVPROC glUniform4dv;
extern PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
extern PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
extern PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
extern PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
extern PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
extern PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
extern PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
extern PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
extern PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
extern PFNGLGETUNIFORMDVPROC glGetUniformdv;
extern PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
extern PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
extern PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
extern PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
extern PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
extern PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
extern PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
extern PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
extern PFNGLPATCHPARAMETERIPROC glPatchParameteri;
extern PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
extern PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
extern PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
extern PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
extern PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
extern PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
extern PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
extern PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
extern PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
extern PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;

# endif /* glGetQueryIndexediv */ /* }}} */
# if defined (GL_VERSION_4_1) /* {{{ */

extern PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
extern PFNGLSHADERBINARYPROC glShaderBinary;
extern PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
extern PFNGLDEPTHRANGEFPROC glDepthRangef;
extern PFNGLCLEARDEPTHFPROC glClearDepthf;
extern PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
extern PFNGLPROGRAMBINARYPROC glProgramBinary;
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
extern PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
extern PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
extern PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
extern PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
extern PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
extern PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
extern PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
extern PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
extern PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
extern PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
extern PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
extern PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
extern PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
extern PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
extern PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
extern PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
extern PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
extern PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
extern PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
extern PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
extern PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
extern PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
extern PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
extern PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
extern PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
extern PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
extern PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
extern PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
extern PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
extern PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
extern PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
extern PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
extern PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
extern PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
extern PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
extern PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
extern PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
extern PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
extern PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
extern PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
extern PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
extern PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
extern PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
extern PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
extern PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
extern PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
extern PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
extern PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
extern PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
extern PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
extern PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
extern PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
extern PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
extern PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
extern PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
extern PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
extern PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
extern PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
extern PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
extern PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
extern PFNGLSCISSORARRAYVPROC glScissorArrayv;
extern PFNGLSCISSORINDEXEDPROC glScissorIndexed;
extern PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
extern PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
extern PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
extern PFNGLGETFLOATI_VPROC glGetFloati_v;
extern PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

# endif /* glGetDoublei_v */ /* }}} */
# if defined (GL_VERSION_4_2) /* {{{ */

extern PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
extern PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
extern PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
extern PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
extern PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
extern PFNGLMEMORYBARRIERPROC glMemoryBarrier;
extern PFNGLTEXSTORAGE1DPROC glTexStorage1D;
extern PFNGLTEXSTORAGE2DPROC glTexStorage2D;
extern PFNGLTEXSTORAGE3DPROC glTexStorage3D;
extern PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
extern PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

# endif /* glDrawTransformFeedbackStreamInstanced */ /* }}} */
# if defined (GL_VERSION_4_3) /* {{{ */

extern PFNGLCLEARBUFFERDATAPROC glClearBufferData;
extern PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
extern PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
extern PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
extern PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
extern PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
extern PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
extern PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
extern PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
extern PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
extern PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
extern PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
extern PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
extern PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
extern PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
extern PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
extern PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
extern PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
extern PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
extern PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
extern PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
extern PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
extern PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
extern PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
extern PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
extern PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
extern PFNGLTEXTUREVIEWPROC glTextureView;
extern PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
extern PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
extern PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
extern PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
extern PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
extern PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
extern PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
extern PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
extern PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
extern PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
extern PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
extern PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
extern PFNGLOBJECTLABELPROC glObjectLabel;
extern PFNGLGETOBJECTLABELPROC glGetObjectLabel;
extern PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
extern PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
extern PFNGLGETPOINTERVPROC glGetPointerv;

# endif /* glGetPointerv */ /* }}} */
# if defined (GL_VERSION_4_4) /* {{{ */

extern PFNGLBUFFERSTORAGEPROC glBufferStorage;
extern PFNGLCLEARTEXIMAGEPROC glClearTexImage;
extern PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
extern PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
extern PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
extern PFNGLBINDTEXTURESPROC glBindTextures;
extern PFNGLBINDSAMPLERSPROC glBindSamplers;
extern PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
extern PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

# endif /* glBindVertexBuffers */ /* }}} */
# if defined (GL_VERSION_4_5) /* {{{ */

extern PFNGLCLIPCONTROLPROC glClipControl;
extern PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
extern PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
extern PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
extern PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
extern PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
extern PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
extern PFNGLCREATEBUFFERSPROC glCreateBuffers;
extern PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
extern PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
extern PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
extern PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
extern PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
extern PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
extern PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
extern PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
extern PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
extern PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
extern PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
extern PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
extern PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
extern PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
extern PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
extern PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
extern PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
extern PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
extern PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
extern PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
extern PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
extern PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
extern PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
extern PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
extern PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
extern PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
extern PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
extern PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
extern PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
extern PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
extern PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
extern PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
extern PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
extern PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
extern PFNGLCREATETEXTURESPROC glCreateTextures;
extern PFNGLTEXTUREBUFFERPROC glTextureBuffer;
extern PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
extern PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
extern PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
extern PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
extern PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
extern PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
extern PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
extern PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
extern PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
extern PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
extern PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
extern PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
extern PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
extern PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
extern PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
extern PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
extern PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
extern PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
extern PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
extern PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
extern PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
extern PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
extern PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
extern PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
extern PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
extern PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
extern PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
extern PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
extern PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
extern PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
extern PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
extern PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
extern PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
extern PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
extern PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
extern PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
extern PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
extern PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
extern PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
extern PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
extern PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
extern PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
extern PFNGLCREATESAMPLERSPROC glCreateSamplers;
extern PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
extern PFNGLCREATEQUERIESPROC glCreateQueries;
extern PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
extern PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
extern PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
extern PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
extern PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
extern PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
extern PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
extern PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
extern PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
extern PFNGLGETNTEXIMAGEPROC glGetnTexImage;
extern PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
extern PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
extern PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
extern PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
extern PFNGLREADNPIXELSPROC glReadnPixels;
extern PFNGLGETNMAPDVPROC glGetnMapdv;
extern PFNGLGETNMAPFVPROC glGetnMapfv;
extern PFNGLGETNMAPIVPROC glGetnMapiv;
extern PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
extern PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
extern PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
extern PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
extern PFNGLGETNCOLORTABLEPROC glGetnColorTable;
extern PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
extern PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
extern PFNGLGETNHISTOGRAMPROC glGetnHistogram;
extern PFNGLGETNMINMAXPROC glGetnMinmax;
extern PFNGLTEXTUREBARRIERPROC glTextureBarrier;

# endif /* glTextureBarrier */ /* }}} */
# if defined (GL_VERSION_4_6) /* {{{ */

extern PFNGLSPECIALIZESHADERPROC glSpecializeShader;
extern PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
extern PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
extern PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

# endif /* glPolygonOffsetClamp */ /* }}} */
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

PFNGLCULLFACEPROC glCullFace;
PFNGLFRONTFACEPROC glFrontFace;
PFNGLHINTPROC glHint;
PFNGLLINEWIDTHPROC glLineWidth;
PFNGLPOINTSIZEPROC glPointSize;
PFNGLPOLYGONMODEPROC glPolygonMode;
PFNGLSCISSORPROC glScissor;
PFNGLTEXPARAMETERFPROC glTexParameterf;
PFNGLTEXPARAMETERFVPROC glTexParameterfv;
PFNGLTEXPARAMETERIPROC glTexParameteri;
PFNGLTEXPARAMETERIVPROC glTexParameteriv;
PFNGLTEXIMAGE1DPROC glTexImage1D;
PFNGLTEXIMAGE2DPROC glTexImage2D;
PFNGLDRAWBUFFERPROC glDrawBuffer;
PFNGLCLEARPROC glClear;
PFNGLCLEARCOLORPROC glClearColor;
PFNGLCLEARSTENCILPROC glClearStencil;
PFNGLCLEARDEPTHPROC glClearDepth;
PFNGLSTENCILMASKPROC glStencilMask;
PFNGLCOLORMASKPROC glColorMask;
PFNGLDEPTHMASKPROC glDepthMask;
PFNGLDISABLEPROC glDisable;
PFNGLENABLEPROC glEnable;
PFNGLFINISHPROC glFinish;
PFNGLFLUSHPROC glFlush;
PFNGLBLENDFUNCPROC glBlendFunc;
PFNGLLOGICOPPROC glLogicOp;
PFNGLSTENCILFUNCPROC glStencilFunc;
PFNGLSTENCILOPPROC glStencilOp;
PFNGLDEPTHFUNCPROC glDepthFunc;
PFNGLPIXELSTOREFPROC glPixelStoref;
PFNGLPIXELSTOREIPROC glPixelStorei;
PFNGLREADBUFFERPROC glReadBuffer;
PFNGLREADPIXELSPROC glReadPixels;
PFNGLGETBOOLEANVPROC glGetBooleanv;
PFNGLGETDOUBLEVPROC glGetDoublev;
PFNGLGETERRORPROC glGetError;
PFNGLGETFLOATVPROC glGetFloatv;
PFNGLGETINTEGERVPROC glGetIntegerv;
PFNGLGETSTRINGPROC glGetString;
PFNGLGETTEXIMAGEPROC glGetTexImage;
PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;
PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;
PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;
PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;
PFNGLISENABLEDPROC glIsEnabled;
PFNGLDEPTHRANGEPROC glDepthRange;
PFNGLVIEWPORTPROC glViewport;
PFNGLNEWLISTPROC glNewList;
PFNGLENDLISTPROC glEndList;
PFNGLCALLLISTPROC glCallList;
PFNGLCALLLISTSPROC glCallLists;
PFNGLDELETELISTSPROC glDeleteLists;
PFNGLGENLISTSPROC glGenLists;
PFNGLLISTBASEPROC glListBase;
PFNGLBEGINPROC glBegin;
PFNGLBITMAPPROC glBitmap;
PFNGLCOLOR3BPROC glColor3b;
PFNGLCOLOR3BVPROC glColor3bv;
PFNGLCOLOR3DPROC glColor3d;
PFNGLCOLOR3DVPROC glColor3dv;
PFNGLCOLOR3FPROC glColor3f;
PFNGLCOLOR3FVPROC glColor3fv;
PFNGLCOLOR3IPROC glColor3i;
PFNGLCOLOR3IVPROC glColor3iv;
PFNGLCOLOR3SPROC glColor3s;
PFNGLCOLOR3SVPROC glColor3sv;
PFNGLCOLOR3UBPROC glColor3ub;
PFNGLCOLOR3UBVPROC glColor3ubv;
PFNGLCOLOR3UIPROC glColor3ui;
PFNGLCOLOR3UIVPROC glColor3uiv;
PFNGLCOLOR3USPROC glColor3us;
PFNGLCOLOR3USVPROC glColor3usv;
PFNGLCOLOR4BPROC glColor4b;
PFNGLCOLOR4BVPROC glColor4bv;
PFNGLCOLOR4DPROC glColor4d;
PFNGLCOLOR4DVPROC glColor4dv;
PFNGLCOLOR4FPROC glColor4f;
PFNGLCOLOR4FVPROC glColor4fv;
PFNGLCOLOR4IPROC glColor4i;
PFNGLCOLOR4IVPROC glColor4iv;
PFNGLCOLOR4SPROC glColor4s;
PFNGLCOLOR4SVPROC glColor4sv;
PFNGLCOLOR4UBPROC glColor4ub;
PFNGLCOLOR4UBVPROC glColor4ubv;
PFNGLCOLOR4UIPROC glColor4ui;
PFNGLCOLOR4UIVPROC glColor4uiv;
PFNGLCOLOR4USPROC glColor4us;
PFNGLCOLOR4USVPROC glColor4usv;
PFNGLEDGEFLAGPROC glEdgeFlag;
PFNGLEDGEFLAGVPROC glEdgeFlagv;
PFNGLENDPROC glEnd;
PFNGLINDEXDPROC glIndexd;
PFNGLINDEXDVPROC glIndexdv;
PFNGLINDEXFPROC glIndexf;
PFNGLINDEXFVPROC glIndexfv;
PFNGLINDEXIPROC glIndexi;
PFNGLINDEXIVPROC glIndexiv;
PFNGLINDEXSPROC glIndexs;
PFNGLINDEXSVPROC glIndexsv;
PFNGLNORMAL3BPROC glNormal3b;
PFNGLNORMAL3BVPROC glNormal3bv;
PFNGLNORMAL3DPROC glNormal3d;
PFNGLNORMAL3DVPROC glNormal3dv;
PFNGLNORMAL3FPROC glNormal3f;
PFNGLNORMAL3FVPROC glNormal3fv;
PFNGLNORMAL3IPROC glNormal3i;
PFNGLNORMAL3IVPROC glNormal3iv;
PFNGLNORMAL3SPROC glNormal3s;
PFNGLNORMAL3SVPROC glNormal3sv;
PFNGLRASTERPOS2DPROC glRasterPos2d;
PFNGLRASTERPOS2DVPROC glRasterPos2dv;
PFNGLRASTERPOS2FPROC glRasterPos2f;
PFNGLRASTERPOS2FVPROC glRasterPos2fv;
PFNGLRASTERPOS2IPROC glRasterPos2i;
PFNGLRASTERPOS2IVPROC glRasterPos2iv;
PFNGLRASTERPOS2SPROC glRasterPos2s;
PFNGLRASTERPOS2SVPROC glRasterPos2sv;
PFNGLRASTERPOS3DPROC glRasterPos3d;
PFNGLRASTERPOS3DVPROC glRasterPos3dv;
PFNGLRASTERPOS3FPROC glRasterPos3f;
PFNGLRASTERPOS3FVPROC glRasterPos3fv;
PFNGLRASTERPOS3IPROC glRasterPos3i;
PFNGLRASTERPOS3IVPROC glRasterPos3iv;
PFNGLRASTERPOS3SPROC glRasterPos3s;
PFNGLRASTERPOS3SVPROC glRasterPos3sv;
PFNGLRASTERPOS4DPROC glRasterPos4d;
PFNGLRASTERPOS4DVPROC glRasterPos4dv;
PFNGLRASTERPOS4FPROC glRasterPos4f;
PFNGLRASTERPOS4FVPROC glRasterPos4fv;
PFNGLRASTERPOS4IPROC glRasterPos4i;
PFNGLRASTERPOS4IVPROC glRasterPos4iv;
PFNGLRASTERPOS4SPROC glRasterPos4s;
PFNGLRASTERPOS4SVPROC glRasterPos4sv;
PFNGLRECTDPROC glRectd;
PFNGLRECTDVPROC glRectdv;
PFNGLRECTFPROC glRectf;
PFNGLRECTFVPROC glRectfv;
PFNGLRECTIPROC glRecti;
PFNGLRECTIVPROC glRectiv;
PFNGLRECTSPROC glRects;
PFNGLRECTSVPROC glRectsv;
PFNGLTEXCOORD1DPROC glTexCoord1d;
PFNGLTEXCOORD1DVPROC glTexCoord1dv;
PFNGLTEXCOORD1FPROC glTexCoord1f;
PFNGLTEXCOORD1FVPROC glTexCoord1fv;
PFNGLTEXCOORD1IPROC glTexCoord1i;
PFNGLTEXCOORD1IVPROC glTexCoord1iv;
PFNGLTEXCOORD1SPROC glTexCoord1s;
PFNGLTEXCOORD1SVPROC glTexCoord1sv;
PFNGLTEXCOORD2DPROC glTexCoord2d;
PFNGLTEXCOORD2DVPROC glTexCoord2dv;
PFNGLTEXCOORD2FPROC glTexCoord2f;
PFNGLTEXCOORD2FVPROC glTexCoord2fv;
PFNGLTEXCOORD2IPROC glTexCoord2i;
PFNGLTEXCOORD2IVPROC glTexCoord2iv;
PFNGLTEXCOORD2SPROC glTexCoord2s;
PFNGLTEXCOORD2SVPROC glTexCoord2sv;
PFNGLTEXCOORD3DPROC glTexCoord3d;
PFNGLTEXCOORD3DVPROC glTexCoord3dv;
PFNGLTEXCOORD3FPROC glTexCoord3f;
PFNGLTEXCOORD3FVPROC glTexCoord3fv;
PFNGLTEXCOORD3IPROC glTexCoord3i;
PFNGLTEXCOORD3IVPROC glTexCoord3iv;
PFNGLTEXCOORD3SPROC glTexCoord3s;
PFNGLTEXCOORD3SVPROC glTexCoord3sv;
PFNGLTEXCOORD4DPROC glTexCoord4d;
PFNGLTEXCOORD4DVPROC glTexCoord4dv;
PFNGLTEXCOORD4FPROC glTexCoord4f;
PFNGLTEXCOORD4FVPROC glTexCoord4fv;
PFNGLTEXCOORD4IPROC glTexCoord4i;
PFNGLTEXCOORD4IVPROC glTexCoord4iv;
PFNGLTEXCOORD4SPROC glTexCoord4s;
PFNGLTEXCOORD4SVPROC glTexCoord4sv;
PFNGLVERTEX2DPROC glVertex2d;
PFNGLVERTEX2DVPROC glVertex2dv;
PFNGLVERTEX2FPROC glVertex2f;
PFNGLVERTEX2FVPROC glVertex2fv;
PFNGLVERTEX2IPROC glVertex2i;
PFNGLVERTEX2IVPROC glVertex2iv;
PFNGLVERTEX2SPROC glVertex2s;
PFNGLVERTEX2SVPROC glVertex2sv;
PFNGLVERTEX3DPROC glVertex3d;
PFNGLVERTEX3DVPROC glVertex3dv;
PFNGLVERTEX3FPROC glVertex3f;
PFNGLVERTEX3FVPROC glVertex3fv;
PFNGLVERTEX3IPROC glVertex3i;
PFNGLVERTEX3IVPROC glVertex3iv;
PFNGLVERTEX3SPROC glVertex3s;
PFNGLVERTEX3SVPROC glVertex3sv;
PFNGLVERTEX4DPROC glVertex4d;
PFNGLVERTEX4DVPROC glVertex4dv;
PFNGLVERTEX4FPROC glVertex4f;
PFNGLVERTEX4FVPROC glVertex4fv;
PFNGLVERTEX4IPROC glVertex4i;
PFNGLVERTEX4IVPROC glVertex4iv;
PFNGLVERTEX4SPROC glVertex4s;
PFNGLVERTEX4SVPROC glVertex4sv;
PFNGLCLIPPLANEPROC glClipPlane;
PFNGLCOLORMATERIALPROC glColorMaterial;
PFNGLFOGFPROC glFogf;
PFNGLFOGFVPROC glFogfv;
PFNGLFOGIPROC glFogi;
PFNGLFOGIVPROC glFogiv;
PFNGLLIGHTFPROC glLightf;
PFNGLLIGHTFVPROC glLightfv;
PFNGLLIGHTIPROC glLighti;
PFNGLLIGHTIVPROC glLightiv;
PFNGLLIGHTMODELFPROC glLightModelf;
PFNGLLIGHTMODELFVPROC glLightModelfv;
PFNGLLIGHTMODELIPROC glLightModeli;
PFNGLLIGHTMODELIVPROC glLightModeliv;
PFNGLLINESTIPPLEPROC glLineStipple;
PFNGLMATERIALFPROC glMaterialf;
PFNGLMATERIALFVPROC glMaterialfv;
PFNGLMATERIALIPROC glMateriali;
PFNGLMATERIALIVPROC glMaterialiv;
PFNGLPOLYGONSTIPPLEPROC glPolygonStipple;
PFNGLSHADEMODELPROC glShadeModel;
PFNGLTEXENVFPROC glTexEnvf;
PFNGLTEXENVFVPROC glTexEnvfv;
PFNGLTEXENVIPROC glTexEnvi;
PFNGLTEXENVIVPROC glTexEnviv;
PFNGLTEXGENDPROC glTexGend;
PFNGLTEXGENDVPROC glTexGendv;
PFNGLTEXGENFPROC glTexGenf;
PFNGLTEXGENFVPROC glTexGenfv;
PFNGLTEXGENIPROC glTexGeni;
PFNGLTEXGENIVPROC glTexGeniv;
PFNGLFEEDBACKBUFFERPROC glFeedbackBuffer;
PFNGLSELECTBUFFERPROC glSelectBuffer;
PFNGLRENDERMODEPROC glRenderMode;
PFNGLINITNAMESPROC glInitNames;
PFNGLLOADNAMEPROC glLoadName;
PFNGLPASSTHROUGHPROC glPassThrough;
PFNGLPOPNAMEPROC glPopName;
PFNGLPUSHNAMEPROC glPushName;
PFNGLCLEARACCUMPROC glClearAccum;
PFNGLCLEARINDEXPROC glClearIndex;
PFNGLINDEXMASKPROC glIndexMask;
PFNGLACCUMPROC glAccum;
PFNGLPOPATTRIBPROC glPopAttrib;
PFNGLPUSHATTRIBPROC glPushAttrib;
PFNGLMAP1DPROC glMap1d;
PFNGLMAP1FPROC glMap1f;
PFNGLMAP2DPROC glMap2d;
PFNGLMAP2FPROC glMap2f;
PFNGLMAPGRID1DPROC glMapGrid1d;
PFNGLMAPGRID1FPROC glMapGrid1f;
PFNGLMAPGRID2DPROC glMapGrid2d;
PFNGLMAPGRID2FPROC glMapGrid2f;
PFNGLEVALCOORD1DPROC glEvalCoord1d;
PFNGLEVALCOORD1DVPROC glEvalCoord1dv;
PFNGLEVALCOORD1FPROC glEvalCoord1f;
PFNGLEVALCOORD1FVPROC glEvalCoord1fv;
PFNGLEVALCOORD2DPROC glEvalCoord2d;
PFNGLEVALCOORD2DVPROC glEvalCoord2dv;
PFNGLEVALCOORD2FPROC glEvalCoord2f;
PFNGLEVALCOORD2FVPROC glEvalCoord2fv;
PFNGLEVALMESH1PROC glEvalMesh1;
PFNGLEVALPOINT1PROC glEvalPoint1;
PFNGLEVALMESH2PROC glEvalMesh2;
PFNGLEVALPOINT2PROC glEvalPoint2;
PFNGLALPHAFUNCPROC glAlphaFunc;
PFNGLPIXELZOOMPROC glPixelZoom;
PFNGLPIXELTRANSFERFPROC glPixelTransferf;
PFNGLPIXELTRANSFERIPROC glPixelTransferi;
PFNGLPIXELMAPFVPROC glPixelMapfv;
PFNGLPIXELMAPUIVPROC glPixelMapuiv;
PFNGLPIXELMAPUSVPROC glPixelMapusv;
PFNGLCOPYPIXELSPROC glCopyPixels;
PFNGLDRAWPIXELSPROC glDrawPixels;
PFNGLGETCLIPPLANEPROC glGetClipPlane;
PFNGLGETLIGHTFVPROC glGetLightfv;
PFNGLGETLIGHTIVPROC glGetLightiv;
PFNGLGETMAPDVPROC glGetMapdv;
PFNGLGETMAPFVPROC glGetMapfv;
PFNGLGETMAPIVPROC glGetMapiv;
PFNGLGETMATERIALFVPROC glGetMaterialfv;
PFNGLGETMATERIALIVPROC glGetMaterialiv;
PFNGLGETPIXELMAPFVPROC glGetPixelMapfv;
PFNGLGETPIXELMAPUIVPROC glGetPixelMapuiv;
PFNGLGETPIXELMAPUSVPROC glGetPixelMapusv;
PFNGLGETPOLYGONSTIPPLEPROC glGetPolygonStipple;
PFNGLGETTEXENVFVPROC glGetTexEnvfv;
PFNGLGETTEXENVIVPROC glGetTexEnviv;
PFNGLGETTEXGENDVPROC glGetTexGendv;
PFNGLGETTEXGENFVPROC glGetTexGenfv;
PFNGLGETTEXGENIVPROC glGetTexGeniv;
PFNGLISLISTPROC glIsList;
PFNGLFRUSTUMPROC glFrustum;
PFNGLLOADIDENTITYPROC glLoadIdentity;
PFNGLLOADMATRIXFPROC glLoadMatrixf;
PFNGLLOADMATRIXDPROC glLoadMatrixd;
PFNGLMATRIXMODEPROC glMatrixMode;
PFNGLMULTMATRIXFPROC glMultMatrixf;
PFNGLMULTMATRIXDPROC glMultMatrixd;
PFNGLORTHOPROC glOrtho;
PFNGLPOPMATRIXPROC glPopMatrix;
PFNGLPUSHMATRIXPROC glPushMatrix;
PFNGLROTATEDPROC glRotated;
PFNGLROTATEFPROC glRotatef;
PFNGLSCALEDPROC glScaled;
PFNGLSCALEFPROC glScalef;
PFNGLTRANSLATEDPROC glTranslated;
PFNGLTRANSLATEFPROC glTranslatef;
PFNGLDRAWARRAYSPROC glDrawArrays;
PFNGLDRAWELEMENTSPROC glDrawElements;
PFNGLGETPOINTERVPROC glGetPointerv;
PFNGLPOLYGONOFFSETPROC glPolygonOffset;
PFNGLCOPYTEXIMAGE1DPROC glCopyTexImage1D;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D;
PFNGLCOPYTEXSUBIMAGE1DPROC glCopyTexSubImage1D;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D;
PFNGLTEXSUBIMAGE1DPROC glTexSubImage1D;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D;
PFNGLBINDTEXTUREPROC glBindTexture;
PFNGLDELETETEXTURESPROC glDeleteTextures;
PFNGLGENTEXTURESPROC glGenTextures;
PFNGLISTEXTUREPROC glIsTexture;
PFNGLARRAYELEMENTPROC glArrayElement;
PFNGLCOLORPOINTERPROC glColorPointer;
PFNGLDISABLECLIENTSTATEPROC glDisableClientState;
PFNGLEDGEFLAGPOINTERPROC glEdgeFlagPointer;
PFNGLENABLECLIENTSTATEPROC glEnableClientState;
PFNGLINDEXPOINTERPROC glIndexPointer;
PFNGLINTERLEAVEDARRAYSPROC glInterleavedArrays;
PFNGLNORMALPOINTERPROC glNormalPointer;
PFNGLTEXCOORDPOINTERPROC glTexCoordPointer;
PFNGLVERTEXPOINTERPROC glVertexPointer;
PFNGLARETEXTURESRESIDENTPROC glAreTexturesResident;
PFNGLPRIORITIZETEXTURESPROC glPrioritizeTextures;
PFNGLINDEXUBPROC glIndexub;
PFNGLINDEXUBVPROC glIndexubv;
PFNGLPOPCLIENTATTRIBPROC glPopClientAttrib;
PFNGLPUSHCLIENTATTRIBPROC glPushClientAttrib;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
PFNGLTEXIMAGE3DPROC glTexImage3D;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;
PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
PFNGLCLIENTACTIVETEXTUREPROC glClientActiveTexture;
PFNGLMULTITEXCOORD1DPROC glMultiTexCoord1d;
PFNGLMULTITEXCOORD1DVPROC glMultiTexCoord1dv;
PFNGLMULTITEXCOORD1FPROC glMultiTexCoord1f;
PFNGLMULTITEXCOORD1FVPROC glMultiTexCoord1fv;
PFNGLMULTITEXCOORD1IPROC glMultiTexCoord1i;
PFNGLMULTITEXCOORD1IVPROC glMultiTexCoord1iv;
PFNGLMULTITEXCOORD1SPROC glMultiTexCoord1s;
PFNGLMULTITEXCOORD1SVPROC glMultiTexCoord1sv;
PFNGLMULTITEXCOORD2DPROC glMultiTexCoord2d;
PFNGLMULTITEXCOORD2DVPROC glMultiTexCoord2dv;
PFNGLMULTITEXCOORD2FPROC glMultiTexCoord2f;
PFNGLMULTITEXCOORD2FVPROC glMultiTexCoord2fv;
PFNGLMULTITEXCOORD2IPROC glMultiTexCoord2i;
PFNGLMULTITEXCOORD2IVPROC glMultiTexCoord2iv;
PFNGLMULTITEXCOORD2SPROC glMultiTexCoord2s;
PFNGLMULTITEXCOORD2SVPROC glMultiTexCoord2sv;
PFNGLMULTITEXCOORD3DPROC glMultiTexCoord3d;
PFNGLMULTITEXCOORD3DVPROC glMultiTexCoord3dv;
PFNGLMULTITEXCOORD3FPROC glMultiTexCoord3f;
PFNGLMULTITEXCOORD3FVPROC glMultiTexCoord3fv;
PFNGLMULTITEXCOORD3IPROC glMultiTexCoord3i;
PFNGLMULTITEXCOORD3IVPROC glMultiTexCoord3iv;
PFNGLMULTITEXCOORD3SPROC glMultiTexCoord3s;
PFNGLMULTITEXCOORD3SVPROC glMultiTexCoord3sv;
PFNGLMULTITEXCOORD4DPROC glMultiTexCoord4d;
PFNGLMULTITEXCOORD4DVPROC glMultiTexCoord4dv;
PFNGLMULTITEXCOORD4FPROC glMultiTexCoord4f;
PFNGLMULTITEXCOORD4FVPROC glMultiTexCoord4fv;
PFNGLMULTITEXCOORD4IPROC glMultiTexCoord4i;
PFNGLMULTITEXCOORD4IVPROC glMultiTexCoord4iv;
PFNGLMULTITEXCOORD4SPROC glMultiTexCoord4s;
PFNGLMULTITEXCOORD4SVPROC glMultiTexCoord4sv;
PFNGLLOADTRANSPOSEMATRIXFPROC glLoadTransposeMatrixf;
PFNGLLOADTRANSPOSEMATRIXDPROC glLoadTransposeMatrixd;
PFNGLMULTTRANSPOSEMATRIXFPROC glMultTransposeMatrixf;
PFNGLMULTTRANSPOSEMATRIXDPROC glMultTransposeMatrixd;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
PFNGLPOINTPARAMETERFPROC glPointParameterf;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
PFNGLPOINTPARAMETERIPROC glPointParameteri;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
PFNGLFOGCOORDFPROC glFogCoordf;
PFNGLFOGCOORDFVPROC glFogCoordfv;
PFNGLFOGCOORDDPROC glFogCoordd;
PFNGLFOGCOORDDVPROC glFogCoorddv;
PFNGLFOGCOORDPOINTERPROC glFogCoordPointer;
PFNGLSECONDARYCOLOR3BPROC glSecondaryColor3b;
PFNGLSECONDARYCOLOR3BVPROC glSecondaryColor3bv;
PFNGLSECONDARYCOLOR3DPROC glSecondaryColor3d;
PFNGLSECONDARYCOLOR3DVPROC glSecondaryColor3dv;
PFNGLSECONDARYCOLOR3FPROC glSecondaryColor3f;
PFNGLSECONDARYCOLOR3FVPROC glSecondaryColor3fv;
PFNGLSECONDARYCOLOR3IPROC glSecondaryColor3i;
PFNGLSECONDARYCOLOR3IVPROC glSecondaryColor3iv;
PFNGLSECONDARYCOLOR3SPROC glSecondaryColor3s;
PFNGLSECONDARYCOLOR3SVPROC glSecondaryColor3sv;
PFNGLSECONDARYCOLOR3UBPROC glSecondaryColor3ub;
PFNGLSECONDARYCOLOR3UBVPROC glSecondaryColor3ubv;
PFNGLSECONDARYCOLOR3UIPROC glSecondaryColor3ui;
PFNGLSECONDARYCOLOR3UIVPROC glSecondaryColor3uiv;
PFNGLSECONDARYCOLOR3USPROC glSecondaryColor3us;
PFNGLSECONDARYCOLOR3USVPROC glSecondaryColor3usv;
PFNGLSECONDARYCOLORPOINTERPROC glSecondaryColorPointer;
PFNGLWINDOWPOS2DPROC glWindowPos2d;
PFNGLWINDOWPOS2DVPROC glWindowPos2dv;
PFNGLWINDOWPOS2FPROC glWindowPos2f;
PFNGLWINDOWPOS2FVPROC glWindowPos2fv;
PFNGLWINDOWPOS2IPROC glWindowPos2i;
PFNGLWINDOWPOS2IVPROC glWindowPos2iv;
PFNGLWINDOWPOS2SPROC glWindowPos2s;
PFNGLWINDOWPOS2SVPROC glWindowPos2sv;
PFNGLWINDOWPOS3DPROC glWindowPos3d;
PFNGLWINDOWPOS3DVPROC glWindowPos3dv;
PFNGLWINDOWPOS3FPROC glWindowPos3f;
PFNGLWINDOWPOS3FVPROC glWindowPos3fv;
PFNGLWINDOWPOS3IPROC glWindowPos3i;
PFNGLWINDOWPOS3IVPROC glWindowPos3iv;
PFNGLWINDOWPOS3SPROC glWindowPos3s;
PFNGLWINDOWPOS3SVPROC glWindowPos3sv;
PFNGLBLENDCOLORPROC glBlendColor;
PFNGLBLENDEQUATIONPROC glBlendEquation;
PFNGLGENQUERIESPROC glGenQueries;
PFNGLDELETEQUERIESPROC glDeleteQueries;
PFNGLISQUERYPROC glIsQuery;
PFNGLBEGINQUERYPROC glBeginQuery;
PFNGLENDQUERYPROC glEndQuery;
PFNGLGETQUERYIVPROC glGetQueryiv;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLISBUFFERPROC glIsBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLBUFFERSUBDATAPROC glBufferSubData;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
PFNGLMAPBUFFERPROC glMapBuffer;
PFNGLUNMAPBUFFERPROC glUnmapBuffer;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
PFNGLDRAWBUFFERSPROC glDrawBuffers;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLDETACHSHADERPROC glDetachShader;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERSOURCEPROC glGetShaderSource;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLGETUNIFORMFVPROC glGetUniformfv;
PFNGLGETUNIFORMIVPROC glGetUniformiv;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
PFNGLISPROGRAMPROC glIsProgram;
PFNGLISSHADERPROC glIsShader;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLUNIFORM1FPROC glUniform1f;
PFNGLUNIFORM2FPROC glUniform2f;
PFNGLUNIFORM3FPROC glUniform3f;
PFNGLUNIFORM4FPROC glUniform4f;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORM2IPROC glUniform2i;
PFNGLUNIFORM3IPROC glUniform3i;
PFNGLUNIFORM4IPROC glUniform4i;
PFNGLUNIFORM1FVPROC glUniform1fv;
PFNGLUNIFORM2FVPROC glUniform2fv;
PFNGLUNIFORM3FVPROC glUniform3fv;
PFNGLUNIFORM4FVPROC glUniform4fv;
PFNGLUNIFORM1IVPROC glUniform1iv;
PFNGLUNIFORM2IVPROC glUniform2iv;
PFNGLUNIFORM3IVPROC glUniform3iv;
PFNGLUNIFORM4IVPROC glUniform4iv;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLVALIDATEPROGRAMPROC glValidateProgram;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
PFNGLCOLORMASKIPROC glColorMaski;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
PFNGLENABLEIPROC glEnablei;
PFNGLDISABLEIPROC glDisablei;
PFNGLISENABLEDIPROC glIsEnabledi;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
PFNGLBINDBUFFERBASEPROC glBindBufferBase;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
PFNGLCLAMPCOLORPROC glClampColor;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
PFNGLUNIFORM1UIPROC glUniform1ui;
PFNGLUNIFORM2UIPROC glUniform2ui;
PFNGLUNIFORM3UIPROC glUniform3ui;
PFNGLUNIFORM4UIPROC glUniform4ui;
PFNGLUNIFORM1UIVPROC glUniform1uiv;
PFNGLUNIFORM2UIVPROC glUniform2uiv;
PFNGLUNIFORM3UIVPROC glUniform3uiv;
PFNGLUNIFORM4UIVPROC glUniform4uiv;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
PFNGLCLEARBUFFERIVPROC glClearBufferiv;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
PFNGLCLEARBUFFERFVPROC glClearBufferfv;
PFNGLCLEARBUFFERFIPROC glClearBufferfi;
PFNGLGETSTRINGIPROC glGetStringi;
PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLISVERTEXARRAYPROC glIsVertexArray;
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
PFNGLTEXBUFFERPROC glTexBuffer;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
PFNGLFENCESYNCPROC glFenceSync;
PFNGLISSYNCPROC glIsSync;
PFNGLDELETESYNCPROC glDeleteSync;
PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
PFNGLWAITSYNCPROC glWaitSync;
PFNGLGETINTEGER64VPROC glGetInteger64v;
PFNGLGETSYNCIVPROC glGetSynciv;
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
PFNGLSAMPLEMASKIPROC glSampleMaski;
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
PFNGLGENSAMPLERSPROC glGenSamplers;
PFNGLDELETESAMPLERSPROC glDeleteSamplers;
PFNGLISSAMPLERPROC glIsSampler;
PFNGLBINDSAMPLERPROC glBindSampler;
PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
PFNGLQUERYCOUNTERPROC glQueryCounter;
PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
PFNGLVERTEXP2UIPROC glVertexP2ui;
PFNGLVERTEXP2UIVPROC glVertexP2uiv;
PFNGLVERTEXP3UIPROC glVertexP3ui;
PFNGLVERTEXP3UIVPROC glVertexP3uiv;
PFNGLVERTEXP4UIPROC glVertexP4ui;
PFNGLVERTEXP4UIVPROC glVertexP4uiv;
PFNGLTEXCOORDP1UIPROC glTexCoordP1ui;
PFNGLTEXCOORDP1UIVPROC glTexCoordP1uiv;
PFNGLTEXCOORDP2UIPROC glTexCoordP2ui;
PFNGLTEXCOORDP2UIVPROC glTexCoordP2uiv;
PFNGLTEXCOORDP3UIPROC glTexCoordP3ui;
PFNGLTEXCOORDP3UIVPROC glTexCoordP3uiv;
PFNGLTEXCOORDP4UIPROC glTexCoordP4ui;
PFNGLTEXCOORDP4UIVPROC glTexCoordP4uiv;
PFNGLMULTITEXCOORDP1UIPROC glMultiTexCoordP1ui;
PFNGLMULTITEXCOORDP1UIVPROC glMultiTexCoordP1uiv;
PFNGLMULTITEXCOORDP2UIPROC glMultiTexCoordP2ui;
PFNGLMULTITEXCOORDP2UIVPROC glMultiTexCoordP2uiv;
PFNGLMULTITEXCOORDP3UIPROC glMultiTexCoordP3ui;
PFNGLMULTITEXCOORDP3UIVPROC glMultiTexCoordP3uiv;
PFNGLMULTITEXCOORDP4UIPROC glMultiTexCoordP4ui;
PFNGLMULTITEXCOORDP4UIVPROC glMultiTexCoordP4uiv;
PFNGLNORMALP3UIPROC glNormalP3ui;
PFNGLNORMALP3UIVPROC glNormalP3uiv;
PFNGLCOLORP3UIPROC glColorP3ui;
PFNGLCOLORP3UIVPROC glColorP3uiv;
PFNGLCOLORP4UIPROC glColorP4ui;
PFNGLCOLORP4UIVPROC glColorP4uiv;
PFNGLSECONDARYCOLORP3UIPROC glSecondaryColorP3ui;
PFNGLSECONDARYCOLORP3UIVPROC glSecondaryColorP3uiv;
PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
PFNGLBLENDEQUATIONIPROC glBlendEquationi;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
PFNGLBLENDFUNCIPROC glBlendFunci;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
PFNGLUNIFORM1DPROC glUniform1d;
PFNGLUNIFORM2DPROC glUniform2d;
PFNGLUNIFORM3DPROC glUniform3d;
PFNGLUNIFORM4DPROC glUniform4d;
PFNGLUNIFORM1DVPROC glUniform1dv;
PFNGLUNIFORM2DVPROC glUniform2dv;
PFNGLUNIFORM3DVPROC glUniform3dv;
PFNGLUNIFORM4DVPROC glUniform4dv;
PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
PFNGLGETUNIFORMDVPROC glGetUniformdv;
PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
PFNGLPATCHPARAMETERIPROC glPatchParameteri;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;
PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
PFNGLSHADERBINARYPROC glShaderBinary;
PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
PFNGLDEPTHRANGEFPROC glDepthRangef;
PFNGLCLEARDEPTHFPROC glClearDepthf;
PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
PFNGLPROGRAMBINARYPROC glProgramBinary;
PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
PFNGLSCISSORARRAYVPROC glScissorArrayv;
PFNGLSCISSORINDEXEDPROC glScissorIndexed;
PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
PFNGLGETFLOATI_VPROC glGetFloati_v;
PFNGLGETDOUBLEI_VPROC glGetDoublei_v;
PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
PFNGLMEMORYBARRIERPROC glMemoryBarrier;
PFNGLTEXSTORAGE1DPROC glTexStorage1D;
PFNGLTEXSTORAGE2DPROC glTexStorage2D;
PFNGLTEXSTORAGE3DPROC glTexStorage3D;
PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;
PFNGLCLEARBUFFERDATAPROC glClearBufferData;
PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
PFNGLTEXTUREVIEWPROC glTextureView;
PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
PFNGLOBJECTLABELPROC glObjectLabel;
PFNGLGETOBJECTLABELPROC glGetObjectLabel;
PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
PFNGLBUFFERSTORAGEPROC glBufferStorage;
PFNGLCLEARTEXIMAGEPROC glClearTexImage;
PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
PFNGLBINDTEXTURESPROC glBindTextures;
PFNGLBINDSAMPLERSPROC glBindSamplers;
PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;
PFNGLCLIPCONTROLPROC glClipControl;
PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
PFNGLCREATEBUFFERSPROC glCreateBuffers;
PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
PFNGLCREATETEXTURESPROC glCreateTextures;
PFNGLTEXTUREBUFFERPROC glTextureBuffer;
PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
PFNGLCREATESAMPLERSPROC glCreateSamplers;
PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
PFNGLCREATEQUERIESPROC glCreateQueries;
PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
PFNGLGETNTEXIMAGEPROC glGetnTexImage;
PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
PFNGLREADNPIXELSPROC glReadnPixels;
PFNGLGETNMAPDVPROC glGetnMapdv;
PFNGLGETNMAPFVPROC glGetnMapfv;
PFNGLGETNMAPIVPROC glGetnMapiv;
PFNGLGETNPIXELMAPFVPROC glGetnPixelMapfv;
PFNGLGETNPIXELMAPUIVPROC glGetnPixelMapuiv;
PFNGLGETNPIXELMAPUSVPROC glGetnPixelMapusv;
PFNGLGETNPOLYGONSTIPPLEPROC glGetnPolygonStipple;
PFNGLGETNCOLORTABLEPROC glGetnColorTable;
PFNGLGETNCONVOLUTIONFILTERPROC glGetnConvolutionFilter;
PFNGLGETNSEPARABLEFILTERPROC glGetnSeparableFilter;
PFNGLGETNHISTOGRAMPROC glGetnHistogram;
PFNGLGETNMINMAXPROC glGetnMinmax;
PFNGLTEXTUREBARRIERPROC glTextureBarrier;
PFNGLSPECIALIZESHADERPROC glSpecializeShader;
PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;

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
	pApi->glCullFace = (PFNGLCULLFACEPROC) pLoad("glCullFace");
	pApi->glFrontFace = (PFNGLFRONTFACEPROC) pLoad("glFrontFace");
	pApi->glHint = (PFNGLHINTPROC) pLoad("glHint");
	pApi->glLineWidth = (PFNGLLINEWIDTHPROC) pLoad("glLineWidth");
	pApi->glPointSize = (PFNGLPOINTSIZEPROC) pLoad("glPointSize");
	pApi->glPolygonMode = (PFNGLPOLYGONMODEPROC) pLoad("glPolygonMode");
	pApi->glScissor = (PFNGLSCISSORPROC) pLoad("glScissor");
	pApi->glTexParameterf = (PFNGLTEXPARAMETERFPROC) pLoad("glTexParameterf");
	pApi->glTexParameterfv = (PFNGLTEXPARAMETERFVPROC) pLoad("glTexParameterfv");
	pApi->glTexParameteri = (PFNGLTEXPARAMETERIPROC) pLoad("glTexParameteri");
	pApi->glTexParameteriv = (PFNGLTEXPARAMETERIVPROC) pLoad("glTexParameteriv");
	pApi->glTexImage1D = (PFNGLTEXIMAGE1DPROC) pLoad("glTexImage1D");
	pApi->glTexImage2D = (PFNGLTEXIMAGE2DPROC) pLoad("glTexImage2D");
	pApi->glDrawBuffer = (PFNGLDRAWBUFFERPROC) pLoad("glDrawBuffer");
	pApi->glClear = (PFNGLCLEARPROC) pLoad("glClear");
	pApi->glClearColor = (PFNGLCLEARCOLORPROC) pLoad("glClearColor");
	pApi->glClearStencil = (PFNGLCLEARSTENCILPROC) pLoad("glClearStencil");
	pApi->glClearDepth = (PFNGLCLEARDEPTHPROC) pLoad("glClearDepth");
	pApi->glStencilMask = (PFNGLSTENCILMASKPROC) pLoad("glStencilMask");
	pApi->glColorMask = (PFNGLCOLORMASKPROC) pLoad("glColorMask");
	pApi->glDepthMask = (PFNGLDEPTHMASKPROC) pLoad("glDepthMask");
	pApi->glDisable = (PFNGLDISABLEPROC) pLoad("glDisable");
	pApi->glEnable = (PFNGLENABLEPROC) pLoad("glEnable");
	pApi->glFinish = (PFNGLFINISHPROC) pLoad("glFinish");
	pApi->glFlush = (PFNGLFLUSHPROC) pLoad("glFlush");
	pApi->glBlendFunc = (PFNGLBLENDFUNCPROC) pLoad("glBlendFunc");
	pApi->glLogicOp = (PFNGLLOGICOPPROC) pLoad("glLogicOp");
	pApi->glStencilFunc = (PFNGLSTENCILFUNCPROC) pLoad("glStencilFunc");
	pApi->glStencilOp = (PFNGLSTENCILOPPROC) pLoad("glStencilOp");
	pApi->glDepthFunc = (PFNGLDEPTHFUNCPROC) pLoad("glDepthFunc");
	pApi->glPixelStoref = (PFNGLPIXELSTOREFPROC) pLoad("glPixelStoref");
	pApi->glPixelStorei = (PFNGLPIXELSTOREIPROC) pLoad("glPixelStorei");
	pApi->glReadBuffer = (PFNGLREADBUFFERPROC) pLoad("glReadBuffer");
	pApi->glReadPixels = (PFNGLREADPIXELSPROC) pLoad("glReadPixels");
	pApi->glGetBooleanv = (PFNGLGETBOOLEANVPROC) pLoad("glGetBooleanv");
	pApi->glGetDoublev = (PFNGLGETDOUBLEVPROC) pLoad("glGetDoublev");
	pApi->glGetError = (PFNGLGETERRORPROC) pLoad("glGetError");
	pApi->glGetFloatv = (PFNGLGETFLOATVPROC) pLoad("glGetFloatv");
	pApi->glGetIntegerv = (PFNGLGETINTEGERVPROC) pLoad("glGetIntegerv");
	pApi->glGetString = (PFNGLGETSTRINGPROC) pLoad("glGetString");
	pApi->glGetTexImage = (PFNGLGETTEXIMAGEPROC) pLoad("glGetTexImage");
	pApi->glGetTexParameterfv = (PFNGLGETTEXPARAMETERFVPROC) pLoad("glGetTexParameterfv");
	pApi->glGetTexParameteriv = (PFNGLGETTEXPARAMETERIVPROC) pLoad("glGetTexParameteriv");
	pApi->glGetTexLevelParameterfv = (PFNGLGETTEXLEVELPARAMETERFVPROC) pLoad("glGetTexLevelParameterfv");
	pApi->glGetTexLevelParameteriv = (PFNGLGETTEXLEVELPARAMETERIVPROC) pLoad("glGetTexLevelParameteriv");
	pApi->glIsEnabled = (PFNGLISENABLEDPROC) pLoad("glIsEnabled");
	pApi->glDepthRange = (PFNGLDEPTHRANGEPROC) pLoad("glDepthRange");
	pApi->glViewport = (PFNGLVIEWPORTPROC) pLoad("glViewport");
	pApi->glNewList = (PFNGLNEWLISTPROC) pLoad("glNewList");
	pApi->glEndList = (PFNGLENDLISTPROC) pLoad("glEndList");
	pApi->glCallList = (PFNGLCALLLISTPROC) pLoad("glCallList");
	pApi->glCallLists = (PFNGLCALLLISTSPROC) pLoad("glCallLists");
	pApi->glDeleteLists = (PFNGLDELETELISTSPROC) pLoad("glDeleteLists");
	pApi->glGenLists = (PFNGLGENLISTSPROC) pLoad("glGenLists");
	pApi->glListBase = (PFNGLLISTBASEPROC) pLoad("glListBase");
	pApi->glBegin = (PFNGLBEGINPROC) pLoad("glBegin");
	pApi->glBitmap = (PFNGLBITMAPPROC) pLoad("glBitmap");
	pApi->glColor3b = (PFNGLCOLOR3BPROC) pLoad("glColor3b");
	pApi->glColor3bv = (PFNGLCOLOR3BVPROC) pLoad("glColor3bv");
	pApi->glColor3d = (PFNGLCOLOR3DPROC) pLoad("glColor3d");
	pApi->glColor3dv = (PFNGLCOLOR3DVPROC) pLoad("glColor3dv");
	pApi->glColor3f = (PFNGLCOLOR3FPROC) pLoad("glColor3f");
	pApi->glColor3fv = (PFNGLCOLOR3FVPROC) pLoad("glColor3fv");
	pApi->glColor3i = (PFNGLCOLOR3IPROC) pLoad("glColor3i");
	pApi->glColor3iv = (PFNGLCOLOR3IVPROC) pLoad("glColor3iv");
	pApi->glColor3s = (PFNGLCOLOR3SPROC) pLoad("glColor3s");
	pApi->glColor3sv = (PFNGLCOLOR3SVPROC) pLoad("glColor3sv");
	pApi->glColor3ub = (PFNGLCOLOR3UBPROC) pLoad("glColor3ub");
	pApi->glColor3ubv = (PFNGLCOLOR3UBVPROC) pLoad("glColor3ubv");
	pApi->glColor3ui = (PFNGLCOLOR3UIPROC) pLoad("glColor3ui");
	pApi->glColor3uiv = (PFNGLCOLOR3UIVPROC) pLoad("glColor3uiv");
	pApi->glColor3us = (PFNGLCOLOR3USPROC) pLoad("glColor3us");
	pApi->glColor3usv = (PFNGLCOLOR3USVPROC) pLoad("glColor3usv");
	pApi->glColor4b = (PFNGLCOLOR4BPROC) pLoad("glColor4b");
	pApi->glColor4bv = (PFNGLCOLOR4BVPROC) pLoad("glColor4bv");
	pApi->glColor4d = (PFNGLCOLOR4DPROC) pLoad("glColor4d");
	pApi->glColor4dv = (PFNGLCOLOR4DVPROC) pLoad("glColor4dv");
	pApi->glColor4f = (PFNGLCOLOR4FPROC) pLoad("glColor4f");
	pApi->glColor4fv = (PFNGLCOLOR4FVPROC) pLoad("glColor4fv");
	pApi->glColor4i = (PFNGLCOLOR4IPROC) pLoad("glColor4i");
	pApi->glColor4iv = (PFNGLCOLOR4IVPROC) pLoad("glColor4iv");
	pApi->glColor4s = (PFNGLCOLOR4SPROC) pLoad("glColor4s");
	pApi->glColor4sv = (PFNGLCOLOR4SVPROC) pLoad("glColor4sv");
	pApi->glColor4ub = (PFNGLCOLOR4UBPROC) pLoad("glColor4ub");
	pApi->glColor4ubv = (PFNGLCOLOR4UBVPROC) pLoad("glColor4ubv");
	pApi->glColor4ui = (PFNGLCOLOR4UIPROC) pLoad("glColor4ui");
	pApi->glColor4uiv = (PFNGLCOLOR4UIVPROC) pLoad("glColor4uiv");
	pApi->glColor4us = (PFNGLCOLOR4USPROC) pLoad("glColor4us");
	pApi->glColor4usv = (PFNGLCOLOR4USVPROC) pLoad("glColor4usv");
	pApi->glEdgeFlag = (PFNGLEDGEFLAGPROC) pLoad("glEdgeFlag");
	pApi->glEdgeFlagv = (PFNGLEDGEFLAGVPROC) pLoad("glEdgeFlagv");
	pApi->glEnd = (PFNGLENDPROC) pLoad("glEnd");
	pApi->glIndexd = (PFNGLINDEXDPROC) pLoad("glIndexd");
	pApi->glIndexdv = (PFNGLINDEXDVPROC) pLoad("glIndexdv");
	pApi->glIndexf = (PFNGLINDEXFPROC) pLoad("glIndexf");
	pApi->glIndexfv = (PFNGLINDEXFVPROC) pLoad("glIndexfv");
	pApi->glIndexi = (PFNGLINDEXIPROC) pLoad("glIndexi");
	pApi->glIndexiv = (PFNGLINDEXIVPROC) pLoad("glIndexiv");
	pApi->glIndexs = (PFNGLINDEXSPROC) pLoad("glIndexs");
	pApi->glIndexsv = (PFNGLINDEXSVPROC) pLoad("glIndexsv");
	pApi->glNormal3b = (PFNGLNORMAL3BPROC) pLoad("glNormal3b");
	pApi->glNormal3bv = (PFNGLNORMAL3BVPROC) pLoad("glNormal3bv");
	pApi->glNormal3d = (PFNGLNORMAL3DPROC) pLoad("glNormal3d");
	pApi->glNormal3dv = (PFNGLNORMAL3DVPROC) pLoad("glNormal3dv");
	pApi->glNormal3f = (PFNGLNORMAL3FPROC) pLoad("glNormal3f");
	pApi->glNormal3fv = (PFNGLNORMAL3FVPROC) pLoad("glNormal3fv");
	pApi->glNormal3i = (PFNGLNORMAL3IPROC) pLoad("glNormal3i");
	pApi->glNormal3iv = (PFNGLNORMAL3IVPROC) pLoad("glNormal3iv");
	pApi->glNormal3s = (PFNGLNORMAL3SPROC) pLoad("glNormal3s");
	pApi->glNormal3sv = (PFNGLNORMAL3SVPROC) pLoad("glNormal3sv");
	pApi->glRasterPos2d = (PFNGLRASTERPOS2DPROC) pLoad("glRasterPos2d");
	pApi->glRasterPos2dv = (PFNGLRASTERPOS2DVPROC) pLoad("glRasterPos2dv");
	pApi->glRasterPos2f = (PFNGLRASTERPOS2FPROC) pLoad("glRasterPos2f");
	pApi->glRasterPos2fv = (PFNGLRASTERPOS2FVPROC) pLoad("glRasterPos2fv");
	pApi->glRasterPos2i = (PFNGLRASTERPOS2IPROC) pLoad("glRasterPos2i");
	pApi->glRasterPos2iv = (PFNGLRASTERPOS2IVPROC) pLoad("glRasterPos2iv");
	pApi->glRasterPos2s = (PFNGLRASTERPOS2SPROC) pLoad("glRasterPos2s");
	pApi->glRasterPos2sv = (PFNGLRASTERPOS2SVPROC) pLoad("glRasterPos2sv");
	pApi->glRasterPos3d = (PFNGLRASTERPOS3DPROC) pLoad("glRasterPos3d");
	pApi->glRasterPos3dv = (PFNGLRASTERPOS3DVPROC) pLoad("glRasterPos3dv");
	pApi->glRasterPos3f = (PFNGLRASTERPOS3FPROC) pLoad("glRasterPos3f");
	pApi->glRasterPos3fv = (PFNGLRASTERPOS3FVPROC) pLoad("glRasterPos3fv");
	pApi->glRasterPos3i = (PFNGLRASTERPOS3IPROC) pLoad("glRasterPos3i");
	pApi->glRasterPos3iv = (PFNGLRASTERPOS3IVPROC) pLoad("glRasterPos3iv");
	pApi->glRasterPos3s = (PFNGLRASTERPOS3SPROC) pLoad("glRasterPos3s");
	pApi->glRasterPos3sv = (PFNGLRASTERPOS3SVPROC) pLoad("glRasterPos3sv");
	pApi->glRasterPos4d = (PFNGLRASTERPOS4DPROC) pLoad("glRasterPos4d");
	pApi->glRasterPos4dv = (PFNGLRASTERPOS4DVPROC) pLoad("glRasterPos4dv");
	pApi->glRasterPos4f = (PFNGLRASTERPOS4FPROC) pLoad("glRasterPos4f");
	pApi->glRasterPos4fv = (PFNGLRASTERPOS4FVPROC) pLoad("glRasterPos4fv");
	pApi->glRasterPos4i = (PFNGLRASTERPOS4IPROC) pLoad("glRasterPos4i");
	pApi->glRasterPos4iv = (PFNGLRASTERPOS4IVPROC) pLoad("glRasterPos4iv");
	pApi->glRasterPos4s = (PFNGLRASTERPOS4SPROC) pLoad("glRasterPos4s");
	pApi->glRasterPos4sv = (PFNGLRASTERPOS4SVPROC) pLoad("glRasterPos4sv");
	pApi->glRectd = (PFNGLRECTDPROC) pLoad("glRectd");
	pApi->glRectdv = (PFNGLRECTDVPROC) pLoad("glRectdv");
	pApi->glRectf = (PFNGLRECTFPROC) pLoad("glRectf");
	pApi->glRectfv = (PFNGLRECTFVPROC) pLoad("glRectfv");
	pApi->glRecti = (PFNGLRECTIPROC) pLoad("glRecti");
	pApi->glRectiv = (PFNGLRECTIVPROC) pLoad("glRectiv");
	pApi->glRects = (PFNGLRECTSPROC) pLoad("glRects");
	pApi->glRectsv = (PFNGLRECTSVPROC) pLoad("glRectsv");
	pApi->glTexCoord1d = (PFNGLTEXCOORD1DPROC) pLoad("glTexCoord1d");
	pApi->glTexCoord1dv = (PFNGLTEXCOORD1DVPROC) pLoad("glTexCoord1dv");
	pApi->glTexCoord1f = (PFNGLTEXCOORD1FPROC) pLoad("glTexCoord1f");
	pApi->glTexCoord1fv = (PFNGLTEXCOORD1FVPROC) pLoad("glTexCoord1fv");
	pApi->glTexCoord1i = (PFNGLTEXCOORD1IPROC) pLoad("glTexCoord1i");
	pApi->glTexCoord1iv = (PFNGLTEXCOORD1IVPROC) pLoad("glTexCoord1iv");
	pApi->glTexCoord1s = (PFNGLTEXCOORD1SPROC) pLoad("glTexCoord1s");
	pApi->glTexCoord1sv = (PFNGLTEXCOORD1SVPROC) pLoad("glTexCoord1sv");
	pApi->glTexCoord2d = (PFNGLTEXCOORD2DPROC) pLoad("glTexCoord2d");
	pApi->glTexCoord2dv = (PFNGLTEXCOORD2DVPROC) pLoad("glTexCoord2dv");
	pApi->glTexCoord2f = (PFNGLTEXCOORD2FPROC) pLoad("glTexCoord2f");
	pApi->glTexCoord2fv = (PFNGLTEXCOORD2FVPROC) pLoad("glTexCoord2fv");
	pApi->glTexCoord2i = (PFNGLTEXCOORD2IPROC) pLoad("glTexCoord2i");
	pApi->glTexCoord2iv = (PFNGLTEXCOORD2IVPROC) pLoad("glTexCoord2iv");
	pApi->glTexCoord2s = (PFNGLTEXCOORD2SPROC) pLoad("glTexCoord2s");
	pApi->glTexCoord2sv = (PFNGLTEXCOORD2SVPROC) pLoad("glTexCoord2sv");
	pApi->glTexCoord3d = (PFNGLTEXCOORD3DPROC) pLoad("glTexCoord3d");
	pApi->glTexCoord3dv = (PFNGLTEXCOORD3DVPROC) pLoad("glTexCoord3dv");
	pApi->glTexCoord3f = (PFNGLTEXCOORD3FPROC) pLoad("glTexCoord3f");
	pApi->glTexCoord3fv = (PFNGLTEXCOORD3FVPROC) pLoad("glTexCoord3fv");
	pApi->glTexCoord3i = (PFNGLTEXCOORD3IPROC) pLoad("glTexCoord3i");
	pApi->glTexCoord3iv = (PFNGLTEXCOORD3IVPROC) pLoad("glTexCoord3iv");
	pApi->glTexCoord3s = (PFNGLTEXCOORD3SPROC) pLoad("glTexCoord3s");
	pApi->glTexCoord3sv = (PFNGLTEXCOORD3SVPROC) pLoad("glTexCoord3sv");
	pApi->glTexCoord4d = (PFNGLTEXCOORD4DPROC) pLoad("glTexCoord4d");
	pApi->glTexCoord4dv = (PFNGLTEXCOORD4DVPROC) pLoad("glTexCoord4dv");
	pApi->glTexCoord4f = (PFNGLTEXCOORD4FPROC) pLoad("glTexCoord4f");
	pApi->glTexCoord4fv = (PFNGLTEXCOORD4FVPROC) pLoad("glTexCoord4fv");
	pApi->glTexCoord4i = (PFNGLTEXCOORD4IPROC) pLoad("glTexCoord4i");
	pApi->glTexCoord4iv = (PFNGLTEXCOORD4IVPROC) pLoad("glTexCoord4iv");
	pApi->glTexCoord4s = (PFNGLTEXCOORD4SPROC) pLoad("glTexCoord4s");
	pApi->glTexCoord4sv = (PFNGLTEXCOORD4SVPROC) pLoad("glTexCoord4sv");
	pApi->glVertex2d = (PFNGLVERTEX2DPROC) pLoad("glVertex2d");
	pApi->glVertex2dv = (PFNGLVERTEX2DVPROC) pLoad("glVertex2dv");
	pApi->glVertex2f = (PFNGLVERTEX2FPROC) pLoad("glVertex2f");
	pApi->glVertex2fv = (PFNGLVERTEX2FVPROC) pLoad("glVertex2fv");
	pApi->glVertex2i = (PFNGLVERTEX2IPROC) pLoad("glVertex2i");
	pApi->glVertex2iv = (PFNGLVERTEX2IVPROC) pLoad("glVertex2iv");
	pApi->glVertex2s = (PFNGLVERTEX2SPROC) pLoad("glVertex2s");
	pApi->glVertex2sv = (PFNGLVERTEX2SVPROC) pLoad("glVertex2sv");
	pApi->glVertex3d = (PFNGLVERTEX3DPROC) pLoad("glVertex3d");
	pApi->glVertex3dv = (PFNGLVERTEX3DVPROC) pLoad("glVertex3dv");
	pApi->glVertex3f = (PFNGLVERTEX3FPROC) pLoad("glVertex3f");
	pApi->glVertex3fv = (PFNGLVERTEX3FVPROC) pLoad("glVertex3fv");
	pApi->glVertex3i = (PFNGLVERTEX3IPROC) pLoad("glVertex3i");
	pApi->glVertex3iv = (PFNGLVERTEX3IVPROC) pLoad("glVertex3iv");
	pApi->glVertex3s = (PFNGLVERTEX3SPROC) pLoad("glVertex3s");
	pApi->glVertex3sv = (PFNGLVERTEX3SVPROC) pLoad("glVertex3sv");
	pApi->glVertex4d = (PFNGLVERTEX4DPROC) pLoad("glVertex4d");
	pApi->glVertex4dv = (PFNGLVERTEX4DVPROC) pLoad("glVertex4dv");
	pApi->glVertex4f = (PFNGLVERTEX4FPROC) pLoad("glVertex4f");
	pApi->glVertex4fv = (PFNGLVERTEX4FVPROC) pLoad("glVertex4fv");
	pApi->glVertex4i = (PFNGLVERTEX4IPROC) pLoad("glVertex4i");
	pApi->glVertex4iv = (PFNGLVERTEX4IVPROC) pLoad("glVertex4iv");
	pApi->glVertex4s = (PFNGLVERTEX4SPROC) pLoad("glVertex4s");
	pApi->glVertex4sv = (PFNGLVERTEX4SVPROC) pLoad("glVertex4sv");
	pApi->glClipPlane = (PFNGLCLIPPLANEPROC) pLoad("glClipPlane");
	pApi->glColorMaterial = (PFNGLCOLORMATERIALPROC) pLoad("glColorMaterial");
	pApi->glFogf = (PFNGLFOGFPROC) pLoad("glFogf");
	pApi->glFogfv = (PFNGLFOGFVPROC) pLoad("glFogfv");
	pApi->glFogi = (PFNGLFOGIPROC) pLoad("glFogi");
	pApi->glFogiv = (PFNGLFOGIVPROC) pLoad("glFogiv");
	pApi->glLightf = (PFNGLLIGHTFPROC) pLoad("glLightf");
	pApi->glLightfv = (PFNGLLIGHTFVPROC) pLoad("glLightfv");
	pApi->glLighti = (PFNGLLIGHTIPROC) pLoad("glLighti");
	pApi->glLightiv = (PFNGLLIGHTIVPROC) pLoad("glLightiv");
	pApi->glLightModelf = (PFNGLLIGHTMODELFPROC) pLoad("glLightModelf");
	pApi->glLightModelfv = (PFNGLLIGHTMODELFVPROC) pLoad("glLightModelfv");
	pApi->glLightModeli = (PFNGLLIGHTMODELIPROC) pLoad("glLightModeli");
	pApi->glLightModeliv = (PFNGLLIGHTMODELIVPROC) pLoad("glLightModeliv");
	pApi->glLineStipple = (PFNGLLINESTIPPLEPROC) pLoad("glLineStipple");
	pApi->glMaterialf = (PFNGLMATERIALFPROC) pLoad("glMaterialf");
	pApi->glMaterialfv = (PFNGLMATERIALFVPROC) pLoad("glMaterialfv");
	pApi->glMateriali = (PFNGLMATERIALIPROC) pLoad("glMateriali");
	pApi->glMaterialiv = (PFNGLMATERIALIVPROC) pLoad("glMaterialiv");
	pApi->glPolygonStipple = (PFNGLPOLYGONSTIPPLEPROC) pLoad("glPolygonStipple");
	pApi->glShadeModel = (PFNGLSHADEMODELPROC) pLoad("glShadeModel");
	pApi->glTexEnvf = (PFNGLTEXENVFPROC) pLoad("glTexEnvf");
	pApi->glTexEnvfv = (PFNGLTEXENVFVPROC) pLoad("glTexEnvfv");
	pApi->glTexEnvi = (PFNGLTEXENVIPROC) pLoad("glTexEnvi");
	pApi->glTexEnviv = (PFNGLTEXENVIVPROC) pLoad("glTexEnviv");
	pApi->glTexGend = (PFNGLTEXGENDPROC) pLoad("glTexGend");
	pApi->glTexGendv = (PFNGLTEXGENDVPROC) pLoad("glTexGendv");
	pApi->glTexGenf = (PFNGLTEXGENFPROC) pLoad("glTexGenf");
	pApi->glTexGenfv = (PFNGLTEXGENFVPROC) pLoad("glTexGenfv");
	pApi->glTexGeni = (PFNGLTEXGENIPROC) pLoad("glTexGeni");
	pApi->glTexGeniv = (PFNGLTEXGENIVPROC) pLoad("glTexGeniv");
	pApi->glFeedbackBuffer = (PFNGLFEEDBACKBUFFERPROC) pLoad("glFeedbackBuffer");
	pApi->glSelectBuffer = (PFNGLSELECTBUFFERPROC) pLoad("glSelectBuffer");
	pApi->glRenderMode = (PFNGLRENDERMODEPROC) pLoad("glRenderMode");
	pApi->glInitNames = (PFNGLINITNAMESPROC) pLoad("glInitNames");
	pApi->glLoadName = (PFNGLLOADNAMEPROC) pLoad("glLoadName");
	pApi->glPassThrough = (PFNGLPASSTHROUGHPROC) pLoad("glPassThrough");
	pApi->glPopName = (PFNGLPOPNAMEPROC) pLoad("glPopName");
	pApi->glPushName = (PFNGLPUSHNAMEPROC) pLoad("glPushName");
	pApi->glClearAccum = (PFNGLCLEARACCUMPROC) pLoad("glClearAccum");
	pApi->glClearIndex = (PFNGLCLEARINDEXPROC) pLoad("glClearIndex");
	pApi->glIndexMask = (PFNGLINDEXMASKPROC) pLoad("glIndexMask");
	pApi->glAccum = (PFNGLACCUMPROC) pLoad("glAccum");
	pApi->glPopAttrib = (PFNGLPOPATTRIBPROC) pLoad("glPopAttrib");
	pApi->glPushAttrib = (PFNGLPUSHATTRIBPROC) pLoad("glPushAttrib");
	pApi->glMap1d = (PFNGLMAP1DPROC) pLoad("glMap1d");
	pApi->glMap1f = (PFNGLMAP1FPROC) pLoad("glMap1f");
	pApi->glMap2d = (PFNGLMAP2DPROC) pLoad("glMap2d");
	pApi->glMap2f = (PFNGLMAP2FPROC) pLoad("glMap2f");
	pApi->glMapGrid1d = (PFNGLMAPGRID1DPROC) pLoad("glMapGrid1d");
	pApi->glMapGrid1f = (PFNGLMAPGRID1FPROC) pLoad("glMapGrid1f");
	pApi->glMapGrid2d = (PFNGLMAPGRID2DPROC) pLoad("glMapGrid2d");
	pApi->glMapGrid2f = (PFNGLMAPGRID2FPROC) pLoad("glMapGrid2f");
	pApi->glEvalCoord1d = (PFNGLEVALCOORD1DPROC) pLoad("glEvalCoord1d");
	pApi->glEvalCoord1dv = (PFNGLEVALCOORD1DVPROC) pLoad("glEvalCoord1dv");
	pApi->glEvalCoord1f = (PFNGLEVALCOORD1FPROC) pLoad("glEvalCoord1f");
	pApi->glEvalCoord1fv = (PFNGLEVALCOORD1FVPROC) pLoad("glEvalCoord1fv");
	pApi->glEvalCoord2d = (PFNGLEVALCOORD2DPROC) pLoad("glEvalCoord2d");
	pApi->glEvalCoord2dv = (PFNGLEVALCOORD2DVPROC) pLoad("glEvalCoord2dv");
	pApi->glEvalCoord2f = (PFNGLEVALCOORD2FPROC) pLoad("glEvalCoord2f");
	pApi->glEvalCoord2fv = (PFNGLEVALCOORD2FVPROC) pLoad("glEvalCoord2fv");
	pApi->glEvalMesh1 = (PFNGLEVALMESH1PROC) pLoad("glEvalMesh1");
	pApi->glEvalPoint1 = (PFNGLEVALPOINT1PROC) pLoad("glEvalPoint1");
	pApi->glEvalMesh2 = (PFNGLEVALMESH2PROC) pLoad("glEvalMesh2");
	pApi->glEvalPoint2 = (PFNGLEVALPOINT2PROC) pLoad("glEvalPoint2");
	pApi->glAlphaFunc = (PFNGLALPHAFUNCPROC) pLoad("glAlphaFunc");
	pApi->glPixelZoom = (PFNGLPIXELZOOMPROC) pLoad("glPixelZoom");
	pApi->glPixelTransferf = (PFNGLPIXELTRANSFERFPROC) pLoad("glPixelTransferf");
	pApi->glPixelTransferi = (PFNGLPIXELTRANSFERIPROC) pLoad("glPixelTransferi");
	pApi->glPixelMapfv = (PFNGLPIXELMAPFVPROC) pLoad("glPixelMapfv");
	pApi->glPixelMapuiv = (PFNGLPIXELMAPUIVPROC) pLoad("glPixelMapuiv");
	pApi->glPixelMapusv = (PFNGLPIXELMAPUSVPROC) pLoad("glPixelMapusv");
	pApi->glCopyPixels = (PFNGLCOPYPIXELSPROC) pLoad("glCopyPixels");
	pApi->glDrawPixels = (PFNGLDRAWPIXELSPROC) pLoad("glDrawPixels");
	pApi->glGetClipPlane = (PFNGLGETCLIPPLANEPROC) pLoad("glGetClipPlane");
	pApi->glGetLightfv = (PFNGLGETLIGHTFVPROC) pLoad("glGetLightfv");
	pApi->glGetLightiv = (PFNGLGETLIGHTIVPROC) pLoad("glGetLightiv");
	pApi->glGetMapdv = (PFNGLGETMAPDVPROC) pLoad("glGetMapdv");
	pApi->glGetMapfv = (PFNGLGETMAPFVPROC) pLoad("glGetMapfv");
	pApi->glGetMapiv = (PFNGLGETMAPIVPROC) pLoad("glGetMapiv");
	pApi->glGetMaterialfv = (PFNGLGETMATERIALFVPROC) pLoad("glGetMaterialfv");
	pApi->glGetMaterialiv = (PFNGLGETMATERIALIVPROC) pLoad("glGetMaterialiv");
	pApi->glGetPixelMapfv = (PFNGLGETPIXELMAPFVPROC) pLoad("glGetPixelMapfv");
	pApi->glGetPixelMapuiv = (PFNGLGETPIXELMAPUIVPROC) pLoad("glGetPixelMapuiv");
	pApi->glGetPixelMapusv = (PFNGLGETPIXELMAPUSVPROC) pLoad("glGetPixelMapusv");
	pApi->glGetPolygonStipple = (PFNGLGETPOLYGONSTIPPLEPROC) pLoad("glGetPolygonStipple");
	pApi->glGetTexEnvfv = (PFNGLGETTEXENVFVPROC) pLoad("glGetTexEnvfv");
	pApi->glGetTexEnviv = (PFNGLGETTEXENVIVPROC) pLoad("glGetTexEnviv");
	pApi->glGetTexGendv = (PFNGLGETTEXGENDVPROC) pLoad("glGetTexGendv");
	pApi->glGetTexGenfv = (PFNGLGETTEXGENFVPROC) pLoad("glGetTexGenfv");
	pApi->glGetTexGeniv = (PFNGLGETTEXGENIVPROC) pLoad("glGetTexGeniv");
	pApi->glIsList = (PFNGLISLISTPROC) pLoad("glIsList");
	pApi->glFrustum = (PFNGLFRUSTUMPROC) pLoad("glFrustum");
	pApi->glLoadIdentity = (PFNGLLOADIDENTITYPROC) pLoad("glLoadIdentity");
	pApi->glLoadMatrixf = (PFNGLLOADMATRIXFPROC) pLoad("glLoadMatrixf");
	pApi->glLoadMatrixd = (PFNGLLOADMATRIXDPROC) pLoad("glLoadMatrixd");
	pApi->glMatrixMode = (PFNGLMATRIXMODEPROC) pLoad("glMatrixMode");
	pApi->glMultMatrixf = (PFNGLMULTMATRIXFPROC) pLoad("glMultMatrixf");
	pApi->glMultMatrixd = (PFNGLMULTMATRIXDPROC) pLoad("glMultMatrixd");
	pApi->glOrtho = (PFNGLORTHOPROC) pLoad("glOrtho");
	pApi->glPopMatrix = (PFNGLPOPMATRIXPROC) pLoad("glPopMatrix");
	pApi->glPushMatrix = (PFNGLPUSHMATRIXPROC) pLoad("glPushMatrix");
	pApi->glRotated = (PFNGLROTATEDPROC) pLoad("glRotated");
	pApi->glRotatef = (PFNGLROTATEFPROC) pLoad("glRotatef");
	pApi->glScaled = (PFNGLSCALEDPROC) pLoad("glScaled");
	pApi->glScalef = (PFNGLSCALEFPROC) pLoad("glScalef");
	pApi->glTranslated = (PFNGLTRANSLATEDPROC) pLoad("glTranslated");
	pApi->glTranslatef = (PFNGLTRANSLATEFPROC) pLoad("glTranslatef");
	pApi->glDrawArrays = (PFNGLDRAWARRAYSPROC) pLoad("glDrawArrays");
	pApi->glDrawElements = (PFNGLDRAWELEMENTSPROC) pLoad("glDrawElements");
	pApi->glGetPointerv = (PFNGLGETPOINTERVPROC) pLoad("glGetPointerv");
	pApi->glPolygonOffset = (PFNGLPOLYGONOFFSETPROC) pLoad("glPolygonOffset");
	pApi->glCopyTexImage1D = (PFNGLCOPYTEXIMAGE1DPROC) pLoad("glCopyTexImage1D");
	pApi->glCopyTexImage2D = (PFNGLCOPYTEXIMAGE2DPROC) pLoad("glCopyTexImage2D");
	pApi->glCopyTexSubImage1D = (PFNGLCOPYTEXSUBIMAGE1DPROC) pLoad("glCopyTexSubImage1D");
	pApi->glCopyTexSubImage2D = (PFNGLCOPYTEXSUBIMAGE2DPROC) pLoad("glCopyTexSubImage2D");
	pApi->glTexSubImage1D = (PFNGLTEXSUBIMAGE1DPROC) pLoad("glTexSubImage1D");
	pApi->glTexSubImage2D = (PFNGLTEXSUBIMAGE2DPROC) pLoad("glTexSubImage2D");
	pApi->glBindTexture = (PFNGLBINDTEXTUREPROC) pLoad("glBindTexture");
	pApi->glDeleteTextures = (PFNGLDELETETEXTURESPROC) pLoad("glDeleteTextures");
	pApi->glGenTextures = (PFNGLGENTEXTURESPROC) pLoad("glGenTextures");
	pApi->glIsTexture = (PFNGLISTEXTUREPROC) pLoad("glIsTexture");
	pApi->glArrayElement = (PFNGLARRAYELEMENTPROC) pLoad("glArrayElement");
	pApi->glColorPointer = (PFNGLCOLORPOINTERPROC) pLoad("glColorPointer");
	pApi->glDisableClientState = (PFNGLDISABLECLIENTSTATEPROC) pLoad("glDisableClientState");
	pApi->glEdgeFlagPointer = (PFNGLEDGEFLAGPOINTERPROC) pLoad("glEdgeFlagPointer");
	pApi->glEnableClientState = (PFNGLENABLECLIENTSTATEPROC) pLoad("glEnableClientState");
	pApi->glIndexPointer = (PFNGLINDEXPOINTERPROC) pLoad("glIndexPointer");
	pApi->glInterleavedArrays = (PFNGLINTERLEAVEDARRAYSPROC) pLoad("glInterleavedArrays");
	pApi->glNormalPointer = (PFNGLNORMALPOINTERPROC) pLoad("glNormalPointer");
	pApi->glTexCoordPointer = (PFNGLTEXCOORDPOINTERPROC) pLoad("glTexCoordPointer");
	pApi->glVertexPointer = (PFNGLVERTEXPOINTERPROC) pLoad("glVertexPointer");
	pApi->glAreTexturesResident = (PFNGLARETEXTURESRESIDENTPROC) pLoad("glAreTexturesResident");
	pApi->glPrioritizeTextures = (PFNGLPRIORITIZETEXTURESPROC) pLoad("glPrioritizeTextures");
	pApi->glIndexub = (PFNGLINDEXUBPROC) pLoad("glIndexub");
	pApi->glIndexubv = (PFNGLINDEXUBVPROC) pLoad("glIndexubv");
	pApi->glPopClientAttrib = (PFNGLPOPCLIENTATTRIBPROC) pLoad("glPopClientAttrib");
	pApi->glPushClientAttrib = (PFNGLPUSHCLIENTATTRIBPROC) pLoad("glPushClientAttrib");
	pApi->glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC) pLoad("glDrawRangeElements");
	pApi->glTexImage3D = (PFNGLTEXIMAGE3DPROC) pLoad("glTexImage3D");
	pApi->glTexSubImage3D = (PFNGLTEXSUBIMAGE3DPROC) pLoad("glTexSubImage3D");
	pApi->glCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3DPROC) pLoad("glCopyTexSubImage3D");
	pApi->glActiveTexture = (PFNGLACTIVETEXTUREPROC) pLoad("glActiveTexture");
	pApi->glSampleCoverage = (PFNGLSAMPLECOVERAGEPROC) pLoad("glSampleCoverage");
	pApi->glCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3DPROC) pLoad("glCompressedTexImage3D");
	pApi->glCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2DPROC) pLoad("glCompressedTexImage2D");
	pApi->glCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1DPROC) pLoad("glCompressedTexImage1D");
	pApi->glCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC) pLoad("glCompressedTexSubImage3D");
	pApi->glCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC) pLoad("glCompressedTexSubImage2D");
	pApi->glCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC) pLoad("glCompressedTexSubImage1D");
	pApi->glGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGEPROC) pLoad("glGetCompressedTexImage");
	pApi->glClientActiveTexture = (PFNGLCLIENTACTIVETEXTUREPROC) pLoad("glClientActiveTexture");
	pApi->glMultiTexCoord1d = (PFNGLMULTITEXCOORD1DPROC) pLoad("glMultiTexCoord1d");
	pApi->glMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DVPROC) pLoad("glMultiTexCoord1dv");
	pApi->glMultiTexCoord1f = (PFNGLMULTITEXCOORD1FPROC) pLoad("glMultiTexCoord1f");
	pApi->glMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FVPROC) pLoad("glMultiTexCoord1fv");
	pApi->glMultiTexCoord1i = (PFNGLMULTITEXCOORD1IPROC) pLoad("glMultiTexCoord1i");
	pApi->glMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IVPROC) pLoad("glMultiTexCoord1iv");
	pApi->glMultiTexCoord1s = (PFNGLMULTITEXCOORD1SPROC) pLoad("glMultiTexCoord1s");
	pApi->glMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SVPROC) pLoad("glMultiTexCoord1sv");
	pApi->glMultiTexCoord2d = (PFNGLMULTITEXCOORD2DPROC) pLoad("glMultiTexCoord2d");
	pApi->glMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DVPROC) pLoad("glMultiTexCoord2dv");
	pApi->glMultiTexCoord2f = (PFNGLMULTITEXCOORD2FPROC) pLoad("glMultiTexCoord2f");
	pApi->glMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FVPROC) pLoad("glMultiTexCoord2fv");
	pApi->glMultiTexCoord2i = (PFNGLMULTITEXCOORD2IPROC) pLoad("glMultiTexCoord2i");
	pApi->glMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IVPROC) pLoad("glMultiTexCoord2iv");
	pApi->glMultiTexCoord2s = (PFNGLMULTITEXCOORD2SPROC) pLoad("glMultiTexCoord2s");
	pApi->glMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SVPROC) pLoad("glMultiTexCoord2sv");
	pApi->glMultiTexCoord3d = (PFNGLMULTITEXCOORD3DPROC) pLoad("glMultiTexCoord3d");
	pApi->glMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DVPROC) pLoad("glMultiTexCoord3dv");
	pApi->glMultiTexCoord3f = (PFNGLMULTITEXCOORD3FPROC) pLoad("glMultiTexCoord3f");
	pApi->glMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FVPROC) pLoad("glMultiTexCoord3fv");
	pApi->glMultiTexCoord3i = (PFNGLMULTITEXCOORD3IPROC) pLoad("glMultiTexCoord3i");
	pApi->glMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IVPROC) pLoad("glMultiTexCoord3iv");
	pApi->glMultiTexCoord3s = (PFNGLMULTITEXCOORD3SPROC) pLoad("glMultiTexCoord3s");
	pApi->glMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SVPROC) pLoad("glMultiTexCoord3sv");
	pApi->glMultiTexCoord4d = (PFNGLMULTITEXCOORD4DPROC) pLoad("glMultiTexCoord4d");
	pApi->glMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DVPROC) pLoad("glMultiTexCoord4dv");
	pApi->glMultiTexCoord4f = (PFNGLMULTITEXCOORD4FPROC) pLoad("glMultiTexCoord4f");
	pApi->glMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FVPROC) pLoad("glMultiTexCoord4fv");
	pApi->glMultiTexCoord4i = (PFNGLMULTITEXCOORD4IPROC) pLoad("glMultiTexCoord4i");
	pApi->glMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IVPROC) pLoad("glMultiTexCoord4iv");
	pApi->glMultiTexCoord4s = (PFNGLMULTITEXCOORD4SPROC) pLoad("glMultiTexCoord4s");
	pApi->glMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SVPROC) pLoad("glMultiTexCoord4sv");
	pApi->glLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXFPROC) pLoad("glLoadTransposeMatrixf");
	pApi->glLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXDPROC) pLoad("glLoadTransposeMatrixd");
	pApi->glMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXFPROC) pLoad("glMultTransposeMatrixf");
	pApi->glMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXDPROC) pLoad("glMultTransposeMatrixd");
	pApi->glBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATEPROC) pLoad("glBlendFuncSeparate");
	pApi->glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC) pLoad("glMultiDrawArrays");
	pApi->glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC) pLoad("glMultiDrawElements");
	pApi->glPointParameterf = (PFNGLPOINTPARAMETERFPROC) pLoad("glPointParameterf");
	pApi->glPointParameterfv = (PFNGLPOINTPARAMETERFVPROC) pLoad("glPointParameterfv");
	pApi->glPointParameteri = (PFNGLPOINTPARAMETERIPROC) pLoad("glPointParameteri");
	pApi->glPointParameteriv = (PFNGLPOINTPARAMETERIVPROC) pLoad("glPointParameteriv");
	pApi->glFogCoordf = (PFNGLFOGCOORDFPROC) pLoad("glFogCoordf");
	pApi->glFogCoordfv = (PFNGLFOGCOORDFVPROC) pLoad("glFogCoordfv");
	pApi->glFogCoordd = (PFNGLFOGCOORDDPROC) pLoad("glFogCoordd");
	pApi->glFogCoorddv = (PFNGLFOGCOORDDVPROC) pLoad("glFogCoorddv");
	pApi->glFogCoordPointer = (PFNGLFOGCOORDPOINTERPROC) pLoad("glFogCoordPointer");
	pApi->glSecondaryColor3b = (PFNGLSECONDARYCOLOR3BPROC) pLoad("glSecondaryColor3b");
	pApi->glSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BVPROC) pLoad("glSecondaryColor3bv");
	pApi->glSecondaryColor3d = (PFNGLSECONDARYCOLOR3DPROC) pLoad("glSecondaryColor3d");
	pApi->glSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DVPROC) pLoad("glSecondaryColor3dv");
	pApi->glSecondaryColor3f = (PFNGLSECONDARYCOLOR3FPROC) pLoad("glSecondaryColor3f");
	pApi->glSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FVPROC) pLoad("glSecondaryColor3fv");
	pApi->glSecondaryColor3i = (PFNGLSECONDARYCOLOR3IPROC) pLoad("glSecondaryColor3i");
	pApi->glSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IVPROC) pLoad("glSecondaryColor3iv");
	pApi->glSecondaryColor3s = (PFNGLSECONDARYCOLOR3SPROC) pLoad("glSecondaryColor3s");
	pApi->glSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SVPROC) pLoad("glSecondaryColor3sv");
	pApi->glSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UBPROC) pLoad("glSecondaryColor3ub");
	pApi->glSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBVPROC) pLoad("glSecondaryColor3ubv");
	pApi->glSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UIPROC) pLoad("glSecondaryColor3ui");
	pApi->glSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIVPROC) pLoad("glSecondaryColor3uiv");
	pApi->glSecondaryColor3us = (PFNGLSECONDARYCOLOR3USPROC) pLoad("glSecondaryColor3us");
	pApi->glSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USVPROC) pLoad("glSecondaryColor3usv");
	pApi->glSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTERPROC) pLoad("glSecondaryColorPointer");
	pApi->glWindowPos2d = (PFNGLWINDOWPOS2DPROC) pLoad("glWindowPos2d");
	pApi->glWindowPos2dv = (PFNGLWINDOWPOS2DVPROC) pLoad("glWindowPos2dv");
	pApi->glWindowPos2f = (PFNGLWINDOWPOS2FPROC) pLoad("glWindowPos2f");
	pApi->glWindowPos2fv = (PFNGLWINDOWPOS2FVPROC) pLoad("glWindowPos2fv");
	pApi->glWindowPos2i = (PFNGLWINDOWPOS2IPROC) pLoad("glWindowPos2i");
	pApi->glWindowPos2iv = (PFNGLWINDOWPOS2IVPROC) pLoad("glWindowPos2iv");
	pApi->glWindowPos2s = (PFNGLWINDOWPOS2SPROC) pLoad("glWindowPos2s");
	pApi->glWindowPos2sv = (PFNGLWINDOWPOS2SVPROC) pLoad("glWindowPos2sv");
	pApi->glWindowPos3d = (PFNGLWINDOWPOS3DPROC) pLoad("glWindowPos3d");
	pApi->glWindowPos3dv = (PFNGLWINDOWPOS3DVPROC) pLoad("glWindowPos3dv");
	pApi->glWindowPos3f = (PFNGLWINDOWPOS3FPROC) pLoad("glWindowPos3f");
	pApi->glWindowPos3fv = (PFNGLWINDOWPOS3FVPROC) pLoad("glWindowPos3fv");
	pApi->glWindowPos3i = (PFNGLWINDOWPOS3IPROC) pLoad("glWindowPos3i");
	pApi->glWindowPos3iv = (PFNGLWINDOWPOS3IVPROC) pLoad("glWindowPos3iv");
	pApi->glWindowPos3s = (PFNGLWINDOWPOS3SPROC) pLoad("glWindowPos3s");
	pApi->glWindowPos3sv = (PFNGLWINDOWPOS3SVPROC) pLoad("glWindowPos3sv");
	pApi->glBlendColor = (PFNGLBLENDCOLORPROC) pLoad("glBlendColor");
	pApi->glBlendEquation = (PFNGLBLENDEQUATIONPROC) pLoad("glBlendEquation");
	pApi->glGenQueries = (PFNGLGENQUERIESPROC) pLoad("glGenQueries");
	pApi->glDeleteQueries = (PFNGLDELETEQUERIESPROC) pLoad("glDeleteQueries");
	pApi->glIsQuery = (PFNGLISQUERYPROC) pLoad("glIsQuery");
	pApi->glBeginQuery = (PFNGLBEGINQUERYPROC) pLoad("glBeginQuery");
	pApi->glEndQuery = (PFNGLENDQUERYPROC) pLoad("glEndQuery");
	pApi->glGetQueryiv = (PFNGLGETQUERYIVPROC) pLoad("glGetQueryiv");
	pApi->glGetQueryObjectiv = (PFNGLGETQUERYOBJECTIVPROC) pLoad("glGetQueryObjectiv");
	pApi->glGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIVPROC) pLoad("glGetQueryObjectuiv");
	pApi->glBindBuffer = (PFNGLBINDBUFFERPROC) pLoad("glBindBuffer");
	pApi->glDeleteBuffers = (PFNGLDELETEBUFFERSPROC) pLoad("glDeleteBuffers");
	pApi->glGenBuffers = (PFNGLGENBUFFERSPROC) pLoad("glGenBuffers");
	pApi->glIsBuffer = (PFNGLISBUFFERPROC) pLoad("glIsBuffer");
	pApi->glBufferData = (PFNGLBUFFERDATAPROC) pLoad("glBufferData");
	pApi->glBufferSubData = (PFNGLBUFFERSUBDATAPROC) pLoad("glBufferSubData");
	pApi->glGetBufferSubData = (PFNGLGETBUFFERSUBDATAPROC) pLoad("glGetBufferSubData");
	pApi->glMapBuffer = (PFNGLMAPBUFFERPROC) pLoad("glMapBuffer");
	pApi->glUnmapBuffer = (PFNGLUNMAPBUFFERPROC) pLoad("glUnmapBuffer");
	pApi->glGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIVPROC) pLoad("glGetBufferParameteriv");
	pApi->glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC) pLoad("glGetBufferPointerv");
	pApi->glBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATEPROC) pLoad("glBlendEquationSeparate");
	pApi->glDrawBuffers = (PFNGLDRAWBUFFERSPROC) pLoad("glDrawBuffers");
	pApi->glStencilOpSeparate = (PFNGLSTENCILOPSEPARATEPROC) pLoad("glStencilOpSeparate");
	pApi->glStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATEPROC) pLoad("glStencilFuncSeparate");
	pApi->glStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATEPROC) pLoad("glStencilMaskSeparate");
	pApi->glAttachShader = (PFNGLATTACHSHADERPROC) pLoad("glAttachShader");
	pApi->glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC) pLoad("glBindAttribLocation");
	pApi->glCompileShader = (PFNGLCOMPILESHADERPROC) pLoad("glCompileShader");
	pApi->glCreateProgram = (PFNGLCREATEPROGRAMPROC) pLoad("glCreateProgram");
	pApi->glCreateShader = (PFNGLCREATESHADERPROC) pLoad("glCreateShader");
	pApi->glDeleteProgram = (PFNGLDELETEPROGRAMPROC) pLoad("glDeleteProgram");
	pApi->glDeleteShader = (PFNGLDELETESHADERPROC) pLoad("glDeleteShader");
	pApi->glDetachShader = (PFNGLDETACHSHADERPROC) pLoad("glDetachShader");
	pApi->glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC) pLoad("glDisableVertexAttribArray");
	pApi->glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC) pLoad("glEnableVertexAttribArray");
	pApi->glGetActiveAttrib = (PFNGLGETACTIVEATTRIBPROC) pLoad("glGetActiveAttrib");
	pApi->glGetActiveUniform = (PFNGLGETACTIVEUNIFORMPROC) pLoad("glGetActiveUniform");
	pApi->glGetAttachedShaders = (PFNGLGETATTACHEDSHADERSPROC) pLoad("glGetAttachedShaders");
	pApi->glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC) pLoad("glGetAttribLocation");
	pApi->glGetProgramiv = (PFNGLGETPROGRAMIVPROC) pLoad("glGetProgramiv");
	pApi->glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC) pLoad("glGetProgramInfoLog");
	pApi->glGetShaderiv = (PFNGLGETSHADERIVPROC) pLoad("glGetShaderiv");
	pApi->glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC) pLoad("glGetShaderInfoLog");
	pApi->glGetShaderSource = (PFNGLGETSHADERSOURCEPROC) pLoad("glGetShaderSource");
	pApi->glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC) pLoad("glGetUniformLocation");
	pApi->glGetUniformfv = (PFNGLGETUNIFORMFVPROC) pLoad("glGetUniformfv");
	pApi->glGetUniformiv = (PFNGLGETUNIFORMIVPROC) pLoad("glGetUniformiv");
	pApi->glGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDVPROC) pLoad("glGetVertexAttribdv");
	pApi->glGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFVPROC) pLoad("glGetVertexAttribfv");
	pApi->glGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIVPROC) pLoad("glGetVertexAttribiv");
	pApi->glGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERVPROC) pLoad("glGetVertexAttribPointerv");
	pApi->glIsProgram = (PFNGLISPROGRAMPROC) pLoad("glIsProgram");
	pApi->glIsShader = (PFNGLISSHADERPROC) pLoad("glIsShader");
	pApi->glLinkProgram = (PFNGLLINKPROGRAMPROC) pLoad("glLinkProgram");
	pApi->glShaderSource = (PFNGLSHADERSOURCEPROC) pLoad("glShaderSource");
	pApi->glUseProgram = (PFNGLUSEPROGRAMPROC) pLoad("glUseProgram");
	pApi->glUniform1f = (PFNGLUNIFORM1FPROC) pLoad("glUniform1f");
	pApi->glUniform2f = (PFNGLUNIFORM2FPROC) pLoad("glUniform2f");
	pApi->glUniform3f = (PFNGLUNIFORM3FPROC) pLoad("glUniform3f");
	pApi->glUniform4f = (PFNGLUNIFORM4FPROC) pLoad("glUniform4f");
	pApi->glUniform1i = (PFNGLUNIFORM1IPROC) pLoad("glUniform1i");
	pApi->glUniform2i = (PFNGLUNIFORM2IPROC) pLoad("glUniform2i");
	pApi->glUniform3i = (PFNGLUNIFORM3IPROC) pLoad("glUniform3i");
	pApi->glUniform4i = (PFNGLUNIFORM4IPROC) pLoad("glUniform4i");
	pApi->glUniform1fv = (PFNGLUNIFORM1FVPROC) pLoad("glUniform1fv");
	pApi->glUniform2fv = (PFNGLUNIFORM2FVPROC) pLoad("glUniform2fv");
	pApi->glUniform3fv = (PFNGLUNIFORM3FVPROC) pLoad("glUniform3fv");
	pApi->glUniform4fv = (PFNGLUNIFORM4FVPROC) pLoad("glUniform4fv");
	pApi->glUniform1iv = (PFNGLUNIFORM1IVPROC) pLoad("glUniform1iv");
	pApi->glUniform2iv = (PFNGLUNIFORM2IVPROC) pLoad("glUniform2iv");
	pApi->glUniform3iv = (PFNGLUNIFORM3IVPROC) pLoad("glUniform3iv");
	pApi->glUniform4iv = (PFNGLUNIFORM4IVPROC) pLoad("glUniform4iv");
	pApi->glUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FVPROC) pLoad("glUniformMatrix2fv");
	pApi->glUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FVPROC) pLoad("glUniformMatrix3fv");
	pApi->glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC) pLoad("glUniformMatrix4fv");
	pApi->glValidateProgram = (PFNGLVALIDATEPROGRAMPROC) pLoad("glValidateProgram");
	pApi->glVertexAttrib1d = (PFNGLVERTEXATTRIB1DPROC) pLoad("glVertexAttrib1d");
	pApi->glVertexAttrib1dv = (PFNGLVERTEXATTRIB1DVPROC) pLoad("glVertexAttrib1dv");
	pApi->glVertexAttrib1f = (PFNGLVERTEXATTRIB1FPROC) pLoad("glVertexAttrib1f");
	pApi->glVertexAttrib1fv = (PFNGLVERTEXATTRIB1FVPROC) pLoad("glVertexAttrib1fv");
	pApi->glVertexAttrib1s = (PFNGLVERTEXATTRIB1SPROC) pLoad("glVertexAttrib1s");
	pApi->glVertexAttrib1sv = (PFNGLVERTEXATTRIB1SVPROC) pLoad("glVertexAttrib1sv");
	pApi->glVertexAttrib2d = (PFNGLVERTEXATTRIB2DPROC) pLoad("glVertexAttrib2d");
	pApi->glVertexAttrib2dv = (PFNGLVERTEXATTRIB2DVPROC) pLoad("glVertexAttrib2dv");
	pApi->glVertexAttrib2f = (PFNGLVERTEXATTRIB2FPROC) pLoad("glVertexAttrib2f");
	pApi->glVertexAttrib2fv = (PFNGLVERTEXATTRIB2FVPROC) pLoad("glVertexAttrib2fv");
	pApi->glVertexAttrib2s = (PFNGLVERTEXATTRIB2SPROC) pLoad("glVertexAttrib2s");
	pApi->glVertexAttrib2sv = (PFNGLVERTEXATTRIB2SVPROC) pLoad("glVertexAttrib2sv");
	pApi->glVertexAttrib3d = (PFNGLVERTEXATTRIB3DPROC) pLoad("glVertexAttrib3d");
	pApi->glVertexAttrib3dv = (PFNGLVERTEXATTRIB3DVPROC) pLoad("glVertexAttrib3dv");
	pApi->glVertexAttrib3f = (PFNGLVERTEXATTRIB3FPROC) pLoad("glVertexAttrib3f");
	pApi->glVertexAttrib3fv = (PFNGLVERTEXATTRIB3FVPROC) pLoad("glVertexAttrib3fv");
	pApi->glVertexAttrib3s = (PFNGLVERTEXATTRIB3SPROC) pLoad("glVertexAttrib3s");
	pApi->glVertexAttrib3sv = (PFNGLVERTEXATTRIB3SVPROC) pLoad("glVertexAttrib3sv");
	pApi->glVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBVPROC) pLoad("glVertexAttrib4Nbv");
	pApi->glVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIVPROC) pLoad("glVertexAttrib4Niv");
	pApi->glVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSVPROC) pLoad("glVertexAttrib4Nsv");
	pApi->glVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUBPROC) pLoad("glVertexAttrib4Nub");
	pApi->glVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBVPROC) pLoad("glVertexAttrib4Nubv");
	pApi->glVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIVPROC) pLoad("glVertexAttrib4Nuiv");
	pApi->glVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSVPROC) pLoad("glVertexAttrib4Nusv");
	pApi->glVertexAttrib4bv = (PFNGLVERTEXATTRIB4BVPROC) pLoad("glVertexAttrib4bv");
	pApi->glVertexAttrib4d = (PFNGLVERTEXATTRIB4DPROC) pLoad("glVertexAttrib4d");
	pApi->glVertexAttrib4dv = (PFNGLVERTEXATTRIB4DVPROC) pLoad("glVertexAttrib4dv");
	pApi->glVertexAttrib4f = (PFNGLVERTEXATTRIB4FPROC) pLoad("glVertexAttrib4f");
	pApi->glVertexAttrib4fv = (PFNGLVERTEXATTRIB4FVPROC) pLoad("glVertexAttrib4fv");
	pApi->glVertexAttrib4iv = (PFNGLVERTEXATTRIB4IVPROC) pLoad("glVertexAttrib4iv");
	pApi->glVertexAttrib4s = (PFNGLVERTEXATTRIB4SPROC) pLoad("glVertexAttrib4s");
	pApi->glVertexAttrib4sv = (PFNGLVERTEXATTRIB4SVPROC) pLoad("glVertexAttrib4sv");
	pApi->glVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBVPROC) pLoad("glVertexAttrib4ubv");
	pApi->glVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIVPROC) pLoad("glVertexAttrib4uiv");
	pApi->glVertexAttrib4usv = (PFNGLVERTEXATTRIB4USVPROC) pLoad("glVertexAttrib4usv");
	pApi->glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC) pLoad("glVertexAttribPointer");
	pApi->glUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FVPROC) pLoad("glUniformMatrix2x3fv");
	pApi->glUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FVPROC) pLoad("glUniformMatrix3x2fv");
	pApi->glUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FVPROC) pLoad("glUniformMatrix2x4fv");
	pApi->glUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FVPROC) pLoad("glUniformMatrix4x2fv");
	pApi->glUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FVPROC) pLoad("glUniformMatrix3x4fv");
	pApi->glUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FVPROC) pLoad("glUniformMatrix4x3fv");
	pApi->glColorMaski = (PFNGLCOLORMASKIPROC) pLoad("glColorMaski");
	pApi->glGetBooleani_v = (PFNGLGETBOOLEANI_VPROC) pLoad("glGetBooleani_v");
	pApi->glGetIntegeri_v = (PFNGLGETINTEGERI_VPROC) pLoad("glGetIntegeri_v");
	pApi->glEnablei = (PFNGLENABLEIPROC) pLoad("glEnablei");
	pApi->glDisablei = (PFNGLDISABLEIPROC) pLoad("glDisablei");
	pApi->glIsEnabledi = (PFNGLISENABLEDIPROC) pLoad("glIsEnabledi");
	pApi->glBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACKPROC) pLoad("glBeginTransformFeedback");
	pApi->glEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACKPROC) pLoad("glEndTransformFeedback");
	pApi->glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC) pLoad("glBindBufferRange");
	pApi->glBindBufferBase = (PFNGLBINDBUFFERBASEPROC) pLoad("glBindBufferBase");
	pApi->glTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGSPROC) pLoad("glTransformFeedbackVaryings");
	pApi->glGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYINGPROC) pLoad("glGetTransformFeedbackVarying");
	pApi->glClampColor = (PFNGLCLAMPCOLORPROC) pLoad("glClampColor");
	pApi->glBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDERPROC) pLoad("glBeginConditionalRender");
	pApi->glEndConditionalRender = (PFNGLENDCONDITIONALRENDERPROC) pLoad("glEndConditionalRender");
	pApi->glVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTERPROC) pLoad("glVertexAttribIPointer");
	pApi->glGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIVPROC) pLoad("glGetVertexAttribIiv");
	pApi->glGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIVPROC) pLoad("glGetVertexAttribIuiv");
	pApi->glVertexAttribI1i = (PFNGLVERTEXATTRIBI1IPROC) pLoad("glVertexAttribI1i");
	pApi->glVertexAttribI2i = (PFNGLVERTEXATTRIBI2IPROC) pLoad("glVertexAttribI2i");
	pApi->glVertexAttribI3i = (PFNGLVERTEXATTRIBI3IPROC) pLoad("glVertexAttribI3i");
	pApi->glVertexAttribI4i = (PFNGLVERTEXATTRIBI4IPROC) pLoad("glVertexAttribI4i");
	pApi->glVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UIPROC) pLoad("glVertexAttribI1ui");
	pApi->glVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UIPROC) pLoad("glVertexAttribI2ui");
	pApi->glVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UIPROC) pLoad("glVertexAttribI3ui");
	pApi->glVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UIPROC) pLoad("glVertexAttribI4ui");
	pApi->glVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IVPROC) pLoad("glVertexAttribI1iv");
	pApi->glVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IVPROC) pLoad("glVertexAttribI2iv");
	pApi->glVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IVPROC) pLoad("glVertexAttribI3iv");
	pApi->glVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IVPROC) pLoad("glVertexAttribI4iv");
	pApi->glVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIVPROC) pLoad("glVertexAttribI1uiv");
	pApi->glVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIVPROC) pLoad("glVertexAttribI2uiv");
	pApi->glVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIVPROC) pLoad("glVertexAttribI3uiv");
	pApi->glVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIVPROC) pLoad("glVertexAttribI4uiv");
	pApi->glVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BVPROC) pLoad("glVertexAttribI4bv");
	pApi->glVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SVPROC) pLoad("glVertexAttribI4sv");
	pApi->glVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBVPROC) pLoad("glVertexAttribI4ubv");
	pApi->glVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USVPROC) pLoad("glVertexAttribI4usv");
	pApi->glGetUniformuiv = (PFNGLGETUNIFORMUIVPROC) pLoad("glGetUniformuiv");
	pApi->glBindFragDataLocation = (PFNGLBINDFRAGDATALOCATIONPROC) pLoad("glBindFragDataLocation");
	pApi->glGetFragDataLocation = (PFNGLGETFRAGDATALOCATIONPROC) pLoad("glGetFragDataLocation");
	pApi->glUniform1ui = (PFNGLUNIFORM1UIPROC) pLoad("glUniform1ui");
	pApi->glUniform2ui = (PFNGLUNIFORM2UIPROC) pLoad("glUniform2ui");
	pApi->glUniform3ui = (PFNGLUNIFORM3UIPROC) pLoad("glUniform3ui");
	pApi->glUniform4ui = (PFNGLUNIFORM4UIPROC) pLoad("glUniform4ui");
	pApi->glUniform1uiv = (PFNGLUNIFORM1UIVPROC) pLoad("glUniform1uiv");
	pApi->glUniform2uiv = (PFNGLUNIFORM2UIVPROC) pLoad("glUniform2uiv");
	pApi->glUniform3uiv = (PFNGLUNIFORM3UIVPROC) pLoad("glUniform3uiv");
	pApi->glUniform4uiv = (PFNGLUNIFORM4UIVPROC) pLoad("glUniform4uiv");
	pApi->glTexParameterIiv = (PFNGLTEXPARAMETERIIVPROC) pLoad("glTexParameterIiv");
	pApi->glTexParameterIuiv = (PFNGLTEXPARAMETERIUIVPROC) pLoad("glTexParameterIuiv");
	pApi->glGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIVPROC) pLoad("glGetTexParameterIiv");
	pApi->glGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIVPROC) pLoad("glGetTexParameterIuiv");
	pApi->glClearBufferiv = (PFNGLCLEARBUFFERIVPROC) pLoad("glClearBufferiv");
	pApi->glClearBufferuiv = (PFNGLCLEARBUFFERUIVPROC) pLoad("glClearBufferuiv");
	pApi->glClearBufferfv = (PFNGLCLEARBUFFERFVPROC) pLoad("glClearBufferfv");
	pApi->glClearBufferfi = (PFNGLCLEARBUFFERFIPROC) pLoad("glClearBufferfi");
	pApi->glGetStringi = (PFNGLGETSTRINGIPROC) pLoad("glGetStringi");
	pApi->glIsRenderbuffer = (PFNGLISRENDERBUFFERPROC) pLoad("glIsRenderbuffer");
	pApi->glBindRenderbuffer = (PFNGLBINDRENDERBUFFERPROC) pLoad("glBindRenderbuffer");
	pApi->glDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERSPROC) pLoad("glDeleteRenderbuffers");
	pApi->glGenRenderbuffers = (PFNGLGENRENDERBUFFERSPROC) pLoad("glGenRenderbuffers");
	pApi->glRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGEPROC) pLoad("glRenderbufferStorage");
	pApi->glGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIVPROC) pLoad("glGetRenderbufferParameteriv");
	pApi->glIsFramebuffer = (PFNGLISFRAMEBUFFERPROC) pLoad("glIsFramebuffer");
	pApi->glBindFramebuffer = (PFNGLBINDFRAMEBUFFERPROC) pLoad("glBindFramebuffer");
	pApi->glDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERSPROC) pLoad("glDeleteFramebuffers");
	pApi->glGenFramebuffers = (PFNGLGENFRAMEBUFFERSPROC) pLoad("glGenFramebuffers");
	pApi->glCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUSPROC) pLoad("glCheckFramebufferStatus");
	pApi->glFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1DPROC) pLoad("glFramebufferTexture1D");
	pApi->glFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2DPROC) pLoad("glFramebufferTexture2D");
	pApi->glFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3DPROC) pLoad("glFramebufferTexture3D");
	pApi->glFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFERPROC) pLoad("glFramebufferRenderbuffer");
	pApi->glGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC) pLoad("glGetFramebufferAttachmentParameteriv");
	pApi->glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC) pLoad("glGenerateMipmap");
	pApi->glBlitFramebuffer = (PFNGLBLITFRAMEBUFFERPROC) pLoad("glBlitFramebuffer");
	pApi->glRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC) pLoad("glRenderbufferStorageMultisample");
	pApi->glFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYERPROC) pLoad("glFramebufferTextureLayer");
	pApi->glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC) pLoad("glMapBufferRange");
	pApi->glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC) pLoad("glFlushMappedBufferRange");
	pApi->glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC) pLoad("glBindVertexArray");
	pApi->glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC) pLoad("glDeleteVertexArrays");
	pApi->glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC) pLoad("glGenVertexArrays");
	pApi->glIsVertexArray = (PFNGLISVERTEXARRAYPROC) pLoad("glIsVertexArray");
	pApi->glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC) pLoad("glDrawArraysInstanced");
	pApi->glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC) pLoad("glDrawElementsInstanced");
	pApi->glTexBuffer = (PFNGLTEXBUFFERPROC) pLoad("glTexBuffer");
	pApi->glPrimitiveRestartIndex = (PFNGLPRIMITIVERESTARTINDEXPROC) pLoad("glPrimitiveRestartIndex");
	pApi->glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC) pLoad("glCopyBufferSubData");
	pApi->glGetUniformIndices = (PFNGLGETUNIFORMINDICESPROC) pLoad("glGetUniformIndices");
	pApi->glGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIVPROC) pLoad("glGetActiveUniformsiv");
	pApi->glGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAMEPROC) pLoad("glGetActiveUniformName");
	pApi->glGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEXPROC) pLoad("glGetUniformBlockIndex");
	pApi->glGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIVPROC) pLoad("glGetActiveUniformBlockiv");
	pApi->glGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC) pLoad("glGetActiveUniformBlockName");
	pApi->glUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDINGPROC) pLoad("glUniformBlockBinding");
	pApi->glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC) pLoad("glDrawElementsBaseVertex");
	pApi->glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC) pLoad("glDrawRangeElementsBaseVertex");
	pApi->glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC) pLoad("glDrawElementsInstancedBaseVertex");
	pApi->glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC) pLoad("glMultiDrawElementsBaseVertex");
	pApi->glProvokingVertex = (PFNGLPROVOKINGVERTEXPROC) pLoad("glProvokingVertex");
	pApi->glFenceSync = (PFNGLFENCESYNCPROC) pLoad("glFenceSync");
	pApi->glIsSync = (PFNGLISSYNCPROC) pLoad("glIsSync");
	pApi->glDeleteSync = (PFNGLDELETESYNCPROC) pLoad("glDeleteSync");
	pApi->glClientWaitSync = (PFNGLCLIENTWAITSYNCPROC) pLoad("glClientWaitSync");
	pApi->glWaitSync = (PFNGLWAITSYNCPROC) pLoad("glWaitSync");
	pApi->glGetInteger64v = (PFNGLGETINTEGER64VPROC) pLoad("glGetInteger64v");
	pApi->glGetSynciv = (PFNGLGETSYNCIVPROC) pLoad("glGetSynciv");
	pApi->glGetInteger64i_v = (PFNGLGETINTEGER64I_VPROC) pLoad("glGetInteger64i_v");
	pApi->glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC) pLoad("glGetBufferParameteri64v");
	pApi->glFramebufferTexture = (PFNGLFRAMEBUFFERTEXTUREPROC) pLoad("glFramebufferTexture");
	pApi->glTexImage2DMultisample = (PFNGLTEXIMAGE2DMULTISAMPLEPROC) pLoad("glTexImage2DMultisample");
	pApi->glTexImage3DMultisample = (PFNGLTEXIMAGE3DMULTISAMPLEPROC) pLoad("glTexImage3DMultisample");
	pApi->glGetMultisamplefv = (PFNGLGETMULTISAMPLEFVPROC) pLoad("glGetMultisamplefv");
	pApi->glSampleMaski = (PFNGLSAMPLEMASKIPROC) pLoad("glSampleMaski");
	pApi->glBindFragDataLocationIndexed = (PFNGLBINDFRAGDATALOCATIONINDEXEDPROC) pLoad("glBindFragDataLocationIndexed");
	pApi->glGetFragDataIndex = (PFNGLGETFRAGDATAINDEXPROC) pLoad("glGetFragDataIndex");
	pApi->glGenSamplers = (PFNGLGENSAMPLERSPROC) pLoad("glGenSamplers");
	pApi->glDeleteSamplers = (PFNGLDELETESAMPLERSPROC) pLoad("glDeleteSamplers");
	pApi->glIsSampler = (PFNGLISSAMPLERPROC) pLoad("glIsSampler");
	pApi->glBindSampler = (PFNGLBINDSAMPLERPROC) pLoad("glBindSampler");
	pApi->glSamplerParameteri = (PFNGLSAMPLERPARAMETERIPROC) pLoad("glSamplerParameteri");
	pApi->glSamplerParameteriv = (PFNGLSAMPLERPARAMETERIVPROC) pLoad("glSamplerParameteriv");
	pApi->glSamplerParameterf = (PFNGLSAMPLERPARAMETERFPROC) pLoad("glSamplerParameterf");
	pApi->glSamplerParameterfv = (PFNGLSAMPLERPARAMETERFVPROC) pLoad("glSamplerParameterfv");
	pApi->glSamplerParameterIiv = (PFNGLSAMPLERPARAMETERIIVPROC) pLoad("glSamplerParameterIiv");
	pApi->glSamplerParameterIuiv = (PFNGLSAMPLERPARAMETERIUIVPROC) pLoad("glSamplerParameterIuiv");
	pApi->glGetSamplerParameteriv = (PFNGLGETSAMPLERPARAMETERIVPROC) pLoad("glGetSamplerParameteriv");
	pApi->glGetSamplerParameterIiv = (PFNGLGETSAMPLERPARAMETERIIVPROC) pLoad("glGetSamplerParameterIiv");
	pApi->glGetSamplerParameterfv = (PFNGLGETSAMPLERPARAMETERFVPROC) pLoad("glGetSamplerParameterfv");
	pApi->glGetSamplerParameterIuiv = (PFNGLGETSAMPLERPARAMETERIUIVPROC) pLoad("glGetSamplerParameterIuiv");
	pApi->glQueryCounter = (PFNGLQUERYCOUNTERPROC) pLoad("glQueryCounter");
	pApi->glGetQueryObjecti64v = (PFNGLGETQUERYOBJECTI64VPROC) pLoad("glGetQueryObjecti64v");
	pApi->glGetQueryObjectui64v = (PFNGLGETQUERYOBJECTUI64VPROC) pLoad("glGetQueryObjectui64v");
	pApi->glVertexAttribDivisor = (PFNGLVERTEXATTRIBDIVISORPROC) pLoad("glVertexAttribDivisor");
	pApi->glVertexAttribP1ui = (PFNGLVERTEXATTRIBP1UIPROC) pLoad("glVertexAttribP1ui");
	pApi->glVertexAttribP1uiv = (PFNGLVERTEXATTRIBP1UIVPROC) pLoad("glVertexAttribP1uiv");
	pApi->glVertexAttribP2ui = (PFNGLVERTEXATTRIBP2UIPROC) pLoad("glVertexAttribP2ui");
	pApi->glVertexAttribP2uiv = (PFNGLVERTEXATTRIBP2UIVPROC) pLoad("glVertexAttribP2uiv");
	pApi->glVertexAttribP3ui = (PFNGLVERTEXATTRIBP3UIPROC) pLoad("glVertexAttribP3ui");
	pApi->glVertexAttribP3uiv = (PFNGLVERTEXATTRIBP3UIVPROC) pLoad("glVertexAttribP3uiv");
	pApi->glVertexAttribP4ui = (PFNGLVERTEXATTRIBP4UIPROC) pLoad("glVertexAttribP4ui");
	pApi->glVertexAttribP4uiv = (PFNGLVERTEXATTRIBP4UIVPROC) pLoad("glVertexAttribP4uiv");
	pApi->glVertexP2ui = (PFNGLVERTEXP2UIPROC) pLoad("glVertexP2ui");
	pApi->glVertexP2uiv = (PFNGLVERTEXP2UIVPROC) pLoad("glVertexP2uiv");
	pApi->glVertexP3ui = (PFNGLVERTEXP3UIPROC) pLoad("glVertexP3ui");
	pApi->glVertexP3uiv = (PFNGLVERTEXP3UIVPROC) pLoad("glVertexP3uiv");
	pApi->glVertexP4ui = (PFNGLVERTEXP4UIPROC) pLoad("glVertexP4ui");
	pApi->glVertexP4uiv = (PFNGLVERTEXP4UIVPROC) pLoad("glVertexP4uiv");
	pApi->glTexCoordP1ui = (PFNGLTEXCOORDP1UIPROC) pLoad("glTexCoordP1ui");
	pApi->glTexCoordP1uiv = (PFNGLTEXCOORDP1UIVPROC) pLoad("glTexCoordP1uiv");
	pApi->glTexCoordP2ui = (PFNGLTEXCOORDP2UIPROC) pLoad("glTexCoordP2ui");
	pApi->glTexCoordP2uiv = (PFNGLTEXCOORDP2UIVPROC) pLoad("glTexCoordP2uiv");
	pApi->glTexCoordP3ui = (PFNGLTEXCOORDP3UIPROC) pLoad("glTexCoordP3ui");
	pApi->glTexCoordP3uiv = (PFNGLTEXCOORDP3UIVPROC) pLoad("glTexCoordP3uiv");
	pApi->glTexCoordP4ui = (PFNGLTEXCOORDP4UIPROC) pLoad("glTexCoordP4ui");
	pApi->glTexCoordP4uiv = (PFNGLTEXCOORDP4UIVPROC) pLoad("glTexCoordP4uiv");
	pApi->glMultiTexCoordP1ui = (PFNGLMULTITEXCOORDP1UIPROC) pLoad("glMultiTexCoordP1ui");
	pApi->glMultiTexCoordP1uiv = (PFNGLMULTITEXCOORDP1UIVPROC) pLoad("glMultiTexCoordP1uiv");
	pApi->glMultiTexCoordP2ui = (PFNGLMULTITEXCOORDP2UIPROC) pLoad("glMultiTexCoordP2ui");
	pApi->glMultiTexCoordP2uiv = (PFNGLMULTITEXCOORDP2UIVPROC) pLoad("glMultiTexCoordP2uiv");
	pApi->glMultiTexCoordP3ui = (PFNGLMULTITEXCOORDP3UIPROC) pLoad("glMultiTexCoordP3ui");
	pApi->glMultiTexCoordP3uiv = (PFNGLMULTITEXCOORDP3UIVPROC) pLoad("glMultiTexCoordP3uiv");
	pApi->glMultiTexCoordP4ui = (PFNGLMULTITEXCOORDP4UIPROC) pLoad("glMultiTexCoordP4ui");
	pApi->glMultiTexCoordP4uiv = (PFNGLMULTITEXCOORDP4UIVPROC) pLoad("glMultiTexCoordP4uiv");
	pApi->glNormalP3ui = (PFNGLNORMALP3UIPROC) pLoad("glNormalP3ui");
	pApi->glNormalP3uiv = (PFNGLNORMALP3UIVPROC) pLoad("glNormalP3uiv");
	pApi->glColorP3ui = (PFNGLCOLORP3UIPROC) pLoad("glColorP3ui");
	pApi->glColorP3uiv = (PFNGLCOLORP3UIVPROC) pLoad("glColorP3uiv");
	pApi->glColorP4ui = (PFNGLCOLORP4UIPROC) pLoad("glColorP4ui");
	pApi->glColorP4uiv = (PFNGLCOLORP4UIVPROC) pLoad("glColorP4uiv");
	pApi->glSecondaryColorP3ui = (PFNGLSECONDARYCOLORP3UIPROC) pLoad("glSecondaryColorP3ui");
	pApi->glSecondaryColorP3uiv = (PFNGLSECONDARYCOLORP3UIVPROC) pLoad("glSecondaryColorP3uiv");
	pApi->glMinSampleShading = (PFNGLMINSAMPLESHADINGPROC) pLoad("glMinSampleShading");
	pApi->glBlendEquationi = (PFNGLBLENDEQUATIONIPROC) pLoad("glBlendEquationi");
	pApi->glBlendEquationSeparatei = (PFNGLBLENDEQUATIONSEPARATEIPROC) pLoad("glBlendEquationSeparatei");
	pApi->glBlendFunci = (PFNGLBLENDFUNCIPROC) pLoad("glBlendFunci");
	pApi->glBlendFuncSeparatei = (PFNGLBLENDFUNCSEPARATEIPROC) pLoad("glBlendFuncSeparatei");
	pApi->glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC) pLoad("glDrawArraysIndirect");
	pApi->glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC) pLoad("glDrawElementsIndirect");
	pApi->glUniform1d = (PFNGLUNIFORM1DPROC) pLoad("glUniform1d");
	pApi->glUniform2d = (PFNGLUNIFORM2DPROC) pLoad("glUniform2d");
	pApi->glUniform3d = (PFNGLUNIFORM3DPROC) pLoad("glUniform3d");
	pApi->glUniform4d = (PFNGLUNIFORM4DPROC) pLoad("glUniform4d");
	pApi->glUniform1dv = (PFNGLUNIFORM1DVPROC) pLoad("glUniform1dv");
	pApi->glUniform2dv = (PFNGLUNIFORM2DVPROC) pLoad("glUniform2dv");
	pApi->glUniform3dv = (PFNGLUNIFORM3DVPROC) pLoad("glUniform3dv");
	pApi->glUniform4dv = (PFNGLUNIFORM4DVPROC) pLoad("glUniform4dv");
	pApi->glUniformMatrix2dv = (PFNGLUNIFORMMATRIX2DVPROC) pLoad("glUniformMatrix2dv");
	pApi->glUniformMatrix3dv = (PFNGLUNIFORMMATRIX3DVPROC) pLoad("glUniformMatrix3dv");
	pApi->glUniformMatrix4dv = (PFNGLUNIFORMMATRIX4DVPROC) pLoad("glUniformMatrix4dv");
	pApi->glUniformMatrix2x3dv = (PFNGLUNIFORMMATRIX2X3DVPROC) pLoad("glUniformMatrix2x3dv");
	pApi->glUniformMatrix2x4dv = (PFNGLUNIFORMMATRIX2X4DVPROC) pLoad("glUniformMatrix2x4dv");
	pApi->glUniformMatrix3x2dv = (PFNGLUNIFORMMATRIX3X2DVPROC) pLoad("glUniformMatrix3x2dv");
	pApi->glUniformMatrix3x4dv = (PFNGLUNIFORMMATRIX3X4DVPROC) pLoad("glUniformMatrix3x4dv");
	pApi->glUniformMatrix4x2dv = (PFNGLUNIFORMMATRIX4X2DVPROC) pLoad("glUniformMatrix4x2dv");
	pApi->glUniformMatrix4x3dv = (PFNGLUNIFORMMATRIX4X3DVPROC) pLoad("glUniformMatrix4x3dv");
	pApi->glGetUniformdv = (PFNGLGETUNIFORMDVPROC) pLoad("glGetUniformdv");
	pApi->glGetSubroutineUniformLocation = (PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC) pLoad("glGetSubroutineUniformLocation");
	pApi->glGetSubroutineIndex = (PFNGLGETSUBROUTINEINDEXPROC) pLoad("glGetSubroutineIndex");
	pApi->glGetActiveSubroutineUniformiv = (PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC) pLoad("glGetActiveSubroutineUniformiv");
	pApi->glGetActiveSubroutineUniformName = (PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC) pLoad("glGetActiveSubroutineUniformName");
	pApi->glGetActiveSubroutineName = (PFNGLGETACTIVESUBROUTINENAMEPROC) pLoad("glGetActiveSubroutineName");
	pApi->glUniformSubroutinesuiv = (PFNGLUNIFORMSUBROUTINESUIVPROC) pLoad("glUniformSubroutinesuiv");
	pApi->glGetUniformSubroutineuiv = (PFNGLGETUNIFORMSUBROUTINEUIVPROC) pLoad("glGetUniformSubroutineuiv");
	pApi->glGetProgramStageiv = (PFNGLGETPROGRAMSTAGEIVPROC) pLoad("glGetProgramStageiv");
	pApi->glPatchParameteri = (PFNGLPATCHPARAMETERIPROC) pLoad("glPatchParameteri");
	pApi->glPatchParameterfv = (PFNGLPATCHPARAMETERFVPROC) pLoad("glPatchParameterfv");
	pApi->glBindTransformFeedback = (PFNGLBINDTRANSFORMFEEDBACKPROC) pLoad("glBindTransformFeedback");
	pApi->glDeleteTransformFeedbacks = (PFNGLDELETETRANSFORMFEEDBACKSPROC) pLoad("glDeleteTransformFeedbacks");
	pApi->glGenTransformFeedbacks = (PFNGLGENTRANSFORMFEEDBACKSPROC) pLoad("glGenTransformFeedbacks");
	pApi->glIsTransformFeedback = (PFNGLISTRANSFORMFEEDBACKPROC) pLoad("glIsTransformFeedback");
	pApi->glPauseTransformFeedback = (PFNGLPAUSETRANSFORMFEEDBACKPROC) pLoad("glPauseTransformFeedback");
	pApi->glResumeTransformFeedback = (PFNGLRESUMETRANSFORMFEEDBACKPROC) pLoad("glResumeTransformFeedback");
	pApi->glDrawTransformFeedback = (PFNGLDRAWTRANSFORMFEEDBACKPROC) pLoad("glDrawTransformFeedback");
	pApi->glDrawTransformFeedbackStream = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC) pLoad("glDrawTransformFeedbackStream");
	pApi->glBeginQueryIndexed = (PFNGLBEGINQUERYINDEXEDPROC) pLoad("glBeginQueryIndexed");
	pApi->glEndQueryIndexed = (PFNGLENDQUERYINDEXEDPROC) pLoad("glEndQueryIndexed");
	pApi->glGetQueryIndexediv = (PFNGLGETQUERYINDEXEDIVPROC) pLoad("glGetQueryIndexediv");
	pApi->glReleaseShaderCompiler = (PFNGLRELEASESHADERCOMPILERPROC) pLoad("glReleaseShaderCompiler");
	pApi->glShaderBinary = (PFNGLSHADERBINARYPROC) pLoad("glShaderBinary");
	pApi->glGetShaderPrecisionFormat = (PFNGLGETSHADERPRECISIONFORMATPROC) pLoad("glGetShaderPrecisionFormat");
	pApi->glDepthRangef = (PFNGLDEPTHRANGEFPROC) pLoad("glDepthRangef");
	pApi->glClearDepthf = (PFNGLCLEARDEPTHFPROC) pLoad("glClearDepthf");
	pApi->glGetProgramBinary = (PFNGLGETPROGRAMBINARYPROC) pLoad("glGetProgramBinary");
	pApi->glProgramBinary = (PFNGLPROGRAMBINARYPROC) pLoad("glProgramBinary");
	pApi->glProgramParameteri = (PFNGLPROGRAMPARAMETERIPROC) pLoad("glProgramParameteri");
	pApi->glUseProgramStages = (PFNGLUSEPROGRAMSTAGESPROC) pLoad("glUseProgramStages");
	pApi->glActiveShaderProgram = (PFNGLACTIVESHADERPROGRAMPROC) pLoad("glActiveShaderProgram");
	pApi->glCreateShaderProgramv = (PFNGLCREATESHADERPROGRAMVPROC) pLoad("glCreateShaderProgramv");
	pApi->glBindProgramPipeline = (PFNGLBINDPROGRAMPIPELINEPROC) pLoad("glBindProgramPipeline");
	pApi->glDeleteProgramPipelines = (PFNGLDELETEPROGRAMPIPELINESPROC) pLoad("glDeleteProgramPipelines");
	pApi->glGenProgramPipelines = (PFNGLGENPROGRAMPIPELINESPROC) pLoad("glGenProgramPipelines");
	pApi->glIsProgramPipeline = (PFNGLISPROGRAMPIPELINEPROC) pLoad("glIsProgramPipeline");
	pApi->glGetProgramPipelineiv = (PFNGLGETPROGRAMPIPELINEIVPROC) pLoad("glGetProgramPipelineiv");
	pApi->glProgramUniform1i = (PFNGLPROGRAMUNIFORM1IPROC) pLoad("glProgramUniform1i");
	pApi->glProgramUniform1iv = (PFNGLPROGRAMUNIFORM1IVPROC) pLoad("glProgramUniform1iv");
	pApi->glProgramUniform1f = (PFNGLPROGRAMUNIFORM1FPROC) pLoad("glProgramUniform1f");
	pApi->glProgramUniform1fv = (PFNGLPROGRAMUNIFORM1FVPROC) pLoad("glProgramUniform1fv");
	pApi->glProgramUniform1d = (PFNGLPROGRAMUNIFORM1DPROC) pLoad("glProgramUniform1d");
	pApi->glProgramUniform1dv = (PFNGLPROGRAMUNIFORM1DVPROC) pLoad("glProgramUniform1dv");
	pApi->glProgramUniform1ui = (PFNGLPROGRAMUNIFORM1UIPROC) pLoad("glProgramUniform1ui");
	pApi->glProgramUniform1uiv = (PFNGLPROGRAMUNIFORM1UIVPROC) pLoad("glProgramUniform1uiv");
	pApi->glProgramUniform2i = (PFNGLPROGRAMUNIFORM2IPROC) pLoad("glProgramUniform2i");
	pApi->glProgramUniform2iv = (PFNGLPROGRAMUNIFORM2IVPROC) pLoad("glProgramUniform2iv");
	pApi->glProgramUniform2f = (PFNGLPROGRAMUNIFORM2FPROC) pLoad("glProgramUniform2f");
	pApi->glProgramUniform2fv = (PFNGLPROGRAMUNIFORM2FVPROC) pLoad("glProgramUniform2fv");
	pApi->glProgramUniform2d = (PFNGLPROGRAMUNIFORM2DPROC) pLoad("glProgramUniform2d");
	pApi->glProgramUniform2dv = (PFNGLPROGRAMUNIFORM2DVPROC) pLoad("glProgramUniform2dv");
	pApi->glProgramUniform2ui = (PFNGLPROGRAMUNIFORM2UIPROC) pLoad("glProgramUniform2ui");
	pApi->glProgramUniform2uiv = (PFNGLPROGRAMUNIFORM2UIVPROC) pLoad("glProgramUniform2uiv");
	pApi->glProgramUniform3i = (PFNGLPROGRAMUNIFORM3IPROC) pLoad("glProgramUniform3i");
	pApi->glProgramUniform3iv = (PFNGLPROGRAMUNIFORM3IVPROC) pLoad("glProgramUniform3iv");
	pApi->glProgramUniform3f = (PFNGLPROGRAMUNIFORM3FPROC) pLoad("glProgramUniform3f");
	pApi->glProgramUniform3fv = (PFNGLPROGRAMUNIFORM3FVPROC) pLoad("glProgramUniform3fv");
	pApi->glProgramUniform3d = (PFNGLPROGRAMUNIFORM3DPROC) pLoad("glProgramUniform3d");
	pApi->glProgramUniform3dv = (PFNGLPROGRAMUNIFORM3DVPROC) pLoad("glProgramUniform3dv");
	pApi->glProgramUniform3ui = (PFNGLPROGRAMUNIFORM3UIPROC) pLoad("glProgramUniform3ui");
	pApi->glProgramUniform3uiv = (PFNGLPROGRAMUNIFORM3UIVPROC) pLoad("glProgramUniform3uiv");
	pApi->glProgramUniform4i = (PFNGLPROGRAMUNIFORM4IPROC) pLoad("glProgramUniform4i");
	pApi->glProgramUniform4iv = (PFNGLPROGRAMUNIFORM4IVPROC) pLoad("glProgramUniform4iv");
	pApi->glProgramUniform4f = (PFNGLPROGRAMUNIFORM4FPROC) pLoad("glProgramUniform4f");
	pApi->glProgramUniform4fv = (PFNGLPROGRAMUNIFORM4FVPROC) pLoad("glProgramUniform4fv");
	pApi->glProgramUniform4d = (PFNGLPROGRAMUNIFORM4DPROC) pLoad("glProgramUniform4d");
	pApi->glProgramUniform4dv = (PFNGLPROGRAMUNIFORM4DVPROC) pLoad("glProgramUniform4dv");
	pApi->glProgramUniform4ui = (PFNGLPROGRAMUNIFORM4UIPROC) pLoad("glProgramUniform4ui");
	pApi->glProgramUniform4uiv = (PFNGLPROGRAMUNIFORM4UIVPROC) pLoad("glProgramUniform4uiv");
	pApi->glProgramUniformMatrix2fv = (PFNGLPROGRAMUNIFORMMATRIX2FVPROC) pLoad("glProgramUniformMatrix2fv");
	pApi->glProgramUniformMatrix3fv = (PFNGLPROGRAMUNIFORMMATRIX3FVPROC) pLoad("glProgramUniformMatrix3fv");
	pApi->glProgramUniformMatrix4fv = (PFNGLPROGRAMUNIFORMMATRIX4FVPROC) pLoad("glProgramUniformMatrix4fv");
	pApi->glProgramUniformMatrix2dv = (PFNGLPROGRAMUNIFORMMATRIX2DVPROC) pLoad("glProgramUniformMatrix2dv");
	pApi->glProgramUniformMatrix3dv = (PFNGLPROGRAMUNIFORMMATRIX3DVPROC) pLoad("glProgramUniformMatrix3dv");
	pApi->glProgramUniformMatrix4dv = (PFNGLPROGRAMUNIFORMMATRIX4DVPROC) pLoad("glProgramUniformMatrix4dv");
	pApi->glProgramUniformMatrix2x3fv = (PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC) pLoad("glProgramUniformMatrix2x3fv");
	pApi->glProgramUniformMatrix3x2fv = (PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC) pLoad("glProgramUniformMatrix3x2fv");
	pApi->glProgramUniformMatrix2x4fv = (PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC) pLoad("glProgramUniformMatrix2x4fv");
	pApi->glProgramUniformMatrix4x2fv = (PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC) pLoad("glProgramUniformMatrix4x2fv");
	pApi->glProgramUniformMatrix3x4fv = (PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC) pLoad("glProgramUniformMatrix3x4fv");
	pApi->glProgramUniformMatrix4x3fv = (PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC) pLoad("glProgramUniformMatrix4x3fv");
	pApi->glProgramUniformMatrix2x3dv = (PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC) pLoad("glProgramUniformMatrix2x3dv");
	pApi->glProgramUniformMatrix3x2dv = (PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC) pLoad("glProgramUniformMatrix3x2dv");
	pApi->glProgramUniformMatrix2x4dv = (PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC) pLoad("glProgramUniformMatrix2x4dv");
	pApi->glProgramUniformMatrix4x2dv = (PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC) pLoad("glProgramUniformMatrix4x2dv");
	pApi->glProgramUniformMatrix3x4dv = (PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC) pLoad("glProgramUniformMatrix3x4dv");
	pApi->glProgramUniformMatrix4x3dv = (PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC) pLoad("glProgramUniformMatrix4x3dv");
	pApi->glValidateProgramPipeline = (PFNGLVALIDATEPROGRAMPIPELINEPROC) pLoad("glValidateProgramPipeline");
	pApi->glGetProgramPipelineInfoLog = (PFNGLGETPROGRAMPIPELINEINFOLOGPROC) pLoad("glGetProgramPipelineInfoLog");
	pApi->glVertexAttribL1d = (PFNGLVERTEXATTRIBL1DPROC) pLoad("glVertexAttribL1d");
	pApi->glVertexAttribL2d = (PFNGLVERTEXATTRIBL2DPROC) pLoad("glVertexAttribL2d");
	pApi->glVertexAttribL3d = (PFNGLVERTEXATTRIBL3DPROC) pLoad("glVertexAttribL3d");
	pApi->glVertexAttribL4d = (PFNGLVERTEXATTRIBL4DPROC) pLoad("glVertexAttribL4d");
	pApi->glVertexAttribL1dv = (PFNGLVERTEXATTRIBL1DVPROC) pLoad("glVertexAttribL1dv");
	pApi->glVertexAttribL2dv = (PFNGLVERTEXATTRIBL2DVPROC) pLoad("glVertexAttribL2dv");
	pApi->glVertexAttribL3dv = (PFNGLVERTEXATTRIBL3DVPROC) pLoad("glVertexAttribL3dv");
	pApi->glVertexAttribL4dv = (PFNGLVERTEXATTRIBL4DVPROC) pLoad("glVertexAttribL4dv");
	pApi->glVertexAttribLPointer = (PFNGLVERTEXATTRIBLPOINTERPROC) pLoad("glVertexAttribLPointer");
	pApi->glGetVertexAttribLdv = (PFNGLGETVERTEXATTRIBLDVPROC) pLoad("glGetVertexAttribLdv");
	pApi->glViewportArrayv = (PFNGLVIEWPORTARRAYVPROC) pLoad("glViewportArrayv");
	pApi->glViewportIndexedf = (PFNGLVIEWPORTINDEXEDFPROC) pLoad("glViewportIndexedf");
	pApi->glViewportIndexedfv = (PFNGLVIEWPORTINDEXEDFVPROC) pLoad("glViewportIndexedfv");
	pApi->glScissorArrayv = (PFNGLSCISSORARRAYVPROC) pLoad("glScissorArrayv");
	pApi->glScissorIndexed = (PFNGLSCISSORINDEXEDPROC) pLoad("glScissorIndexed");
	pApi->glScissorIndexedv = (PFNGLSCISSORINDEXEDVPROC) pLoad("glScissorIndexedv");
	pApi->glDepthRangeArrayv = (PFNGLDEPTHRANGEARRAYVPROC) pLoad("glDepthRangeArrayv");
	pApi->glDepthRangeIndexed = (PFNGLDEPTHRANGEINDEXEDPROC) pLoad("glDepthRangeIndexed");
	pApi->glGetFloati_v = (PFNGLGETFLOATI_VPROC) pLoad("glGetFloati_v");
	pApi->glGetDoublei_v = (PFNGLGETDOUBLEI_VPROC) pLoad("glGetDoublei_v");
	pApi->glDrawArraysInstancedBaseInstance = (PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC) pLoad("glDrawArraysInstancedBaseInstance");
	pApi->glDrawElementsInstancedBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC) pLoad("glDrawElementsInstancedBaseInstance");
	pApi->glDrawElementsInstancedBaseVertexBaseInstance = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC) pLoad("glDrawElementsInstancedBaseVertexBaseInstance");
	pApi->glGetInternalformativ = (PFNGLGETINTERNALFORMATIVPROC) pLoad("glGetInternalformativ");
	pApi->glGetActiveAtomicCounterBufferiv = (PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC) pLoad("glGetActiveAtomicCounterBufferiv");
	pApi->glBindImageTexture = (PFNGLBINDIMAGETEXTUREPROC) pLoad("glBindImageTexture");
	pApi->glMemoryBarrier = (PFNGLMEMORYBARRIERPROC) pLoad("glMemoryBarrier");
	pApi->glTexStorage1D = (PFNGLTEXSTORAGE1DPROC) pLoad("glTexStorage1D");
	pApi->glTexStorage2D = (PFNGLTEXSTORAGE2DPROC) pLoad("glTexStorage2D");
	pApi->glTexStorage3D = (PFNGLTEXSTORAGE3DPROC) pLoad("glTexStorage3D");
	pApi->glDrawTransformFeedbackInstanced = (PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC) pLoad("glDrawTransformFeedbackInstanced");
	pApi->glDrawTransformFeedbackStreamInstanced = (PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC) pLoad("glDrawTransformFeedbackStreamInstanced");
	pApi->glClearBufferData = (PFNGLCLEARBUFFERDATAPROC) pLoad("glClearBufferData");
	pApi->glClearBufferSubData = (PFNGLCLEARBUFFERSUBDATAPROC) pLoad("glClearBufferSubData");
	pApi->glDispatchCompute = (PFNGLDISPATCHCOMPUTEPROC) pLoad("glDispatchCompute");
	pApi->glDispatchComputeIndirect = (PFNGLDISPATCHCOMPUTEINDIRECTPROC) pLoad("glDispatchComputeIndirect");
	pApi->glCopyImageSubData = (PFNGLCOPYIMAGESUBDATAPROC) pLoad("glCopyImageSubData");
	pApi->glFramebufferParameteri = (PFNGLFRAMEBUFFERPARAMETERIPROC) pLoad("glFramebufferParameteri");
	pApi->glGetFramebufferParameteriv = (PFNGLGETFRAMEBUFFERPARAMETERIVPROC) pLoad("glGetFramebufferParameteriv");
	pApi->glGetInternalformati64v = (PFNGLGETINTERNALFORMATI64VPROC) pLoad("glGetInternalformati64v");
	pApi->glInvalidateTexSubImage = (PFNGLINVALIDATETEXSUBIMAGEPROC) pLoad("glInvalidateTexSubImage");
	pApi->glInvalidateTexImage = (PFNGLINVALIDATETEXIMAGEPROC) pLoad("glInvalidateTexImage");
	pApi->glInvalidateBufferSubData = (PFNGLINVALIDATEBUFFERSUBDATAPROC) pLoad("glInvalidateBufferSubData");
	pApi->glInvalidateBufferData = (PFNGLINVALIDATEBUFFERDATAPROC) pLoad("glInvalidateBufferData");
	pApi->glInvalidateFramebuffer = (PFNGLINVALIDATEFRAMEBUFFERPROC) pLoad("glInvalidateFramebuffer");
	pApi->glInvalidateSubFramebuffer = (PFNGLINVALIDATESUBFRAMEBUFFERPROC) pLoad("glInvalidateSubFramebuffer");
	pApi->glMultiDrawArraysIndirect = (PFNGLMULTIDRAWARRAYSINDIRECTPROC) pLoad("glMultiDrawArraysIndirect");
	pApi->glMultiDrawElementsIndirect = (PFNGLMULTIDRAWELEMENTSINDIRECTPROC) pLoad("glMultiDrawElementsIndirect");
	pApi->glGetProgramInterfaceiv = (PFNGLGETPROGRAMINTERFACEIVPROC) pLoad("glGetProgramInterfaceiv");
	pApi->glGetProgramResourceIndex = (PFNGLGETPROGRAMRESOURCEINDEXPROC) pLoad("glGetProgramResourceIndex");
	pApi->glGetProgramResourceName = (PFNGLGETPROGRAMRESOURCENAMEPROC) pLoad("glGetProgramResourceName");
	pApi->glGetProgramResourceiv = (PFNGLGETPROGRAMRESOURCEIVPROC) pLoad("glGetProgramResourceiv");
	pApi->glGetProgramResourceLocation = (PFNGLGETPROGRAMRESOURCELOCATIONPROC) pLoad("glGetProgramResourceLocation");
	pApi->glGetProgramResourceLocationIndex = (PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC) pLoad("glGetProgramResourceLocationIndex");
	pApi->glShaderStorageBlockBinding = (PFNGLSHADERSTORAGEBLOCKBINDINGPROC) pLoad("glShaderStorageBlockBinding");
	pApi->glTexBufferRange = (PFNGLTEXBUFFERRANGEPROC) pLoad("glTexBufferRange");
	pApi->glTexStorage2DMultisample = (PFNGLTEXSTORAGE2DMULTISAMPLEPROC) pLoad("glTexStorage2DMultisample");
	pApi->glTexStorage3DMultisample = (PFNGLTEXSTORAGE3DMULTISAMPLEPROC) pLoad("glTexStorage3DMultisample");
	pApi->glTextureView = (PFNGLTEXTUREVIEWPROC) pLoad("glTextureView");
	pApi->glBindVertexBuffer = (PFNGLBINDVERTEXBUFFERPROC) pLoad("glBindVertexBuffer");
	pApi->glVertexAttribFormat = (PFNGLVERTEXATTRIBFORMATPROC) pLoad("glVertexAttribFormat");
	pApi->glVertexAttribIFormat = (PFNGLVERTEXATTRIBIFORMATPROC) pLoad("glVertexAttribIFormat");
	pApi->glVertexAttribLFormat = (PFNGLVERTEXATTRIBLFORMATPROC) pLoad("glVertexAttribLFormat");
	pApi->glVertexAttribBinding = (PFNGLVERTEXATTRIBBINDINGPROC) pLoad("glVertexAttribBinding");
	pApi->glVertexBindingDivisor = (PFNGLVERTEXBINDINGDIVISORPROC) pLoad("glVertexBindingDivisor");
	pApi->glDebugMessageControl = (PFNGLDEBUGMESSAGECONTROLPROC) pLoad("glDebugMessageControl");
	pApi->glDebugMessageInsert = (PFNGLDEBUGMESSAGEINSERTPROC) pLoad("glDebugMessageInsert");
	pApi->glDebugMessageCallback = (PFNGLDEBUGMESSAGECALLBACKPROC) pLoad("glDebugMessageCallback");
	pApi->glGetDebugMessageLog = (PFNGLGETDEBUGMESSAGELOGPROC) pLoad("glGetDebugMessageLog");
	pApi->glPushDebugGroup = (PFNGLPUSHDEBUGGROUPPROC) pLoad("glPushDebugGroup");
	pApi->glPopDebugGroup = (PFNGLPOPDEBUGGROUPPROC) pLoad("glPopDebugGroup");
	pApi->glObjectLabel = (PFNGLOBJECTLABELPROC) pLoad("glObjectLabel");
	pApi->glGetObjectLabel = (PFNGLGETOBJECTLABELPROC) pLoad("glGetObjectLabel");
	pApi->glObjectPtrLabel = (PFNGLOBJECTPTRLABELPROC) pLoad("glObjectPtrLabel");
	pApi->glGetObjectPtrLabel = (PFNGLGETOBJECTPTRLABELPROC) pLoad("glGetObjectPtrLabel");
	pApi->glBufferStorage = (PFNGLBUFFERSTORAGEPROC) pLoad("glBufferStorage");
	pApi->glClearTexImage = (PFNGLCLEARTEXIMAGEPROC) pLoad("glClearTexImage");
	pApi->glClearTexSubImage = (PFNGLCLEARTEXSUBIMAGEPROC) pLoad("glClearTexSubImage");
	pApi->glBindBuffersBase = (PFNGLBINDBUFFERSBASEPROC) pLoad("glBindBuffersBase");
	pApi->glBindBuffersRange = (PFNGLBINDBUFFERSRANGEPROC) pLoad("glBindBuffersRange");
	pApi->glBindTextures = (PFNGLBINDTEXTURESPROC) pLoad("glBindTextures");
	pApi->glBindSamplers = (PFNGLBINDSAMPLERSPROC) pLoad("glBindSamplers");
	pApi->glBindImageTextures = (PFNGLBINDIMAGETEXTURESPROC) pLoad("glBindImageTextures");
	pApi->glBindVertexBuffers = (PFNGLBINDVERTEXBUFFERSPROC) pLoad("glBindVertexBuffers");
	pApi->glClipControl = (PFNGLCLIPCONTROLPROC) pLoad("glClipControl");
	pApi->glCreateTransformFeedbacks = (PFNGLCREATETRANSFORMFEEDBACKSPROC) pLoad("glCreateTransformFeedbacks");
	pApi->glTransformFeedbackBufferBase = (PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC) pLoad("glTransformFeedbackBufferBase");
	pApi->glTransformFeedbackBufferRange = (PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC) pLoad("glTransformFeedbackBufferRange");
	pApi->glGetTransformFeedbackiv = (PFNGLGETTRANSFORMFEEDBACKIVPROC) pLoad("glGetTransformFeedbackiv");
	pApi->glGetTransformFeedbacki_v = (PFNGLGETTRANSFORMFEEDBACKI_VPROC) pLoad("glGetTransformFeedbacki_v");
	pApi->glGetTransformFeedbacki64_v = (PFNGLGETTRANSFORMFEEDBACKI64_VPROC) pLoad("glGetTransformFeedbacki64_v");
	pApi->glCreateBuffers = (PFNGLCREATEBUFFERSPROC) pLoad("glCreateBuffers");
	pApi->glNamedBufferStorage = (PFNGLNAMEDBUFFERSTORAGEPROC) pLoad("glNamedBufferStorage");
	pApi->glNamedBufferData = (PFNGLNAMEDBUFFERDATAPROC) pLoad("glNamedBufferData");
	pApi->glNamedBufferSubData = (PFNGLNAMEDBUFFERSUBDATAPROC) pLoad("glNamedBufferSubData");
	pApi->glCopyNamedBufferSubData = (PFNGLCOPYNAMEDBUFFERSUBDATAPROC) pLoad("glCopyNamedBufferSubData");
	pApi->glClearNamedBufferData = (PFNGLCLEARNAMEDBUFFERDATAPROC) pLoad("glClearNamedBufferData");
	pApi->glClearNamedBufferSubData = (PFNGLCLEARNAMEDBUFFERSUBDATAPROC) pLoad("glClearNamedBufferSubData");
	pApi->glMapNamedBuffer = (PFNGLMAPNAMEDBUFFERPROC) pLoad("glMapNamedBuffer");
	pApi->glMapNamedBufferRange = (PFNGLMAPNAMEDBUFFERRANGEPROC) pLoad("glMapNamedBufferRange");
	pApi->glUnmapNamedBuffer = (PFNGLUNMAPNAMEDBUFFERPROC) pLoad("glUnmapNamedBuffer");
	pApi->glFlushMappedNamedBufferRange = (PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC) pLoad("glFlushMappedNamedBufferRange");
	pApi->glGetNamedBufferParameteriv = (PFNGLGETNAMEDBUFFERPARAMETERIVPROC) pLoad("glGetNamedBufferParameteriv");
	pApi->glGetNamedBufferParameteri64v = (PFNGLGETNAMEDBUFFERPARAMETERI64VPROC) pLoad("glGetNamedBufferParameteri64v");
	pApi->glGetNamedBufferPointerv = (PFNGLGETNAMEDBUFFERPOINTERVPROC) pLoad("glGetNamedBufferPointerv");
	pApi->glGetNamedBufferSubData = (PFNGLGETNAMEDBUFFERSUBDATAPROC) pLoad("glGetNamedBufferSubData");
	pApi->glCreateFramebuffers = (PFNGLCREATEFRAMEBUFFERSPROC) pLoad("glCreateFramebuffers");
	pApi->glNamedFramebufferRenderbuffer = (PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC) pLoad("glNamedFramebufferRenderbuffer");
	pApi->glNamedFramebufferParameteri = (PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC) pLoad("glNamedFramebufferParameteri");
	pApi->glNamedFramebufferTexture = (PFNGLNAMEDFRAMEBUFFERTEXTUREPROC) pLoad("glNamedFramebufferTexture");
	pApi->glNamedFramebufferTextureLayer = (PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC) pLoad("glNamedFramebufferTextureLayer");
	pApi->glNamedFramebufferDrawBuffer = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC) pLoad("glNamedFramebufferDrawBuffer");
	pApi->glNamedFramebufferDrawBuffers = (PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC) pLoad("glNamedFramebufferDrawBuffers");
	pApi->glNamedFramebufferReadBuffer = (PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC) pLoad("glNamedFramebufferReadBuffer");
	pApi->glInvalidateNamedFramebufferData = (PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC) pLoad("glInvalidateNamedFramebufferData");
	pApi->glInvalidateNamedFramebufferSubData = (PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC) pLoad("glInvalidateNamedFramebufferSubData");
	pApi->glClearNamedFramebufferiv = (PFNGLCLEARNAMEDFRAMEBUFFERIVPROC) pLoad("glClearNamedFramebufferiv");
	pApi->glClearNamedFramebufferuiv = (PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC) pLoad("glClearNamedFramebufferuiv");
	pApi->glClearNamedFramebufferfv = (PFNGLCLEARNAMEDFRAMEBUFFERFVPROC) pLoad("glClearNamedFramebufferfv");
	pApi->glClearNamedFramebufferfi = (PFNGLCLEARNAMEDFRAMEBUFFERFIPROC) pLoad("glClearNamedFramebufferfi");
	pApi->glBlitNamedFramebuffer = (PFNGLBLITNAMEDFRAMEBUFFERPROC) pLoad("glBlitNamedFramebuffer");
	pApi->glCheckNamedFramebufferStatus = (PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC) pLoad("glCheckNamedFramebufferStatus");
	pApi->glGetNamedFramebufferParameteriv = (PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC) pLoad("glGetNamedFramebufferParameteriv");
	pApi->glGetNamedFramebufferAttachmentParameteriv = (PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC) pLoad("glGetNamedFramebufferAttachmentParameteriv");
	pApi->glCreateRenderbuffers = (PFNGLCREATERENDERBUFFERSPROC) pLoad("glCreateRenderbuffers");
	pApi->glNamedRenderbufferStorage = (PFNGLNAMEDRENDERBUFFERSTORAGEPROC) pLoad("glNamedRenderbufferStorage");
	pApi->glNamedRenderbufferStorageMultisample = (PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC) pLoad("glNamedRenderbufferStorageMultisample");
	pApi->glGetNamedRenderbufferParameteriv = (PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC) pLoad("glGetNamedRenderbufferParameteriv");
	pApi->glCreateTextures = (PFNGLCREATETEXTURESPROC) pLoad("glCreateTextures");
	pApi->glTextureBuffer = (PFNGLTEXTUREBUFFERPROC) pLoad("glTextureBuffer");
	pApi->glTextureBufferRange = (PFNGLTEXTUREBUFFERRANGEPROC) pLoad("glTextureBufferRange");
	pApi->glTextureStorage1D = (PFNGLTEXTURESTORAGE1DPROC) pLoad("glTextureStorage1D");
	pApi->glTextureStorage2D = (PFNGLTEXTURESTORAGE2DPROC) pLoad("glTextureStorage2D");
	pApi->glTextureStorage3D = (PFNGLTEXTURESTORAGE3DPROC) pLoad("glTextureStorage3D");
	pApi->glTextureStorage2DMultisample = (PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC) pLoad("glTextureStorage2DMultisample");
	pApi->glTextureStorage3DMultisample = (PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC) pLoad("glTextureStorage3DMultisample");
	pApi->glTextureSubImage1D = (PFNGLTEXTURESUBIMAGE1DPROC) pLoad("glTextureSubImage1D");
	pApi->glTextureSubImage2D = (PFNGLTEXTURESUBIMAGE2DPROC) pLoad("glTextureSubImage2D");
	pApi->glTextureSubImage3D = (PFNGLTEXTURESUBIMAGE3DPROC) pLoad("glTextureSubImage3D");
	pApi->glCompressedTextureSubImage1D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC) pLoad("glCompressedTextureSubImage1D");
	pApi->glCompressedTextureSubImage2D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC) pLoad("glCompressedTextureSubImage2D");
	pApi->glCompressedTextureSubImage3D = (PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC) pLoad("glCompressedTextureSubImage3D");
	pApi->glCopyTextureSubImage1D = (PFNGLCOPYTEXTURESUBIMAGE1DPROC) pLoad("glCopyTextureSubImage1D");
	pApi->glCopyTextureSubImage2D = (PFNGLCOPYTEXTURESUBIMAGE2DPROC) pLoad("glCopyTextureSubImage2D");
	pApi->glCopyTextureSubImage3D = (PFNGLCOPYTEXTURESUBIMAGE3DPROC) pLoad("glCopyTextureSubImage3D");
	pApi->glTextureParameterf = (PFNGLTEXTUREPARAMETERFPROC) pLoad("glTextureParameterf");
	pApi->glTextureParameterfv = (PFNGLTEXTUREPARAMETERFVPROC) pLoad("glTextureParameterfv");
	pApi->glTextureParameteri = (PFNGLTEXTUREPARAMETERIPROC) pLoad("glTextureParameteri");
	pApi->glTextureParameterIiv = (PFNGLTEXTUREPARAMETERIIVPROC) pLoad("glTextureParameterIiv");
	pApi->glTextureParameterIuiv = (PFNGLTEXTUREPARAMETERIUIVPROC) pLoad("glTextureParameterIuiv");
	pApi->glTextureParameteriv = (PFNGLTEXTUREPARAMETERIVPROC) pLoad("glTextureParameteriv");
	pApi->glGenerateTextureMipmap = (PFNGLGENERATETEXTUREMIPMAPPROC) pLoad("glGenerateTextureMipmap");
	pApi->glBindTextureUnit = (PFNGLBINDTEXTUREUNITPROC) pLoad("glBindTextureUnit");
	pApi->glGetTextureImage = (PFNGLGETTEXTUREIMAGEPROC) pLoad("glGetTextureImage");
	pApi->glGetCompressedTextureImage = (PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC) pLoad("glGetCompressedTextureImage");
	pApi->glGetTextureLevelParameterfv = (PFNGLGETTEXTURELEVELPARAMETERFVPROC) pLoad("glGetTextureLevelParameterfv");
	pApi->glGetTextureLevelParameteriv = (PFNGLGETTEXTURELEVELPARAMETERIVPROC) pLoad("glGetTextureLevelParameteriv");
	pApi->glGetTextureParameterfv = (PFNGLGETTEXTUREPARAMETERFVPROC) pLoad("glGetTextureParameterfv");
	pApi->glGetTextureParameterIiv = (PFNGLGETTEXTUREPARAMETERIIVPROC) pLoad("glGetTextureParameterIiv");
	pApi->glGetTextureParameterIuiv = (PFNGLGETTEXTUREPARAMETERIUIVPROC) pLoad("glGetTextureParameterIuiv");
	pApi->glGetTextureParameteriv = (PFNGLGETTEXTUREPARAMETERIVPROC) pLoad("glGetTextureParameteriv");
	pApi->glCreateVertexArrays = (PFNGLCREATEVERTEXARRAYSPROC) pLoad("glCreateVertexArrays");
	pApi->glDisableVertexArrayAttrib = (PFNGLDISABLEVERTEXARRAYATTRIBPROC) pLoad("glDisableVertexArrayAttrib");
	pApi->glEnableVertexArrayAttrib = (PFNGLENABLEVERTEXARRAYATTRIBPROC) pLoad("glEnableVertexArrayAttrib");
	pApi->glVertexArrayElementBuffer = (PFNGLVERTEXARRAYELEMENTBUFFERPROC) pLoad("glVertexArrayElementBuffer");
	pApi->glVertexArrayVertexBuffer = (PFNGLVERTEXARRAYVERTEXBUFFERPROC) pLoad("glVertexArrayVertexBuffer");
	pApi->glVertexArrayVertexBuffers = (PFNGLVERTEXARRAYVERTEXBUFFERSPROC) pLoad("glVertexArrayVertexBuffers");
	pApi->glVertexArrayAttribBinding = (PFNGLVERTEXARRAYATTRIBBINDINGPROC) pLoad("glVertexArrayAttribBinding");
	pApi->glVertexArrayAttribFormat = (PFNGLVERTEXARRAYATTRIBFORMATPROC) pLoad("glVertexArrayAttribFormat");
	pApi->glVertexArrayAttribIFormat = (PFNGLVERTEXARRAYATTRIBIFORMATPROC) pLoad("glVertexArrayAttribIFormat");
	pApi->glVertexArrayAttribLFormat = (PFNGLVERTEXARRAYATTRIBLFORMATPROC) pLoad("glVertexArrayAttribLFormat");
	pApi->glVertexArrayBindingDivisor = (PFNGLVERTEXARRAYBINDINGDIVISORPROC) pLoad("glVertexArrayBindingDivisor");
	pApi->glGetVertexArrayiv = (PFNGLGETVERTEXARRAYIVPROC) pLoad("glGetVertexArrayiv");
	pApi->glGetVertexArrayIndexediv = (PFNGLGETVERTEXARRAYINDEXEDIVPROC) pLoad("glGetVertexArrayIndexediv");
	pApi->glGetVertexArrayIndexed64iv = (PFNGLGETVERTEXARRAYINDEXED64IVPROC) pLoad("glGetVertexArrayIndexed64iv");
	pApi->glCreateSamplers = (PFNGLCREATESAMPLERSPROC) pLoad("glCreateSamplers");
	pApi->glCreateProgramPipelines = (PFNGLCREATEPROGRAMPIPELINESPROC) pLoad("glCreateProgramPipelines");
	pApi->glCreateQueries = (PFNGLCREATEQUERIESPROC) pLoad("glCreateQueries");
	pApi->glGetQueryBufferObjecti64v = (PFNGLGETQUERYBUFFEROBJECTI64VPROC) pLoad("glGetQueryBufferObjecti64v");
	pApi->glGetQueryBufferObjectiv = (PFNGLGETQUERYBUFFEROBJECTIVPROC) pLoad("glGetQueryBufferObjectiv");
	pApi->glGetQueryBufferObjectui64v = (PFNGLGETQUERYBUFFEROBJECTUI64VPROC) pLoad("glGetQueryBufferObjectui64v");
	pApi->glGetQueryBufferObjectuiv = (PFNGLGETQUERYBUFFEROBJECTUIVPROC) pLoad("glGetQueryBufferObjectuiv");
	pApi->glMemoryBarrierByRegion = (PFNGLMEMORYBARRIERBYREGIONPROC) pLoad("glMemoryBarrierByRegion");
	pApi->glGetTextureSubImage = (PFNGLGETTEXTURESUBIMAGEPROC) pLoad("glGetTextureSubImage");
	pApi->glGetCompressedTextureSubImage = (PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC) pLoad("glGetCompressedTextureSubImage");
	pApi->glGetGraphicsResetStatus = (PFNGLGETGRAPHICSRESETSTATUSPROC) pLoad("glGetGraphicsResetStatus");
	pApi->glGetnCompressedTexImage = (PFNGLGETNCOMPRESSEDTEXIMAGEPROC) pLoad("glGetnCompressedTexImage");
	pApi->glGetnTexImage = (PFNGLGETNTEXIMAGEPROC) pLoad("glGetnTexImage");
	pApi->glGetnUniformdv = (PFNGLGETNUNIFORMDVPROC) pLoad("glGetnUniformdv");
	pApi->glGetnUniformfv = (PFNGLGETNUNIFORMFVPROC) pLoad("glGetnUniformfv");
	pApi->glGetnUniformiv = (PFNGLGETNUNIFORMIVPROC) pLoad("glGetnUniformiv");
	pApi->glGetnUniformuiv = (PFNGLGETNUNIFORMUIVPROC) pLoad("glGetnUniformuiv");
	pApi->glReadnPixels = (PFNGLREADNPIXELSPROC) pLoad("glReadnPixels");
	pApi->glGetnMapdv = (PFNGLGETNMAPDVPROC) pLoad("glGetnMapdv");
	pApi->glGetnMapfv = (PFNGLGETNMAPFVPROC) pLoad("glGetnMapfv");
	pApi->glGetnMapiv = (PFNGLGETNMAPIVPROC) pLoad("glGetnMapiv");
	pApi->glGetnPixelMapfv = (PFNGLGETNPIXELMAPFVPROC) pLoad("glGetnPixelMapfv");
	pApi->glGetnPixelMapuiv = (PFNGLGETNPIXELMAPUIVPROC) pLoad("glGetnPixelMapuiv");
	pApi->glGetnPixelMapusv = (PFNGLGETNPIXELMAPUSVPROC) pLoad("glGetnPixelMapusv");
	pApi->glGetnPolygonStipple = (PFNGLGETNPOLYGONSTIPPLEPROC) pLoad("glGetnPolygonStipple");
	pApi->glGetnColorTable = (PFNGLGETNCOLORTABLEPROC) pLoad("glGetnColorTable");
	pApi->glGetnConvolutionFilter = (PFNGLGETNCONVOLUTIONFILTERPROC) pLoad("glGetnConvolutionFilter");
	pApi->glGetnSeparableFilter = (PFNGLGETNSEPARABLEFILTERPROC) pLoad("glGetnSeparableFilter");
	pApi->glGetnHistogram = (PFNGLGETNHISTOGRAMPROC) pLoad("glGetnHistogram");
	pApi->glGetnMinmax = (PFNGLGETNMINMAXPROC) pLoad("glGetnMinmax");
	pApi->glTextureBarrier = (PFNGLTEXTUREBARRIERPROC) pLoad("glTextureBarrier");
	pApi->glSpecializeShader = (PFNGLSPECIALIZESHADERPROC) pLoad("glSpecializeShader");
	pApi->glMultiDrawArraysIndirectCount = (PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC) pLoad("glMultiDrawArraysIndirectCount");
	pApi->glMultiDrawElementsIndirectCount = (PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC) pLoad("glMultiDrawElementsIndirectCount");
	pApi->glPolygonOffsetClamp = (PFNGLPOLYGONOFFSETCLAMPPROC) pLoad("glPolygonOffsetClamp");
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
	glCullFace = pApi->glCullFace;
	glFrontFace = pApi->glFrontFace;
	glHint = pApi->glHint;
	glLineWidth = pApi->glLineWidth;
	glPointSize = pApi->glPointSize;
	glPolygonMode = pApi->glPolygonMode;
	glScissor = pApi->glScissor;
	glTexParameterf = pApi->glTexParameterf;
	glTexParameterfv = pApi->glTexParameterfv;
	glTexParameteri = pApi->glTexParameteri;
	glTexParameteriv = pApi->glTexParameteriv;
	glTexImage1D = pApi->glTexImage1D;
	glTexImage2D = pApi->glTexImage2D;
	glDrawBuffer = pApi->glDrawBuffer;
	glClear = pApi->glClear;
	glClearColor = pApi->glClearColor;
	glClearStencil = pApi->glClearStencil;
	glClearDepth = pApi->glClearDepth;
	glStencilMask = pApi->glStencilMask;
	glColorMask = pApi->glColorMask;
	glDepthMask = pApi->glDepthMask;
	glDisable = pApi->glDisable;
	glEnable = pApi->glEnable;
	glFinish = pApi->glFinish;
	glFlush = pApi->glFlush;
	glBlendFunc = pApi->glBlendFunc;
	glLogicOp = pApi->glLogicOp;
	glStencilFunc = pApi->glStencilFunc;
	glStencilOp = pApi->glStencilOp;
	glDepthFunc = pApi->glDepthFunc;
	glPixelStoref = pApi->glPixelStoref;
	glPixelStorei = pApi->glPixelStorei;
	glReadBuffer = pApi->glReadBuffer;
	glReadPixels = pApi->glReadPixels;
	glGetBooleanv = pApi->glGetBooleanv;
	glGetDoublev = pApi->glGetDoublev;
	glGetError = pApi->glGetError;
	glGetFloatv = pApi->glGetFloatv;
	glGetIntegerv = pApi->glGetIntegerv;
	glGetString = pApi->glGetString;
	glGetTexImage = pApi->glGetTexImage;
	glGetTexParameterfv = pApi->glGetTexParameterfv;
	glGetTexParameteriv = pApi->glGetTexParameteriv;
	glGetTexLevelParameterfv = pApi->glGetTexLevelParameterfv;
	glGetTexLevelParameteriv = pApi->glGetTexLevelParameteriv;
	glIsEnabled = pApi->glIsEnabled;
	glDepthRange = pApi->glDepthRange;
	glViewport = pApi->glViewport;
	glNewList = pApi->glNewList;
	glEndList = pApi->glEndList;
	glCallList = pApi->glCallList;
	glCallLists = pApi->glCallLists;
	glDeleteLists = pApi->glDeleteLists;
	glGenLists = pApi->glGenLists;
	glListBase = pApi->glListBase;
	glBegin = pApi->glBegin;
	glBitmap = pApi->glBitmap;
	glColor3b = pApi->glColor3b;
	glColor3bv = pApi->glColor3bv;
	glColor3d = pApi->glColor3d;
	glColor3dv = pApi->glColor3dv;
	glColor3f = pApi->glColor3f;
	glColor3fv = pApi->glColor3fv;
	glColor3i = pApi->glColor3i;
	glColor3iv = pApi->glColor3iv;
	glColor3s = pApi->glColor3s;
	glColor3sv = pApi->glColor3sv;
	glColor3ub = pApi->glColor3ub;
	glColor3ubv = pApi->glColor3ubv;
	glColor3ui = pApi->glColor3ui;
	glColor3uiv = pApi->glColor3uiv;
	glColor3us = pApi->glColor3us;
	glColor3usv = pApi->glColor3usv;
	glColor4b = pApi->glColor4b;
	glColor4bv = pApi->glColor4bv;
	glColor4d = pApi->glColor4d;
	glColor4dv = pApi->glColor4dv;
	glColor4f = pApi->glColor4f;
	glColor4fv = pApi->glColor4fv;
	glColor4i = pApi->glColor4i;
	glColor4iv = pApi->glColor4iv;
	glColor4s = pApi->glColor4s;
	glColor4sv = pApi->glColor4sv;
	glColor4ub = pApi->glColor4ub;
	glColor4ubv = pApi->glColor4ubv;
	glColor4ui = pApi->glColor4ui;
	glColor4uiv = pApi->glColor4uiv;
	glColor4us = pApi->glColor4us;
	glColor4usv = pApi->glColor4usv;
	glEdgeFlag = pApi->glEdgeFlag;
	glEdgeFlagv = pApi->glEdgeFlagv;
	glEnd = pApi->glEnd;
	glIndexd = pApi->glIndexd;
	glIndexdv = pApi->glIndexdv;
	glIndexf = pApi->glIndexf;
	glIndexfv = pApi->glIndexfv;
	glIndexi = pApi->glIndexi;
	glIndexiv = pApi->glIndexiv;
	glIndexs = pApi->glIndexs;
	glIndexsv = pApi->glIndexsv;
	glNormal3b = pApi->glNormal3b;
	glNormal3bv = pApi->glNormal3bv;
	glNormal3d = pApi->glNormal3d;
	glNormal3dv = pApi->glNormal3dv;
	glNormal3f = pApi->glNormal3f;
	glNormal3fv = pApi->glNormal3fv;
	glNormal3i = pApi->glNormal3i;
	glNormal3iv = pApi->glNormal3iv;
	glNormal3s = pApi->glNormal3s;
	glNormal3sv = pApi->glNormal3sv;
	glRasterPos2d = pApi->glRasterPos2d;
	glRasterPos2dv = pApi->glRasterPos2dv;
	glRasterPos2f = pApi->glRasterPos2f;
	glRasterPos2fv = pApi->glRasterPos2fv;
	glRasterPos2i = pApi->glRasterPos2i;
	glRasterPos2iv = pApi->glRasterPos2iv;
	glRasterPos2s = pApi->glRasterPos2s;
	glRasterPos2sv = pApi->glRasterPos2sv;
	glRasterPos3d = pApi->glRasterPos3d;
	glRasterPos3dv = pApi->glRasterPos3dv;
	glRasterPos3f = pApi->glRasterPos3f;
	glRasterPos3fv = pApi->glRasterPos3fv;
	glRasterPos3i = pApi->glRasterPos3i;
	glRasterPos3iv = pApi->glRasterPos3iv;
	glRasterPos3s = pApi->glRasterPos3s;
	glRasterPos3sv = pApi->glRasterPos3sv;
	glRasterPos4d = pApi->glRasterPos4d;
	glRasterPos4dv = pApi->glRasterPos4dv;
	glRasterPos4f = pApi->glRasterPos4f;
	glRasterPos4fv = pApi->glRasterPos4fv;
	glRasterPos4i = pApi->glRasterPos4i;
	glRasterPos4iv = pApi->glRasterPos4iv;
	glRasterPos4s = pApi->glRasterPos4s;
	glRasterPos4sv = pApi->glRasterPos4sv;
	glRectd = pApi->glRectd;
	glRectdv = pApi->glRectdv;
	glRectf = pApi->glRectf;
	glRectfv = pApi->glRectfv;
	glRecti = pApi->glRecti;
	glRectiv = pApi->glRectiv;
	glRects = pApi->glRects;
	glRectsv = pApi->glRectsv;
	glTexCoord1d = pApi->glTexCoord1d;
	glTexCoord1dv = pApi->glTexCoord1dv;
	glTexCoord1f = pApi->glTexCoord1f;
	glTexCoord1fv = pApi->glTexCoord1fv;
	glTexCoord1i = pApi->glTexCoord1i;
	glTexCoord1iv = pApi->glTexCoord1iv;
	glTexCoord1s = pApi->glTexCoord1s;
	glTexCoord1sv = pApi->glTexCoord1sv;
	glTexCoord2d = pApi->glTexCoord2d;
	glTexCoord2dv = pApi->glTexCoord2dv;
	glTexCoord2f = pApi->glTexCoord2f;
	glTexCoord2fv = pApi->glTexCoord2fv;
	glTexCoord2i = pApi->glTexCoord2i;
	glTexCoord2iv = pApi->glTexCoord2iv;
	glTexCoord2s = pApi->glTexCoord2s;
	glTexCoord2sv = pApi->glTexCoord2sv;
	glTexCoord3d = pApi->glTexCoord3d;
	glTexCoord3dv = pApi->glTexCoord3dv;
	glTexCoord3f = pApi->glTexCoord3f;
	glTexCoord3fv = pApi->glTexCoord3fv;
	glTexCoord3i = pApi->glTexCoord3i;
	glTexCoord3iv = pApi->glTexCoord3iv;
	glTexCoord3s = pApi->glTexCoord3s;
	glTexCoord3sv = pApi->glTexCoord3sv;
	glTexCoord4d = pApi->glTexCoord4d;
	glTexCoord4dv = pApi->glTexCoord4dv;
	glTexCoord4f = pApi->glTexCoord4f;
	glTexCoord4fv = pApi->glTexCoord4fv;
	glTexCoord4i = pApi->glTexCoord4i;
	glTexCoord4iv = pApi->glTexCoord4iv;
	glTexCoord4s = pApi->glTexCoord4s;
	glTexCoord4sv = pApi->glTexCoord4sv;
	glVertex2d = pApi->glVertex2d;
	glVertex2dv = pApi->glVertex2dv;
	glVertex2f = pApi->glVertex2f;
	glVertex2fv = pApi->glVertex2fv;
	glVertex2i = pApi->glVertex2i;
	glVertex2iv = pApi->glVertex2iv;
	glVertex2s = pApi->glVertex2s;
	glVertex2sv = pApi->glVertex2sv;
	glVertex3d = pApi->glVertex3d;
	glVertex3dv = pApi->glVertex3dv;
	glVertex3f = pApi->glVertex3f;
	glVertex3fv = pApi->glVertex3fv;
	glVertex3i = pApi->glVertex3i;
	glVertex3iv = pApi->glVertex3iv;
	glVertex3s = pApi->glVertex3s;
	glVertex3sv = pApi->glVertex3sv;
	glVertex4d = pApi->glVertex4d;
	glVertex4dv = pApi->glVertex4dv;
	glVertex4f = pApi->glVertex4f;
	glVertex4fv = pApi->glVertex4fv;
	glVertex4i = pApi->glVertex4i;
	glVertex4iv = pApi->glVertex4iv;
	glVertex4s = pApi->glVertex4s;
	glVertex4sv = pApi->glVertex4sv;
	glClipPlane = pApi->glClipPlane;
	glColorMaterial = pApi->glColorMaterial;
	glFogf = pApi->glFogf;
	glFogfv = pApi->glFogfv;
	glFogi = pApi->glFogi;
	glFogiv = pApi->glFogiv;
	glLightf = pApi->glLightf;
	glLightfv = pApi->glLightfv;
	glLighti = pApi->glLighti;
	glLightiv = pApi->glLightiv;
	glLightModelf = pApi->glLightModelf;
	glLightModelfv = pApi->glLightModelfv;
	glLightModeli = pApi->glLightModeli;
	glLightModeliv = pApi->glLightModeliv;
	glLineStipple = pApi->glLineStipple;
	glMaterialf = pApi->glMaterialf;
	glMaterialfv = pApi->glMaterialfv;
	glMateriali = pApi->glMateriali;
	glMaterialiv = pApi->glMaterialiv;
	glPolygonStipple = pApi->glPolygonStipple;
	glShadeModel = pApi->glShadeModel;
	glTexEnvf = pApi->glTexEnvf;
	glTexEnvfv = pApi->glTexEnvfv;
	glTexEnvi = pApi->glTexEnvi;
	glTexEnviv = pApi->glTexEnviv;
	glTexGend = pApi->glTexGend;
	glTexGendv = pApi->glTexGendv;
	glTexGenf = pApi->glTexGenf;
	glTexGenfv = pApi->glTexGenfv;
	glTexGeni = pApi->glTexGeni;
	glTexGeniv = pApi->glTexGeniv;
	glFeedbackBuffer = pApi->glFeedbackBuffer;
	glSelectBuffer = pApi->glSelectBuffer;
	glRenderMode = pApi->glRenderMode;
	glInitNames = pApi->glInitNames;
	glLoadName = pApi->glLoadName;
	glPassThrough = pApi->glPassThrough;
	glPopName = pApi->glPopName;
	glPushName = pApi->glPushName;
	glClearAccum = pApi->glClearAccum;
	glClearIndex = pApi->glClearIndex;
	glIndexMask = pApi->glIndexMask;
	glAccum = pApi->glAccum;
	glPopAttrib = pApi->glPopAttrib;
	glPushAttrib = pApi->glPushAttrib;
	glMap1d = pApi->glMap1d;
	glMap1f = pApi->glMap1f;
	glMap2d = pApi->glMap2d;
	glMap2f = pApi->glMap2f;
	glMapGrid1d = pApi->glMapGrid1d;
	glMapGrid1f = pApi->glMapGrid1f;
	glMapGrid2d = pApi->glMapGrid2d;
	glMapGrid2f = pApi->glMapGrid2f;
	glEvalCoord1d = pApi->glEvalCoord1d;
	glEvalCoord1dv = pApi->glEvalCoord1dv;
	glEvalCoord1f = pApi->glEvalCoord1f;
	glEvalCoord1fv = pApi->glEvalCoord1fv;
	glEvalCoord2d = pApi->glEvalCoord2d;
	glEvalCoord2dv = pApi->glEvalCoord2dv;
	glEvalCoord2f = pApi->glEvalCoord2f;
	glEvalCoord2fv = pApi->glEvalCoord2fv;
	glEvalMesh1 = pApi->glEvalMesh1;
	glEvalPoint1 = pApi->glEvalPoint1;
	glEvalMesh2 = pApi->glEvalMesh2;
	glEvalPoint2 = pApi->glEvalPoint2;
	glAlphaFunc = pApi->glAlphaFunc;
	glPixelZoom = pApi->glPixelZoom;
	glPixelTransferf = pApi->glPixelTransferf;
	glPixelTransferi = pApi->glPixelTransferi;
	glPixelMapfv = pApi->glPixelMapfv;
	glPixelMapuiv = pApi->glPixelMapuiv;
	glPixelMapusv = pApi->glPixelMapusv;
	glCopyPixels = pApi->glCopyPixels;
	glDrawPixels = pApi->glDrawPixels;
	glGetClipPlane = pApi->glGetClipPlane;
	glGetLightfv = pApi->glGetLightfv;
	glGetLightiv = pApi->glGetLightiv;
	glGetMapdv = pApi->glGetMapdv;
	glGetMapfv = pApi->glGetMapfv;
	glGetMapiv = pApi->glGetMapiv;
	glGetMaterialfv = pApi->glGetMaterialfv;
	glGetMaterialiv = pApi->glGetMaterialiv;
	glGetPixelMapfv = pApi->glGetPixelMapfv;
	glGetPixelMapuiv = pApi->glGetPixelMapuiv;
	glGetPixelMapusv = pApi->glGetPixelMapusv;
	glGetPolygonStipple = pApi->glGetPolygonStipple;
	glGetTexEnvfv = pApi->glGetTexEnvfv;
	glGetTexEnviv = pApi->glGetTexEnviv;
	glGetTexGendv = pApi->glGetTexGendv;
	glGetTexGenfv = pApi->glGetTexGenfv;
	glGetTexGeniv = pApi->glGetTexGeniv;
	glIsList = pApi->glIsList;
	glFrustum = pApi->glFrustum;
	glLoadIdentity = pApi->glLoadIdentity;
	glLoadMatrixf = pApi->glLoadMatrixf;
	glLoadMatrixd = pApi->glLoadMatrixd;
	glMatrixMode = pApi->glMatrixMode;
	glMultMatrixf = pApi->glMultMatrixf;
	glMultMatrixd = pApi->glMultMatrixd;
	glOrtho = pApi->glOrtho;
	glPopMatrix = pApi->glPopMatrix;
	glPushMatrix = pApi->glPushMatrix;
	glRotated = pApi->glRotated;
	glRotatef = pApi->glRotatef;
	glScaled = pApi->glScaled;
	glScalef = pApi->glScalef;
	glTranslated = pApi->glTranslated;
	glTranslatef = pApi->glTranslatef;
	glDrawArrays = pApi->glDrawArrays;
	glDrawElements = pApi->glDrawElements;
	glGetPointerv = pApi->glGetPointerv;
	glPolygonOffset = pApi->glPolygonOffset;
	glCopyTexImage1D = pApi->glCopyTexImage1D;
	glCopyTexImage2D = pApi->glCopyTexImage2D;
	glCopyTexSubImage1D = pApi->glCopyTexSubImage1D;
	glCopyTexSubImage2D = pApi->glCopyTexSubImage2D;
	glTexSubImage1D = pApi->glTexSubImage1D;
	glTexSubImage2D = pApi->glTexSubImage2D;
	glBindTexture = pApi->glBindTexture;
	glDeleteTextures = pApi->glDeleteTextures;
	glGenTextures = pApi->glGenTextures;
	glIsTexture = pApi->glIsTexture;
	glArrayElement = pApi->glArrayElement;
	glColorPointer = pApi->glColorPointer;
	glDisableClientState = pApi->glDisableClientState;
	glEdgeFlagPointer = pApi->glEdgeFlagPointer;
	glEnableClientState = pApi->glEnableClientState;
	glIndexPointer = pApi->glIndexPointer;
	glInterleavedArrays = pApi->glInterleavedArrays;
	glNormalPointer = pApi->glNormalPointer;
	glTexCoordPointer = pApi->glTexCoordPointer;
	glVertexPointer = pApi->glVertexPointer;
	glAreTexturesResident = pApi->glAreTexturesResident;
	glPrioritizeTextures = pApi->glPrioritizeTextures;
	glIndexub = pApi->glIndexub;
	glIndexubv = pApi->glIndexubv;
	glPopClientAttrib = pApi->glPopClientAttrib;
	glPushClientAttrib = pApi->glPushClientAttrib;
	glDrawRangeElements = pApi->glDrawRangeElements;
	glTexImage3D = pApi->glTexImage3D;
	glTexSubImage3D = pApi->glTexSubImage3D;
	glCopyTexSubImage3D = pApi->glCopyTexSubImage3D;
	glActiveTexture = pApi->glActiveTexture;
	glSampleCoverage = pApi->glSampleCoverage;
	glCompressedTexImage3D = pApi->glCompressedTexImage3D;
	glCompressedTexImage2D = pApi->glCompressedTexImage2D;
	glCompressedTexImage1D = pApi->glCompressedTexImage1D;
	glCompressedTexSubImage3D = pApi->glCompressedTexSubImage3D;
	glCompressedTexSubImage2D = pApi->glCompressedTexSubImage2D;
	glCompressedTexSubImage1D = pApi->glCompressedTexSubImage1D;
	glGetCompressedTexImage = pApi->glGetCompressedTexImage;
	glClientActiveTexture = pApi->glClientActiveTexture;
	glMultiTexCoord1d = pApi->glMultiTexCoord1d;
	glMultiTexCoord1dv = pApi->glMultiTexCoord1dv;
	glMultiTexCoord1f = pApi->glMultiTexCoord1f;
	glMultiTexCoord1fv = pApi->glMultiTexCoord1fv;
	glMultiTexCoord1i = pApi->glMultiTexCoord1i;
	glMultiTexCoord1iv = pApi->glMultiTexCoord1iv;
	glMultiTexCoord1s = pApi->glMultiTexCoord1s;
	glMultiTexCoord1sv = pApi->glMultiTexCoord1sv;
	glMultiTexCoord2d = pApi->glMultiTexCoord2d;
	glMultiTexCoord2dv = pApi->glMultiTexCoord2dv;
	glMultiTexCoord2f = pApi->glMultiTexCoord2f;
	glMultiTexCoord2fv = pApi->glMultiTexCoord2fv;
	glMultiTexCoord2i = pApi->glMultiTexCoord2i;
	glMultiTexCoord2iv = pApi->glMultiTexCoord2iv;
	glMultiTexCoord2s = pApi->glMultiTexCoord2s;
	glMultiTexCoord2sv = pApi->glMultiTexCoord2sv;
	glMultiTexCoord3d = pApi->glMultiTexCoord3d;
	glMultiTexCoord3dv = pApi->glMultiTexCoord3dv;
	glMultiTexCoord3f = pApi->glMultiTexCoord3f;
	glMultiTexCoord3fv = pApi->glMultiTexCoord3fv;
	glMultiTexCoord3i = pApi->glMultiTexCoord3i;
	glMultiTexCoord3iv = pApi->glMultiTexCoord3iv;
	glMultiTexCoord3s = pApi->glMultiTexCoord3s;
	glMultiTexCoord3sv = pApi->glMultiTexCoord3sv;
	glMultiTexCoord4d = pApi->glMultiTexCoord4d;
	glMultiTexCoord4dv = pApi->glMultiTexCoord4dv;
	glMultiTexCoord4f = pApi->glMultiTexCoord4f;
	glMultiTexCoord4fv = pApi->glMultiTexCoord4fv;
	glMultiTexCoord4i = pApi->glMultiTexCoord4i;
	glMultiTexCoord4iv = pApi->glMultiTexCoord4iv;
	glMultiTexCoord4s = pApi->glMultiTexCoord4s;
	glMultiTexCoord4sv = pApi->glMultiTexCoord4sv;
	glLoadTransposeMatrixf = pApi->glLoadTransposeMatrixf;
	glLoadTransposeMatrixd = pApi->glLoadTransposeMatrixd;
	glMultTransposeMatrixf = pApi->glMultTransposeMatrixf;
	glMultTransposeMatrixd = pApi->glMultTransposeMatrixd;
	glBlendFuncSeparate = pApi->glBlendFuncSeparate;
	glMultiDrawArrays = pApi->glMultiDrawArrays;
	glMultiDrawElements = pApi->glMultiDrawElements;
	glPointParameterf = pApi->glPointParameterf;
	glPointParameterfv = pApi->glPointParameterfv;
	glPointParameteri = pApi->glPointParameteri;
	glPointParameteriv = pApi->glPointParameteriv;
	glFogCoordf = pApi->glFogCoordf;
	glFogCoordfv = pApi->glFogCoordfv;
	glFogCoordd = pApi->glFogCoordd;
	glFogCoorddv = pApi->glFogCoorddv;
	glFogCoordPointer = pApi->glFogCoordPointer;
	glSecondaryColor3b = pApi->glSecondaryColor3b;
	glSecondaryColor3bv = pApi->glSecondaryColor3bv;
	glSecondaryColor3d = pApi->glSecondaryColor3d;
	glSecondaryColor3dv = pApi->glSecondaryColor3dv;
	glSecondaryColor3f = pApi->glSecondaryColor3f;
	glSecondaryColor3fv = pApi->glSecondaryColor3fv;
	glSecondaryColor3i = pApi->glSecondaryColor3i;
	glSecondaryColor3iv = pApi->glSecondaryColor3iv;
	glSecondaryColor3s = pApi->glSecondaryColor3s;
	glSecondaryColor3sv = pApi->glSecondaryColor3sv;
	glSecondaryColor3ub = pApi->glSecondaryColor3ub;
	glSecondaryColor3ubv = pApi->glSecondaryColor3ubv;
	glSecondaryColor3ui = pApi->glSecondaryColor3ui;
	glSecondaryColor3uiv = pApi->glSecondaryColor3uiv;
	glSecondaryColor3us = pApi->glSecondaryColor3us;
	glSecondaryColor3usv = pApi->glSecondaryColor3usv;
	glSecondaryColorPointer = pApi->glSecondaryColorPointer;
	glWindowPos2d = pApi->glWindowPos2d;
	glWindowPos2dv = pApi->glWindowPos2dv;
	glWindowPos2f = pApi->glWindowPos2f;
	glWindowPos2fv = pApi->glWindowPos2fv;
	glWindowPos2i = pApi->glWindowPos2i;
	glWindowPos2iv = pApi->glWindowPos2iv;
	glWindowPos2s = pApi->glWindowPos2s;
	glWindowPos2sv = pApi->glWindowPos2sv;
	glWindowPos3d = pApi->glWindowPos3d;
	glWindowPos3dv = pApi->glWindowPos3dv;
	glWindowPos3f = pApi->glWindowPos3f;
	glWindowPos3fv = pApi->glWindowPos3fv;
	glWindowPos3i = pApi->glWindowPos3i;
	glWindowPos3iv = pApi->glWindowPos3iv;
	glWindowPos3s = pApi->glWindowPos3s;
	glWindowPos3sv = pApi->glWindowPos3sv;
	glBlendColor = pApi->glBlendColor;
	glBlendEquation = pApi->glBlendEquation;
	glGenQueries = pApi->glGenQueries;
	glDeleteQueries = pApi->glDeleteQueries;
	glIsQuery = pApi->glIsQuery;
	glBeginQuery = pApi->glBeginQuery;
	glEndQuery = pApi->glEndQuery;
	glGetQueryiv = pApi->glGetQueryiv;
	glGetQueryObjectiv = pApi->glGetQueryObjectiv;
	glGetQueryObjectuiv = pApi->glGetQueryObjectuiv;
	glBindBuffer = pApi->glBindBuffer;
	glDeleteBuffers = pApi->glDeleteBuffers;
	glGenBuffers = pApi->glGenBuffers;
	glIsBuffer = pApi->glIsBuffer;
	glBufferData = pApi->glBufferData;
	glBufferSubData = pApi->glBufferSubData;
	glGetBufferSubData = pApi->glGetBufferSubData;
	glMapBuffer = pApi->glMapBuffer;
	glUnmapBuffer = pApi->glUnmapBuffer;
	glGetBufferParameteriv = pApi->glGetBufferParameteriv;
	glGetBufferPointerv = pApi->glGetBufferPointerv;
	glBlendEquationSeparate = pApi->glBlendEquationSeparate;
	glDrawBuffers = pApi->glDrawBuffers;
	glStencilOpSeparate = pApi->glStencilOpSeparate;
	glStencilFuncSeparate = pApi->glStencilFuncSeparate;
	glStencilMaskSeparate = pApi->glStencilMaskSeparate;
	glAttachShader = pApi->glAttachShader;
	glBindAttribLocation = pApi->glBindAttribLocation;
	glCompileShader = pApi->glCompileShader;
	glCreateProgram = pApi->glCreateProgram;
	glCreateShader = pApi->glCreateShader;
	glDeleteProgram = pApi->glDeleteProgram;
	glDeleteShader = pApi->glDeleteShader;
	glDetachShader = pApi->glDetachShader;
	glDisableVertexAttribArray = pApi->glDisableVertexAttribArray;
	glEnableVertexAttribArray = pApi->glEnableVertexAttribArray;
	glGetActiveAttrib = pApi->glGetActiveAttrib;
	glGetActiveUniform = pApi->glGetActiveUniform;
	glGetAttachedShaders = pApi->glGetAttachedShaders;
	glGetAttribLocation = pApi->glGetAttribLocation;
	glGetProgramiv = pApi->glGetProgramiv;
	glGetProgramInfoLog = pApi->glGetProgramInfoLog;
	glGetShaderiv = pApi->glGetShaderiv;
	glGetShaderInfoLog = pApi->glGetShaderInfoLog;
	glGetShaderSource = pApi->glGetShaderSource;
	glGetUniformLocation = pApi->glGetUniformLocation;
	glGetUniformfv = pApi->glGetUniformfv;
	glGetUniformiv = pApi->glGetUniformiv;
	glGetVertexAttribdv = pApi->glGetVertexAttribdv;
	glGetVertexAttribfv = pApi->glGetVertexAttribfv;
	glGetVertexAttribiv = pApi->glGetVertexAttribiv;
	glGetVertexAttribPointerv = pApi->glGetVertexAttribPointerv;
	glIsProgram = pApi->glIsProgram;
	glIsShader = pApi->glIsShader;
	glLinkProgram = pApi->glLinkProgram;
	glShaderSource = pApi->glShaderSource;
	glUseProgram = pApi->glUseProgram;
	glUniform1f = pApi->glUniform1f;
	glUniform2f = pApi->glUniform2f;
	glUniform3f = pApi->glUniform3f;
	glUniform4f = pApi->glUniform4f;
	glUniform1i = pApi->glUniform1i;
	glUniform2i = pApi->glUniform2i;
	glUniform3i = pApi->glUniform3i;
	glUniform4i = pApi->glUniform4i;
	glUniform1fv = pApi->glUniform1fv;
	glUniform2fv = pApi->glUniform2fv;
	glUniform3fv = pApi->glUniform3fv;
	glUniform4fv = pApi->glUniform4fv;
	glUniform1iv = pApi->glUniform1iv;
	glUniform2iv = pApi->glUniform2iv;
	glUniform3iv = pApi->glUniform3iv;
	glUniform4iv = pApi->glUniform4iv;
	glUniformMatrix2fv = pApi->glUniformMatrix2fv;
	glUniformMatrix3fv = pApi->glUniformMatrix3fv;
	glUniformMatrix4fv = pApi->glUniformMatrix4fv;
	glValidateProgram = pApi->glValidateProgram;
	glVertexAttrib1d = pApi->glVertexAttrib1d;
	glVertexAttrib1dv = pApi->glVertexAttrib1dv;
	glVertexAttrib1f = pApi->glVertexAttrib1f;
	glVertexAttrib1fv = pApi->glVertexAttrib1fv;
	glVertexAttrib1s = pApi->glVertexAttrib1s;
	glVertexAttrib1sv = pApi->glVertexAttrib1sv;
	glVertexAttrib2d = pApi->glVertexAttrib2d;
	glVertexAttrib2dv = pApi->glVertexAttrib2dv;
	glVertexAttrib2f = pApi->glVertexAttrib2f;
	glVertexAttrib2fv = pApi->glVertexAttrib2fv;
	glVertexAttrib2s = pApi->glVertexAttrib2s;
	glVertexAttrib2sv = pApi->glVertexAttrib2sv;
	glVertexAttrib3d = pApi->glVertexAttrib3d;
	glVertexAttrib3dv = pApi->glVertexAttrib3dv;
	glVertexAttrib3f = pApi->glVertexAttrib3f;
	glVertexAttrib3fv = pApi->glVertexAttrib3fv;
	glVertexAttrib3s = pApi->glVertexAttrib3s;
	glVertexAttrib3sv = pApi->glVertexAttrib3sv;
	glVertexAttrib4Nbv = pApi->glVertexAttrib4Nbv;
	glVertexAttrib4Niv = pApi->glVertexAttrib4Niv;
	glVertexAttrib4Nsv = pApi->glVertexAttrib4Nsv;
	glVertexAttrib4Nub = pApi->glVertexAttrib4Nub;
	glVertexAttrib4Nubv = pApi->glVertexAttrib4Nubv;
	glVertexAttrib4Nuiv = pApi->glVertexAttrib4Nuiv;
	glVertexAttrib4Nusv = pApi->glVertexAttrib4Nusv;
	glVertexAttrib4bv = pApi->glVertexAttrib4bv;
	glVertexAttrib4d = pApi->glVertexAttrib4d;
	glVertexAttrib4dv = pApi->glVertexAttrib4dv;
	glVertexAttrib4f = pApi->glVertexAttrib4f;
	glVertexAttrib4fv = pApi->glVertexAttrib4fv;
	glVertexAttrib4iv = pApi->glVertexAttrib4iv;
	glVertexAttrib4s = pApi->glVertexAttrib4s;
	glVertexAttrib4sv = pApi->glVertexAttrib4sv;
	glVertexAttrib4ubv = pApi->glVertexAttrib4ubv;
	glVertexAttrib4uiv = pApi->glVertexAttrib4uiv;
	glVertexAttrib4usv = pApi->glVertexAttrib4usv;
	glVertexAttribPointer = pApi->glVertexAttribPointer;
	glUniformMatrix2x3fv = pApi->glUniformMatrix2x3fv;
	glUniformMatrix3x2fv = pApi->glUniformMatrix3x2fv;
	glUniformMatrix2x4fv = pApi->glUniformMatrix2x4fv;
	glUniformMatrix4x2fv = pApi->glUniformMatrix4x2fv;
	glUniformMatrix3x4fv = pApi->glUniformMatrix3x4fv;
	glUniformMatrix4x3fv = pApi->glUniformMatrix4x3fv;
	glColorMaski = pApi->glColorMaski;
	glGetBooleani_v = pApi->glGetBooleani_v;
	glGetIntegeri_v = pApi->glGetIntegeri_v;
	glEnablei = pApi->glEnablei;
	glDisablei = pApi->glDisablei;
	glIsEnabledi = pApi->glIsEnabledi;
	glBeginTransformFeedback = pApi->glBeginTransformFeedback;
	glEndTransformFeedback = pApi->glEndTransformFeedback;
	glBindBufferRange = pApi->glBindBufferRange;
	glBindBufferBase = pApi->glBindBufferBase;
	glTransformFeedbackVaryings = pApi->glTransformFeedbackVaryings;
	glGetTransformFeedbackVarying = pApi->glGetTransformFeedbackVarying;
	glClampColor = pApi->glClampColor;
	glBeginConditionalRender = pApi->glBeginConditionalRender;
	glEndConditionalRender = pApi->glEndConditionalRender;
	glVertexAttribIPointer = pApi->glVertexAttribIPointer;
	glGetVertexAttribIiv = pApi->glGetVertexAttribIiv;
	glGetVertexAttribIuiv = pApi->glGetVertexAttribIuiv;
	glVertexAttribI1i = pApi->glVertexAttribI1i;
	glVertexAttribI2i = pApi->glVertexAttribI2i;
	glVertexAttribI3i = pApi->glVertexAttribI3i;
	glVertexAttribI4i = pApi->glVertexAttribI4i;
	glVertexAttribI1ui = pApi->glVertexAttribI1ui;
	glVertexAttribI2ui = pApi->glVertexAttribI2ui;
	glVertexAttribI3ui = pApi->glVertexAttribI3ui;
	glVertexAttribI4ui = pApi->glVertexAttribI4ui;
	glVertexAttribI1iv = pApi->glVertexAttribI1iv;
	glVertexAttribI2iv = pApi->glVertexAttribI2iv;
	glVertexAttribI3iv = pApi->glVertexAttribI3iv;
	glVertexAttribI4iv = pApi->glVertexAttribI4iv;
	glVertexAttribI1uiv = pApi->glVertexAttribI1uiv;
	glVertexAttribI2uiv = pApi->glVertexAttribI2uiv;
	glVertexAttribI3uiv = pApi->glVertexAttribI3uiv;
	glVertexAttribI4uiv = pApi->glVertexAttribI4uiv;
	glVertexAttribI4bv = pApi->glVertexAttribI4bv;
	glVertexAttribI4sv = pApi->glVertexAttribI4sv;
	glVertexAttribI4ubv = pApi->glVertexAttribI4ubv;
	glVertexAttribI4usv = pApi->glVertexAttribI4usv;
	glGetUniformuiv = pApi->glGetUniformuiv;
	glBindFragDataLocation = pApi->glBindFragDataLocation;
	glGetFragDataLocation = pApi->glGetFragDataLocation;
	glUniform1ui = pApi->glUniform1ui;
	glUniform2ui = pApi->glUniform2ui;
	glUniform3ui = pApi->glUniform3ui;
	glUniform4ui = pApi->glUniform4ui;
	glUniform1uiv = pApi->glUniform1uiv;
	glUniform2uiv = pApi->glUniform2uiv;
	glUniform3uiv = pApi->glUniform3uiv;
	glUniform4uiv = pApi->glUniform4uiv;
	glTexParameterIiv = pApi->glTexParameterIiv;
	glTexParameterIuiv = pApi->glTexParameterIuiv;
	glGetTexParameterIiv = pApi->glGetTexParameterIiv;
	glGetTexParameterIuiv = pApi->glGetTexParameterIuiv;
	glClearBufferiv = pApi->glClearBufferiv;
	glClearBufferuiv = pApi->glClearBufferuiv;
	glClearBufferfv = pApi->glClearBufferfv;
	glClearBufferfi = pApi->glClearBufferfi;
	glGetStringi = pApi->glGetStringi;
	glIsRenderbuffer = pApi->glIsRenderbuffer;
	glBindRenderbuffer = pApi->glBindRenderbuffer;
	glDeleteRenderbuffers = pApi->glDeleteRenderbuffers;
	glGenRenderbuffers = pApi->glGenRenderbuffers;
	glRenderbufferStorage = pApi->glRenderbufferStorage;
	glGetRenderbufferParameteriv = pApi->glGetRenderbufferParameteriv;
	glIsFramebuffer = pApi->glIsFramebuffer;
	glBindFramebuffer = pApi->glBindFramebuffer;
	glDeleteFramebuffers = pApi->glDeleteFramebuffers;
	glGenFramebuffers = pApi->glGenFramebuffers;
	glCheckFramebufferStatus = pApi->glCheckFramebufferStatus;
	glFramebufferTexture1D = pApi->glFramebufferTexture1D;
	glFramebufferTexture2D = pApi->glFramebufferTexture2D;
	glFramebufferTexture3D = pApi->glFramebufferTexture3D;
	glFramebufferRenderbuffer = pApi->glFramebufferRenderbuffer;
	glGetFramebufferAttachmentParameteriv = pApi->glGetFramebufferAttachmentParameteriv;
	glGenerateMipmap = pApi->glGenerateMipmap;
	glBlitFramebuffer = pApi->glBlitFramebuffer;
	glRenderbufferStorageMultisample = pApi->glRenderbufferStorageMultisample;
	glFramebufferTextureLayer = pApi->glFramebufferTextureLayer;
	glMapBufferRange = pApi->glMapBufferRange;
	glFlushMappedBufferRange = pApi->glFlushMappedBufferRange;
	glBindVertexArray = pApi->glBindVertexArray;
	glDeleteVertexArrays = pApi->glDeleteVertexArrays;
	glGenVertexArrays = pApi->glGenVertexArrays;
	glIsVertexArray = pApi->glIsVertexArray;
	glDrawArraysInstanced = pApi->glDrawArraysInstanced;
	glDrawElementsInstanced = pApi->glDrawElementsInstanced;
	glTexBuffer = pApi->glTexBuffer;
	glPrimitiveRestartIndex = pApi->glPrimitiveRestartIndex;
	glCopyBufferSubData = pApi->glCopyBufferSubData;
	glGetUniformIndices = pApi->glGetUniformIndices;
	glGetActiveUniformsiv = pApi->glGetActiveUniformsiv;
	glGetActiveUniformName = pApi->glGetActiveUniformName;
	glGetUniformBlockIndex = pApi->glGetUniformBlockIndex;
	glGetActiveUniformBlockiv = pApi->glGetActiveUniformBlockiv;
	glGetActiveUniformBlockName = pApi->glGetActiveUniformBlockName;
	glUniformBlockBinding = pApi->glUniformBlockBinding;
	glDrawElementsBaseVertex = pApi->glDrawElementsBaseVertex;
	glDrawRangeElementsBaseVertex = pApi->glDrawRangeElementsBaseVertex;
	glDrawElementsInstancedBaseVertex = pApi->glDrawElementsInstancedBaseVertex;
	glMultiDrawElementsBaseVertex = pApi->glMultiDrawElementsBaseVertex;
	glProvokingVertex = pApi->glProvokingVertex;
	glFenceSync = pApi->glFenceSync;
	glIsSync = pApi->glIsSync;
	glDeleteSync = pApi->glDeleteSync;
	glClientWaitSync = pApi->glClientWaitSync;
	glWaitSync = pApi->glWaitSync;
	glGetInteger64v = pApi->glGetInteger64v;
	glGetSynciv = pApi->glGetSynciv;
	glGetInteger64i_v = pApi->glGetInteger64i_v;
	glGetBufferParameteri64v = pApi->glGetBufferParameteri64v;
	glFramebufferTexture = pApi->glFramebufferTexture;
	glTexImage2DMultisample = pApi->glTexImage2DMultisample;
	glTexImage3DMultisample = pApi->glTexImage3DMultisample;
	glGetMultisamplefv = pApi->glGetMultisamplefv;
	glSampleMaski = pApi->glSampleMaski;
	glBindFragDataLocationIndexed = pApi->glBindFragDataLocationIndexed;
	glGetFragDataIndex = pApi->glGetFragDataIndex;
	glGenSamplers = pApi->glGenSamplers;
	glDeleteSamplers = pApi->glDeleteSamplers;
	glIsSampler = pApi->glIsSampler;
	glBindSampler = pApi->glBindSampler;
	glSamplerParameteri = pApi->glSamplerParameteri;
	glSamplerParameteriv = pApi->glSamplerParameteriv;
	glSamplerParameterf = pApi->glSamplerParameterf;
	glSamplerParameterfv = pApi->glSamplerParameterfv;
	glSamplerParameterIiv = pApi->glSamplerParameterIiv;
	glSamplerParameterIuiv = pApi->glSamplerParameterIuiv;
	glGetSamplerParameteriv = pApi->glGetSamplerParameteriv;
	glGetSamplerParameterIiv = pApi->glGetSamplerParameterIiv;
	glGetSamplerParameterfv = pApi->glGetSamplerParameterfv;
	glGetSamplerParameterIuiv = pApi->glGetSamplerParameterIuiv;
	glQueryCounter = pApi->glQueryCounter;
	glGetQueryObjecti64v = pApi->glGetQueryObjecti64v;
	glGetQueryObjectui64v = pApi->glGetQueryObjectui64v;
	glVertexAttribDivisor = pApi->glVertexAttribDivisor;
	glVertexAttribP1ui = pApi->glVertexAttribP1ui;
	glVertexAttribP1uiv = pApi->glVertexAttribP1uiv;
	glVertexAttribP2ui = pApi->glVertexAttribP2ui;
	glVertexAttribP2uiv = pApi->glVertexAttribP2uiv;
	glVertexAttribP3ui = pApi->glVertexAttribP3ui;
	glVertexAttribP3uiv = pApi->glVertexAttribP3uiv;
	glVertexAttribP4ui = pApi->glVertexAttribP4ui;
	glVertexAttribP4uiv = pApi->glVertexAttribP4uiv;
	glVertexP2ui = pApi->glVertexP2ui;
	glVertexP2uiv = pApi->glVertexP2uiv;
	glVertexP3ui = pApi->glVertexP3ui;
	glVertexP3uiv = pApi->glVertexP3uiv;
	glVertexP4ui = pApi->glVertexP4ui;
	glVertexP4uiv = pApi->glVertexP4uiv;
	glTexCoordP1ui = pApi->glTexCoordP1ui;
	glTexCoordP1uiv = pApi->glTexCoordP1uiv;
	glTexCoordP2ui = pApi->glTexCoordP2ui;
	glTexCoordP2uiv = pApi->glTexCoordP2uiv;
	glTexCoordP3ui = pApi->glTexCoordP3ui;
	glTexCoordP3uiv = pApi->glTexCoordP3uiv;
	glTexCoordP4ui = pApi->glTexCoordP4ui;
	glTexCoordP4uiv = pApi->glTexCoordP4uiv;
	glMultiTexCoordP1ui = pApi->glMultiTexCoordP1ui;
	glMultiTexCoordP1uiv = pApi->glMultiTexCoordP1uiv;
	glMultiTexCoordP2ui = pApi->glMultiTexCoordP2ui;
	glMultiTexCoordP2uiv = pApi->glMultiTexCoordP2uiv;
	glMultiTexCoordP3ui = pApi->glMultiTexCoordP3ui;
	glMultiTexCoordP3uiv = pApi->glMultiTexCoordP3uiv;
	glMultiTexCoordP4ui = pApi->glMultiTexCoordP4ui;
	glMultiTexCoordP4uiv = pApi->glMultiTexCoordP4uiv;
	glNormalP3ui = pApi->glNormalP3ui;
	glNormalP3uiv = pApi->glNormalP3uiv;
	glColorP3ui = pApi->glColorP3ui;
	glColorP3uiv = pApi->glColorP3uiv;
	glColorP4ui = pApi->glColorP4ui;
	glColorP4uiv = pApi->glColorP4uiv;
	glSecondaryColorP3ui = pApi->glSecondaryColorP3ui;
	glSecondaryColorP3uiv = pApi->glSecondaryColorP3uiv;
	glMinSampleShading = pApi->glMinSampleShading;
	glBlendEquationi = pApi->glBlendEquationi;
	glBlendEquationSeparatei = pApi->glBlendEquationSeparatei;
	glBlendFunci = pApi->glBlendFunci;
	glBlendFuncSeparatei = pApi->glBlendFuncSeparatei;
	glDrawArraysIndirect = pApi->glDrawArraysIndirect;
	glDrawElementsIndirect = pApi->glDrawElementsIndirect;
	glUniform1d = pApi->glUniform1d;
	glUniform2d = pApi->glUniform2d;
	glUniform3d = pApi->glUniform3d;
	glUniform4d = pApi->glUniform4d;
	glUniform1dv = pApi->glUniform1dv;
	glUniform2dv = pApi->glUniform2dv;
	glUniform3dv = pApi->glUniform3dv;
	glUniform4dv = pApi->glUniform4dv;
	glUniformMatrix2dv = pApi->glUniformMatrix2dv;
	glUniformMatrix3dv = pApi->glUniformMatrix3dv;
	glUniformMatrix4dv = pApi->glUniformMatrix4dv;
	glUniformMatrix2x3dv = pApi->glUniformMatrix2x3dv;
	glUniformMatrix2x4dv = pApi->glUniformMatrix2x4dv;
	glUniformMatrix3x2dv = pApi->glUniformMatrix3x2dv;
	glUniformMatrix3x4dv = pApi->glUniformMatrix3x4dv;
	glUniformMatrix4x2dv = pApi->glUniformMatrix4x2dv;
	glUniformMatrix4x3dv = pApi->glUniformMatrix4x3dv;
	glGetUniformdv = pApi->glGetUniformdv;
	glGetSubroutineUniformLocation = pApi->glGetSubroutineUniformLocation;
	glGetSubroutineIndex = pApi->glGetSubroutineIndex;
	glGetActiveSubroutineUniformiv = pApi->glGetActiveSubroutineUniformiv;
	glGetActiveSubroutineUniformName = pApi->glGetActiveSubroutineUniformName;
	glGetActiveSubroutineName = pApi->glGetActiveSubroutineName;
	glUniformSubroutinesuiv = pApi->glUniformSubroutinesuiv;
	glGetUniformSubroutineuiv = pApi->glGetUniformSubroutineuiv;
	glGetProgramStageiv = pApi->glGetProgramStageiv;
	glPatchParameteri = pApi->glPatchParameteri;
	glPatchParameterfv = pApi->glPatchParameterfv;
	glBindTransformFeedback = pApi->glBindTransformFeedback;
	glDeleteTransformFeedbacks = pApi->glDeleteTransformFeedbacks;
	glGenTransformFeedbacks = pApi->glGenTransformFeedbacks;
	glIsTransformFeedback = pApi->glIsTransformFeedback;
	glPauseTransformFeedback = pApi->glPauseTransformFeedback;
	glResumeTransformFeedback = pApi->glResumeTransformFeedback;
	glDrawTransformFeedback = pApi->glDrawTransformFeedback;
	glDrawTransformFeedbackStream = pApi->glDrawTransformFeedbackStream;
	glBeginQueryIndexed = pApi->glBeginQueryIndexed;
	glEndQueryIndexed = pApi->glEndQueryIndexed;
	glGetQueryIndexediv = pApi->glGetQueryIndexediv;
	glReleaseShaderCompiler = pApi->glReleaseShaderCompiler;
	glShaderBinary = pApi->glShaderBinary;
	glGetShaderPrecisionFormat = pApi->glGetShaderPrecisionFormat;
	glDepthRangef = pApi->glDepthRangef;
	glClearDepthf = pApi->glClearDepthf;
	glGetProgramBinary = pApi->glGetProgramBinary;
	glProgramBinary = pApi->glProgramBinary;
	glProgramParameteri = pApi->glProgramParameteri;
	glUseProgramStages = pApi->glUseProgramStages;
	glActiveShaderProgram = pApi->glActiveShaderProgram;
	glCreateShaderProgramv = pApi->glCreateShaderProgramv;
	glBindProgramPipeline = pApi->glBindProgramPipeline;
	glDeleteProgramPipelines = pApi->glDeleteProgramPipelines;
	glGenProgramPipelines = pApi->glGenProgramPipelines;
	glIsProgramPipeline = pApi->glIsProgramPipeline;
	glGetProgramPipelineiv = pApi->glGetProgramPipelineiv;
	glProgramUniform1i = pApi->glProgramUniform1i;
	glProgramUniform1iv = pApi->glProgramUniform1iv;
	glProgramUniform1f = pApi->glProgramUniform1f;
	glProgramUniform1fv = pApi->glProgramUniform1fv;
	glProgramUniform1d = pApi->glProgramUniform1d;
	glProgramUniform1dv = pApi->glProgramUniform1dv;
	glProgramUniform1ui = pApi->glProgramUniform1ui;
	glProgramUniform1uiv = pApi->glProgramUniform1uiv;
	glProgramUniform2i = pApi->glProgramUniform2i;
	glProgramUniform2iv = pApi->glProgramUniform2iv;
	glProgramUniform2f = pApi->glProgramUniform2f;
	glProgramUniform2fv = pApi->glProgramUniform2fv;
	glProgramUniform2d = pApi->glProgramUniform2d;
	glProgramUniform2dv = pApi->glProgramUniform2dv;
	glProgramUniform2ui = pApi->glProgramUniform2ui;
	glProgramUniform2uiv = pApi->glProgramUniform2uiv;
	glProgramUniform3i = pApi->glProgramUniform3i;
	glProgramUniform3iv = pApi->glProgramUniform3iv;
	glProgramUniform3f = pApi->glProgramUniform3f;
	glProgramUniform3fv = pApi->glProgramUniform3fv;
	glProgramUniform3d = pApi->glProgramUniform3d;
	glProgramUniform3dv = pApi->glProgramUniform3dv;
	glProgramUniform3ui = pApi->glProgramUniform3ui;
	glProgramUniform3uiv = pApi->glProgramUniform3uiv;
	glProgramUniform4i = pApi->glProgramUniform4i;
	glProgramUniform4iv = pApi->glProgramUniform4iv;
	glProgramUniform4f = pApi->glProgramUniform4f;
	glProgramUniform4fv = pApi->glProgramUniform4fv;
	glProgramUniform4d = pApi->glProgramUniform4d;
	glProgramUniform4dv = pApi->glProgramUniform4dv;
	glProgramUniform4ui = pApi->glProgramUniform4ui;
	glProgramUniform4uiv = pApi->glProgramUniform4uiv;
	glProgramUniformMatrix2fv = pApi->glProgramUniformMatrix2fv;
	glProgramUniformMatrix3fv = pApi->glProgramUniformMatrix3fv;
	glProgramUniformMatrix4fv = pApi->glProgramUniformMatrix4fv;
	glProgramUniformMatrix2dv = pApi->glProgramUniformMatrix2dv;
	glProgramUniformMatrix3dv = pApi->glProgramUniformMatrix3dv;
	glProgramUniformMatrix4dv = pApi->glProgramUniformMatrix4dv;
	glProgramUniformMatrix2x3fv = pApi->glProgramUniformMatrix2x3fv;
	glProgramUniformMatrix3x2fv = pApi->glProgramUniformMatrix3x2fv;
	glProgramUniformMatrix2x4fv = pApi->glProgramUniformMatrix2x4fv;
	glProgramUniformMatrix4x2fv = pApi->glProgramUniformMatrix4x2fv;
	glProgramUniformMatrix3x4fv = pApi->glProgramUniformMatrix3x4fv;
	glProgramUniformMatrix4x3fv = pApi->glProgramUniformMatrix4x3fv;
	glProgramUniformMatrix2x3dv = pApi->glProgramUniformMatrix2x3dv;
	glProgramUniformMatrix3x2dv = pApi->glProgramUniformMatrix3x2dv;
	glProgramUniformMatrix2x4dv = pApi->glProgramUniformMatrix2x4dv;
	glProgramUniformMatrix4x2dv = pApi->glProgramUniformMatrix4x2dv;
	glProgramUniformMatrix3x4dv = pApi->glProgramUniformMatrix3x4dv;
	glProgramUniformMatrix4x3dv = pApi->glProgramUniformMatrix4x3dv;
	glValidateProgramPipeline = pApi->glValidateProgramPipeline;
	glGetProgramPipelineInfoLog = pApi->glGetProgramPipelineInfoLog;
	glVertexAttribL1d = pApi->glVertexAttribL1d;
	glVertexAttribL2d = pApi->glVertexAttribL2d;
	glVertexAttribL3d = pApi->glVertexAttribL3d;
	glVertexAttribL4d = pApi->glVertexAttribL4d;
	glVertexAttribL1dv = pApi->glVertexAttribL1dv;
	glVertexAttribL2dv = pApi->glVertexAttribL2dv;
	glVertexAttribL3dv = pApi->glVertexAttribL3dv;
	glVertexAttribL4dv = pApi->glVertexAttribL4dv;
	glVertexAttribLPointer = pApi->glVertexAttribLPointer;
	glGetVertexAttribLdv = pApi->glGetVertexAttribLdv;
	glViewportArrayv = pApi->glViewportArrayv;
	glViewportIndexedf = pApi->glViewportIndexedf;
	glViewportIndexedfv = pApi->glViewportIndexedfv;
	glScissorArrayv = pApi->glScissorArrayv;
	glScissorIndexed = pApi->glScissorIndexed;
	glScissorIndexedv = pApi->glScissorIndexedv;
	glDepthRangeArrayv = pApi->glDepthRangeArrayv;
	glDepthRangeIndexed = pApi->glDepthRangeIndexed;
	glGetFloati_v = pApi->glGetFloati_v;
	glGetDoublei_v = pApi->glGetDoublei_v;
	glDrawArraysInstancedBaseInstance = pApi->glDrawArraysInstancedBaseInstance;
	glDrawElementsInstancedBaseInstance = pApi->glDrawElementsInstancedBaseInstance;
	glDrawElementsInstancedBaseVertexBaseInstance = pApi->glDrawElementsInstancedBaseVertexBaseInstance;
	glGetInternalformativ = pApi->glGetInternalformativ;
	glGetActiveAtomicCounterBufferiv = pApi->glGetActiveAtomicCounterBufferiv;
	glBindImageTexture = pApi->glBindImageTexture;
	glMemoryBarrier = pApi->glMemoryBarrier;
	glTexStorage1D = pApi->glTexStorage1D;
	glTexStorage2D = pApi->glTexStorage2D;
	glTexStorage3D = pApi->glTexStorage3D;
	glDrawTransformFeedbackInstanced = pApi->glDrawTransformFeedbackInstanced;
	glDrawTransformFeedbackStreamInstanced = pApi->glDrawTransformFeedbackStreamInstanced;
	glClearBufferData = pApi->glClearBufferData;
	glClearBufferSubData = pApi->glClearBufferSubData;
	glDispatchCompute = pApi->glDispatchCompute;
	glDispatchComputeIndirect = pApi->glDispatchComputeIndirect;
	glCopyImageSubData = pApi->glCopyImageSubData;
	glFramebufferParameteri = pApi->glFramebufferParameteri;
	glGetFramebufferParameteriv = pApi->glGetFramebufferParameteriv;
	glGetInternalformati64v = pApi->glGetInternalformati64v;
	glInvalidateTexSubImage = pApi->glInvalidateTexSubImage;
	glInvalidateTexImage = pApi->glInvalidateTexImage;
	glInvalidateBufferSubData = pApi->glInvalidateBufferSubData;
	glInvalidateBufferData = pApi->glInvalidateBufferData;
	glInvalidateFramebuffer = pApi->glInvalidateFramebuffer;
	glInvalidateSubFramebuffer = pApi->glInvalidateSubFramebuffer;
	glMultiDrawArraysIndirect = pApi->glMultiDrawArraysIndirect;
	glMultiDrawElementsIndirect = pApi->glMultiDrawElementsIndirect;
	glGetProgramInterfaceiv = pApi->glGetProgramInterfaceiv;
	glGetProgramResourceIndex = pApi->glGetProgramResourceIndex;
	glGetProgramResourceName = pApi->glGetProgramResourceName;
	glGetProgramResourceiv = pApi->glGetProgramResourceiv;
	glGetProgramResourceLocation = pApi->glGetProgramResourceLocation;
	glGetProgramResourceLocationIndex = pApi->glGetProgramResourceLocationIndex;
	glShaderStorageBlockBinding = pApi->glShaderStorageBlockBinding;
	glTexBufferRange = pApi->glTexBufferRange;
	glTexStorage2DMultisample = pApi->glTexStorage2DMultisample;
	glTexStorage3DMultisample = pApi->glTexStorage3DMultisample;
	glTextureView = pApi->glTextureView;
	glBindVertexBuffer = pApi->glBindVertexBuffer;
	glVertexAttribFormat = pApi->glVertexAttribFormat;
	glVertexAttribIFormat = pApi->glVertexAttribIFormat;
	glVertexAttribLFormat = pApi->glVertexAttribLFormat;
	glVertexAttribBinding = pApi->glVertexAttribBinding;
	glVertexBindingDivisor = pApi->glVertexBindingDivisor;
	glDebugMessageControl = pApi->glDebugMessageControl;
	glDebugMessageInsert = pApi->glDebugMessageInsert;
	glDebugMessageCallback = pApi->glDebugMessageCallback;
	glGetDebugMessageLog = pApi->glGetDebugMessageLog;
	glPushDebugGroup = pApi->glPushDebugGroup;
	glPopDebugGroup = pApi->glPopDebugGroup;
	glObjectLabel = pApi->glObjectLabel;
	glGetObjectLabel = pApi->glGetObjectLabel;
	glObjectPtrLabel = pApi->glObjectPtrLabel;
	glGetObjectPtrLabel = pApi->glGetObjectPtrLabel;
	glBufferStorage = pApi->glBufferStorage;
	glClearTexImage = pApi->glClearTexImage;
	glClearTexSubImage = pApi->glClearTexSubImage;
	glBindBuffersBase = pApi->glBindBuffersBase;
	glBindBuffersRange = pApi->glBindBuffersRange;
	glBindTextures = pApi->glBindTextures;
	glBindSamplers = pApi->glBindSamplers;
	glBindImageTextures = pApi->glBindImageTextures;
	glBindVertexBuffers = pApi->glBindVertexBuffers;
	glClipControl = pApi->glClipControl;
	glCreateTransformFeedbacks = pApi->glCreateTransformFeedbacks;
	glTransformFeedbackBufferBase = pApi->glTransformFeedbackBufferBase;
	glTransformFeedbackBufferRange = pApi->glTransformFeedbackBufferRange;
	glGetTransformFeedbackiv = pApi->glGetTransformFeedbackiv;
	glGetTransformFeedbacki_v = pApi->glGetTransformFeedbacki_v;
	glGetTransformFeedbacki64_v = pApi->glGetTransformFeedbacki64_v;
	glCreateBuffers = pApi->glCreateBuffers;
	glNamedBufferStorage = pApi->glNamedBufferStorage;
	glNamedBufferData = pApi->glNamedBufferData;
	glNamedBufferSubData = pApi->glNamedBufferSubData;
	glCopyNamedBufferSubData = pApi->glCopyNamedBufferSubData;
	glClearNamedBufferData = pApi->glClearNamedBufferData;
	glClearNamedBufferSubData = pApi->glClearNamedBufferSubData;
	glMapNamedBuffer = pApi->glMapNamedBuffer;
	glMapNamedBufferRange = pApi->glMapNamedBufferRange;
	glUnmapNamedBuffer = pApi->glUnmapNamedBuffer;
	glFlushMappedNamedBufferRange = pApi->glFlushMappedNamedBufferRange;
	glGetNamedBufferParameteriv = pApi->glGetNamedBufferParameteriv;
	glGetNamedBufferParameteri64v = pApi->glGetNamedBufferParameteri64v;
	glGetNamedBufferPointerv = pApi->glGetNamedBufferPointerv;
	glGetNamedBufferSubData = pApi->glGetNamedBufferSubData;
	glCreateFramebuffers = pApi->glCreateFramebuffers;
	glNamedFramebufferRenderbuffer = pApi->glNamedFramebufferRenderbuffer;
	glNamedFramebufferParameteri = pApi->glNamedFramebufferParameteri;
	glNamedFramebufferTexture = pApi->glNamedFramebufferTexture;
	glNamedFramebufferTextureLayer = pApi->glNamedFramebufferTextureLayer;
	glNamedFramebufferDrawBuffer = pApi->glNamedFramebufferDrawBuffer;
	glNamedFramebufferDrawBuffers = pApi->glNamedFramebufferDrawBuffers;
	glNamedFramebufferReadBuffer = pApi->glNamedFramebufferReadBuffer;
	glInvalidateNamedFramebufferData = pApi->glInvalidateNamedFramebufferData;
	glInvalidateNamedFramebufferSubData = pApi->glInvalidateNamedFramebufferSubData;
	glClearNamedFramebufferiv = pApi->glClearNamedFramebufferiv;
	glClearNamedFramebufferuiv = pApi->glClearNamedFramebufferuiv;
	glClearNamedFramebufferfv = pApi->glClearNamedFramebufferfv;
	glClearNamedFramebufferfi = pApi->glClearNamedFramebufferfi;
	glBlitNamedFramebuffer = pApi->glBlitNamedFramebuffer;
	glCheckNamedFramebufferStatus = pApi->glCheckNamedFramebufferStatus;
	glGetNamedFramebufferParameteriv = pApi->glGetNamedFramebufferParameteriv;
	glGetNamedFramebufferAttachmentParameteriv = pApi->glGetNamedFramebufferAttachmentParameteriv;
	glCreateRenderbuffers = pApi->glCreateRenderbuffers;
	glNamedRenderbufferStorage = pApi->glNamedRenderbufferStorage;
	glNamedRenderbufferStorageMultisample = pApi->glNamedRenderbufferStorageMultisample;
	glGetNamedRenderbufferParameteriv = pApi->glGetNamedRenderbufferParameteriv;
	glCreateTextures = pApi->glCreateTextures;
	glTextureBuffer = pApi->glTextureBuffer;
	glTextureBufferRange = pApi->glTextureBufferRange;
	glTextureStorage1D = pApi->glTextureStorage1D;
	glTextureStorage2D = pApi->glTextureStorage2D;
	glTextureStorage3D = pApi->glTextureStorage3D;
	glTextureStorage2DMultisample = pApi->glTextureStorage2DMultisample;
	glTextureStorage3DMultisample = pApi->glTextureStorage3DMultisample;
	glTextureSubImage1D = pApi->glTextureSubImage1D;
	glTextureSubImage2D = pApi->glTextureSubImage2D;
	glTextureSubImage3D = pApi->glTextureSubImage3D;
	glCompressedTextureSubImage1D = pApi->glCompressedTextureSubImage1D;
	glCompressedTextureSubImage2D = pApi->glCompressedTextureSubImage2D;
	glCompressedTextureSubImage3D = pApi->glCompressedTextureSubImage3D;
	glCopyTextureSubImage1D = pApi->glCopyTextureSubImage1D;
	glCopyTextureSubImage2D = pApi->glCopyTextureSubImage2D;
	glCopyTextureSubImage3D = pApi->glCopyTextureSubImage3D;
	glTextureParameterf = pApi->glTextureParameterf;
	glTextureParameterfv = pApi->glTextureParameterfv;
	glTextureParameteri = pApi->glTextureParameteri;
	glTextureParameterIiv = pApi->glTextureParameterIiv;
	glTextureParameterIuiv = pApi->glTextureParameterIuiv;
	glTextureParameteriv = pApi->glTextureParameteriv;
	glGenerateTextureMipmap = pApi->glGenerateTextureMipmap;
	glBindTextureUnit = pApi->glBindTextureUnit;
	glGetTextureImage = pApi->glGetTextureImage;
	glGetCompressedTextureImage = pApi->glGetCompressedTextureImage;
	glGetTextureLevelParameterfv = pApi->glGetTextureLevelParameterfv;
	glGetTextureLevelParameteriv = pApi->glGetTextureLevelParameteriv;
	glGetTextureParameterfv = pApi->glGetTextureParameterfv;
	glGetTextureParameterIiv = pApi->glGetTextureParameterIiv;
	glGetTextureParameterIuiv = pApi->glGetTextureParameterIuiv;
	glGetTextureParameteriv = pApi->glGetTextureParameteriv;
	glCreateVertexArrays = pApi->glCreateVertexArrays;
	glDisableVertexArrayAttrib = pApi->glDisableVertexArrayAttrib;
	glEnableVertexArrayAttrib = pApi->glEnableVertexArrayAttrib;
	glVertexArrayElementBuffer = pApi->glVertexArrayElementBuffer;
	glVertexArrayVertexBuffer = pApi->glVertexArrayVertexBuffer;
	glVertexArrayVertexBuffers = pApi->glVertexArrayVertexBuffers;
	glVertexArrayAttribBinding = pApi->glVertexArrayAttribBinding;
	glVertexArrayAttribFormat = pApi->glVertexArrayAttribFormat;
	glVertexArrayAttribIFormat = pApi->glVertexArrayAttribIFormat;
	glVertexArrayAttribLFormat = pApi->glVertexArrayAttribLFormat;
	glVertexArrayBindingDivisor = pApi->glVertexArrayBindingDivisor;
	glGetVertexArrayiv = pApi->glGetVertexArrayiv;
	glGetVertexArrayIndexediv = pApi->glGetVertexArrayIndexediv;
	glGetVertexArrayIndexed64iv = pApi->glGetVertexArrayIndexed64iv;
	glCreateSamplers = pApi->glCreateSamplers;
	glCreateProgramPipelines = pApi->glCreateProgramPipelines;
	glCreateQueries = pApi->glCreateQueries;
	glGetQueryBufferObjecti64v = pApi->glGetQueryBufferObjecti64v;
	glGetQueryBufferObjectiv = pApi->glGetQueryBufferObjectiv;
	glGetQueryBufferObjectui64v = pApi->glGetQueryBufferObjectui64v;
	glGetQueryBufferObjectuiv = pApi->glGetQueryBufferObjectuiv;
	glMemoryBarrierByRegion = pApi->glMemoryBarrierByRegion;
	glGetTextureSubImage = pApi->glGetTextureSubImage;
	glGetCompressedTextureSubImage = pApi->glGetCompressedTextureSubImage;
	glGetGraphicsResetStatus = pApi->glGetGraphicsResetStatus;
	glGetnCompressedTexImage = pApi->glGetnCompressedTexImage;
	glGetnTexImage = pApi->glGetnTexImage;
	glGetnUniformdv = pApi->glGetnUniformdv;
	glGetnUniformfv = pApi->glGetnUniformfv;
	glGetnUniformiv = pApi->glGetnUniformiv;
	glGetnUniformuiv = pApi->glGetnUniformuiv;
	glReadnPixels = pApi->glReadnPixels;
	glGetnMapdv = pApi->glGetnMapdv;
	glGetnMapfv = pApi->glGetnMapfv;
	glGetnMapiv = pApi->glGetnMapiv;
	glGetnPixelMapfv = pApi->glGetnPixelMapfv;
	glGetnPixelMapuiv = pApi->glGetnPixelMapuiv;
	glGetnPixelMapusv = pApi->glGetnPixelMapusv;
	glGetnPolygonStipple = pApi->glGetnPolygonStipple;
	glGetnColorTable = pApi->glGetnColorTable;
	glGetnConvolutionFilter = pApi->glGetnConvolutionFilter;
	glGetnSeparableFilter = pApi->glGetnSeparableFilter;
	glGetnHistogram = pApi->glGetnHistogram;
	glGetnMinmax = pApi->glGetnMinmax;
	glTextureBarrier = pApi->glTextureBarrier;
	glSpecializeShader = pApi->glSpecializeShader;
	glMultiDrawArraysIndirectCount = pApi->glMultiDrawArraysIndirectCount;
	glMultiDrawElementsIndirectCount = pApi->glMultiDrawElementsIndirectCount;
	glPolygonOffsetClamp = pApi->glPolygonOffsetClamp;
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
