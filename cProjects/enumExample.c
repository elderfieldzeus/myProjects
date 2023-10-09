#include <stdio.h>
#include <string.h>

typedef enum{
    cat, dog, monkey, horse
}animals;

int main(){
    animals type;
    type = dog;
    printf("Type is in index: %d", type);
    return 0;
}