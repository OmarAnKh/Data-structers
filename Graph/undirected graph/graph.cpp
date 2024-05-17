#include <iostream>
#include "graph.h"
#include <vector>
using namespace std;

int main()
{
    Edges graph(5);
    graph.insert(1, 2);
    graph.insert(0, 1);
    graph.insert(1, 3);
    graph.insert(2, 3);
    graph.insert(0, 4);
    graph.printGraph();
    vector<int> result = graph.breadthSearch(0);
    for (auto i = result.begin(); i != result.end(); ++i)
        cout << *i << " ";
}