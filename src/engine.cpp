#include <engine.h>


namespace base {
    float engine::fps = 300.0f;

    entityManager* engine::entityManager;
    componentManager* engine::componentManager;
    systemManager* engine::systemManager;

    elasticCollisionSystem* engine::elasticCollisionSystem;
    movementSystem* engine::movementSystem;


    void engine::getInstances() {
        entityManager = &entityManager::getInstance();
        componentManager = &componentManager::getInstance();
        systemManager = &systemManager::getInstance();

        elasticCollisionSystem = &elasticCollisionSystem::getInstance();
        movementSystem = &movementSystem::getInstance();
    }

    void engine::start() {
        std::printf("Engine started!\n");
        getInstances();
    }

    void engine::play(const windowConfig* const config) {
        renderSystem::createWindow(config);

        fps += (float) (fps == 0.0f);
        do {
            elasticCollisionSystem->update(1.0f / fps);
            movementSystem->update();
            renderSystem::update();
        } while (glutGetWindow());
    }
}
