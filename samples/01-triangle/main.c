#define GLLD_IMPLEMENTATION
#include <glld/glld.h>
#
#define WINDOW_IMPLEMENTATION
#include <window/window.h>

static const GLchar *glsl[] = {
    /* vertex.glsl */
    [0] = "#version 460 core\n"
          "\n"
          "layout (location = 0)\n"
          "in vec3 a_position;\n"
          "\n"
          "layout (location = 1)\n"
          "in vec4 a_color;\n"
          "\n"
          "layout (location = 0)\n"
          "out vec4 v_color;\n"
          "\n"
          "void main() {\n"
          "    gl_Position = vec4(a_position, 1.0);\n"
          "    v_color = a_color;\n"
          "}\n",

    /* fragment.glsl */
    [1] = "#version 460 core\n"
          "\n"
          "layout (location = 0)\n"
          "in vec4 v_color;\n"
          "\n"
          "layout (location = 0)\n"
          "out vec4 f_color;\n"
          "\n"
          "void main() {\n"
          "   f_color = v_color;\n"
          "}\n"
};


int main(void) {
    /* init 'window.h' */
    library_t library = 0;
    win_init(&library);
    win_set_hints(library, WINDOW_CLIENT_API, WINDOW_API_OPENGL);


    /* create 'window' */
    window_t window = 0;
    win_window_create(library, &window, 800, 600, "glld.h - 01. Triangle");
    win_window_map(library, window);


    /* create 'context' */
    context_t context = 0;
    win_context_create(library, &context, window);
    win_gl_make_current(library, context);


    /* init 'glld.h' */
    if (!glld_loader((glld_loader_t) win_gl_get_proc_address)) { return (1); }


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

    glVertexArrayAttribBinding(va, 0, 0);
    glVertexArrayAttribBinding(va, 1, 0);
    
    glVertexArrayAttribFormat(va, 0, 3, GL_FLOAT, GL_FALSE, 0 * sizeof(GLfloat));
    glVertexArrayAttribFormat(va, 1, 4, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat));
    

    /* create vertex buffer */
    GLuint vb;
    {
        glCreateBuffers(1, &vb);
    }

    GLfloat vertices[] = { -0.5, -0.5, 0.0,     1.0, 0.0, 0.0, 1.0,
                            0.5, -0.5, 0.0,     0.0, 1.0, 0.0, 1.0,
                            0.0,  0.5, 0.0,     0.0, 0.0, 1.0, 1.0, };

    glNamedBufferData(vb, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexArrayVertexBuffer(va, 0, vb, 0, 7 * sizeof(GLfloat));

    for (int exit = 0; !exit; ) {
        /* render */
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glBindVertexArray(va);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);
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
    glDeleteVertexArrays(1, &va), va = 0;
    glDeleteProgram(shader), shader = 0;

    /* quit */
    glld_unload();
    win_quit(library);
    return (0);
}
