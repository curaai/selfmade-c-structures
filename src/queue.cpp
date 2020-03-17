#include "queue.h"
#include <stdexcept>

void Queue::push(int x)
{
    list.add(x);
}

int Queue::pop(void)
{
    if(!list.length)
        throw std::length_error("Cannot popping on empty stack");

    auto element = list.get(0);
    int x = element->item;
    list.remove(0);
    return x;
}