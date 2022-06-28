#include <iostream>

using namespace std;

const int MAX = 3;

class Full
{
private:
    int a;

public:
    Full(int i) : a(i)
    {
    }
    int getValue()
    {
        return this->a;
    }
};

class Empty
{
};

class Stack
{
private:
    int s[MAX];
    int top;

public:
    Stack()
    {
        this->top = -1;
    }
    void push(int a)
    {
        if (this->top >= MAX - 1)
        {
            throw Full(a);
        }
        this->s[++this->top] = a;
    }
    int pop()
    {
        if (this->top < 0)
        {
            throw Empty();
        }
        return this->s[this->top--];
    }
};

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
    }
    catch (Full e)
    {
        cout << "Exception: Stack Full..." << endl;
        cout << "The value do not push into stack: " << e.getValue() << endl;
    }

    /*
        Exception: Stack Full...
        The value do not push into stack: 40
    */

    return 0;
}
