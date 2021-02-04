//
// Created by xkey on 17.01.2021.
//

#ifndef MAZEGAME_GAMEOBJECT_H
#define MAZEGAME_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Sound/Sound.h"

class GameObject {
public:
    std::string tag = "None";

    virtual void display(sf::RenderWindow *window);
    virtual GameObject *update();
    void setTexture(std::string name, int originX=0, int originY=0);
    virtual int onCollision(GameObject *other);
    virtual void takeHit(int power);
    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();
    sf::Sprite *getSprite();
    virtual void setDT(sf::Time dt);
    bool toRemove = false;
    ~GameObject();
protected:
    sf::Time dt;
    sf::Texture *texture = nullptr;
    sf::Sprite *sprite = nullptr;
    sf::Vector2f position;
    Sound *sound = nullptr;
};


#endif //MAZEGAME_GAMEOBJECT_H
