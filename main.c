#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Liste.h"

int main(int argc, char *argv[]){

    Node *head = malloc(sizeof(Node));
    createList(&head);
    FILE *inPtr, *outPtr;
    if((inPtr=fopen(argv[2],"r"))==NULL){
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    if((outPtr=fopen(argv[3],"w"))==NULL){
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    freadList(&head,inPtr);
    
    fprintList(head,outPtr);
    


}