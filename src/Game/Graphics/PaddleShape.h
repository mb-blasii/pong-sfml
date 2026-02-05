#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

namespace Pong {

    class PaddleShape : public sf::RectangleShape {
    public:
        PaddleShape() {
            setFillColor(sf::Color::White);
        }
    };

}
