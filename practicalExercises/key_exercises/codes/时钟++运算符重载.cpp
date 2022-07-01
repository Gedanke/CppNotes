#include <iostream>
#include <cmath>

using namespace std;

// 时钟类
class Clock
{
private:
    int hour, minute, second;

public:
    Clock();
    Clock(int h = 0, int m = 0, int s = 0);
    void showTime();
    Clock &operator++();
    Clock operator++(int);
};

// 构造函数
Clock::Clock()
{
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}

Clock::Clock(int h, int m, int s)
{
    if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
    {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    else
    {
        cout << "输入时间格式有误!" << endl;
    }
}

// 显示时间
void Clock::showTime()
{
    cout << this->hour << ":" << this->minute << ":" << this->second << endl;
}

// 时间递增一秒，重载前置 ++
Clock &Clock::operator++()
{
    this->second++;
    if (this->second >= 60)
    {
        this->second = this->second - 60;
        this->minute++;
        if (this->minute >= 60)
        {
            this->minute = this->minute - 60;
            this->hour++;
            this->hour = this->hour % 24;
        }
    }
    return *this;
}

// 时间递增一秒，重载后置 ++
Clock Clock::operator++(int)
{
    Clock old = *this;
    ++(*this);
    return old;
}

int main()
{
    Clock clock(23, 59, 59);
    cout << "Time:" << endl;
    clock.showTime();

    cout << "clock++" << endl;
    (clock++).showTime();

    cout << "++clock" << endl;
    (++clock).showTime();

    /*
        Time:
        23:59:59
        clock++
        23:59:59
        ++clock
        0:0:1s
    */

    return 0;
}
