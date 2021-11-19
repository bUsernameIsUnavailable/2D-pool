#ifndef INC_2D_POOL_PHYSICS2DMANAGER_H
#define INC_2D_POOL_PHYSICS2DMANAGER_H

#include <collider2DComponent.h>
#include <singleton.h>


namespace base {
    class physics2DManager final : public utils::singleton<physics2DManager> {
    public:
        static constexpr float minSpeed = 0.0001f;

        static glm::vec2 getOverlap(const collider2DComponent&, const collider2DComponent&);
    };
}


#endif //INC_2D_POOL_PHYSICS2DMANAGER_H
