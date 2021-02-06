//
// Created by xkey on 05.02.2021.
//

#include <iostream>
#include "Spawner.h"
#include "Enemy.h"

GameObject *Spawner::update() {
    this->timeFromLast += this->dt.asSeconds();
    Enemy *enemy = nullptr;
//    std::cout << this->timeFromLast << ":" << this->timeDelay << std::endl;
    if (this->timeFromLast > this->timeDelay) {
        this->timeFromLast = 0;
        int i = rand() % 4;
        enemy = new Enemy(30, 20, 5, this->player, this->map);
        sf::Vector2f position((this->spawnCord[i][0] * 40)-20, this->spawnCord[i][1] * 40 - 20);
        if (position.x == 0)
            position.x += 40;
        else if (position.x >= Map::mapWith - 1)
            position.x -= 40;

        if (position.y == 0)
            position.y += 40;
        else if (position.y >= Map::mapHeight)
            position.y -= 40;
        std::cout << position.x << ":" << position.y << std::endl;
        enemy->setPosition(position);
        enemy->setTexture("Enemy/Enemy1.png", 8, 8);

    }
    return enemy;
}

Spawner::Spawner(Map *map, Player *player) {
    int ct = 0;
    this->isPhysics = false;
    this->tag == "Spawner";
    this->drawable = true;
    for (int i = 0; i < Map::mapHeight; i++) {
        for (int j = 0; j < Map::mapWith; j++) {
            if (map->isSpawner(j, i)) {
                this->spawnCord[ct][0] = j;
                this->spawnCord[ct][1] = i;
                ct++;
            }
        }
    }
    this->map = map;
    this->player = player;
}
