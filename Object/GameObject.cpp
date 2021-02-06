//
// Created by xkey on 17.01.2021.
//

#include "GameObject.h"
#include <filesystem>
#include <iostream>


void GameObject::display(sf::RenderWindow *window) {
    if(this->drawable) {
        this->sprite->setPosition(this->position);
        window->draw(*this->sprite);
    }
}

void GameObject::setTexture(std::string name, int originX, int originY) {
    if (this->sprite == nullptr) {
        this->sprite = new sf::Sprite();
    }
    if (this->texture == nullptr) {
        this->texture = new sf::Texture();
    }
    std::string path = std::filesystem::current_path();
    path += "/Image/" + name;
    if (!this->texture->loadFromFile(path)) {
        std::cout << "cos nie tak " << path << std::endl;
    }
    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(originX, originY);
}

void GameObject::setPosition(sf::Vector2f position) {
    this->position.x = position.x;
    this->position.y = position.y;
}

GameObject::~GameObject() {
    delete this->texture;
    delete this->sprite;
    delete this->sound;
}

GameObject *GameObject::update() {}

void GameObject::setDT(sf::Time dtTime) {
    this->dt = dtTime;
}

int GameObject::onCollision(GameObject * other) {
//    std::cout<<"basic" << std::endl;
    return 0;
}

sf::Vector2f GameObject::getPosition() {
    return this->position;
}

sf::Vector2f GameObject::getSize() {
    if (this->sprite)
        return this->sprite->getScale();
    return sf::Vector2f(0, 0);
}

sf::Sprite *GameObject::getSprite() {
    return this->sprite;
}


void GameObject::takeHit(int power) {}



