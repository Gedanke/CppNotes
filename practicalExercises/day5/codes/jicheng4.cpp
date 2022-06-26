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

class Derived : private Base
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
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:9) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:15) 不可访问
    d.showY();
    // 20
    return 0;
}
