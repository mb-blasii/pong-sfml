#include "Scene.hpp"

#include "Game/Entities/Ball.hpp"
#include "Game/Entities/GameBorder.hpp"
#include "Game/Entities/Paddle.hpp"
#include "Game/Graphics/DashedLineShape.hpp"

namespace Pong {
    Scene* Scene::m_instance = nullptr;

    Scene::Scene() {
        dashedLine = new DashedLineShape();
        gameBorder = new GameBorder();
        paddle_L = new Paddle(Paddle::Left);
        paddle_R = new Paddle(Paddle::Right);
        ball = new Ball();

        //UI
        mainScreen = new MainScreen();

    }

    Scene* Scene::getInstance() {
        if (m_instance) return m_instance;

        m_instance = new Scene();
        return m_instance;
    }
}
