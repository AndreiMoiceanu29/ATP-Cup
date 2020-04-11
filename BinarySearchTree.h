//
// Created by andre on 11.04.2020.
//

#ifndef TEMA1_BINARYSEARCHTREE_H
#define TEMA1_BINARYSEARCHTREE_H
#include<stdio.h>
#include<stdlib.h>
#include "Liste.h"

typedef struct tnode{

    Player data;
    struct tnode *left, *right;
}TNode;

TNode *newTNode(Player data);
TNode *insert(TNode *, Player);
TNode *populateTree(TNode *, Player v[], int);
void traverseTree(TNode *, FILE *);
void countElementsBetween(TNode *, int, int, int *);
void isInTree(TNode *, Player, int *);

#endif //TEMA1_BINARYSEARCHTREE_H
