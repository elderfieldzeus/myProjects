//CODED ON IPAD

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char **names;
}Names;

int getSize();
Names getNames(int size);
void printNames(Names person, int size);

int main(){
    setbuf(stdout, NULL);
    int size = getSize();
    Names person = getNames(size);
    printNames(person, size);
    return 0;
}

int getSize(){
    int size;
    printf("\033[H\033[J");
    printf("Enter size: ");
    scanf("%d", &size);
    return size;
}

Names getNames(int size){
    Names person;
    printf("\033[H\033[J");
    person.names = malloc(sizeof(char*)*size);
    for(int i = 0; i<size; i++){
        printf("Enter name %d: ", i+1);
        person.names[i] = malloc(sizeof(char)*20);
        scanf(" %20[^\n]", person.names[i]);
    }

    return person;
}

void printNames(Names person, int size){
    printf("\033[H\033[J");
    for (int i=0; i<size; i++){
        printf("Name %d: %s\n", i+1, person.names[i]);
        free(person.names[i]);
    }
    free(person.names);
}