#include "linked_list.h"
#include <string>
template <typename nodeType>
Doublylist<nodeType>::Doublylist()
{
    head = new DNode<nodeType>;
    tail = new DNode<nodeType>;
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    this->n = 0;
}
template <typename nodeType>
Doublylist<nodeType>::Doublylist(const Doublylist &obj)
{
    head = new DNode<nodeType>;
    tail = new DNode<nodeType>;
    head->next = tail;
    head->prev = NULL;
    tail->prev = head;
    tail->next = NULL;
    this->n = 0;
    append(obj);
}
template <typename nodeType>
Doublylist<nodeType>::~Doublylist()
{
    while (!empty())
    {
        this->removeFront();
    }
}
template <typename nodeType>
void Doublylist<nodeType>::nodeSwap(DNode<nodeType> *firstNode, DNode<nodeType> *secNode) // Swap 2 nodes
{
    if (!empty() && firstNode->next != secNode && firstNode->prev != secNode)
    {
        DNode<nodeType> *tempNode1 = firstNode->next;
        DNode<nodeType> *tempNode2 = firstNode->prev;
        firstNode->next = secNode->next;
        secNode->prev->next = firstNode;
        secNode->next->prev = firstNode;
        firstNode->prev = secNode->prev;
        secNode->next = tempNode1;
        tempNode1->prev = secNode;
        secNode->prev = tempNode2;
        tempNode2->next = secNode;
    }
    else if (!empty() && firstNode->next == secNode)
    {
        firstNode->next = secNode->next;
        secNode->next->prev = firstNode;
        secNode->prev->prev->next = secNode;
        secNode->prev = firstNode->prev;
        firstNode->prev = secNode;
        secNode->next = firstNode;
    }
    else if (!empty() && firstNode->prev == secNode)
    {
        secNode->next = firstNode->next;
        firstNode->next->prev = secNode;
        firstNode->prev->prev->next = firstNode;
        firstNode->prev = secNode->prev;
        secNode->prev = firstNode;
        firstNode->next = secNode;
    }
}
template <typename nodeType>
DNode<nodeType> *Doublylist<nodeType>::
    findNode(const nodeType element) // find a specific node
{
    if (!empty())
    {
        DNode<nodeType> *temp = head->next;
        while (temp->data != element && temp != tail)
        {
            temp = temp->next;
        }
        if (temp->data == element)
        {
            return temp;
        }
    }
    return NULL;
}
template <typename nodeType>
bool Doublylist<nodeType>::empty()
{
    if (head->next == tail)
    {
        return 1;
    }
    return 0;
}
template <typename nodeType>
int Doublylist<nodeType>::size()
{
    return n;
}
template <typename nodeType>
void Doublylist<nodeType>::addFront(const nodeType &item)
{
    DNode<nodeType> *node = new DNode<nodeType>;
    node->data = item;
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    n++;
}
template <typename nodeType>
void Doublylist<nodeType>::removeFront()
{
    if (!empty())
    {
        DNode<nodeType> *temp = head->next;
        head->next->next->prev = head->next->prev;
        head->next = head->next->next;
        delete temp;
        n--;
    }
}
template <typename nodeType>
nodeType Doublylist<nodeType>::getFront()
{
    if (!empty())
    {
        return head->next->data;
    }
    exit(1);
}
template <typename nodeType>
void Doublylist<nodeType>::addBack(const nodeType &item)
{
    DNode<nodeType> *temp = new DNode<nodeType>;
    temp->data = item;
    temp->next = tail;
    temp->prev = tail->prev;
    tail->prev = temp;
    temp->prev->next = temp;
    n++;
}
template <typename nodeType>
nodeType Doublylist<nodeType>::getback()
{
    if (!empty())
    {
        return tail->prev->data;
    }
    exit(1);
}
template <typename nodeType>
void Doublylist<nodeType>::removeBack()
{
    if (!empty())
    {
        DNode<nodeType> *temp = tail->prev;
        tail->prev = temp->prev;
        tail->prev->next = temp->next;
        n--;
    }
}
template <typename nodeType>
void Doublylist<nodeType>::displayList()
{
    if (!empty())
    {
        DNode<nodeType> *temp = head->next;
        while (temp != tail)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}
template <typename nodeType>
void Doublylist<nodeType>::displayListInReverse()
{
    if (!empty())
    {
        DNode<nodeType> *temp = tail->prev;
        while (temp != head)
        {
            cout << temp->data << endl;
            temp = temp->prev;
        }
    }
}
template <typename nodeType>
bool Doublylist<nodeType>::find(const nodeType element)
{
    if (!empty())
    {
        DNode<nodeType> *temp = head->next;
        while (temp->data != element && temp != tail)
        {
            temp = temp->next;
        }
        if (temp->data == element)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    exit(1);
}
template <typename nodeType>
void Doublylist<nodeType>::insertAfter(const nodeType &element, const nodeType &item)
{
    if (!empty())
    {
        DNode<nodeType> *temp = findNode(element);
        DNode<nodeType> *node = new DNode<nodeType>;
        node->data = item;
        node->next = temp->next;
        temp->next->prev = node;
        node->prev = temp;
        temp->next = node;
        n++;
    }
}
template <typename nodeType>
void Doublylist<nodeType>::insertBefor(const nodeType &element, const nodeType &item)
{
    if (!empty())
    {
        DNode<nodeType> *temp = findNode(element);
        DNode<nodeType> *node = new DNode<nodeType>;
        node->data = item;
        node->next = temp;
        temp->prev->next = node;
        node->prev = temp->prev;
        temp->prev = node;
        n++;
    }
}
template <typename nodeType>
void Doublylist<nodeType>::removeAfter(const nodeType &element)
{
    if (!empty())
    {
        DNode<nodeType> *temp = findNode(element);
        DNode<nodeType> *deleteMe = temp->next;
        deleteMe->next->prev = temp;
        temp->next = deleteMe->next;
        delete deleteMe;
        n--;
    }
}
template <typename nodeType>
void Doublylist<nodeType>::removeBefor(const nodeType &element)
{
    if (!empty())
    {
        DNode<nodeType> *temp = findNode(element);
        DNode<nodeType> *deleteMe = temp->prev;
        deleteMe->prev->next = temp;
        temp->prev = deleteMe->prev;
        delete deleteMe;
        n--;
    }
}
template <typename nodeType>
bool Doublylist<nodeType>::isExist(const nodeType &element)
{
    return find(element);
}
template <typename nodeType>
void Doublylist<nodeType>::remove(const nodeType &element)
{
    if (!empty())
    {
        DNode<nodeType> *deleteMe = findNode(element);
        if (deleteMe)
        {
            deleteMe->next->prev = deleteMe->prev;
            deleteMe->prev->next = deleteMe->next;
            delete deleteMe;
            n--;
        }
    }
}
template <typename nodeType>
void Doublylist<nodeType>::removeAll()
{
    while (!empty())
    {
        removeFront();
    }
}
template <typename nodeType>
bool Doublylist<nodeType>::isPalindrome()
{
    DNode<nodeType> *last = tail->prev;
    DNode<nodeType> *first = head->next;
    while (last != first)
    {
        if (last->data != first->data)
            return false;
        last = last->prev;
        first = first->next;
    }
    return true;
}
template <typename nodeType>
void Doublylist<nodeType>::sort()
{
    if (!empty())
    {
        for (int i = 0; i < n - 1; i++)
        {
            bool helpSort = false;
            DNode<nodeType> *temp = head;
            for (int j = 0; j < n - i; j++)
            {
                if (temp->data > temp->next->data)
                {
                    nodeSwap(temp, temp->next);
                    helpSort = true;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (!helpSort)
                break;
        }
    }
}
template <typename nodeType>
void Doublylist<nodeType>::swap(const nodeType &element1, const nodeType &element2)
{
    nodeSwap(findNode(element1), findNode(element1));
}
template <typename nodeType>
void Doublylist<nodeType>::append(const Doublylist &obj)
{
    DNode<nodeType> *temp = obj.head->next;
    while (temp != obj.tail)
    {
        this->addFront(temp->data);
        temp = temp->next;
    }
}
template <typename nodeType>
Doublylist<nodeType> &Doublylist<nodeType>::operator=(const Doublylist<nodeType> &obj)
{
    removeAll();
    append(obj);
    return *this;
}
template <typename nodeType>
Doublylist<nodeType> Doublylist<nodeType>::divide()
{
    int counter = 0;
    Doublylist<nodeType> result;
    DNode<nodeType> *temp = head->next;
    while (counter < n / 2)
    {
        temp = temp->next;
        counter++;
    }
    while (temp != tail)
    {
        result.addFront(temp->data);
        temp = temp->next;
    }
    return result;
}
template <typename nodeType>
Doublylist<nodeType> Doublylist<nodeType>::divide(const nodeType item)
{
    DNode<nodeType> *temp = findNode(item);
    DNode<nodeType> *temp2 = head->next;
    Doublylist result;
    while (temp2 != temp)
    {
        temp2 = temp2->next;
    }
    while (temp2 != tail)
    {
        result.addFront(temp2->data);
        temp2 = temp2->next;
    }
    return result;
}
template <typename nodeType>
double Doublylist<nodeType>::AVG()
{
    DNode<nodeType> *temp = head->next;
    double sum = 0;
    while (temp != tail)
    {
        sum += temp->data;
        temp = temp->next;
    }
    return (sum / n);
}