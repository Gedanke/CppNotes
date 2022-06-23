# static

当与不同类型一起使用时，```static``` 关键字具有不同的含义。我们可以使用 ```static``` 关键字：

* 静态变量：函数中的变量，类中的变量
* 静态类的成员：类对象和类中的函数

## 静态变量

```
函数中的静态变量
```

当变量声明为 ```static``` 时，空间将在程序的生命周期内分配。即使多次调用该函数，静态变量的空间也只分配一次，前一次调用中的变量值通过下一次函数调用传递。这对于在 C/C++ 或需要存储先前函数状态的任何其他应用程序非常有用。

```cpp
#include <iostream>

using namespace std;

void demo()
{
    static int count = 0;
    cout << count << " ";
    count++;
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        demo();
    }
    cout << endl;
    // 0 1 2 3 4
    return 0;
}
```

可以在上面的程序中看到变量 ```count``` 被声明为 ```static```。因此，它的值通过函数调用来传递。每次调用函数时，都不会对变量计数进行初始化。

---

## 类中的静态变量

由于声明为 ```static``` 的变量只被初始化一次，因为它们在单独的静态存储中分配了空间，因此类中的静态变量 **由对象共享**。对于不同的对象，不能有相同静态变量的多个副本。也是因为这个原因，静态变量不能使用 **构造函数** 初始化。

```cpp
#include <iostream>

using namespace std;

class Apple
{
public:
    static int i;
    Apple()
    {
    }
};

int main()
{
    Apple apple1;
    Apple apple2;

    apple1.i = 2;
    apple2.i = 3;

    cout << apple1.i << " " << apple2.i << endl;
    /*
        /usr/bin/ld: /tmp/ccauVA3a.o: in function `main':
        main.cpp:(.text+0x35): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x3f): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x49): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x6f): undefined reference to `Apple::i'
        collect2: error: ld returned 1 exit status
    */
    return 0;
}
```

可以在上面的程序中看到我们已经尝试为多个对象创建静态变量i的多个副本。但这并没有发生。因此，类中的静态变量应由用户使用类外的类名和范围解析运算符显式初始化，如下所示：

```cpp
#include <iostream>

using namespace std;

class Apple
{
public:
    static int i;
    Apple()
    {
    }
};

int Apple::i = 0;

int main()
{
    Apple appple;
    cout<<appple.i<<endl;
    /*
        0
    */
    return 0;
}
```

---

## 静态成员

```
类对象为静态
```

就像变量一样，对象也在声明为 ```static``` 时具有范围，直到程序的生命周期。

考虑以下程序，其中对象是非静态的。

```cpp
#include <iostream>

using namespace std;

class Apple
{
private:
    int i;

public:
    Apple()
    {
        this->i = 0;
        cout << "Inside Constructor" << endl;
    }
    ~Apple()
    {
        cout << "Inside Destructor" << endl;
    }
};

int main()
{
    int x = 0;
    if (x == 0)
    {
        Apple apple;
    }
    cout << "End of main" << endl;
    /*
        Inside Constructor
        Inside Destructor
        End of main
    */
    return 0;
}
```

在上面的程序中，对象在 ```if``` 块内声明为非静态。因此，变量的范围仅在 ```if``` 块内。因此，当创建对象时，将调用构造函数，并且在 ```if``` 块的控制权越过析构函数的同时调用，因为对象的范围仅在声明它的 ```if``` 块内。 如果我们将对象声明为静态，现在让我们看看输出的变化。

```cpp
#include <iostream>

using namespace std;

class Apple
{
private:
    int i;

public:
    Apple()
    {
        this->i = 0;
        cout << "Inside Constructor" << endl;
    }
    ~Apple()
    {
        cout << "Inside Destructor" << endl;
    }
};

int main()
{
    int x = 0;
    if (x == 0)
    {
        static Apple apple;
    }
    cout << "End of main" << endl;
    /*
        Inside Constructor
        End of main
        Inside Destructor
    */
    return 0;
}
```

可以清楚地看到输出的变化。现在，在 ```main``` 结束后调用析构函数。这是因为静态对象的范围是贯穿程序的生命周期。

---

## 类中的静态函数

就像类中的静态数据成员或静态变量一样，静态成员函数也不依赖于类的对象。我们被允许使用对象和 ```.``` 来调用静态成员函数。但建议使用类名和范围解析运算符调用静态成员。

允许静态成员函数仅访问静态数据成员或其他静态成员函数，它们无法访问类的非静态数据成员或成员函数。

```cpp
#include <iostream>

using namespace std;

class Apple
{
public:
    static void msg()
    {
        cout << "Welcome to Apple" << endl;
    }
};

int main()
{
    Apple::msg();
    // Welcome to Apple
    return 0;
}
```

---

## 限定访问范围 

```static``` 还有限定访问范围的作用(类似于匿名名字空间)

```cpp
// source.cpp
#include <cstdio>

extern char *msg;

void sayHello()
{
    printf("%s", msg);
}

// main.cpp
#include <iostream>

using namespace std;

extern void sayHello();
const char *msg = "hello world!\n";

int main()
{
    sayHello();
    // hello world!
    return 0;
}
```

g++ 对于上面两个代码文件是可以正常编译并且打印 ```Hello World!```，但如果给 ```main.cpp``` 中的 msg 加上 ```static```，则会导致 ```undefined reference to 'msg'``` 的编译错误：

```cpp
#include <iostream>

using namespace std;

extern void sayHello();
static const char *msg = "hello world!\n";

int main()
{
    sayHello();
    /*
        /usr/bin/ld: /tmp/ccc7xbbT.o: in function `sayHello()':
        source.cpp:(.text+0xb): undefined reference to `msg'
        collect2: error: ld returned 1 exit status
    */
    return 0;
}
```

---

## 总结

```static``` 静态变量，程序生命周期中只分配一次，在类中，不同对象共享一份，不能在构造函数中初始化，应该在类外显式初始化

类中静态成员不依赖于对象，可以使用 ```对象.静态成员``` 或者 ```类名::静态成员```

```this``` 只能用于非静态成员函数内部，因此静态成员函数只能访问静态函数或者成员，无法访问非静态函数于成员；而非静态函数则都可以访问所有成员

```static``` 还有限制范围范围的作用，类似于匿名空间

---
