#include <climits>

int no_comparisions = 0;
int getMinIndex(int *array, int startIndex, int endIndex)
{
    int min = INT_MAX;
    int index = -1;
    for (int i = startIndex; i <= endIndex; i++)
    {
        no_comparisions++;
        if (min > array[i])
        {
            min = array[i];
            index = i;
        }
    }
    return index;
}

void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sort(int *array, int size)
{
    no_comparisions = 0;
    for (int i = 0; i < size - 1; i++)
    {
        swap(array + i, array + getMinIndex(array, i, size - 1));
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}
