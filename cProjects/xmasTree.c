#include <stdio.h>

int main() {
    int height, space, i, j;
    
    printf("Enter the height of the Xmas Tree: ");
    scanf("%d", &height);
    
    space = height-1;
    for(i=0; i<height; i++){
    	for(j=space-i; j>0; j--){
    		printf(" ");
		}
		for (j=0; j<((i+1)*2-1); j++){
			printf("*");
		}
		printf("\n");
	}
	for(i=0; i<space; i++){
		printf(" ");
	}
	printf("*");
    
    return 0;
}

