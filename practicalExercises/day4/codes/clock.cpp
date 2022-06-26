#include <iostream>
#include "clock.h"

using namespace std;

Clock::Clock(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}

Clock::Clock(Clock &c)
{
    this->hour = c.hour;
    this->minute = c.minute;
    this->second = c.second;
}

void Clock::set(int h, int m, int s)
{
    this->hour = h;
    this->minute = m;
    this->second = s;
}

void Clock::showTime()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

Clock::~Clock()
{
}

int main()
{
    Clock c(0, 0, 0);

    c.set(20, 20, 20);
    c.showTime();

    Clock c1(c);
    c1.set(21, 22, 23);
    c1.showTime();
    // 20:20:20
    // 21:22:23
    return 0;
}
