#include "engine.h"
#include "windowManager.h"


int main(int argc, char** const argv)
{
    base::engine::start(base::windowManager::getInstance().createWindowConfig()
        ->setArguments(argc, argv)
        ->setDisplayMode(GLUT_SINGLE | GLUT_RGB)
        ->setPosition(100, 100)
        ->setSize(800, 600)
        ->setTitle("2D Pool")
    );

    return 0;
}
