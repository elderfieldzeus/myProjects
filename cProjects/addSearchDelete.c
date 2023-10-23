#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char name[100];
    int age;
    char phoneNum[12];
}PERSON;

PERSON *getPerson();
void wouldYouLike(PERSON *person, int *pSize);
void formalize(char *formal);
void sortNames(PERSON *person, int *pSize);
int compareOrder(const char name[], const char namePlusOne[]);
void addPerson(PERSON *person, int *pSize);
int checkName(PERSON *person, char nameToCheck[], int *pSize);
void searchPerson(PERSON *person, int *pSize);
void deletePerson(PERSON *person, int *pSize);
void printAllNames(PERSON *person, int *pSize);

int main(){
    int size = 1;
    PERSON *person = getPerson();
    wouldYouLike(person, &size);
    free(person);
    return 0;
}

PERSON *getPerson(){
    PERSON *person = malloc(sizeof(PERSON));
    printf("\033[H\033[J");
    printf("Enter name: ");
    scanf(" %99[^\n]", person[0].name);
    formalize(person[0].name);
    printf("Enter age: ");
    scanf("%d", &person[0].age);
    printf("Enter Phone Number: ");
    scanf(" %99[^\n]", person[0].phoneNum);
    return person;
}

void wouldYouLike(PERSON *person, int *pSize){
    start:
        sortNames(person, pSize);
        int option;
        printf("\nSelect option:\n");
        printf("[1] Add another person.\n");
        printf("[2] Search for data through name.\n");
        printf("[3] Print all names.\n");
        printf("[4] Delete a name.\n");
        printf("[5] End application.\n");
        printf("Chosen option: ");
        scanf("%d", &option);
    
    switch(option){
        case 1: printf("\033[H\033[J"); addPerson(person, pSize); break;
        case 2: printf("\033[H\033[J"); searchPerson(person, pSize); break;
        case 3: printf("\033[H\033[J"); printAllNames(person, pSize); break;
        case 4: printf("\033[H\033[J"); deletePerson(person, pSize); break;
        case 5: printf("\033[H\033[J"); printf("THANK YOU FOR USING!!!"); break;
        default: printf("\nInvalid option, choose again!\n"); goto start;
    }
}

void formalize(char *formal){
    for(int j = 0; formal[j] != '\0'; j++){
        if(j == 0 || formal[j-1] == ' '){
            formal[j] = toupper(formal[j]);
        }
        else{
            formal[j] = tolower(formal[j]);
        }
    }
}

void sortNames(PERSON *person, int *pSize){
    for(int i = 0; i<(*pSize)-1; i++){
        for(int j = 0; j<(*pSize)-1-i; j++){
            if(compareOrder(person[j].name, person[j+1].name)){
                PERSON temp = person[j];
                person[j] = person[j+1];
                person[j+1] = temp;
            }
        }
    }
}

int compareOrder(const char name[], const char namePlusOne[]){
    for(int i = 0; name[i] != '\0' && namePlusOne[i] != '\0'; i++){
        if(name[i] > namePlusOne[i]){
            return 1;
        }
        else if(name[i] != namePlusOne[i]){
            return 0;
        }
    }
    if(strlen(name) > strlen(namePlusOne))
        return 1;
    return 0;
}

void addPerson(PERSON *person, int *pSize){
    char name[100];
    printf("Enter name: ");
    scanf(" %99[^\n]", name);
    if (checkName(person, name, pSize)){
        printf("NAME ALREADY TAKEN\n\n");
        goto end;
    }
    (*pSize)++;
    person = realloc(person, sizeof(PERSON)*(*pSize));
    formalize(name);
    strcpy(person[*pSize-1].name, name);
    printf("Enter age: ");
    scanf("%d", &person[*pSize-1].age);
    printf("Enter Phone Number: ");
    scanf(" %99[^\n]", person[*pSize-1].phoneNum);
    end: 
        wouldYouLike(person, pSize);
}

int checkName(PERSON *person, char nameToCheck[], int *pSize){
    for(int i = 0; i<*pSize; i++){
        if(strcmp(nameToCheck, person[i].name) == 0){
                return 1;
            }
    }
    return 0;
}

void searchPerson(PERSON *person, int *pSize){
    char search[100];
    start:
        printf("Enter name you would like to search: ");
        scanf(" %99[^\n]", search);
        formalize(search);
        for(int i = 0; i < *pSize; i++){
            if(strcmp(search, person[i].name) == 0){
                printf("\nName: %s\n", person[i].name);
                printf("Age: %d\n", person[i].age);
                printf("Phone Number: %s\n", person[i].phoneNum);
                goto exit;
            }
        }

    printf("\nINVALID NAME\n\n");

    exit:
        wouldYouLike(person, pSize);
}

void deletePerson(PERSON *person, int *pSize){
    char delete[100];
    int index;
    printf("Enter name to delete: ");
    scanf(" %99[^\n]", delete);
    if(!(checkName(person, delete, pSize))){
        printf("NAME NOT FOUND");
        goto exit;
    }
    formalize(delete);
    for(int i = 0; i < *pSize; i++){
        if(strcmp(delete, person[i].name) == 0){
            index = i;
            break;
        }
    }
    for(int i = index; i < *pSize-1; i++){
        person[i] = person[i+1];
    }
    (*pSize)--;

    person = realloc(person, sizeof(PERSON)*(*pSize));
    printf("NAME SUCCESSFULLY DELETED\n");
    exit:
        wouldYouLike(person, pSize);
}

void printAllNames(PERSON *person, int *pSize){
    printf("LIST OF NAMES:\n\n");
    for(int i = 0; i<*pSize; i++){
        printf("%s\n", person[i].name);
    }
    wouldYouLike(person, pSize);
}