#include "heap.h"


void Heap::insert(int k) 
{
    // insert first 
    arr[max++] = k;

    int i=max-1;
    int parent = static_cast<int>(i / 2);
    
    while(arr[parent] != 0 && i > 1)
    {
        if (arr[i] > arr[parent])
            swap(&arr[i], &arr[parent]);
        else
            break;
        i = parent;
    }
}

void Heap::remove(void)
{
    // set last element to root
    arr[1] = arr[max-1]; 
    arr[max-1] = 0;

    int i = 1;
    while(i < max)
    {
        int cmpIdx = arr[i*2] > arr[i*2+1] ? i*2 : i*2+1;
        if(arr[i] < arr[cmpIdx])
            swap(&arr[i], &arr[cmpIdx]);
        else
            break;
        i = cmpIdx;
    }
}