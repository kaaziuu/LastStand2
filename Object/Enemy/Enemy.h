//
// Created by xkey on 03.02.2021.
//

#ifndef MAZEGAME_ENEMY_H
#define MAZEGAME_ENEMY_H


#include "../Person.h"
#include "../../Stucture/List.h"
#include "../Player/Player.h"
#include "Dijkstra.h"

enum enemyType {
    knightType = 0,
    soldierType = 1
};

class Enemy : public Person {
public:
    Enemy(int hp, int power, float speed, Player *player,
          Map *map);

    GameObject *update() override;
    void setPlayer(Player *player);
    void takeHit(int hp) override;
    bool alive = true;

private:
    Dijkstra *dijkstra;
    int type{};
    float range = 40;
    float timeFromLastAttack = 0.21;
    float walkTime = 0.3;
    float fromLastWalkTIme = 0;
    void knight();
    GameObject *soldier();
    Map *map;
    Player *player = nullptr;


};


#endif //MAZEGAME_ENEMY_H
