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
