#include "GameBorder.hpp"

#include "atlas/physics/shapes/shape2d.h"
#include <Game/Globals.hpp>

namespace Pong {
    GameBorder::GameBorder() {
        boxTop = new atlas::physics::shape::Box2D();
        boxBottom = new atlas::physics::shape::Box2D();
        boxLeft = new atlas::physics::shape::Box2D();
        boxRight = new atlas::physics::shape::Box2D();

        boxTop->center = {0, -(SCREEN_HEIGHT / 2.f)};
        boxTop->halfExtents = {SCREEN_WIDTH / 2.f, 20};
        boxTop->axes[0] = {1, 0};
        boxTop->axes[1] = {0, 1};

        boxBottom->center = {0, SCREEN_HEIGHT / 2.f};
        boxBottom->halfExtents = {SCREEN_WIDTH / 2.f, 20};
        boxBottom->axes[0] = {1, 0};
        boxBottom->axes[1] = {0, 1};

        boxLeft->center = {-(SCREEN_WIDTH / 2.f), 0};
        boxLeft->halfExtents = {20, SCREEN_HEIGHT / 2.f};
        boxLeft->axes[0] = {1, 0};
        boxLeft->axes[1] = {0, 1};

        boxRight->center = {SCREEN_WIDTH / 2.f, 0};
        boxRight->halfExtents = {20, SCREEN_HEIGHT / 2.f};
        boxRight->axes[0] = {1, 0};
        boxRight->axes[1] = {0, 1};
    }
}
