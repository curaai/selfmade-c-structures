#include "graph.h"

// bool Vertex::isAdjacent(const Vertex* v)
// {
//     for(int i=0; i<edges.length; i++)
//         if (edges[i] == v)
//             return true;
//     return false;
// }

// void Vertex::addEdge(Vertex* v)
// {
//     for(int i=0; i<edges.length; i++)
//         if (edges[i] == v)
//             return;
//     edges.add(v);
// }


// Vertex* Graph::insert(int n, LinkedList<Vertex*> adjacents)
// {
//     auto v = new Vertex(n);
//     if(adjacents)
//         v->edges = adjacents;
//     vertexes.add(v);
// }

// void Graph::remove(Vertex* v)
// {
//     for(int idxV=0; idxV < vertexes.length; idxV++) {
//         auto vertex = vertexes.get(idxV);
//         for(int idxE=0; idxE < vertex->item->edges.length; idxE++) {
//             auto edge = vertex->item->edges.get(idxE);
//             if(edge == v) {
//                 vertex->item->edges.remove(idxE);
//                 break;
//             }
//         }
//     }
//     vertexes.remove(v); 
// }