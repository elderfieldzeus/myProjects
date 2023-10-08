#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char **name;
    int size;
}Person;

Person getNames();
void chooseOption(Person *per);
void insertArrayEnd(Person *per);
void insertArrayStart(Person *per);
void deleteArray(Person *per);
void updateArray(Person *per);
void printAll(Person *per);
int tryAgain();
void freeAll(Person *per);

int main(){
    setbuf(stdout, NULL);
    Person Per = getNames();
    Person *per = &Per;
    start:
    chooseOption(per);
    printAll(per);
    if(tryAgain())
        goto start;
    freeAll(per);
    return 0;
}

Person getNames(){
    Person per;
    per.size = 5;
    per.name = malloc(sizeof(char*)*per.size);
    printf("\033[H\033[J");
    for(int i = 0; i<per.size; i++){
        per.name[i] = malloc(sizeof(char)*20);
        printf("Enter name %d: ", i+1);
        scanf(" %19[^\n]", per.name[i]);
    }

    return per;
}
void chooseOption(Person *per){
    int choice;
    printf("\033[H\033[J");    
    printf("Would you like to:\n");
    printf("[1] Insert another name at the end?\n");
    printf("[2] Insert another name at the start?\n");
    printf("[3] Delete based on location?\n");
    printf("[4] Update based on location?\n");
    printf("Chosen option: ");
    scanf("%d", &choice);
    switch(choice){
        case 1: insertArrayEnd(per);break;
        case 2: insertArrayStart(per);break;
        case 3: deleteArray(per);break;
        case 4: updateArray(per);break;
        default: 
            printf("INVALID INPUT!!!\n");
    }
}

void insertArrayEnd(Person *per){
    per->size++;
    per->name = realloc(per->name, sizeof(char*)*per->size);
    per->name[per->size-1] = malloc(sizeof(char)*20);
    printf("\033[H\033[J");
    printf("Enter your inserted name: ");
    scanf(" %19[^\n]", per->name[per->size-1]);
}

void insertArrayStart(Person *per){
    per->size++;
    per->name = realloc(per->name, sizeof(char*)*per->size);
    per->name[per->size-1] = malloc(sizeof(char)*20);
    char temp[20];
    printf("\033[H\033[J");
    printf("Enter your inserted name: ");
    scanf(" %19[^\n]", temp);

    for(int i = per->size-1; i>=0; i--){
        strcpy(per->name[i+1],per->name[i]);
    }
    strcpy(per->name[0], temp);
}

void deleteArray(Person *per){
    int index;
    do{
        printf("\033[H\033[J");
        printf("Enter array you choose to delete (0-index): ");
        scanf("%d", &index);
    }while(index<0 || index >=per->size);
    
    for(int i = index; i<(per->size)-1; i++){
        strcpy(per->name[i], per->name[i+1]);
    }
    free(per->name[per->size-1]);
    per->size--;
    per->name = realloc(per->name, sizeof(char*)*per->size);
}

void updateArray(Person *per){
    int choice;
    do{
        printf("\033[H\033[J");
        printf("Enter location you choose to update (0-index): ");
        scanf("%d", &choice);
    }while(choice < 0 || choice >= per->size);

    printf("Enter updated name: ");
    scanf(" %19[^\n]", per->name[choice]);
}

void printAll(Person *per){
    printf("\033[H\033[J");
    for(int i = 0; i<per->size; i++){
        printf("Name %d: %s\n", i+1, per->name[i]);
    }
}

int tryAgain(){
    char ch;
    printf("\n\nAnother? (y/n): ");
    scanf(" %c", &ch);
    if (tolower(ch) == 'y')
        return 1;
    return 0;
}

void freeAll(Person *per){
    for(int i = 0; i<per->size; i++){
        free(per->name[i]);
    }
    free(per->name);
}