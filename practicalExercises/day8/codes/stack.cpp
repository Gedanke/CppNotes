#include <iostream>

using namespace std;

template <class T, int MAXSIZE>
class Stack
{
private:
    T elem[MAXSIZE];
    int top;

public:
    Stack()
    {
        this->top = 0;
    }
    void push(T e);
    T pop();
    bool empty()
    {
        if (this->top <= -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void setEmpty()
    {
        this->top = -1;
    }
    bool full()
    {
        if (this->top >= MAXSIZE - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

template <class T, int MAXSIZE>
void Stack<T, MAXSIZE>::push(T e)
{
    if (this->full())
    {
        cout << "stack full!";
        return;
    }
    this->elem[++top] = e;
}

template <class T, int MAXSIZE>
T Stack<T, MAXSIZE>::pop()
{
    if (this->empty())
    {
        cout << "stack empty!" << endl;
        return 0;
    }
    return this->elem[top--];
}

int main()
{
    Stack<int, 10> istack;
    Stack<char, 10> cstack;
    istack.setEmpty();
    cstack.setEmpty();
    cout << "int stack" << endl;
    int i;
    for (i = 1; i < 11; i++)
    {
        istack.push(i);
    }
    for (i = 1; i < 11; i++)
    {
        cout << istack.pop() << "\t";
    }

    cout << "\n"
         << "char stack" << endl;
    cstack.push('A');
    cstack.push('B');
    cstack.push('C');
    cstack.push('D');
    cstack.push('E');

    for (i = 1; i < 6; i++)
    {
        cout << cstack.pop() << "\t";
    }
    cout << endl;
    /*
        int stack
        10      9       8       7       6       5       4       3       2       1
        char stack
        E       D       C       B       A
    */

    return 0;
}
