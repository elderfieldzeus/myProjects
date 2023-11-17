#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node{
    int sample;
    struct Node *next;
}Node;

int askForSize();
Node *initializeNodes(int size);
void askForInput(Node *nod);
void printInput(Node *nod);
void freeAll(Node *nod);

int main(){
    int size = askForSize();
    Node *nod = initializeNodes(size);
    askForInput(nod);
    printInput(nod);
    freeAll(nod);
    return 0;
}

int askForSize(){
    int size;
    do{
        printf("Enter number of nodes: ");
        scanf("%d", &size);
        if(size <= 0) printf("INVALID INPUT\n");
    }while(size <= 0);
    return size;
}

Node *initializeNodes(int size){
    Node *startingNode = (Node*)malloc(sizeof(Node));
    Node *currentNode = startingNode;
    for(int i=0; i<size-1; i++){
        currentNode->next = (Node*)malloc(sizeof(Node));
        currentNode = currentNode->next;
    }
    currentNode->next = NULL;
    return startingNode;
}

void askForInput(Node *nod){
    for(Node *currentNode = nod; currentNode != NULL; currentNode = currentNode->next){
        printf("Input any digit: ");
        scanf("%d", &currentNode->sample);
    }
}

void printInput(Node *nod){
    Node *currentNode = nod;
    printf("[");
    for(currentNode; currentNode != NULL; currentNode=currentNode->next){
        printf("%d ", currentNode->sample);
    }

    printf("\b]");
}

void freeAll(Node *nod){
    Node *currentNode = nod;
    Node *temp;

    for(currentNode; currentNode != NULL; currentNode = currentNode->next){
        temp = currentNode;
        free(temp);
    }

}