#include "linked-list.h"
#include <iostream>
using namespace std;
int main()
{
    SinglyList<int> obj;
    obj.addFront(50);
    obj.addFront(30);
    obj.addFront(20);
    obj.addFront(40);
    obj.addFront(10);
    obj.sort();
    SinglyList<int> obj2 = obj.divide(30);
    obj2.displayList();
}