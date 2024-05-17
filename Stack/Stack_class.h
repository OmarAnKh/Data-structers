#include "iostream"

using namespace std;
template <typename stackType>
class ArrayStack
{
private:
    stackType *stack;
    int n;
    int cap;

public:
public:
    ArrayStack(int c = 5);
    ArrayStack(const ArrayStack<stackType> &obj);
    ~ArrayStack();
    void push(const stackType &item);
    void pop();
    stackType top();
    bool empty();
    bool full();
    int size();
    ArrayStack<stackType> &operator=(const ArrayStack<stackType> &obj);
    void cat(const ArrayStack<stackType> &obj)
    {
    }

};

// cat
// cin
// cout
