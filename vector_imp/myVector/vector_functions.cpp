#include "vector_class.h"
template <typename T>
myVector<T>::myVector(int temp)
{
    capacity = temp;
    a = new T[capacity];
    n = 0;
}
template <typename T>
myVector<T>::myVector(const myVector<T> &obj)
{
    a = new T[obj.capacity];
    this->capacity = obj.capacity;
    this->n = obj.n;
    for (int i = 0; i < this->n; i++)
    {
        this->a[i] = obj.a[i];
    }
}
template <typename T>
myVector<T>::~myVector()
{
    if (a != NULL)
    {
        delete[] a;
    }
}
template <typename T>
void myVector<T>::insert(T value)
{

    if (this->n >= this->capacity)
    {
        ReSize();
    }
    this->a[this->n] = value;
    n++;
}
template <typename T>
void myVector<T>::edit(int index, T value)
{
    if (index < this->n)
    {
        this->a[index] = value;
    }
}
template <typename T>
void myVector<T>::removeByindex(int index)
{
    if (index < this->n)
    {
        for (int i = 0; i < n; i++)
        {
            if (index == i)
            {
                for (int j = i; j < n - 1; j++)
                {
                    this->a[j] = this->a[j + 1];
                }
                n--;
            }
        }
    }
}
template <typename T>
T myVector<T>::get(int index)
{
    if (index >= n || index < 0)
    {
        exit(1);
    }
    return this->a[index];
}
template <typename T>
bool myVector<T>::empty()
{
    if (n == 0)
    {
        return 1;
    }
    else if (n > 0)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}
template <typename T>
void myVector<T>::clear()
{
    n = 0;
}
template <typename T>
T myVector<T>::back()
{
    return this->a[n - 1];
}
template <typename T>
void myVector<T>::pushback(T value)
{
    insert(value);
}
template <typename T>
void myVector<T>::popback()
{
    this->a[n] = 0;
    n--;
}
template <typename T>
int myVector<T>::findByValue(T value)
{
    for (int i = 0; i < n; i++)
    {
        if (abs(this->a[i] - value) <= 0.0000000000000000000001)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
T myVector<T>::findByindex(int index)
{
    if (index >= n || index < 0)
    {
        exit(1);
    }
    return this->a[index];
}
template <typename T>
void myVector<T>::removeByValue(T value)
{
    int flag = findByValue(value);
    if (flag != -1)
    {
        for (int i = flag; i < n - 1; i++)
        {
            this->a[i] = this->a[i + 1];
        }
        this->a[n] = 0;
        n--;
    }
}
template <typename T>
void myVector<T>::removeAllByValue(T value)
{
    int flag = findByValue(value);
    while (flag != -1)
    {
        for (int i = flag; i < n - 1; i++)
        {
            this->a[i] = this->a[i + 1];
        }
        this->a[n] = 0;
        n--;
        flag = findByValue(value);
    }
}
template <typename T>
myVector<T> myVector<T>::sort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] < a[j])
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    return *this;
}
template <typename T>
int myVector<T>::size()
{
    return n;
}
template <typename T>
T myVector<T>::operator[](int index)
{
    if (index >= n || index < 0)
    {
        exit(1);
    }
    return this->a[index];
}
template <typename T>
myVector<T> myVector<T>::operator+(const myVector<T> &obj)
{
    int cap = obj.capacity + this->capacity;
    myVector result(cap);
    result.n = this->n + obj.n;
    for (int i = 0; i < this->n; i++)
    {
        result.a[i] = this->a[i];
    }
    for (int i = this->n, j = 0; j < obj.n; i++, j++)
    {
        result.a[i] = obj.a[j];
    }
    return result;
}
template <typename T>
myVector<T> myVector<T>::operator=(const myVector<T> &obj)
{

    if (this->a != NULL)
    {
        delete[] this->a;
    }
    this->a = new T[obj.capacity];
    this->capacity = obj.capacity;
    this->n = obj.n;
    for (int i = 0; i < this->n; i++)
    {
        this->a[i] = obj.a[i];
    }
    return *this;
}
template <typename T>
bool myVector<T>::operator==(const myVector<T> &obj)
{
    if (this->n == obj.n)
    {
        int i;
        for (i = 0; i <= n && this->a[i] == obj.a[i]; i++)
            ;
        if (i == n)
        {
            return 1;
        }
    }
    return 0;
}
template <typename T>
string myVector<T>::toString()
{
    string str;
    for (int i = 0; i < n; i++)
    {
        str += to_string(a[i]);
    }
    return str;
}
