#include <iostream>

void insertion_sort(int *array, int size)
{
     for (int i = 0; i < size; i++)
     {
          int key = array[i];
          int j = i - 1;
          while (j >= 0 && array[j] > key)
          {
               array[j + 1] = array[j];
               j--;
          }
          array[j + 1] = key;
     }
}

void printArray(int *array, int size)
{
     for (int i = 0; i < size; i++)
     {
          std::cout << array[i] << " ";
     }
}

int main(int argc, char const *argv[])
{
     int arr[] = {10, 54, 12, 34, 23, 76};
     insertion_sort(arr, 6);
     printArray(arr, 6);
     return 0;
}
