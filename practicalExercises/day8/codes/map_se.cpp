#include <iostream>
#include <string>
#include <map>

using namespace std;

void test()
{
    string name[] = {
        "wanger", "zhangsan", "lisi"};
    double salary[] = {
        1200, 2000, 3000};
    map<string, double> sal;
    map<string, double>::iterator p;
    for (int i = 0; i < 3; i++)
    {
        sal.insert(make_pair(name[i], salary[i]));
    }
    sal["tom"] = 3400;
    sal["bob"] = 3100;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        cout << p->first << "\t" << p->second << endl;
    }
    string person;
    cout << "find person" << endl;
    cin >> person;
    int flag = 1;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        if (p->first == person)
        {
            cout << p->second << endl;
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "No result" << endl;
    }
    cout << "delete person" << endl;
    cin >> person;
    map<string, double>::iterator it;
    it = sal.find(person);
    if (it != sal.end())
    {
        cout << "find successfully" << (*it).first << ":" << (*it).second << endl;
        sal.erase(it);
        cout << "delete successfully" << endl;
    }
    cout << "result" << endl;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        cout << p->first << " : " << p->second << endl;
    }
}

int main()
{
    test();

    /*
        bob     3100
        lisi    3000
        tom     3400
        wanger  1200
        zhangsan        2000
        find person
        bob
        3100
        delete person
        tom
        find successfullytom:3400
        delete successfully
        result
        bob : 3100
        lisi : 3000
        wanger : 1200
        zhangsan : 2000
    */

    return 0;
}
