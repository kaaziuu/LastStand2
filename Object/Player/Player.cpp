//
// Created by xkey on 29.01.2021.
//

#include "Player.h"
#include <iostream>
#include <math.h>
#include <filesystem>

Player::Player(int hp, int power, float speed, sf::RenderWindow *window) : Person(hp, power, speed) {
    this->tag = "Player";
    this->window = window;
    this->heat = new sf::Texture();
    std::string path = std::filesystem::current_path();
    path += "/Image/player/heat.png";
    this->heat->loadFromFile(path);

    this->heatSprite = new sf::Sprite(*this->heat);
    this->heatSprite->setPosition(0, 0);
}

void Player::move(int key, List<GameObject> *list) {
//    sf::Keyboard::setVirtualKeyboardVisible(true);
    float rotation = 0;
    float mod = 1;
    sf::Vector2f newPosition = this->position;
    int direction = 0;

    if (key == sf::Keyboard::W && this->lastKey != sf::Keyboard::W ) {
        direction = 0;
        newPosition.y -= 40;
        rotation = 0;
        mod = 2;
        this->lastKey = sf::Keyboard::W;

    } else if (key == sf::Keyboard::S && this->lastKey != sf::Keyboard::S) {
        newPosition.y += 40;
        rotation = 180;
        mod = -2;
        direction = 1;
        this->lastKey = sf::Keyboard::S;

    } else if (key == sf::Keyboard::A && this->lastKey != sf::Keyboard::A) {

        newPosition.x -= 40;
        rotation -= 90 / mod;
        direction = 2;
        this->lastKey = sf::Keyboard::A;

    } else if (key == sf::Keyboard::D && this->lastKey != sf::Keyboard::D) {
        newPosition.x += 40;
        rotation += 90 / mod;
        direction = 3;
        this->lastKey = sf::Keyboard::D;
    }

    int y = (int) round(newPosition.y);
    int x = (int) round(newPosition.x);
    bool ok = true;
    for(int i=0;i< list->getSize(); i++)
    {
        GameObject *obj = list->get(i);
        if(obj->tag == "Enemy" && obj->isCollision(newPosition))
        {
            ok= false;
        }
    }
    if (!this->map->isWall(x, y, direction) && ok) {
        this->position = newPosition;

    }
    if (mod != 1 || rotation != 0) {
        this->rotation = rotation;
    }
}

GameObject *Player::update() {
//    this->move();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && this->timeFromLastShot > this->timeDelayBetweenShot) {
        timeFromLastShot = 0;
        return this->gun->shot(this->rotation, this->position);
    }
    this->timeFromLastShot += this->dt.asSeconds();
    this->timeFromLastHit += this->dt.asSeconds();
    return nullptr;
}

void Player::resetLastKey() {
    this->lastKey = -1;

}

Player::~Player()  {
    delete this->gun;
    delete this->heat;
    delete this->heatSprite;
}

void Player::takeHit(int hp) {
    Person::takeHit(hp);
    std::cout << this->hp << std::endl;
    this->timeFromLastHit = 0;
    if(this->hp <= 0)
        this->toRemove = true;
}

void Player::display(sf::RenderWindow *window) {
    if(this->timeFromLastHit < this->timeHitTexture) {

        window->draw(*this->heatSprite);
    }
    Person::display(window);
}


