#include "iostream"
#include "Stack_class.h"
template <typename stackType>
ArrayStack<stackType>::ArrayStack(int c = 5)
{
    cap = c;
    size = 0;
    stack = new stackType[cap];
}

template <typename stackType>
ArrayStack<stackType>::~ArrayStack()
{
    if (stack)
        delete[] stack;
    stack = NULL;
}
template <typename stackType>
void ArrayStack<stackType>::push(const stackType &item)
{
    if (size >= cap)
        return;
    stack[size] = item;
    size++;
}
template <typename stackType>
void ArrayStack<stackType>::pop()
{
    size--;
    
}