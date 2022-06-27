#include <iostream>

using namespace std;

class Counter
{
private:
    int n;

public:
    Counter(int i = 0) : n(i){};
    Counter operator++();
    Counter operator++(int);
    friend Counter operator--(Counter &c);
    friend Counter operator--(Counter &c, int);
    void display();
};

Counter Counter::operator++()
{
    ++this->n;
    return *this;
}

Counter Counter::operator++(int)
{
    this->n++;
    return *this;
}

Counter operator--(Counter &c)
{
    --c.n;
    return c;
}

Counter operator--(Counter &c, int)
{
    c.n--;
    return c;
}

void Counter::display()
{
    cout << "Counter " << this->n << endl;
}

int main()
{
    Counter c;

    ++c;
    c.display();

    c++;
    c.display();

    --c;
    c.display();

    c--;
    c.display();

    /*
        Counter 1
        Counter 2
        Counter 1
        Counter 0
    */

    return 0;
}
