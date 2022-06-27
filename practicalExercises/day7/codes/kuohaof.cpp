#include <iostream>
#include <cstring>

using namespace std;

struct Person
{
    double salary;
    char *name;
};

class SalaryManager
{
    Person *employ;
    int max;
    int n;

public:
    SalaryManager(int Max = 0)
    {
        this->max = Max;
        this->n = 0;
        this->employ = new Person[this->max];
    }
    double &operator[](char *Name)
    {
        Person *p;
        for (p = this->employ; p < this->employ + this->n; p++)
            // 如果存在
            if (strcmp(p->name, Name) == 0)
                return p->salary;
        p = this->employ + this->n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;
        return p->salary;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << this->employ[i].name << " " << this->employ[i].salary << endl;
        }
    }
};

int main()
{
    SalaryManager s(4);
    s[(char *)"Alex"] = 2020.20;
    s[(char *)"Bob"] = 2021.21;
    s[(char *)"Clax"] = 2022.22;
    s[(char *)"Clax"] = 2023.23;

    cout << "Alex: " << s[(char *)"Alex"] << endl;
    cout << "Bob: " << s[(char *)"Bob"] << endl;
    cout << "Clax: " << s[(char *)"Clax"] << endl;
    cout << "------display()------" << endl;
    s.display();

    /*
        Alex: 2020.2
        Bob: 2021.21
        Clax: 2023.23
        ------display()------
        Alex 2020.2
        Bob 2021.21
        Clax 2023.23
    */

    return 0;
}
