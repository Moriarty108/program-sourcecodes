#include <iostream>
#include <stdio.h>
#include <climits>
using namespace std;

#define SPACE_NOT_AVAILABLE -1

/* Function prototypes begin */
int spaceLeft(int mem_part[], int numOfPart);
void allocateByFirstFit(int mem_part[], int numOfPart, int process[], int numOfProc);
int availableSpace(int mem_part[], int numOfPart, int spaceRequired);
void allocateByBestFit(int mem_part[], int numOfPart, int process[], int numOfProc);
int smallestSpaceAvailable(int mem_part[], int numOfPart, int spaceRequired);
void allocateByWorstFit(int mem_part[], int numOfPart, int process[], int numOfProc);
int largestSpaceAvailable(int mem_part[], int numOfPart, int spaceRequired);
void displayAllocationDetails(int mem_part[], int numOfPart);
/* Function prototypes end */

int main()
{

    int numOfPart, numOfProc;
    cout << "\n => Enter Number of Memory Partitions:";
    cin >> numOfPart;
    int mem_part[numOfPart];
    cout << "\n => Enter the Size of the Partitions...\n";
    for (int i = 0; i < numOfPart; i++)
    {
        cout << "\nEnter Size for Partition " << i + 1 << " :";
        cin >> mem_part[i];
    }
    cout << "\n => Enter Number of Processes :";
    cin >> numOfProc;
    int process[numOfProc];
    cout << "\n => Enter the Size of the Processes...\n";
    for (int i = 0; i < numOfProc; i++)
    {
        cout << "\nEnter Size for Process " << i + 1 << " :";
        cin >> process[i];
    }
    cout << "\n => Choose an Algorithm for the Memory Allocation...";
    cout << "\n[1] First Fit";
    cout << "\n[2] Best Fit";
    cout << "\n[3] Worst Fit";
    cout << "\n => Choose [1-3]:";
    int ch;
    cin >> ch;
    if (ch == 1)
    {
        allocateByFirstFit(
            mem_part,
            numOfPart,
            process,
            numOfProc);
    }
    else if (ch == 2)
    {
        allocateByBestFit(
            mem_part,
            numOfPart,
            process,
            numOfProc);
    }
    else if (ch == 3)
    {
        allocateByWorstFit(
            mem_part,
            numOfPart,
            process,
            numOfProc);
    }

    cout << "\n\t Memory Status after Allocation...\n";
    displayAllocationDetails(mem_part, numOfPart);
    return 0;
}

void displayAllocationDetails(int mem_part[], int numOfPart)
{
    cout << "\n\t Partition           Space Free\n";

    for (int i = 0; i < numOfPart; i++)
    {
        cout << "\t     " << i + 1 << "                   " << mem_part[i] << "Kb\n";
    }
}
void allocateByWorstFit(int mem_part[], int numOfPart, int process[], int numOfProc)
{

    for (int i = 0; i < numOfProc; i++)
    {
        /* Finding the smallest space Available that will 
        suffice for the process */
        int index = largestSpaceAvailable(
            mem_part,
            numOfPart,
            process[i]);

        if (index != SPACE_NOT_AVAILABLE)
        {
            mem_part[index] -= process[i];
        }
        else
        {
            cout << "\n Warning! : Space Not Sufficient for Process\n " << i + 1;
        }
    }
}

void allocateByBestFit(int mem_part[], int numOfPart, int process[], int numOfProc)
{

    for (int i = 0; i < numOfProc; i++)
    {
        /* Finding the smallest space Available that will 
        suffice for the process */
        int index = smallestSpaceAvailable(
            mem_part,
            numOfPart,
            process[i]);

        if (index != SPACE_NOT_AVAILABLE)
        {
            mem_part[index] -= process[i];
        }
        else
        {
            cout << "\n Warning! : Space Not Sufficient for Process\n " << i + 1;
        }
    }
}

int largestSpaceAvailable(int mem_part[], int numOfPart, int spaceRequired)
{
    int spaceArray[numOfPart];
    int indexArray[numOfPart];
    int size = 0;
    for (int i = 0; i < numOfPart; i++)
    {
        if (spaceRequired <= mem_part[i])
        {
            indexArray[size] = i;
            spaceArray[size++] = mem_part[i];
        }
    }

    int max = INT_MIN;
    int index = -1;
    if (size != 0)
    {
        if (size == 1)
        {
            max = spaceArray[size - 1];
            index = indexArray[size - 1];
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if ((max < spaceArray[i]))
                {
                    max = spaceArray[i];
                    index = indexArray[i];
                }
            }
        }
    }
    if (size == 0)
        return size - 1;
    else
        return index;
}

int smallestSpaceAvailable(int mem_part[], int numOfPart, int spaceRequired)
{
    int spaceArray[numOfPart];
    int indexArray[numOfPart];
    int size = 0;
    for (int i = 0; i < numOfPart; i++)
    {
        if (spaceRequired <= mem_part[i])
        {
            indexArray[size] = i;
            spaceArray[size++] = mem_part[i];
        }
    }

    int min = INT_MAX;
    int index = -1;
    if (size != 0)
    {
        if (size == 1)
        {
            min = spaceArray[size - 1];
            index = indexArray[size - 1];
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                if ((min > spaceArray[i]))
                {
                    min = spaceArray[i];
                    index = indexArray[i];
                }
            }
        }
    }

    if (size == 0)
        return size - 1;
    else
        return index;
}
int spaceLeft(int mem_part[], int numOfPart)
{
    int space = 0;
    for (int i = 0; i < numOfPart; i++)
    {
        space += mem_part[i];
    }
    return space;
}

void allocateByFirstFit(int mem_part[], int numOfPart, int process[], int numOfProc)
{

    for (int i = 0; i < numOfProc; i++)
    {
        /* getting the index of where the space is available */
        int index = availableSpace(
            mem_part,
            numOfPart,
            process[i]);

        if (index != SPACE_NOT_AVAILABLE)
        {
            mem_part[index] -= process[i];
        }
    }
}
/* Returns the index at which space is available for a particular space */
int availableSpace(int mem_part[], int numOfPart, int spaceRequired)
{
    int index = -1;
    for (int i = 0; i < numOfPart; i++)
    {
        if (spaceRequired <= mem_part[i])
        {
            index = i;
            break;
        }
    }
    return index;
}