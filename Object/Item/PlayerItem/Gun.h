//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_GUN_H
#define MAZEGAME_GUN_H


#include <string>
#include "../Item.h"

class Gun : public Item {
public:
    Gun(int maxAmmo, int power);

    GameObject *shot(float rotation, sf::Vector2f postion);

    std::string tag = "Gun";

private:
    std::string soundPath = "Gun/Basic.wav";
    int power;
    int maxAmmo;
    int currentAmmo{};

};


#endif //MAZEGAME_GUN_H
