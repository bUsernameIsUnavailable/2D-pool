#include <windowManager.h>


namespace base {
    std::vector<windowConfig*> windowManager::windows;

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
