#pragma once
#include <vector>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Pong {
    class Renderer {
    private:
        static Renderer *m_instance;

        std::vector<sf::Drawable*> m_drawables;

        Renderer() = default;
        ~Renderer() = default;

    public:
        static Renderer *getInstance();

        void registerDrawable(sf::Drawable *drawable);
        void unregisterDrawable(sf::Drawable *drawable);
        void render(sf::RenderWindow& window) const;
    };
}
