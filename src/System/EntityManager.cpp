#include "EntityManager.hpp"

#include <algorithm>

#include "Game/Entities/Entity.hpp"

namespace Pong {

    EntityManager* EntityManager::m_instance = nullptr;

    EntityManager* EntityManager::getInstance() {
        if (m_instance) return m_instance;
        m_instance = new EntityManager();
        return m_instance;
    }

    void EntityManager::registerEntity(Entity *entity) {
        m_entities.push_back(entity);

        if (m_started) entity->start();
    }

    void EntityManager::unregisterEntity(Entity *entity) {
        m_entities.erase(
                std::ranges::remove(m_entities, entity).begin(),
                m_entities.end()
            );
    }

    void EntityManager::start() {
        for (auto* entity : m_entities) {
            entity->start();
        }

        m_started = true;
    }

    void EntityManager::update(float dt) const {
        for (auto* entity : m_entities) {
            entity->update(dt);
        }
    }
}
