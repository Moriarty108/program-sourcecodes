#include <iostream>

void counting_sort(int *, int *, int, int);
int getMax(int *, int);
int main()
{
    int A[] = {2, 5, 3, 0, 2, 3, 0, 3};
    int B[8];

    counting_sort(A, B, getMax(A, 8), 8);

    std::cout << "\nArray After Sorting : ";

    for (int i = 0; i < 8; i++)
    {
        std::cout << B[i] << " ";
    }
    return 0;
}

void counting_sort(int *A, int *B, int k, int size_A)
{
    int *c = new int[k + 1];
    for (int i = 0; i < (k + 1); i++)
    {
        c[i] = 0;
    }

    for (int j = 0; j < size_A; j++)
    {
        c[A[j]] += 1;
    }

    for (int i = 1; i < (k + 1); i++)
    {
        c[i] += c[i - 1];
    }

    std::cout << "\nArray C :";
    for (int i = 0; i < k + 1; i++)
    {
        std::cout << c[i] << " ";
    }

    for (int j = size_A - 1; j >= 0; j--)
    {
        B[c[A[j]] - 1] = A[j];
        c[A[j]] = c[A[j]] - 1;
    }

    delete[] c;
}

int getMax(int *array, int size)
{
    int max = 0;
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}