#define GLLD_IMPLEMENTATION
#include "./../../glld.h"


int main(void) {
    glld_t glld = { 0 };
    if (!glld_load(&glld)) { return (1); }
    printf("glld.h: %d.%d\n", glld.version.major, glld.version.minor);
    printf("OpenGL: %d.%d\n", glld.gl.version.major, glld.gl.version.minor);

    /* ... */

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* ... */
    
    if (!glld_unload(&glld)) { return (1); }

    return (0);
}
