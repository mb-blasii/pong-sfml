#pragma once
#include "Entity.hpp"
#include "Game/Graphics/BallShape.hpp"
#include <atlas/physics/shapes/shape2d.h>

#include "atlas/core/transform/transform.h"

namespace Pong {
    class Paddle;

    class Ball : public Entity {
    public:
        explicit Ball();

        ~Ball() override = default;

        void update(float dt) override;
        void start() override;

    private:
        const float SPEED = 500.f;
        float m_accSpeed = 0; //Accumulated Speed
        atlas::core::vec::Vec3 m_dir;

        Paddle* m_padL = nullptr;
        Paddle* m_padR = nullptr;

        atlas::physics::shape::Box2D* m_boxTop = nullptr;
        atlas::physics::shape::Box2D* m_boxBottom = nullptr;
        atlas::physics::shape::Box2D* m_boxLeft = nullptr;
        atlas::physics::shape::Box2D* m_boxRight = nullptr;

        atlas::core::transform::Transform m_transform;
        BallShape m_ballShape;
        atlas::physics::shape::Circle m_localCircle;
        atlas::physics::shape::Circle m_worldCircle;


        //Utility
        bool hasBounce(const atlas::physics::shape::Box2D& box) const;
    };
}
