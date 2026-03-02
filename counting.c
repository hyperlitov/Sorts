#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100

void CountingSort(int array[], int size)
{
    int counter_array[1000/*при ограничении значения числа в исходном массиве до 1000*/] = {0};
    int index = 0;

    for (int i = 0; i < size; i++)
        counter_array[array[i]]++;
    
    for (int i = 0; i < 1000 - 1; i++)
        for (int j = 0; j < counter_array[i]; j++)
        {
            array[index] = i;
            index++;
        }
}
void print_array(int arr[], int size){
    for(int i = 0; i<size; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[SIZE];
    for(int i = 0; i<SIZE; ++i){
        arr[i] = rand()%1000;
    }
    print_array(arr, SIZE);
    CountingSort(arr, SIZE);
    print_array(arr, SIZE);
    return 0;
}