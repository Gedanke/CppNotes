#include <iostream>

using namespace std;

void isLeapYear()
{
    int year;
    bool isLeapYear;
    cout << "Enter the year: ";
    cin >> year;
    isLeapYear = (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    if (isLeapYear)
    {
        cout << year << " is a leap year" << endl;
    }
    else
    {
        cout << year << " is not a leap year" << endl;
    }
}

int main()
{
    isLeapYear();

    /*
        Enter the year: 2000
        2000 is a leap year
    */

    return 0;
}