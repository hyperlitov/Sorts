#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define DEFAULT_SIZE 100

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


int main()
{
    std::srand(std::time(NULL));

    int arr[DEFAULT_SIZE];

    std::cout << "BEFORE: ";
    for (int i = 0; i < DEFAULT_SIZE; i++)
    {
        arr[i] = std::rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    

    return 0;
}
