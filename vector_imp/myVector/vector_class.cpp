#include <iostream>
#include <string>
#include "vector_class.h"
using namespace std;

int main()
{
    myVector<string> V1;
    V1.insert("a");
    V1.insert("b");
    V1.insert("c");
    V1.insert("e");
    V1.insert("a");
    V1.insert("l");
    V1.insert("p");
    myVector<string> V2(V1);
    cout << V1.sort();
}
