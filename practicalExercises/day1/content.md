# Day1

---

闰年判断：

```cpp
#include <iostream>

using namespace std;

void isLeapYear()
{
    int year;
    bool isLeapYear;
    cout << "Enter the year: ";
    cin >> year;
    isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    if (isLeapYear)
    {
        cout << year << " is a leap year" << endl;
    }
    else
    {
        cout << year << " is not a leap year" << endl;
    }
}

int main()
{
    isLeapYear();

    /*
        Enter the year: 2000
        2000 is a leap year
    */

    return 0;
}
```

输出：

```cpp
#include <iostream>

using namespace std;

void print_start()
{
    int i, j, k, f;
    for (i = 1; i <= 4; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (k = 1; k <= 8 - 2 * i; k++)
            cout << " ";
        for (f = 1; f <= 2 * i; f++)
            cout << '*';
        cout << endl;
    }
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 30; j++)
            cout << " ";
        for (f = 1; f <= 7 - 2 * i; f++)
            cout << '*';
        cout << endl;
    }
}

int main()
{
    print_start();
    
    /*
                                            **
                                          ****
                                        ******
                                      ********
                                      *****
                                      ***
                                      *

    */
    
    return 0;
}
```

union：

```cpp
#include <iostream>

using namespace std;

union demo
{
    struct
    {
        int x;
        int y;
        int z;
    } u;
    int k;
} d;

int main()
{
    d.u.x = 3;
    d.u.y = 4;
    d.u.z = 5;
    cout << d.u.x << " " << d.u.y << " " << d.u.z << " " << d.k << " " << endl;
    d.k = 1;
    cout << d.u.x << " " << d.u.y << " " << d.u.z << " " << d.k << " " << endl;
    
    // 3 4 5 3
    // 1 4 5 1
    
    return 0;
}
```

注释：

```cpp
#include <iostream>

// 一种条件编译指令注释

//另一种注释方法
#if 0
asd
#endif

//打开注释
//条件编译指令
#if 1
asData
#endif
```

---
