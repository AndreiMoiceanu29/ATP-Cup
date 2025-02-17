#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Liste.h"


Node *getNode(Country country){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = country;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void createList(Node **head){
    (*head)->prev = *head;
    (*head)->next = *head;
}
void append(Node **head, Node *newNode){
    (*head)->prev->next = newNode;
    newNode->prev = (*head)->prev;
    newNode->next = (*head);
    (*head)->prev = newNode;
}

void printList(Node *head){
    Node *p = head->next;
    
    while(p != head){
        printf("%s\n",p->data.name);
        p = p->next;
        
    }
}

void fprintList(Node *head, FILE *outPtr){
    Node *p = head->next;
    while(p != head){
        fprintf(outPtr,"%s\n",p->data.name);
        p = p->next;
    }
}

int freadList(Node **head, FILE *inPtr){
    
    int numC, numP,i,j;
    Country cBuff;
    //char sBuff[100];
    fscanf(inPtr,"%d",&numC);
    
    for(i=0;i<numC;i++){
        fscanf(inPtr,"%d",&cBuff.nr_players);
        cBuff.players = malloc(sizeof(Player) * cBuff.nr_players);
        cBuff.name = malloc(100);
        fscanf(inPtr,"%s",cBuff.name);
        //cBuff.name = strdup(sBuff);
        
        for(j=0;j<cBuff.nr_players;j++){
            
            //Citim fiecare jucator.
            cBuff.players[j].first_name = malloc(100);
            fscanf(inPtr,"%s",cBuff.players[j].first_name);
            //cBuff.players[j].first_name = strdup(sBuff);
            cBuff.players[j].last_name = malloc(100);
            fscanf(inPtr,"%s",cBuff.players[j].last_name);
            //cBuff.players[j].last_name = strdup(sBuff);
            fscanf(inPtr,"%d",&cBuff.players[j].score);
        }
        cBuff.global_score = 0;
        append(head,getNode(cBuff));
    }
    return numC;

}

float getMeanScore(Country country){
    float meanScore = 0.0;
    int i;
    for(i=0;i<country.nr_players;i++){
        meanScore += country.players[i].score;
    }
    return (meanScore/country.nr_players);
}

Node *getNodeWithMinimumScore(Node *head){
    float min = 999999.0;
    float score; 
    Node *p = head->next;
    Node *buff; 
    while(p != head){
        score = getMeanScore(p->data);
        if(score < min){
            min = score;
            buff = p;
        }
        p = p->next;
    }
    return buff;
}

void deleteNodeAtAddr(Node *addr){
    (addr)->prev->next = (addr)->next;
    (addr)->next->prev = (addr)->prev;
    free(addr);
}