<div align="center">

# glld.h - single-header only OpenGL loader

</div>

glld.h is a single-header only legacy, modern and embedded-systems OpenGL loader, based on the official KhronosGroup's OpenGL Registry.
It's simple, easy to use, highly configurable with support for GNU/Linux, MacOS and Windows Operating Systems.

```c
#define GLLD_IMPLEMENTATION
#include "glld.h"

int main(void) {
    if (!glld_load(0)) { return (1); }

    /* ... */
    
    glClearColor(1.0, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    /* ... */

    glld_unload(0);
    return (0);
}
```

## Credits

Project source:
- [KhronosGroup/OpenGL-Registry](https://github.com/KhronosGroup/OpenGL-Registry.git);

Credits, inspirations:
- [nothings/stb](https://github.com/nothings/stb.git);
- [Dav1dde/glad](https://github.com/Dav1dde/glad.git);
- [macron/glbind](https://github.com/mackron/glbind.git);

## Licence

This project is licenced under [LGPL-3 Licence](./LICENCE).
