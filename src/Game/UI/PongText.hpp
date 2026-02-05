#pragma once
#include "Game/Globals.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "System/Renderer.hpp"

namespace Pong {
    class Renderer;

    class PongText : public sf::Text {
        public:
        explicit PongText(const sf::Font& font) : Text(font) {
            setString("PONG");
            setCharacterSize(224);
            setFillColor(sf::Color::White);

            auto bounds = getGlobalBounds();
            setOrigin({bounds.getCenter().x, 0});
            setPosition({0, -(SCREEN_HEIGHT / 2.f - 50) });

            Renderer::getInstance()->registerDrawable(this);
        }
    };
}
