#include "circular-singly-list-functions.cpp"
#include <iostream>
using namespace std;
int main()
{
    circularSinglyList<int> obj;
    obj.add(10);
    obj.add(20);
    obj.add(30);
    obj.add(40);
    circularSinglyList<int> obj2;
    obj2 = obj;
    obj2.removeAll();
    obj2.displayList();
}