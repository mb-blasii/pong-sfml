#include "Renderer.hpp"

#include <algorithm>

namespace Pong {
    Renderer* Renderer::m_instance = nullptr;

    Renderer *Renderer::getInstance() {
        if (m_instance) return m_instance;

        m_instance = new Renderer();
        return m_instance;
    }

    void Renderer::registerDrawable(sf::Drawable *drawable) {
        m_drawables.push_back(drawable);
    }

    void Renderer::unregisterDrawable(sf::Drawable *drawable) {
        m_drawables.erase(
                std::ranges::remove(m_drawables, drawable).begin(),
                m_drawables.end()
            );
    }

    void Renderer::render(sf::RenderWindow &window) const {
        window.clear(sf::Color::Black);

        for (auto* drawable : m_drawables) {
            window.draw(*drawable);
        }

        window.display();
    }
}
