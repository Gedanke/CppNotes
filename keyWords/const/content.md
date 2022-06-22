# const

---

## 含义

常类型是指使用类型修饰符 ```const``` 说明的类型，常类型的变量或对象的值是不能被更新的。

---

## 作用

* 可以定义常量
* 类型检查：
  * ``const`` 常量与 ``#define`` 宏定义常量的区别: ``const`` 常量具有类型，编译器可以进行安全检查；``#define`` 定义的宏常量(假设它不是花括号初始化器列表)同样存在类型，具体的类型和各种字面量(整数、浮点、用户定义等)和运算符的结果类型有关，编译器会进行字符串替换，不会进行安全检查
  * ``const`` 定义的变量只有类型为整数或枚举，且以常量表达式初始化时才能作为常量表达式。其他情况下它只是一个 ``const`` 限定的变量，不要将与常量混淆
* 防止修改，起保护作用，增加程序健壮性

```cpp
#include <iostream>

using namespace std;

void fun(const int i)
{
    // i=10; 表达式必须是可修改的左值
    cout << i << endl;
}

int main()
{
    fun(1);
    return 0;
}
```

* 可以节省空间，避免不必要的内存分配
  * ``const`` 定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像 ``#define`` 一样给出的是立即数
  * ``const`` 定义的常量在程序运行过程中只有一份拷贝，而 ``#define`` 定义的常量在内存中有若干个拷贝
  * 需要注意的是，若用 ``const`` 定义常量(类型为整数或枚举，必须以常量表达式初始化)，则这种常量在非 ``odr`` 式使用(粗略来说是只使用其值)时不需要依赖其身为变量的身份，一定场合下甚至可以不需要定义(譬如作为类的 ``static`` 成员对象)。编译器在作为常量处理它时，不会依赖“一份定义”，而是像是立即数一样使用它，它本身可能在机器码中被“拷贝”到多个地方，和 ``#define`` 定义的宏常量的结果相同。另一方面，``const`` 定义的常量由于是整数或枚举，所以直接变成机器码上的立即数往往性能更好

---

## const 对象默认为文件局部变量

注意：非 ``const`` 变量默认为 ``extern``。要使 ``const`` 变量能够在其他文件中访问，必须在文件中显式地指定它为 ``extern``。

* 未被 ``const`` 修饰的变量在不同文件的访问

```cpp
// file.cpp
int ext

// main.cpp
#include <iostream>

using namespace std;

extern int ext;

// g++ -o main file.cpp main.cpp && ./main

int main()
{
    cout << (ext + 1024) << endl;
    return 0;
}
```

* ``const`` 常量在不同文件的访问

```cpp
// extern_file.cpp
extern const int ext = 12;

// extern_main.cpp
#include <iostream>

using namespace std;

extern const int ext;

// g++ -o const_main const_file.cpp const_main.cpp && ./const_main

int main()
{
    cout << (ext + 1024) << endl;
    return 0;
}
```

小结：可以发现未被 ``const`` 修饰的变量不需要 ``extern`` 显式声明！而 ``const`` 常量需要显式声明 ``extern`` ，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。

---

## 定义常量

```cpp
#include <iostream>

using namespace std;

int main()
{
    const int a = 10;
    // a=11; 表达式必须是可修改的左值
    const string s = "const";
    // const int i; 常量 变量 "i" 需要初始值设定项
    const int j = 0;
    return 0;
}
```

上述有两个错误

* 第一：b 为常量，不可更改
* 第二：i 为常量，必须进行初始化(因为常量在定义后就不能被修改，所以定义时必须初始化)

---

## 指针与 const

与指针相关的 ``const`` 有四种：

```cpp
const char * a; //指向 const 对象的指针或者说指向常量的指针。
char const * a; //同上
char * const a; //指向类型对象的 const 指针。或者说常指针、const 指针。
const char * const a; //指向 const 对象的 const 指针。
```

小结：如果 ``const`` 位于 ``*`` 的左侧，则 ``const`` 就是用来修饰指针所指向的变量，即指针指向为常量；如果 ``const`` 位于 ``*`` 的右侧，``const`` 就是修饰指针本身，即指针本身是常量。

具体使用如下：

* 指向常量的指针

```cpp
const int *ptr;
*ptr = 10; //error 表达式必须是可修改的左值
```

ptr 是一个指向 ``int`` 类型 ``const`` 对象的指针，``const`` 定义的是 ``int`` 类型，也就是 ptr 所指向的对象类型，而不是 ptr 本身，所以 ptr 可以不用赋初始值。但是不能通过 ptr 去修改所指对象的值。

除此之外，也不能使用 ``void*`` 指针保存 ``const`` 对象的地址，必须使用 ``const void*`` 类型的指针保存 ``const`` 对象的地址。

```cpp
const int p = 10;
const void *vp = &p;
auto ap = &p;
// void *vp = &p; "const int *" 类型的值不能用于初始化 "void *" 类型的实体
```

**允许把非 const 对象的地址赋给指向 const 对象的指针**

将非 ``const`` 对象的地址赋给 ``const`` 对象的指针:

```cpp
const int *ptr;
int val = 3;
ptr = &val; //ok
```

不能通过 ptr 指针来修改 val 的值，即使它指向的是非 ``const`` 对象。

我们不能使用指向 ``const`` 对象的指针修改基础对象，然而如果该指针指向了非 ``const`` 对象，可用其他方式修改其所指的对象。可以修改 ``const`` 指针所指向的值的，但是不能通过 ``const`` 对象指针来进行而已！如下修改：

```cpp
int *ptr1 = &val;
*ptr1 = 4;
cout << *ptr << endl;
```

* 常指针

``const`` 指针必须进行初始化，且 ``const`` 指针的值不能修改。

```cpp
#include <iostream>

using namespace std;

int main()
{
    const int *ptr;
    // *ptr=10; 表达式必须是可修改的左值

    const int p = 10;
    const void *vp = &p;
    auto ap = &p;
    // void *vp=&p; "const int *" 类型的值不能用于初始化 "void *" 类型的实体

    const int *c_ptr;
    int val = 3;
    c_ptr = &val; // ok
    int *ptr1 = &val;
    *ptr1 = 2;
    cout << ptr << " " << *ptr << endl;
    // 0x7fff60c6d5a0 1
    return 0;
}
```

上述修改 ptr 指针所指向的值，可以通过非 ``const`` 指针来修改。

最后，当把一个 ```const``` 常量的地址赋值给 ptr 时候，由于 ptr 指向的是一个变量，而不是 const 常量，所以会报错，出现：```const int  *-> int * ```错误！

```cpp
#include<iostream>

using namespace std;

int main()
{
    const int num_=0;
    // int* const p_ = &num_; // "const int *" 类型的值不能用于初始化 "int *const" 类型的实体
    return 0;
}
```

上述若改为 ```const int *ptr``` 或者改为 ```const int *const ptr```，都可以正常！

```cpp
#include<iostream>

using namespace std;

int main()
{
    const int num__=1;
    // int* const p__ = &num__; // "const int *" 类型的值不能用于初始化 "int *const" 类型的实体
    const int* const p__=&num__;
    cout << *p__ << endl;
    return 0;
}
```

* 指向常量的常指针

理解完前两种情况，下面这个情况就比较好理解了：

```cpp
#include <iostream>

using namespace std;

int main()
{
    const int p = 3;
    const int *const ptr = &p;
    cout << *ptr << endl;
    return 0;
}
```

ptr 是一个 ```const``` 指针，然后指向了一个 ```int``` 类型的 ```const``` 对象。


---

## 函数中使用 const

```const 修饰函数返回值```

这个跟 ```const``` 修饰普通变量以及指针的含义基本相同：

* ```const int```

```cpp
const int func1();
```

这个本身无意义，因为参数返回本身就是赋值给其他的变量！

* ```const int*```

```cpp
const int* func2();
```

指针指向的内容不变。

* ```int *const```

```cpp
int *const func2();
```

指针本身不可变。

### const 修饰函数参数

* 传递过来的参数及指针本身在函数内不可变，无意义！

```cpp
void func(const int var); // 传递过来的参数不可变
void func(int *const var); // 指针本身不可变
```

表明参数在函数体内不能被修改，但此处没有任何意义，var 本身就是形参，在函数内不会改变。包括传入的形参是指针也是一样。

输入参数采用“值传递”，由于函数将自动产生临时变量用于复制该参数，该输入参数本来就无需保护，所以不要加 ```const``` 修饰。

* 参数指针所指内容为常量不可变

```cpp
void StringCopy(char *dst, const char *src);
```

其中 src 是输入参数，dst 是输出参数。给 src 加上 ```const``` 修饰后，如果函数体内的语句试图改动 src 的内容，编译器将指出错误。这就是加了 ```const``` 的作用之一。

* 参数为引用，为了增加效率同时防止修改

```cpp
void func(const A &a)
```

对于非内部数据类型的参数而言，像 ```void func(A a)``` 这样声明的函数注定效率比较低。因为函数体内将产生 A 类型的临时对象用于复制参数 a，而临时对象的构造、复制、析构过程都将消耗时间。

为了提高效率，可以将函数声明改为 ```void func(A &a)```，因为“引用传递”仅借用一下参数的别名而已，不需要产生临 时对象。

但是函数 ```void func(A &a)``` 存在一个缺点：

```
“引用传递”有可能改变参数 a，这是我们不期望的。解决这个问题很容易，加 const 修饰即可，因此函数最终成为 void func(const A &a)。
```

以此类推，是否应将 ```void func(int x)``` 改写为 ```void func(const int &x)```，以便提高效率？完全没有必要，因为内部数据类型的参数不存在构造、析构的过程，而复制也非常快，“值传递”和“引用传递”的效率几乎相当。

小结：

* 对于非内部数据类型的输入参数，应该将“值传递”的方式改为“const 引用传递”，目的是提高效率。例如将 ```void func(A a)``` 改为 ```void func(const A &a)```
* 对于内部数据类型的输入参数，不要将“值传递”的方式改为“const 引用传递”。否则既达不到提高效率的目的，又降低了函数的可理解性。例如 ```void func(int x)``` 不应该改为 ```void func(const int &x)```

以上解决了两个面试问题：

* 如果函数需要传入一个指针，是否需要为该指针加上 ```const```，把 ```const``` 加在指针不同的位置有什么区别
* 如果写的函数需要传入的参数是一个复杂类型的实例，传入值参数或者引用参数有什么区别，什么时候需要为传入的引用参数加上 ```const```

---

## 类中使用 const

在一个类中，任何不会修改数据成员的函数都应该声明为 ```const``` 类型。如果在编写 ```const``` 成员函数时，不慎修改 数据成员，或者调用了其它非 ```const``` 成员函数，编译器将指出错误，这无疑会提高程序的健壮性。

使用 ```const``` 关键字进行说明的成员函数，称为常成员函数。只有常成员函数才有资格操作常量或常对象，没有使用 ```const``` 关键字进行说明的成员函数不能用来操作常对象。

对于类中的 ```const``` 成员变量必须通过 **初始化列表** 进行初始化，如下所示：

```cpp
class Apple
{
private:
    int people[100];
public:
    Apple(int i); 
    const int apple_number;
};

Apple::Apple(int i):apple_number(i)
{

}
```

```const``` 对象只能访问 ```const``` 成员函数,而非const对象可以访问任意的成员函数,包括 ```const``` 成员函数.

例如：

```cpp
// apple.cpp
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Apple
{
private:
    vector<int> people;

public:
    static const int apple_num = 10;
    Apple(int i);
    void take(int num) const;
    void add(int num);
    void add(int num) const;
    int getCount() const;
};

// main.cpp
#include <iostream>
#include "apple.cpp"

using namespace std;

Apple::Apple(int i) : people(100, 0)
{
    // edit
}

void Apple::add(int num)
{
    this->take(num);
}

void Apple::add(int num) const
{
    this->take(num);
}

void Apple::take(int num) const
{
    cout << "take function " << num << endl;
}

int Apple::getCount() const
{
    this->take(1);
    return this->apple_num;
}

int main()
{
    Apple a(2);
    cout << a.getCount() << endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}
```

此时报错，上面 ```getCount()``` 方法中调用了一个 ```add``` 方法，而 ```add``` 方法并非 ```const``` 修饰，所以运行报错。也就是说 ```const``` 成员函数只能访问 ```const``` 成员函数。

当调用改为：

```cpp
const Apple b(3);
b.add(); // error
```

此时，可以证明的是 ```const``` 对象只能访问 ```const``` 成员函数。

我们除了上述的初始化 ```const``` 常量用初始化列表方式外，也可以通过下面方法：

* 第一：将常量定义与 ```static``` 结合，也就是：

```cpp
static const int apple_number
```

* 第二：在外面初始化：

```cpp
const int Apple::apple_number = 10;
```

当然，如果使用 c++11 进行编译，直接可以在定义出初始化，可以直接写成：

```cpp
static const int apple_number = 10;
// 或者
const int apple_number = 10;
```

这两种都在 c++11 中支持

编译的时候加上 ```-std=c++11``` 即可！

这里提到了 ```static```，下面简单的说一下：

在 C++ 中，```static``` 静态成员变量不能在类的内部初始化。在类的内部只是声明，定义必须在类定义体的外部，通常在类的实现文件中初始化。

在类中声明：

```cpp
static int ap;
```

在类实现文件中使用：

```cpp
int Apple::ap = 666
```

对于此项，c++11 不能进行声明并初始化，也就是上述使用方法。

---

## 总结

```const``` 修饰的变量是不能改变的，注意它与宏的区别，如果要跨文件访问，需要加上 ```extern```

```const``` 定义常量时需要初始化，之后不能再修改

```const``` 在 ```*``` 左侧，指针指向常量(可以不用赋初值)，无法通过指针修改对象；在右侧，指针本身是常量，必须初始化，指针指向的值不可修改，但可以通过非 ```const``` 指针进行修改

```const``` 可以修饰函数返回值，需要注意值传递和引用传递，将参数设置未引用或常引用，可以增加效率

类成员若不对其进行修改，可以将其声明为 ```const``` 类型，常函数才能操作常变量或者常对象，非常函数不行，且在初始化列表中初始化，如果用 ```static``` 修饰，也可以在类外初始化。```static``` 在类内声明，不能在类内初始化

```const``` 对象只能访问常成员函数，而非常对象可以访问任意常成员函数

---
