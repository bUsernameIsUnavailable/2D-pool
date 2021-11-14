#include "systemManager.h"


namespace base {
    std::unordered_map<const char*, std::shared_ptr<system>> systemManager::systems = 0;
    std::unordered_map<const char*, Signature> systemManager::signatures = 0;
}
