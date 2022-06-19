#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
protected:
    int x;

public:
    virtual void fun() = 0;
    Base(int i)
    {
        this->x = i;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int x, int y) : Base(x)
    {
        this->y = y;
    }
    void fun()
    {
        cout << "x = " << x << ";y = " << y << endl;
    }
};

int main()
{
    Derived d(3, 4);
    d.fun();
    // x = 3;y = 4
    return 0;
}