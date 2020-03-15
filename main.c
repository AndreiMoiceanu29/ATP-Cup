#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Liste.h"

int isPowerOfTwo(int nr);

int main(int argc, char *argv[]){
    int nrTari;
    int cerinte[5];
    int i;
    Node *head = malloc(sizeof(Node));
    createList(&head);
    FILE *inPtr, *outPtr, *crPtr;
    if((crPtr=fopen(argv[1],"r"))==NULL){
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    for(i=0;i<5;i++){
        fscanf(crPtr,"%d",&cerinte[i]);
    }
    fclose(crPtr);
    if((inPtr=fopen(argv[2],"r"))==NULL){
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    if((outPtr=fopen(argv[3],"w"))==NULL){
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    nrTari=freadList(&head,inPtr);
    fclose(inPtr);
    if(cerinte[1]){
        while(!isPowerOfTwo(nrTari)){
            nrTari--;
            deleteNodeAtAddr(getNodeWithMinimumScore(head));
        }
    }
    fprintList(head,outPtr);
    fclose(outPtr);
    


}

int isPowerOfTwo(int nr){
    /*
    Facem un si pe biti intre nr si nr-1 si vedem rezultatul
    Daca rezultatul e 0 avem putere a lui doi.
    Fie nr=4, in baza_2 4=100, 4-1=3 sau 011 in baza_2, nr&nr-1 = 0 -> Putere a lui 2.
    */
    if(nr && (!(nr&(nr-1)))){
        return 1;
    } else{
        return 0;
    }

}