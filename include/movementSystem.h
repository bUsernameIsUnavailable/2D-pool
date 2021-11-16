#ifndef INC_2D_POOL_MOVEMENTSYSTEM_H
#define INC_2D_POOL_MOVEMENTSYSTEM_H

#include <systemManager.h>


namespace base {
    class movementSystem : public system, public utils::singleton<movementSystem> {
    public:
        void update() const;
    };
}


#endif //INC_2D_POOL_MOVEMENTSYSTEM_H
