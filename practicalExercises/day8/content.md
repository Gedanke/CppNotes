# Day8

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
