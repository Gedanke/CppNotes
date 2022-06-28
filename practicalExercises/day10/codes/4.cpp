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
