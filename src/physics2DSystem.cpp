#include <engine.h>
#include <physics2DSystem.h>
#include <transformComponent.h>


namespace base {
    void physics2DSystem::update() {
        colliderEntities.clear();
        for (const auto& entity : entities) {
            colliderEntities.push_back(entity);
        }

        for (unsigned int index1 = 0u; index1 < colliderEntities.size(); ++index1) {
            auto& transform1 = engine::getComponent<transformComponent>(colliderEntities[index1]);
            const auto& collider1 = engine::getComponent<collider2DComponent>(colliderEntities[index1]);

            for (unsigned int index2 = index1 + 1u; index2 < colliderEntities.size(); ++index2) {
                auto& transform2 = engine::getComponent<transformComponent>(colliderEntities[index2]);
                const auto& collider2 = engine::getComponent<collider2DComponent>(colliderEntities[index2]);

                if (!collision2DManager::areOverlapping(collider1, collider2)
                || !collision2DManager::areOverlapping(collider2, collider1))
                    continue;
            }
        }
    }
}
