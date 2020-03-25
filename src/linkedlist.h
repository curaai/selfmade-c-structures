#pragma once

#include <stdexcept>


template<typename T>
class Element
{
public:
    Element(T item, Element<T>* prev)
        : Element(item, prev, nullptr) {}
    Element(T item, Element<T>* prev, Element<T>* next)
        : item(item), prev(prev), next(next)
    {
        if(prev)
            prev->next = this;
        if(next)
            next->prev = this;
    }
    ~Element()
    {
        if(prev)
            prev->next = next;
        if(next)
            next->prev = prev;
    }

public:
    T item; 
    Element<T>* prev=nullptr;
    Element<T>* next=nullptr;
};

template<typename T>
class LinkedList
{
public:
    LinkedList(){};
    ~LinkedList()
    {
        while(head) {
            Element<T>* x = head->next;
            delete head;
            head = x;
        }
    }

    void add(T item)
    {
        tail = new Element<T> {item, tail};
        if(head == nullptr)
            head = tail;
        length++;
    }
    T& get(int idx)
    {
        int cnt = 0;
        Element<T>* tElement = head;
        while(idx != cnt++) 
            tElement = tElement->next;
        
        return tElement->item;
    }
    void remove(int idx)
    {
        if(0 > idx || idx > length-1)
            throw std::invalid_argument("Index Error");
        if(idx == length-1)
            tail = tail->prev;
        auto item = getElement(idx);
        if(idx == 0) {
            head = item->next;
        }
        delete item;
        length--; 
    }

private:
    Element<T>* getElement(int idx)
    {
        int cnt = 0;
        Element<T>* tElement = head;
        while(idx != cnt++) 
            tElement = tElement->next;
        
        return tElement;
    }

public:
    Element<T>* head=nullptr;
    Element<T>* tail=nullptr;
    int length=0;
};