#include "../include/engine.h"
#include "../include/windowConfig.h"

#include <GL/freeglut.h>


int main(int argc, char** const argv)
{
    base::engine::getInstance().start((new base::windowConfig())
        ->setArguments(argc, argv)
        ->setDisplayMode(GLUT_SINGLE | GLUT_RGB)
        ->setPosition(100, 100)
        ->setSize(800, 600)
        ->setTitle("2D Pool")
    );

    return 0;
}
