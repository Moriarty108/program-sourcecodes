#include <iostream>

int partition(int *array, int start, int end)
{
     int pivot = array[end];
     int i = (start - 1);
     for (int j = start; j < end; j++)
     {
          if (pivot >= array[j])
          {
               i++;
               int temp = array[i];
               array[i] = array[j];
               array[j] = temp;
          }
     }

     int temp = array[i + 1];
     array[i + 1] = array[end];
     array[end] = temp;

     return (i + 1);
}

void quick_sort(int *array, int start, int end)
{
     if (start < end)
     {
          int q = partition(array, start, end);
          quick_sort(array, start, q - 1);
          quick_sort(array, q + 1, end);
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
     int arr[] = {45, 54, 12, 34, 23, 76};
     quick_sort(arr, 0, 5);
     printArray(arr, 6);
     return 0;
}
