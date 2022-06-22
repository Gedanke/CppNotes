# decltype

---

## 基本使用

```decltype``` 的语法是:

```cpp
decltype (expression)
```

这里的括号是必不可少的，```decltype``` 的作用是“查询表达式的类型”，因此，上面语句的效果是，返回 ```expression``` 表达式的类型。注意，```decltype``` 仅仅“查询”表达式的类型，并不会对表达式进行“求值”。

```auto``` 和 ```decltype``` 关键字都可以自动推导出变量的类型，但它们的用法是有区别的：

```cpp
auto varname = value;
decltype(exp) varname = value;
```

其中，```varname``` 表示变量名，```value``` 表示赋给变量的值，```exp``` 表示一个表达式。

```auto``` 根据 =右边的初始值 ```value``` 推导出变量的类型，而 ```decltype``` 根据 ```exp``` 表达式推导出变量的类型，跟 = 右边的 ```value``` 没有关系。

另外，```auto``` 要求变量必须初始化，而 ```decltype``` 不要求。这很容易理解，```auto``` 是根据变量的初始值来推导出变量类型的，如果不初始化，变量的类型也就无法推导了。 ```decltype``` 可以写成下面的形式：

```cpp
decltype(exp) varname;
```

demo:

```cpp
#include <iostream>

using namespace std;

int main()
{
    // decltype(exp) varname;

    // exp 为 int，a 为 int
    decltype(1 + 1) a = 1;
    // exp 为 int，b 为 int
    decltype(1 + 1) b = 1.1;
    // exp 为 double，c 为 double
    decltype(1.1 + 1.1) c = 1;
    // exp 为 double，a 为 double
    decltype(1.1 + 2.2) d = 1.1;

    // decltype exp 不会求值
    decltype('c' - 'a') e = 'f';
    decltype('a' + 2) f = 'f';

    // exp 为 char，g，h 都为 char
    decltype('c') g = 98;
    decltype('c') h = 'a';

    // c 输出
    printf("%d %d %f %f %d %c %c %c\n", a, b, c, d, e, f, g, h);
    // c++ 输出
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << endl;

    return 0;
}
```

### 推导出表达式类型

```cpp
int i = 4;
decltype(i) a; // 推导结果为 int。a 的类型为 int。
```

### 与 using/typedef 合用，用于定义类型

```cpp
using size_t = decltype(sizeof(0)); // sizeof(a) 的返回值为 size_t 类型
using ptrdiff_t = decltype((int *)0 - (int *)0);
using nullptr_t = decltype(nullptr);
vector<int> vec;
typedef decltype(vec.begin()) vectype;
for (vectype i = vec.begin(); i != vec.end(); i++)
{
    //...
}
```    

这样和 ```auto``` 一样，也提高了代码的可读性。

### 重用匿名类型

在 C++ 中，有时候会遇上一些匿名类型，如:

```cpp
struct 
{
    int d ;
    double b;
}anon_s;
```

而借助 ```decltype```，我们可以重新使用这个匿名的结构体：

```cpp
decltype(anon_s) as;//定义了一个上面匿名的结构体
```

### 泛型编程中结合 auto，用于追踪函数的返回值类型

这也是 ```decltype``` 最大的用途了。

```cpp
template <typename T>
auto multiply(T x, T y) -> decltype(x * y)
{
    return x * y;
}
```

demo:

```cpp
#include <iostream>
#include <vector>

using namespace std;

template <typename T>

auto multiply(T x, T y) -> decltype(x * y)
{
    return x * y;
}

int main()
{
    int nums[] = {1, 2, 3, 4};
    vector<int> vec(nums, nums + 4);
    vector<int>::iterator it;

    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    using nullptr_t = decltype(nullptr);
    nullptr_t nu;
    int *p = NULL;

    if (p == nu)
    {
        cout << "NULL" << endl;
    }
    typedef decltype(vec.begin()) vectype;

    for (vectype i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    struct
    {
        int a;
        double b;
    } a_b;

    decltype(a_b) as;

    as.a = 3;
    as.b = 4;
    cout << as.a << endl;
    cout << multiply(3, 4) << endl;

    /*
        1 2 3 4
        NULL
        1 2 3 4
        3
        12
    */

    return 0;
}
```

---

## 判别规则

对于 ```decltype(e)``` 而言，其判别结果受以下条件的影响：

如果 e 是一个没有带括号的标记符表达式或者类成员访问表达式，那么的 ```decltype(e)``` 就是 e 所命名的实体的类型。此外，如果 e 是一个被重载的函数，则会导致编译错误。

否则，假设 e 的类型是 T，如果 e 是一个将亡值，那么 ```decltype(e)``` 为 ```T&&``` 否则，假设 e 的类型是 T，如果 e 是一个左值，那么 ```decltype(e)``` 为 ```T&```。 

否则，假设 e 的类型是 T，则 ```decltype(e)``` 为 T。

标记符指的是除去关键字、字面量等编译器需要使用的标记之外的程序员自己定义的标记，而单个标记符对应的表达式即为标记符表达式。例如：

```cpp
int arr[4];
```

则 ```arr``` 为一个标记符表达式，而 ```arr[3] + 0``` 不是。

举例如下：

```cpp
#include <iostream>

using namespace std;

int main()
{
    int i = 4;
    int arr[5] = {0};
    int *ptr = arr;
    struct S
    {
        double d;
    } s;
    void Overloaded(int);
    void Overloaded(char); // 重载的函数
    int &&RvalRef();
    const bool Func(int);

    //规则一：推导为其类型
    decltype(arr) var1; // int[] 标记符表达式
    decltype(ptr) var2; // int *  标记符表达式
    decltype(s.d) var3; // doubel 成员访问表达式

    // decltype(Overloaded) var4;//重载函数。编译错误。

    //规则二：将亡值。推导为类型的右值引用。
    decltype(RvalRef()) var5 = 1;

    //规则三：左值，推导为类型的引用。
    decltype((i)) var6 = i;            // int&
    decltype(true ? i : i) var7 = i;   // int&  条件表达式返回左值。
    decltype(++i) var8 = i;            // int&  ++i返回i的左值。
    decltype(arr[5]) var9 = i;         // int&. [] 操作返回左值
    decltype(*ptr) var10 = i;          // int& *操作返回左值
    decltype("hello") var11 = "hello"; // const char(&)[9]  字符串字面常量为左值，且为 const 左值。

    //规则四：以上都不是，则推导为本类型
    decltype(1) var12;              // const int
    decltype(Func(1)) var13 = true; // const bool
    decltype(i++) var14 = i;        // int i++ 返回右值

    return 0;
}
```

---
