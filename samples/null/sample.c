#define GLLD_IMPLEMENTATION
#include "./../../glld.h"


int main(void) {
    if (glld_load(0) != GL_NO_ERROR) { return (1); }

    /* ... */

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    /* ... */
    
    if (glld_unload(0) != GL_NO_ERROR) { return (1); }

    return (0);
}
