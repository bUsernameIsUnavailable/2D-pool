#include <engine.h>


namespace base {
    entityManager* engine::entityManager;
    componentManager* engine::componentManager;
    systemManager* engine::systemManager;

    collisionSystem* engine::collisionSystem;
    movementSystem* engine::movementSystem;


    void engine::getInstances() {
        entityManager = &entityManager::getInstance();
        componentManager = &componentManager::getInstance();
        systemManager = &systemManager::getInstance();

        collisionSystem = &collisionSystem::getInstance();
        movementSystem = &movementSystem::getInstance();
    }

    void engine::start() {
        std::printf("Engine started!\n");
        getInstances();
    }

    void engine::play(const windowConfig* const config) {
        renderSystem::createWindow(config);

        do {
            collisionSystem->update();
            movementSystem->update();
            renderSystem::update();
        } while (glutGetWindow());
    }
}
