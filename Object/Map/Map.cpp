//
// Created by xkey on 02.02.2021.
//

#include <filesystem>
#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map(int level) {
    std::string path = std::filesystem::current_path();
    path += "/Level/"+std::to_string(level)+".txt";
    std::string line;
    sf::Vector2f  pos;
    std::ifstream file(path);
    int lineCt = 0;
    while (std::getline(file, line))
    {
        pos.y = lineCt*40;
        for(int j=0;j<Map::mapWith;j++)
        {
            pos.x = j*40;
            switch (line[j]) {
                case '0':
                    this->map[lineCt][j].setTexture("Ground/wall.png");
                    this->map[lineCt][j].isWall = true;
                    break;
                case '1':
                    this->map[lineCt][j].setTexture("Ground/floor.png");
                    break;
                case '2':
                    this->map[lineCt][j].setTexture("Ground/door.png");
                    this->map[lineCt][j].isWall = true;
                    this->map[lineCt][j].isSpawn = true;
                    break;

            }
            this->map[lineCt][j].setPosition(pos);
//            std::cout << "hello ";
        }
        lineCt++;
    }
    file.close();
}

void Map::display(sf::RenderWindow *window) {
    for(auto &row : this->map)
    {
        for(auto &tile : row)
        {
            tile.display(window);
        }
    }
}

bool Map::isWall(int x, int y, int direction) {
    x/=40;
    y/=40;

    return this->map[y][x].isWall;
}

bool Map::isSpawner(int x, int y) {
    if(this->map[y][x].isSpawn)
        return true;
    return false;
}
