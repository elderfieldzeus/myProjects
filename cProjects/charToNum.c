#include <stdio.h>

int main(){
	char string[100];
	int num[100], i, j=-1;
	scanf("%s", string);
	for(i = 0; string[i] != '\0'; i++){
		if(string[i] >= '0' && string[i] <= '9'){
			num[++j] = string[i] - '0';
		}
	}
	
	for(i=0; i<=j; i++){
		printf("%d", num[i]);
	}
	
	return 0;
}
