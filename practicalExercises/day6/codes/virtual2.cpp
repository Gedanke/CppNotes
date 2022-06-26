#include <iostream>

using namespace std;

/*
    某公司有经理、销售员、小时工等多类人员。经理按周计算薪金；销售员每月底薪800元，
    然后加销售提成，每销售1件产品提取销售利润的5%；小时工按小时计算薪金。每类人员都有姓名和身份证号等数据。
    为简化问题，把各类人员的共有信息抽象成基类Employee，其他人员则继承该类的功能。
*/

class Employee
{
private:
    string name;
    string id;

public:
    Employee(string name, string id)
    {
        this->name = name;
        this->id = id;
    }
    string getName()
    {
        return this->name;
    }
    string getId()
    {
        return this->id;
    }
    float getSalary()
    {
        return 0.0;
    }
    void print()
    {
        cout << "Name: " << this->name << "\t\t Id: " << this->id << endl;
    }
};

class Manager : public Employee
{
private:
    float weekSalary;

public:
    Manager(string name, string id, int week) : Employee(name, id)
    {
        this->weekSalary = week * 2000;
    }
    float getSalary()
    {
        return this->weekSalary;
    }
    void print()
    {
        cout << "Manager: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

class SaleWorker : public Employee
{
private:
    float baseMoney = 6000.0;
    float workMoney;

public:
    SaleWorker(string name, string id, int profit, int x) : Employee(name, id)
    {
        this->workMoney = this->baseMoney + x * 0.05 * profit;
    }
    float getSalary()
    {
        return this->workMoney;
    }
    void print()
    {
        cout << "SaleWorker: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

class HourWorker : public Employee
{
private:
    float hourMoney = 100.0;
    float totalMoney;

public:
    HourWorker(string name, string id, int h) : Employee(name, id)
    {
        this->totalMoney = h * this->hourMoney;
    }
    float getSalary()
    {
        return this->totalMoney;
    }
    void print()
    {
        cout << "HourWorker: " << this->getName() << "\t\t Id: "
             << this->getId() << "\t\t Money: " << this->getSalary() << endl;
    }
};

int main()
{
    cout << "week: " << endl;
    int week;
    cin >> week;
    Manager m("wang", "12345", week);
    m.print();
    cout << "profit: " << endl;
    int profit;
    cin >> profit;
    cout << "num: " << endl;
    int x;
    cin >> x;
    SaleWorker s("Li", "12344", profit, x);
    s.print();
    cout << "hour: " << endl;
    int hour;
    cin >> hour;
    HourWorker h("He", "12333", hour);
    h.print();

    /*
        week:
        4
        Manager: wang            Id: 12345               Money: 8000
        profit:
        10000
        num:
        3
        SaleWorker: Li           Id: 12344               Money: 7500
        hour:
        8
        HourWorker: He           Id: 12333               Money: 800
    */

    return 0;
}
