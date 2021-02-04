#include <iostream>
#include "Game.h"

int main() {
    auto game = new Game();
    game->mainLoop();
    delete game;
    return 0;
}
