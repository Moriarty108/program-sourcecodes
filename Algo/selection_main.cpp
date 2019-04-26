#include <iostream>
#include "InputGen.cpp"
#include "selection_sort.cpp"

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
        sort(arr, length);
        printArray(arr, length);
        std::cout << "\n No of Comparisions : " << no_comparisions;
        file.closeFile();
    }
    return 0;
}