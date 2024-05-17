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
ArrayStack<stackType>::ArrayStack(const ArrayStack<stackType> &obj)
{
    cap = obj.cap;
    size = obj.size;
    stack = new stackType[cap];
    for (int i = 0; i < size; i++)
    {
        stack[i] = obj.stack[i];
    }
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
template <typename stackType>
bool ArrayStack<stackType>::empty()
{
    return size == 0;
}
template <typename stackType>
bool ArrayStack<stackType>::full()
{
    return size = > cap;
}
template <typename stackType>
int ArrayStack<stackType>::size()
{
    return size;
}

template <typename stackType>
stackType ArrayStack<stackType>::top()
{
    if (!empty())
    {
        return stack[size - 1];
    }
    else
    {
        exit(1);
    }
}
template <typename stackType>
ArrayStack<stackType> &ArrayStack<stackType>::operator=(const ArrayStack<stackType> &obj)
{
    delete[] stack;
    cap = obj.cap;
    size = obj.size;
    stack = new stackType[cap];
    for (int i = 0; i < size; i++)
    {
        stack[i] = obj.stack[i];
    }
}
template <typename stackType>
void ArrayStack<stackType>::cat(const ArrayStack<stackType> &obj)
{
    stack temp(obj.siz)
}
