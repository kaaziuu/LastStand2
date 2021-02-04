//
// Created by xkey on 29.01.2021.
//

#include "Bullet.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265


GameObject * Bullet::update() {
    this->position.x += xSpeed;
    this->position.y += ySpeed;
    return nullptr;
}

Bullet::Bullet(float rotation, sf::Vector2f postion) {
//    this->rotation = rotation;
    float cos = std::cos(rotation * PI / 180);
    float sin = std::sin(rotation * PI / 180);
    this->tag="Bullet";
    this->xSpeed = sin * this->speed ;
    this->ySpeed = cos * this->speed * -1;
    this->setPosition(postion);
//    this->sprite->setRotation(rotation);
    this->setTexture("Item/Gun/Bullet.png");
//    std::cout << this->texture->getSize().x << ":" <<this->texture->getSize().y;
}

int Bullet::onCollision(GameObject *other) {
    if(other->tag=="Enemy")
        other->takeHit(10);
    return GameObject::onCollision(other);
}
