#ifndef CLOCK
#define CLOCK

class Clock
{
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int h, int m, int s);
    Clock(Clock &c);
    void set(int h, int m, int s);
    void showTime();
    ~Clock();
};

#endif