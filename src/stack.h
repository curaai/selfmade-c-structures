#pragma once 

#include "linkedlist.h"

class Stack 
{
public:
    Stack(){}
    ~Stack(){}
    void push(int x);
    int pop(void);
    const int getSize(void) { return list.length; }

private:
    LinkedList list;
};