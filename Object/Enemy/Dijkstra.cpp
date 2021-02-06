//
// Created by xkey on 06.02.2021.
//

#include "Dijkstra.h"
#include <math.h>

#define MAX_INT 2147483647


Dijkstra::graph* Dijkstra::createGraph() {
    graph *newEl = nullptr;
    graph *current = (graph *) malloc(sizeof(graph));
    current->before = nullptr;
    current->next = nullptr;
    current->node1 = (node *) malloc(sizeof(node));
    current->node1->fullCost = MAX_INT;
    current->node1->idx = 0;
    current->node1->idy = 0;
    current->node1->neighborhood = nullptr;
    current->node1->predecessor = nullptr;
    graph *head= current;
    for (int i = 0; i < Map::mapHeight; i++) {
        for (int j = 0; j < Map::mapWith; j++) {
            newEl = (graph *) malloc(sizeof(graph));
            newEl->before = current;
            newEl->next = nullptr;
            current->next = newEl;
            newEl->node1 = (node *) malloc(sizeof(node));
            newEl->node1->predecessor = nullptr;
            newEl->node1->neighborhood = nullptr;
            newEl->node1->idx = j;
            newEl->node1->idy = i;
            current = newEl;
        }
    }


    current = head;
    int cx, cy;
    while (current) {
        cx = current->node1->idx;
        cy = current->node1->idy;
        if (!this->map->isWall(cx * 40, cy * 40, -1)) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) == abs(j)) continue;
                    if (!map->isWall((cx + j) * 40, (cy + i) * 40, -1)) {
                        neighborhood *neighborhood1 = (neighborhood *) malloc(sizeof(neighborhood1));
                        neighborhood1->node1 = this->findById(head, cx + j, cy + i)->node1;
                        neighborhood1->cost = 1;
                        neighborhood1->next = nullptr;
                        if (current->node1->neighborhood) {
                            neighborhood *ct = current->node1->neighborhood;
                            while (ct->next)
                                ct = ct->next;
                            ct->next = neighborhood1;
                        } else
                            current->node1->neighborhood = neighborhood1;

                    }
                }
            }
        } else {
            current->node1->neighborhood = nullptr;
        }
        current = current->next;
    }
    return head;

}

Dijkstra::Dijkstra(Map *map) {
    this->map = map;
}

Dijkstra::graph *Dijkstra::findById(Dijkstra::graph *lHead, int x, int y) {

    graph *current = lHead;
    while (current) {
        if (current->node1->idx == x && current->node1->idy == y)
            break;
        current = current->next;
    }
    if (current)
        return current;
    return nullptr;
}

char Dijkstra::nextStep(int x, int y, int targetX, int targetY) {
    graph *head =this->createGraph();
    graph *Q = head;
    graph *S = nullptr;
    graph *current = this->findById(Q, x, y);
    current->node1->fullCost = 0;
    while (Q) {
        current = findWithTheSmallestCost(Q);
        Q = this->removeById(Q, current->node1->idx, current->node1->idy);
        S = this->addNode(S, current);
        neighborhood *neighbor = current->node1->neighborhood;
        while (neighbor) {
            if (neighbor->node1->fullCost > current->node1->fullCost + neighbor->cost) {
                neighbor->node1->fullCost = current->node1->fullCost + neighbor->cost;
                neighbor->node1->predecessor = current->node1;
            }
            neighbor = neighbor->next;
        }
    }
    graph *tmp = findById(S, targetX, targetY);
    if(tmp != nullptr) {
        node *last = tmp->node1;

        for (; last->predecessor->predecessor; last = last->predecessor);
        this->reset(S);
        this->reset(head);
        if (last->idx > x) {
            return 'e';
        }
        if (last->idx < x)
            return 'w';
        if (last->idy > y)
            return 's';

        return 'n';
    }
    return 'p';
}

Dijkstra::graph *Dijkstra::removeById(Dijkstra::graph *head, int xId, int yId) {
    graph *current = head;
    if (head && (head->node1->idy != yId || head->node1->idx != xId)) {
        while (current) {
            if (current->node1->idx == xId && current->node1->idy == yId)
                break;
            current = current->next;
        }
        if (current != nullptr) {
            current->before->next = current->next;
            if (current->next)
                current->next->before = current->before;
        }
    } else if (head) {
        head = head->before;
    }
    return head;
}

Dijkstra::graph *Dijkstra::findWithTheSmallestCost(Dijkstra::graph *head) {
    graph *current = head;
    graph *theSmallest = head;
    while (current) {
        if (current->node1->fullCost < theSmallest->node1->fullCost)
            theSmallest = current;
        current = current->next;
    }
    return theSmallest;
}

Dijkstra::graph *Dijkstra::addNode(Dijkstra::graph *lHead, Dijkstra::graph *add) {
    if (lHead) {
        graph *current = lHead;
        while (current->next != NULL)
            current = current->next;
        add->before = current;
        add->next = nullptr;
        current->next = add;
    } else {
        add->next = nullptr;
        add->before = nullptr;
        lHead = add;
    }
    return lHead;
}

void Dijkstra::reset(Dijkstra::graph *S) {
    graph *current = S;
    while (S)
    {
        S = S->next;
//        free(current);
        current = S;
    }

}




