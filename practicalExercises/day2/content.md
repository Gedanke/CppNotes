# Day2

---

递归：

```cpp
#include <iostream>

using namespace std;

int f(int n);
int f(int n, int k);

void f1()
{
    cout << "input x: " << endl;
    int x;
    cin >> x;
    cout << f(x) << endl;
}

void f2()
{
    cout << "input x: " << endl;
    int n, k;
    cin >> n;
    cin >> k;
    cout << f(n, k) << endl;
}

int main()
{
    f1();
    f2();

    /*
        input x:
        4
        24
        input x:
        4 3
        4
    */

    return 0;
}

int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * f(n - 1);
    }
}

int f(int n, int k)
{
    if ((n == k) || (k == 0))
    {
        return 1;
    }
    else
    {
        return f(n - 1, k - 1) + f(n - 1, k);
    }
}
```

enum：

```cpp
#include <iostream>

using namespace std;

enum weekday
{
    s,
    m,
    t,
    w,
    thu,
    f,
    st
};

int main()
{
    enum weekday wek = s;
    for (int i = wek; i != st; i++)
    {
        cout << i << endl;
        cout << wek + s << endl;
        cout << "-------------------------" << endl;
    }

    /*
        0
        0
        -------------------------
        1
        0
        -------------------------
        2
        0
        -------------------------
        3
        0
        -------------------------
        4
        0
        -------------------------
        5
        0
        -------------------------
    */

    return 0;
}
```

计算 $\pi$：

```cpp
#include <iostream>

using namespace std;

double arctan(double x);

int main()
{
    double a = 16.0 * arctan(1.0 / 5.0);
    double b = 4.0 * arctan(1.0 / 239.0);
    double pi = a - b;
    cout << pi << endl;
    // 3.14159
    return 0;
}

double arctan(double x)
{
    double res = 0.0;
    double head = x;
    int tail = 1;
    while (double(head / tail) > 1e-15)
    {
        res = (tail % 4 == 1) ? res + head / tail : res - head / tail;
        head *= x * x;
        tail += 2;
    }
    return res;
}
```

汉诺塔：

```cpp
#include <iostream>

using namespace std;

void move(char A, char B);
void hanoi(int n, char A, char B, char C);

int main()
{
    int disks;
    cin >> disks;
    hanoi(disks, 'A', 'B', 'C');

    /*
        3
        A->C
        A->B
        C->B
        A->C
        B->A
        B->C
        A->C
    */

    return 0;
}

void move(char A, char B)
{
    cout << A << "->" << B << endl;
}

void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        move(A, C);
    }
    else
    {
        hanoi(n - 1, A, C, B);
        move(A, C);
        hanoi(n - 1, B, A, C);
    }
}
```

power：

```cpp
#include <iostream>

using namespace std;

double power(double x, int n);
void powerDemo();

int main()
{
    powerDemo();

    /*
        16
        8
    */

    return 0;
}

double power(double x, int n)
{
    double res = 1.0;
    while (n--)
    {
        res = res * x;
    }
    return res;
}

void powerDemo()
{
    int x;
    cin >> x;
    int w = 0;
    int sum = 0;
    int each, chu;
    for (int i = 0; i < 8; i++)
    {
        each = x % 10;
        chu = x / 10;
        sum += each * power(2, w);
        x = chu;
        w++;
    }
    cout << sum << endl;
}
```

rolldice：

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int rolldice();

int main()
{
    int flag;
    unsigned seed;
    cout << "请输入一个数" << endl;
    cin >> seed;
    srand(seed);
    int sum = rolldice();
    int selfdim;
    switch (sum)
    {
    case 7:
    case 11:
        flag = 1;
        break;
    case 2:
    case 3:
    case 12:
        flag = 2;
        break;
    default:
        flag = 0;
        selfdim = sum;
        break;
    }
    while (flag == 0)
    {
        sum = rolldice();
        if (sum == selfdim)
        {
            flag = 1;
        }
        else if (sum == 7)
        {
            flag = 2;
        }
    }
    if (flag == 1)
    {
        cout << "player win\n";
    }
    else
    {
        cout << "player loses\n";
    }

    /*
        请输入一个数
        16
        sum = 1 + 4
        sum = 4 + 5
        sum = 4 + 6
        sum = 2 + 6
        sum = 4 + 1
        player win
    */

    return 0;
}

int rolldice()
{
    int sum = 0;
    int dim1 = rand() % 6 + 1;
    int dim2 = rand() % 6 + 1;
    sum = dim1 + dim2;
    cout << "sum = " << dim1 << " + " << dim2 << endl;
    return sum;
}
```

static：

```cpp
#include <iostream>

using namespace std;

int i = 10; // i 全局变量，静态生存期

int main()
{
    static int a;
    // 静态局部变量，有全局寿命，局部可见
    int b = -10;
    // b, c为局部变量，具有动态生存期
    int c = 0;
    void fun();
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    c = c + 8;
    fun();
    cout << "---MAIN---\n";
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    i = i + 10;
    fun();
    fun();

    /*
        ---MAIN---
        i: 10 a: 0 b: -10 c: 0
        ---OTHER---
        i: 42 a: 4 b: 0 c: 15
        ---MAIN---
        i: 42 a: 0 b: -10 c: 8
        ---OTHER---
        i: 84 a: 6 b: 4 c: 15
        ---OTHER---
        i: 116 a: 8 b: 6 c: 15
    */

    return 0;
}

void fun()
{
    static int a = 2;
    static int b;
    // a,b 为静态局部变量，具有全局寿命，局部可见。
    // 只第一次进入函数时被初始化。
    int c = 10;
    // c 为局部变量，具有动态生存期
    a = a + 2;
    i = i + 32;
    c = c + 5;
    cout << "---OTHER---" << endl;
    cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
    b = a;
}
```

struct：

```cpp
#include <iostream>

using namespace std;

struct Student
{
    int num;
    char name[20];
    char gender;
};

int main()
{
    Student s = {
        18, "Jay", 'M'};
    cout << s.num << endl;
    cout << sizeof(s.num) << endl;
    cout << sizeof(s.name) << endl;
    cout << sizeof(s.gender) << endl;
    cout << sizeof(s) << endl;

    /*
        18
        4
        20
        1
        28
    */

    return 0;
}
```

---
