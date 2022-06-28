# Day10

---

File:

```cpp
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class CStudent
{
private:
    char name[20];
    int age;

public:
    CStudent()
    {
    }
    CStudent(char *name, int age)
    {
        strcpy(this->name, name);
        this->age = age;
    }
    void display()
    {
        cout << this->name << "\t" << this->age << endl;
    }
};

class IStudent
{
private:
    string name;
    int age;

public:
    IStudent()
    {
    }
    IStudent(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void display()
    {
        cout << this->name << "\t" << this->age << endl;
    }
};

void testC()
{
    ofstream outFile("cstudent.dat", ios::out | ios::binary);
    cout << "input n: " << endl;
    int n;
    cin >> n;
    char name[20];
    int age;
    while (n--)
    {
        cin >> name >> age;
        CStudent s(name, age);
        cout << sizeof(s) << endl;
        outFile.write((char *)&s, sizeof(s));
    }
    outFile.close();

    cout << "----" << endl;
    CStudent ss;
    ifstream inFile("cstudent.dat", ios::in | ios::binary); //二进制读方式打开
    while (inFile.read((char *)&ss, sizeof(ss)))
    {
        ss.display();
    }
    inFile.close();

    /*
        input n:
        1
        kk 12
        24
        ----
        kk      12
    */
}

void testI()
{
    ofstream outFile("istudent.dat", ios::out | ios::binary);
    cout << "input n: " << endl;
    int n;
    cin >> n;
    string name;
    int age;
    while (n--)
    {
        cin >> name >> age;
        IStudent s(name, age);
        cout << sizeof(s) << endl;
        outFile.write((char *)&s, sizeof(s));
    }
    outFile.close();

    cout << "----" << endl;
    IStudent ss;
    ifstream inFile("istudent.dat", ios::in | ios::binary); //二进制读方式打开
    while (inFile.read((char *)&ss, sizeof(ss)))
    {
        ss.display();
    }
    inFile.close();

    /*
        input n:
        1
        dd 12
        40
        ----
        �=      12
        free(): invalid pointer
        Aborted
    */
}

int main()
{
    // testC();
    // testI();
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    //用cin输入字符串数据时，如果字符串中含有空白就不能完整输入。因为遇到空白字符时，cin就认为字符串结束了。
    char a[50];
    cout << "input a string" << endl;
    cin >> a;
    cout << a << endl;

    /*
        input a string
        qwer
        qwer
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    char stu[5][10];
    int i;
    for (i = 0; i < 5; i++)
    {
        cin.getline(stu[i], 10, ',');
    }
    cout << "cout" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << stu[i];
    }
    cout << endl;

    /*
        1
        2
        3
        4
        5
        cout
        1
        2
        3
        4
        5
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    char c;
    char a[40] = "this is a string...";
    cout << "use get() input char:" << endl;
    ;
    while ((c = cin.get()) != '\n')
    {
        cout.put(c);
        cout.put('\n');
        cout.put('t').put('h').put('i').put('s').put('\n');
        cout.write(a, 40).put('\n');
        cout << "look"
             << "\t here!" << endl;
    }

    /*
        use get() input char:
        a
        a
        this
        this is a string...
        look     here!
     */
    /*
        use get() input char:
        ab
        a
        this
        this is a string...
        look     here!
        b
        this
        this is a string...
        look     here!
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    char c[40] = "this is a string...";
    double d = -1231.232;

    cout.width(30);
    cout.fill('*');
    cout.setf(ios::left);
    cout << c << "----L1" << endl;

    cout.width(30);
    cout.fill('-');
    cout.setf(ios::right);
    cout << c << "----L2" << endl;

    cout.setf(ios::dec | ios::showbase | ios::showpoint);
    cout.width(30);
    cout << d << "----L3" << endl;

    cout.setf(ios::showpoint);
    cout.precision(10);
    cout << d << "----L4" << endl;

    cout.width(30);
    cout.setf(ios::oct, ios::basefield);
    cout << 100 << "----L5" << endl;

    /*
        this is a string...***********----L1
        -----------this is a string...----L2
        -----------------------1231.23----L3
        -1231.232000----L4
        --------------------------0144----L5
     */

    return 0;
}
```

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char c[30] = "this is a string";
    double d = -1234.8976;
    cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << c << "----L2" << endl;
    // showbase 显示数值的基数前缀
    cout << dec << showbase << showpoint << setw(30) << d << "----L3" << endl;
    // showpoint 显示小数点
    cout << setw(30) << showpoint << setprecision(10) << d << "----L4" << endl;
    // setbase(8) 设置八进制
    cout << setw(30) << setbase(16) << 100 << "----L5" << endl;

    /*
        root@master:/home/root/codes/cplusplus/vscode/demo/test# g++ -o main main.cpp && ./main
        this is a string**************----L1
        **************this is a string----L2
        **********************-1234.90----L3
        ******************-1234.897600----L4
        **************************0x64----L5
     */

    return 0;
}
```

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
       fstream ioFile;
       ioFile.open("./a.dat", ios::out);
       ioFile << "张三"
              << "  " << 76 << " " << 98 << " " << 67 << endl; // L3
       ioFile << "李四"
              << "  " << 89 << " " << 70 << " " << 60 << endl;
       ioFile << "王十"
              << "  " << 91 << " " << 88 << " " << 77 << endl;
       ioFile << "黄二"
              << "  " << 62 << " " << 81 << " " << 75 << endl;
       ioFile << "刘六"
              << "  " << 90 << " " << 78 << " " << 67 << endl;
       ioFile.close();
       ioFile.open("./a.dat", ios::in | ios::binary);
       char name[10];
       int chinese, math, computer;
       cout << "姓名\t"
            << "英语\t"
            << "数学\t"
            << "计算机\t"
            << "总分" << endl;
       ioFile >> name;
       while (!ioFile.eof())
       {
              ioFile >> chinese >> math >> computer;
              cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
              ioFile >> name;
       }
       ioFile.close();

       /*
           姓名    英语    数学    计算机  总分
           张三    76      98      67      241
           李四    89      70      60      219
           王十    91      88      77      256
           黄二    62      81      75      218
           刘六    90      78      67      235
        */

       return 0;
}
```

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char ch;
    ofstream out("./test.dat", ios::out | ios::binary);
    for (int i = 0; i < 90; i++)
    {
        if (i > 0 && (i % 30) == 0)
        {
            out.put('\n');
        }
        out.put(i);
        out.put(' ');
    }
    out.close();
    ifstream in("./test.dat", ios::in | ios::binary);
    while (in.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    in.close();

    /*




         1 2 3 4 5 6 7 8 9 : ;
        < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y
    */

    return 0;
}
```

```cpp
#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
private:
    int number;
    int age;
    string name;
    double sal;

public:
    Employee()
    {
    }
    Employee(int number, int age, string name, double sal)
    {
        this->number = number;
        this->age = age;
        this->name = name;
        this->sal = sal;
    }
    void display()
    {
        cout << this->number << "\t" << this->name << "\t" << this->age << "\t" << this->sal;
    }
};

int main()
{
    ofstream out("./d.dat", ios::out);
    Employee e1(1, 23, "张三", 2300);
    Employee e2(2, 21, "张四", 2350);
    Employee e3(3, 20, "张五", 2390);
    Employee e4(4, 22, "张六", 2310);

    out.write((char *)&e1, sizeof(e1));
    out.write((char *)&e2, sizeof(e2));
    out.write((char *)&e3, sizeof(e3));
    out.write((char *)&e4, sizeof(e4));

    Employee e5(3, 30, "张七", 2200);
    out.seekp(3 * sizeof(e1));
    out.write((char *)&e5, sizeof(e5));
    out.close();

    /*
     */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    用法：a = cin.get() ?或者 ?cin.get(a)
    结束条件：输入字符足够后回车
    说明：这个是单字符的输入，用途是输入一个字符，把它的ASCALL码存入到a中
    处理方法：与cin不同，cin.get()在缓冲区遇到[enter]，[space]，[tab]不会作为舍弃，而是继续留在缓冲区中
*/

int main()
{
    char a, b, c, d;
    cin.get(a);
    cin.get(b);
    c = cin.get();
    d = cin.get();
    cout << int(a) << "," << int(b) << "," << int(c) << "," << int(d) << endl;

    /*
        abcd
        97,98,99,100
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

// cin.get(arrayname,size)  把字符输入到arrayname中，长度不超过size

int main()
{
    // get()两个参数

    // 1.输入串长<size，输入串长>arraylength，会自动扩张arrayname大小，使能保存所有数据
    //  char a[10];
    //  cin.get(a,20);
    //  cout<<a<<endl;
    //  cout<<sizeof(a)<<endl;
    // 2.输入串长<size，输入串长<arraylength，把串全部输入，后面补‘\0’
    //  char b[10];
    //  cin.get(b,20);
    //  cout<<b<<endl;//12345，此时数组内数据为‘12345'\0’
    //  cout<<sizeof(b)<<endl;
    // 3.输入串长>size，先截取size个字符，若还是大于arraylength，则输入前arraylength-1个字符，最后补充‘\0’
    //  char c[5];
    //  cin.get(c,10);
    //  cout<<c<<endl;
    //  cout<<sizeof(c)<<endl;
    // 4.输入串长>size，先截取size个字符，若小于arraylength，则把截取串放入数组中，最后补充‘\0’
    //  char d[10];
    //  cin.get(d,5);
    //  cout<<d<<endl;
    //  cout<<sizeof(d)<<endl;

    // get()三个参数
    /*
        用法：cin.get(arrayname,size,s) ?把数据输入到arrayname字符数组中，当到达长度size时结束或者遇到字符s时结束
        注释：a必须是字符数组，即char a[]l类型，不可为string类型；size为最大的输入长度；s为控制，遇到s则当前输入结束缓存区里的s将被舍弃
    */
    int i;
    char e[10];
    cin.get(e, 8, ',');
    cout << e << endl;

    /*
        abcdefgh
        abcdefg
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    （1）cin.getline(arrayname,size)与cin.get(arrayname,size)的区别
    cin.get(arrayname,size)当遇到[enter]时会结束目前输入，他不会删除缓冲区中的[enter]
    cin.getline(arrayname,size)当遇到[enter]时会结束当前输入，但是会删除缓冲区中的[enter]
*/

int main()
{
    /*
    char a[10];
    char b;
    cin.get(a,10);
    cin.get(b);
    cout<<a<<endl<<int(b);//输入：12345[enter] 输出：12345 【换行】 10*/
    /*char c[10];
    char d;
    cin.getline(c,10);
    cin.get(d);
    cout<<c<<endl<<int(d);//输入：12345[enter]a[enter] 输出：12345【换行】97*/
    // cin.getline(arrayname,size,s)与cin.gei(arrayname,size,s)的区别
    /*
    cin.getline(arrayname,size,s)当遇到s时会结束输入，并把s从缓冲区中删除
    cin.get（arrayname,size,s）当遇到s时会结束输入，但不会删除缓冲区中的s
    */
    /*
    char e[10];
    char f;
    cin.get(e,10,',');
    cin.get(f);
    cout<<e<<endl<<f;//输入：12345,[enter] 输出：12345【换行】，说明：cin,get不会删除缓冲区的，
    */
    char e1[10];
    char f1;
    cin.getline(e1, 10, ',');
    cin.get(f1);
    cout << e1 << endl
         << f1; //输入：asd,wqe 输出：asd【换行】w

    /*
        0123456789
        012345678
    */

    return 0;
}
```

```cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class Person
{
private:
    char name[20];
    char id[20];
    int age;
    char address[20];

public:
    Person()
    {
    }
    Person(char *name, char *id, int age, char *address)
    {
        strcpy(this->name, name);
        strcpy(this->id, id);
        this->age = age;
        strcpy(this->address, address);
    }
    void display()
    {
        cout << this->name << "\t" << this->id << "\t" << this->age << "\t" << this->address << endl;
    }
};

int main()
{
    vector<Person> v;
    ofstream out("./person.dat", ios::out | ios::binary);
    char name[20], id[20], address[20];
    int age;
    cout << "------input number:" << endl;
    int num;
    cin >> num;
    while (num--)
    {
        cout << "name: " << endl;
        cin >> name;
        cout << "id: " << endl;
        cin >> id;
        cout << "age: " << endl;
        cin >> age;
        cout << "address: " << endl;
        cin >> address;
        Person per(name, id, age, address);
        out.write((char *)&per, sizeof(per));
    }
    out.close();

    cout << "------" << endl;
    ifstream in("./person.dat", ios::in | ios::binary);
    Person p;
    while (in.read((char *)&p, sizeof(p)))
    {
        v.push_back(p);
    }
    in.close();
    for (auto vv : v)
    {
        vv.display();
    }

    /*
        ------input number:
        2
        name:
        dd
        id:
        12
        age:
        20
        address:
        cn
        name:
        ff
        id:
        13
        age:
        21
        address:
        cn
        ------
        dd      12      20      cn
        ff      13      21      cn
    */

    return 0;
}
```

---
