#include <iostream>
#include "Game.h"
#include "time.h"
int main() {
    srand(time(NULL));

    auto game = new Game();
    game->mainLoop();
    delete game;
    return 0;
}
