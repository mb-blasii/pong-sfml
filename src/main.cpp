#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game/GameWindow.hpp"
#include "System/EntityManager.hpp"
#include "System/Renderer.hpp"
#include "System/Scene.hpp"

int main()
{
    Pong::GameWindow window;

    Pong::Scene* scene = Pong::Scene::getInstance();

    Pong::EntityManager* entityManager = Pong::EntityManager::getInstance();
    entityManager->start();

    Pong::Renderer* renderer = Pong::Renderer::getInstance();

    sf::Clock clock;
    while (window.isOpen())
    {
        const float dt = clock.restart().asSeconds();

        //std::cout << "FPS: " << 1/dt << std::endl;

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        entityManager->update(dt);
        renderer->render(window);
    }

    return 0;
}
