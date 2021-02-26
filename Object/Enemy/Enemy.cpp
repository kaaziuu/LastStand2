//
// Created by xkey on 03.02.2021.
//

#include "Enemy.h"
#include <math.h>
#include <iostream>

Enemy::Enemy(int hp, int power, float speed, Player *player,
             Map *map, List<GameObject> *list) : Person(hp, power, speed) {
    this->map = map;
    this->player = player;
    this->type = knightType;
    this->tag = "Enemy";
    this->dijkstra = new Dijkstra(this->map);
    this->gameList = list;
}


void Enemy::setPlayer(Player *player) {
    this->player = player;
}


GameObject *Enemy::update() {

    GameObject *newBullet = nullptr;
    if (this->alive) {
        if (this->type == knightType)
            this->knight();
        else
            newBullet = this->soldier();
    }
    return newBullet;
}


void Enemy::knight() {
    sf::Vector2f playerPos = this->player->getPosition();
    float xDistance = abs(this->position.x - playerPos.x);
    float yDistance = abs(this->position.y - playerPos.y);
//    std::cout  <<  xDistance << ":" << yDistance << std::endl;

    this->timeFromLastAttack += this->dt.asSeconds();
    this->fromLastWalkTIme += this->dt.asSeconds();
//    std::cout << this->timeFromLastAttack << std::endl;
    if (xDistance <= this->range && yDistance <= this->range && timeFromLastAttack >= this->speed) {
//        std::cout << xDistance << ":" << yDistance << std::endl;
        this->timeFromLastAttack = 0;
        this->player->takeHit(this->power);
    } else if (this->fromLastWalkTIme > this->walkTime && (xDistance >= this->range || yDistance >= this->range)) {
        this->fromLastWalkTIme = 0;
        std::cout << this->tag << std::endl;
        int direction;
        if(this->position.x > playerPos.x)
            direction = 0;
        else if(this->position.x < playerPos.x)
            direction = 1;
        else if(this->position.y > playerPos.y)
            direction = 2;
        else if(this->position.y < playerPos.y)
            direction = 3;

        sf::Vector2f move = this->position;
        bool ok = true;
        int ct = 0;
        while (ct<4)
        {
            switch (direction) {
                case 0:
                    move.x -= 40;
                    break;
                case 1:
                    move.x += 40;
                    break;
                case 2:
                    move.y -= 40;
                    break;
                case 3:
                    move.y += 40;
                    break;
            }
            for(int i=0;i< this->gameList->getSize();i++)
            {
                GameObject*obj = this->gameList->get(i);
                if(obj->tag == "Enemy" || obj->tag=="Player")
                {
                    if(obj->isCollision(move)) {
                        ok = false;
                        break;
                    }

                }

            }
            if(this->map->isWall(move.x, move.y, -1) || !ok)
            {

                move = this->position;
                direction++;
                if(direction>=4)
                    direction=0;
                ct++;
            }
            else
            {
                break;
            }
        }

        this->position = move;
    }

}

GameObject *Enemy::soldier() {
    return nullptr;
}

char getDirection(int x, int y) {
    if (x == 1)
        return 'l';
    else if (x == -1)
        return 'r';
    else if (y == 1)
        return 't';
    else if (y == -1)
        return 'b';
    return 'X';
}



void Enemy::takeHit(int hp) {
    Person::takeHit(hp);
    if (this->hp <= 0 && this->alive) {
        std::cout << "im heat" << std::endl;
        this->alive = false;
        this->setTexture("Enemy/DeadEnemy.png", 8, 8);
        this->tag = "deadEnemy";
        this->player->score += 10;
    }
}

