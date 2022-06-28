#include <iostream>

using namespace std;

const int MAX = 3;
class Full
{
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
    void push(int a);
    int pop();
};

void Stack::push(int a)
{
    if (this->top >= MAX - 1)
    {
        throw Full();
    }
    this->s[++this->top] = a;
}

int Stack::pop()
{
    if (this->top < 0)
    {
        throw Empty();
    }
    return this->s[this->top--];
}

int main()
{
    Stack s;
    try
    {
        s.push(10);
        s.push(20);
        s.push(30);
        cout << "Stack(0)= " << s.pop() << endl;
        cout << "Stack(1)= " << s.pop() << endl;
        cout << "Stack(2)= " << s.pop() << endl;
        cout << "Stack(3)= " << s.pop() << endl;
    }
    catch (Full)
    {
        cout << "Exception: Stack Full" << endl;
    }
    catch (Empty)
    {
        cout << "Exception: Stack Empty" << endl;
    }

    /*
        Stack(0)= 30
        Stack(1)= 20
        Stack(2)= 10
        Stack(3)= Exception: Stack Empty
    */

    return 0;
}
