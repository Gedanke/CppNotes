# Day8

模板(template)是 C++ 实现代码重用机制的重要工具，是泛型技术(即与数据类型无关的通用程序设计技术)的基础。模板是 C++ 中相对较新的语言机制，它实现了与具体数据类型无关的通用算法程序设计，能够提高软件开发的效率，是程序代码复用的强有力工具。

本章主要介绍了函数模板和类模板两类，以及 STL 库中的几个常用模板数据类型。 

一、模板 

1、模板概念 

模板是对具有相同特性的函数或类的再抽象，模板是一种参数多态性的工具，可以为逻辑功能相同而类型不同的程序提供一种代码共享的机制。一个模板并非一个实实在在的函数或类，仅仅是一个函数或类的描述，是参数化的函数和类

2、模板分类 函数模板 类模板

3、函数模板与模板函数 

函数模板提供了一种通用的函数行为，该函数行为可以用多种不同的数据类型进行调用，编译器会据调用类型自动将它实例化为具体数据类型的函数代码，也就是说函数模板代表了一个函数家族。与普通函数相比，函数模板中某些函数元素的数据类型是未确定的，这些元素的类型将在使用时被参数化；与重载函数相比，函数模板不需要程序员重复编写函数代码，它可以自动生成许多功能相同但参数和返回值类型不同的函数。 

二、函数模板 

函数模板的定义

```cpp
template <class T1, class T2, ...>返回类型 函数名(参数表)
{
    // 函数模板定义体
}
```

`template` 是定义模板的关键字；写在一对 `<>` 中的 `T1, T2, ...` 是模板参数，其中的 `class` 表示其后的参数可以是任意类型。 

模板参数常称为类型参数或类属参数，在模板实例化(即调用模板函数时)时需要传递的实参是一种数据类型，如 `int` 或 `double` 之类。 

函数模板的参数表中常常出现模板参数，如 `T1, T2` 

* 在定义模板时，不允许 `template` 语句与函数模板定义之间有任何其他语句。

```cpp
template <class T>
int x;                 // 错误，不允许在此位置有任何语句
T min(T a, T b){...}
```

* 函数模板可以有多个类型参数，但每个类型参数都必须用关键字 `class` 或 `typename` 限定。此外，模板参数中还可以出现确定类型参数，称为非类型参数。

例：

```cpp
template <class T1, class T2, class T3, int T4>
T1 fx(T1 a, T 2 b, T3 c){...}
```

* 在传递实参时，非类型参数 `T4` 只能使用常量

不要把这里的 `class` 与类的声明关键字 `class` 混淆在一起，虽然它们由相同的字母组成，但含义是不同的。这里的 `class `表示 T 是一个类型参数，可以是任何数据类型，如 `int、float、char` 等，或者用户定义的 `struct、enum` 或 `class` 等自定义数据类型

* 为了区别类与模板参数中的类型关键字 `class`，标准 C++ 提出了用 `typename` 作为模板参数的类型关键字，同时也支持使用 `class`。比如，把 `min` 定义的 `template` 写成下面的形式是完全等价的：

```cpp
template <typename T> 
T min(T a, T b){...}
```

函数模板的实例化

* 实例化发生的时机。模板实例化发生在调用模板函数时。当编译器遇到程序中对函数模板的调用时，它才会根据调用语句中实参的具体类型，确定模板参数的数据类型，并用此类型替换函数模板中的模板参数，生成能够处理该类型的函数代码，即模板函数
* 当多次发生类型相同的参数调用时，只在第1次进行实例化。假设有下面的函数调用：

```cpp
int x = min(2,3);     
int y = min(3,9);
int z = min(8.5);
```

编译器只在第 1 次调用时生成模板函数，当之后遇到相同类型的参数调用时，不再生成其他模板函数，它将调用第 1 次实例化生成的模板函数。

* 实例化的方式

隐式实例化

编译器能够判断模板参数类型时，自动实例化函数模板为模板函数

```cpp
template <typename T> T max (T, T);
// ...
int i = max (1, 2); 
float f = max (1.0, 2.0);
char ch = max (‘a’, ‘A’);
// ...
```

隐式实例化，表面上是在调用模板，实际上是调用其实例

显示实例化 `explicit instantiation` 时机,编译器不能判断模板参数类型或常量值 需要使用特定数据类型实例化 语法形式:: `模板名称<数据类型, ..., 常量值, ...> (参数)`

```cpp
template <class T> T max (T, T);
// ...
int i = max (1, ‘2’); 
// error: data type can’t be deduced
int i = max<int> (1, ‘2’);
// ...
```

4. 函数模板的特化

* 特化的原因 但在某些情况下，模板描述的通用算法不适合特定的场合(数据类型等)比如：如 `max` 函数

```cpp
char * cp = max ("abcd", "1234");
```

实例化为：

```cpp
char * max (char * a, char * b)
{
    return a > b ? a : b;
}
```

这肯定是有问题的，因为字符串的比较为：

```cpp
char * max (char * a, char * b)
{	
    return strcmp(a, b)>0 ? a : b;   
}
```

* 特化。所谓特化，就是针对模板不能处理的特殊数据类型，编写与模板同名的特殊函数专门处理这些数据类型。 模板特化的定义形式：

```cpp
template <> 返回类型 函数名<特化的数据类型>(参数表) 
{
    ...
}
``` 

说明： `template <>` 是模板特化的关键字，`<>` 中不需要任何内容；数名后的 `<>` 中是需要特化处理的数据类型

**说明** 

* 当程序中同时存在模板和它的特化时，特化将被优先调用
* 在同一个程序中，除了函数模板和它的特化外，还可以有同名的普通函数。其区别在于 C++ 会对普通函数的调用实参进行隐式的类型转换，但不会对模板函数及特化函数的参数进行任何形式的类型转换

**调用顺序**

当同一程序中具有模板与普通函数时，其匹配顺序如下： 

```text
完全匹配的非模板函数 完全匹配的模板函数 类型相容的非模板函数 
```

**类模板** 

类模板的概念 

类模板可用来设计结构和成员函数完全相同，但所处理的数据类型不同的通用类。如栈，存在双精度栈：

```cpp
class doubleStack
{
private:
    double data[size];
    // ...
};
```

字符栈：

```cpp
class charStack
{
private:
    char data[size];
    // ...
};
```

这些栈除了数据类型之外，操作完全相同，就可用类模板实现。

类模板的声明

```cpp
template<class T1, class T2, ...>
class 类名
{
    ... // 类成员的声明与定义
}
```

其中 `T1、T2` 是类型参数 类模板中可以有多个模板参数，包括类型参数和非类型参数

**非类型参数**

非类型参数是指某种具体的数据类型，在调用模板时只能为其提供用相应类型的常数值。非类型参数是受限制的，通常可以是整型、枚举型、对象或函数的引用，以及对象、函数或类成员的指针，但不允许用浮点型(或双精度型)、类对象或 `void` 作为非类型参数。

在下面的模板参数表中，`T1、T2` 是类型参数，`T3` 是非类型参数。

```cpp
template<class T1,class T2,int T3>
```

在实例化时，必须为 `T1、T2` 提供一种数据类型，为 `T3` 指定一个整常数(如 10)，该模板才能被正确地实例化。

类模板的成员函数的定义 

* 方法 1：在类模板外定义，语法 `template <模板参数列表> 返回值类型 类模板名<模板参数名表>::成员函数名 (参数列表){...};` 
* 方法 2：成员函数定义，与常规成员函数的定义类似，另外 “模板参数列表”引入的“类型标识符”作为数据类型使用 “模板参数列表”引入的“普通数据类型常量”作为常量使用 

**类模板特化**

解决的方法是特化。即用与该模板相同的名字为某种数据类型专门重写一个模板类。 

类模板有两种特化方式：一种是特化整个类模板，另一种是特化个别成员函数 特化成员函数的方法：

```cpp
template <> 返回类型 类模板名<特化的数据类型>::特化成员函数名(参数表)
{
   ... // 函数定义体
}
```

```cpp
template <>
void Array<char *>::Sort()
{
    for (int i = 0; i < Size - 1; i++)
    {
        int p = i;
        for (int j = i + 1; j < Size; j++)
            if (strcmp(a[p], a[j]) < 0)
                p = j;
        char *t = a[p];
        a[p] = a[i];
        a[i] = t;
    }
}
```

---

class:

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int Size = 5;
template <class T>
class Array
{
private:
    T a[Size];

public:
    Array()
    {
        for (int i = 0; i < Size; i++)
        {
            this->a[i] = 0;
        }
    }
    T &operator[](int i);
    void Sort();
};

template <class T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i > Size - 1)
    {
        cout << "\n error" << endl;
        exit(1);
    }
    return this->a[i];
}

template <class T>
void Array<T>::Sort()
{
    int p;
    for (int i = 0; i < Size - 1; i++)
    {
        p = i;
        for (int j = i; j < Size; j++)
        {
            if (this->a[p] < this->a[j])
            {
                p = j;
            }
        }
        T t = this->a[p];
        this->a[p] = a[i];
        this->a[i] = t;
    }
}

template <>
void Array<char *>::Sort()
{
    int p;
    for (int i = 0; i < Size - 1; i++)
    {
        p = i;
        for (int j = i; j < Size; j++)
        {
            if (strcmp(this->a[p], this->a[j]) < 0)
            {
                p = j;
            }
        }
        char *t = this->a[p];
        this->a[p] = a[i];
        this->a[i] = t;
    }
}

int main()
{
    Array<int> a1;
    Array<char *> b1;
    a1[0] = 1;
    a1[1] = 23;
    a1[2] = 6;
    a1[3] = 3;
    a1[4] = 9;
    a1.Sort();
    for (int i = 0; i < 5; i++)
    {
        cout << a1[i] << "\t";
    }
    cout << endl;
    b1[0] = (char *)"x1";
    b1[1] = (char *)"ya";
    b1[2] = (char *)"ad";
    b1[3] = (char *)"be";
    b1[4] = (char *)"bc";
    b1.Sort();
    for (int i = 0; i < 5; i++)
    {
        cout << b1[i] << "\t";
    }
    cout << endl;

    /*
        23      9       6       3       1
        ya      x1      be      bc      ad
     */

    return 0;
}
```

map:

```cpp
#include <iostream>
#include <string>
#include <map>

using namespace std;

void test()
{
    string name[] = {
        "wanger", "zhangsan", "lisi"};
    double salary[] = {
        1200, 2000, 3000};
    map<string, double> sal;
    map<string, double>::iterator p;
    for (int i = 0; i < 3; i++)
    {
        sal.insert(make_pair(name[i], salary[i]));
    }
    sal["tom"] = 3400;
    sal["bob"] = 3100;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        cout << p->first << "\t" << p->second << endl;
    }
    string person;
    cout << "find person" << endl;
    cin >> person;
    int flag = 1;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        if (p->first == person)
        {
            cout << p->second << endl;
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "No result" << endl;
    }
    cout << "delete person" << endl;
    cin >> person;
    map<string, double>::iterator it;
    it = sal.find(person);
    if (it != sal.end())
    {
        cout << "find successfully" << (*it).first << ":" << (*it).second << endl;
        sal.erase(it);
        cout << "delete successfully" << endl;
    }
    cout << "result" << endl;
    for (p = sal.begin(); p != sal.end(); p++)
    {
        cout << p->first << " : " << p->second << endl;
    }
}

int main()
{
    test();

    /*
        bob     3100
        lisi    3000
        tom     3400
        wanger  1200
        zhangsan        2000
        find person
        bob
        3100
        delete person
        tom
        find successfullytom:3400
        delete successfully
        result
        bob : 3100
        lisi : 3000
        wanger : 1200
        zhangsan : 2000
    */

    return 0;
}
```

stack:

```cpp
#include <iostream>

using namespace std;

template <class T, int MAXSIZE>
class Stack
{
private:
    T elem[MAXSIZE];
    int top;

public:
    Stack()
    {
        this->top = 0;
    }
    void push(T e);
    T pop();
    bool empty()
    {
        if (this->top <= -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void setEmpty()
    {
        this->top = -1;
    }
    bool full()
    {
        if (this->top >= MAXSIZE - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

template <class T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (this->full())
    {
        cout << "stack full!";
        return;
    }
    this->elem[++top] = e;
}

template <class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (this->empty())
    {
        cout << "stack empty!" << endl;
        return 0;
    }
    return this->elem[top--];
}

int main()
{
    Stack<int, 10> istack;
    Stack<char, 10> cstack;
    istack.setEmpty();
    cstack.setEmpty();
    cout << "int stack" << endl;
    int i;
    for (i = 1; i < 11; i++)
    {
        istack.push(i);
    }
    for (i = 1; i < 11; i++)
    {
        cout << istack.pop() << "\t";
    }

    cout << "\n"
         << "char stack" << endl;
    cstack.push('A');
    cstack.push('B');
    cstack.push('C');
    cstack.push('D');
    cstack.push('E');

    for (i = 1; i < 6; i++)
    {
        cout << cstack.pop() << "\t";
    }
    cout << endl;
    /*
        int stack
        10      9       8       7       6       5       4       3       2       1
        char stack
        E       D       C       B       A
    */

    return 0;
}
```

template:

```cpp
#include <iostream>

using namespace std;

template <class T>
// 降序排列
void sort(T *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i; j < n; j++)
        {
            if (t[p] < t[j])
            {
                p = j;
            }
        }
        T tmp = t[i];
        t[i] = t[p];
        t[p] = tmp;
    }
}

template <class T>
void display(T &t, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[] = {2, 3, 7, 1, 9, 4, 5, 8, 6};
    char b[] = {'a', 'c', 'g', 'f', 'b', 'd', 'e'};
    sort(a, 9);
    sort(b, 8);
    display(a, 9);
    display(b, 8);

    /*
        9 8 7 6 5 4 3 2 1
        g f e d c b a
    */

    return 0;
}
```

```cpp
#include <iostream>
#include <cstring>

using namespace std;

template <class T>

T Max(T a, T b)
{
    return (a > b) ? a : b;
}

template <>
char *Max<char *>(char *a, char *b)
{
    return (strcmp(a, b) >= 0) ? a : b;
}

int main()
{
    float c = 5.1, d = 3.2;
    cout << "2,3的最大值是：" << Max(3, 2) << endl;
    cout << "c,d的最大值是：" << Max(c, d) << endl;
    cout << Max("xbv", "xyce") << endl;

    /*
        2,3的最大值是：3
        c,d的最大值是：5.1
        xbv
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

template <class T>
T Max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    double a = 2, b = 3.4;
    float c = 5.1, d = 3.2;
    //在模板调用时进行参数类型的强制转换
    cout << "2, 3.2    的最大值是：" << Max(double(2), 3.2) << endl;
    cout << "a, c    的最大值是：" << Max(float(a), c) << endl;
    //显示指定函数模板实例化的参数类型
    cout << "'a', 3    的最大值是：" << Max<int>('a', 3) << endl;

    /*
        2, 3.2    的最大值是：3.2
        a, c    的最大值是：5.1
        'a', 3    的最大值是：97
        sh: 1: pause: not found
    */

    return 0;
}
```

```cpp
#include <iostream>

//注意一点，max与min使用的时候，容易引起冲突，如果写了下面这一行代码，则要改变函数模板名字，否则直接使用std::cout与std::endl
using namespace std;

/*
    不要把这里的class与类的声明关键字class混淆在一起，虽然它们由相同的字母组成，但含义是不同的。
    这里的class表示T是一个类型参数，可以是任何数据类型，如int、float、char等，或者用户定义的struct、enum或class等自定义数据类型。
*/

template <class T>
T Min(T a, T b)
{
    return (a < b) ? a : b;
}

/*
    为了区别类与模板参数中的类型关键字class，标准C++提出?了用typename作为模板参数的类型关键字，同时也支持使用class。
    比如，把min定义的template <class T>写成下面的形式是完全等价的：
*/

template <typename T>
T myMin(T a, T b)
{
    return (a < b) ? a : b;
}

/*
    模板实例化发生在调用模板函数时。当编译器遇到程序中对函数模板的调用时，
    它才会根据调用语句中实参的具体类型，确定模板参数的数据类型，
    并用此类型替换函数模板中的模板参数，生成能够处理该类型的函数代码，即模板函数。
    当多次发生类型相同的参数调用时，只在第1次进行实例化。编译器只在第 1 次调用时生成模板函数，
    当之后遇到相同类型的参数调用时，不再生成其他模板函数，它将调用第 1 次实例化生成的模板函数。
*/

int main()
{
    double a = 2, b = 3.4;
    float c = 2.3, d = 3.2;
    cout << "2，3 的最小值是：" << Min<int>(2, 3) << endl; //显式调用
    cout << "2，3.4 的最小值是：" << Min(a, b) << endl;    //隐式调用
    cout << "'a'，'b' 的最小值是：" << Min('a', 'b') << endl;
    cout << "2.3，3.2 的最小值是：" << Min(c, d) << endl;
    cout << "2.3，3.2 的最大值是：" << std::min(c, d) << endl; //引用命名空间内部的最小值函数
    cout << "2.3，3.2 的最小值是：" << myMin(c, d) << endl;    //更换class为typename
    // cout<<"2，'a'    的最小值是："<<Min(2,'a')<<endl; //报错,不同类型无法处理

    /*
        2，3 的最小值是：2
        2，3.4 的最小值是：2
        'a'，'b' 的最小值是：a
        2.3，3.2 的最小值是：2.3
        2.3，3.2 的最大值是：2.3
        2.3，3.2 的最小值是：2.3
    */

    return 0;
}
```

---
