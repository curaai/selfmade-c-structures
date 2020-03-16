#pragma once

class Element
{
public:
    Element(int item, Element* prev);
    Element(int item, Element* prev, Element* next);
    ~Element();

public:
    int item; 
    Element* prev=nullptr;
    Element* next=nullptr;
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void add(int item);
    Element* get(int idx);
    void remove(int idx);

public:
    Element* head=nullptr;
    Element* tail=nullptr;
    int length=0;
};