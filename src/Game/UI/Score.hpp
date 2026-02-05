#pragma once
#include "Game/GameState.hpp"
#include "Game/Globals.hpp"
#include "Game/Entities/Entity.hpp"
#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/Text.hpp"
#include "System/Renderer.hpp"

namespace Pong {
    class GameState;

    class Score : Entity {
        public:
        explicit Score(const sf::Font& font) {
            gameState = GameState::getInstance();

            scoreTxt_L = new sf::Text(font, "0");
            scoreTxt_R = new sf::Text(font, "0");

            scoreTxt_L->setCharacterSize(220);
            scoreTxt_L->setFillColor(sf::Color {255,255,255,50});

            scoreTxt_R->setCharacterSize(220);
            scoreTxt_R->setFillColor(sf::Color {255,255,255,50});

            Renderer* renderer = Renderer::getInstance();
            renderer->registerDrawable(scoreTxt_L);
            renderer->registerDrawable(scoreTxt_R);
        }

        sf::Text* scoreTxt_L;
        sf::Text* scoreTxt_R;

        void start() override { }
        void update(float dt) override {
            setLeft(std::to_string(gameState->scoreLeft));
            setRight(std::to_string(gameState->scoreRight));
        }

    private:
        GameState* gameState;

        void setLeft(const sf::String& text) {
            scoreTxt_L->setString(text);

            auto bounds = scoreTxt_L->getGlobalBounds();
            scoreTxt_L->setOrigin({bounds.size.x, 0});
            scoreTxt_L->setPosition({-22.f, -(SCREEN_HEIGHT / 2.f) });
        }

        void setRight(const sf::String& text) {
            scoreTxt_R->setString(text);

            scoreTxt_R->setOrigin({0, 0});
            scoreTxt_R->setPosition({0, -(SCREEN_HEIGHT / 2.f) });
        }
    };
}
