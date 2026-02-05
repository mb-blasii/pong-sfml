#pragma once
#include <vector>

namespace Pong {
    class Entity;


    class EntityManager {
    private:
        bool m_started = false;
        static EntityManager *m_instance;
        std::vector<Entity *> m_entities;

        EntityManager() = default;

        ~EntityManager() = default;

    public:
        static EntityManager *getInstance();

        void registerEntity(Entity *entity);

        void unregisterEntity(Entity *entity);

        void start();

        void update(float dt) const;
    };
}
