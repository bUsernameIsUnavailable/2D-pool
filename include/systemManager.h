#ifndef INC_2D_POOL_SYSTEMMANAGER_H
#define INC_2D_POOL_SYSTEMMANAGER_H

#include "ecsTypes.h"
#include "singleton.h"

#include <cassert>
#include <memory>
#include <set>
#include <unordered_map>


namespace base {
    struct system {
        std::set<Entity> entities;
    };

    class systemManager : public utils::singleton<systemManager> {
        static std::unordered_map<const char*, std::shared_ptr<system>> systems;
        static std::unordered_map<const char*, Signature> signatures;

    public:
        template<typename T>
        static std::shared_ptr<T> registerSystem() {
            const char* const typeName = typeid(T).name();
            assert(systems.find(typeName) == systems.end() && "System is already registered!");

            auto system = std::make_shared<T>();
            systems.insert({ typeName, system });
            return system;
        }

        template<typename T>
        static void setSignature(const Signature& signature) {
            const char* const typeName = typeid(T).name();
            assert(systems.find(typeName) != systems.end() && "System is not registered!");

            signatures.insert({ typeName, signature });
        }

        static void onEntityDestroyed(const Entity& entity) {
            for (const auto& pair : systems) {
                pair.second->entities.erase(entity);
            }
        }

        static void onEntitySignatureChanged(const Entity& entity, const Signature& entitySignature) {
            for (const auto& pair : systems) {
                const auto& systemSignature = signatures[pair.first];

                if ((entitySignature & systemSignature) == systemSignature) {
                    pair.second->entities.insert(entity);
                }
                else {
                    pair.second->entities.erase(entity);
                }
            }
        }
    };
}


#endif //INC_2D_POOL_SYSTEMMANAGER_H
