#include <stdio.h>

typedef void (*pf)();

typedef struct _A
{
    pf _f;
} A;

typedef struct _B
{
    A _b;
} B;

void FunA()
{
    printf("%s\n", "Base A::fun()");
}

void FunB()
{
    printf("%s\n", "Base B::fun()");
}

int main()
{
    A a;
    B b;

    a._f = FunA;
    b._b._f = FunB;

    A *pa = &a;
    pa->_f();
    pa = (A *)&b;
    pa->_f();

    a._f();
    b._b._f();

    /*
        Base A::fun()
        Base B::fun()
        Base A::fun()
        Base B::fun()
    */

    return 0;
}
