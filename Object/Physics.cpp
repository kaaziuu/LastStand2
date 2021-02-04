//
// Created by xkey on 03.02.2021.
//

#include <iostream>
#include "Physics.h"

void Physics::collisionDetection(List<GameObject> *list) {
    GameObject *current = nullptr;
    GameObject *other = nullptr;
//    std::cout <<  list->getSize() << std::endl;
    sf::Vector2f currentPosition;
    for (int i = 0; i < list->getSize(); i++) {
        current = list->get(i);
        currentPosition = current->getPosition();
        for (int j = i + 1; j < list->getSize(); j++) {
            other = list->get(j);
            if (current->getSprite()->getGlobalBounds().intersects(other->getSprite()->getGlobalBounds()))
                current->onCollision(other);
        }
    }
//    std::cout << "___" << list->getSize() << std::endl;
}

void Physics::outTheScreen(List<GameObject> *list) {
    sf::Vector2f currentPosition;
    GameObject *current;
    for (int i = 0; i < list->getSize(); i++) {
        current = list->get(i);
        currentPosition = current->getPosition();
        if (currentPosition.x > 800 || currentPosition.x < 0 || currentPosition.y > 800 || currentPosition.y < 0 ||
            (current->toRemove && current->tag != "Player"))
            list->remove(i);


    }

}
