//
// Created by xkey on 17.01.2021.
//

#ifndef MAZEGAME_TILE_H
#define MAZEGAME_TILE_H


#include "../GameObject.h"
#include <SFML/Graphics.hpp>

class Tile : public GameObject {
public:
    bool isWall = false;
};


#endif //MAZEGAME_TILE_H
