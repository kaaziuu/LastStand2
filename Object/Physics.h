//
// Created by xkey on 03.02.2021.
//

#ifndef MAZEGAME_PHYSICS_H
#define MAZEGAME_PHYSICS_H


#include "GameObject.h"
#include "../Stucture/List.h"

class Physics {
public:
    void collisionDetection( List<GameObject> *list );

    void outTheScreen(List<GameObject> *list);
};


#endif //MAZEGAME_PHYSICS_H
