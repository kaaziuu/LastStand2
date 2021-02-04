//
// Created by xkey on 29.01.2021.
//

#include "Player.h"
#include <iostream>
#include <math.h>

Player::Player(int hp, int power, float speed, sf::RenderWindow *window) : Person(hp, power, speed) {
    this->tag = "Player";
    this->window = window;
}

void Player::move() {
//    sf::Keyboard::setVirtualKeyboardVisible(true);
    float rotation = 0;
    float mod = 1;
    sf::Vector2f newPosition = this->position;
    int direction = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !this->keyIsPress) {
        direction = 0;
        newPosition.y -= 1;
        rotation = 0;
        mod = 2;
        this->keyIsPress = true;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !this->keyIsPress) {
        newPosition.y += 1;
        rotation = 180;
        mod = -2;
        direction = 1;
        this->keyIsPress = true;

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !this->keyIsPress) {

        newPosition.x -= 1;
        rotation -= 90 / mod;
        direction = 2;
        this->keyIsPress = true;


    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !this->keyIsPress) {
        newPosition.x += 1;
        rotation += 90 / mod;
        direction = 3;
        this->keyIsPress = true;
    }else{
        this->keyIsPress = false;
    }

    int y = (int) round(position.y);
    int x = (int) round(position.x);
    if (!this->map->isWall(x, y, direction)) {
        this->position = newPosition;
    }
    if (mod != 1 || rotation != 0) {
        this->rotation = rotation;
    }
}

GameObject *Player::update() {
    this->move();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && this->timeFromLastShot > this->timeDelayBetweenShot) {
        timeFromLastShot = 0;
        return this->gun->shot(this->rotation, this->position);
    }
    timeFromLastShot += this->dt.asSeconds();
    return nullptr;
}


