//
// Created by xkey on 17.01.2021.
//

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

Game::Game() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Last Stand", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2f startPositionsPlayer(400, 400);
    this->player = new Player(100, 10, 1, this->window);
    this->player->setTexture("player/basicPlayer.png", 8, 8);
    this->player->setPosition(startPositionsPlayer);
    this->list->add(player);
    this->map = new Map(1);
    this->player->setMap(this->map);
}

Game::~Game() {
//    delete this->map[0][0];
    delete this->player;
    delete this->map;
    delete this->list;


}

void Game::mainLoop() {
    sf::Clock dClock;
    GameObject *current = nullptr;
    std::string path = std::filesystem::current_path();
    sf::Font font;
    font.loadFromFile(path+"/Font/arial.ttf");
    this->window->setKeyRepeatEnabled(true);
    while (this->window->isOpen()) {
        sf::Event event;
        while (this->window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->window->close();
            }
        }
//        this->player->update();
        GameObject *tmp = nullptr;
        GameObject *current = nullptr;
        if (!this->player->toRemove) {
            for (int i = 0; i < this->list->getSize(); i++) {
                current = this->list->get(i);
                current->setDT(dClock.restart());
                tmp = current->update();
                if (tmp != nullptr)
                    this->list->add(tmp);
            }
        }

        // disply
        this->window->clear(sf::Color::Black);
        this->map->display(this->window);
        physics->collisionDetection(list);
        for (int i = 0; i < this->list->getSize(); i++) {
            current = this->list->get(i);
            if (current)
                current->display(window);
            else
                this->list->remove(i);
        }
        if(player->toRemove)
        {
            sf::Text text;
            text.setFont(font);
            text.setString("GAME OVER");
            text.setCharacterSize(56);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold | sf::Text::Underlined);
            text.setPosition(250, 300 );
            this->window->draw(text);
        }

        this->window->display();
    }

}
