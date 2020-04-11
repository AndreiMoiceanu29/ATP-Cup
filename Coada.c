#include<stdio.h>
#include<string.h>
#include"Liste.h"
#include"Coada.h"



// A utility function to create an empty queue
struct Queue* createQueue()
{
     Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// The function to add a key k to q
void enqueue(struct Queue* q, Meci m)
{
    // Create a new LL node

     QNode* temp = newNode(m);

    // If queue is empty, then new node is front and rear both
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    // Add the new node at the end of queue and change rear
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove a key from given queue q
void dequeue(struct Queue* q)
{
    // If queue is empty, return NULL.
    if (q->front == NULL)
        return;

    // Store previous front and move front one node ahead
     QNode* temp = q->front;

    q->front = q->front->next;

    // If front becomes NULL, then change rear also as NULL
    if (q->front == NULL)
        q->rear = NULL;

    //free(temp);
}


QNode *qpeek(struct Queue *q){
    if(!isEmptyQ(q)){
        return q->front;
    }
}
int isEmptyQ(struct Queue *q){
    if(q->front == NULL){
        return 1;
    } else {
        return 0;
    }
}


QNode *newNode(Meci m){
    QNode *n = malloc(sizeof(QNode));
    n->next =  NULL;
    n->data = m;
    return n;
}