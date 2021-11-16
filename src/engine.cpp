#include <engine.h>


namespace base {
    float engine::fps = 240.0f;

    entityManager* engine::entityManager;
    componentManager* engine::componentManager;
    systemManager* engine::systemManager;

    physics2DSystem* engine::physicsSystem;
    accelerationSystem* engine::accelerationSystem;


    void engine::getInstances() {
        entityManager = &entityManager::getInstance();
        componentManager = &componentManager::getInstance();
        systemManager = &systemManager::getInstance();

        physicsSystem = &physics2DSystem::getInstance();
        accelerationSystem = &accelerationSystem::getInstance();
    }

    void engine::start() {
        std::printf("Engine started!\n");
        getInstances();
    }

    void engine::play(const windowConfig* const config) {
        renderSystem::createWindow(config);

        fps += (float) (fps == 0.0f);
        do {
            physicsSystem->update();
            accelerationSystem->update(1.0f / fps);
            renderSystem::update();
        } while (glutGetWindow());
    }
}
