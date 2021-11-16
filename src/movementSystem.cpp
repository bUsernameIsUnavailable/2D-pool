#include <movementSystem.h>
#include <collider2DComponent.h>
#include <engine.h>
#include <rigidbody2DComponent.h>
#include <transformComponent.h>


namespace base {
    void movementSystem::update() const {
        for (const auto& entity : entities) {
            auto& transform = engine::getComponent<transformComponent>(entity);
            auto& collider2D = engine::getComponent<collider2DComponent>(entity);
            const auto& rigidbody2D = engine::getComponent<rigidbody2DComponent>(entity);

            std::for_each(collider2D.points.begin(), collider2D.points.end(), [&rigidbody2D](glm::vec2& point) {
                point += rigidbody2D.velocity / rigidbody2D.mass;
            });
            transform.translation = glm::translate(
                    transform.translation,
                    glm::vec3(rigidbody2D.velocity.x, rigidbody2D.velocity.y, 0.0f) / rigidbody2D.mass
            );
        }
    }
}
