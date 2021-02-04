//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_SOUND_H
#define MAZEGAME_SOUND_H

#include <SFML/Audio.hpp>

class Sound {

public:
    Sound();

    Sound(const std::string& path);

    void setSound(const std::string path);


    void play(bool loop);

    ~Sound();

private:
    std::string path;
    sf::Sound *sound = nullptr;
    sf::SoundBuffer *buffer{};
};


#endif //MAZEGAME_SOUND_H
