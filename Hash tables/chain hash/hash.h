#include <iostream>
#include <string>
#include "linked-list.h"
using namespace std;

class chainingHash
{
private:
    SinglyList<string> *hash;
    int capacity;
    int hashIt(const string &item)
    {
        int index = item[0] + item[1];
        return index % capacity;
    }

public:
    chainingHash(int cap = 5)
    {
        capacity = cap;
        hash = new SinglyList<string>[capacity];
    }
    chainingHash(const chainingHash &obj)
    {
        capacity = obj.capacity;
        hash = new SinglyList<string>[capacity];

        for (int i = 0; i < capacity; i++)
        {
            hash[i] = obj.hash[i];
        }
    }
    ~chainingHash()
    {
        capacity = 0;
        delete[] hash;
    }
    bool insert(const string &item)
    {
        int index = hashIt(item);
        hash[index].addBack(item);

        return 1;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {

            hash[i].displayList();
        }
    }
    bool remove(const string &item)
    {
        int index = hashIt(item);

        return hash[index].remove(item);

        return false;
    }
    bool find(const string &item)
    {
        int index = hashIt(item);

        if (hash[index].find(item))
        {
            return true;
        }
        return false;
    }
};