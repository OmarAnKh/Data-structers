#include <iostream>
#include <string>
#include <cassert>
using namespace std;
template <typename T>
class myVector
{
private:
    T *a;
    int capacity;
    int n;
    void ReSize()
    {
        T *temp;
        temp = new T[this->capacity * 2];
        this->capacity = this->capacity * 2;
        for (int i = 0; i < this->n; i++)
        {
            temp[i] = this->a[i];
        }
        delete[] this->a;
        a = temp;
    }

public:
    myVector(int temp = 5);
    myVector(const myVector<T> &temp);
    ~myVector();
    void insert(T value);                          // insert a value at the last index of the array
    void edit(int index, T value);                 // edit a value of an index in the array
    void removeByindex(int index);                 // remove a value from the array by it's index
    T get(int index);                              // get a value of the array by it's index
    bool empty();                                  // check if the array is empty
    void clear();                                  // clear the whole array
    T back();                                      // get the value for the last element in the array
    void pushback(T value);                        // insert a value at the last index of the array
    void popback();                                // remove the last element of the array
    void removeByValue(T value);                   // remove an element of the array by its value
    int findByValue(T value);                      // find the index for an element of the array by its value(doesnt work on string)
    T findByindex(int index);                      // find the value for an element of the array by its index
    void removeAllByValue(T value);                // remove all the elements that have the same value(doesnt work on string)
    myVector<T> sort();                            // sort the array ascending
    int size();                                    // get the number of elements in the array
    myVector<T> operator+(const myVector<T> &obj); // concatenate to vectors  together
    myVector<T> operator=(const myVector<T> &obj); // assigns a vector to another one
    T operator[](int index);                       // get a value of the array by it's index
    bool operator==(const myVector<T> &obj);       // check if 2 vectors are equal(doesnt work on string)
    string toString();                             // returne the vector as a string
    friend istream &operator>>(istream &in, myVector<T> &obj)
    {
        obj.n = 0;
        for (int i = 0; i < obj.capacity; i++)
        {
            in >> obj.a[i];
            obj.n++;
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, const myVector<T> &obj)
    {
        for (int i = 0; i < obj.n; i++)
        {
            out << obj.a[i] << "\t";
        }
        return out;
    }
};
