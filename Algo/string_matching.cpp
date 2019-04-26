#include <iostream>
#include <string.h>

bool endText(char *text, int j)
{
     return (strlen(text) < j);
}
int simpleScan(char *pattern, char *text)
{
     int m = strlen(pattern);
     int match = -1;
     int i, j, k;
     i = j = k = 0;
     while (!endText(text, j))
     {
          if (k >= m)
          {
               match = i;
               break;
          }
          if (text[j] == pattern[k])
          {
               j++;
               k++;
          }
          else
          {
               int backup = k - 1;
               j = j - backup;
               k = k - backup;
               i = j;
               j++;
          }
     }
     return match;
}

void kmpSetup(char *pattern, int *fail)
{
     int k, s;
     fail[0] = 0;
     for (k = 1; k < strlen(pattern); k++)
     {
          s = fail[k - 1];
          while (s >= 1)
          {
               if (pattern[s] == pattern[k])
                    break;
               s = fail[s - 1];
          }
          fail[k] = s + 1;
     }
}

int kmpScan(char *pattern, char *text)
{
     int m = strlen(pattern);
     int fail[m];
     kmpSetup(pattern, fail);
     int match = -1;
     int j, k;
     j = k = 0;
     while (!endText(text, j))
     {
          if (k >= m)
          {
               match = j - m; //match found
               break;
          }
          if (k == 0)
          {
               j++;
               k = 1; //start over
          }
          else if (text[j] == pattern[k])
          {
               j++;
               k++;
          }
          else
               k = fail[k - 1]; //follow the fail arrow
     }
     return match;
}

int main(int argc, char const *argv[])
{
     char text[] = "ABABABC";
     char pattern[] = "BA";
     std::cout << "\nMatch : " << simpleScan(pattern, text);
     return 0;
}
