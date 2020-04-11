#include<stdio.h>
#include<stdlib.h>
#include"Liste.h"
#include"Stiva.h"

void createStack(Node **s, int *size){
    *size = 0;
    createList(s);
}

void push(Node **s, Node *n, int *size){
    (*size)++;
    append(s,n); //Se apeleaza direct functia append definita in Liste.h.
}

Node *pop(Node **s, int *size){
    if(!isEmpty(*s)){
        (*size)--;
        Node *n = (*s)->prev;
        deleteNodeAtAddr((*s)->prev);
        return n;
    } else{
        return NULL;
    }
}

Node *peek(Node *s){
    if(!isEmpty(s))
    return s->prev;
    else{
        return NULL;
    }
}
int isEmpty(Node *s){

    if(s->next == s){
        return 1;
    } else {
        return 0;
    }
}
int hasOnlyOneElement(Node *s, int size){

    if(size == 1){
        return 1;
    } else {
        return 0;
    }
}