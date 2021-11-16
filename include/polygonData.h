#ifndef INC_2D_POOL_POLYGONDATA_H
#define INC_2D_POOL_POLYGONDATA_H

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <vector>


namespace utils {
    class polygonData {
        std::vector<glm::vec2> points;
        std::vector<GLfloat> vertices;
        std::vector<GLuint> indices;

    public:
        polygonData(
                const GLfloat&, const GLfloat&, const float&,
                const unsigned int&, unsigned int&,
                const GLfloat&, const GLfloat&, const GLfloat&
        );

        [[nodiscard]] inline const std::vector<glm::vec2>& getPoints() const { return points; }
        [[nodiscard]] inline const std::vector<GLfloat>& getVertices() const { return vertices; }
        [[nodiscard]] inline const std::vector<GLuint>& getIndices() const { return indices; }
    };
}


#endif //INC_2D_POOL_POLYGONDATA_H
