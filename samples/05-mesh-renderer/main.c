#define GLLD_IMPLEMENTATION
#include <glld/glld.h>
#
#define WINDOW_IMPLEMENTATION
#include <window/window.h>

typedef struct GLvertex GLvertex;

struct GLvertex {
    GLfloat vp[3];
    GLfloat vn[3];
    GLfloat vt[2];
};


typedef struct GLbuffer GLbuffer;

struct GLbuffer {
    GLuint id;
};


typedef struct GLmesh GLmesh;

struct GLmesh {
    GLbuffer vertex;
    GLbuffer index;
};

GLint glCreateMesh(GLmesh *mesh) {
    /* null-check */
    if (!mesh) { return (0); }

    /* create 'mesh's buffers */
    glCreateBuffers(1, &mesh->vertex.id);
    glCreateBuffers(1, &mesh->index.id);

    /* success */
    return (1);
}


GLint glDeleteMesh(GLmesh *mesh) {
    /* null-check */
    if (!mesh) { return (0); }

    /* delete 'mesh's buffers */
    glDeleteBuffers(1, &mesh->vertex.id);
    glDeleteBuffers(1, &mesh->index.id);

    /* success */
    return (1);
}


GLint glBakeMesh(GLmesh *mesh, GLvertex *vertices, GLsizei vsize, GLuint *indices, GLsizei isize) {
    /* null-check */
    if (!mesh) { return (0); }

    /* set buffer data */
    GLuint vb = mesh->vertex.id;
    if (!vb) { return (0); }

    GLuint ib = mesh->index.id;
    if (!ib) { return (0); }

    glNamedBufferData(vb, vsize, vertices, GL_STATIC_DRAW);
    glNamedBufferData(ib, isize, indices, GL_STATIC_DRAW);

    /* success */
    return (1);
}


GLint glLoadMesh(GLmesh *mesh, GLuint va) {
    /* null-check */
    if (!mesh) { return (0); }
    if (!va)   { return (0); }

    /* set vertex data into the vertex array */
    GLuint vb = mesh->vertex.id;
    if (!vb) { return (0); }

    GLuint ib = mesh->index.id;
    if (!ib) { return (0); }
    
    glVertexArrayVertexBuffer(va, 0, vb, 0, sizeof(GLvertex));
    glVertexArrayElementBuffer(va, ib);

    /* success */
    return (1);
}


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
    win_window_create(library, &window, 800, 600, "glld.h - 02. Quad");
    win_window_map(library, window);


    /* create 'context' */
    context_t context = 0;
    win_context_create(library, &context, window);
    win_gl_make_current(library, context);


    /* init 'glld.h' */
    glld_loader(0, (glld_loader_t) win_gl_get_proc_address);


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
    

    /* create 'triangle' mesh */
    GLvertex t_vertex[] = {
        [0] = { .vp = { -0.5, -0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 0.0 } },
        [1] = { .vp = {  0.5, -0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 1.0 } },
        [2] = { .vp = {  0.0,  0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 1.0, 0.0 } },
    };
    
    GLuint t_index[] = { 0, 1, 2 };
    
    GLmesh triangle = { 0 };
    glCreateMesh(&triangle);
    glBakeMesh(&triangle, t_vertex, sizeof(t_vertex), t_index, sizeof(t_index));

    /* create 'rect' mesh */
    GLvertex r_vertex[] = {
        [0] = { .vp = { -0.5, -0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 0.0 } },
        [1] = { .vp = {  0.5, -0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 0.0, 1.0 } },
        [2] = { .vp = { -0.5,  0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 1.0, 0.0 } },
        [3] = { .vp = {  0.5,  0.5, 0.0 }, .vn = { 0.0, 0.0, 0.0 }, .vt = { 1.0, 1.0 } },
    };
    
    GLuint r_index[] = { 0, 1, 2,
                         1, 2, 3, };
    
    GLmesh rect = { 0 };
    glCreateMesh(&rect);
    glBakeMesh(&rect, r_vertex, sizeof(r_vertex), r_index, sizeof(r_index));

    for (int exit = 0; !exit; ) {
        /* render */
        glClearColor(0.1, 0.1, 0.1, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader);
        glBindVertexArray(va);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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

                case (WINDOW_EVENT_KEYBOARD_KEY): {
                    int keycode = event.keyboard.key.code;
                    switch (keycode) {
                        case (WINDOW_KEYCODE_1): { glLoadMesh(&triangle, va); } break;
                        case (WINDOW_KEYCODE_2): { glLoadMesh(&rect, va); } break;
                    }
                } break;
            }
        }
    }
   

    /* unload resources */
    glDeleteMesh(&rect);
    glDeleteMesh(&triangle);
    glDeleteVertexArrays(1, &va), va = 0;
    glDeleteProgram(shader), shader = 0;

    /* quit */
    glld_unload(0);
    win_quit(library);
    return (0);
}
