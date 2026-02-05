#pragma once
#include "System/EntityManager.hpp"

namespace Pong {

    class Entity {
        public:
        virtual ~Entity() {EntityManager::getInstance()->unregisterEntity(this);}
        Entity() {EntityManager::getInstance()->registerEntity(this);}

        virtual void update(float dt) {};
        virtual void start() {};
    };
}
