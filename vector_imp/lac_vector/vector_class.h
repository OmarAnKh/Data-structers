#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class myVector
{
private:
    double *a;
    int capacity;
    int n;
    void resize()
    {
        double *temp = new double[capacity * 2];
        for (int i = 0; i < n; i++)
        {
            temp[i] = a[i];
        }
        delete[] a;
        a = temp;
        capacity *= 2;
    }

public:
    myVector(int CAP = 5)
    {
        capacity = CAP;
        a = new double[capacity]{0};
        n = 0;
    }
    myVector(const myVector &obj)
    {
        this->capacity = obj.capacity;
        this->a = new double[this->capacity];
        this->n = obj.n;
        for (int i = 0; i < this->n; i++)
        {
            this->a[i] = obj.a[i];
        }
    }
    ~myVector()
    {
        if (this->a != NULL)
        {
            delete[] a;
            a = NULL;
        }
    }

    void add(double x)
    {
        if (n >= capacity)
        {
            resize();
        }
        a[n++] = x;
    }
    myVector operator=(const myVector &obj)
    {
        if (this->a != NULL)
        {
            delete[] a;
        }
        this->capacity = obj.capacity;
        this->n = obj.n;
        a = new double[capacity];
        for (int i = 0; i < n; i++)
        {
            this->a[i] = obj.a[i];
        }
        return *this;
    }

    myVector operator+(const myVector &obj)
    {
        if (this->n + obj.n >= this->capacity)
        {
            resize();
        }
        myVector result(this->capacity);
        result.n = this->n + obj.n;
        for (int i = 0; i < this->n; i++)
        {
            result.a[i] = this->a[i];
        }
        for (int i = this->n, j = 0; j < obj.n; i++, j++)
        {
            result.a[i] = obj.a[j];
        }
        return result;
    }

    friend istream &operator>>(istream &in, myVector &obj)
    {
        obj.n = 0;
        for (int i = 0; i < obj.capacity; i++)
        {
            in >> obj.a[i];
            obj.n++;
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, const myVector &obj)
    {
        for (int i = 0; i < obj.n; i++)
        {
            out << obj.a[i] << "\t";
        }
        return out;
    }

    double get(int index)
    {
        assert(index <= this->n && index > 0);
        return this->a[index];
    }
    double operator[](int index)
    {
        return get(index);
    }
    bool remove(int index)
    {
        assert(index < 0 || index >= n);
        return false;
        for (int i = index; i < n - 1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
        return true;
    }
    int find(double value)
    {
        int i;
        for (int i = 0; i < n && abs(a[i] - value) <= 0.000000000000001; i++)
            ;
        if (i >= n)
        {
            return -1;
        }

        return i;
    }
    string toString()
    {
        string str;
        for (int i = 0; i < n; i++)
        {
            str += "\n";
            str += to_string(a[i]);
        }
        return str;
    }
};