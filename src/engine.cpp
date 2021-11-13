#include "../include/engine.h"
#include "../include/windowConfig.h"

#include <GL/glew.h>
#include <GL/freeglut.h>


namespace base {
    engine::~engine() {
        delete config;
    }

    void engine::start(const windowConfig* const window) {
        std::printf("Engine started!\n");

        config = window;
        glutInit(config->getArgumentCount(), config->getArgumentVector());
        glutInitDisplayMode(config->getDisplayMode());
        glutInitWindowPosition(config->getPosition().x, config->getPosition().y);
        glutInitWindowSize(config->getSize().width, config->getSize().height);
        glutCreateWindow(config->getTitle().c_str());

        glewInit();
        onStart();
        glutDisplayFunc(engine::render);
        glutCloseFunc(engine::cleanup);
        glutMainLoop();
    }

    void engine::onStart() {
        std::printf("Initialising...\n");
        glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    }

    void engine::render() {
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

    void engine::cleanup() {
        std::printf("Cleaning up...\n");
        std::printf("Cleanup successful!\n\n");
    }
}
