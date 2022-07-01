#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    double salary;
    string name;
};

class SalaryManage
{
private:
    Person *employ;
    int max;
    int n;

public:
    SalaryManage(int max = 0)
    {
        this->max = max;
        this->n = 0;
        this->employ = new Person[this->max];
    }
    double &operator[](string name)
    {
        // 重载 []，返回引用
        Person *p;
        for (p = this->employ; p < this->employ + n; p++)
        {
            if (p->name.compare(name) == 0)
            {
                return p->salary;
            }
        }
        p = this->employ + this->n++;
        p->name = name;
        p->salary = 0;
        return p->salary;
    }

    void display()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << this->employ[i].name << " " << this->employ[i].salary << endl;
        }
    }
    ~SalaryManage()
    {
        delete[] this->employ;
    }
};

int main()
{
    SalaryManage s(3);
    s["张三"] = 2188.88;
    s["里斯"] = 1230.07;
    s["王无"] = 3200.97;
    cout << "张三\t" << s["张三"] << endl;
    cout << "里斯\t" << s["里斯"] << endl;
    cout << "王无\t" << s["王无"] << endl;

    cout << "-------下为display的输出--------\n";
    s.display();

    /*
        张三    2188.88
        里斯    1230.07
        王无    3200.97
        -------下为display的输出--------
        张三 2188.88
        里斯 1230.07
        王无 3200.97
    */

    return 0;
}