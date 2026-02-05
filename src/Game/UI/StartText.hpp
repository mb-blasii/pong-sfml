#pragma once
#include "Game/Globals.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "System/Renderer.hpp"

namespace Pong {
    class StartText : public sf::Text {
        public:
        explicit StartText(const sf::Font& font) : Text(font) {
            setString("Press SPACE to start!");
            setCharacterSize(32);
            setFillColor(sf::Color::White);

            auto bounds = getGlobalBounds();
            setOrigin({bounds.getCenter().x, bounds.size.y});
            setPosition({0, (SCREEN_HEIGHT / 2.f - 100) });

            Renderer::getInstance()->registerDrawable(this);
        }
    };
}
