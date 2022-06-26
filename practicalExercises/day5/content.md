# Day4

---

constructor：

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int x;

public:
    A(int i = 0)
    {
        this->x = i;
        cout << "----A----" << endl;
    }
};

class B
{
private:
    int y;

public:
    B(int i)
    {
        this->y = i;
        cout << "----B----" << endl;
    }
};

class C
{
private:
    int z;

public:
    C(int i)
    {
        this->z = i;
        cout << "----C----" << endl;
    }
};

class D : public B
{
public:
    C c1, c2;
    A *a1 = new A(10);
    A a0, a4;
    D() : a0(0), a4(4), c1(1), c2(2), B(1)
    {
        cout << "----D----" << endl;
    }
    ~D()
    {
        delete this->a1;
    }
};

int main()
{
    D d;

    /*
        ----B----
        ----C----
        ----C----
        ----A----
        ----A----
        ----A----
        ----D----
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    先构造成员
    再构造自身（调用构造函数）
*/

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
    B b;
    A a;
};

int main()
{
    C c;

    /*
        B
        A
        C
        ~C
        ~A
        ~B
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    先构造成员
    再构造自身（调用构造函数）
*/

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
public:
    ~B()
    {
        cout << "~B" << endl;
    }
};

int main()
{
    B b;

    /*
        A
        ~B
        ~A
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    Base(int a)
    {
        this->x = a;
        cout << "Base x= " << this->x << endl;
    }
    ~Base()
    {
        cout << "~Base" << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    Derived(int a, int b) : Base(a)
    {
        this->y = b;
        cout << "Derived y= " << this->y << endl;
    }
    ~Derived()
    {
        cout << "~Derived" << endl;
    }
};

int main()
{
    Derived d(1, 2);

    /*
        Base x= 1
        Derived y= 2
        ~Derived
        ~Base
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
    ~B()
    {
        cout << "~B" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C" << endl;
    }
    ~C()
    {
        cout << "~C" << endl;
    }
};

class D
{
private:
    B b;
    A a;
    C c;

public:
    D()
    {
        cout << "D" << endl;
    }
    ~D()
    {
        cout << "~D" << endl;
    }
};

int main()
{
    D d;

    /*
        B
        A
        C
        D
        ~D
        ~C
        ~A
        ~B
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Point
{
protected:
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        cout << "point(" << this->x << "," << this->y << ")" << endl;
    }
};

class Line : public Point
{
protected:
    int len;

public:
    Line(int a, int b, int l) : Point(a, b)
    {
        this->len = l;
        cout << "Line" << endl;
    }
};

int main()
{
    Line l(1, 2, 3);

    /*
        point(1,2)
        Line
    */

    return 0;
}
```

继承：

```cpp
#include <iostream>

using namespace std;

/*
    基类中protected的成员
    类内部：可以访问
    类的使用者：不能访问
    类的派生类成员：可以访问
*/

class B
{
private:
    int i;

protected:
    int j;

public:
    int k;
};

class D : public B
{
public:
    void f()
    {
        // this->i=1;
        // 成员 "B::i" (已声明 所在行数:14) 不可访问
        this->j = 2;
        this->k = 3;
    }
};

int main()
{
    B b;
    // b.i=1;
    // 成员 "B::i" (已声明 所在行数:14) 不可访问
    // b.j=2;
    // 成员 "B::j" (已声明 所在行数:16) 不可访问
    b.k = 3;
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

/*
    派生方式为protected的继承称为保护继承，在这种继承方式下，
    基类的public成员在派生类中会变成protected成员，
    基类的protected和private成员在派生类中保持原来的访问权限
*/

class Base
{
private:
    int x;

protected:
    int getX()
    {
        return this->x;
    }

public:
    void setX(int x)
    {
        this->x = x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : protected Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:19) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:22) 不可访问
    d.showY();
    // 20
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    void setX(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return this->x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : public Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    d.setX(10);
    d.setY(20);
    d.showX();
    d.showY();
    d.setY();
    d.showX();
    d.showY();

    /*
        10
        20
        10
        10
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class Base
{
private:
    int x;

public:
    void setX(int x)
    {
        this->x = x;
    }
    int getX()
    {
        return this->x;
    }
    void showX()
    {
        cout << this->x << endl;
    }
};

class Derived : private Base
{
private:
    int y;

public:
    void setY()
    {
        this->y = this->getX();
    }
    void setY(int y)
    {
        this->y = y;
    }
    void showY()
    {
        cout << this->y << endl;
    }
};

int main()
{
    Derived d;
    // d.setX(10); 函数 "Base::setX" (已声明 所在行数:9) 不可访问
    d.setY(20);
    // d.showX(); 函数 "Base::showX" (已声明 所在行数:15) 不可访问
    d.showY();
    // 20
    return 0;
}
```

基类与派生类：

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    void setA(int x)
    {
        this->a = x;
    }
    int getA()
    {
        return this->a;
    }
};

class B : public A
{
private:
    int b;

public:
    void setB(int x)
    {
        this->b = x;
    }
    int getB()
    {
        return this->b;
    }
};

void f1(A a, int x)
{
    a.setA(x);
}

void f2(A *a, int x)
{
    a->setA(x);
}

void f3(A &a, int x)
{
    a.setA(x);
}

int main()
{
    A a1, *pa;
    B b1, *pb;
    a1.setA(1);
    b1.setA(2);
    // 把派生类对象赋值给基类对象
    a1 = b1;
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 2
    // 2
    a1.setA(10);
    cout << a1.getA() << endl;
    cout << b1.getA() << endl;
    // 10
    // 2
    // 把派生类对象的地址赋值给基类指针
    pa = &b1;
    pa->setA(20);
    cout << pa->getA() << endl;
    cout << b1.getA() << endl;
    // 20
    // 20
    // 用派生类对象初始化基类对象的引用
    A &ra = b1;
    ra.setA(30);
    cout << ra.getA() << endl;
    cout << b1.getA() << endl;
    // 30
    // 30
    b1.setA(7);
    cout << b1.getA() << endl;
    // 7
    f1(b1, 100);
    cout << b1.getA() << endl;
    // 7
    f2(&b1, 200);
    cout << b1.getA() << endl;
    // 200
    f3(b1, 300);
    cout << b1.getA() << endl;
    // 300
    return 0;
}
```

虚拟继承：

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B : public A
{
};

class C : public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    // d.fun(); "D::fun" 不明确
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
public:
    void fun()
    {
        cout << "A" << endl;
    }
};

class B : virtual public A
{
};

class C : virtual public A
{
};

class D : public B, public C
{
};

int main()
{
    D d;
    d.fun();
    // A
    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A(int a)
    {
        this->a = a;
        cout << "Virtual A" << endl;
    }
};

class B : virtual public A
{
public:
    B(int i) : A(i)
    {
        cout << "virtual B" << endl;
    }
};

class C : virtual public A
{
private:
    int x;

public:
    C(int i) : A(i)
    {
        this->x = i;
        cout << "C" << endl;
    }
};

class ABC : public C, public B
{
public:
    ABC(int i, int j, int k) : C(i), B(j), A(i)
    {
        cout << "ABC" << endl;
    }
};

int main()
{
    ABC abc(1, 2, 3);

    /*
        Virtual A
        C
        virtual B
        ABC
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class A
{
private:
    int a;

public:
    A()
    {
        cout << "A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B" << endl;
    }
};

class B1 : virtual public B, virtual public A
{
public:
    B1(int i)
    {
        cout << "B1" << endl;
    }
};

class B2 : virtual public A, virtual public B
{
public:
    B2(int j)
    {
        cout << "B2" << endl;
    }
};

class D : public B1, public B2
{
public:
    D(int m, int n) : B1(m), B2(n)
    {
        cout << "D" << endl;
    }
    A a;
};

int main()
{
    D d(1, 2);

    /*
        B
        A
        B1
        B2
        A
        D
    */

    return 0;
}
```

直接基类与间接基类：

```cpp
#include <iostream>

using namespace std;

// 当同时存在直接基类和间接基类时，每个派生类只负责其直接基类的构造

class A
{
private:
    int x;

public:
    A(int a)
    {
        this->x = a;
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

class B : public A
{
public:
    B(int x) : A(x)
    {
        cout << "B" << endl;
    }
};

class C : public B
{
public:
    C(int y) : B(y)
    {
        cout << "C" << endl;
    }
};

int main()
{
    C c(1);

    /*
        A
        B
        C
        ~A
    */

    return 0;
}
```

---
