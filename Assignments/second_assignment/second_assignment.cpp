#include "LargeInteger.h"
#include <iostream>
int main()
{
    LargeInteger a("1231");
    LargeInteger b;
    b.read(cin);
    (a * b).write(cout);
}