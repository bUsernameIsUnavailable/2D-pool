#ifndef INC_2D_POOL_WINDOWMANAGER_H
#define INC_2D_POOL_WINDOWMANAGER_H

#include <singleton.h>
#include <windowConfig.h>

#include <vector>


namespace base {
    class windowManager final : public utils::singleton<windowManager> {
        static std::vector<windowConfig*> windows;

    public:
        ~windowManager() override;

        static windowConfig* createWindowConfig();

        inline static windowConfig*& getWindow(const unsigned int& index = 0u) { return windows[index]; }
    };
}


#endif //INC_2D_POOL_WINDOWMANAGER_H
