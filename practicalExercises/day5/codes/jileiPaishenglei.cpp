#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    void setA(int x)
    {
        this->a = x;
    }
    int getA()
    {
        return this->a;
    }
};

class B : public A
{
private:
    int b;

public:
    void setB(int x)
    {
        this->b = x;
    }
    int getB()
    {
        return this->b;
    }
};

void f1(A a, int x)
{
    a.setA(x);
}

void f2(A *a, int x)
{
    a->setA(x);
}

void f3(A &a, int x)
{
    a.setA(x);
}

int main()
{
    A a1, *pa;
    B b1, *pb;
    a1.setA(1);
    b1.setA(2);
    // 把派生类对象赋值给基类对象
    a1 = b1;
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 2
    // 2
    a1.setA(10);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 10
    // 2
    // 把派生类对象的地址赋值给基类指针
    pa = &b1;
    pa->setA(20);
    cout << pa->getA() << endl;
    cout << b1.getA() << endl;
    // 20
    // 20
    // 用派生类对象初始化基类对象的引用
    A &ra = b1;
    ra.setA(30);
    cout << ra.getA() << endl;
    cout << b1.getA() << endl;
    // 30
    // 30
    b1.setA(7);
    cout << b1.getA() << endl;
    // 7
    f1(b1, 100);
    cout << b1.getA() << endl;
    // 7
    f2(&b1, 200);
    cout << b1.getA() << endl;
    // 200
    f3(b1, 300);
    cout << b1.getA() << endl;
    // 300
    return 0;
}
