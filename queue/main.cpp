#include "queue.h"
int main()
{
    queue<int> obj(2);
    obj.enqueue(1);
    obj.enqueue(2);
    cout<<obj.dequeue();
    cout<<obj.dequeue();

}