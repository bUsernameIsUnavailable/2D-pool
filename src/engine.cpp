#include "../include/engine.h"

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <ctime>


namespace base {
    engine engine::initialise(int* const argc, char** const argv) const {
        glutInit(argc, argv);
        std::printf("Engine started!\n");
        return *this;
    }

    engine engine::setDisplayMode(const unsigned int newDisplayMode) {
        if (newDisplayMode != displayMode) {
            displayMode = newDisplayMode;
            glutInitDisplayMode(displayMode);
            std::printf("Display mode set to %u\n", displayMode);
        }
        return *this;
    }

    engine engine::setWindowPosition(const int newX, const int newY) {
        if (newX != windowPosition.x || newY != windowPosition.y) {
            windowPosition.x = newX;
            windowPosition.y = newY;
            glutInitWindowPosition(windowPosition.x, windowPosition.y);
            std::printf("Window position set to (%dx%d)\n", windowPosition.x, windowPosition.y);
        }
        return *this;
    }

    engine engine::setWindowSize(const int newWidth, const int newHeight) {
        if (newWidth != windowSize.width || newHeight != windowSize.height) {
            windowSize.width = newWidth;
            windowSize.height = newHeight;
            glutInitWindowSize(windowSize.width, windowSize.height);
            std::printf("Window size set to (%dx%d)\n", windowSize.width, windowSize.height);
        }
        return *this;
    }

    engine engine::createWindow(const char* const newTitle) {
        if (newTitle != title) {
            title = newTitle;
            glutCreateWindow(title.c_str());
            std::printf("Created window with title \"%s\"\n", title.c_str());
        }
        return *this;
    }

    engine engine::setSeed(const unsigned int newSeed) {
        if (newSeed != seed) {
            seed = newSeed;
            std::srand(seed);
            std::printf("Seed set to %u\n\n", seed);
        }
        return *this;
    }

    void engine::start(const unsigned int userSeed) {
        setSeed((userSeed == 0u) * std::time(nullptr) + userSeed);
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
        // TODO
        std::printf("Cleanup successful!\n\n");
    }
}
