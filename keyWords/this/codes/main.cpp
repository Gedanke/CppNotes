#include <iostream>

using namespace std;

class Person
{
public:
    typedef enum
    {
        BOY = 0,
        GIRL
    } SexType;

private:
    string name;
    int age;
    SexType sex;

public:
    Person(string n, int a, SexType s)
    {
        this->name = n;
        this->age = a;
        this->sex = s;
    }
    int get_age() const
    {
        return this->age;
    }
    Person &add_age(int a)
    {
        this->age += a;
        return *this;
    }
    ~Person()
    {
    }
};

int main()
{
    Person person("zhangsan", 20, Person::BOY);
    cout << person.get_age() << endl;
    person.add_age(4);
    cout << person.get_age() << endl;
    // 20
    // 24
    return 0;
}