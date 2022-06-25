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