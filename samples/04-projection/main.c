#define GLLD_IMPLEMENTATION
#include <glld/glld.h>
#
#define WINDOW_IMPLEMENTATION
#include <window/window.h>
#
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

typedef struct GLvertex GLvertex;

struct GLvertex {
    GLfloat vp[3];
    GLfloat vn[3];
    GLfloat vt[2];
};


static const GLchar *glsl[] = {
    /* vertex.glsl */
    [0] = "#version 460 core\n"
          "\n"
          "layout (location = 0)\n"
          "in vec3 a_vp;\n"
          "\n"
          "layout (location = 1)\n"
          "in vec3 a_vn;\n"
          "\n"
          "layout (location = 2)\n"
          "in vec2 a_vt;\n"
          "\n"
          "layout (location = 0)\n"
          "out vec3 v_vn;\n"
          "\n"
          "layout (location = 1)\n"
          "out vec2 v_vt;\n"
          "\n"
          "uniform mat4 u_projection;\n"
          "uniform mat4 u_view;\n"
          "uniform mat4 u_model;\n"
          "\n"
          "void main() {\n"
          "    gl_Position = u_model * u_view * u_projection * vec4(a_vp, 1.0);\n"
          "    v_vn = a_vn;\n"
          "    v_vt = a_vt;\t"
          "}\n",

    /* fragment.glsl */
    [1] = "#version 460 core\n"
          "\n"
          "layout (location = 0)\n"
          "in vec3 v_vn;\n"
          "\n"
          "layout (location = 1)\n"
          "in vec2 v_vt;\n"
          "\n"
          "layout (location = 0)\n"
          "out vec4 f_color;\n"
          "\n"
          "uniform sampler2D u_texture;\n"
          "\n"
          "void main() {\n"
          "   f_color = texture(u_texture, v_vt);\n"
          "}\n"
};


int main(int ac, char **av) {
    /* init 'window.h' */
    library_t library = 0;
    win_init(&library);
    win_set_hints(library, WINDOW_CLIENT_API, WINDOW_API_OPENGL);


    /* create 'window' */
    window_t window = 0;
    win_window_create(library, &window, 800, 600, "glld.h - 04. Projection");
    win_window_map(library, window);


    /* create 'context' */
    context_t context = 0;
    win_context_create(library, &context, window);
    win_gl_make_current(library, context);


    /* init 'glld.h' */
    if (!glld_loader((glld_loader_t) win_gl_get_proc_address)) { return (1); }


    /* load 'image' */
    int w = 0,
        h = 0,
        c = 0;
    stbi_uc *image = stbi_load(av[1], &w, &h, &c, 0);
    if (!image) { return (2); }


    /* create 'texture' */
    GLuint texture;
    {
        glCreateTextures(GL_TEXTURE_2D, 1, &texture);

        glTextureStorage2D(texture, 1, GL_RGBA8, w, h);
        glTextureSubImage2D(texture, 0, 0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, image);
        glGenerateTextureMipmap(texture);

        glTextureParameteri(texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTextureParameteri(texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTextureParameteri(texture, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(texture, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }


    /* create 'shader' */
    GLuint shader = glCreateProgram();
    {
        GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &glsl[0], 0);
        glCompileShader(vertex);
        glAttachShader(shader, vertex);
        
        GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &glsl[1], 0);
        glCompileShader(fragment);
        glAttachShader(shader, fragment);
        
        glLinkProgram(shader);
        glDeleteShader(vertex), vertex = 0;
        glDeleteShader(fragment), fragment = 0;
    }


    /* create vertex array */
    GLuint va;
    {
        glCreateVertexArrays(1, &va);
    }

    glEnableVertexArrayAttrib(va, 0);
    glEnableVertexArrayAttrib(va, 1);
    glEnableVertexArrayAttrib(va, 2);

    glVertexArrayAttribBinding(va, 0, 0);
    glVertexArrayAttribBinding(va, 1, 0);
    glVertexArrayAttribBinding(va, 2, 0);
    
    glVertexArrayAttribFormat(va, 0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(GLfloat));
    glVertexArrayAttribFormat(va, 1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat));
    glVertexArrayAttribFormat(va, 2, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat));
    

    /* create vertex buffer */
    GLuint vb;
    {
        glCreateBuffers(1, &vb);
    }

    GLvertex vertices[] = {
        [0] = { .vp = { 0.0, 0.0, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 0.0 } },
        [1] = { .vp = { w,   0.0, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 1.0 } },
        [2] = { .vp = { 0.0, h,   0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 1.0, 0.0 } },
        [3] = { .vp = { w,   h,   0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 1.0, 1.0 } },
    };

    glNamedBufferData(vb, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexArrayVertexBuffer(va, 0, vb, 0, sizeof(GLvertex));


    /* create index buffer */
    GLuint ib;
    {
        glCreateBuffers(1, &ib);
    }
    
    GLuint indices[] = { 0, 1, 2,
                         1, 2, 3, };

    glNamedBufferData(ib, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexArrayElementBuffer(va, ib);


    /* create 'model', 'view' and 'projection' matrices */
    GLfloat projection[] = {  0.0025,  0.0,     0.0, 0.0,
                              0.0,     0.0033,  0.0, 0.0,
                              0.0,     0.0,    -2.0, 0.0,
                             -1.0,    -1.0,    -1.0, 1.0 , };

    GLfloat view[] = { 1.0, 0.0, 0.0, 0.0,
                       0.0, 1.0, 0.0, 0.0,
                       0.0, 0.0, 1.0, 0.0,
                       0.0, 0.0, 0.0, 1.0, };

    GLfloat model[] = { 1.0, 0.0, 0.0, 0.0,
                        0.0, 1.0, 0.0, 0.0,
                        0.0, 0.0, 1.0, 0.0,
                        0.0, 0.0, 0.0, 1.0, };

    /* set uniforms to 'shader' */
    GLint u_projection = glGetUniformLocation(shader, "u_projection");
    glProgramUniformMatrix4fv(shader, u_projection, 1, GL_FALSE, &projection[0]);
    
    GLint u_view = glGetUniformLocation(shader, "u_view");
    glProgramUniformMatrix4fv(shader, u_view, 1, GL_FALSE, &view[0]);
    
    GLint u_model = glGetUniformLocation(shader, "u_model");
    glProgramUniformMatrix4fv(shader, u_model, 1, GL_FALSE, &model[0]);

    for (int exit = 0; !exit; ) {
        /* render */
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glBindTextureUnit(0, texture);
        glBindVertexArray(va);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        glBindTextureUnit(0, 0);
        glUseProgram(0);

        /* poll events */
        win_gl_swap_buffers(library, context);
        event_t event = { 0 };
        while (win_event_poll(library, &event)) {
            switch (event.type) {
                case (WINDOW_EVENT_QUIT): {
                    exit = 1;
                } break;
            }
        }
    }
   

    /* unload resources */
    glDeleteBuffers(1, &vb), vb = 0;
    glDeleteBuffers(1, &ib), ib = 0;
    glDeleteVertexArrays(1, &va), va = 0;
    glDeleteProgram(shader), shader = 0;
    glDeleteTextures(1, &texture), texture = 0;
    stbi_image_free(image), image = 0;

    /* quit */
    glld_unload();
    win_quit(library);
    return (0);
}
