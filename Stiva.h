#include<stdio.h>
#include<stdlib.h>
#include"Liste.h"

void createStack(Node **, int *);
void push(Node **, Node *, int *); //Adauga un element la varful stivei.
Node *pop(Node **, int *); //Scoate elementul de la varful stivei.
Node *peek(Node *); //Returneaza elementul de la varful stivei.
int isEmpty(Node *); //Verifica daca stiva este goala.
int hasOnlyOneElement(Node *, int);
