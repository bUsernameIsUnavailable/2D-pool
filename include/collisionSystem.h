#ifndef INC_2D_POOL_COLLISIONSYSTEM_H
#define INC_2D_POOL_COLLISIONSYSTEM_H

#include <collision2DManager.h>
#include <systemManager.h>


namespace base {
    class collisionSystem final : public system, public utils::singleton<collisionSystem> {
        std::vector<Entity> colliderEntities;
        static constexpr float restitution = 1.0f;

    public:
        void update(const float&);
    };
}


#endif //INC_2D_POOL_COLLISIONSYSTEM_H
