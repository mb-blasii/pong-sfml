#include "Paddle.hpp"

#include "System/Renderer.hpp"
#include <Conversions/AtlasConversions.hpp>

namespace Pong {

    Paddle::Paddle(Side side) {
        m_side = side;

        m_posY = 0;
        m_posX = side == Left ? -POS_X : POS_X;

        m_upKey = side == Left ? sf::Keyboard::Key::W : sf::Keyboard::Key::Up;
        m_downKey = side == Left ? sf::Keyboard::Key::S : sf::Keyboard::Key::Down;

        Renderer::getInstance()->registerDrawable(m_paddleShape);

        m_localBox = new atlas::physics::shape::Box2D();
        m_worldBox = new atlas::physics::shape::Box2D();
        m_localBox->center = {0, 0};
        m_localBox->halfExtents = {0.5f, 0.5f};
        m_localBox->axes[0] = {1, 0};
        m_localBox->axes[1] = {0, 1};

        m_transform.setLocalScale({WIDTH, HEIGHT, 1.0f});
        m_transform.setLocalPosition({m_posX, m_posY, 0.0f});

        m_paddleShape->setSize({WIDTH, HEIGHT});
        m_paddleShape->setOrigin({WIDTH / 2.f, HEIGHT / 2.f});
        m_paddleShape->setPosition({m_posX, m_posY});

        localToWorld(*m_localBox, m_transform.getWorldMatrix(), *m_worldBox);
    }

    void Paddle::update(float dt) {

        if (sf::Keyboard::isKeyPressed(m_upKey)) {
            m_posY -= PADDLE_SPEED * dt;
            if (m_posY <= -225.f) m_posY = -225.f;

            m_transform.setWorldPosition({m_posX, m_posY, 0});
            m_paddleShape->setPosition({ m_posX, m_posY });

            localToWorld(*m_localBox, m_transform.getWorldMatrix(), *m_worldBox);
        }

        if (sf::Keyboard::isKeyPressed(m_downKey)) {
            m_posY += PADDLE_SPEED * dt;
            if (m_posY >= 225.f) m_posY = 225.f;

            m_transform.setWorldPosition({m_posX, m_posY, 0});
            m_paddleShape->setPosition({ m_posX, m_posY });

            localToWorld(*m_localBox, m_transform.getWorldMatrix(), *m_worldBox);
        }
    }
}
