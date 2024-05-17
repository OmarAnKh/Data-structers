#include "linked-list.h"
#include <iostream>
using namespace std;
int main()
{
    SinglyList<int> obj;
    obj.addFront(50);
    obj.remove(50);
    obj.addFront(50);
    obj.displayList();
}