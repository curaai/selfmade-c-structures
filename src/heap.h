#pragma once 

#define HEAP_SIZE 64 

class Heap 
{
public:
    Heap(){}
    ~Heap(){}

    void insert(int k);
    void remove(void);
    static void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
public:
    int max=1;
    int arr[HEAP_SIZE] {0};
};