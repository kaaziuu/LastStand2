//
// Created by xkey on 17.01.2021.
//

#ifndef MAZEGAME_GAME_H
#define MAZEGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Object/Tile/Tile.h"
#include "Object/Player/Player.h"
#include "Stucture/List.h"
#include "Object/Map/Map.h"
#include "Object/GameObject.h"
#include "Object/Physics.h"
#include "Object/Enemy/Spawner.h"
#include "Object/Menu/Menu.h"

class Game {
public:
    Game();

    ~Game();

    void mainLoop();

private:
    Physics *physics = nullptr;
    Spawner *spawner = nullptr;
    Menu *menu = nullptr;
    sf::RenderWindow *window;
    Player *player = nullptr;
    Map *map = nullptr;
    List<GameObject> *list = new List<GameObject>();
    int state=0;
};


#endif //MAZEGAME_GAME_H
