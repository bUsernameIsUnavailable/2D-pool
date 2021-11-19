#ifndef INC_2D_POOL_RIGIDBODY2DCOMPONENT_H
#define INC_2D_POOL_RIGIDBODY2DCOMPONENT_H

#include <glm/glm.hpp>


namespace base {
    struct rigidbody2DComponent final {
        glm::vec2 velocity;
        float mass = 1000000000.0f;
    };
}


#endif //INC_2D_POOL_RIGIDBODY2DCOMPONENT_H
