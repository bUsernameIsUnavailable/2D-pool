#ifndef INC_2D_POOL_SYSTEMMANAGER_H
#define INC_2D_POOL_SYSTEMMANAGER_H

#include <ecsTypes.h>
#include <singleton.h>

#include <cassert>
#include <memory>
#include <set>
#include <unordered_map>


namespace base {
    class systemManager;

    class system {
        friend class systemManager;

    protected:
        std::set<Entity> entities;
    };

    class systemManager : public utils::singleton<systemManager> {
    public:
        std::unordered_map<const char*, system* const> systems;
        std::unordered_map<const char*, const Signature> signatures;

    public:
        template<typename T>
        void registerSystem(system* const system) {
            const char* const typeName = typeid(T).name();
            assert(systems.find(typeName) == systems.end() && "System is already registered!");

            systems.insert({ typeName, system });
        }

        template<typename T>
        void setSignature(const Signature& signature) {
            const char* const typeName = typeid(T).name();
            assert(systems.find(typeName) != systems.end() && "System is not registered!");

            signatures.insert({ typeName, signature });
        }

        void onEntityDestroyed(const Entity& entity) {
            for (const auto& pair : systems) {
                pair.second->entities.erase(entity);
            }
        }

        void onEntitySignatureChanged(const Entity& entity, const Signature& entitySignature) {
            for (const auto& pair : systems) {
                const auto& systemSignature = signatures[pair.first];
                auto& systemEntities = pair.second->entities;

                if ((entitySignature & systemSignature) == systemSignature) {
                    systemEntities.insert(entity);
                }
                else {
                    systemEntities.erase(entity);
                }
            }
        }
    };
}


#endif //INC_2D_POOL_SYSTEMMANAGER_H
