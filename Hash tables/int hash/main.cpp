#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
     myhash obj(7);
     obj.insert(6);
     obj.insert(7);
     obj.insert(8);
     obj.insert(9);
     obj.insert(10);
     obj.insert(12);
     obj.insert(15);
     obj.print();
     obj.remove(15);
     cout << "\n";
     obj.remove(16);
     obj.print();
     cout << "\n"
          << obj.find(10);
     cout << "\n"
          << obj.find(5);
}