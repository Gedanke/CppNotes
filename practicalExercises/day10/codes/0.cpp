#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CStudent
{
private:
    char name[20];
    int age;

public:
    CStudent()
    {
    }
    CStudent(char *name, int age)
    {
        strcpy(this->name, name);
        this->age = age;
    }
    void display()
    {
        cout << this->name << "\t" << this->age << endl;
    }
};

class IStudent
{
private:
    string name;
    int age;

public:
    IStudent()
    {
    }
    IStudent(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout << this->name << "\t" << this->age << endl;
    }
};

void testC()
{
    ofstream outFile("cstudent.dat", ios::out | ios::binary);
    cout << "input n: " << endl;
    int n;
    cin >> n;
    char name[20];
    int age;
    while (n--)
    {
        cin >> name >> age;
        CStudent s(name, age);
        cout << sizeof(s) << endl;
        outFile.write((char *)&s, sizeof(s));
    }
    outFile.close();

    cout << "----" << endl;
    CStudent ss;
    ifstream inFile("cstudent.dat", ios::in | ios::binary); //二进制读方式打开
    while (inFile.read((char *)&ss, sizeof(ss)))
    {
        ss.display();
    }
    inFile.close();

    /*
        input n:
        1
        kk 12
        24
        ----
        kk      12
    */
}

void testI()
{
    ofstream outFile("istudent.dat", ios::out | ios::binary);
    cout << "input n: " << endl;
    int n;
    cin >> n;
    string name;
    int age;
    while (n--)
    {
        cin >> name >> age;
        IStudent s(name, age);
        cout << sizeof(s) << endl;
        outFile.write((char *)&s, sizeof(s));
    }
    outFile.close();

    cout << "----" << endl;
    IStudent ss;
    ifstream inFile("istudent.dat", ios::in | ios::binary); //二进制读方式打开
    while (inFile.read((char *)&ss, sizeof(ss)))
    {
        ss.display();
    }
    inFile.close();

    /*
        input n:
        1
        dd 12
        40
        ----
        �=      12
        free(): invalid pointer
        Aborted
    */
}

int main()
{
    // testC();
    // testI();
    return 0;
}