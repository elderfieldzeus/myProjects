#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Going to sleep in:\n");
    for(int i = 5; i>0; i--){
        printf("%d...\n", i);
        sleep(1);
    }
    printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    return 0;
}