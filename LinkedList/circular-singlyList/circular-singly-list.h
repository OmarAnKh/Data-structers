#include <iostream>
#include <string>
using namespace std;
template <typename nodeType>
class CSNode
{
public:
    nodeType data;
    CSNode<nodeType> *next;
};
template <typename nodeType>
class circularSinglyList
{
private:
    CSNode<nodeType> *cursor;
    int n;

public:
    circularSinglyList();
    circularSinglyList(const circularSinglyList &obj);
    ~circularSinglyList();
    int size();
    bool empty() const;
    void add(const nodeType &item);
    nodeType front();
    void addBack(const nodeType &item);
    nodeType back();
    void advance();
    void remove();
    void removeAll();
    void append(const circularSinglyList &obj);
    void displayList();
    circularSinglyList<nodeType> &operator=(const circularSinglyList &obj);
};
// cout