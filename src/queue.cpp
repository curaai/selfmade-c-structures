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

    auto x = list.get(0);
    list.remove(0);
    return x;
}