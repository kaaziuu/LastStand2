//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_BULLET_H
#define MAZEGAME_BULLET_H


#include "../../GameObject.h"

class Bullet : public GameObject {

    GameObject* update() override;

public:
    Bullet(float rotation, sf::Vector2f postion);
    int onCollision(GameObject *other) override;
private:
    const std::string texturePath = "item/gun/bullet.png";
    float speed = 0.7;
    float xSpeed;
    float ySpeed;
};


#endif //MAZEGAME_BULLET_H
