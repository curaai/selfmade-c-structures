#include "set.h"

#include <stdexcept>


Set::Set(LinkedList& list)
{
    for(int i=0; i<list.length; i++)
        add(list.get(i)->item);
}

Set::Set(std::initializer_list<int> vec)
{
    for(int x : vec)
        add(x);
}


void Set::add(int x)
{
    if(!contain(x))
        list.add(x);
}

void Set::remove(int x)
{
    for(int i=0; i<list.length; i++) {
        auto var = list.get(i);
        if(var->item == x) {
            list.remove(i);
            return;
        }
    }
    throw std::invalid_argument("Cannot find value");
}

bool Set::contain(int x)
{
    for(int i=0; i<list.length; i++) {
        if(list.get(i)->item == x) 
            return true;
    }
    return false;
}

LinkedList* Set::toList(void)
{
    auto data = new LinkedList;
    for(int i=0; i<list.length; i++)
        data->add(list.get(i)->item);
    return data;
}

Set Set::operator&(Set& set) 
{
    LinkedList data;
    for(int i=0; i<list.length; i++) {
        auto var = list.get(i)->item;
        if(set.contain(var))
            data.add(var);
    }

    return Set{data};
}

Set Set::operator|(Set& set) 
{
    LinkedList data;
    for(int i=0; i<list.length; i++) {
        data.add(list.get(i)->item);
    }

    auto tempList = set.toList();
    for(int i=0; i<tempList->length; i++) {
        auto var = tempList->get(i)->item;
        if(!contain(var))
            data.add(var);
    }
    return Set{data};
}

Set Set::operator-(Set& set) 
{
    LinkedList data;
    for(int i=0; i<list.length; i++) {
        auto var = list.get(i)->item;
        if(!set.contain(var))
            data.add(var);
    }
    return Set(data);
}

bool Set::operator==(Set& set)
{
    if(set.getSize() != getSize()) 
        return false;
    return *this < set;
}

bool Set::operator<(Set& set) 
{
    for(int i=0; i<list.length; i++) {
        auto var = list.get(i)->item;
        if(!set.contain(var))
            return false;
    }
    return true;
}
