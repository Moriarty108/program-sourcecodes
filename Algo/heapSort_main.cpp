#include "Heap.hpp"
#include <iostream>

void printArray(int *arr, int size);
int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    Heap heap(arr, 10);
    //heap.build_max_heap();
    heap.sort();
    std::cout << "Array after Sorting : ";
    printArray(arr, 10);
    std::cout << "\n";
    return 0;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}