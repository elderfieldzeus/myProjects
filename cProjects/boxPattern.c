#include <stdio.h>

int main() {
    int width, length, i, j;
    
    printf("Input width: ");
    scanf("%d", &width);
    printf("Inpud length: ");
    scanf("%d", &length);
    
    for(i=0; i<length; i++){
    	if(i==0 || i==length-1){
    		for(j=0; j<width; j++){	
    			printf("* ");
    		}
    		printf("\n");
		}
		else{
			for(j=0; j<width; j++){
				if(j==0 || j==width-1){
					printf("* ");
				}
				else{
					printf("  ");
				}
			}
			printf("\n");
		}
	}
    
    return 0;
}

