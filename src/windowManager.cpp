#include "windowManager.h"


namespace base {
    windowManager::~windowManager() {
        for (const auto& window : windows) {
            delete window;
        }
    }

    windowConfig* windowManager::createWindowConfig() {
        auto* const window = new windowConfig();
        windows.push_back(window);
        return window;
    }
}
