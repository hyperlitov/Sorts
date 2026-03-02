#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define DEFAULT_SIZE 100

void InsertionSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            int curr_index = i + 1;
            int counter = 0;

            while (curr_index > 0 && array[curr_index] < array[curr_index - 1])
            {
                int tmp = array[curr_index];
                array[curr_index] = array[curr_index - 1];
                array[curr_index - 1] = tmp;
                curr_index--;
            }
        }
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

    InsertionSort(arr, DEFAULT_SIZE);

    return 0;
}
