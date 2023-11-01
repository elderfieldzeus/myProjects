#include <stdio.h>

enum direction{
    RIGHT, DOWN, LEFT, UP
};

int main(){
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int arr[n][n], count = 1, i = 0, j = 0, firstRow = 0, lastRow = n-1, firstCol = 0, lastCol = n-1;
    enum direction rowCol = RIGHT;

    while (count <= n*n){
        arr[i][j] = count;
        count++;
        switch(rowCol){
            case RIGHT: 
                if(j < lastCol){
                    j++;
                }else{
                    i++;
                    firstRow++;
                    rowCol = DOWN;
                }
                break;
            case DOWN:
                if(i < lastRow){
                    i++;
                }else{
                    j--;
                    lastCol--;
                    rowCol = LEFT;
                }
                break;
            case LEFT:
                if(j > firstCol){
                    j--;
                }else{
                    i--;
                    lastRow--;
                    rowCol = UP;
                }
                break;
            case UP:
                if(i > firstRow){
                    i--;
                }else{
                    j++;
                    firstCol++;
                    rowCol = RIGHT;
                }
                break;
        }
    }

    printf("Spiral matrix:\n");
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}