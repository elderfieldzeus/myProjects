#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *playerName;
    int age;
    float height;
}Vitals;

typedef struct{
    char *teamName;
    char position[2];
    float ppg;
    float apg;
    float rpg;
    Vitals vit;
}Stats;

int getSize();
Stats *statGetter(int size);
void printTable(Stats *stat, int size);
void freeAll(Stats *stat, int size);

int main(){
    int size = getSize();
    Stats *stat;
    stat = statGetter(size);
    printTable(stat, size);
    freeAll(stat, size);
    return 0;
}

int getSize(){
    int size;
    system("cls"); 
    printf("Enter number of players: ");
    scanf("%d", &size);
    return size;
}

Stats *statGetter(int size){
    int i;
    Stats Stat[size], *stat;
    stat = Stat;
    stat = malloc(sizeof(Stats)*size);

    for (i=0; i<size; i++){
        system("cls"); 
        printf("Enter player name: ");
        stat[i].vit.playerName = malloc(sizeof(char)*20);
        scanf(" %99[^\n]", stat[i].vit.playerName);
        printf("Enter player age: ");
        scanf("%d", &stat[i].vit.age);
        printf("Enter player height: ");
        scanf("%f", &stat[i].vit.height);
        printf("Enter team name: ");
        stat[i].teamName = malloc(sizeof(char)*20);
        scanf(" %99[^\n]", stat[i].teamName);
        printf("Enter position (PG, SG, SF, SG, C): ");
        scanf(" %s", &stat[i].position);
        printf("PPG: ");
        scanf("%f", &stat[i].ppg); 
        printf("APG: ");
        scanf("%f", &stat[i].apg);
        printf("RPG: ");
        scanf("%f", &stat[i].rpg);
    }

    return stat;
}

void printTable(Stats *stat, int size){
    system("cls");
    int i;
    printf("%-20s %-12s %-15s %-20s %-17s %-12s %-12s %-12s\n", "PLAYER NAME", "AGE", "HEIGHT", "TEAM NAME", "POSITION", "PPG", "APG", "RPG");

    for (i=0; i<size; i++){
        printf("\n%-20s %-12d %-15.2f %-20s %-17s %-12.1f %-12.1f %-12.1f\n", stat[i].vit.playerName, stat[i].vit.age, stat[i].vit.height, stat[i].teamName, stat[i].position, stat[i].ppg, stat[i].apg, stat[i].rpg);
    }
}

void freeAll(Stats *stat, int size){
    int i;
    for (i=0; i<size; i++){
        free(stat[i].vit.playerName);
        free(stat[i].teamName);
    }
    free(stat);
}