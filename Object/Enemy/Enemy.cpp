//
// Created by xkey on 03.02.2021.
//

#include "Enemy.h"

GameObject *Enemy::update() {
    return nullptr;
}

void Enemy::setList(List<GameObject> *list) {
    this->list = list;
}

void Enemy::setPlayer(Player *player) {
    this->player = player;
}
