#include "stack.h"
#include <stdexcept>

void Stack::push(int x)
{
    list.add(x);
}

int Stack::pop(void)
{
    if(!list.length)
        throw std::length_error("Cannot popping on empty stack");

    auto element = list.get(list.length-1);
    int x = element->item;
    list.remove(list.length-1);
    return x; 
}