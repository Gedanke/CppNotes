#include <iostream>

using namespace std;

union demo
{
    struct
    {
        int x;
        int y;
        int z;
    } u;
    int k;
} d;

int main()
{
    d.u.x = 3;
    d.u.y = 4;
    d.u.z = 5;
    cout << d.u.x << " " << d.u.y << " " << d.u.z << " " << d.k << " " << endl;
    d.k = 1;
    cout << d.u.x << " " << d.u.y << " " << d.u.z << " " << d.k << " " << endl;
    
    // 3 4 5 3
    // 1 4 5 1
    
    return 0;
}