#include "entityManager.h"


namespace base {
    Entity entityManager::livingEntityCount;
    std::queue<Entity> entityManager::availableEntities = 0;
    std::array<Signature, maxEntityCount> entityManager::signatures;
}
