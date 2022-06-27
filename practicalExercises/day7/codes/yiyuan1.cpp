#include <iostream>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time(int h, int m, int s);
    Time operator++();
    friend Time operator--(Time &t);
    void display();
};

Time::Time(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
    if (this->hour >= 24 || this->hour < 0)
    {
        this->hour = 0;
    }
    if (this->minute >= 60 || this->minute < 0)
    {
        this->minute = 0;
    }
    if (this->second >= 60 || this->second < 0)
    {
        this->second = 0;
    }
}

Time Time::operator++()
{
    this->second++;
    if (this->second >= 60)
    {
        this->second = 0;
        this->minute++;
        if (this->minute >= 60)
        {
            this->minute = 0;
            this->hour++;
            if (this->hour >= 24)
            {
                this->hour = 0;
            }
        }
    }
    return *this;
}

Time operator--(Time &t)
{
    t.second--;
    if (t.second < 0)
    {
        t.second = 59;
        t.minute--;
        if (t.minute < 0)
        {
            t.minute = 59;
            t.hour--;
            if (t.hour < 0)
            {
                t.hour = 23;
            }
        }
    }
    return t;
}

void Time::display()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

int main()
{
    Time t1(23, 59, 59);
    t1.display();

    ++t1;
    t1.display();

    t1.operator++();
    t1.display();

    Time t2(24, 60, 60);
    t2.display();

    ++t2;
    t2.display();

    --t2;
    t2.display();

    /*
        23:59:59
        0:0:0
        0:0:1
        0:0:0
        0:0:1
        0:0:0
    */

    return 0;
}
