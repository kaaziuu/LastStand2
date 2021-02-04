//
// Created by xkey on 29.01.2021.
//

#include "Sound.h"
#include <filesystem>
#include <iostream>

Sound::Sound() = default;

std::string getPath() {
    std::string location = std::filesystem::current_path();
    location += "/Sound/";
    return location;
}

Sound::Sound(const std::string &path) {
    this->path = path;
    this->buffer = new sf::SoundBuffer();
    this->path = getPath() + path;
    this->buffer->loadFromFile(this->path);
}

void Sound::setSound(const std::string path) {
    this->path = getPath() + path;
    if (this->buffer == nullptr)
        this->buffer = new sf::SoundBuffer();

    this->buffer->loadFromFile(this->path);

}

void Sound::play(bool loop = false) {
    if (this->sound == nullptr)
        this->sound = new sf::Sound();
    this->sound->setLoop(loop);
    this->sound->setBuffer(*this->buffer);
    this->sound->play();


}

Sound::~Sound() {
    if (this->buffer != nullptr)
        delete this->buffer;
    if (this->sound != nullptr)
        delete this->sound;
}
