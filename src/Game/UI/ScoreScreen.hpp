#pragma once
#include "Score.hpp"

namespace Pong {
    class ScoreScreen {
    public:
        ScoreScreen() {
            if (m_font.openFromFile("res/fonts/Square.ttf")) {
                score = new Score(m_font);
            }
        }

        void hide() const {
            auto renderer = Renderer::getInstance();

        }

    private:
        Score* score;
        sf::Font m_font;
    };
}
