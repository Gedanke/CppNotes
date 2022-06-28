# Day9

---

try catch:

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "1--before try block" << endl;
    try
    {
        cout << "2--inside try block" << endl;
        // throw 10;
        throw(char *) "s";
        cout << "3--after throw" << endl;
    }
    catch (int i)
    {
        cout << "4--catch int i" << endl;
    }
    catch (char *s)
    {
        cout << "5--catch char *s" << endl;
    }
    cout << "6--after catch" << endl;

    /*
        1--before try block
        2--inside try block
        4--catch int i
        6--after catch

        1--before try block
        2--inside try block
        5--catch char *s
        6--after catch
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

int main()
{
    cout << "1--before try block" << endl;
    try
    {
        cout << "2--inside try block" << endl;
        throw 10;
        cout << "3--after throw" << endl;
    }
    catch (double i)
    {
        cout << "4--catch double i" << endl;
    }
    cout << "5--after catch" << endl;

    /*
        1--before try block
        2--inside try block
        terminate called after throwing an instance of 'int'
        Aborted
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

void temperature(int t)
{
    try
    {
        if (t == 100)
        {
            throw "boiling point";
        }
        else if (t == 0)
        {
            throw "freezing point";
        }
        else
        {
            cout << "ok" << endl;
        }
    }
    catch (int x)
    {
        cout << "temperature=" << x << endl;
    }
    catch (char const *s)
    {
        cout << s << endl;
    }
}

int main()
{
    temperature(0);
    temperature(10);
    temperature(100);

    /*
        freezing point
        ok
        boiling point
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

void temperature(int t)
{
    if (t == 100)
    {
        throw "boiling point";
    }
    else if (t == 0)
    {
        throw "freezing point";
    }
    else
    {
        cout << "ok" << endl;
    }
}

int main()
{
    try
    {
        temperature(0);
        // temperature(10);
        // temperature(100);
    }
    catch (char const *s)
    {
        cout << s << endl;
    }

    /*
        freezing point
        ok
        boiling point
    */

    return 0;
}
```

```cpp
#include <iostream>
#define throw(...)
using namespace std;

void handler(int n) throw(int, char, double)
{
    if (n == 1)
    {
        throw n;
    }
    if (n == 2)
    {
        throw 'x';
    }
    if (n == 3)
    {
        throw 1.1;
    }
}

int main()
{
    cout << "before handler" << endl;
    try
    {
        handler(1);
    }
    catch (int i)
    {
        cout << "catch an integer.." << endl;
    }
    catch (char c)
    {
        cout << "catch a char" << endl;
    }
    catch (double d)
    {
        cout << "catch a double" << endl;
    }

    /*
        before handler
        catch an integer..
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

void errorHandler(int n) throw()
{
    try
    {
        if (n == 1)
        {
            throw n;
        }
        if (n == 2)
        {
            throw "dx";
        }
        if (n == 3)
        {
            throw 1.1;
        }
    }
    catch (...)
    {
        cout << "catch en exception" << endl;
    }
}

int main()
{
    errorHandler(1);
    errorHandler(2);
    errorHandler(3);

    /*
        catch en exception
        catch en exception
        catch en exception
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
    A(int i = 0) : a(i)
    {
        cout << "A constructor" << endl;
    }
    ~A()
    {
        cout << "A destructor" << endl;
    }
};

class B
{
private:
    A obj[3];
    double *pb[10];

public:
    B(int k)
    {
        cout << "B constructor" << endl;
        for (int i = 0; i < 10; i++)
        {
            this->pb[i] = new double[20000000];
            if (this->pb[i] == 0)
            {
                throw i;
            }
            else
            {
                cout << "Allocated 200000000 doubles in pb[" << i << "]" << endl;
            }
        }
    }
    ~B()
    {
        cout << "B destructor" << endl;
    }
};

int main()
{
    try
    {
        B b(2);
    }
    catch (int e)
    {
        cout << "catch an exception when allocated pb[" << e << "]" << endl;
    }

    /*
        A constructor
        A constructor
        A constructor
        B constructor
        Allocated 200000000 doubles in pb[0]
        Allocated 200000000 doubles in pb[1]
        Allocated 200000000 doubles in pb[2]
        Allocated 200000000 doubles in pb[3]
        Allocated 200000000 doubles in pb[4]
        Allocated 200000000 doubles in pb[5]
        Allocated 200000000 doubles in pb[6]
        Allocated 200000000 doubles in pb[7]
        Allocated 200000000 doubles in pb[8]
        Allocated 200000000 doubles in pb[9]
        B destructor
        A destructor
        A destructor
        A destructor
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

// 内部再次throw异常时，函数不要带throw()

void errorHandler(int n)
{
    try
    {
        if (n == 1)
        {
            throw n;
        }
        cout << "ok" << endl;
    }
    catch (int e)
    {
        cout << "catch an exception in function\t" << e << endl;
        throw e;
    }
}

int main()
{
    try
    {
        errorHandler(1);
    }
    catch (int x)
    {
        cout << "catch an exception in main" << endl;
    }
    cout << "end" << endl;

    /*
        catch an exception in function  1
        catch an exception in main
        end
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

const int MAX = 3;
class Full
{
};
class Empty
{
};

class Stack
{
private:
    int s[MAX];
    int top;

public:
    Stack()
    {
        this->top = -1;
    }
    void push(int a);
    int pop();
};

void Stack::push(int a)
{
    if (this->top >= MAX - 1)
    {
        throw Full();
    }
    this->s[++this->top] = a;
}

int Stack::pop()
{
    if (this->top < 0)
    {
        throw Empty();
    }
    return this->s[this->top--];
}

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Stack(0)= " << s.pop() << endl;
        cout << "Stack(1)= " << s.pop() << endl;
        cout << "Stack(2)= " << s.pop() << endl;
        cout << "Stack(3)= " << s.pop() << endl;
    }
    catch (Full)
    {
        cout << "Exception: Stack Full" << endl;
    }
    catch (Empty)
    {
        cout << "Exception: Stack Empty" << endl;
    }

    /*
        Stack(0)= 30
        Stack(1)= 20
        Stack(2)= 10
        Stack(3)= Exception: Stack Empty
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class BasicException
{
public:
    virtual string where()
    {
        return "Basic Exception";
    }
};

class FileSysException : public BasicException
{
public:
    virtual string where()
    {
        return "FileSysException";
    }
};

class FileNotFind : public FileSysException
{
public:
    virtual string where()
    {
        return "FileNotFind";
    }
};

class DiskNotFind : public FileSysException
{
public:
    virtual string where()
    {
        return "DiskNotFind";
    }
};

int main()
{
    try
    {
        FileNotFind err;
        // DiskNotFind err;
        throw &err;
    }
    catch (BasicException *p)
    {
        cout << p->where() << endl;
    }

    /*
        DiskNotFind
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

class BasicException
{
public:
    string where()
    {
        return "Basic Exception";
    }
};

class FileSysException : public BasicException
{
public:
    string where()
    {
        return "FileSysException";
    }
};

class FileNotFind : public FileSysException
{
public:
    string where()
    {
        return "FileNotFind";
    }
};

class DiskNotFind : public FileSysException
{
public:
    string where()
    {
        return "DiskNotFind";
    }
};

int main()
{
    try
    {
        throw FileSysException();
    }
    catch (DiskNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.where() << endl;
    }
    catch (BasicException p)
    {
        cout << p.where() << endl;
    }
    try
    {
        throw DiskNotFind();
    }
    catch (BasicException p)
    {
        cout << p.where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.where() << endl;
    }
    catch (DiskNotFind p)
    {
        cout << p.where() << endl;
    }
    catch (FileNotFind p)
    {
        cout << p.where() << endl;
    }

    /*
        FileSysException
        Basic Exception
    */

    return 0;
}
```

```cpp
#include <iostream>

using namespace std;

const int MAX = 3;

class Full
{
private:
    int a;

public:
    Full(int i) : a(i)
    {
    }
    int getValue()
    {
        return this->a;
    }
};

class Empty
{
};

class Stack
{
private:
    int s[MAX];
    int top;

public:
    Stack()
    {
        this->top = -1;
    }
    void push(int a)
    {
        if (this->top >= MAX - 1)
        {
            throw Full(a);
        }
        this->s[++this->top] = a;
    }
    int pop()
    {
        if (this->top < 0)
        {
            throw Empty();
        }
        return this->s[this->top--];
    }
};

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (Full e)
    {
        cout << "Exception: Stack Full..." << endl;
        cout << "The value do not push into stack: " << e.getValue() << endl;
    }

    /*
        Exception: Stack Full...
        The value do not push into stack: 40
    */

    return 0;
}
```

---
