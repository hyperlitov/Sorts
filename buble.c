#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
void Bubble(int array[], int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
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
        arr[i] = rand()%100;
    }
    print_array(arr, SIZE);
    Bubble(arr, SIZE);
    print_array(arr, SIZE);
    return 0;
}