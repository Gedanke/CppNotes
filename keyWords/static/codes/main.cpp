#include <iostream>

using namespace std;

extern void sayHello();
const char *msg = "hello world!\n";

int main()
{
    sayHello();
    // hello world!
    return 0;
}