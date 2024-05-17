#include <iostream>
#include <string>
#include "stack.h"
#include "vector.h"
#include <fstream>
using namespace std;
template <typename nodeType>
class CDnode
{
public:
    CDnode<nodeType> *next;
    CDnode<nodeType> *prev;
    nodeType cityName;
    myVector martyrVector;
    stackLinkedList martyrStack;
};
template <typename nodeType>
class CircularDoubleLinkedList
{
private:
    CDnode<nodeType> *cursor;
    int number;

public:
    CircularDoubleLinkedList()
    {
        cursor = new CDnode<nodeType>;
        number = 0;
        cursor->next = cursor;
        cursor->prev = cursor;
    }
    ~CircularDoubleLinkedList()
    {
    }
    bool empty()
    {
        if (number == 0)
        {
            return 1;
        }
        return 0;
    }

    bool addNewCity(string city)
    {
        city = tolower(city);
        if (!find(city))
        {
            CDnode<nodeType> *temp = cursor;
            CDnode<nodeType> *newNode = new CDnode<nodeType>;
            newNode->cityName = city;
            while (temp->next != cursor && city > temp->cityName)
            {
                temp = temp->next;
            }
            temp->next->prev = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            number++;
            return 1;
        }
        return 0;
    }
    void add(string n, string a, string city, string e, string d, string g)
    {
        city = tolower(city);
        n = tolower(n);
        if (!empty() && !find(city))
        {
            CDnode<nodeType> *temp = cursor;
            CDnode<nodeType> *newNode = new CDnode<nodeType>;
            newNode->cityName = city;

            newNode->martyrStack.insertMartyr(n, a, city, d, g);
            newNode->martyrVector.insertMartyr(n, a, city, d, g);
            while (temp->next != cursor && city > temp->cityName)
            {
                temp = temp->next;
            }
            if (temp->cityName > newNode->cityName)
            {
                nodeType temp1 = temp->cityName;
                stackLinkedList temp2 = temp->martyrStack;
                myVector temp3 = temp->martyrVector;
                temp->cityName = newNode->cityName;
                newNode->cityName = temp1;
                temp->martyrStack = newNode->martyrStack;
                temp->martyrVector = newNode->martyrVector;
                newNode->cityName = temp1;
                newNode->martyrStack = temp2;
                newNode->martyrVector = temp3;
            }

            temp->next->prev = newNode;
            newNode->next = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
            number++;

            return;
        }
        else if (find(city))
        {
            CDnode<nodeType> *temp = findNode(city);
            temp->martyrStack.insertMartyr(n, a, city, d, g);
            temp->martyrVector.insertMartyr(n, a, city, d, g);
            return;
        }
        cursor->cityName = city;
        cursor->martyrStack.insertMartyr(n, a, e, d, g);
        cursor->martyrVector.insertMartyr(n, a, e, d, g);
        number++;
    }

    bool find(const nodeType item)
    {
        CDnode<nodeType> *temp = cursor;
        while (item != temp->cityName && temp->next != cursor)
        {
            temp = temp->next;
        }
        if (temp->cityName == item)
        {
            return 1;
        }
        return 0;
    }

    CDnode<nodeType> *findNode(string item)
    {
        CDnode<nodeType> *temp = cursor;
        while (item != temp->cityName && temp->next != cursor)
        {
            temp = temp->next;
        }
        if (temp->cityName == item)
        {
            return temp;
        }
        else if (cursor->cityName == item)
        {
            return cursor;
        }
        return NULL;
    }
    string tolower(string city)
    {
        for (int i = 0; i < city.length(); i++)
        {
            if (city[i] >= 'A' && city[i] <= 'Z')
            {
                city[i] = city[i] + 32;
            }
        }
        return city;
    }
    void display()
    {
        CDnode<nodeType> *temp = cursor;
        while (temp->next != cursor)
        {
            cout << temp->cityName << endl;
            temp = temp->next;
        }
        cout << temp->cityName << endl;
    }

    bool updateCityName(string newCity, string oldCity)
    {
        newCity = tolower(newCity);
        oldCity = tolower(oldCity);
        if (find(oldCity) && !find(newCity) && oldCity != cursor->cityName)
        {
            CDnode<string> *newNode = findNode(oldCity);
            newNode->cityName = newCity;
            CDnode<nodeType> *temp = cursor;
            while (temp->next != cursor && newCity > temp->cityName)
            {
                temp = temp->next;
            }
            temp = temp->next;
            if (temp->cityName > newNode->cityName)
            {
                nodeType temp1 = temp->cityName;
                stackLinkedList temp2 = temp->martyrStack;
                myVector temp3 = temp->martyrVector;
                temp->cityName = newNode->cityName;
                newNode->cityName = temp1;
                temp->martyrStack = newNode->martyrStack;
                temp->martyrVector = newNode->martyrVector;
                newNode->cityName = temp1;
                newNode->martyrStack = temp2;
                newNode->martyrVector = temp3;
            }
            sort();
            return 1;
        }

        return 0;
    }
    void nodeSwap(CDnode<string> *firstNode, CDnode<string> *secNode)
    {

        if (!empty() && firstNode->next != secNode && firstNode->prev != secNode)
        {
            CDnode<nodeType> *tempNode1 = firstNode->next;
            CDnode<nodeType> *tempNode2 = firstNode->prev;
            firstNode->next = secNode->next;
            secNode->prev->next = firstNode;
            secNode->next->prev = firstNode;
            firstNode->prev = secNode->prev;
            secNode->next = tempNode1;
            tempNode1->prev = secNode;
            secNode->prev = tempNode2;
            tempNode2->next = secNode;
        }
        else if (!empty() && firstNode->next == secNode)
        {
            firstNode->next = secNode->next;
            secNode->next->prev = firstNode;
            secNode->prev->prev->next = secNode;
            secNode->prev = firstNode->prev;
            firstNode->prev = secNode;
            secNode->next = firstNode;
        }
        else if (!empty() && firstNode->prev == secNode)
        {
            secNode->next = firstNode->next;
            firstNode->next->prev = secNode;
            firstNode->prev->prev->next = firstNode;
            firstNode->prev = secNode->prev;
            secNode->prev = firstNode;
            firstNode->next = secNode;
        }
    }
    void sort()
    {
        if (!empty())
        {
            for (int i = 0; i < number - 1; i++)
            {
                bool helpSort = false;
                CDnode<nodeType> *temp = cursor;
                for (int j = 0; j < number - i; j++)
                {
                    if (temp->cityName > temp->next->cityName)
                    {
                        nodeSwap(temp, temp->next);
                        helpSort = true;
                    }
                    else
                    {
                        temp = temp->next;
                    }
                }
                if (!helpSort)
                    break;
            }
        }
    }
    bool deleteCity(string city)
    {
        city = tolower(city);
        if (find(city))
        {
            CDnode<nodeType> *deleteMe = findNode(city);

            if (deleteMe == cursor)
            {

                cursor = cursor->next;
            }

            deleteMe->next->prev = deleteMe->prev;
            deleteMe->prev->next = deleteMe->next;
            delete deleteMe;
            number--;

            return true;
        }

        return false;
    }
    bool removeMartyr(string name, string city)
    {
        city = tolower(city);
        name = tolower(name);
        CDnode<string> *temp = findNode(city);
        if (temp != NULL)
        {
            int flag = temp->martyrStack.removeMartyr(name);
            int flag2 = temp->martyrVector.removeMartyr(name);
            if (flag2 && flag)
            {
                return 1;
            }
        }
        return 0;
    }
    bool displayInfo(string name, string city)
    {
        city = tolower(city);
        name = tolower(name);
        CDnode<string> *temp = findNode(city);
        if (temp != NULL)
        {
            return temp->martyrVector.displayInfo(name);
        }
        return 0;
    }
    int printAmount(string city)
    {
        city = tolower(city);
        CDnode<string> *temp = findNode(city);
        if (temp != NULL)
        {
            return temp->martyrVector.vectorSize();
        }
        return -1;
    }
    bool printInfoForCity(string city)
    {
        city = tolower(city);
        CDnode<string> *temp = findNode(city);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        if (temp != NULL)
        {
            temp->martyrVector.printAllInfo();
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            return 1;
        }

        return 0;
    }
    bool printInfoForCityInREV(string city)
    {
        city = tolower(city);
        CDnode<string> *temp = findNode(city);
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        if (temp != NULL)
        {
            temp->martyrStack.printAllInfoInREV();
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            return 1;
        }

        return 0;
    }
    int minimumNumber1()
    {
        CDnode<string> *temp = cursor;
        int count = temp->martyrVector.vectorSize();
        while (temp->next != cursor)
        {
            if (temp->martyrVector.vectorSize() < count)
            {
                count = temp->martyrVector.vectorSize();
            }
            temp = temp->next;
        }
        return count;
    }
    void saveData(string fileName)
    {
        CDnode<string> *temp = cursor;
        ofstream outputFile;

        outputFile.open(fileName);
        if (!outputFile.is_open())
        {
            cout << "Error opening the file!" << endl;
            exit(1);
        }
        outputFile << "Name"
                   << ","
                   << "Age"
                   << ","
                   << "Event location - District"
                   << ","
                   << "Date of death"
                   << ","
                   << "Gender" << endl;
        while (temp->next != cursor)
        {
            martyr *data = temp->martyrVector.getData();
            for (int i = 0; i < temp->martyrVector.vectorSize(); i++)
            {
                outputFile << data[i].getName() << "," << data[i].getAge() << "," << data[i].getEventLocation() << "," << data[i].getDateOfDeath() << "," << data[i].getGender() << endl;
            }
            temp = temp->next;
        }
        outputFile.close();
    }

    void updateMartyr(string oldcity, string newCity, string oldName, string newName, string age)
    {
        oldcity = tolower(oldcity);
        oldName = tolower(oldName);
        newName = tolower(newName);
        CDnode<string> *temp = findNode(oldcity);
        if (temp != NULL)
        {
            temp->martyrVector.updateMartyr(newCity, oldName, newName, age);
            temp->martyrStack.updateMartyr(newCity, oldName, newName, age);
        }
    }
};