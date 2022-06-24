#include <iostream>

using namespace std;

/*
虚函数可以被私有化，但有一些细节需要注意。
基类指针指向继承类对象，则调用继承类对象的函数；
int main() 必须声明为 Base 类的友元，否则编译失败。编译器报错：ptr 无法访问私有函数。
当然，把基类声明为 public，继承类为 private，该问题就不存在了。----> 见另外一个例子
*/

class Dervied;

class Base
{
public:
    virtual void fun()
    {
        cout << "Base fun" << endl;
    }
    // friend int main();
};

class Derived : public Base
{
private:
    void fun()
    {
        cout << "Derived fun" << endl;
    }
};

int main()
{
    Base *p = new Derived();
    p->fun();
    // Derived fun
    return 0;
}