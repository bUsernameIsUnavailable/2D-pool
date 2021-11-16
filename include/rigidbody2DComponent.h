#ifndef INC_2D_POOL_RIGIDBODY2DCOMPONENT_H
#define INC_2D_POOL_RIGIDBODY2DCOMPONENT_H

#include <glm/glm.hpp>
#include <limits>


namespace base {
    struct rigidbody2DComponent {
        glm::vec2 velocity;
        float mass = std::numeric_limits<float>::infinity();
    };
}


#endif //INC_2D_POOL_RIGIDBODY2DCOMPONENT_H
