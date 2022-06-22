#include <iostream>

using namespace std;

extern int ext;

// g++ -o main file.cpp main.cpp && ./main

int main()
{
    cout << (ext + 1024) << endl;
    return 0;
}