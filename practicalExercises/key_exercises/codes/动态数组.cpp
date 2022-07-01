#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *sPtr;
    const char *s = "hello";
    sPtr = new char[strlen(s) + 1];
    strncpy(sPtr, s, strlen(s));

    cout << sPtr << endl;

    /*
        hello
     */

    return 0;
}
