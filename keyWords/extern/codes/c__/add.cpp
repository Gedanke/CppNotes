#include <iostream>
#include "add.h"

using namespace std;

// extern "C"
// {
// #include "add.h"
// }

int main()
{
    add(2, 3);
    // gcc -c add.c
    // g++ add.cpp add.o -o main && ./main

    /*
        /usr/bin/ld: /tmp/ccYLSayn.o: in function `main':
        add.cpp:(.text+0x13): undefined reference to `add(int, int)'
        collect2: error: ld returned 1 exit status
    */

    return 0;
}