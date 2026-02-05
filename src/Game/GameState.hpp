#pragma once

namespace Pong {
    class GameState {
        public:
        bool isPlaying = false;
        int scoreLeft = 0;
        int scoreRight = 0;

    //singleton
    public:
        static GameState* getInstance();

        void setScoreLeft();
        void setScoreRight();
    private:
        GameState() = default;
        ~GameState() = default;

        static GameState* m_instance;
    };
}
