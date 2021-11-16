#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <accelerationSystem.h>
#include <componentManager.h>
#include <entityManager.h>
#include <physics2DSystem.h>
#include <renderSystem.h>
#include <singleton.h>
#include <systemManager.h>
#include <windowConfig.h>

#include <memory>


namespace base {
    class engine final : public utils::singleton<engine> {
        static float fps;

        static entityManager* entityManager;
        static componentManager* componentManager;
        static systemManager* systemManager;

        static physics2DSystem* physicsSystem;
        static accelerationSystem* accelerationSystem;

        static void getInstances();

    public:
        static void start();
        static void play(const windowConfig*);

        inline static const Entity& createEntity() { return entityManager->createEntity(); }

        static void destroyEntity(const Entity& entity) {
            entityManager->destroyEntity(entity);
            componentManager->onEntityDestroyed(entity);
            systemManager->onEntityDestroyed(entity);
        }

        template<typename T>
        inline static void registerComponent() {
            componentManager->registerComponent<T>();
        }

        template<typename T>
        inline static const ComponentType& getComponentType() {
            return componentManager->getComponentType<T>();
        }

        template<typename T>
        static void addComponent(const Entity& entity, const T& component) {
            componentManager->addComponent<T>(entity, component);

            Signature signature = entityManager->getSignature(entity);
            signature.set(componentManager->getComponentType<T>(), true);

            entityManager->setSignature(entity, signature);
            systemManager->onEntitySignatureChanged(entity, signature);
        }

        template<typename T>
        static void removeComponent(const Entity& entity) {
            componentManager->removeComponent<T>(entity);

            const Signature signature = entityManager->getSignature(entity);
            signature.set(componentManager->getComponentType<T>(), false);

            entityManager->setSignature(entity, signature);
            systemManager->onEntitySignatureChanged(entity, signature);
        }

        template<typename T>
        inline static T& getComponent(const Entity& entity) {
            return componentManager->getComponent<T>(entity);
        }

        template<typename T>
        inline static void registerSystem(system* const system) {
            systemManager->registerSystem<T>(system);
        }

        template<typename T>
        inline static void setSystemSignature(const Signature& signature) {
            return systemManager->setSignature<T>(signature);
        }
    };
}


#endif //GRAPHICS_ENGINE_H
