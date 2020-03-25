#include "graph.h"

bool Vertex::isAdjacent(const Vertex* v)
{
    if(!edges)
        return false;
    for(int i=0; i<edges->length; i++)
        if (edges->get(i) == v)
            return true;
    return false;
}

Vertex* Graph::insert(int n, LinkedList<Vertex*>* adjacents)
{
    auto v = new Vertex(n);
    if(adjacents)
        setEdges(v, adjacents);
    vertexes.add(v);
    return v;
}

void Graph::remove(Vertex* v)
{
    int idxRm = 0;
    for(int idxV=0; idxV < vertexes.length; idxV++) {
        auto vertex = vertexes.get(idxV);
        for(int idxE=0; idxE < vertex->edges->length; idxE++) {
            auto edge = vertex->edges->get(idxE);
            if(edge == v) {
                vertex->edges->remove(idxE);
                break;
            }
        }
        if(vertex == v) {
            idxRm = idxV;
        }
    }
    vertexes.remove(idxRm);
    delete v;
}

void Graph::addEdge(Vertex* leave, Vertex* enter)
{
    leave->edges->add(enter);
}

void Graph::setEdges(Vertex* v, LinkedList<Vertex*>* edges)
{
    if(v->edges)
        delete v->edges;
    v->edges = edges;
}