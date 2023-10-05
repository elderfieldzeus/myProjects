#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int askForChoice();
void choiceChecker(int choice);
void printBinary(int num);
void printInteger(char* binary);
void askAgain();

int main(){
    system("cls");
	int choice;
	choice = askForChoice();	
	choiceChecker(choice);	
	return 0;
}

int askForChoice(){
	int choice;
	printf("Do you wanna input decimal or binary?\n(1) Decimal\n(2) Binary\n\nAnswer: ");
	scanf("%d", &choice);
	return choice;
}

void choiceChecker(int choice){
	if(choice == 1){
		system("cls");
		int num;
		printf("Enter your decimal number: ");
		scanf("%d", &num);
		printBinary(num);
	}else if(choice == 2){
		system("cls");
		char binary[100];
		printf("Enter your binary number: ");
		scanf("%s", binary);
		printInteger(binary);
	}else{
		system("cls");
		printf("TRY AGAIN!!\n\n");
		main();
	}
}

void printBinary(int num){
	int size = (num>255) ? 16: 8;
	char binaryOutput[size];
	binaryOutput[size] = '\0';
	for(size; size>=0; num/=2){
		if(num%2 == 1){
			binaryOutput[--size] = '1';
		}else{
			binaryOutput[--size] = '0';
		}
	}
	printf("Binary form: %s", binaryOutput);
	askAgain();
}

void printInteger(char* binary){
	int i=0, yes = 1;
	long long num = 0;
	for(i = 1; i<strlen(binary); i++){
		if(binary[strlen(binary)-i] != '0' && binary[strlen(binary)-i] != '1'){
			yes = 0;
			break;
		}
		if(binary[strlen(binary)-i] == '1'){
			num += pow(2,i-1);
		}
	}
	
	(yes) ? printf("Integer form: %lld", num) : printf("INVALID INPUT");
	askAgain();
	
}

void askAgain(){
	printf("\n\nWould you like to convert another decimal/binary? \n(y) or (n): ");
	char choice;
	scanf(" %c", &choice);
	choice = tolower(choice);
	system("cls");
	(choice == 'y') ? main(): printf("Thank you for using!");
}