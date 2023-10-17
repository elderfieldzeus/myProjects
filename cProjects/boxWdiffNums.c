#include <stdio.h>

int main(){
    setbuf(stdout, NULL);
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    for (int i = 0; i<=num*2-2; i++){
        int pNum = num;
        for (int j = 0; j<=num*2-2; j++){
            printf("%d ", pNum);
            if(j<i){
                pNum--;
            }
            if(j>=num*2-2-i){
                pNum++;
            }
        }
        printf("\n");
    }
}