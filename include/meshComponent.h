#ifndef INC_2D_POOL_MESHCOMPONENT_H
#define INC_2D_POOL_MESHCOMPONENT_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>


namespace base {
    struct meshComponent final {
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;
    };
}


#endif //INC_2D_POOL_MESHCOMPONENT_H
