#include <iostream>

using namespace std;

// 基类指针或引用指向派生类对象时,虚函数与非虚函数区别：
// 声明Employee的print为虚函数，则可访问到Manager的print函数，非虚函数，则只能访问到Employee的print

class Employee
{
private:
    string name;
    string id;

public:
    Employee(string name, string id);
    string getName();
    string getId();
    float getSalary();
    virtual void print();
};

Employee::Employee(string name, string id)
{
    this->name = name;
    this->id = id;
}

string Employee::getName()
{
    return this->name;
}

string Employee::getId()
{
    return this->id;
}

float Employee::getSalary()
{
    return 0.0;
}
void Employee::print()
{
    cout << "Name: " << this->getName() << "\t Id: " << this->id << endl;
}

class Manager : public Employee
{
private:
    float weekSalary;

public:
    Manager(string name, string id, float s = 0.0) : Employee(name, id)
    {
        this->weekSalary = s;
    }
    void setSalary(float s)
    {
        this->weekSalary = s;
    }
    float getSalary()
    {
        return this->weekSalary;
    }
    void print()
    {
        cout << "Manager: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

int main()
{
    Employee e("mi", "0001"), *pm;
    Manager m("wang", "0002", 220);
    m.print();
    pm = &m;
    pm->print();
    Employee &rm = m;
    rm.print();

    /*
        Manager: wang            Id: 0002                Money: 220
        Manager: wang            Id: 0002                Money: 220
        Manager: wang            Id: 0002                Money: 220
    */

    return 0;
}
