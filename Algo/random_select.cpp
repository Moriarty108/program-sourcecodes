#include <iostream>
#include <vector>

int randomised_select(std::vector<int> array, int p, int r, int i)
{
     if (p == r)
          return array[p];
     //TODO:randomised_partition
     q = randomised_partition(array, p, r);
     k = q - p + 1; //position of pivot in smaller list
     if (i == k)
          return array[q];
     else if (i < k)
          return randomised_select(array, p, q - 1, r);
     else
          return randomised_select(array, q + 1, r, i - k);
}

int main(int argc, char const *argv[])
{

     return 0;
}
