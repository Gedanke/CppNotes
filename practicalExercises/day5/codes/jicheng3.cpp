#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    void setX(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return this->x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    d.setX(10);
    d.setY(20);
    d.showX();
    d.showY();
    d.setY();
    d.showX();
    d.showY();

    /*
        10
        20
        10
        10
    */

    return 0;
}
