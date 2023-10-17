#include <stdio.h>

int main(){
    int binary = 0, num, digit = 0;
    printf("Enter your number: ");
    scanf("%d", &num);
    int copyN = num;
    while (copyN != 0){
        digit++;
        copyN/=2;
    }
    int times = 0;
    for(num; num!=0; num/=2){
        if(num%2){
            int add = 1;
            for(int i = 0; i<times; i++){
                add*=10;
            }
            binary+=add;
        }
        times++;   
    }
    //check palindrome
    int copyB = binary;
    int checker = 1;
    while(copyB!=0 && checker){
        int lastD = copyB%10;
        int div = 1;
        for(int i = 0; i<digit-1; i++){
            div*=10;
        }
        int firstD = copyB/div;
        if(lastD != firstD){
            checker = 0;
        }
        digit-=2;
        copyB-=firstD*div;
        copyB/=10;
    } 
    printf("The value of your soul is %d.\n", binary);
    checker ? printf("You are worthy my child.") : printf("Ahh, you are filty. Be gone.");
}