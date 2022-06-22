#include <iostream>

using namespace std;

extern const int ext;

// g++ -o const_main const_file.cpp const_main.cpp && ./const_main

int main()
{
    cout << (ext + 1024) << endl;
    return 0;
}