#ifndef INC_2D_POOL_ACCELERATIONSYSTEM_H
#define INC_2D_POOL_ACCELERATIONSYSTEM_H

#include <systemManager.h>


namespace base {
    class accelerationSystem : public system, public utils::singleton<accelerationSystem> {
    public:
        void update(const float&) const;
    };
}


#endif //INC_2D_POOL_ACCELERATIONSYSTEM_H
