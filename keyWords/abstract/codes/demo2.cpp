#include <iostream>

using namespace std;

// 抽象类至少包含一个纯虚函数

class Base
{
private:
    int x;

public:
    virtual void show() = 0;
    int getX()
    {
        return this->x;
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
    void show()
    {
        cout << "In Derived" << endl;
    }
};

int main()
{
    Base *bp = new Derived();
    bp->show();
    // In Derived
    return 0;
}