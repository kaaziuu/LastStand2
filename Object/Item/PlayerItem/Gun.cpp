//
// Created by xkey on 29.01.2021.
//

#include "Gun.h"
#include "Bullet.h"

GameObject* Gun::shot(float rotation, sf::Vector2f postion) {
    this->sound->play(false);
    Bullet *tmp = new Bullet(rotation, postion);
    return  tmp;
}

Gun::Gun(int maxAmmo, int power) {
    this->maxAmmo = maxAmmo;
    this->power = power;
    this->sound = new Sound(this->soundPath);
}
