//
// Created by andre on 11.04.2020.
//

#include "BinarySearchTree.h"
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Liste.h"


TNode *newTNode(Player data){

    TNode *node = malloc(sizeof(TNode));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

TNode *insert(TNode *node, Player data){
    if(node == NULL){

        return newTNode(data);

    }

    if(data.score < node->data.score){
        node->left = insert(node->left,data);
    } else if(data.score > node->data.score){
        node->right = insert(node->right,data);
    } if(data.score == node->data.score){
        //Cazul de egalitate de scoruri.
        if(strcmp(data.first_name,node->data.first_name) < 0){
            node->data = data;
        } else if(strcmp(data.first_name,node->data.first_name) == 0){
            if(strcmp(data.last_name,node->data.last_name) < 0){
                node->data = data;
            }
        }
    }
    return node;
}

TNode *populateTree(TNode *root, Player v[], int len){
    int i;
    for(i = 0; i<len;i++){

        root = insert(root,v[i]);
    }
    return root;
}


void countElementsBetween(TNode *root, int a, int b,int *numPlayers){

    if(root){
        countElementsBetween(root->left,a,b,numPlayers);
        if(root->data.score > a && root->data.score < b){
            (*numPlayers)++;

        }
        countElementsBetween(root->right,a,b,numPlayers);
    }

}

void traverseTree(TNode *root, FILE *outPtr){
    //Traversare in DRS.
    if(root){
        traverseTree(root->right,outPtr);
        fprintf(outPtr,"%s %s %d\n",root->data.first_name,root->data.last_name,root->data.score);
        traverseTree(root->left,outPtr);
    }
}

void isInTree(TNode *root, Player key, int *resp){
    if(root){
        isInTree(root->left,key,resp);
        if(strcmp(root->data.first_name,key.first_name) == 0 && strcmp(root->data.last_name,key.last_name) == 0 && root->data.score == key.score){
            *resp = 1;

        }
        isInTree(root->right,key,resp);
    }

}