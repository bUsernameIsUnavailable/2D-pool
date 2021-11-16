#ifndef INC_2D_POOL_ENTITYMANAGER_H
#define INC_2D_POOL_ENTITYMANAGER_H

#include <ecsTypes.h>
#include <singleton.h>

#include <array>
#include <cassert>
#include <queue>


namespace base {
    class entityManager final : public utils::singleton<entityManager> {
        Entity livingEntityCount = 0u;
        std::queue<Entity> availableEntities;
        std::array<Signature, maxEntityCount> signatures;

    public:
        entityManager() {
            for (Entity entity = 0u; entity < maxEntityCount; ++entity) {
                availableEntities.push(entity);
            }
        }

        const Entity& createEntity() {
            assert(livingEntityCount < maxEntityCount && "Too many entities have been created!");

            const Entity& entity = availableEntities.front();
            availableEntities.pop();
            ++livingEntityCount;

            return entity;
        }

        void destroyEntity(const Entity& entity) {
            assert(entity < maxEntityCount && "Entity is out of range!");

            signatures[entity].reset();
            availableEntities.push(entity);
            --livingEntityCount;
        }

        [[nodiscard]] const Signature& getSignature(const Entity& entity) const {
            assert(entity < maxEntityCount && "Entity is our of range!");

            return signatures[entity];
        }

        void setSignature(const Entity& entity, const Signature& signature) {
            assert(entity < maxEntityCount && "Entity is our of range!");

            signatures[entity] = signature;
        }
    };
}


#endif //INC_2D_POOL_ENTITYMANAGER_H
