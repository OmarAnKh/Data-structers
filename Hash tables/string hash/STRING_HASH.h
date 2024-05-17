#include <iostream>
using namespace std;
class Bucket
{
public:
    string data;
    int status;
    Bucket()
    {
        status = 0;
    }
};

class MyStringHash
{
    Bucket *hash;
    int capacity;
    int hashIt(const string &item)
    {
        int index = item[0] + item[1];
        return index % capacity;
    }

public:
    MyStringHash(int cap = 5)
    {
        capacity = cap;
        hash = new Bucket[capacity];
    }

    MyStringHash(const MyStringHash &obj)
    {
        capacity = obj.capacity;

        hash = new Bucket[capacity];
        for (int i = 0; i < capacity; i++)
        {
            hash[i].data = obj.hash[i].data;
            hash[i].status = obj.hash[i].status;
        }
    }
    ~MyStringHash()
    {
        capacity = 0;
        delete[] hash;
    }
    int insert(const string &item)
    {
        int index = hashIt(item);
        if (hash[index].status == 0)
        {
            hash[index].data = item;
            hash[index].status = 1;
            return 1;
        }

        for (int i = index + 1; i != index; i = (i + 1) % capacity)
        {
            if (hash[i].status == 0)
            {
                hash[i].data = item;
                hash[i].status = 1;
                return 1;
            }
        }
        return 0;
    }
    int remove(const string &item)
    {
        int index = hashIt(item);
        if (hash[index].status == 1)
        {
            if (hash[index].data == item)
            {
                hash[index].data = "nothing is here";
                hash[index].status = 0;
                return 1;
            }
        }

        for (int i = index + 1; i != index; i = (i + 1) % capacity)
        {
            if (hash[i].status == 1)
            {
                if (hash[i].data == item)
                {
                    hash[i].data = "nothing is here";
                    hash[i].status = 0;
                    return 1;
                }
            }
        }
        return 0;
    }
    string *return_data()
    {
        int size = 0;
        for (int i = 0; i < capacity; i++)
        {
            if (hash[i].status == 1)
            {
                size++;
            }
        }

        string *newData = new string[size]{""};
        for (int i = 0; i < capacity; i++)
        {
            if (hash[i].status == 1)
            {
                newData[i] = hash[i].data;
            }
        }
        return newData;
    }
    bool find(const string &item)
    {
        int index = hashIt(item);
        if (hash[index].status == 1 && hash[index].data == item)
        {
            return true;
        }
        for (int i = index + 1; i != index; i = (1 + i) % capacity)
        {
            if (hash[i].status == 1 && hash[i].data == item)
            {
                return true;
            }
        }
        return false;
    }
};