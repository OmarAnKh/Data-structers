#include "doublyLink_functions.cpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    Doublylist<string> obj;
    obj.addBack("omar");
    obj.addBack("amjad");
    obj.addBack("aboood");
    obj.sort();
    obj.displayList();
}