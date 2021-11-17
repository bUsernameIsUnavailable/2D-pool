#include <engine.h>
#include <collisionSystem.h>
#include <rigidbody2DComponent.h>


namespace base {
    void collisionSystem::update(const float& fixedDeltaTime) {
        colliderEntities.clear();
        for (const auto &entity: entities) {
            colliderEntities.push_back(entity);
        }

        for (unsigned int indexFrom = 0u; indexFrom < colliderEntities.size() - 1u; ++indexFrom) {
            auto& rigidbodyFrom = engine::getComponent<rigidbody2DComponent>(colliderEntities[indexFrom]);
            const auto& colliderFrom = engine::getComponent<collider2DComponent>(colliderEntities[indexFrom]);

            for (unsigned int indexTo = indexFrom + 1u; indexTo < colliderEntities.size(); ++indexTo) {
                auto& rigidbodyTo = engine::getComponent<rigidbody2DComponent>(colliderEntities[indexTo]);
                const auto& colliderTo = engine::getComponent<collider2DComponent>(colliderEntities[indexTo]);

                const glm::vec2 overlapFromTo = collision2DManager::getOverlap(colliderFrom, colliderTo);
                if (overlapFromTo == glm::vec2(0.0f, 0.0f))
                    continue;

                const glm::vec2 overlapToFrom = collision2DManager::getOverlap(colliderTo, colliderFrom);
                if (overlapToFrom == glm::vec2(0.0f, 0.0f))
                    continue;

                glm::vec2 overlap((float) (!colliderFrom.isTrigger && !colliderTo.isTrigger) * fixedDeltaTime);
                if (glm::length(overlapFromTo) <= glm::length(overlapToFrom)) {
                    overlap *= overlapFromTo;
                }
                else {
                    overlap *= overlapToFrom;
                }
                const float& inverseMassFrom = 1.0f / rigidbodyFrom.mass;
                const float& inverseMassTo = 1.0f / rigidbodyTo.mass;
                const float& inverseMassSum = inverseMassFrom + inverseMassTo;

                rigidbodyFrom.velocity += overlap * inverseMassFrom / inverseMassSum;
                rigidbodyTo.velocity -= overlap * inverseMassTo / inverseMassSum;

                const glm::vec2& tangent = glm::normalize(overlap);
                const glm::vec2& impulse = glm::dot(rigidbodyFrom.velocity - rigidbodyTo.velocity, tangent)
                        * -(1.0f + restitution) / inverseMassSum * tangent;

                rigidbodyFrom.velocity += impulse * inverseMassFrom;
                rigidbodyTo.velocity -= impulse * inverseMassTo;
            }
        }
    }
}
