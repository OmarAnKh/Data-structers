#include <iostream>
#include <string>

using namespace std;
class myVector
{
private:
    martyr *array;
    int size;
    int capacity;
    void resize()
    {
        martyr *temp;
        temp = new martyr[this->capacity * 2];
        this->capacity = this->capacity * 2;
        for (int i = 0; i < this->size; i++)
        {
            temp[i] = this->array[i];
        }
        delete[] this->array;
        array = temp;
    }

public:
    int vectorSize()
    {
        return size;
    }
    myVector(int cap = 5)
    {
        capacity = cap;
        size = 0;
        array = new martyr[capacity];
    }
    myVector(const myVector &obj)
    {
        this->capacity = obj.capacity;
        this->size = obj.size;
        array = new martyr[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->array[i] = obj.array[i];
        }
    }
    ~myVector()
    {
        delete[] array;
    }
    void insertMartyr(string n = "", string a = "", string e = "", string d = "", string g = "")
    {

        full();

        if (!empty())
        {
            for (int i = 0; i < size; i++)
            {

                if (array[i].getName() > n || array[i].getName() == "")
                {
                    for (int j = size - 1; j >= i && j > 0; j--)
                    {
                        array[j] = array[j - 1];
                    }
                    array[i].setName(n);
                    array[i].setAge(a);
                    array[i].setEventLocation(e);
                    array[i].setdateOfDeath(d);
                    array[i].setGender(g);
                    break;
                }
            }
        }
        else if (empty())
        {
            array[size].setName(n);
            array[size].setAge(a);
            array[size].setEventLocation(e);
            array[size].setdateOfDeath(d);
            array[size].setGender(g);
        }
        size++;
    }
    void full()
    {
        if (size >= capacity)
        {
            resize();
        }
    }
    myVector &operator=(const myVector &obj)
    {
        this->capacity = obj.capacity;
        this->size = obj.size;
        delete[] this->array;
        this->array = new martyr[capacity];
        for (int i = 0; i < obj.size; i++)
        {
            this->array[i] = obj.array[i];
        }
        return *this;
    }
    bool empty()
    {
        return size == 0;
    }
    bool removeMartyr(string name)
    {

        martyr *temp = new martyr[capacity];
        int i, j;
        for (i = 0, j = 0; i < size; i++)
        {
            if (name != array[i].getName())
            {
                temp[i] = array[i];
                j++;
            }
        }
        if (j < i)
        {
            size--;
            delete[] array;
            array = temp;
            return 1;
        }
        else
        {
            delete temp;
            return 0;
        }
    }
    bool displayInfo(string name)
    {
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (name == array[i].getName())
            {
                flag = 1;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout << array[i].getName() << "\t" << array[i].getAge() << "\t" << array[i].getEventLocation() << "\t" << array[i].getDateOfDeath() << "\t" << array[i].getGender() << endl;
                cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }
        if (flag)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void printAllInfo()
    {
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << array[i].getName() << "\t" << array[i].getAge() << "\t" << array[i].getEventLocation() << "\t" << array[i].getDateOfDeath() << "\t" << array[i].getGender() << endl;
        }
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    martyr *getData()
    {
        return array;
    }

    void updateMartyr(string city,string oldName, string newName, string age)
    {
        for (int i = 0; i < size; i++)
        {
            if (oldName == array[i].getName())
            {
                array[i].setName(newName);
                array[i].setAge(age);
                array[i].setEventLocation(city);
                break;
            }
        }
    }
};