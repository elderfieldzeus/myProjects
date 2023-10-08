#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int arr[5];
}Numbers;

Numbers getNumbers();
void bubbleSort(Numbers array);
void selectionSort(Numbers array);
void insertionSort(Numbers array);
void mergeSort(Numbers array);

int main(){
    setbuf(stdout, NULL);
    Numbers array = getNumbers();
    bubbleSort(array);
    selectionSort(array);
    insertionSort(array);
}

Numbers getNumbers(){
    Numbers array;
    printf("\033[H\033[J");
    for(int i=0; i<5; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &array.arr[i]);
    }
    return array;
}

void bubbleSort(Numbers array){
    int copy[5];
    for(int i=0; i<5; i++){
        copy[i] = array.arr[i];
    }

    //BUBBLE SORTING ALGORITHM BELOW
    for(int i=1; i<5; i++){
        for(int j=0; j<5-i; j++){
            if(copy[j] > copy[j+1]){
                int temp = copy[j];
                copy[j] = copy[j+1];
                copy[j+1] = temp;
            }
        }
    }

    //PRINT
    printf("\nBUBBLE SORT: \t[");
    for(int i=0; i<5; i++){
        printf("%d ", copy[i]);
    }
    printf("\b]");
}

void selectionSort(Numbers array){
    int copy[5];
    for(int i=0; i<5; i++){
        copy[i] = array.arr[i];
    }

    //SELECTION SORTING ALGORITHM BELOW
    for(int i = 0; i<5-1; i++){
        int min = i;
        for(int j=i+1; j<5; j++){
            if(copy[j] < copy[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = copy[min];
            copy[min] = copy[i];
            copy[i] = temp;
        }
    }

    //PRINT
    printf("\nSELECTION SORT: [");
    for(int i=0; i<5; i++){
        printf("%d ", copy[i]);
    }
    printf("\b]");
}

void insertionSort(Numbers array){
    int copy[5];
    for(int i=0; i<5; i++){
        copy[i] = array.arr[i];
    }

    //INSERTION ALGORITHM BELOW
    for(int i = 1; i<5; i++){
        int key = copy[i];
        int j = i-1;

        while(j >= 0 && copy[j] > key){
            copy[j+1] = copy[j];
            j = j-1;
        }
        copy[j+1] = key;
    }

    //PRINT
    printf("\nINSERTION SORT: [");
    for(int i=0; i<5; i++){
        printf("%d ", copy[i]);
    }
    printf("\b]");
}

void mergeSort(Numbers array){
    int copy[5];
    for(int i=0; i<5; i++){
        copy[i] = array.arr[i];
    }

    //MERGE SORT ALGORITHM BELOW

}