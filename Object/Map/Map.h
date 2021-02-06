//
// Created by xkey on 02.02.2021.
//

#ifndef MAZEGAME_MAP_H
#define MAZEGAME_MAP_H


#include "../Tile/Tile.h"

class Map {

public:
    static const int mapWith = 20;
    static const int mapHeight = 20;

    Map(int level);
    bool isWall(int x, int y, int direction);
    bool isSpawner(int x, int y);

    void display(sf::RenderWindow *Window);

private:
    Tile map[mapHeight][mapWith];


};


#endif //MAZEGAME_MAP_H
