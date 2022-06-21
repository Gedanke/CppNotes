#include <iostream>

using namespace std;

int count = 0;

class A
{
public:
    static int count;
};

int A::count;

int main()
{
    ::count = 1;
    A::count = 5;
    cout << ::count << endl;
    // 1
    cout << A::count << endl;
    // 5
    // int count=3;
    // count=4;
    return 0;
}