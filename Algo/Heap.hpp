#ifndef __HEAP_H_
#define __HEAP_H_

class Heap
{
     int *array;
     int heap_size;
     int length;
     int right(int i)
     {
          return ((2 * i) + 2);
     }

     int left(int i)
     {
          return ((2 * i) + 1);
     }

     void swap(int *n1, int *n2)
     {
          int temp = *n1;
          *n1 = *n2;
          *n2 = temp;
     }
     /*
     !Not sure about this!
     int parent(int i)
     {
          return (i / 2);
     }*/
   public:
     Heap(int *arr, int length);
     void build_max_heap();
     //void build_min_heap();
     void max_heapify(int i);
     //void min_heapify(int i);
     void sort();
     int getMax();
     int extract_max();
     /*
     ?Not Complete
     *May need to use vector 
     *or something like that for this 
     void increase_key(int i, int key);
     void insert(int key);*/
};

#endif
