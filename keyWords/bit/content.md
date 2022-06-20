# Bit Field

---

## 位域是什么

“位域” 或 “位段”(Bit field)为一种数据结构，可以把数据以位的形式紧凑的储存，并允许程序员对此结构的位进行操作。这种数据结构的一个好处是它可以使数据单元节省储存空间，当程序需要成千上万个数据单元时，这种方法就显得尤为重要。第二个好处是位段可以很方便的访问一个整数值的部分内容从而可以简化程序源代码。

而这种数据结构的缺点在于，位段实现依赖于具体的机器和系统，在不同的平台可能有不同的结果，这导致了位段在本质上是不可移植的。

* 位域在内存中的布局是与机器有关的
* 位域的类型必须是整型或枚举类型，带符号类型中的位域的行为将因具体实现而定
* 取地址运算符(&)不能作用于位域，任何指针都无法指向类的位域

---

## 位域使用

位域通常使用结构体声明，该结构声明为每个位域成员设置名称，并决定其宽度：

```cpp
struct bit_field_name
{
	type member_name : width;
};
```

|||
|:----:|:----:|
| Elements | Description |
| ```bit_field_name``` | 位域结构名 |
| ```type``` | 位域成员的类型，必须为 ```int、signed int``` 或者 ```unsigned int``` 类型 |
| ```member_name``` | 位域成员名 |
| ```width``` | 规定成员所占的位数 |

例如声明如下一个位域:

```cpp
struct _PRCODE
{
	unsigned int code1: 2;
	unsigned int cdde2: 2;
	unsigned int code3: 8;
};
struct _PRCODE prcode;
```

该定义使 ```prcode``` 包含 2 个 2 ```Bits``` 位域和 1 个 8 ```Bits``` 位域，我们可以使用结构体的成员运算符对其进行赋值

```cpp
prcode.code1 = 0;
prcode.code2 = 3;
procde.code3 = 102;
```

赋值时要注意值的大小不能超过位域成员的容量，例如 ```prcode.code3``` 为 8 ```Bits``` 的位域成员，其容量为 $2^8 = 256$，即赋值范围应为 $[0,255]$。

---

## 位域的大小和对齐

### 位域的大小

例如以下位域：

```cpp
struct box 
{
	unsigned int a: 1;
	unsigned int  : 3;
	unsigned int b: 4;
};
```

该位域结构体中间有一个未命名的位域，占据 3 ```Bits```，仅起填充作用，并无实际意义。 填充使得该结构总共使用了 8 ```Bits```。但 C 语言使用 ```unsigned int``` 作为位域的基本单位，即使一个结构的唯一成员为 1 ```Bit``` 的位域，该结构大小也和一个 ```unsigned int``` 大小相同。 有些系统中，```unsigned int``` 为 16 ```Bits```，在 x86 系统中为 32 ```Bits```。文章以下均默认 ```unsigned int``` 为 32 ```Bits```。

### 位域的对齐

一个位域成员不允许跨越两个 ```unsigned int``` 的边界，如果成员声明的总位数超过了一个 ```unsigned int``` 的大小，那么编辑器会自动移位位域成员，使其按照 ```unsigned int``` 的边界对齐。例如：

```cpp
struct stuff 
{
	unsigned int field1: 30;
	unsigned int field2: 4;
	unsigned int field3: 3;
};
```

```field1 + field2 = 34 Bits```，超出 32 ```Bits```, 编译器会将 ```field2``` 移位至下一个 ```unsigned int``` 单元存放，```stuff.field1``` 和 ```stuff.field2``` 之间会留下一个 2 ```Bits``` 的空隙，```stuff.field3``` 紧跟在 ```stuff.field2``` 之后，该结构现在大小为 ```2 * 32 = 64 Bits```

这个空洞可以用之前提到的未命名的位域成员填充，我们也可以使用一个宽度为 0 的未命名位域成员令下一位域成员与下一个整数对齐。例如:

```cpp
struct stuff 
{
	unsigned int field1: 30;
	unsigned int       : 2;
	unsigned int field2: 4;
	unsigned int       : 0;
	unsigned int field3: 3; 
};
```

这里 ```stuff.field1``` 与 ```stuff.field2``` 之间有一个 2 ```Bits``` 的空隙，```stuff.field3``` 则存储在下一个 ```unsigned int``` 中，该结构现在大小为 ```3 * 32 = 96 Bits```

demo:

```cpp
#include <iostream>

using namespace std;

struct stuff
{
    unsigned int field1 : 30;
    unsigned int : 2;
    unsigned int field2 : 4;
    unsigned int : 0;
    unsigned int field3 : 3;
};

int main()
{
    struct stuff s = {1, 3, 5};
    cout << s.field1 << endl;
    cout << s.field2 << endl;
    cout << s.field3 << endl;
    cout << sizeof(s) << endl;
    // 1
    // 3
    // 5
    // 12
    return 0;
}
```

---

## 位域的初始化和位的重映射

### 初始化

位域的初始化与普通结构体初始化的方法相同，这里列举两种，如下:

```cpp
struct stuff s1= {20, 8, 6};
```

或者直接为位域成员赋值

```cpp
struct stuff s1;
s1.field1 = 20;
s1.field2 = 8;
s1.field3 = 4;
```

---

### 位域的重映射(Re-mapping)

声明一个大小为 32 ```Bits``` 的位域

```cpp
struct box {
    unsigned int ready:     2;
	unsigned int error:     2;
	unsigned int command:   4;
	unsigned int sector_no: 24;
}b1;
```

利用重映射将位域归零

```cpp
int* p = (int *) &b1;  // 将 "位域结构体的地址" 映射至 "整形(int*)的地址" 
*p = 0;                // 清除 s1，将各成员归零
```

利用联合 ```union``` 将 32 ```Bits``` 位域重映射至 ```unsigned int``` 型

```text
“联合” 是一种特殊的类，也是一种构造类型的数据结构。在一个 “联合” 内可以定义多种不同的数据类型，一个被说明为该 “联合” 类型的变量中，允许装入该 “联合” 所定义的任何一种数据，这些数据共享同一段内存，以达到节省空间的目的

“联合” 与 “结构” 有一些相似之处。但两者有本质上的不同。在结构中各成员有各自的内存空间，一个结构变量的总长度是各成员长度之和(空结构除外，同时不考虑边界调整)。而在 “联合” 中，各成员共享一段内存空间，一个联合变量的长度等于各成员中最长的长度。应该说明的是，这里所谓的共享不是指把多个成员同时装入一个联合变量内，而是指该联合变量可被赋予任一成员值，但每次只能赋一种值， 赋入新值则冲去旧值。
```

我们可以声明以下联合:

```cpp
union u_box {
    struct box st_box;     
    unsigned int ui_box;
};
```

x86 系统中 ```unsigned int``` 和 ```box``` 都为 32 ```Bits```, 通过该联合使 ```st_box``` 和 ```ui_box``` 共享一块内存。具体位域中哪一位与 ```unsigned int``` 哪一位相对应，取决于编译器和硬件。利用联合将位域归零，代码如下：

```cpp
union u_box u;
u.ui_box = 0;
```

demo:

```cpp
#include <iostream>

using namespace std;

struct Box
{
    unsigned int ready : 2;
    unsigned int error : 2;
    unsigned int command : 4;
    unsigned int sector_no : 24;
};

void printMsg(struct Box b)
{
    cout << b.ready << " " << b.error << " " << b.command << " " << b.sector_no << endl;
}

union UBox
{
    struct Box st_box;
    long long int ui_box;
};

int main()
{
    struct Box b = {1, 2, 3, 4};
    printMsg(b);
    cout << sizeof(b) << endl;
    int *p = (int *)&b; // 将 "位域结构体的地址" 映射至 "整形(int*)的地址"
    *p = 0;             // 清除 s1，将各成员归零
    printMsg(b);
    cout << sizeof(b) << endl;

    cout << "------" << endl;

    union UBox u;
    u.ui_box = 0;

    cout << sizeof(u) << endl;
    cout << sizeof(u.st_box) << endl;
    cout << sizeof(u.ui_box) << endl;

    /*
        1 2 3 4
        4
        0 0 0 0
        4
        ------
        8
        4
        8
    */

    return 0;
}
```

---

## 总结

位域可以变量以比特位的形式存放，但大小不能超过成员类型(整形或者枚举型)的最大容量，取地址运算符(&)不能作用于位域，任何指针都无法指向类的位域

一个位域成员不能跨过两个成员类型容量，否则编译器会自动补齐，也可以用未命名的位域成员进行填充

可以重映射，使得位域所有成员归零，利用联合 ```union``` 可以将位域重映射至其他类型

---
