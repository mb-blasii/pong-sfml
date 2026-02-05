#pragma once

namespace Pong {
    class DashedLineShape;
    class GameBorder;
    class Ball;
    class Paddle;

    class Scene {

    //singleton
    public:
        static Scene* getInstance();

    private:
        static Scene* m_instance;

        Scene();
        ~Scene() = default;

    public:
        Paddle* paddle_L;
        Paddle* paddle_R;
        Ball* ball;
        GameBorder* gameBorder;
        DashedLineShape* dashedLine;
    };
}
