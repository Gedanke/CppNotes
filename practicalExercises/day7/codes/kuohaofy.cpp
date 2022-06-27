#include <iostream>

using namespace std;

class X
{
public:
    int operator()(int i = 0)
    {
        cout << "X::operator(" << i << ")" << endl;
        return i;
    }
    int operator()(int i, int j)
    {
        cout << "X::operator(" << i << "," << j << ")" << endl;
        return i;
    }
    int operator[](int i)
    {
        cout << "X::operator[" << i << "]" << endl;
        return i;
    }
    int operator[](char *c)
    {
        cout << "X::operator[" << c << "]" << endl;
        return 0;
    }
};

int main()
{
    X obj;
    int i = obj(obj(1), 2);
    int a = obj[i];
    int b = obj[(char *)"abcdefg"];
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

    /*
        X::operator(1)
        X::operator(1,2)
        X::operator[1]
        X::operator[abcdefg]
        a= 1
        b= 0
    */

    return 0;
}
