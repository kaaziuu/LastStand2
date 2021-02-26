 //
// Created by xkey on 05.02.2021.
//

#ifndef LASTSTAND2_SPAWNER_H
#define LASTSTAND2_SPAWNER_H


#include "../GameObject.h"
#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../../Stucture/List.h"
 class Spawner : public GameObject {
public:
    Spawner(Map *map, Player *player, List<GameObject> *list);
    GameObject*update() override;

 private:
    int spawnCord[4][2];
    float timeDelay = 0.9;
    float timeFromLast = 5.1;
    Map *map;
    Player *player;
    List<GameObject> *list;

};


#endif //LASTSTAND2_SPAWNER_H
