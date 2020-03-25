#pragma once 

#include "linkedlist.h"

class Graph;

class Vertex
{
friend class Graph;
public:
    bool isAdjacent(const Vertex* v);
private:
    Vertex(int n=0) : n(n), edges(new LinkedList<Vertex*>()) {}
    ~Vertex(){ delete edges; }

public:
    const int n;
    LinkedList<Vertex*>* edges=nullptr;
};

class Graph
{
public:
    Graph(){}
    ~Graph(){}

public:
    Vertex* insert(int n, LinkedList<Vertex*>* adjacents);
    void remove(Vertex* v);
    bool contain(Vertex* v);
    void addEdge(Vertex* leave, Vertex* enter);
    void setEdges(Vertex* v, LinkedList<Vertex*>* edges);
    LinkedList<Vertex*> dps(Vertex* start);
    LinkedList<Vertex*> bps(Vertex* start);
    int getSize(void) { return vertexes.length; }

public:
    LinkedList<Vertex*> vertexes;
};