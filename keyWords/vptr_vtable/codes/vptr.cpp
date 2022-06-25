#include <iostream>

using namespace std;

// c++ 虚函数 vptr 和 vtable

// 函数指针
typedef void (*Fun)();

class Base
{
public:
    virtual void fun1()
    {
        cout << "Base::fun1()" << endl;
    }
    virtual void fun2()
    {
        cout << "Base::fun2()" << endl;
    }
    virtual void fun3()
    {
    }
    ~Base()
    {
    }
};

class Derived : public Base
{
public:
    Derived()
    {
    }
    void fun1()
    {
        cout << "Dervied::fun1()" << endl;
    }
    void fun2()
    {
        cout << "Dervied::fun1()" << endl;
    }
    ~Derived()
    {
    }
};

// 获取 vptr 地址与 func 地址,vptr 指向的是一块内存，这块内存存放的是虚函数地址，这块内存就是我们所说的虚表
Fun getAddr(void *obj, unsigned int offset)
{
    cout << "=========================" << endl;
    // 64 位操作系统，占 8 字节，通过 *(unsigned long *)obj 取出前 8 字节，即 vptr 指针
    void *vptr_addr = (void *)*(unsigned long *)obj;
    cout << "vptr_addr: " << vptr_addr << endl;
    // 通过 vptr 指针访问 virtual table，因为虚表中每个元素(虚函数指针)在 64 位编译器下是 8 个字节，
    // 因此通过 *(unsigned long *)vptr_addr 取出前 8 字节
    // 后面加上偏移量就是每个函数的地址！
    void *func_addr = (void *)*((unsigned long *)vptr_addr + offset);
    cout << "func_addr: " << func_addr << endl;
    return (Fun)func_addr;
}

int main()
{
    Base ptr;
    Derived d;
    Base *pt = new Derived(); // 基类指针指向派生类实例
    Base &pp = ptr;           // 基类引用指向基类实例
    Base &p = d;              // 基类引用指向派生类实例
    cout << "基类对象直接调用" << endl;
    ptr.fun1();
    cout << "基类引用指向基类实例" << endl;
    pp.fun1();
    cout << "基类指针指向派生类实例并调用虚函数" << endl;
    pt->fun1();
    cout << "基类引用指向基类实例并调用虚函数" << endl;
    p.fun1();

    // 手动查找vptr 和 vtable
    Fun f1 = getAddr(pt, 0);
    (*f1)();
    Fun f2 = getAddr(pt, 1);
    (*f2)();

    delete pt;

    /*
    基类对象直接调用
    Base::fun1()
    基类引用指向基类实例
    Base::fun1()
    基类指针指向派生类实例并调用虚函数
    Dervied::fun1()
    基类引用指向基类实例并调用虚函数
    Dervied::fun1()
    =========================
    vptr_addr: 0x564d63dfecf0
    func_addr: 0x564d63dfc66e
    Dervied::fun1()
    =========================
    vptr_addr: 0x564d63dfecf0
    func_addr: 0x564d63dfc6aa
    Dervied::fun1()
    */
    return 0;
}