//
// Created by xkey on 06.02.2021.
//

#ifndef LASTSTAND2_DIJKSTRA_H
#define LASTSTAND2_DIJKSTRA_H


#include "../Map/Map.h"

class Dijkstra {
public:
    explicit Dijkstra(Map *map);

    char nextStep(int x, int y, int targetX, int targetY);

private:

    struct neighborhood;

    typedef struct node {
        struct node *predecessor;
        int fullCost;
        int idx;
        int idy;
        struct neighborhood *neighborhood;
    } node;

    typedef struct neighborhood {
        node *node1;
        int cost;
        struct neighborhood *next;
    } neighborhood;

    typedef struct graph {
        node *node1;
        struct graph *before;
        struct graph *next;
    } graph;

    graph *createGraph();


    graph *findById(graph *lHead, int x, int y);

    graph *removeById(graph *head, int xId, int yId);

    graph *findWithTheSmallestCost(graph *head);

    graph *addNode(graph *head, graph *add);

    void reset(graph *S);

    Map *map;
    int start[2];
    int finish[2];

};


#endif //LASTSTAND2_DIJKSTRA_H
