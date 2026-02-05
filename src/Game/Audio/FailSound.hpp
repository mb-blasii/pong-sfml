#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace Pong {
    class FailSound{
    public:
        FailSound() {
            if (sb.loadFromFile("res/audio/sfx/404743__owlstorm__retro-video-game-sfx-fail.wav")) {
                s = new sf::Sound(sb);

                s->setVolume(50.f);
            }
        }

        void playSound() const {
            s->play();
        }

    private:
        sf::Sound* s;
        sf::SoundBuffer sb;
    };
}
