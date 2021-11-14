#ifndef INC_2D_POOL_RENDERSYSTEM_H
#define INC_2D_POOL_RENDERSYSTEM_H

#include <systemManager.h>
#include <windowConfig.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


namespace base {
    class renderSystem : public system, public utils::singleton<renderSystem> {
        static std::string vertexShader;
        static std::string fragmentShader;

        static GLuint vaoId;
        static GLuint vboId;
        static GLuint eboId;
        static GLuint programId;

        static GLfloat screenWidth;
        static GLfloat screenHeight;

        static glm::mat4 currentTransform;
        static glm::mat4 resizeMatrix;

        static GLint currentTransformId;

        static std::vector<GLfloat> totalVertices;
        static std::vector<GLuint> totalIndices;

        static void initialise();
        static void cleanup();

        void createVbo();
        static void destroyVbo();

        static void loadShaders();

    public:
        static void createWindow(const windowConfig*);

        void render();
    };
}


#endif //INC_2D_POOL_RENDERSYSTEM_H
