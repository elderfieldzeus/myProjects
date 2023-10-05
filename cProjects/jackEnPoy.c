#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int loadingScreen();
int getInput();
int getRandomNum();
int battleChecker(int input, int randomNum);
void printResults(int input, int randomNum, int checker);
int playAgain();
void exitApp();

int main(){
    system("cls");
    if (!loadingScreen())
        goto exit;

    start:
    system("cls");
    int input = getInput(),
    randomNum = getRandomNum();
    if (input == -1){
        goto start;
    }
    int checker = battleChecker(input, randomNum);
    printResults(input, randomNum, checker);

    if (playAgain()) 
        goto start;
    
    exit:
    exitApp();
    return 0;
}

int loadingScreen(){
    int start;
    printf("  WELCOME TO JACK EN POY BY ZEUS\n");
    printf("JUST PICK ROCK PAPER OR SCISSORS!!!\n");
    printf("     Press [1] to enter: ");
    scanf("%d", &start);

    if (start != 1)
        return 0;

    return start;
}

int getInput(){
    char choice[10];
    int i;
    printf("ROCK, PAPER, OR SCISSORS?!?!: ");
    scanf(" %s", choice);

    for(i = 0; choice[i] != '\0'; i++){
        choice[i] = tolower(choice[i]);
    }

    if (strcmp(choice, "rock") == 0)
        return 1;
    else if (strcmp(choice, "paper") == 0)
        return 2;
    else if (strcmp(choice, "scissors") == 0 || strcmp(choice, "scissors") == 0)
        return 3;

    return -1;
}

int getRandomNum(){
    srand(time(NULL));
    int randomNum = (rand() % 3) + 1;
    return randomNum;
}

int battleChecker(int input, int randomNum){
    if(randomNum == input)
        return 0;
    else if(input == 1 && randomNum == 3)
        return 1;
    else if(input < randomNum || (input == 3 && randomNum == 1))
        return -1;
    else{
        return 1;
    }
}   

void printResults(int input, int randomNum, int checker){
    system("cls");
    switch(input){
        case 1: 
            printf("        You chose ROCK!!!\n");
            break;
        case 2:
            printf("       You chose PAPER!!!\n");
            break;
        case 3:
            printf("      You chose SCISSORS!!!\n");
            break;
    }

    printf("    Your enemy chose ");
    switch(randomNum){
        case 1: 
            printf("ROCK!!!\n");
            break;
        case 2:
            printf("PAPER!!!\n");
            break;
        case 3:
            printf("SCISSORS!!!\n");
            break;
    }
    switch(checker){
        case 0: 
            printf("\n         ITS A TIE!!!\n\n");
            break;
        case 1:
            printf("\n         YOU WINNNNN!!!\n\n");
            break;
        case -1:
            printf("\n        YOU LOSEEEEE!!!\n\n");
            break;
    }
}

int playAgain(){
    char choice[5];
    printf("Would you like to play again? (Y/N): ");
    scanf(" %s", choice);

    for(int i = 0; choice[i] != '\0'; i++){
        choice[i] = tolower(choice[i]);
    }

    if(strcmp(choice, "yes") == 0 || strcmp(choice, "y") == 0)
        return 1;
    else
        return 0;
}

void exitApp(){
    system("cls");
    printf("THANKS FOR PLAYING!!!");
}
