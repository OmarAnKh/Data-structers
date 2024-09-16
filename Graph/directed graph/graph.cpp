#include <iostream>
#include "graph.h"
#include <vector>
using namespace std;
int main()
{
    Graph g;
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 5, 10);
    g.addEdge(1, 3, 20);
    g.addEdge(2, 3, 5);
    g.deleteEdge(1, 5);
    g.deleteVertex(2);
    g.printGraph();

    return 0;
}