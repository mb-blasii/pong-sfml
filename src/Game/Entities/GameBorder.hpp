#pragma once
#include "Game/Graphics/GameBorderShape.hpp"

namespace atlas::physics::shape {
    struct Box2D;
}

namespace Pong {
    class GameBorder {

        public:
        GameBorder();

        GameBorderShape borderShape;
        atlas::physics::shape::Box2D* boxTop;
        atlas::physics::shape::Box2D* boxBottom;
        atlas::physics::shape::Box2D* boxLeft;
        atlas::physics::shape::Box2D* boxRight;
    };
}
