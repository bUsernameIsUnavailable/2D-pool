#ifndef INC_2D_POOL_COLLISIONSYSTEM_H
#define INC_2D_POOL_COLLISIONSYSTEM_H

#include <physics2DManager.h>
#include <systemManager.h>


namespace base {
    class collisionSystem final : public system, public utils::singleton<collisionSystem> {
        static constexpr float restitution = 1.0f;

    public:
        void update() const;
    };
}


#endif //INC_2D_POOL_COLLISIONSYSTEM_H
