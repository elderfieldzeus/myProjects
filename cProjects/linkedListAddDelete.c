#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}NODE;

NODE *getNodes();
void printNodes(NODE *mainNode);
void options(NODE *mainNode);
void addNode(NODE *mainNode);
void deleteNode(NODE *mainNode);
void sortNode(NODE *mainNode);
void swapNodes(NODE *mainNode, NODE *tail, NODE *head);
void freeAll(NODE *mainNode);

int main() {
    NODE *mainNode = getNodes();
    printNodes(mainNode); 
    freeAll(mainNode);
    return 0;
}

NODE *getNodes(){
    NODE *head = malloc(sizeof(NODE));
    NODE *tail = head;
    int size;
    printf("Enter number of nodes: ");
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        printf("Enter node %d value: ", i + 1);
        scanf("%d", &tail->value);

        if(i + 1 == size){
            tail->next = NULL;
        }
        else{
            tail->next = malloc(sizeof(NODE));
            tail = tail->next;
        }
    }

    return head;
}

void printNodes(NODE *mainNode){
    NODE *current = mainNode;
    printf("\nYour values are: [");
    while(current != NULL){
        current->next != NULL ? printf("%d, ", current->value) : printf("%d", current->value);
        current = current->next;
    }
    printf("]\n");
    options(mainNode);
}

void options(NODE *mainNode){
    int input;
    printf("\n[1] ADD NODE\n");
    printf("[2] DELETE NODE\n");
    printf("[3] SORT NODE\n");
    printf("[4] PRINT NODES\n");
    printf("[ANY OTHER KEY TO EXIT]\n");
    printf("Input: ");
    scanf("%d", &input);
    switch(input){
        case 1: addNode(mainNode); break;
        case 2: deleteNode(mainNode); break;
        case 3: sortNode(mainNode); break;
        case 4: printNodes(mainNode); break;
        default: return;
    }
    
}

void addNode(NODE *mainNode){
    NODE *current = mainNode;
    for(current; current->next != NULL; current = current->next);
    current->next = malloc(sizeof(NODE));
    current = current->next;
    printf("Enter a number: ");
    scanf("%d", &current->value);
    current->next = NULL;
    options(mainNode);
}

void deleteNode(NODE *mainNode){
    NODE *prev = NULL;
    NODE *current = mainNode;
    int num;
    printf("Enter node number to delete: ");
    scanf("%d", &num);

    for(int i = 0; i < num - 1 && current != NULL; i++, current = current->next){
        if(prev == NULL){
            prev = mainNode;
        }
        else{
            prev = prev->next;
        }
    }

    if(current == NULL || num <= 0){
        printf("NODE NOT FOUND, TRY AGAIN");
    }
    else {
        if(prev != NULL){
            prev->next = current->next;
        }
        else{
            mainNode = mainNode->next;
        }

        free(current);
        printf("NODE DELETED\n");
    }

    options(mainNode);  
}

void sortNode(NODE *mainNode){ //FIX THIS ARGHH
    NODE *head = NULL;
    NODE *tail = NULL;

    for(head = mainNode; head->next != NULL; head = head->next){
        int base = head->value;
        for(tail = head->next; tail != NULL; tail = tail->next){
            if(tail->value < base){
                base = tail->value;
                printf("SWAP %d & %d\n", head->value, tail->value);
                swapNodes(mainNode, tail, head);
                printf("MV = %d\n", mainNode->value);
                printf("T = %d\n", tail->value);
                printf("H = %d\n", head->value);
            }
        }
    }
    printf("NODE SORTED");
    options(mainNode);
}

void swapNodes(NODE *mainNode, NODE *tail, NODE *head){
    NODE *currentX, *prevX, *currentY, *prevY;
    currentX = mainNode;
    prevX = NULL;
    while(currentX != NULL && currentX != head){
        prevX = currentX;
        currentX = currentX->next;
    }

    currentY = mainNode;
    prevY = NULL;
    while(currentY != NULL && currentY != tail){
        prevY = currentY;
        currentY = currentY->next;
    }

    if(prevX == NULL){
        if(currentY->next == NULL){
            NODE *tempX = currentX->next;
            prevY->next = currentX;
            currentY->next = tempX;
            currentX->next = NULL;
            mainNode = currentY;
        }
        else{
            if(currentY == currentX->next){
                NODE *tempX = currentX;
                NODE *tempY = currentY->next;
                mainNode = currentY;
                mainNode->next = tempX;
                tempX->next = tempY;
            }
            else{
                NODE *tempX = currentX->next;
                NODE *tempY = currentY->next;
                prevY->next = currentX;
                currentY->next = tempX;
                currentX->next = tempY;
                mainNode = currentY;
            }
        }
    }
    else{
        if(currentY->next == NULL){
            NODE* tempX = currentX->next;
            prevX->next = currentY;
            prevY->next = currentX;
            currentY->next = tempX;
            currentX->next = NULL;
        }
        else{
            if(currentY == currentX->next){
                NODE *temp = currentY->next;
                prevX->next = currentY;
                currentY->next = currentX;
                currentX->next = temp;
            }
            else{
                NODE* tempX = currentX->next, *tempY = currentY->next;
                prevX->next = currentY;
                prevY->next = currentX;
                currentY->next = tempX;
                currentX->next = tempY;
            }
        }
    }
}

void freeAll(NODE *mainNode){
    NODE* current = NULL;
    while(mainNode != NULL){
        current = mainNode;
        mainNode = mainNode->next;
        free(current);
    }
}