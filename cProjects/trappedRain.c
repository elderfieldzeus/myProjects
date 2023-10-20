#include <stdio.h>

/*
INPUT SIZES OF BUILDINGS AND COMPUTE THE WATER IN BETWEEN
EXAMPLE: 3 0 0 1 0 4
          *
*         *
*         *
* _ _ * _ *
3 0 0 1 0 4
THEREFORE, WATER IN BETWEEN IS 11 UNITS.
*/

int getHeight(int size){
    int height = 0;
    int arr[size];
    int lMax = 0, rMax = 0, left = 0, right = size-1; 
    printf("Enter the elements of the array:\n");

    for(int i= 0; i<size; i++){
        scanf("%d", &arr[i]);
    }
    
    while(left<right){
        if(arr[left] < arr[right]){
            if(lMax <= arr[left]){
                lMax = arr[left];
            }else{
                height += lMax - arr[left];
            }
            left++;
        }
        else{
            if(rMax <= arr[right]){
                rMax = arr[right];
            }else{
                height += rMax - arr[right];
            }
            right--;
        }
    }

    return height;
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int height = getHeight(size);
    printf("The amount of water trapped is %d.", height);
}