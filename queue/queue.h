#include <iostream>
#include <string>
using namespace std;
template <typename queueType>
class queue
{
private:
    queueType *array;
    int size;
    int place;
    int capacity;

public:
    queue(int s = 5)
    {
        capacity = s;
        array = new queueType[size];
        place = 0;
        size = 0;
    }

    ~queue()
    {
        if (array != NULL)
        {
            delete[] array;
        }
        capacity = 0;
        size = 0;
        place = 0;
    }
    bool enqueue(queueType item)
    {
        if (size < capacity)
        {
            array[size] = item;
            size++;
            return 1;
        }
        return 0;
    }
    int dequeue()
    {
        if (place < size)
        {
            int temp = array[place];
            place++;
            return temp;
        }
        cout << "an error occurred";
        exit(1);
    }
    int front()
    {
        return array[place];
    }
    int arryaSize()
    {
        return size;
    }
    bool empty()
    {
        return size == 0;
    }
};