#include <iostream>
#include "binarySearchTree.h"
using namespace std;

int main()
{
    binarySearchTree<int> obj;
    obj.insert(2);
    obj.insert(3);
    obj.insert(4);
    obj.insert(1);
    obj.insert(-2);
    obj.insert(0);
    obj.print(2, "NRL");
}