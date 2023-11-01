#include <stdio.h>

typedef struct{
    int row;
    int col;
}TABLE;

enum direction{
    RIGHT, DOWN, LEFT, UP
};

int main(){
    TABLE first, last;
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int arr[n][n], count = 1, i = 0, j = 0;
    first.row = 0, last.row = n-1, first.col = 0, last.col = n-1;
    enum direction rowCol = RIGHT;

    while (count <= n*n){
        arr[i][j] = count;
        count++;
        switch(rowCol){
            case RIGHT: 
                if(j < last.col){
                    j++;
                }else{
                    i++;
                    first.row++;
                    rowCol = DOWN;
                }
                break;
            case DOWN:
                if(i < last.row){
                    i++;
                }else{
                    j--;
                    last.col--;
                    rowCol = LEFT;
                }
                break;
            case LEFT:
                if(j > first.col){
                    j--;
                }else{
                    i--;
                    last.row--;
                    rowCol = UP;
                }
                break;
            case UP:
                if(i > first.row){
                    i--;
                }else{
                    j++;
                    first.col++;
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