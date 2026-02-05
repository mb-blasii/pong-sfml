#pragma once
#include <SFML/Graphics/CircleShape.hpp>

namespace Pong {
    class BallShape : public sf::CircleShape {
    public:
        BallShape() {
            setRadius(RADIUS);

            setOrigin({
                RADIUS,
                RADIUS
            });

            setFillColor(sf::Color::White);
        };

        private:
            const float RADIUS = 10.0f;

    };
}
