#include <iostream>

using namespace std;

class A
{
public:
    char a;
    int b;
};

class B
{
public:
    short a;
    long b;
};

class C : A, B
{
private:
    char c;
};

int main()
{
    cout << sizeof(A) << endl;
    // 8
    cout << sizeof(B) << endl;
    // 16
    cout << sizeof(C) << endl;
    // 32
    return 0;
}