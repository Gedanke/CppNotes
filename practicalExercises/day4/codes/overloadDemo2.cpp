#include <iostream>

using namespace std;

class Time
{
private:
    int h, m, s;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        this->h = h;
        this->m = m;
        this->s = s;
    }
    void operator++();
    void operator++(int);
    void showTime()
    {
        cout << this->h << ":" << this->m << ":" << this->s << endl;
    }
};

void Time::operator++()
{
    this->s++;
    if (this->s == 60)
    {
        this->s = 0;
        this->m++;
        if (this->m == 60)
        {
            this->m = 0;
            this->h++;
            if (this->h == 24)
            {
                this->h = 0;
            }
        }
    }
}

void Time::operator++(int)
{
    this->s++;
    if (this->s == 60)
    {
        this->s = 0;
        this->m++;
        if (this->m == 60)
        {
            this->m = 0;
            this->h++;
            if (this->h == 24)
            {
                this->h = 0;
            }
        }
    }
}

int main()
{
    Time t(23, 59, 59);
    t.showTime();
    ++t;
    t.showTime();
    t++;
    t.showTime();

    /*
        23:59:59
        0:0:0
        0:0:1
    */

    return 0;
}
