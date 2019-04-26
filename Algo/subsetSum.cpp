#include <iostream>
#include <vector>

bool isSubSetSum(std::vector<int> set, int sum)
{
     bool subset[set.size()][sum + 1];
     for (int i = 0; i < set.size(); i++)
          subset[i][0] = true;
     for (int i = 1; i <= sum; i++)
          subset[0][i] = false;

     for (int i = 1; i < set.size(); i++)
     {
          for (int j = 1; j <= sum; j++)
          {
               if (set[i] > j)
                    subset[i][j] = subset[i - 1][j];
               else
               {
                    subset[i][j] = (subset[i - 1][j] || subset[i - 1][j - set[i]]);
               }
          }
     }

     return subset[set.size() - 1][sum];
}

int main()
{
     std::vector<int> set = {0, 1, 2, 3, 6};
     int sum = 7;
     if (isSubSetSum(set, sum))
          std::cout << "Sum Found\n";
     return 0;
}