#include "engine.h"


namespace base {
    const entityManager* engine::entityManager;
    const componentManager* engine::componentManager;
    const systemManager* engine::systemManager;

    graphicsManager* engine::graphicsManager;


    void engine::getManagers() {
        graphicsManager = &graphicsManager::getInstance();
        entityManager = &entityManager::getInstance();
        componentManager = &componentManager::getInstance();
        systemManager = &systemManager::getInstance();
    }

    void engine::start(const windowConfig* const config) {
        getManagers();
        std::printf("Engine started!\n");

        graphicsManager::createWindow(config);
    }
}
