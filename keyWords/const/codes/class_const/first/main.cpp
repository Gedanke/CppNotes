#include <iostream>
#include "apple.cpp"

using namespace std;

Apple::Apple(int i) : people(100, 0), apple_num(i)
{
    // edit
}

void Apple::add(int num)
{
    this->take(num);
}

void Apple::add(int num) const
{
    this->take(num);
}

void Apple::take(int num) const
{
    cout << "take function " << num << endl;
}

int Apple::getCount() const
{
    this->take(1);
    return this->apple_num;
}

int main()
{
    Apple a(2);
    cout << a.getCount() << endl;
    a.add(10);
    const Apple b(3);
    b.add(100);
    return 0;
}