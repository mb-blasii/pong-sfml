#include <iostream>
#include <SFML/Graphics.hpp>

#include "Game/GameState.hpp"
#include "Game/GameWindow.hpp"
#include "Game/UI/Score.hpp"
#include "Game/UI/ScoreScreen.hpp"
#include "System/EntityManager.hpp"
#include "System/Renderer.hpp"
#include "System/Scene.hpp"

int main()
{
    Pong::GameWindow window;

    Pong::Scene* scene = Pong::Scene::getInstance();
    Pong::GameState* gameState = Pong::GameState::getInstance();
    Pong::ScoreScreen* score = nullptr;

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

            if (!gameState->isPlaying) {
                if (event->is<sf::Event::KeyPressed>()) {
                    const auto& key = event.value().getIf<sf::Event::KeyPressed>();

                    if (key->code == sf::Keyboard::Key::Space)
                    {
                        gameState->isPlaying = true;
                        scene->mainScreen->hide();
                        if (!score) score = new Pong::ScoreScreen();
                    }
                }
            }
        }

        entityManager->update(dt);
        renderer->render(window);
    }

    return 0;
}
