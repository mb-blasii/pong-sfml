#pragma once
#include <vector>

namespace Pong {
    class Entity;


    class EntityManager {
    private:
        static EntityManager *m_instance;
        std::vector<Entity *> m_entities;

        EntityManager() = default;

        ~EntityManager() = default;

    public:
        static EntityManager *getInstance();

        void registerEntity(Entity *entity);

        void unregisterEntity(Entity *entity);

        void start() const;

        void update(float dt) const;
    };
}
