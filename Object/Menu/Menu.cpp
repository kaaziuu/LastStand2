//
// Created by xkey on 06.02.2021.
//

#include <SFML/Window/Event.hpp>
#include <filesystem>
#include "Menu.h"

int Menu::display(sf::RenderWindow *window, sf::Event event) {
    window->clear(sf::Color(156,145,145));
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
        if(event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2i mouse = sf::Mouse::getPosition(*window);
            sf::Vector2f mouseF( static_cast<float>( mouse.x ), static_cast<float>( mouse.y ) );
            if(this->startSprite->getGlobalBounds().contains(mouseF))
            {
                return 1;
            }else if(this->exitSprite->getGlobalBounds().contains(mouseF))
            {
                window->close();
            }

        }
    }

    window->draw(*this->startSprite);
    window->draw(*this->exitSprite);
    return 0;
//    window->display();
}

Menu::Menu()
{
    std::string path = std::filesystem::current_path();
    sf::Font font;
    this->startTexture = new sf::Texture();
    this->startTexture->loadFromFile(path+"/Menu/Start.png");
    this->exitTexture = new sf::Texture();
    this->exitTexture->loadFromFile(path+"/Menu/Exit.png");

    this->startSprite = new sf::Sprite();
    this->startSprite->setTexture(*this->startTexture);
    this->startSprite->setPosition(350, 350);

    this->exitSprite = new sf::Sprite();
    this->exitSprite->setTexture(*this->exitTexture);
    this->exitSprite->setPosition(350, 450);
}

Menu::~Menu() {
    delete this->startSprite;
    delete this->startTexture;
    delete this->exitSprite;
    delete this->exitTexture;
};
