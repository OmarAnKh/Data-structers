#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph
{
private:
    unordered_map<int, set<vector<int>>> graph;

public:
    void addVertex(int vertex)
    {
        graph[vertex];
    }

    int addEdge(int src, int des, int cost)
    {
        addVertex(src);
        addVertex(des);
        if (graph.find(src) != graph.end())
        {
            for (auto SetItr = graph[src].begin(); SetItr != graph[src].end(); SetItr++)
            {
                if ((*SetItr)[0] == des)
                {
                    if ((*SetItr)[1] > cost)
                    {
                        vector<int> updatedEdge = *SetItr;
                        graph[src].erase(SetItr);
                        updatedEdge[1] = cost;
                        graph[src].insert(updatedEdge);
                        return 1;
                    }
                    return 1;
                }
            }
            vector<int> temp = {des, cost};
            graph[src].insert(temp);
            return 1;
        }
        return 0;
    }

    void printGraph()
    {
        for (auto graphItr = graph.begin(); graphItr != graph.end(); graphItr++)
        {
            cout << "Vertex " << graphItr->first << " has edges: \n";

            for (auto SetItr = graphItr->second.begin(); SetItr != graphItr->second.end(); SetItr++)
            {
                cout << "  -> Destination: " << (*SetItr)[0] << ", Cost: " << (*SetItr)[1] << endl;
            }
        }
    }

    bool deleteVertex(int Vertex)
    {
        if (graph.find(Vertex) == graph.end())
        {
            return false;
        }

        for (auto graphItr = graph.begin(); graphItr != graph.end(); graphItr++)
        {
            deleteEdge(graphItr->first, Vertex);
        }
        graph.erase(Vertex);
        return true;
    }

    bool deleteEdge(int src, int des)
    {
        vector<int> temp = isAdjacent(src, des);
        if (temp.size() > 0)
        {
            graph[src].erase(temp);
            return 1;
        }
        return 0;
    }

    vector<int> isAdjacent(int src, int des)
    {
        for (auto SetItr = graph[src].begin(); SetItr != graph[src].end(); SetItr++)
        {
            if ((*SetItr)[0] == des)
            {
                return (*SetItr);
            }
        }
        return {};
    }

    

};
