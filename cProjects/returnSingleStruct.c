#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[20];
    int age;
    float height;
}PERSON;

PERSON getStruct();

int main(){
    PERSON Per;
    Per = getStruct();

    printf("Name is %s\n", Per.name);
    printf("Age is %d\n", Per.age);
    printf("Height is %.2f\n", Per.height);

    return 0;
}

PERSON getStruct(){
    PERSON Per, *pers;
    pers = &Per;

    printf("Enter name: ");
    scanf(" %99[^\n]", pers->name);
    printf("Enter age: ");
    scanf("%d", &pers->age);
    printf("Enter height: ");
    scanf("%f", &pers->height);

    return *pers;
}