#include <iostream>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) \
                             : (b))

int main()
{
    int max_val = MAX(3, 6);
    cout << max_val << endl;
    return 0;
}