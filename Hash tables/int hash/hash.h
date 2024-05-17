#include <iostream>
using namespace std;
class myhash
{
private:
    int *valueArray;
    bool *reservationsArray;
    int capacity;

public:
    myhash(int cap = 5)
    {
        capacity = cap;
        valueArray = new int[cap];
        reservationsArray = new bool[cap]{0};
    }
    ~myhash()
    {
        delete[] valueArray;
        delete[] reservationsArray;
        capacity = 0;
    }
    int hashit(int item)
    {
        return (item + 2) % capacity;
    }
    bool insert(int item)
    {
        int index = hashit(item);
        if (reservationsArray[index] == 0)
        {
            reservationsArray[index] = 1;
            valueArray[index] = item;
            return 1;
        }
        for (int i = index + 1; i != index; i = (i + 1) % capacity)
        {
            if (reservationsArray[i] == 0)
            {
                reservationsArray[i] = 1;
                valueArray[i] = item;
                return 1;
            }
        }
        return 0;
    }

    bool remove(int item)
    {

        int index = hashit(item);
        if (reservationsArray[index] == 1)
        {
            if (valueArray[index] == item)
            {
                reservationsArray[index] = 0;
                return 1;
            }
        }
        for (int i = index + 1; i < capacity; i++)
        {
            if (reservationsArray[i] == 1)
            {
                if (valueArray[i] == item)
                {
                    reservationsArray[i] = 0;
                    return 1;
                }
            }
        }
        return 0;
    }
    void print()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (reservationsArray[i] != 0)
            {
                cout << valueArray[i];
            }
        }
    }
    int find(int item)
    {
        int index = hashit(item);
        if (reservationsArray[index] == 1)
        {
            if (valueArray[index] == item)
            {
                return item;
            }
        }
        for (int i = index + 1; i < capacity; i++)
        {
            if (reservationsArray[i] == 1)
            {
                if (valueArray[i] == item)
                {
                    return item;
                }
            }
        }
        return 0;
    }
};