#include "circular-double-linked-list.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
vector<string> splitString(const string &inputString, char delimiter)
{
    vector<string> result;
    stringstream ss(inputString);
    string token;
    while (getline(ss, token, delimiter))
    {
        result.push_back(token);
    }
    return result;
}
bool insertAnewLocation(CircularDoubleLinkedList<string> &obj, string city)
{
    if (obj.addNewCity(city))
    {
        return 1;
    }
    return 0;
}
bool updateCity(CircularDoubleLinkedList<string> &obj, string newCity, string oldCity)
{
    if (obj.updateCityName(newCity, oldCity))
    {
        return 1;
    }
    return 0;
}
bool deleteCity(CircularDoubleLinkedList<string> &obj, string newCity)
{
    if (obj.deleteCity(newCity))
    {
        return 1;
    }
    return 0;
}
void addMartyr(CircularDoubleLinkedList<string> &obj, string n, string a, string e, string d, string g)
{
    obj.add(n, a, e, e, d, g);
}
bool removeMartyr(CircularDoubleLinkedList<string> &obj, string n, string city)
{
    return obj.removeMartyr(n, city);
}
bool displayInfo(CircularDoubleLinkedList<string> &obj, string n, string city)
{
    return obj.displayInfo(n, city);
}
int printAmount(CircularDoubleLinkedList<string> &obj, string city)
{
    return obj.printAmount(city);
}
bool printInfoForCity(CircularDoubleLinkedList<string> &obj, string city)
{
    return obj.printInfoForCity(city);
}
bool printInfoForCityInREV(CircularDoubleLinkedList<string> &obj, string city)
{
    return obj.printInfoForCityInREV(city);
}
int minimumNumber(CircularDoubleLinkedList<string> &obj)
{
    return obj.minimumNumber1();
}
void saveToFile(CircularDoubleLinkedList<string> &obj, string fileName)
{
    obj.saveData(fileName);
}
void updateMartyr(CircularDoubleLinkedList<string> &obj, string city, string oldName, string age, string newName, string newCity)
{
    obj.updateMartyr(city, newCity, oldName, newName, age);
}
int main()
{
    CircularDoubleLinkedList<string> obj;

    ifstream martyrFile("data.csv");
    string myText;
    getline(martyrFile, myText);
    while (getline(martyrFile, myText))
    {
        vector<string>
            data = splitString(myText, ',');
        obj.add(data[0], data[1], data[2], data[2], data[3], data[4]);
    }

    int choice;
    cout << "choose one of the next, please" << endl;
    cout << "0-To end." << endl;
    cout << "1-insert new location record." << endl;
    cout << "2-update an existing location." << endl;
    cout << "3-delete an existing location." << endl;
    cout << "4-search for a location record." << endl;
    cin >> choice;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    string newCity = "";
    string oldCity = "";
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            cout << "enter the new city name" << endl;
            cin.ignore();
            getline(cin, newCity);
            insertAnewLocation(obj, newCity);
            break;
        case 2:
            cout << "enter the new city name" << endl;
            cin.ignore();
            getline(cin, newCity);
            cout << "enter the old city name" << endl;
            getline(cin, oldCity);
            updateCity(obj, newCity, oldCity);
            obj.display();
            break;
        case 3:
            cout << "enter the city name you want to delete it" << endl;
            cin.ignore();
            getline(cin, newCity);
            deleteCity(obj, newCity);
            break;
        case 4:
            cout << "please choose A), B) or C)" << endl;
            cout << "A) Martyrs' Menu" << endl;
            cout << "B) Statistics Report" << endl;
            cout << "C) To End" << endl;
            cin >> newCity;
            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            while (newCity == "A" || newCity == "a" || newCity == "B" || newCity == "b")
            {

                if (newCity == "A" || newCity == "a")
                {
                    int choice2;
                    cout << "choose one of the next, please" << endl;
                    cout << "0-To end." << endl;
                    cout << "1-Insert a new martyr record." << endl;
                    cout << "2-Delete a martyr record." << endl;
                    cout << "3-Search for a martyr by name and display his/her information." << endl;
                    cin >> choice2;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    if (choice2 == 0)
                    {
                        cout << "please choose A), B) or C)" << endl;
                        cout << "A) Martyrs' Menu" << endl;
                        cout << "B) Statistics Report" << endl;
                        cout << "C) To End" << endl;
                        cin >> newCity;
                        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    while (choice2 != 0)
                    {
                        int choice;
                        string n = "";
                        string a = "";
                        string e = "";
                        string d = "";
                        string g = "";
                        switch (choice2)
                        {
                        case 1:
                            cout << "enter the name of the Martyr" << endl;
                            cin.ignore();
                            getline(cin, n);
                            cout << "enter the age of the Martyr" << endl;
                            getline(cin, a);
                            cout << "enter the city of the Martyr" << endl;
                            getline(cin, e);
                            cout << "enter the Date of death of the Martyr" << endl;
                            getline(cin, d);
                            cout << "enter the gender of the Martyr" << endl;
                            getline(cin, g);
                            addMartyr(obj, n, a, e, d, g);
                            break;
                        case 2:
                            cout << "please insert the city" << endl;
                            cin.ignore();
                            getline(cin, e);
                            cout << "now insert the name" << endl;
                            getline(cin, n);

                            if (!removeMartyr(obj, n, e))
                            {
                                cout << "something went wrong " << endl;
                            }

                            break;
                        case 3:
                            cout << "please insert the city" << endl;
                            cin.ignore();
                            getline(cin, e);
                            cout << "now insert the name" << endl;
                            getline(cin, n);
                            if (!displayInfo(obj, n, e))
                            {
                                cout << "the data you have entred was wrong " << endl;
                            }
                            break;
                        case 4:
                            cout << "enter the name of the Martyr" << endl;
                            cin.ignore();
                            getline(cin, n);
                            cout << "enter the city of the Martyr" << endl;
                            getline(cin, g);
                            cout << "enter the new age of the Martyr" << endl;
                            getline(cin, e);
                            cout << "enter the new name of the Martyr" << endl;
                            getline(cin, a);
                            cout << "enter the new city of the Martyr" << endl;
                            getline(cin, d);
                            updateMartyr(obj, g, n, e, a, d);
                            break;
                        }
                        if (choice2 != 0)
                        {
                            cout << "choose one of the next, please" << endl;
                            cout << "0-To end." << endl;
                            cout << "1-Insert a new martyr record." << endl;
                            cout << "2-Delete a martyr record." << endl;
                            cout << "3-Search for a martyr by name and display his/her information." << endl;
                            cin >> choice2;
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }

                        if (choice2 == 0)
                        {
                            cout << "please choose A), B) or C)" << endl;
                            cout << "A) Martyrs' Menu" << endl;
                            cout << "B) Statistics Report" << endl;
                            cout << "C) To End" << endl;
                            cin >> newCity;
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                    }
                }
                else if (newCity == "B" || newCity == "b")
                {
                    int choice2 = 1;
                    cout << "choose one of the next, please" << endl;
                    cout << "0-To end." << endl;
                    cout << "1-Number of martyrs in a city." << endl;
                    cout << "2-Print all the martyrs info in a city." << endl;
                    cout << "3-Print all the martyrs info from the newest to the oldest in a city." << endl;
                    cout << "4-Check the minimum number of martyrs";
                    cin >> choice2;
                    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    if (choice2 == 0)
                    {
                        cout << "please choose A), B) or C)" << endl;
                        cout << "A) Martyrs' Menu" << endl;
                        cout << "B) Statistics Report" << endl;
                        cout << "C) To End" << endl;
                        cin >> newCity;
                        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                    }
                    while (choice2 != 0)
                    {
                        string city = "";
                        switch (choice2)
                        {
                        case 1:
                        {
                            cout << "please insert the city" << endl;
                            cin.ignore();
                            getline(cin, city);
                            int size = printAmount(obj, city);
                            if (size == -1)
                            {
                                cout << "something went wrong" << endl;
                            }
                            else
                            {
                                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << "there is " << size << " martyrs in this city" << endl;
                                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            }
                            break;
                        }
                        case 2:
                        {
                            cout << "please insert the city" << endl;
                            cin.ignore();
                            getline(cin, city);
                            if (!printInfoForCity(obj, city))
                            {
                                cout << "something went wrong";
                            }
                            break;
                        }
                        case 3:
                        {
                            cout << "please insert the city" << endl;
                            cin.ignore();
                            getline(cin, city);
                            if (!printInfoForCityInREV(obj, city))
                            {
                                cout << "something went wrong";
                            }
                            break;
                        }
                        case 4:
                        {
                            int min = minimumNumber(obj);
                            if (!min)
                            {
                                cout << "something went wrong" << endl;
                            }
                            else
                            {
                                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                                cout << min << endl;
                                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                            }
                            break;
                        }
                        default:
                            break;
                        }
                        if (choice2 != 0)
                        {
                            cout << "choose one of the next, please" << endl;
                            cout << "0-To end." << endl;
                            cout << "1-Number of martyrs in a city." << endl;
                            cout << "2-Print all the martyrs info in a city." << endl;
                            cout << "3-Print all the martyrs info from the newest to the oldest in a city." << endl;
                            cout << "4-Check the minimum number of martyrs";
                            cin >> choice2;
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }

                        if (choice2 == 0)
                        {
                            cout << "please choose A), B) or C)" << endl;
                            cout << "A) Martyrs' Menu" << endl;
                            cout << "B) Statistics Report" << endl;
                            cout << "C) To End" << endl;
                            cin >> newCity;
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                        }
                    }
                }
            }
            break;
        default:
            cout << "pleas choose one of the above numbers" << endl;
            break;
        }
        cout << "choose one of the next, please" << endl;
        cout << "0-To end." << endl;
        cout << "1-insert new location record." << endl;
        cout << "2-update an existing location." << endl;
        cout << "3-delete an existing location." << endl;
        cout << "4-search for a location record." << endl;
        cin >> choice;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    cout << "do you want to save the changes? (yes Or no)" << endl;
    string yesOrNo = "";
    cin.ignore();
    getline(cin, yesOrNo);
    if (yesOrNo == "yes" || yesOrNo == "Yes")
    {
        cout << "please enter the file name you want to save the data in" << endl;
        string fileName = "";
        getline(cin, fileName);
        saveToFile(obj, fileName);
    }
}