//
// Created by xkey on 17.01.2021.
//

#include "Game.h"
#include "Object/Enemy/Enemy.h"
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>

Game::Game() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Last Stand", sf::Style::Titlebar | sf::Style::Close);
    sf::Vector2f startPositionsPlayer(420, 420);
    this->player = new Player(40, 10, 1, this->window);
    this->player->setTexture("player/basicPlayer.png", 8, 8);
    this->player->setPosition(startPositionsPlayer);
    this->list->add(player);
    this->map = new Map(1);
    this->player->setMap(this->map);
    this->physics = new Physics(map);
    this->spawner = new Spawner(this->map, this->player, this->list);
    this->menu = new Menu();
    this->backgroundSound = new Sound("Soundtrack/mainBackgroundSong.wav");
    this->backgroundSound->play(true);
}

Game::~Game() {
//    delete this->map[0][0];
    delete this->player;
    delete this->map;
    delete this->list;
    delete this->menu;
    delete this->backgroundSound;


}

void Game::mainLoop() {
    sf::Clock dClock;
    GameObject *current = nullptr;
    std::string path = std::filesystem::current_path();
    sf::Font font;
    font.loadFromFile(path + "/Font/arial.ttf");
    sf::Text score;
    score.setFont(font);
    score.setCharacterSize(16);
    score.setStyle(sf::Text::Bold);
    score.setPosition(40, 40);
    score.setFillColor(sf::Color::White);
    sf::Time dt;
    sf::Text hpText;
    hpText.setFont(font);
    hpText.setCharacterSize(16);
    hpText.setStyle(sf::Text::Bold);
    hpText.setPosition(690, 40);
    hpText.setFillColor(sf::Color::White);
    while (this->window->isOpen()) {
        sf::Event event;
        if (this->state == 0) {

            this->state = this->menu->display(window, event);

        } else if (this->state == 1) {
            dt = dClock.restart();
            while (this->window->pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    this->window->close();
                }
                if (event.type == sf::Event::KeyPressed) {
                    if (this->player->toRemove) {
                        if (event.key.code == sf::Keyboard::Enter) {
                            this->player->setHp(40);
                            this->player->toRemove = false;
                            this->player->score = 0;
                            sf::Vector2f startPositionsPlayer(420, 420);
                            this->player->setPosition(startPositionsPlayer);
                            for (int i = 0; i < this->list->getSize(); ++i) {
                                GameObject *obj = this->list->get(i);
                                if (obj->tag == "Enemy" || obj->tag == "deadEnemy") {
                                    obj->drawable = false;
                                    this->list->remove(i);
                                }
                            }
                            this->state = 0;
                        }
                    } else {
                        this->player->move(event.key.code);
                    }
                }
                if (event.type == sf::Event::KeyReleased) {
                    this->player->resetLastKey();
                }
            }
//        this->player->update();
            GameObject *tmp = nullptr;
            GameObject *current = nullptr;
            if (!this->player->toRemove) {
                this->spawner->setDT(dt);
                current = this->spawner->update();
                if (current != nullptr)
                    this->list->add(current);
                for (int i = 0; i < this->list->getSize(); i++) {
                    current = this->list->get(i);
                    if (current->drawable) {
                        current->setDT(dt);
                        tmp = current->update();
                        if (tmp != nullptr)
                            this->list->add(tmp);
                    }
                }
            }

            // disply
            this->window->clear(sf::Color::Black);
            this->map->display(this->window);
            physics->collisionDetection(list);
            physics->outTheScreen(list);
            for (int i = 0; i < this->list->getSize(); i++) {
                current = this->list->get(i);
                if (current && current->tag == "deadEnemy")
                    current->display(window);
            }
            for (int i = 0; i < this->list->getSize(); i++) {
                current = this->list->get(i);
                if (current && current->drawable && current->tag != "Spawner" && current->tag != "deadEnemy")
                    current->display(window);
                if (current && !current->drawable && current->tag != "Spawner")
                    list->remove(i);
            }
            if (player->toRemove) {
                sf::Text text;
                text.setFont(font);
                text.setString("GAME OVER");
                text.setCharacterSize(56);
                text.setFillColor(sf::Color::Red);
                text.setStyle(sf::Text::Bold | sf::Text::Underlined);
                text.setPosition(250, 300);
                sf::Text next;
                next.setFont(font);
                next.setString("Click Enter to  back to menu");
                next.setCharacterSize(56);
                next.setFillColor(sf::Color::Red);
                next.setStyle(sf::Text::Bold);
                next.setPosition(50, 400);

                this->window->draw(next);
                this->window->draw(text);
            }
            hpText.setString("Hp: " + std::to_string(this->player->getHp()));
            score.setString("Score: " + std::to_string(this->player->score));
            this->window->draw(score);
            this->window->draw(hpText);
        }

        this->window->display();
    }

}
