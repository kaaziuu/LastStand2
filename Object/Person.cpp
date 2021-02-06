//
// Created by xkey on 29.01.2021.
//

#include "Person.h"
#include <string.h>
#include <iostream>

Person::Person(int hp, int power, float speed)
:hp{hp}, power{power}, speed{speed}{
    this->sound;
}

void Person::display(sf::RenderWindow *window) {
    this->sprite->setRotation(this->rotation);
    GameObject::display(window);
}

Person::~Person() {
    delete this->sound;
}

void Person::setMap(Map *map) {
    this->map = map;
}

void Person::takeHit(int power){
    this->hp -= power;

}

int Person::getHp() {
    return this->hp;
}




