#pragma once
#include <SFML/Audio/Music.hpp>

namespace Pong {
    class MusicPlayer {
        public:
        MusicPlayer() {
            if (m_music.openFromFile("res/audio/music/219824_freesound__zagi2__judgment-dragon-loop-2.wav"))
            {
                m_music.setLooping(true);
                m_music.setVolume(15.f);
                m_music.play();
            }
        }

    private:
        sf::Music m_music;
    };
}
