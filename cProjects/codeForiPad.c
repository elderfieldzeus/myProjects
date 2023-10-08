#include <stdio.h>

int main(){
    setbuf(stdout, NULL); //THIS ALLOWS INPUT ON IPAD TERMINAL
    printf("\033[H\033[J"); //THIS CLEARS THE SCREEN IN TERMINAL
    printf("WOW THIS WAS CODED IN IPAD???");
    return 0;
}