# extern

---

## C++ 与 C 编译区别

在 C++ 中常在头文件见到 extern "C" 修饰函数，那有什么作用呢？是用于 C++ 链接在 C 语言模块中定义的函数。

C++ 虽然兼容 C，但 C+ +文件中函数编译后生成的符号与 C 语言生成的不同。因为 C++ 支持函数重载，C++ 函数编译后生成的符号带有函数参数类型的信息，而 C 则没有。

例如 ```int add(int a, int b)``` 函数经过 C++ 编译器生成 ```.o``` 文件后，```add``` 会变成形如 ```add_int_int``` 之类的, 而 C 的话则会是形如 ```_add```, 就是说：相同的函数，在 C 和 C++ 中，编译后生成的符号不同。

这就导致一个问题：如果 C++ 中使用 C 语言实现的函数，在编译链接的时候，会出错，提示找不到对应的符号。此时 ```extern "C"``` 就起作用了：告诉链接器去寻找 ```_add``` 这类的 C 语言符号，而不是经过 ```C++``` 修饰的符号。

---

## C++ 调用 C 函数

C++ 调用 C 函数的例子: 引用 C 的头文件时，需要加 ```extern "C"```

```add.h```

```cpp
#ifndef ADD_H
#define ADD_H
extern int add(int x, int y);
#endif
```

```add.c```

```cpp
#include "add.h"

int add(int x, int y)
{
    return x + y;
}
```

```add.cpp```

```cpp
#include <iostream>
// #include "add.h"

using namespace std;

extern "C"
{
#include "add.h"
}

int main()
{
    add(2, 3);
    // gcc -c add.c
    // g++ add.cpp add.o -o main && ./main

    /*
        /usr/bin/ld: /tmp/ccYLSayn.o: in function `main':
        add.cpp:(.text+0x13): undefined reference to `add(int, int)'
        collect2: error: ld returned 1 exit status
    */

    return 0;
}
```

如果没有 

```cpp
extern "C"
{
#include "add.h"
}
```

直接是

```cpp
#include "add.h"
```

就会报错：

```shell
/usr/bin/ld: /tmp/ccYLSayn.o: in function `main':
add.cpp:(.text+0x13): undefined reference to `add(int, int)'
collect2: error: ld returned 1 exit status
```

编译的时候一定要注意，先通过 ```gcc``` 生成中间文件 ```add.o```

```shell
~$ gcc -c add.c 
```
然后编译：

```shell
~$ g++ add.cpp add.o -o main
```

而通常为了C代码能够通用，即既能被C调用，又能被 C++ 调用，头文件通常会有如下写法：

```cpp
#ifdef __cplusplus
extern "C"
{
#endif
    int add(int x, int y);
#ifdef __cplusplus
}
#endif
```

即在 C++ 调用该接口时，会以 C 接口的方式调用。这种方式使得 C++ 者不需要额外的 ```extern C```，而标准库头文件通常也是类似的做法，否则你为何不需要 ```extern C``` 就可以直接使用 ```stdio.h``` 中的 C 函数呢？

---

## C 中调用 C++ 函数

```extern "C"``` 在 C 中是语法错误，需要放在 C++ 头文件中。

```add.h```

```cpp
#ifndef ADD_H
#define ADD_H
extern "C"
{
    int add(int x, int y);
}
#endif
```

```add.cpp```

```cpp
#include "add.h"

int add(int x, int y)
{
    return x + y;
}
```

```add.c```

```cpp
extern int add(int x, int y);

int main()
{
    add(2, 3);
    // g++ -c add.cpp
    // gcc add.c add.o -o main && ./main
    return 0;
}
```

综上，总结出使用方法，在 C 语言的头文件中，对其外部函数只能指定为 extern 类型，C语言中不支持 ```extern "C"``` 声明，在 ```.c``` 文件中包含了 ```extern "C"``` 时会出现编译语法错误。所以使用 ```extern "C"``` 全部都放在于 cpp 程序相关文件或其头文件中。

---

## 总结

C++ 调用 C 函数：

```cpp
// xx.h
extern int add(...)

// xx.c
int add()
{

}

// xx.cpp
extern "C"
{
    #include "xx.h"
}
```

C 调用 C++ 函数

```cpp
//xx.h
extern "C"
{
    int add();
}

//xx.cpp
int add()
{
    
}

//xx.c
extern int add();
```

不过与 C++ 调用 C 接口不同，C++ 确实是能够调用编译好的 C 函数，而这里 C 调用 C++，不过是把 C++ 代码当成 C 代码编译后调用而已。也就是说，C 并不能直接调用 C++ 库函数。

---
