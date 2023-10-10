#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct{
    char guess[6];
    char answer[6];
    char status[6];
    int correctPosition[6];
    int correctLetter[6];
}Wordle;

Wordle getStruct();
int homePage();
void exitNow();
void startGame(Wordle *word);
void askGuess(Wordle *word);
void checkWord(Wordle *word);
void printStatus(Wordle *word);
void endGame(Wordle word);
void sortCLArray(Wordle *word);

int main(){
    Wordle word = getStruct();
    if(homePage()){
        startGame(&word);
        endGame(word);
    }
    else{
        exitNow();
    }
    
    return 0;
}

Wordle getStruct(){
    srand(time(0));
    Wordle input;
    printf("\033[H\033[J");
    int wordGenerator = rand()%10 + 1;
    switch(wordGenerator){
        case 1: strcpy(input.answer, "whirl");break;
        case 2: strcpy(input.answer, "minor");break;
        case 3: strcpy(input.answer, "attic");break;
        case 4: strcpy(input.answer, "growl");break;
        case 5: strcpy(input.answer, "swift");break;
        case 6: strcpy(input.answer, "crepe");break;
        case 7: strcpy(input.answer, "honey");break;
        case 8: strcpy(input.answer, "funky");break;
        case 9: strcpy(input.answer, "grave");break;
        case 10: strcpy(input.answer, "dwell");break;
    }  
    strcpy(input.status, "_____");
    
    return input;
}

int homePage(){
    char start[5];
    printf("\033[H\033");
    printf("WELCOME TO HONEY ALISON'S WORDLE!!!\n");
    printf("   Type \"play\" to start: ");
    scanf(" %s", start);
    for(int i = 0; start[i] != '\0'; i++){
        start[i] = tolower(start[i]);
    }
    if(!strcmp(start, "play")){
        printf("\033[H\033[J");
        return 1;
    }  
    return 0;
}

void exitNow(){
    printf("\033[H\033[J");
    printf("THANKS FOR TRYING!!!");
}

void startGame(Wordle *word){
    do{
        askGuess(word);
        checkWord(word);
        printStatus(word);
    }while(strcmp(word->answer, word->guess));
}

void askGuess(Wordle *word){
    do{
        printf("STATUS: %s\n", word->status);
        printf("Input guess: ");
        scanf(" %s", word->guess);
        if(!strcmp(word->guess, "ANS"))
            printf("%s\n\n", word->answer);
        if(strlen(word->guess) != 5)
            printf("\nONLY INPUT FIVE LETTER WORD!!!\n");
    }while(strlen(word->guess) != 5);
}

void checkWord(Wordle *word){
    int cpCount = 0, clCount = 0;
    for(int i = 0; i<5; i++){
        word->guess[i] = tolower(word->guess[i]);
    }
    word->correctPosition[0] = -1;
    word->correctLetter[0] = -1;
    for(int i = 0; i<5; i++){
        if(word->answer[i] == word->guess[i]){
            word->correctPosition[cpCount] = i;
            word->correctPosition[++cpCount] = -1;
            word->status[i] = word->guess[i];
        }
        else{
            for(int j = 0; j<5; j++){
                if(word->answer[i] == word->guess[j]){
                    word->correctLetter[clCount] = j;
                    word->correctLetter[++clCount] = -1;
                }
            }
        }
    }
}

void printStatus(Wordle *word){
    if(!strcmp(word->answer, word->guess))
        return;
    printf("\nLetters with correct positions: ");
    for(int i = 0; word->correctPosition[i] != -1; i++){
        printf("%c ", word->guess[word->correctPosition[i]]);
    }
    sortCLArray(word);
    printf("\nCorrect letters with wrong positions: ");
    for(int i = 0; word->correctLetter[i] != -1; i++){
        printf("%c ", word->guess[word->correctLetter[i]]);
    }
    printf("\n\n");
}

void endGame(Wordle word){
    printf("\033[H\033[J");
    for(int i = 0; i<5; i++){
        word.status[i] = toupper(word.status[i]);
    }
    printf("CONGRATS!!! THE WORD WAS %s!!!", word.status);
}

void sortCLArray(Wordle *word){
    int size = 0;
    for(int i = 0; word->correctLetter[i] != -1; i++){
        size++;
    }
    for(int i = 0; i<size-1; i++){
        for(int j=0; j<size-1-i; j++){
            if(word->correctLetter[j] > word->correctLetter[j+1]){
                int temp = word->correctLetter[j];
                word->correctLetter[j] = word->correctLetter[j+1];
                word->correctLetter[j+1] = temp;
            }
        }
    }
}
