#ifndef INC_2D_POOL_COLLIDER2DCOMPONENT_H
#define INC_2D_POOL_COLLIDER2DCOMPONENT_H

#include <glm/glm.hpp>
#include <vector>


namespace base {
    struct collider2DComponent final {
        std::vector<glm::vec2> points;
        bool isTrigger = false;
    };
}


#endif //INC_2D_POOL_COLLIDER2DCOMPONENT_H
