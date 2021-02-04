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


    void move();

    float timeDelayBetweenShot = 2;
    float timeFromLastShot = 2.1;

    GameObject *update() override;


private:
    bool keyIsPress = false;
    sf::RenderWindow *window;
    Gun *gun = new Gun(20, 10);
};


#endif //MAZEGAME_PLAYER_H
