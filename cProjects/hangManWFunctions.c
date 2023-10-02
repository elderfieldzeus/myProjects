#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char word[20];
    char guess;
    char status[20];
    int lives;
    int start;
    int valid;
    int difficulty;
    int checker;
}Hang;

void welcomeScreen(Hang *man);
void difficultySetter(Hang *man);
void setupFunc(Hang *man);
void askForGuess(Hang *man);
void displayStatus(Hang *man);
void printStick(Hang *man);
bool  statusChecker(Hang *man);

int main(){
    system("cls");
    bool check;
    Hang Man, *man;
    man = &Man;
    start: 
        welcomeScreen(man);
        if(man->start != 1){
            goto exit;
        }
    do{
        difficultySetter(man);
        setupFunc(man);
    }while(man->valid == -1);

    while(man->lives > 0){
        askForGuess(man);
        printStick(man); 
        check = statusChecker(man);
        if(check){
            goto exit;
        }
    }
    

     

    exit:
        printf("THANKS FOR PLAYING!!!");
        return 0;
}

void welcomeScreen(Hang *man){
    printf("%34s\n", "HEY THERE!! WELCOME TO HANGMAN 2.0");
    printf("%8s%s\n\n","", "by Zeus Elderfield");
    printf("%14s%s\n", "", "START!");
    printf("%11s%s", "", "TYPE (1): ");
    scanf("%d", &man->start);
    system("cls");
}

void difficultySetter(Hang *man){
    printf("(1) EASY (2) MEDIUM (3) HARD\n");
    printf("%7s%s", "", "Input choice: ");
    scanf("%d", &man->difficulty);
    system("cls");
}

void setupFunc(Hang *man){
    switch(man->difficulty){
        case 1: 
            strcpy(man->word,"hello");
            strcpy(man->status, "_____");
            man->lives = 6;
            man->valid = 1;
            break;
        
        case 2:
            strcpy(man->word,"hotdog");
            strcpy(man->status, "______");
            man->lives = 6;
            man->valid = 1;
            break;

        case 3:
            strcpy(man->word,"carbohydrate");
            strcpy(man->status, "____________");
            man->lives = 6;
            man->valid = 1;
            break;
        default:
            man->valid = -1;
            printf("%26s\n\n", "INVALID INPUT TRY AGAIN");
    }
}

void askForGuess(Hang *man){
    printf("Guess a letter: ");
    scanf(" %c", &man->guess);
    int i, length = strlen(man->word); 
    man->checker = 0;

    for(i=0; i<length; i++){
        if(man->word[i] == man->guess){
            man->status[i] = man->guess;
            man->checker = 1;
        }
    }
    system("cls");
    displayStatus(man);
}

void displayStatus(Hang *man){
    printf("STATUS: %s\n", man->status);
}

void printStick(Hang *man){
    if(!man->checker){
        (man->lives)--;
    }
    switch(man->lives){
        case 6:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|            \n");
			printf("|            \n");
			printf("|             \n");
			printf("|____________\n\n");
			break;
        case 5:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|            \n");
			printf("|             \n");
			printf("|____________\n\n");
            break;
        case 4:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|     |       \n");
			printf("|             \n");
			printf("|____________\n\n");
            break;
        case 3:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|    /|       \n");
			printf("|             \n");
			printf("|____________\n\n");
            break;
        case 2:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|    /|\\    \n");
			printf("|             \n");
			printf("|____________\n\n");
            break;
        case 1:
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|    /|\\    \n");
			printf("|    /        \n");
			printf("|____________\n\n");
            break;
        case '0':
            printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     0      \n");
			printf("|    /|\\    \n");
			printf("|    / \\    \n");
			printf("|____________\n\n");
            break;
    }
}

bool statusChecker(Hang *man){
    if(strcmp(man->word,man->status) == 0){
        system("cls");
        printf("WINNER!!!");
        return true;
    }

    if(man->lives <= 0){
        system("cls");
        printf("NICE TRYYY!!!");
        return true;
    }

    return false;
}