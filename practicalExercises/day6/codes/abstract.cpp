#include <iostream>

using namespace std;

class Figure
{
protected:
    double x, y;

public:
    void set(double i, double j)
    {
        this->x = i;
        this->y = j;
    }
    virtual void area() = 0;
};

class Trianle : public Figure
{
public:
    void area()
    {
        cout << "Trianle" << endl;
    }
};

class Rectangle : public Figure
{
public:
    void area()
    {
        cout << "Rectangle" << endl;
    }
};

int main()
{
    // 抽象指针
    Figure *pf = NULL;
    // Figure f; 不允许使用抽象类类型 "Figure" 的对象
    Rectangle r;
    Trianle t;
    t.set(10, 20);
    pf = &t;
    pf->area();
    r.set(10, 20);
    pf = &r;
    pf->area();
    // 抽象类引用
    Figure &rf = t;
    rf.set(20, 20);
    rf.area();

    /*
        Trianle
        Rectangle
        Trianle
    */

    return 0;
}
