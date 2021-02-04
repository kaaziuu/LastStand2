//
// Created by xkey on 03.02.2021.
//

#ifndef MAZEGAME_ENEMY_H
#define MAZEGAME_ENEMY_H


#include "../Person.h"
#include "../../Stucture/List.h"
#include "../Player/Player.h"

class Enemy : public Person {
public:
     GameObject* update() override;
     void setList(List<GameObject> *list);
     void setPlayer(Player *player);

private:
    List<GameObject> *list;
    Player *player = nullptr;
};


#endif //MAZEGAME_ENEMY_H
