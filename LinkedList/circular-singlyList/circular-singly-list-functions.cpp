#include "circular-singly-list.h"
#include "string"
using namespace std;
template <typename nodeType>
circularSinglyList<nodeType>::circularSinglyList()
{
    cursor = NULL;
    n = 0;
}
template <typename nodeType>
circularSinglyList<nodeType>::circularSinglyList(const circularSinglyList &obj)
{
    cursor = NULL;
    n = 0;
    if (!obj.empty())
    {
        CSNode<nodeType> *temp = obj.cursor->next;
        while (temp != obj.cursor)
        {
            this->add(temp->data);
            temp = temp->next;
        }
        this->add(temp->data);
        temp = temp->next;
    }
    exit(1);
}
template <typename nodeType>
circularSinglyList<nodeType>::~circularSinglyList()
{
    removeAll();
}

template <typename nodeType>
bool circularSinglyList<nodeType>::empty() const
{
    return cursor == NULL;
}
template <typename nodeType>
int circularSinglyList<nodeType>::size()
{
    return n;
}
template <typename nodeType>
void circularSinglyList<nodeType>::add(const nodeType &item)
{
    CSNode<nodeType> *newNode = new CSNode<nodeType>;
    newNode->data = item;
    if (empty())
    {
        newNode->next = newNode;
        cursor = newNode;
        n++;
        return;
    }
    newNode->next = cursor->next;
    cursor->next = newNode;
    cursor = newNode;
    n++;
}
template <typename nodeType>
void circularSinglyList<nodeType>::addBack(const nodeType &item)
{
    CSNode<nodeType> *newNode = new CSNode<nodeType>;
    newNode->data = item;
    if (empty())
    {

        cursor = newNode;
        newNode->next = newNode;
        n++;
        return;
    }
    CSNode<nodeType> *temp = cursor;
    while (temp->next != cursor)
    {
        temp = temp->next;
    }
    newNode->next = cursor;
    temp->next = newNode;
}
template <typename nodeType>
nodeType circularSinglyList<nodeType>::front()
{
    if (!empty())
    {
        return cursor->next->data;
    }
    exit(1);
}
template <typename nodeType>
nodeType circularSinglyList<nodeType>::back()
{
    if (!empty())
    {
        CSNode<nodeType> *temp = cursor;
        while (temp->next != cursor)
        {
            temp = temp->next;
        }
        return temp->data;
    }
    exit(1);
}
template <typename nodeType>
void circularSinglyList<nodeType>::advance()
{
    if (!empty())
    {
        cursor = cursor->next;
    }
}

template <typename nodeType>
void circularSinglyList<nodeType>::remove()
{
    if (!empty())
    {
        CSNode<nodeType> *temp = cursor->next;
        cursor->next = cursor->next->next;
        delete temp;
    }
}
template <typename nodeType>
void circularSinglyList<nodeType>::displayList()
{
    if (!empty())
    {
        CSNode<nodeType> *temp = cursor->next;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        } while (temp != cursor->next);
    }
}
template <typename nodeType>
void circularSinglyList<nodeType>::removeAll()
{
    if (!empty())
    {
        CSNode<nodeType> *temp = cursor->next;
        while (temp != cursor)
        {
            remove();
            temp = cursor->next;
        }
        remove();
        
    }
}
template <typename nodeType>
void circularSinglyList<nodeType>::append(const circularSinglyList &obj)
{
    if (!(obj.empty() && empty()))
    {
        CSNode<nodeType> *temp = obj.cursor->next;
        do
        {
            this->add(temp->data);
            temp = temp->next;
        } while (temp != obj.cursor->next);
    }
}
template <typename nodeType>
circularSinglyList<nodeType> &circularSinglyList<nodeType>::operator=(const circularSinglyList &obj)
{
    if (!obj.empty())
    {
        this->removeAll();
        CSNode<nodeType> *temp = obj.cursor->next;
        while (temp != obj.cursor)
        {
            this->add(temp->data);
            temp = temp->next;
        }
        this->add(temp->data);
        temp = temp->next;
        return *this;
    }
    exit(1);
}