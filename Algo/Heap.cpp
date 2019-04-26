#include "Heap.hpp"
#include <cstdlib>
#include <climits>

Heap::Heap(int *arr, int length)
{
     array = arr;
     this->length = length;
     this->heap_size = length;
}

void Heap::max_heapify(int i)
{
     int r = right(i);
     int l = left(i);
     int largest;
     if (l < this->heap_size && array[l] > array[i])
          largest = l;
     else
          largest = i;

     if (r < this->heap_size && array[r] > array[largest])
          largest = r;

     if (largest != i)
     {
          swap(&array[i], &array[largest]);
          max_heapify(largest);
     }
}

void Heap::build_max_heap()
{
     this->heap_size = this->length;
     for (int i = ((this->length / 2) - 1); i >= 0; i--)
     {
          max_heapify(i);
     }
}

void Heap::sort()
{
     this->build_max_heap();
     for (int i = length - 1; i >= 1; i--)
     {
          swap(&array[i], &array[0]);
          heap_size--;
          max_heapify(0);
     }
}

int Heap::getMax()
{
     return array[0];
}

int Heap::extract_max()
{
     if (heap_size < 1)
     {
          exit(EXIT_FAILURE);
     }

     int max = array[0];
     array[0] = array[heap_size - 1];
     heap_size--;
     max_heapify(0);
     return max;
}

/*
*Incomplete definitions
void Heap::increase_key(int i, int key)
{
     if (key < array[i])
          exit(EXIT_FAILURE);
     array[i] = key;
     while (i > 1 && array[parent(i)] < array[i])
     {
          swap(&array[parent(i)], &array[i]);
          i = parent(i);
     }
}

void Heap::insert(int key)
{
     heap_size++;
     array[heap_size - 1] = INT_MIN;
     increase_key(heap_size - 1, key);
}*/