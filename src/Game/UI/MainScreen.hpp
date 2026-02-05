#pragma once
#include "PongText.hpp"
#include "StartText.hpp"
#include "SFML/Graphics/Font.hpp"

namespace Pong {
    class MainScreen {
    public:
        MainScreen() {
            if (m_font.openFromFile("res/fonts/Square.ttf")) {
                m_pongTxt = new PongText(m_font);
                m_startTxt = new StartText(m_font);
            }
        }

        void hide() const {
            auto renderer = Renderer::getInstance();

            renderer->unregisterDrawable(m_pongTxt);
            renderer->unregisterDrawable(m_startTxt);
        }

    private:
        PongText* m_pongTxt;
        StartText* m_startTxt;
        sf::Font m_font;
    };
}