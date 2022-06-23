# struct

---

## C 中 struct

* 在 C 中 ```struct``` 只单纯的用作数据的复合类型，也就是说，在结构体声明中只能将数据成员放在里面，而不能将函数放在里面
* 在 C 结构体声明中不能使用 C++ 访问修饰符，如：```public、protected、private``` 而在 C++ 中可以使用
* 在 C 中定义结构体变量，如果使用了下面定义必须加 ```struct```
* C 的结构体不能继承(没有这一概念)
* 若结构体的名字与函数名相同，可以正常运行且正常的调用。例如：可以定义与 ```struct Base``` 不冲突的 ```void Base() {}```

demo:

```c
#include <stdio.h>

struct Base
{ // public
    int v1;
    //    public:      //error
    int v2;
    // private:
    int v3;
    // void print(){       // c中不能在结构体中嵌入函数
    //     printf("%s\n","hello world");
    // };    //error!
};

void Base()
{
    printf("%s\n", "I am Base func");
}

// struct Base base1;  //ok
// Base base2; //error

int main()
{
    struct Base base;
    base.v1 = 1;
    // base.print();
    printf("%d\n", base.v1);
    Base();

    /*
        1
        I am Base func
    */

    return 0;
}
```

---

## C++ 中 struct

与 C 对比如下：

* C++ 结构体中不仅可以定义数据，还可以定义函数
* C++ 结构体中可以使用访问修饰符，如：```public、protected、private```
* C++ 结构体使用可以直接使用不带 ```struct```
* C++ 继承
* 若结构体的名字与函数名相同，可以正常运行且正常的调用。但是定义结构体变量时候只能用带 ```struct``` 的

例如：

情形 1：不适用 ```typedef``` 定义结构体别名

```cpp
struct Student
{
};
// Student(){}
struct Student s; // ok
Student s;        // ok
```

添加同名函数后：

```cpp
struct Student
{
};

Student() {} // 应输入标识符
struct Student s; // 应输入“;”
Student s;  
```

情形 2：使用 ```typedef``` 定义结构体别名

```cpp
typedef struct Base1
{
    int v1;
    int v3;

public: //显示声明public
    int v2;
    void print()
    {
        printf("%s\n", "hello world");
    };
} B;
void B() {} // error! 符号 "B" 已经被定义为一个 "struct Base1" 的别名
```

前三种案例

```cpp
#include <iostream>

using namespace std;

struct Base
{
    int v1;
    int v2;

public:
    int v3;
    void print()
    {
        cout << "Base" << endl;
    }
};

int main()
{
    struct Base base1;
    Base base2;
    Base base;
    base.v1 = 1;
    base.v3 = 3;
    base.print();
    cout << base.v1 << endl;
    cout << base.v3 << endl;
    // Base
    // 1
    // 3
}
```

继承案例

```cpp
#include <iostream>
#include <stdio.h>

using namespace std;

struct Base
{
    int v1;
    int v3;

public:
    int v2;
    virtual void print()
    {
        cout << "Base" << endl;
    };
    Base()
    {
        cout << "Base construct" << endl;
    };
    virtual ~Base()
    {
        cout << "Base deconstruct" << endl;
    };
};

struct Derived : Base
{
    Derived()
    {
        cout << "Derived construct" << endl;
    };
    virtual ~Derived()
    {
        cout << "Derived deconstruct" << endl;
    };

public:
    int v2;
    void print()
    {
        cout << "Derived" << endl;
    };
};

int main()
{
    Base *b = new Derived();
    b->print();
    delete b;

    /*
        Base construct
        Derived construct
        Derived
        Derived deconstruct
        Base deconstruct
    */

    return 0;
}
```

同名函数

```cpp
#include <iostream>

using namespace std;

struct Base
{
    int v1;
    int v3;

public:
    int v2;
    void print()
    {
        cout << "Base" << endl;
    }
};

typedef struct Base1
{
    int v1;
    int v3;

public:
    int v2;
    void print()
    {
        cout << "Base1" << endl;
    }
} B;

void Base()
{
    cout << "void Base" << endl;
}

int main()
{
    struct Base base;
    base.v1 = 1;
    base.v3 = 3;
    base.print();
    cout << base.v1 << endl;
    cout << base.v3 << endl;
    Base();
    // Base
    // 1
    // 3
    // void Base
}
```

---

## 总结

C 和 C++ 中的 ```struct``` 区别

|||
|:----:|:----:|
| C | C++ |
| 不能将函数放在结构体声明 | 能将函数放在结构体声明 |
| 在 C 结构体声明中不能使用 C++ 访问修饰符 | ```public、protected、private``` 在 C++ 中可以使用 |
| 在 C 中定义结构体变量，如果使用了下面定义必须加 ```struct``` | 可以不加 ```struct``` |
| 结构体不能继承(没有这一概念) | 可以继承 |
| 若结构体的名字与函数名相同，可以正常运行且正常的调用 | 若结构体的名字与函数名相同，使用结构体，只能使用带 ```struct``` 定义 |

---
