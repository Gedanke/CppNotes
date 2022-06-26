#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        this->x = 0;
    }
    static void f(A a);

private:
    int x;
};

void A::f(A a)
{
    cout << a.x << endl;
}

int main()
{
    A a;
    a.f(a);
    // 0
    return 0;
}