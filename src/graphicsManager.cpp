#include "graphicsManager.h"


namespace base {
    GLuint graphicsManager::vaoId;
    GLuint graphicsManager::vboId;
    GLuint graphicsManager::eboId;

    std::vector<GLfloat> graphicsManager::totalVertices;
    std::vector<GLuint> graphicsManager::totalIndices;


    void graphicsManager::createWindow(const windowConfig* const config) {
        glutInit(config->getArgumentCount(), config->getArgumentVector());
        glutInitDisplayMode(config->getDisplayMode());
        glutInitWindowPosition(config->getPosition().x, config->getPosition().y);
        glutInitWindowSize(config->getSize().width, config->getSize().height);
        glutCreateWindow(config->getTitle().c_str());

        glewInit();
        onStart();
        glutDisplayFunc(graphicsManager::render);
        glutCloseFunc(graphicsManager::cleanup);
        glutMainLoop();
    }

    void graphicsManager::createVbo() {

    }

    void graphicsManager::destroyVbo() {
        glDisableVertexAttribArray(2u);
        glDisableVertexAttribArray(1u);
        glDisableVertexAttribArray(0u);

        glBindBuffer(GL_ARRAY_BUFFER, 0u);
        glDeleteBuffers(1u, &eboId);
        glDeleteBuffers(1u, &vboId);

        glBindVertexArray(0u);
        glDeleteVertexArrays(1u, &vaoId);
    }

    void graphicsManager::onStart() {
        std::printf("Initialising...\n");
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    }

    void graphicsManager::render() {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

    void graphicsManager::cleanup() {
        std::printf("Cleaning up...\n");
        std::printf("Cleanup successful!\n\n");
    }
}
