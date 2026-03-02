#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 100


void MergeSort (int array[], int size, int left_index, int right_index)
{
    if (left_index < right_index)
    {
        int mid_index = left_index + (right_index - left_index) / 2;

        MergeSort(array, size, left_index, mid_index);
        MergeSort(array, size, mid_index + 1, right_index);

        int l = left_index;
        int r = mid_index + 1;
        
        int buf[size];
        for (int i = 0; i < size; i++)
            buf[i] = array[i];
        
        
        while (l <= mid_index && r <= right_index)
        {
            if (array[l] > array[r])
            {
                buf[r + l - mid_index - 1] = array[r];
                r++;
            }
            else
            {
                buf[r + l - mid_index - 1] = array[l];
                l++;
            }
        }
        
        while (l <= mid_index)
        {
            buf[r + l - mid_index - 1] = array[l];
            l++;
        }
        
        for (int i = left_index; i <= right_index; i++)
            array[i] = buf[i];
    }
}


void print_array(int arr[], int size, int reverse){
    switch (reverse)
    {
    case 0:
        for(int i = 0; i<size; ++i){
            printf("%d ", arr[i]);
        }
        break;
    
    default:
        for(int i = size-1; i>=0; --i){
            printf("%d ", arr[i]);
        }
        break;
    }
    
    printf("\n");
}
void print_chet_nechet(int arr[], int size){
    for(int i = size-1; i>=0; --i){
        if(arr[i] %2 == 0){
            printf("%d ", arr[i]);
        }
    }
    for(int i = size-1; i>=0; --i){
        if(arr[i] %2 != 0){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int arr[SIZE];
    for(int i = 0; i<SIZE; ++i){
        arr[i] = rand()%1000;
    }
    print_array(arr, SIZE, 0);
    MergeSort(arr, SIZE, 0, SIZE-1);
    print_chet_nechet(arr, SIZE);
    

    return 0;
}






