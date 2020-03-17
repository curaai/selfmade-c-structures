#pragma once 

#include "linkedlist.h"

#include <initializer_list>

class Set 
{
public:
    Set(){};
    Set(LinkedList& list);
    Set(std::initializer_list<int> vec);
    ~Set(){};

    void add(int x);
    void remove(int x);
    bool contain(int x);
    int getSize(void) { return list.length; }
    bool isEmpty(void) { return static_cast<bool>(list.length); }
    LinkedList* toList(void); 

    Set operator&(Set& set);
    Set operator|(Set& set);
    Set operator-(Set& set); 
    bool operator==(Set& set); 
    bool operator<(Set& set); 
    
private:
    LinkedList list;
};