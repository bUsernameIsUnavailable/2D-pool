#ifndef INC_2D_POOL_COMPONENTMANAGER_H
#define INC_2D_POOL_COMPONENTMANAGER_H

#include "ecsTypes.h"
#include "singleton.h"

#include <array>
#include <cassert>
#include <memory>
#include <unordered_map>


namespace base {
    class componentArrayBase {
    public:
        virtual ~componentArrayBase() = 0;
        virtual void onEntityDestroyed(const Entity&) = 0;
    };

    template<typename T>
    class componentArray : public componentArrayBase {
        size_t size = 0u;
        std::array<T, maxEntityCount> components;
        std::unordered_map<Entity, size_t> mapEntityToIndex;
        std::unordered_map<size_t, Entity> mapIndexToEntity;

    public:
        void insertData(const Entity& entity, const T& component) {
            assert(mapEntityToIndex.find(entity) == mapEntityToIndex.end() && "Entity already has component!");

            mapEntityToIndex[entity] = size;
            mapIndexToEntity[size] = entity;
            components[size] = component;

            ++size;
        }

        void removeData(const Entity& entity) {
            assert(mapEntityToIndex.find(entity) != mapEntityToIndex.end() && "Entity doesn't own component!");

            constexpr size_t removedIndex = mapEntityToIndex[entity];
            constexpr size_t lastIndex = size - 1u;
            components[removedIndex] = components[lastIndex];

            constexpr Entity lastElement = mapIndexToEntity[lastIndex];
            mapEntityToIndex[lastElement] = removedIndex;
            mapIndexToEntity[removedIndex] = lastElement;

            mapEntityToIndex.erase(entity);
            mapIndexToEntity.erase(lastIndex);
            --size;
        }

        const T& getData(const Entity& entity) {
            assert(mapEntityToIndex.find(entity) != mapEntityToIndex.end() && "Entity doesn't own component!");

            return components[mapEntityToIndex[entity]];
        }

        void onEntityDestroyed(const Entity& entity) override {
            if (mapEntityToIndex.find(entity) == mapEntityToIndex.end())
                return;

            removeData(entity);
        }
    };

    class componentManager : public utils::singleton<componentManager> {
        static ComponentType nextComponentType;
        static std::unordered_map<const char*, ComponentType> componentTypes;
        static std::unordered_map<const char*, std::shared_ptr<componentArrayBase>> componentArrays;

        template<typename T>
        static std::shared_ptr<componentArray<T>> getComponentArray() {
            const char* const typeName = typeid(T).name();
            assert(componentTypes.find(typeName) != componentTypes.end() && "Component is not registered!");

            return std::static_pointer_cast<componentArray<T>>(componentArrays[typeName]);
        }

    public:
        template<typename T>
        static void registerComponent() {
            const char* const typeName = typeid(T).name();
            assert(componentTypes.find(typeName) == componentTypes.end() && "Component is already registered!");

            componentTypes.insert({ typeName, nextComponentType });
            componentArrays.insert({ typeName, std::make_shared<componentArray<T>>() });
            ++nextComponentType;
        }

        template<typename T>
        static const ComponentType& getComponentType() {
            const char* const typeName = typeid(T).name();
            assert(componentTypes.find(typeName) != componentTypes.end() && "Component is not registered!");

            return componentTypes[typeName];
        }

        template<typename T>
        inline static void addComponent(const Entity& entity, const T& component) {
            getComponentArray<T>()->insertData(entity, component);
        }

        template<typename T>
        inline static void removeComponent(const Entity& entity) {
            getComponentArray<T>()->removeData(entity);
        }

        template<typename T>
        inline static const T& getComponent(const Entity& entity) {
            getComponentArray<T>()->getData(entity);
        }

        static void onEntityDestroyed(const Entity& entity) {
            for (const auto& pair : componentArrays) {
                pair.second->onEntityDestroyed(entity);
            }
        }
    };
}


#endif //INC_2D_POOL_COMPONENTMANAGER_H
