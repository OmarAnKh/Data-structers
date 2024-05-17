#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Vertex
{
public:
    int value;

public:
    Vertex()
    {
        value = 0;
    }
};

class Edges
{
private:
    Vertex **graph;
    int size;
    int cap;

public:
    Edges(int c)
    {
        cap = c;
        size = 0;
        graph = new Vertex *[cap];
        for (int i = 0; i < cap; i++)
        {
            graph[i] = new Vertex[2];
        }
    }
    void insert(int start, int end)
    {
        if (size >= cap)
        {
            cout << "you have reach your limit ";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            if (graph[size][0].value == start && graph[size][1].value == end)
            {
                return;
            }
            if (graph[size][0].value == end && graph[size][1].value == start)
            {
                return;
            }
        }

        graph[size][0].value = start;
        graph[size][1].value = end;
        size++;
    }
    vector<int> getAllChilds(int value)
    {
        vector<int> childs;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (graph[i][j].value == value)
                {
                    if (j == 0)
                    {
                        childs.push_back(graph[i][1].value);
                    }
                    else
                    {
                        childs.push_back(graph[i][0].value);
                    }
                }
            }
        }
        return childs;
    }
    vector<int> breadthSearch(int start)
    {
        vector<int> result;
        vector<bool> visited(cap, false);

        queue<int> queue;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty())
        {
            int current = queue.front();
            queue.pop();
            result.push_back(current);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    if (graph[i][j].value == current)
                    {
                        int neighbor = (j == 0) ? graph[i][1].value : graph[i][0].value;
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            queue.push(neighbor);
                        }
                    }
                }
            }
        }
        return result;
    }
    void printGraph()
    {
        for (int i = 0; i < cap; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cout << graph[i][j].value << "\t";
            }
            cout << endl;
        }
    }
};