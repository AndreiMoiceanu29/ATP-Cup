#include<stdio.h>
#include<stdlib.h>

//Structura pentru jucator:
typedef struct Player { 
   char *last_name;
   char *first_name;
   int score;
} Player;
 
//Structura pentru tara:
typedef struct Country {
   char *name;
   int nr_players;
   int global_score;
   Player *players;
} Country;

//Structura pentru nod:
typedef struct Elem{
    struct Elem *prev;
    struct Elem *next;
    Country data;
}Node;

Node *getNode(Country); //Functie care intoarce un nod.
void createList(Node **); //Functie care genereaza o lista dublu inlantuita cu santinela.
void append(Node **, Node *); //Adauga un element la capatul listei.
void printList(Node *); //Afiseaza elementele listei.
void fprintList(Node *, FILE *);//Scrie elementele listei intr-un fisier.
void freadList(Node **, FILE *);//Citeste elementele unei liste dintr-un fisier