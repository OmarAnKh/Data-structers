#include <iostream>
#include "vector_class.h"
using namespace std;

int main()
{
    myVector V1;
    V1.add(10);
    V1.add(20);
    V1.add(30);
    myVector V2;
    V2.add(40);
    V2.add(50);
    V2.add(60);
    cout << V1 + V2;
}