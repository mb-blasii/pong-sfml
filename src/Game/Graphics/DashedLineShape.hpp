#pragma once
#include "SFML/Graphics/VertexArray.hpp"
#include <Game/Globals.hpp>

#include "System/Renderer.hpp"

namespace Pong {
    class Renderer;

    class DashedLineShape : public sf::VertexArray {

    public:
        DashedLineShape() : VertexArray(sf::PrimitiveType::Lines) {
            for (float y = -(SCREEN_HEIGHT/2.f - 30); y < SCREEN_HEIGHT/2.f - 25; y += 25.f)
            {
                append({ {0.f, y}, sf::Color::White });
                append({ {0.f, y + 10.f}, sf::Color::White });
            }

            Renderer::getInstance()->registerDrawable(this);
        }
    };
}
