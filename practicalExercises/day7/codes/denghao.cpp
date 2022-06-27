#include <iostream>

using namespace std;

class X
{
public:
    X &operator=(const X &x)
    {
        cout << "a:" << endl;
        return *this;
    }
};

int main()
{
    X x1, x2, x3;
    x1 = x2;
    x1.operator=(x2);
    x1 = x2 = x3;

    /*
        a:
        a:
        a:
        a:
    */

    return 0;
}
