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
    NODE *whole = mainNode;
    NODE *left = NULL;
    NODE *right = NULL;
    NODE *oldWhole = NULL;
    while(whole->next != NULL){
        for(left = whole, right = whole->next; right != NULL; left = left->next, right = right->next){
            if(left->value > right->value){
                NODE *temp = right->next;
                right->next = left;
                left->next = temp;
                if(oldWhole == NULL){
                    mainNode = right;
                }
                else{
                    oldWhole->next = right;
                }
                left = right;
                right = left->next;
            }

            if(oldWhole == NULL){
                oldWhole = left;
            }
            else{
                oldWhole = oldWhole->next;
            }
        }
        oldWhole = whole;
        whole = whole->next;
    }

    printf("NODE SORTED\n");
    options(mainNode);
}

void freeAll(NODE *mainNode){
    NODE* current = NULL;
    while(mainNode != NULL){
        current = mainNode;
        mainNode = mainNode->next;
        free(current);
    }
}