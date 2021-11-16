#ifndef INC_2D_POOL_COLLISION2DMANAGER_H
#define INC_2D_POOL_COLLISION2DMANAGER_H

#include <collider2DComponent.h>
#include <singleton.h>


namespace base {
    class collision2DManager : public utils::singleton<collision2DManager> {
    public:
        static glm::vec2 getOverlap(const collider2DComponent&, const collider2DComponent&);
    };
}


#endif //INC_2D_POOL_COLLISION2DMANAGER_H
