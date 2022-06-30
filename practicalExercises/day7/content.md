# Day7

运算符重载是 C++ 的一项强大功能。通过重载，可以扩展 C++ 运算符的功能，使它们能够操作用户自定义的数据类型，增加程序代码的直观性和可读性。

本章主要介绍类成员运算符重载与友元运算符重载, 二元运算符与一元运算符重载, 运算符 `++、--、[]、()` 重载，`this` 指针与运算符重载及 流运算符 `<<` 和 `>>` 的重载

一、重载二元运算符

1、二元运算符的调用形式与解析

`aa@bb` 可解释成 `aa.operator@(bb)` 或解释成 `operator@(aa,bb)`

如果两者都有定义，就按照重载解析

```cpp
class X
{
public:
	void operator+(int);
	X(int);
};
void operator+ (X, X);
void operator+ (X, double);
```

2、类运算符重载形式

* 非静态成员运算符重载

以类成员形式重载的运算符参数比实际参数少一个，第 1 个参数是以 `this` 指针隐式传递的。

```cpp
class Complex
{
    double real, image;
public:
    Complex operator+ (Complex b)
    {
        ...
    }
...
};
```

* 友元运算符重载

如果将运算符函数作为类的友元重载，它需要的参数个数就与运算符实际需要的参数个数相同。比如，若用友元函数重载 `Complex` 类的加法运算符，则形式如下：

```cpp
class Complex
{
	friend Complex operator+ (Complex a, Complex b);		// 声明
//......
};

Complex operator+ (Complex a, Complex b)
{
    ...
}     		// 定义
```

二、重载一元运算符

* 一元运算符

一元运算符只需要一个运算参数，如取地址运算符(&)、负数(?)、自增加(++)等

* 一元运算符常见调用形式为：

`@a` 或 `a@` // 隐式调用形式

`a.operator@()` // 显式调用一元运算符 `@`

其中的 `@` 代表一元运算符，`a` 代表操作数

`@a` 代表前缀一元运算，如 `++a`

`a@` 表示后缀运算，如 `a++`

* `@a` 将被 C++ 解释为下面的形式之一

```cp
a.operator@()
operator@(a)
```

* 一元运算符作为类成员函数重载时不需要参数，其形式如下：

```cpp
class X
{
    T operator@()
    {
        ...
    };
};
```

`T` 是运算符 `@` 的返回类型。从形式上看，作为类成员函数重载的一元运算符没有参数，但实际上它包含了一个隐含参数

即调用对象的 `this` 指针

* 前自增(减)与后自增(减)

C++ 编译器可以通过在运算符函数参数表中是否插入关键字 `int` 来区分这两种方式

```cpp
// 前缀
operator -- ();
operator -- (X & x);
// 后缀
operator -- (int);
operator -- (X & x, int);
```

三、重载赋值运算符 =

* 赋值运算符 `=` 的重载特殊性

赋值运算进行时将调用此运算符

只能用成员函数重载

如果需要而没有定义时，编译器自动生成，该版本进行 `bit-by-bit` 拷贝

四、重载赋值运算符 []

* `[]` 是一个二元运算符，其重载形式如下：

```cpp
class X
{
    X& operator[](int n);
};
```

* 重载 `[]` 需要注意的问题
    * `[]` 是一个二元运算符，其第 1 个参数是通过对象的 `this` 指针传递的，第 2 个参数代表数组的下标
    * 由于 `[]` 既可以出现在赋值符 `=` 的左边，也可以出现在赋值符 `=` 的右边，所以重载运算符 `[]` 时常返回引用
    * `[]` 只能被重载为类的非静态成员函数，不能被重载为友元和普通函数

五、重载 ()

* 运算符 `()` 是函数调用运算符，也能被重载。且只能被重载为类的成员函数
* 运算符 `()` 的重载形式如下：

```cpp
class X
{
    X& operator( )(参数表);
};
```

其中的参数表可以包括任意多个参数。

* 运算符 `()` 的调用形式如下：

```cpp
X Obj; // 对象定义
Obj()(参数表); // 调用形式 1
Obj(参数表); // 调用形式 2
```

---

重载等号：

```cpp
#include <iostream>

using namespace std;

class X
{
public:
    X &operator=(const X &x)
    {
        cout << "a:" << endl;
        return *this;
    }
};

int main()
{
    X x1, x2, x3;
    x1 = x2;
    x1.operator=(x2);
    x1 = x2 = x3;

    /*
        a:
        a:
        a:
        a:
    */

    return 0;
}
```

二元运算符：

```cpp
#include <iostream>

using namespace std;

// 复数类 Complex，运算符重载实现加减乘除运算

class Complex
{
private:
    double r;
    double i;

public:
    Complex(double R = 0, double I = 0) : r(R), i(I){};
    Complex operator+(Complex c);
    Complex operator-(Complex c);
    Complex operator*(Complex c);
    Complex operator/(Complex c);
    void display();
};

Complex Complex::operator+(Complex c)
{
    return Complex(this->r + c.r, this->i + c.i);
}
Complex Complex::operator-(Complex c)
{
    return Complex(this->r - c.r, this->i - c.i);
}
Complex Complex::operator*(Complex c)
{
    Complex t;
    t.r = this->r * c.r - this->i * c.i;
    t.i = this->r * c.i + this->i * c.r;
    return i;
}
Complex Complex::operator/(Complex c)
{
    Complex t;
    double x;
    x = 1 / (c.r * c.r + c.i * c.i);
    t.r = x * (this->r * c.r + this->i * c.i);
    t.i = x * (this->i * c.r - this->r * c.i);
    return t;
}

void Complex::display()
{
    cout << this->r;
    if (this->i > 0)
    {
        cout << " + ";
    }
    if (this->i != 0)
    {
        cout << this->i << "i" << endl;
    }
}

int main()
{
    Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
    Complex a, b(2, 3);
    a = b + 2;

    // a = 2 + b; 没有与这些操作数匹配的 "+" 运算符C/C++(349)
    // main.cpp(65, 9): 操作数类型为: int + Complex
    /*
        a ? b
        a.operator?(b);    //类的非静态成员函数
        operator?(a, b);  //友元函数 和 普通函数
    */

    a.display();

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c6 = c1 / c2;

    c3.display();
    c4.display();
    c5.display();
    c6.display();

    /*
        4 + 3i
        4 + 6i
        -2-2i
        20.44 + 0.08i
    */

    return 0;
}
```

```cpp
#include <iostream>

/*
    在C++的标准命名空间 std 中预定义了复数类 Complex，
    并且通过友元重载了 Complex 的各种运算，包括本程序中重载的 +、-、*、/。
    若使用 using namespace std 将 std 名字空间引入本程序，
    则本程序中的 Complex 将与 std 名字空间中的 Complex 类的运算符重载函数产生冲突，引起编译错误。
*/

/*
    对于不要求左值且可以交换参数次序的运算符（如+、-、*、/ 等运算符），
    最好用非成员形式（包括友元和普通函数）的重载运算符函数实现。
*/

// 解决前面的 2 + b 问题。

class Complex
{
private:
    double r;
    double i;

public:
    Complex(double R = 0, double I = 0) : r(R), i(I){};
    friend Complex operator+(Complex a, Complex b);
    friend Complex operator-(Complex a, Complex b);
    friend Complex operator*(Complex a, Complex b);
    friend Complex operator/(Complex a, Complex b);

    friend Complex operator+(Complex a, double b)
    {
        return Complex(a.r + b, a.i);
    }
    friend Complex operator+(double a, Complex b)
    {
        return Complex(a + b.r, b.i);
    }

    void display();
};

Complex operator+(Complex a, Complex b)
{
    return Complex(a.r + b.r, a.i + b.i);
}

Complex operator-(Complex a, Complex b)
{
    return Complex(a.r - b.r, a.i - b.i);
}

Complex operator*(Complex a, Complex b)
{
    Complex t;
    t.r = a.r * b.r - a.i * b.i;
    t.i = a.i * b.i + a.i * b.i;
    return t;
}

Complex operator/(Complex a, Complex b)
{
    Complex t;
    double x;
    x = 1 / (b.r * b.r + b.i * b.i);
    t.r = x * (a.r * b.r + a.i * b.i);
    t.i = x * (a.i * b.r - a.r * b.i);
    return t;
}

void Complex::display()
{
    std::cout << this->r;
    if (this->i > 0)
    {
        std::cout << " + ";
    }
    if (this->i != 0)
    {
        std::cout << this->i << "i" << std::endl;
    }
}

int main()
{
    Complex c1(1, 2), c2(3, 4), c3, c4, c5, c6;
    Complex b(2, 3);
    Complex a1 = b + 2;
    Complex a2 = 2 + b;
    a1.display();
    a2.display();

    c3 = c1 + c2;
    c4 = c1 - c2;
    c5 = c1 * c2;
    c6 = c1 / c2;

    c1.display();
    c2.display();
    c3.display();
    c4.display();
    c5.display();
    c6.display();

    /*
        4 + 3i
        4 + 3i
        1 + 2i
        3 + 4i
        4 + 6i
        -2-2i
        -5 + 16i
        0.44 + 0.08i
    */

    return 0;
}
```

() 运算符：

```cpp
#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void operator()(int h, int m, int s)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void show()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

int main()
{
    Time t(12, 12, 12);
    t.show();
    t.operator()(13, 13, 13);
    t.show();
    t(14, 14, 14);
    t.show();

    /*
        12:12:12
        13:13:13
        14:14:14
    */

    return 0;
}
```

[] 运算符：

```cpp
#include <iostream>
#include <cstring>

using namespace std;

struct Person
{
    double salary;
    char *name;
};

class SalaryManager
{
    Person *employ;
    int max;
    int n;

public:
    SalaryManager(int Max = 0)
    {
        this->max = Max;
        this->n = 0;
        this->employ = new Person[this->max];
    }
    double &operator[](char *Name)
    {
        Person *p;
        for (p = this->employ; p < this->employ + this->n; p++)
            // 如果存在
            if (strcmp(p->name, Name) == 0)
                return p->salary;
        p = this->employ + this->n++;
        p->name = new char[strlen(Name) + 1];
        strcpy(p->name, Name);
        p->salary = 0;
        return p->salary;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << this->employ[i].name << " " << this->employ[i].salary << endl;
        }
    }
};

int main()
{
    SalaryManager s(4);
    s[(char *)"Alex"] = 2020.20;
    s[(char *)"Bob"] = 2021.21;
    s[(char *)"Clax"] = 2022.22;
    s[(char *)"Clax"] = 2023.23;

    cout << "Alex: " << s[(char *)"Alex"] << endl;
    cout << "Bob: " << s[(char *)"Bob"] << endl;
    cout << "Clax: " << s[(char *)"Clax"] << endl;
    cout << "------display()------" << endl;
    s.display();

    /*
        Alex: 2020.2
        Bob: 2021.21
        Clax: 2023.23
        ------display()------
        Alex 2020.2
        Bob 2021.21
        Clax 2023.23
    */

    return 0;
}
```

[] 与 () 运算符：

```cpp
#include <iostream>

using namespace std;

class X
{
public:
    int operator()(int i = 0)
    {
        cout << "X::operator(" << i << ")" << endl;
        return i;
    }
    int operator()(int i, int j)
    {
        cout << "X::operator(" << i << "," << j << ")" << endl;
        return i;
    }
    int operator[](int i)
    {
        cout << "X::operator[" << i << "]" << endl;
        return i;
    }
    int operator[](char *c)
    {
        cout << "X::operator[" << c << "]" << endl;
        return 0;
    }
};

int main()
{
    X obj;
    int i = obj(obj(1), 2);
    int a = obj[i];
    int b = obj[(char *)"abcdefg"];
    cout << "a= " << a << endl;
    cout << "b= " << b << endl;

    /*
        X::operator(1)
        X::operator(1,2)
        X::operator[1]
        X::operator[abcdefg]
        a= 1
        b= 0
    */

    return 0;
}
```

一元运算符：

```cpp
#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s);
    Time operator++();
    friend Time operator--(Time &t);
    void display();
};

Time::Time(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
    if (this->hour >= 24 || this->hour < 0)
    {
        this->hour = 0;
    }
    if (this->minute >= 60 || this->minute < 0)
    {
        this->minute = 0;
    }
    if (this->second >= 60 || this->second < 0)
    {
        this->second = 0;
    }
}

Time Time::operator++()
{
    this->second++;
    if (this->second >= 60)
    {
        this->second = 0;
        this->minute++;
        if (this->minute >= 60)
        {
            this->minute = 0;
            this->hour++;
            if (this->hour >= 24)
            {
                this->hour = 0;
            }
        }
    }
    return *this;
}

Time operator--(Time &t)
{
    t.second--;
    if (t.second < 0)
    {
        t.second = 59;
        t.minute--;
        if (t.minute < 0)
        {
            t.minute = 59;
            t.hour--;
            if (t.hour < 0)
            {
                t.hour = 23;
            }
        }
    }
    return t;
}

void Time::display()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

int main()
{
    Time t1(23, 59, 59);
    t1.display();

    ++t1;
    t1.display();

    t1.operator++();
    t1.display();

    Time t2(24, 60, 60);
    t2.display();

    ++t2;
    t2.display();

    --t2;
    t2.display();

    /*
        23:59:59
        0:0:0
        0:0:1
        0:0:0
        0:0:1
        0:0:0
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Counter
{
private:
    int n;

public:
    Counter(int i = 0) : n(i){};
    Counter operator++();
    Counter operator++(int);
    friend Counter operator--(Counter &c);
    friend Counter operator--(Counter &c, int);
    void display();
};

Counter Counter::operator++()
{
    ++this->n;
    return *this;
}

Counter Counter::operator++(int)
{
    this->n++;
    return *this;
}

Counter operator--(Counter &c)
{
    --c.n;
    return c;
}

Counter operator--(Counter &c, int)
{
    c.n--;
    return c;
}

void Counter::display()
{
    cout << "Counter " << this->n << endl;
}

int main()
{
    Counter c;

    ++c;
    c.display();

    c++;
    c.display();

    --c;
    c.display();

    c--;
    c.display();

    /*
        Counter 1
        Counter 2
        Counter 1
        Counter 0
    */

    return 0;
}
```

综合案例：

```cpp
#include <iostream>
#include <cstring>

using namespace std;

// 设计一个字符串类String，通过运算符重载实现字符串的输入、输出以及+=、==、!=、<、>、>=、[ ]等运算
class String
{
private:
    int length;
    char *sPtr;
    void setString(const char *s2);
    friend ostream &operator<<(ostream &os, const String &s)
    {
        return os << s.sPtr;
    }

    friend istream &operator>>(istream &is, String &s)
    {
        return is >> s.sPtr;
    }

public:
    String(const char * = "");
    const String &operator=(const String &R)
    {
        this->length = R.length;
        strcmp(this->sPtr, R.sPtr);
        return *this;
    }
    const String &operator+=(const String &R);
    bool operator==(const String &R);
    bool operator!=(const String &R);
    bool operator!();
    bool operator<(const String &R) const;
    bool operator>(const String &R);
    bool operator>=(const String &R);
    char &operator[](int);
    ~String(){};
};

const String &String::operator+=(const String &R)
{
    char *tmp = this->sPtr;
    this->length += R.length;
    this->sPtr = new char[this->length + 1];
    strcpy(this->sPtr, tmp);
    strcat(this->sPtr, R.sPtr);
    delete[] tmp;
    return *this;
}

String::String(const char *str)
{
    this->sPtr = new char[strlen(str) + 1];
    strcpy(this->sPtr, str);
    this->length = strlen(str);
}

bool String::operator==(const String &R)
{
    return strcmp(this->sPtr, R.sPtr) == 0;
}
bool String::operator!=(const String &R)
{
    return !(*this == R);
}
bool String::operator!()
{
    return this->length == 0;
}
bool String::operator<(const String &R) const
{
    return strcmp(this->sPtr, R.sPtr) < 0;
}
bool String::operator>(const String &R)
{
    return R < *this;
}
bool String::operator>=(const String &R)
{
    return !(*this < R);
}
char &String::operator[](int sub)
{
    return this->sPtr[sub];
}

int main()
{
    String s1("happy"), s2("new year"), s3;
    cout << "s1 is " << s1 << "\ns2 is " << s2 << "\ns3 is " << s3
         << "\n比较s2和s1:"
         << "\ns2 ==s1结果是 " << (s2 == s1 ? "true" : "false")
         << "\ns2 != s1结果是 " << (s2 != s1 ? "true" : "false")
         << "\ns2 >  s1结果是 " << (s2 > s1 ? "true" : "false")
         << "\ns2 <  s1结果是 " << (s2 < s1 ? "true" : "false")
         << "\ns2 >= s1结果是 " << (s2 >= s1 ? "true" : "false");
    cout << "\n\n测试s3是否为空: ";
    if (!s3)
    {
        cout << "s3是空串" << endl; // L3
        cout << "把s1赋给s3的结果是：";
        s3 = s1;
        cout << "s3=" << s3 << "\n"; // L5
    }
    cout << "s1 += s2 的结果是：s1="; // L6
    s1 += s2;
    cout << s1; // L7

    cout << "\ns1 +=  to you 的结果是："; // L8
    s1 += " to you";
    cout << "s1 = " << s1 << endl; // L9
    s1[0] = 'H';
    s1[6] = 'N';
    s1[10] = 'Y';
    cout << "s1 = " << s1 << "\n"; // L10

    /*
        s1 is happy
        s2 is new year
        s3 is
        比较s2和s1:
        s2 ==s1结果是 false
        s2 != s1结果是 true
        s2 >  s1结果是 true
        s2 <  s1结果是 false
        s2 >= s1结果是 true

        测试s3是否为空: s3是空串
        把s1赋给s3的结果是：s3=
        s1 += s2 的结果是：s1=happynew year
        s1 +=  to you 的结果是：s1 = happynew year to you
        s1 = HappynNw yYar to you
    */

    return 0;
}
```

---
