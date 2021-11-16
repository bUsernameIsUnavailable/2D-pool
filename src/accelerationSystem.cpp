#include <accelerationSystem.h>
#include <collider2DComponent.h>
#include <engine.h>
#include <rigidbody2DComponent.h>
#include <transformComponent.h>


namespace base {
    void accelerationSystem::update(const float& fixedDeltaTime) const {
        for (const auto& entity : entities) {
            auto& transform = engine::getComponent<transformComponent>(entity);
            auto& collider2D = engine::getComponent<collider2DComponent>(entity);
            auto& rigidbody2D = engine::getComponent<rigidbody2DComponent>(entity);

            glm::mat4& translation = transform.translation;
            std::vector<glm::vec2>& points = collider2D.points;
            glm::vec2& velocity = rigidbody2D.velocity;

            velocity = glm::normalize(glm::vec2(0.0f, 0.2f)) * fixedDeltaTime;
            std::for_each(points.begin(), points.end(), [&velocity](glm::vec2& point) {
                point += velocity;
            });
            translation = glm::translate(translation,glm::vec3(velocity.x, velocity.y, 0.0f));
        }
    }
}
