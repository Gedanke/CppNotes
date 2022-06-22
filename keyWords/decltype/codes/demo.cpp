#include <iostream>

using namespace std;

int main()
{
    // decltype(exp) varname;

    // exp 为 int，a 为 int
    decltype(1 + 1) a = 1;
    // exp 为 int，b 为 int
    decltype(1 + 1) b = 1.1;
    // exp 为 double，c 为 double
    decltype(1.1 + 1.1) c = 1;
    // exp 为 double，a 为 double
    decltype(1.1 + 2.2) d = 1.1;

    // decltype 不会求值
    decltype('c' - 'a') e = 'f';
    decltype('a' + 2) f = 'f';

    // exp 为 char，g，h 都为 char
    decltype('c') g = 98;
    decltype('c') h = 'a';

    // c 输出
    printf("%d %d %f %f %d %c %c %c\n", a, b, c, d, e, f, g, h);
    // c++ 输出
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << endl;

    return 0;
}