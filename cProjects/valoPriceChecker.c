#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define numOfGuns 17
 
typedef struct{
	char gunName[20];
	int price;
	char type[20];
}Stats;
 
char *getChoice();
Stats *listOfGuns();
void checkGun(char *gun);
int anotherGun();
void thankYou();
 
int main(){
	char *gun;
    int another;
    do{
        gun = getChoice();
	    checkGun(gun);
        another = anotherGun();
    }while(another);

    thankYou();
	free(gun);
	return 0;
}
 
char *getChoice(){
    system("cls");
	char *choice = malloc(sizeof(char)*20);
	printf("Enter gun of choice: ");
	scanf(" %20[^\n]", choice);
	return choice;
}
 
Stats *listOfGuns(){
	Stats *bang = malloc(sizeof(Stats)*numOfGuns);
 
	strcpy(bang[0].gunName, "classic");
	bang[0].price = 0;
	strcpy(bang[1].gunName, "shorty");
	bang[1].price = 300;
	strcpy(bang[2].gunName, "frenzy");
	bang[2].price = 450;
	strcpy(bang[3].gunName, "ghost");
	bang[3].price = 500;
	strcpy(bang[4].gunName, "sheriff");
	bang[4].price = 800;
 
	for (int i=0; i<=4; i++){
		strcpy(bang[i].type, "Pistol");
	}
 
	strcpy(bang[5].gunName, "stinger");
	bang[5].price = 1100;
	strcpy(bang[6].gunName, "spectre");
	bang[6].price = 1600;
 
	for (int i=5; i<=6; i++){
		strcpy(bang[i].type, "SMG");
	}
 
	strcpy(bang[7].gunName, "bucky");
	bang[7].price = 850;
	strcpy(bang[8].gunName, "judge");
	bang[8].price = 1850;
 
	for (int i=7; i<=8; i++){
		strcpy(bang[i].type, "Shotgun");
	}
 
	strcpy(bang[9].gunName, "bulldog");
	bang[9].price = 2050;
	strcpy(bang[10].gunName, "guardian");
	bang[10].price = 2250;
	strcpy(bang[11].gunName, "phantom");
	bang[11].price = 2900;
	strcpy(bang[12].gunName, "vandal");
	bang[12].price = 2900;
 
	for (int i=9; i<=12; i++){
		strcpy(bang[i].type, "Rifle");
	}
 
	strcpy(bang[13].gunName, "marshal");
	bang[13].price = 950;
	strcpy(bang[14].gunName, "operator");
	bang[14].price = 4700;
 
	for (int i=13; i<=14; i++){
		strcpy(bang[i].type, "Sniper Rifle");
	}
 
	strcpy(bang[15].gunName, "ares");
	bang[15].price = 1600;
	strcpy(bang[16].gunName, "odin");
	bang[16].price = 3200;
 
	for (int i=15; i<=16; i++){
		strcpy(bang[i].type, "Machine Gun");
	}
 
 
	return bang;
}
 
void checkGun(char *gun){
    system("cls");
	Stats *bang = listOfGuns();
 
	for(int i=0; gun[i] != '\0'; i++){
		gun[i] = tolower(gun[i]);
	}
 
	for(int i=0; i<numOfGuns; i++){
		if(!strcmp(gun, bang[i].gunName)){
			printf("Gun Type: %s\n", bang[i].type);
            bang[i].gunName[0] = toupper(bang[i].gunName[0]);
			printf("Gun Name: %s\n", bang[i].gunName);
			printf("Price: %d Credits", bang[i].price);
            free(bang);
			return;
		}
	}
    free(bang);
    printf("INVALID INPUT");
}

int anotherGun(){
    char choice;
    printf("\n\nAnother? (y/n): ");
    scanf(" %c", &choice);
    if(tolower(choice) == 'y')
        return 1;
    else   
        return 0;
}

void thankYou(){
    system("cls");
    printf("THANK YOU FOR USING!");
}