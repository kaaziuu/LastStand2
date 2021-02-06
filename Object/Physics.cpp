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
        if(current->isPhysics) {
            currentPosition = current->getPosition();
            for (int j = 0; j < list->getSize(); j++) {
                if (j == i) continue;
                other = list->get(j);
                if(other->isPhysics) {
                    if (current->getSprite()->getGlobalBounds().intersects(other->getSprite()->getGlobalBounds())) {
//                std::cout << current->tag << "-> " << other->tag << std::endl;
                        current->onCollision(other);
                    }
                }
            }
        }

    }
//    std::cout << "___" << list->getSize() << std::endl;
}

void Physics::outTheScreen(List<GameObject> *list) {
    sf::Vector2f currentPosition;
    GameObject *current;
    for (int i = 0; i < list->getSize(); i++) {
        current = list->get(i);
        if(current->drawable) {
            currentPosition = current->getPosition();
            if (currentPosition.x > 800 || currentPosition.x < 0 || currentPosition.y > 800 || currentPosition.y < 0 ||
                (current->toRemove && current->tag != "Player") ||
                (map->isWall(currentPosition.x, currentPosition.y, 0))) {
//                std::cout << "remove";
                current->drawable = false;
                current->toRemove = true;
            }
        }
    }

}

Physics::Physics(Map *map) {
    this->map = map;
}
