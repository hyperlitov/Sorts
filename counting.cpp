#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#define DEFAULT_SIZE 100

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
    
    CountingSort(arr, DEFAULT_SIZE);

    return 0;
}

