#include<stdio.h>
#include<string.h>
#include"Liste.h"
typedef struct meci
{
    Player *primulJucator, *alDoileaJucator;
    /* data */
}Meci;

typedef struct nod{
    struct nod* next;
    Meci data;
}QNode;

typedef struct Queue{
     QNode *front, *rear;
}Queue;

Queue* createQueue();
void enqueue(Queue *q, Meci m);
void dequeue(Queue *queue);
QNode *qpeek(Queue *queue);
int isEmptyQ(Queue *queue);
QNode *newNode(Meci m);
