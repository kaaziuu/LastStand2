//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_PERSON_H
#define MAZEGAME_PERSON_H


#include "GameObject.h"
#include "Sound/Sound.h"
#include "Tile/Tile.h"
#include "Map/Map.h"
#include <SFML/Audio.hpp>

class Person : public GameObject {


public:
    Person(int hp, int power, float speed);
    void display(sf::RenderWindow *window) override;

    virtual void setMap(Map *map);
    void takeHit(int hp) override;
    int getHp();
    ~Person();
protected:
    float rotation = 0;
    int hp,power;
    float speed;
    Map *map = nullptr;

};


#endif //MAZEGAME_PERSON_H
