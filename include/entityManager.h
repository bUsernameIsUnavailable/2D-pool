#ifndef INC_2D_POOL_ENTITYMANAGER_H
#define INC_2D_POOL_ENTITYMANAGER_H

#include "ecsTypes.h"
#include "singleton.h"

#include <array>
#include <cassert>
#include <queue>


namespace base {
    class entityManager : public utils::singleton<entityManager> {
        static Entity livingEntityCount;
        static std::queue<Entity> availableEntities;
        static std::array<Signature, maxEntityCount> signatures;

    public:
        static void resetAvailableEntities() {
            for (Entity entity = 0u; entity < maxEntityCount; ++entity) {
                availableEntities.push(entity);
            }
        }

        static const Entity& createEntity() {
            assert(livingEntityCount < maxEntityCount && "Too many entities have been created!");

            const Entity& entity = availableEntities.front();
            availableEntities.pop();
            ++livingEntityCount;

            return entity;
        }

        static void destroyEntity(const Entity& entity) {
            assert(entity < maxEntityCount && "Entity is out of range!");

            signatures[entity].reset();
            availableEntities.push(entity);
            --livingEntityCount;
        }

        static const Signature& getSignature(const Entity& entity) {
            assert(entity < maxEntityCount && "Entity is our of range!");

            return signatures[entity];
        }

        static void setSignature(const Entity& entity, const Signature& signature) {
            assert(entity < maxEntityCount && "Entity is our of range!");

            signatures[entity] = signature;
        }
    };
}


#endif //INC_2D_POOL_ENTITYMANAGER_H
