#include <iostream>
#include "hash.h"

using namespace std;

int main()
{
     chainingHash obj(5);
     obj.insert("C");
     obj.insert("A");
     obj.insert("B");
     obj.insert("D");
     obj.insert("E");
     obj.insert("A");
     obj.remove("B");
     cout << obj.find("B") << endl;
     cout << obj.find("A") << endl;
     obj.print();
}