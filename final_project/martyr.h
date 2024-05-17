#include <iostream>
#include <string>
using namespace std;
class martyr
{
private:
    string name;
    string age;
    string event_location;
    string date_of_death;
    string gender;

public:
    martyr(string n = "", string a = "", string e = "", string d = "", string g = "")
    {
        name = n;
        age = a;
        event_location = e;
        date_of_death = d;
        gender = g;
    }
    string getName() const
    {
        return name;
    }
    string getAge() const
    {
        return age;
    }
    string getEventLocation() const
    {
        return event_location;
    }
    string getDateOfDeath() const
    {
        return date_of_death;
    }
    string getGender() const
    {
        return gender;
    }
    void setName(string n)
    {
        name = n;
    }
    void setAge(string a)
    {
        age = a;
    }
    void setEventLocation(string e)
    {
        event_location = e;
    }
    void setdateOfDeath(string d)
    {
        date_of_death = d;
    }
    void setGender(string g)
    {
        gender = g;
    }
    friend ostream &operator<<(ostream &out, const martyr &obj)
    {
        cout << obj.getName() << "\t\t" << obj.getAge() << "\t\t" << obj.getEventLocation() << "\t\t" << obj.getDateOfDeath() << "\t\t" << obj.getGender() << "\t\t" << endl;
        return out;
    }
    martyr &operator=(const martyr &obj)
    {
        this->setName(obj.getName());
        this->setAge(obj.getAge());
        this->setEventLocation(obj.getEventLocation());
        this->setdateOfDeath(obj.getDateOfDeath());
        this->setGender(obj.getGender());
        return *this;
    }
};