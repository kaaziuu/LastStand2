//
// Created by xkey on 29.01.2021.
//

#ifndef MAZEGAME_PLAYER_H
#define MAZEGAME_PLAYER_H


#include "../Person.h"
#include "../Item/PlayerItem/Gun.h"

class Player : public Person {
public:

    Player(int hp, int power, float speed, sf::RenderWindow * window);
    ~Player() override;

    void move(int key);
    void resetLastKey();
    void takeHit(int hp) override;
    float timeDelayBetweenShot = 1;
    float timeFromLastShot = 2.1;
    float timeHitTexture=0.2;
    float timeFromLastHit=0.21;
    GameObject *update() override;
    void display(sf::RenderWindow *window) override;
    int score = 0;


private:
    char lastKey;
    sf::Texture *heat;
    sf::Sprite *heatSprite;
    sf::RenderWindow *window;
    Gun *gun = new Gun(20, 10);
};


#endif //MAZEGAME_PLAYER_H
