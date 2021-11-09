#include "../include/engine.h"

#include <GL/freeglut.h>


int main(int argc, char** const argv)
{
    base::engine::getInstance().initialise(&argc, argv)
        .setDisplayMode(GLUT_SINGLE | GLUT_RGB)
        .setWindowPosition(100, 100)
        .setWindowSize(800, 600)
        .createWindow("2D Pool")
        .start();

    return 0;
}
