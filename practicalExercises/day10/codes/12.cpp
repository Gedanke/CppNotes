#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class Person
{
private:
    char name[20];
    char id[20];
    int age;
    char address[20];

public:
    Person()
    {
    }
    Person(char *name, char *id, int age, char *address)
    {
        strcpy(this->name, name);
        strcpy(this->id, id);
        this->age = age;
        strcpy(this->address, address);
    }
    void display()
    {
        cout << this->name << "\t" << this->id << "\t" << this->age << "\t" << this->address << endl;
    }
};

int main()
{
    vector<Person> v;
    ofstream out("./person.dat", ios::out | ios::binary);
    char name[20], id[20], address[20];
    int age;
    cout << "------input number:" << endl;
    int num;
    cin >> num;
    while (num--)
    {
        cout << "name: " << endl;
        cin >> name;
        cout << "id: " << endl;
        cin >> id;
        cout << "age: " << endl;
        cin >> age;
        cout << "address: " << endl;
        cin >> address;
        Person per(name, id, age, address);
        out.write((char *)&per, sizeof(per));
    }
    out.close();

    cout << "------" << endl;
    ifstream in("./person.dat", ios::in | ios::binary);
    Person p;
    while (in.read((char *)&p, sizeof(p)))
    {
        v.push_back(p);
    }
    in.close();
    for (auto vv : v)
    {
        vv.display();
    }

    /*
        ------input number:
        2
        name:
        dd
        id:
        12
        age:
        20
        address:
        cn
        name:
        ff
        id:
        13
        age:
        21
        address:
        cn
        ------
        dd      12      20      cn
        ff      13      21      cn
    */

    return 0;
}