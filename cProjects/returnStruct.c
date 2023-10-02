#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct people{
    char name[20];
    int age;
};

struct people *getStruct();

int main(){
    int i;
    struct people *pers;
    pers = getStruct();

    for(i = 0; i<3; i++){
    printf("Name: %s\n", pers[i].name);
    printf("Age: %d\n", pers[i].age);
    }
    free(pers);

    return 0;
}

struct people *getStruct(){
    int i;
    struct people Pers[3], *pers;
    pers = (struct people*)malloc(sizeof(struct people) * 3);

    for(i=0; i<3; i++){
    pers[i] = Pers[i];
    printf("Enter name: ");
    scanf(" %99[^\n]", pers[i].name);
    printf("Enter age: ");
    scanf("%d", &pers[i].age);
    }
    return pers;
}