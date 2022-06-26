#include <iostream>

using namespace std;

void swap(int &a, int &b);

int main()
{
    int x1 = 5;
    int x2 = 7;
    cout << x1 << " " << x2 << endl;
    // 7 5
    swap(x1, x2);
    cout << x1 << " " << x2 << endl;
    // 7 5
    return 0;
}

void swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}