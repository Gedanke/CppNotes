#include <iostream>

using namespace std;

class Apple
{
public:
    static int i;
    Apple()
    {
    }
};

int main()
{
    Apple apple1;
    Apple apple2;

    apple1.i = 2;
    apple2.i = 3;

    cout << apple1.i << " " << apple2.i << endl;
    /*
        /usr/bin/ld: /tmp/ccauVA3a.o: in function `main':
        main.cpp:(.text+0x35): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x3f): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x49): undefined reference to `Apple::i'
        /usr/bin/ld: main.cpp:(.text+0x6f): undefined reference to `Apple::i'
        collect2: error: ld returned 1 exit status
    */
    return 0;
}