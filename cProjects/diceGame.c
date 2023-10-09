#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct{
    int dice[3];
    char **playerName;
    int *sumOfRoll;
    int size;
}Game;

Game getInfo();
void rollDice(Game *game);
void toLowerString(char roll[]);
void getWinner(Game game);
int countWinners(int index[]);
void freeAll(Game *game);

int main(){
    Game game = getInfo();
    rollDice(&game);
    getWinner(game);
    freeAll(&game);
    return 0;
}

Game getInfo(){ 
    Game game;
    printf("\033[H\033[J");
    printf("Enter number of players: ");
    scanf("%d", &game.size);
    game.playerName = malloc(sizeof(char*)*game.size);
    printf("\033[H\033[J");
    for(int i = 0; i < game.size; i++){
        game.playerName[i] = malloc(sizeof(char)*20);
        printf("Enter Name of player #%d: ", i+1);
        scanf(" %19[^\n]", game.playerName[i]);
    }
    game.sumOfRoll = calloc(game.size, sizeof(int));
    return game;
}

void rollDice(Game *game){
    srand(time(NULL));
    char roll[5];
    printf("\033[H\033[J");
    for(int i=0; i<game->size; i++){
        do{
        printf("It is %s's turn to roll!\nType \"roll\" to play the game: ", game->playerName[i]);
        scanf(" %s", roll);
        toLowerString(roll);
        printf("\n");
        }while(strcmp(roll, "roll"));
        for(int j = 0; j<3; j++){
            game->dice[j] = (rand()%6)+1;
            printf("Dice #%d: %d\n", j+1, game->dice[j]);
            game->sumOfRoll[i] += game->dice[j];
        }
        printf("Total: %d\n", game->sumOfRoll[i]);
        printf("\n");
    }
}

void toLowerString(char roll[]){
    for(int i = 0; roll[i] != '\0'; i++){
        roll[i] = tolower(roll[i]);
    }
}

void getWinner(Game game){
    int biggest, index[game.size], k = 0;
    char winner[20];
    biggest = game.sumOfRoll[0];
    index[k] = 0;
    index[k+1] = -1;
    for(int i = 1; i<game.size; i++){
        if(game.sumOfRoll[i]>biggest){
            k = 0;
            biggest = game.sumOfRoll[i];
            index[k] = i;
            index[k+1] = -1;
        }    
        else if(game.sumOfRoll[i] == biggest){
            k++;
            index[k] = i;
            index[k+1] = -1;
        }    
    }
    int numOfWinners = countWinners(index);
    printf("YOUR WINNER/S ARE:\n");
    for(int i = 0; i<numOfWinners; i++){
        printf("%s --> SCORE: %d\n", game.playerName[index[i]], game.sumOfRoll[index[i]]);
    }
    printf("\n");
}

int countWinners(int index[]){
    int count = 0;
    for(int i = 0; index[i]!=-1; i++){
        count++;
    }
    return count;
}

void freeAll(Game *game){
    for(int i = 0; i<game->size; i++){
        free(game->playerName[i]);
    }
    free(game->playerName);
    free(game->sumOfRoll);
}