#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "Globals.hpp"

namespace Pong {
    class GameWindow : public sf::RenderWindow {
    public:
        GameWindow() : RenderWindow(
            sf::VideoMode({SCREEN_WIDTH, SCREEN_HEIGHT}),
            "Pong - SFML"
        ) {
            setVerticalSyncEnabled(true);
            setFramerateLimit(60);

            sf::View view;

            view.setSize({
                static_cast<float>(SCREEN_WIDTH),
                static_cast<float>(SCREEN_HEIGHT)
            });

            view.setCenter({0.f, 0.f});

            setView(view);
        }
    };
}
