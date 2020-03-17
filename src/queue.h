#pragma once 

#include "linkedlist.h"


class Queue 
{
public:
    Queue(){};
    ~Queue(){};

    void push(int x);
    int pop(void);
    int getSize(void) { return list.length; }


private:
    LinkedList list;
};