#include <iostream>

using namespace std;

/*
若一个类为另一个类的友元，则此类的所有成员都能访问对方类的私有成员。
声明语法：将友元类名在另一个类中使用friend修饰说明。
*/

class A
{
    friend class B;

private:
    int x;

public:
    void display()
    {
        cout << this->x << endl;
    }
};

/*
    如果声明B类是A类的友元，B类的成员函数就可以访问A类的私有和保护数据，
    但A类的成员函数却不能访问B类的私有、保护数据。
*/

class B
{
private:
    A a;

public:
    void set(int i)
    {
        this->a.x = i;
    }
    void display()
    {
        this->a.display();
    }
};

int main()
{
    B b;
    b.set(10);
    b.display();
    // 10
    return 0;
}
