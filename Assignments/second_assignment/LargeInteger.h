#include <iostream>
#include <string>
using namespace std;
class LargeInteger
{
private:
    int *number;
    int length;
    int maxSize;

public:
    LargeInteger(string number1)
    {
        number = new int[number1.length() * 2]{0};
        length = number1.length();
        maxSize = length * 2;
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (number1[i] >= '0' && number1[i] <= '9')
            {
                counter++;
            }
        }
        if (counter == length)
        {
            for (int i = maxSize - 1, j = length - 1; i >= 0 && j >= 0; j--, i--)
            {
                number[i] = number1[j] - '0';
            }
            return;
        }
        exit(1); 
    }
    LargeInteger(int size = 10)
    {
        length = 0;
        maxSize = size;
        number = new int[maxSize]{0};
    }
    LargeInteger(const LargeInteger &obj)
    {
        this->length = obj.length;
        maxSize = obj.maxSize;
        number = new int[maxSize]{0};
        for (int i = 0; i < maxSize; i++)
        {
            number[i] = obj.number[i];
        }
    }
    ~LargeInteger()
    {
        length = 0;
        maxSize = 0;
        delete[] number;
    }
    bool set(string str)
    {
        if (number != NULL)
        {
            delete[] number;
        }
        length = str.length();
        maxSize = length * 2;
        number = new int[maxSize]{0};
        int counter = 0;
        for (int i = 0; i < length; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                counter++;
            }
        }
        if (counter == length)
        {
            for (int i = maxSize - 1, j = length - 1; i >= 0 && j >= 0; j--, i--)
            {
                number[i] = str[j] - '0';
            }
            return 1;
        }
        return 0;
    }
    void read(istream &in)
    {
        string str;
        in >> str;
        set(str);
    }
    void write(ostream &out)
    {
        for (int i = maxSize - length; i < maxSize; i++)
        {
            cout << number[i];
        }
    }
    LargeInteger operator*(const LargeInteger &obj)
    {

        if (length > obj.length)
        {
            LargeInteger result(maxSize + obj.maxSize);
            int zero = 0;
            for (int i = obj.maxSize - 1; i >= obj.maxSize - obj.length; i--)
            {

                int temp = (maxSize + obj.maxSize) - 1 - zero;

                for (int j = maxSize - 1; j >= maxSize - length; j--)
                {
                    result.number[temp] += obj.number[i] * number[j];

                    temp--;
                }
                zero++;
            }
            for (int i = (maxSize + obj.maxSize) - 1; i >= 0; i--)
            {

                if (result.number[i] > 9)
                {
                    int temp = result.number[i] % 10;
                    result.number[i - 1] += result.number[i] / 10;
                    result.number[i] = temp;
                }
            }
            int counter = 0;
            for (int i = 0; i < result.maxSize; i++)
            {

                if (result.number[i] != 0)
                {
                    break;
                }
                counter++;
            }
            result.length = result.maxSize - counter;
            return result;
        }

        LargeInteger result(maxSize + obj.maxSize);
        int zero = 0;
        for (int i = maxSize - 1; i >= maxSize - length; i--)
        {

            int temp = (maxSize + obj.maxSize) - 1 - zero;

            for (int j = obj.maxSize - 1; j >= obj.maxSize - obj.length; j--)
            {
                result.number[temp] += obj.number[j] * number[i];

                temp--;
            }
            zero++;
        }
        for (int i = (maxSize + obj.maxSize) - 1; i >= 0; i--)
        {

            if (result.number[i] > 9)
            {
                int temp = result.number[i] % 10;
                result.number[i - 1] += result.number[i] / 10;
                result.number[i] = temp;
            }
        }
        int counter = 0;
        for (int i = 0; i < result.maxSize; i++)
        {

            if (result.number[i] != 0)
            {
                break;
            }
            counter++;
        }
        result.length = result.maxSize - counter;
        return result;
    }
    LargeInteger operator+(const LargeInteger &obj)
    {
        if (this->length >= obj.length)
        {
            LargeInteger result(this->maxSize + 1);
            result.maxSize = this->maxSize;
            result.length = this->length;
            int overflow = 0;
            for (int i = maxSize - 1, j = obj.maxSize - 1; j >= 0; i--, j--)
            {
                int temp = this->number[i] + obj.number[j] + overflow;
                if (temp > 9)
                {
                    temp %= 10;
                }

                result.number[i] = temp;
                if ((this->number[i] + obj.number[j] + overflow) > 9)
                {
                    overflow = 1;
                }
                else
                {
                    overflow = 0;
                }
            }
            if (overflow)
            {
                result.number[(this->maxSize - this->length) - 1] = overflow;
                result.length++;
            }
            int counter = 0;
            for (int i = 0; i < result.maxSize; i++)
            {

                if (result.number[i] != 0)
                {
                    break;
                }
                counter++;
            }
            result.length = result.maxSize - counter;
            return result;
        }

        LargeInteger result(obj.maxSize + 1);
        result.maxSize = obj.maxSize;
        result.length = obj.length;
        int overflow = 0;
        for (int i = maxSize - 1, j = obj.maxSize - 1; i >= 0; i--, j--)
        {

            int temp = this->number[i] + obj.number[j] + overflow;
            if (temp > 9)
            {
                temp %= 10;
            }
            result.number[j] = temp;
            if ((this->number[i] + obj.number[j] + overflow) > 9)
            {
                overflow = 1;
            }
            else
            {
                overflow = 0;
            }
        }
        if (overflow)
        {
            result.number[(obj.maxSize - obj.length) - 1] = overflow;
            result.length++;
        }
        int counter = 0;
        for (int i = 0; i < result.maxSize; i++)
        {

            if (result.number[i] != 0)
            {
                break;
            }
            counter++;
        }
        result.length = result.maxSize - counter;
        return result;
    }
    LargeInteger operator-(const LargeInteger &obj)
    {
        if (*this > obj)
        {
            LargeInteger result(*this);

            int overflow = 0;
            for (int i = maxSize - 1, j = obj.maxSize - 1; i >= maxSize - length; i--, j--)
            {
                int counter = i - 1;
                result.number[i] = result.number[i] - obj.number[j];

                if (result.number[i] < 0)
                {
                    while (result.number[counter] == 0)
                    {
                        counter--;
                    }
                    result.number[counter]--;
                    counter++;
                    while (counter != i)
                    {
                        result.number[counter] += 9;
                        counter++;
                    }
                    result.number[counter] += 10;
                }
            }
            int counter = 0;
            for (int i = 0; i < result.maxSize; i++)
            {

                if (result.number[i] != 0)
                {
                    break;
                }
                counter++;
            }
            result.length = result.maxSize - counter;
            return result;
        }

        LargeInteger result(obj);

        int overflow = 0;
        for (int i = obj.maxSize - 1, j = maxSize - 1; i >= obj.maxSize - obj.length; i--, j--)
        {
            int counter = i - 1;
            result.number[i] = result.number[i] - this->number[j];
            cout << result.number[i];
            if (result.number[i] < 0)
            {
                while (result.number[counter] == 0)
                {
                    counter--;
                }
                result.number[counter]--;
                counter++;
                while (counter != i)
                {
                    result.number[counter] += 9;
                    counter++;
                }
                result.number[counter] += 10;
            }
        }
        int counter = 0;
        for (int i = 0; i < result.maxSize; i++)
        {

            if (result.number[i] != 0)
            {
                break;
            }
            counter++;
        }
        result.length = result.maxSize - counter;
        return result;
    }
    bool operator==(const LargeInteger &obj)
    {
        int counter = 0;
        if (this->length == obj.length)
        {
            for (int i = maxSize - length; i < maxSize; i++)
            {
                if (this->number[i] != obj.number[i])
                {
                    break;
                }
                counter++;
            }
        }
        if (counter == length)
        {
            return 1;
        }
        return 0;
    }
    bool operator>(const LargeInteger &obj)
    {
        if (this->length > obj.length)
        {
            return 1;
        }
        else if (this->length == obj.length)
        {
            if (this->number[(maxSize - length)] > obj.number[(obj.maxSize - obj.length)])
            {
                return 1;
            }
        }

        return 0;
    }
    bool operator<(const LargeInteger &obj)
    {
        if (this->length < obj.length)
        {
            return 1;
        }
        else if (this->length == obj.length)
        {
            if (this->number[(maxSize - length)] < obj.number[(obj.maxSize - obj.length)])
            {
                return 1;
            }
        }
        return 0;
    }
    LargeInteger operator=(const LargeInteger &obj)
    {
        this->length = obj.length;
        this->maxSize = obj.maxSize;
        if (this->number != NULL)
        {
            delete[] number;
        }
        number = new int[maxSize];
        for (int i = 0; i < maxSize; i++)
        {
            number[i] = obj.number[i];
        }
        return *this;
    }
};