#include <iostream>

using namespace std;

/*
    派生方式为protected的继承称为保护继承，在这种继承方式下，
    基类的public成员在派生类中会变成protected成员，
    基类的protected和private成员在派生类中保持原来的访问权限
*/

class Base
{
private:
    int x;

protected:
    int getX()
    {
        return this->x;
    }

public:
    void setX(int x)
    {
        this->x = x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : protected Base
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
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:19) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:22) 不可访问
    d.showY();
    // 20
    return 0;
}
