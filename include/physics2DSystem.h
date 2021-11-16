#ifndef INC_2D_POOL_PHYSICS2DSYSTEM_H
#define INC_2D_POOL_PHYSICS2DSYSTEM_H

#include <collision2DManager.h>
#include <systemManager.h>


namespace base {
    class physics2DSystem final : public system, public utils::singleton<physics2DSystem> {
        std::vector<Entity> colliderEntities;

    public:
        void update();
    };
}


#endif //INC_2D_POOL_PHYSICS2DSYSTEM_H
