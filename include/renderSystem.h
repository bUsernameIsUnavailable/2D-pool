#ifndef INC_2D_POOL_RENDERSYSTEM_H
#define INC_2D_POOL_RENDERSYSTEM_H

#include <systemManager.h>
#include <windowManager.h>

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>


namespace base {
    class renderSystem final : public system, public utils::singleton<renderSystem> {
        static std::string vertexShader;
        static std::string fragmentShader;

        static GLuint vaoId;
        static GLuint vboId;
        static GLuint eboId;
        static GLuint programId;

        static std::vector<GLuint> textureIds;

        static GLfloat screenWidth;
        static GLfloat screenHeight;

        static glm::mat4 currentTransform;
        static glm::mat4 resizeMatrix;

        static GLint currentTransformId;
        static GLint colourCodeId;

        static std::vector<GLfloat> totalVertices;
        static std::vector<GLuint> totalIndices;

        static void reshapeWindow(GLint, GLint);

        void createVbo();
        static void loadShaders();
        void loadTextures();

        static void cleanup();
        static void destroyShaders();
        static void destroyVbo();

    public:
        void initialise();
        static void createWindow(const windowConfig*);

        static void update();
        void render();
    };
}


#endif //INC_2D_POOL_RENDERSYSTEM_H
