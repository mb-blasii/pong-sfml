#pragma once
#include "Entity.hpp"
#include <Game/Globals.hpp>

#include "Game/Graphics/PaddleShape.h"
#include "SFML/Window/Keyboard.hpp"
#include <atlas/physics/shapes/shape2d.h>
#include <atlas/core/transform/transform.h>

namespace Pong {

class Paddle : public Entity {

public:
    enum Side {
        Left,
        Right,
    };

    explicit Paddle(Side side);

    ~Paddle() override = default;

    void update(float dt) override;
    void start() override {};

    atlas::physics::shape::Box2D* m_worldBox;
    private:
    atlas::core::transform::Transform m_transform;

    PaddleShape* m_paddleShape = new PaddleShape();
    atlas::physics::shape::Box2D* m_localBox;

    Side m_side;
    float m_posX, m_posY;
    sf::Keyboard::Key m_upKey, m_downKey;

    const float PADDLE_SPEED = 350.f; //250

    const float SIDE_MARGIN = 100.f;
    const float POS_X = SCREEN_WIDTH / 2.0f - SIDE_MARGIN; //R-side value

    static constexpr float WIDTH  = 12.f;
    static constexpr float HEIGHT = 200.f;

};

}
