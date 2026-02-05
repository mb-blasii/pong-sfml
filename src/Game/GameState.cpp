#include "GameState.hpp"

namespace Pong {
    GameState* GameState::m_instance = nullptr;

    GameState* GameState::getInstance() {
        if (m_instance) return m_instance;
        m_instance = new GameState();
        return m_instance;
    }

    void GameState::setScoreLeft() {
        scoreLeft++;
        isPlaying = false;
    }

    void GameState::setScoreRight() {
        scoreRight++;
        isPlaying = false;
    }
}
