#ifndef INC_2D_POOL_TRANSFORMCOMPONENT_H
#define INC_2D_POOL_TRANSFORMCOMPONENT_H

#include <glm/glm.hpp>


namespace base {
    struct transformComponent final {
        glm::mat4 translation = glm::mat4(1.0f);
        [[maybe_unused]] glm::mat4 rotation = glm::mat4(1.0f);
        [[maybe_unused]] glm::mat4 scale = glm::mat4(1.0f);
    };
}


#endif //INC_2D_POOL_TRANSFORMCOMPONENT_H
