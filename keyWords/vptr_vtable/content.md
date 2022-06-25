# C++ 虚函数的 vptr 与 vtable

---

## 基础理论

为了实现虚函数，C++ 使用一种称为虚拟表的特殊形式的后期绑定。该虚拟表是用于解决在动态/后期绑定方式的函数调用函数的查找表。虚拟表有时会使用其他名称，例如“vtable”，“虚函数表”，“虚方法表”或“调度表”。

虚拟表实际上非常简单，虽然用文字描述有点复杂。首先，每个使用虚函数的类(或者从使用虚函数的类派生)都有自己的虚拟表。该表只是编译器在编译时设置的静态数组。虚拟表包含可由类的对象调用的每个虚函数的一个条目。此表中的每个条目只是一个函数指针，指向该类可访问的派生函数。

其次，编译器还会添加一个隐藏指向基类的指针，我们称之为 ```vptr```。```vptr``` 在创建类实例时自动设置，以便指向该类的虚拟表。与 ```this``` 指针不同，```this``` 指针实际上是编译器用来解析自引用的函数参数，```vptr``` 是一个真正的指针。

因此，它使每个类对象的分配为一个指针的大小。这也意味着 ```vptr``` 由派生类继承，这很重要。

---

## 实现与内部结构

下面来看自动与手动操纵 ```vptr``` 来获取地址与调用虚函数

开始看代码之前，为了大家理解，这里给出调用图：

![](base.jpg)

代码全部遵循标准的注释风格

```cpp
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

    // 调用 fun1()
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
        vptr_addr: 0x55ce3b31bcf0
        func_addr: 0x55ce3b31966e
        Dervied::fun1()
        =========================
        vptr_addr: 0x55ce3b31bcf0
        func_addr: 0x55ce3b3196aa
        Dervied::fun1()
    */

    // 调用 fun3()
    /*
        基类对象直接调用
        基类引用指向基类实例
        基类指针指向派生类实例并调用虚函数
        基类引用指向基类实例并调用虚函数
        =========================
        vptr_addr: 0x55afeaab2cf0
        func_addr: 0x55afeaab0676
        Dervied::fun1()
        =========================
        vptr_addr: 0x55afeaab2cf0
        func_addr: 0x55afeaab06b2
        Dervied::fun1()
    */
    return 0;
}
```

可以发现 C++ 的动态多态性是通过虚函数来实现的。简单的说，通过 ```virtual``` 函数，指向子类的基类指针可以调用子类的函数。例如，上述通过基类指针指向派生类实例，并调用虚函数，将上述代码简化为：

```cpp
Base *pt = new Derived(); // 基类指针指向派生类实例
cout<<"基类指针指向派生类实例并调用虚函数"<<endl;
pt->fun1();
```

其过程为：首先程序识别出 ```fun1()``` 是个虚函数，其次程序使用 ```pt->vptr``` 来获取 Derived 的虚拟表。第三，它查找 Derived 虚拟表中调用哪个版本的 ```fun1()```。这里就可以发现调用的是 ```Derived::fun1()```。因此 ```pt->fun1()``` 被解析为 ```Derived::fun1()```

除此之外，上述代码也包含了手动获取 ```vptr``` 地址，并调用 ```vtable``` 中的函数，那么我们一起来验证一下上述的地址与真正在自动调用 ```vtable``` 中的虚函数，比如上述 ```pt->fun1()``` 的时候，是否一致

这里采用 gdb 调试，在编译的时候记得加上 ```-g```

通过 ```gdb main``` 进入 gdb 调试页面，然后输入 ```b Derived::fun1``` 对 fun1 打断点，然后通过输入 r 运行程序到断点处，此时需要查看调用栈中的内存地址，通过 ```disassemable fun1``` 可以查看当前有关 fun1 中的相关汇编代码，我们看到了 ```0x000055555555566e```，然后再对比上述的结果会发现与手动调用的 fun1 一致，fun2 类似，以此证明代码正确

全过程如下

```shell
$ gdb main
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from main...
(gdb) b Derived::fun1
Breakpoint 1 at 0x166e: file main.cpp, line 35.
(gdb) r
Starting program: /home/root/codes/cplusplus/vscode/demo/testc/main 
基类对象直接调用
Base::fun1()
基类引用指向基类实例
Base::fun1()
基类指针指向派生类实例并调用虚函数

Breakpoint 1, Derived::fun1 (this=0x7ffff7f127a3 <std::ostream::flush()+35>) at main.cpp:35
35          void fun1()
(gdb) disassemble fun1
Dump of assembler code for function Derived::fun1():
=> 0x000055555555566e <+0>:     endbr64 
   0x0000555555555672 <+4>:     push   %rbp
   0x0000555555555673 <+5>:     mov    %rsp,%rbp
   0x0000555555555676 <+8>:     sub    $0x10,%rsp
   0x000055555555567a <+12>:    mov    %rdi,-0x8(%rbp)
   0x000055555555567e <+16>:    lea    0x99e(%rip),%rsi        # 0x555555556023
   0x0000555555555685 <+23>:    lea    0x29b4(%rip),%rdi        # 0x555555558040 <_ZSt4cout@@GLIBCXX_3.4>
   0x000055555555568c <+30>:    callq  0x5555555550f0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x0000555555555691 <+35>:    mov    %rax,%rdx
   0x0000555555555694 <+38>:    mov    0x2935(%rip),%rax        # 0x555555557fd0
   0x000055555555569b <+45>:    mov    %rax,%rsi
   0x000055555555569e <+48>:    mov    %rdx,%rdi
   0x00005555555556a1 <+51>:    callq  0x555555555120 <_ZNSolsEPFRSoS_E@plt>
   0x00005555555556a6 <+56>:    nop
   0x00005555555556a7 <+57>:    leaveq 
   0x00005555555556a8 <+58>:    retq   
End of assembler dump.
(gdb) disassemble fun2
Dump of assembler code for function Derived::fun2():
   0x00005555555556aa <+0>:     endbr64 
   0x00005555555556ae <+4>:     push   %rbp
   0x00005555555556af <+5>:     mov    %rsp,%rbp
   0x00005555555556b2 <+8>:     sub    $0x10,%rsp
   0x00005555555556b6 <+12>:    mov    %rdi,-0x8(%rbp)
   0x00005555555556ba <+16>:    lea    0x962(%rip),%rsi        # 0x555555556023
   0x00005555555556c1 <+23>:    lea    0x2978(%rip),%rdi        # 0x555555558040 <_ZSt4cout@@GLIBCXX_3.4>
   0x00005555555556c8 <+30>:    callq  0x5555555550f0 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
   0x00005555555556cd <+35>:    mov    %rax,%rdx
   0x00005555555556d0 <+38>:    mov    0x28f9(%rip),%rax        # 0x555555557fd0
   0x00005555555556d7 <+45>:    mov    %rax,%rsi
   0x00005555555556da <+48>:    mov    %rdx,%rdi
   0x00005555555556dd <+51>:    callq  0x555555555120 <_ZNSolsEPFRSoS_E@plt>
   0x00005555555556e2 <+56>:    nop
   0x00005555555556e3 <+57>:    leaveq 
   0x00005555555556e4 <+58>:    retq   
End of assembler dump.
```

---

## 总结

虚拟表只是看起来复杂，其实很简单，每个含有虚函数的类都有自己的虚拟表，根据子类对父类虚函数实现与否，```vptr``` 会指向不同的函数，这也是多态的体现。 

---
