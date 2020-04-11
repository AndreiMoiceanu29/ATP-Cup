#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <limits.h>
#include"Liste.h"
#include"Stiva.h"
#include"Coada.h"
#include "BinarySearchTree.h"

int isPowerOfTwo(int nr);

void loadStack(Node **s, Node *head, int *);

void performRound(Queue *q, Node **stack, FILE *outPtr, int *stackSize, TNode **root);

double getMaxScore(Player *, int);

int main(int argc, char *argv[]) {
    int nrTari;
    int cerinte[5];
    int i;
    int stackSize;
    Node *head = malloc(sizeof(Node));
    Node *stack = malloc(sizeof(Node));
    createStack(&stack, &stackSize);
    TNode *root = NULL;
    Queue *q = createQueue();
    createList(&head);
    FILE *inPtr, *outPtr, *crPtr;
    if ((crPtr = fopen(argv[1], "r")) == NULL) {
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    for (i = 0; i < 5; i++) {
        fscanf(crPtr, "%d", &cerinte[i]);
    }

    if ((inPtr = fopen(argv[2], "r")) == NULL) {
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    if ((outPtr = fopen(argv[3], "w")) == NULL) {
        printf("Nu s-a putut deschide fisierul\n.");
        exit(1);
    }
    nrTari = freadList(&head, inPtr);
    fclose(inPtr);
    if (cerinte[1]) {
        while (!isPowerOfTwo(nrTari)) {
            nrTari--;
            deleteNodeAtAddr(getNodeWithMinimumScore(head));
        }
    }
    fprintList(head, outPtr);

    if (cerinte[2]) {
        loadStack(&stack, head, &stackSize);

        performRound(q, &stack, outPtr, &stackSize, &root);
    }
    if (cerinte[3]) {
        fprintf(outPtr, "\n====== CLASAMENT JUCATORI ======\n");
        traverseTree(root, outPtr);
    }
    if (cerinte[4]) {
        int resp1 = 0, resp2 = 0;
        int numPlayers = 0;
        Player jucator1, jucator2;
        char buf[100];
        fscanf(crPtr, "%s", buf);
        jucator1.first_name = strdup(buf);
        fscanf(crPtr, "%s", buf);
        jucator1.last_name = strdup(buf);
        fscanf(crPtr, "%d", &jucator1.score);
        fscanf(crPtr, "%s", buf);
        jucator2.first_name = strdup(buf);
        fscanf(crPtr, "%s", buf);
        jucator2.last_name = strdup(buf);
        fscanf(crPtr, "%d", &jucator2.score);
        isInTree(root, jucator1, &resp1);
        isInTree(root, jucator2, &resp2);

        if (resp1 && resp2) {
            if (jucator1.score < jucator2.score) {
                countElementsBetween(root, jucator1.score, jucator2.score, &numPlayers);
            } else {
                countElementsBetween(root, jucator2.score, jucator1.score, &numPlayers);
            }

            fprintf(outPtr, "\n%d\n", numPlayers);
        } else if (!resp1) {
            fprintf(outPtr, "\n%s %s nu poate fi identificat!\n", jucator1.first_name, jucator1.last_name);
        } else {
            fprintf(outPtr, "\n%s %s nu poate fi identificat!\n", jucator2.first_name, jucator2.last_name);
        }
    }
    fclose(crPtr);
    fclose(outPtr);


}

int isPowerOfTwo(int nr) {
    /*
    Facem un si pe biti intre nr si nr-1 si vedem rezultatul
    Daca rezultatul e 0 avem putere a lui doi.
    Fie nr=4, in baza_2 4=100, 4-1=3 sau 011 in baza_2, nr&nr-1 = 0 -> Putere a lui 2.
    */
    if (nr && (!(nr & (nr - 1)))) {
        return 1;
    } else {
        return 0;
    }

}

void loadStack(Node **s, Node *head, int *stackSize) {
    while (head->next != head) { //Cat timp lista nu este goala.
        Node *n = getNode(head->next->data);

        push(s, n, stackSize);
        deleteNodeAtAddr(head->next);
    }
}

void performRound(Queue *q, Node **stack, FILE *outPtr, int *stackSize, TNode **root) {
    Meci m;
    Node *winners = malloc(sizeof(Node)); //Stiva tara castigatoare.
    int winnersSize;
    createStack(&winners, &winnersSize);
    int num_etapa = 1;
    int hasOneElement = 0;
    int hasFourElements = 0;
    short unsigned int scor_local[2];
    int i, j;
    do {
        fprintf(outPtr, "\n====== ETAPA %d ======\n", num_etapa);


        while (!isEmpty(*stack)) {

            scor_local[0] = scor_local[1] = 0;
            Country primaTara = pop(stack, stackSize)->data;

            Country aDouaTara = pop(stack, stackSize)->data;
            for (i = 0; i < primaTara.nr_players; i++) {

                for (j = 0; j < aDouaTara.nr_players; j++) {
                    m.primulJucator = &primaTara.players[i];
                    m.alDoileaJucator = &aDouaTara.players[j];

                    enqueue(q, m);


                }
            }

            //S-a incarcat prima coada.
            //Dorim sa desfasuram meciul.
            fprintf(outPtr, "\n%s %d ----- %s %d\n", primaTara.name, primaTara.global_score, aDouaTara.name,
                    aDouaTara.global_score);

            while (!isEmptyQ(q)) {

                QNode *buffer = qpeek(q);
                dequeue(q);

                fprintf(outPtr, "%s %s %d vs %s %s %d\n", buffer->data.primulJucator->first_name,
                        buffer->data.primulJucator->last_name, buffer->data.primulJucator->score,
                        buffer->data.alDoileaJucator->first_name, buffer->data.alDoileaJucator->last_name,
                        buffer->data.alDoileaJucator->score);


                if (buffer->data.primulJucator->score > buffer->data.alDoileaJucator->score) {
                    buffer->data.primulJucator->score += 5;
                    scor_local[0] += 3;
                } else if (buffer->data.primulJucator->score < buffer->data.alDoileaJucator->score) {
                    buffer->data.alDoileaJucator->score += 5;
                    scor_local[1] += 3;
                } else {
                    buffer->data.primulJucator->score += 2;
                    buffer->data.alDoileaJucator->score += 2;
                    scor_local[0] += 1;
                    scor_local[1] += 1;
                }
                free(buffer);


            }


            //Meciurile dintre 2 tari s-au terminat, dorim sa vedem care tara are scorul cel mai mare.

            if (scor_local[0] > scor_local[1]) {

                //Prima tara este castigatoare pe baza scorului local.
                primaTara.global_score += scor_local[0];
                push(&winners, getNode(primaTara), &winnersSize); //Se adauga prima tara in stiva winners.
                if (hasFourElements) {
                    (*root) = populateTree((*root), aDouaTara.players, aDouaTara.nr_players);

                }
            } else if (scor_local[0] < scor_local[1]) {

                //A doua tara este castigatoarea
                aDouaTara.global_score += scor_local[1];
                push(&winners, getNode(aDouaTara), &winnersSize);
                if (hasFourElements) {
                    (*root) = populateTree((*root), primaTara.players, primaTara.nr_players);

                }
            } else {

                //Cazul in care scorurile sunt egale.
                //Se cauta scorul maxim al unui player.
                double max1, max2;
                max1 = getMaxScore(primaTara.players, primaTara.nr_players);
                max2 = getMaxScore(aDouaTara.players, aDouaTara.nr_players);
                if (max1 > max2 || max1 == max2) {
                    primaTara.global_score += scor_local[0];
                    push(&winners, getNode(primaTara), &winnersSize);
                    if (hasFourElements) {
                        (*root) = populateTree((*root), aDouaTara.players, aDouaTara.nr_players);

                    }
                } else if (max1 < max2) {
                    aDouaTara.global_score += scor_local[1];
                    push(&winners, getNode(aDouaTara), &winnersSize);
                    if (hasFourElements) {
                        (*root) = populateTree((*root), primaTara.players, primaTara.nr_players);

                    }
                }
            }


        }
        if (winnersSize == 4) {
            hasFourElements = 1;
        }

        if (hasOnlyOneElement(winners, winnersSize)) {
            hasOneElement = 1;
            Player *winnerPlayers = peek(winners)->data.players;
            (*root) = populateTree((*root), winnerPlayers, peek(winners)->data.nr_players);


        }


        fprintf(outPtr, "\n=== WINNER ===\n");
        while (!isEmpty(winners)) {
            Node *winnerNode = getNode(pop(&winners, &winnersSize)->data);
            if (winnerNode) {
                fprintf(outPtr, "%s --- %d\n", winnerNode->data.name, winnerNode->data.global_score);

            }
            push(stack, winnerNode, stackSize);
        }


        num_etapa++;
    } while (!hasOneElement);

}

double getMaxScore(Player *players, int num_players) {
    double max_score = INT_MIN;
    int i;
    for (i = 0; i < num_players; i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
        }
    }
    return max_score;
}