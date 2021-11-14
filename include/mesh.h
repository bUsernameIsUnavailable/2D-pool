#ifndef INC_2D_POOL_MESH_H
#define INC_2D_POOL_MESH_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <vector>


namespace base {
    class mesh {
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;

    public:
        [[nodiscard]] inline const std::vector<GLfloat>& getVertices() const { return vertices; }
        [[nodiscard]] inline const std::vector<GLuint>& getIndices() const { return indices; }
    };
}


#endif //INC_2D_POOL_MESH_H
