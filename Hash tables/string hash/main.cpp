#include <iostream>

#include "STRING_HASH.h"
using namespace std;

int main()
{

     MyStringHash obj(5);
     obj.insert("6");
     obj.insert("7");
     obj.insert("8");
     obj.insert("9");
     obj.insert("10");
     obj.insert("12");
     cout << obj.find("12");
     string *data = new string[5];
     data = obj.return_data();
     for (int i = 0; i < 5; i++)
     {
          cout << data[i] << endl;
     }
}