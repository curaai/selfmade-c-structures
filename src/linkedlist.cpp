#include "linkedlist.h"
#include <stdexcept>


Element::Element(int item, Element* prev)
    : Element(item, prev, nullptr)
{
    
}

Element::Element(int item, Element* prev, Element* next)
    : item(item)
    , prev(prev)
    , next(next)
{
    if(prev)
        prev->next = this;
    if(next)
        next->prev = this;
}

Element::~Element()
{
    if(prev)
        prev->next = next;
    if(next)
        next->prev = prev;
}


LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{
    while(head) {
        Element* x = head->next;
        delete head;
        head = x;
    }
}

void LinkedList::add(int item)
{
    tail = new Element {item, tail};
    if(head == nullptr)
        head = tail;
    length++;
}


Element* LinkedList::get(int idx)
{
    int cnt = 0;
    Element* tElement = head;
    while(idx != cnt++) 
        tElement = tElement->next;
    
    return tElement;
}

void LinkedList::remove(int idx)
{
    if(0 > idx || idx > length-1)
        throw std::invalid_argument("Index Error");
    if(idx == length-1)
        tail = tail->prev;
    auto item = get(idx);
    if(idx == 0) {
        head = item->next;
    }
    delete item;
    length--; 
}