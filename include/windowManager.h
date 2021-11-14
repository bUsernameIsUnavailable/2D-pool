#ifndef INC_2D_POOL_WINDOWMANAGER_H
#define INC_2D_POOL_WINDOWMANAGER_H

#include "singleton.h"
#include "windowConfig.h"

#include <vector>


namespace base {
    class windowManager : public utils::singleton<windowManager> {
        std::vector<const windowConfig*> windows;

    public:
        ~windowManager() override;

        windowConfig* createWindowConfig();
    };
}


#endif //INC_2D_POOL_WINDOWMANAGER_H
