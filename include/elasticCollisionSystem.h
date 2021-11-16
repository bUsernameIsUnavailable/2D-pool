#ifndef INC_2D_POOL_ELASTICCOLLISIONSYSTEM_H
#define INC_2D_POOL_ELASTICCOLLISIONSYSTEM_H

#include <collision2DManager.h>
#include <systemManager.h>


namespace base {
    class elasticCollisionSystem final : public system, public utils::singleton<elasticCollisionSystem> {
        std::vector<Entity> colliderEntities;

    public:
        void update(const float&);
    };
}


#endif //INC_2D_POOL_ELASTICCOLLISIONSYSTEM_H
