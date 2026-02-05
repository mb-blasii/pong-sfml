#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <Game/Globals.hpp>

#include "System/Renderer.hpp"

namespace Pong {
    class GameBorderShape : public sf::RectangleShape {
    public:
        GameBorderShape() {
            setSize({
            SCREEN_WIDTH - GAME_MARGIN * 2.f,
            SCREEN_HEIGHT - GAME_MARGIN * 2.f
        });

            setOrigin({
                (SCREEN_WIDTH - GAME_MARGIN * 2.f)  * 0.5f,
                (SCREEN_HEIGHT - GAME_MARGIN * 2.f) * 0.5f
            });

            setFillColor(sf::Color::Transparent);
            setOutlineColor(sf::Color::White);
            setOutlineThickness(BORDER_THICK);

            Renderer* renderer = Renderer::getInstance();
            renderer->registerDrawable(this);
        };

    private:
        const float GAME_MARGIN   = 20.f;
        const float BORDER_THICK  = 2.f;

    public:

    };
}
