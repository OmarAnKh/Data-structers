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
    ~ArrayStack();
    void push(const stackType&item);
    void pop();
};
// push
// pop
// top
// empty
// size
// constructors
// =
// destructor