# macro

---

## 宏中包含特殊符号

分为几种：```#```，```##```，```\```

### 字符串化操作符(#)

在一个宏中的参数前面使用一个 #,预处理器会把这个参数转换为一个字符数组，换言之就是：# 是“字符串化”的意思，出现在宏定义中的 # 是把跟在后面的参数转换成一个字符串。

注意：其只能用于有传入参数的宏定义中，且必须置于宏定义体中的参数名前。

例如：

```cpp
#include <iostream>

using namespace std;

#define exp(s) printf("test s is:%s\n", s)
#define exp1(s) printf("test s is:%s\n", #s)
#define exp2(s) #s

int main()
{
    exp("hello");
    exp1(hello);

    string str = exp2(bac);
    cout << str << " " << str.size() << endl;

    /*
        忽略传入参数名前面和后面的空格。
    */

    string str1 = exp2(asda bac);

    /*
        当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
        用每个子字符串之间以一个空格连接，忽略剩余空格。
    */

    cout << str1 << " " << str1.size() << endl;

    return 0;
}
```

上述代码给出了基本的使用与空格处理规则，空格处理规则如下：

* 忽略传入参数名前面和后面的空格

```cpp
string str = exp2(bac);
cout << str << " " << str.size() << endl;
```

输出：

```text
bac 3
```

* 当传入参数名间存在空格时，编译器将会自动连接各个子字符串，用每个子字符串之间以一个空格连接，忽略剩余空格。

```cpp
string str1 = exp2(asda  bac);
cout << str1 << " " << str1.size() << endl;
```

输出：

```text
asda bac 8
```

### 符号连接操作符(##)

“##” 是一种分隔连接方式，它的作用是先分隔，然后进行强制连接。将宏定义的多个形参转换成一个实际参数名。

注意事项：

* 当用 ```##``` 连接形参时，```##``` 前后的空格可有可无
* 连接后的实际参数名，必须为实际存在的参数名或是编译器已知的宏定义
* 如果 ```##``` 后的参数本身也是一个宏的话，```##``` 会阻止这个宏的展开

示例：

```cpp
#include <iostream>

using namespace std;

#define expA(s) printf("前缀加上后的字符串为:%s\n", gc_##s) // gc_s 必须存在
// 注意事项 2
#define expB(s) printf("前缀加上后的字符串为:%s\n", gc_##s) // gc_s 必须存在
// 注意事项 1
#define gc_hello1 "I am gc_hello1"

int main()
{
    // 注意事项1
    const char *gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);
}
```

### 续行操作符(\)

当定义的宏不能用一行表达完整时，可以用 ```\``` 表示下一行继续此宏的定义。

注意 ```\``` 前留空格。

```cpp
#include <iostream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) \
                             : (b))

int main()
{
    int max_val = MAX(3, 6);
    cout << max_val << endl;
    return 0;
}
```

案例：

```cpp
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

///===========================================

/*
    (#) 字符串操作符
*/

///===========================================

#define exp(s) printf("test s is: %s\n", s)
#define exp1(s) printf("test s is: %s\n", #s)

#define exp2(s) #s

///===========================================

/*
    (##) 符号连接操作符
*/

///===========================================

#define expA(s) printf("前缀加上后的字符串为: %s\n", gc_##s) // gc_s必须存在

#define expB(s) printf("前缀加上后的字符串为: %s\n", gc_##s) // gc_s必须存在

#define gc_hello1 "I am gc_hello1"

///===========================================

/*
    (\) 续行操作符
*/

///===========================================

#define MAX(a, b) ((a) > (b) ? (a) \
                             : (b))

int main()
{
    ///===========================================
    /*
        (#)字符串操作符
    */
    ///===========================================
    exp("hello");
    exp1(hello);

    string str = exp2(bac);
    cout << str << " " << str.size() << endl;

    /*
        忽略传入参数名前面和后面的空格。
    */

    string str1 = exp2(asda bac);

    /*
        当传入参数名间存在空格时，编译器将会自动连接各个子字符串，
        用每个子字符串之间以一个空格连接，忽略剩余空格。
    */

    cout << str1 << " " << str1.size() << endl;

    ///===========================================
    /*
        (#)字符串操作符
    */
    ///===========================================

    const char *gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);

    char var1_p[20];
    char var2_p[20];

    // 连接后的实际参数名赋值
    strcpy(var1_p, "aaaa");
    strcpy(var2_p, "bbbb");

    ///===========================================
    /*
        (\)续行操作符
    */
    ///===========================================

    int max_val = MAX(3, 6);
    cout << max_val << endl;

    /*
        test s is: hello
        test s is: hello
        bac 3
        asda bac 8
        前缀加上后的字符串为: I am gc_hello
        前缀加上后的字符串为: I am gc_hello1
        6
    */

    return 0;
}
```

---

## do{...}while(0) 的使用

### 避免语义曲解

例如：

```cpp
#define fun() \
    f1();     \
    f2();

if(a > 0)
	fun()
```

这个宏被展开后就是：

```cpp
if(a > 0)
	f1();
	f2();
```

本意是 ```a>0``` 执行 ```f1 f2```，而实际是 ```f2``` 每次都会执行，所以就错误了。

为了解决这种问题，在写代码的时候，通常可以采用 ```{}``` 块。

如：

```cpp
#define fun() {f1();f2();}
if(a > 0)
	fun();
// 宏展开
if(a > 0)
{
    f1();
    f2();
};
```

但是会发现上述宏展开后多了一个分号，实际语法不太对。(虽然编译运行没问题，正常没分号)。

### 避免使用 goto 控制流

在一些函数中，我们可能需要在 ```return``` 语句之前做一些清理工作，比如释放在函数开始处由 ```malloc``` 申请的内存空间，使用 ```goto``` 总是一种简单的方法：

```cpp
int f()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;
#ifndef DEBUG
    int error = 1;
#endif
    if (error)
        goto END;
    // dosomething
END:
    cout << "free" << endl;
    free(p);
    return 0;
}
```

但由于 ```goto``` 不符合软件工程的结构化，而且有可能使得代码难懂，所以很多人都不倡导使用，这个时候我们可以使用 ```do{...}while(0)``` 来做同样的事情：

```cpp
int ff()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;
    do
    {
#ifndef DEBUG
        int error = 1;
#endif
        if (error)
            break;
        // dosomething
    } while (0);
    cout << "free" << endl;
    free(p);
    return 0;
}
```

这里将函数主体部分使用 ```do{...}while(0)``` 包含起来，使用 ```break``` 来代替 ```goto```，后续的清理工作在 ```while``` 之后，现在既能达到同样的效果，而且代码的可读性、可维护性都要比上面的 ```goto``` 代码好的多了。


### 避免由宏引起的警告

内核中由于不同架构的限制，很多时候会用到空宏。在编译的时候，这些空宏会给出 warning，为了避免这样的 warning，我们可以使用 ```do{...}while(0)``` 来定义空宏：

```cpp
#define EMPTYMICRO do{}while(0)
```

### 定义单一的函数块来完成复杂的操作

如果你有一个复杂的函数，变量很多，而且你不想要增加新的函数，可以使用 ```do{...}while(0)```，将你的代码写在里面，里面可以定义变量而不用考虑变量名会同函数之前或者之后的重复。这种情况应该是指一个变量多处使用(但每处的意义还不同)，我们可以在每个 ```do-while``` 中缩小作用域，比如：

```cpp
int fc()
{
    int k1 = 10;
    cout << k1 << endl;
    do
    {
        int k1 = 100;
        cout << k1 << endl;
    } while (0);
    cout << k1 << endl;
}
```

案例:

```cpp
#include <iostream>
#include <malloc.h>

using namespace std;

#define f1() cout << "f1()" << endl;
#define f2() cout << "f2()" << endl;

#define fun() \
    {         \
        f1(); \
        f2()  \
    }
#define fun1() \
    do         \
    {          \
        f1();  \
        f2();  \
    } while (0)

int f()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;

#ifndef DEBUG
    int error = 1;
#endif
    if (error)
    {
        goto END;
    }
END:
    cout << "free" << endl;
    free(p);
    return 0;
}

int ff()
{
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;

    do
    {
#ifndef DEBUG
        int error = 1;
#endif
        if (error)
        {
            break;
        }
    } while (0);

    cout << "free" << endl;
    free(p);
    return 0;
}

void fc()
{
    int k1 = 10;
    cout << k1 << endl;

    do
    {
        int k1 = 100;
        cout << k1 << endl;
    } while (0);
    cout << k1 << endl;
}

int main()
{
    if (1 > 0)
    {
        fun();
    }

    if (2 > 0)
    {
        fun1();
    }

    f();
    ff();
    fc();

    /*
        f1()
        f2()
        f1()
        f2()
        10
        free
        10
        free
        10
        100
        10
    */
    return 0;
}
```

参考：[https://www.cnblogs.com/lizhenghn/p/3674430.html](https://www.cnblogs.com/lizhenghn/p/3674430.html)

---
