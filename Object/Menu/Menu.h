//
// Created by xkey on 06.02.2021.
//

#ifndef LASTSTAND2_MENU_H
#define LASTSTAND2_MENU_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Menu {
public:
    Menu();
    ~Menu();
    int display(sf::RenderWindow *window, sf::Event event);

private:
    sf::Texture *startTexture;
    sf::Texture *exitTexture;
    sf::Sprite *startSprite;
    sf::Sprite *exitSprite;
};


#endif //LASTSTAND2_MENU_H
