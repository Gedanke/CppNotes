#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
    int x = 7;
    x = 9;
    assert(x == 7);
    // main: main.cpp:9: int main(): Assertion `x==7' failed.
    // Aborted
    return 0;
}
