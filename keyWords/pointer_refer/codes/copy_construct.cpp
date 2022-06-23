#include <iostream>

using namespace std;

class Copyable
{
public:
    Copyable()
    {
    }
    Copyable(const Copyable &o)
    {
        cout << "Copy" << endl;
    }
};

Copyable ReturnValue()
{
    return Copyable();
}

void AcceptVal(Copyable a)
{
}

void AcceptRef(const Copyable &a)
{
}

int main()
{
    // g++ -o main main.cpp -fno-elide-constructors  && ./main
    cout << "pass by value: " << endl;
    AcceptVal(ReturnValue());
    cout << "pass by reference: " << endl;
    AcceptRef(ReturnValue());

    /*
        pass by value:
        Copy
        Copy
        pass by reference:
        Copy
    */

    return 0;
}