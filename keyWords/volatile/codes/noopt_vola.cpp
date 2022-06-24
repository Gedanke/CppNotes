#include <iostream>

using namespace std;

int main()
{
    const int local = 10;
    int *ptr = (int *)&local;
    cout << local << endl;
    // 10
    *ptr = 100;
    cout << local << endl;
    // 10
    return 0;
}