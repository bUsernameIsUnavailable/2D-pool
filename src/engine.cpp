#include <engine.h>
#include <renderSystem.h>


namespace base {
    entityManager* engine::entityManager;
    componentManager* engine::componentManager;
    systemManager* engine::systemManager;


    void engine::getManagers() {
        entityManager = &entityManager::getInstance();
        componentManager = &componentManager::getInstance();
        systemManager = &systemManager::getInstance();
    }

    void engine::start() {
        std::printf("Engine started!\n");
        getManagers();
    }

    void engine::play(const windowConfig* const config) {
        renderSystem::createWindow(config);
    }
}
