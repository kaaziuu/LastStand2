//
// Created by xkey on 03.02.2021.
//

#ifndef MAZEGAME_PHYSICS_H
#define MAZEGAME_PHYSICS_H


#include "GameObject.h"
#include "../Stucture/List.h"
#include "Map/Map.h"

class Physics {
public:
    Physics(Map *map);
    void collisionDetection( List<GameObject> *list );

    void outTheScreen(List<GameObject> *list);
private:
    Map *map = nullptr;
};


#endif //MAZEGAME_PHYSICS_H
