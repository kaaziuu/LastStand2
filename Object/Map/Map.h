//
// Created by xkey on 02.02.2021.
//

#ifndef MAZEGAME_MAP_H
#define MAZEGAME_MAP_H


#include "../Tile/Tile.h"

class Map {
    static const int mapWith = 20;
    static const int mapHeight = 20;
    Tile map[mapHeight][mapWith];
public:
    Map(int level);
    bool isWall(int x, int y, int direction);

    void display(sf::RenderWindow *Window);
};


#endif //MAZEGAME_MAP_H
