#include <iostream>
#include <string>
#include "linked-list.h"
#include "martyr.h"
using namespace std;
class stackLinkedList
{
private:
    SinglyList<martyr> stack;

public:
    stackLinkedList(const stackLinkedList &obj)
    {
        this->stack = obj.stack;
    }
    stackLinkedList()
    {
    }

    void addFront(const martyr &item)
    {
    }
    void insertMartyr(string n = "", string a = "", string e = "", string d = "", string g = "")
    {
        martyr obj;
        obj.setName(n);
        obj.setAge(a);
        obj.setEventLocation(e);
        obj.setdateOfDeath(d);
        obj.setGender(g);
        stack.addBack(obj);
    }
    void display()
    {
        stack.displayList();
    }
    stackLinkedList &operator=(const stackLinkedList &obj)
    {
        this->stack = obj.stack;
        return *this;
    }
    bool removeMartyr(string name)
    {
        if (stack.isExist(name))
        {
            return stack.remove(name);
        }
        return 0;
    }
    SinglyList<martyr> printAllInfoInREV()
    {
        SinglyList<martyr> stack2;
        SinglyList<martyr> stack3;
        stack3 = stack;
        while (stack3.size())
        {
            cout << stack3.getBack();
            stack3.removeBack();
        }

        return stack2;
    }
    void updateMartyr(string city,string oldName, string newName, string age)
    {
        SNode<martyr> *tempNode = stack.find(oldName);
        tempNode->data.setAge(age);
        tempNode->data.setEventLocation(city);
        tempNode->data.setName(newName);
    }
};