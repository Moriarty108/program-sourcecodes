#include <iostream>
#include "InputGen.cpp"

int bubble_sort(int *, int);
void printArray(int *, int);
int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "\nPlease Specify the File Name";
    }
    else
    {
        InputFileGen file;
        file.openFile(argv[1]);
        int arr[1000];
        int length = file.read(arr);
        int no_comparisions = bubble_sort(arr, length);
        printArray(arr, length);
        std::cout << "\n No of Comparisions : " << no_comparisions;
        file.closeFile();
    }
    return 0;
}

int bubble_sort(int *arr, int size)
{
    int count = 0, temp;
    bool sorted = false;

    for (int i = 0; i < size - 1; i++)
    {
        if (sorted)
            break;

        sorted = true;

        for (int j = 0; j < size - i - 1; j++)
        {
            count++;

            if (arr[j] > arr[j + 1])
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;

                sorted = false;
            }
        }
    }

    return count;
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}