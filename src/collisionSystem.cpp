#include <engine.h>
#include <collisionSystem.h>
#include <rigidbody2DComponent.h>


namespace base {
    void collisionSystem::update() const {
        for (const auto& entityFrom : entities) {
            auto& rigidbodyFrom = engine::getComponent<rigidbody2DComponent>(entityFrom);
            const auto& colliderFrom = engine::getComponent<collider2DComponent>(entityFrom);

            if (colliderFrom.isTrigger)
                continue;

            for (const auto& entityTo : entities) {
                if (entityFrom >= entityTo)
                    continue;

                auto& rigidbodyTo = engine::getComponent<rigidbody2DComponent>(entityTo);
                const auto& colliderTo = engine::getComponent<collider2DComponent>(entityTo);

                if (colliderTo.isTrigger)
                    continue;

                const glm::vec2 overlapFromTo = physics2DManager::getOverlap(colliderFrom, colliderTo);
                if (overlapFromTo == glm::vec2(0.0f, 0.0f))
                    continue;

                const glm::vec2 overlapToFrom = physics2DManager::getOverlap(colliderTo, colliderFrom);
                if (overlapToFrom == glm::vec2(0.0f, 0.0f))
                    continue;

                const bool& isOverlapFromTo = glm::length(overlapFromTo) <= glm::length(overlapToFrom);
                const glm::vec2& overlap = glm::normalize(
                        (float) isOverlapFromTo * overlapFromTo
                        + (float) !isOverlapFromTo * overlapToFrom
                );

                const float& inverseMassFrom = 1.0f / rigidbodyFrom.mass;
                const float& inverseMassTo = 1.0f / rigidbodyTo.mass;
                const float& reducedMass = 1.0f / (inverseMassFrom + inverseMassTo);

                const glm::vec2& impulse = glm::dot(rigidbodyFrom.velocity - rigidbodyTo.velocity, overlap)
                        * -(1.0f + restitution) * reducedMass * overlap;

                rigidbodyFrom.velocity += impulse * inverseMassFrom;
                rigidbodyTo.velocity -= impulse * inverseMassTo;
            }
        }
    }
}
