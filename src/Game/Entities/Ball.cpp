#include "Ball.hpp"

#include <random>

#include "GameBorder.hpp"
#include "Paddle.hpp"
#include "Conversions/AtlasConversions.hpp"
#include "System/Renderer.hpp"
#include "System/Scene.hpp"

namespace Pong {

    //Utility
    atlas::core::vec::Vec3 computeBounceDirection(
    const atlas::core::vec::Vec3& currentDir,
    float yVariation = 0.75f,
    float maxYAbs = 0.85f
)
    {
        static std::mt19937 rng{ std::random_device{}() };
        std::uniform_real_distribution<float> dist(-yVariation, yVariation);

        atlas::core::vec::Vec3 newDir;

        newDir.x = -currentDir.x;

        float signY = (currentDir.y >= 0.f) ? 1.f : -1.f;
        float absY  = std::abs(currentDir.y);

        absY += dist(rng);
        absY = std::clamp(absY, 0.05f, maxYAbs);

        newDir.y = absY * signY;

        return newDir.normalized();
    }

    bool Ball::hasBounce(const atlas::physics::shape::Box2D& box) const {
        return atlas::physics::shape::overlap(box.computeRect(), m_worldCircle);
    }

    Ball::Ball() {
        Renderer::getInstance()->registerDrawable(&m_ballShape);

        m_transform.setLocalScale({10, 10, 0});

        std::random_device rd;

        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(-100, 100);

        m_dir.x = distrib(gen);
        m_dir.y = distrib(gen) / 2.f;
        m_dir.normalize();
    }

    void Ball::update(float dt) {
        m_transform.translateWorld(m_dir * ((SPEED + m_accSpeed) * dt));
        auto pos = m_transform.getWorldPosition();
        m_ballShape.setPosition({pos.x, pos.y});

        localToWorld(m_localCircle, m_transform.getWorldMatrix(), m_worldCircle);

        if (hasBounce(*m_padL->m_worldBox) || hasBounce(*m_padR->m_worldBox)) {
            m_dir = computeBounceDirection(m_dir);
            m_accSpeed += 25;
        }

        if (hasBounce(*m_boxTop) || hasBounce(*m_boxBottom))
            m_dir = {m_dir.x, -m_dir.y, m_dir.z};

        if (hasBounce(*m_boxLeft) || hasBounce(*m_boxRight))
            m_dir *= 0;

    }

    void Ball::start() {
        auto scene = Scene::getInstance();

        m_padL = scene->paddle_L;
        m_padR = scene->paddle_R;

        m_boxTop = scene->gameBorder->boxTop;
        m_boxBottom = scene->gameBorder->boxBottom;
        m_boxLeft = scene->gameBorder->boxLeft;
        m_boxRight = scene->gameBorder->boxRight;
    }
}
