#include <iostream>
using namespace std;
template <typename nodeType>
class SNode
{
public:
    nodeType data;
    SNode *next;
};
template <typename nodeType>
class SinglyList
{
private:
    SNode<nodeType> *head;
    int n;
    void nodeSwap(SNode<nodeType> *firstItem, SNode<nodeType> *secItem)
    {
        SNode<nodeType> *tempNode2 = secItem->next;
        SNode<nodeType> *tempNode = head;
        while (tempNode->next != firstItem)
        {
            tempNode = tempNode->next;
        }
        tempNode->next = secItem;
        secItem->next = firstItem;
        firstItem->next = tempNode2;
    }

public:
    SinglyList(const SinglyList &obj)
    {
        SNode<nodeType> *temp = obj.head;
        while (temp)
        {
            this->addBack(temp->data);
            temp = temp->next;
        }
    }
    SinglyList() : head(NULL), n(0) {}
    ~SinglyList()
    {
        while (!empty())
        {
            removeFront();
        }
    }
    bool empty() const
    {
        return head == NULL;
    }
    int size() const
    {
        return n;
    }
    void addFront(const nodeType &item)
    {
        SNode<nodeType> *m = new SNode<nodeType>;
        m->next = NULL;
        m->data = item;
        if (empty())
        {
            head = m;
            n++;
            return;
        }
        else
        {
            m->next = head;
            head = m;
            n++;
            return;
        }
    }
    bool removeFront()
    {
        if (empty())
        {
            return 0;
        }
        SNode<nodeType> *tempNode = head->next;
        delete head;
        head = tempNode;
        n--;
        return 1;
    }
    nodeType getFront() const
    {
        if (empty())
            exit(1);
        return head->data;
    }
    void displayList() const
    {
        SNode<nodeType> *p = head;
        while (p)
        {
            cout << p->data << endl;
            p = p->next;
        }
    }
    nodeType getBack() const
    {
        if (empty())
            exit(1);
        SNode<nodeType> *p = head;
        while (p && p->next)
        {
            p = p->next;
        }
        return p->data;
    }
    bool removeBack()
    {
        if (empty())
            return false;
        SNode<nodeType> *p, *q;
        p = q = head;
        while (p && p->next)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        delete p;
        n--;
        return true;
    }
    void addBack(const nodeType &item)
    {
        if (empty())
        {
            addFront(item);
            return;
        }
        SNode<nodeType> *m = new SNode<nodeType>;
        m->next = NULL;
        m->data = item;
        SNode<nodeType> *p = head;
        while (p && p->next)
        {
            p = p->next;
        }
        p->next = m;
        n++;
        return;
    }
    void insertAfter(SNode<nodeType> *p, const nodeType &item)
    {
        SNode<nodeType> *tempNode = new SNode<nodeType>;
        tempNode->data = item;
        tempNode->next = p->next;
        p->next = tempNode;
    }
    void insertBefor(SNode<nodeType> *p, const nodeType &item)
    {
        SNode<nodeType> *q = new SNode<nodeType>;
        q->data = item;
        q->next = p;
        SNode<nodeType> *m = head;
        while (m->next != p)
        {
            m = m->next;
        }
        m->next = m;
    }
    void removeAfter(SNode<nodeType> *p)
    {
        SNode<nodeType> *tempNode = p->next->next;
        delete p->next;
        p->next = tempNode;
        n--;
    }
    void removeBefor(SNode<nodeType> *p)
    {
        SNode<nodeType> *tempNext = p;
        SNode<nodeType> *tempNode = head;
        while (tempNode->next != p)
        {
            tempNode = tempNode->next;
        }
        delete tempNode;
        tempNode = tempNext;
        n--;
    }
    bool isExist(string element)
    {
        if (!empty())
        {
            SNode<nodeType> *tempNode = head;
            while (tempNode->data.getName() != element && tempNode->next)
            {
                tempNode = tempNode->next;
            }
            if (tempNode->data.getName() == element)
            {
                return true;
            }
        }
        return false;
    }
    SNode<nodeType> *find(string element)
    {
        if (!empty())
        {
            SNode<nodeType> *temoNode = head;
            while (temoNode->data.getName() != element && temoNode->next)
            {
                temoNode = temoNode->next;
            }
            if (temoNode->data.getName() == element)
            {
                return temoNode;
            }
        }
        return NULL;
    }
    bool remove(string item)
    {
        if (!empty())
        {
            SNode<nodeType> *tempNode = head;
            if (tempNode->data.getName() == item)
            {
                head = head->next;
                delete tempNode;
                return true;
            }
            else
            {
                while (tempNode->next->data.getName() != item && tempNode->next)
                {
                    tempNode = tempNode->next;
                }
                if (tempNode->next->data.getName() == item)
                {
                    SNode<nodeType> *node = tempNode->next;
                    tempNode->next = node->next;
                    delete node;
                    return true;
                }
            }
        }
        return false;
    }
    void sort()
    {
        if (!empty())
        {
            for (int i = 0; i < n - 1; i++)
            {
                bool helpSort = false;
                SNode<nodeType> *temp = head;
                for (int j = 0; j < n - i - 1; j++)
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
    void append(const SinglyList &obj)
    {
        SNode<nodeType> *temp = obj.head;
        while (temp)
        {
            this->addBack(temp->data);
            temp = temp->next;
        }
    }
    SinglyList divide()
    {
        SinglyList result;
        SNode<nodeType> *temp = head;
        int size = n / 2;
        int counter = 0;
        while (counter < size)
        {
            temp = temp->next;
            counter++;
        }
        while (temp)
        {
            result.addBack(temp->data);
            temp = temp->next;
        }
        return result;
    }
    SinglyList &operator=(const SinglyList &obj)
    {
        while (!empty())
        {
            removeFront();
        }
        SNode<nodeType> *temp = obj.head;
        while (temp)
        {
            this->addBack(temp->data);
            temp = temp->next;
        }
        return *this;
    }
    SinglyList divide(const nodeType item)
    {
        SNode<nodeType> *temp = this->find(item);
        SNode<nodeType> *temp2 = head;
        SinglyList result;
        while (temp2 != temp)
        {
            temp2 = temp2->next;
        }
        while (temp2)
        {
            result.addBack(temp2->data);
            temp2 = temp2->next;
        }
        return result;
    }
    double AVG()
    {
        SNode<nodeType> *temp = head;
        double sum = 0;
        while (temp)
        {
            sum += temp->data;
            temp = temp->next;
        }
        return (sum / n);
    }
    SinglyList &MakeREV(const SinglyList &obj)
    {
        while (!empty())
        {
            removeFront();
        }
        SNode<nodeType> *temp = obj.head;
        while (temp)
        {
            this->addFront(temp->data);
            temp = temp->next;
        }
        return *this;
    }
};
