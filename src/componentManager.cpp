#include "componentManager.h"


namespace base {
    ComponentType componentManager::nextComponentType;
    std::unordered_map<const char*, ComponentType> componentManager::componentTypes = 0;
    std::unordered_map<const char*, std::shared_ptr<componentArrayBase>> componentManager::componentArrays = 0;
}
