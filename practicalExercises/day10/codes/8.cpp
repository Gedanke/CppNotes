#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
private:
    int number;
    int age;
    string name;
    double sal;

public:
    Employee()
    {
    }
    Employee(int number, int age, string name, double sal)
    {
        this->number = number;
        this->age = age;
        this->name = name;
        this->sal = sal;
    }
    void display()
    {
        cout << this->number << "\t" << this->name << "\t" << this->age << "\t" << this->sal;
    }
};

int main()
{
    ofstream out("./d.dat", ios::out);
    Employee e1(1, 23, "张三", 2300);
    Employee e2(2, 21, "张四", 2350);
    Employee e3(3, 20, "张五", 2390);
    Employee e4(4, 22, "张六", 2310);

    out.write((char *)&e1, sizeof(e1));
    out.write((char *)&e2, sizeof(e2));
    out.write((char *)&e3, sizeof(e3));
    out.write((char *)&e4, sizeof(e4));

    Employee e5(3, 30, "张七", 2200);
    out.seekp(3 * sizeof(e1));
    out.write((char *)&e5, sizeof(e5));
    out.close();

    /*
     */

    return 0;
}
