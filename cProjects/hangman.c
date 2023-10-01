#include <stdio.h>
#include <string.h>

int main(){
	
	char hangman[]= "zeus";
	char progress[]= {'_','_','_','_'};
	char guess;
	
	int a=0;
	int i;
	
	while(a<=3){	
		
	printf("Your status is %s \nGuess a letter:", progress);
	scanf(" %c",&guess);
	
	int correctGuess = -1;
	
	for(i=0; i<4; i++){
		if(guess == hangman[i]){
			correctGuess = i;
			break;
		}
	}
	
	if(correctGuess != -1){
		progress[correctGuess]=guess;
		for(i=0;i<4;i++){
			printf("%c ",progress[i]);
		}
		printf("\n");
	}
	
	else{
		a++;
	}
		if(a == 0){
			printf("\n_____________\n");
			printf("|     |      \n");
			printf("|            \n");
			printf("|            \n");
			printf("|             \n");
			printf("|____________\n\n");
			;
		
		}
		else if(a == 1){
			printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     O      \n");
			printf("|             \n");
			printf("|             \n");
			printf("|____________\n");
		
		}else if(a == 2){
			printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     O      \n");
			printf("|    /|\\    \n");
			printf("|             \n");
			printf("|____________\n\n");
		
		}else if(a == 3){
			printf("\n_____________\n");
			printf("|     |      \n");
			printf("|     O      \n");
			printf("|    /|\\    \n");
			printf("|    / \\    \n");
			printf("|____________\n\n");
			printf("\n GAME OVER!");
			break;
		}
		
		if(strcmp(progress,hangman)==0){
		printf("\nGOOD GAME");
		break;
	}
	
	
	}
	

	return 0;
	
}


