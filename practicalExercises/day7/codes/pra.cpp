#include <iostream>
#include <cstring>

using namespace std;

// 设计一个字符串类String，通过运算符重载实现字符串的输入、输出以及+=、==、!=、<、>、>=、[ ]等运算
class String
{
private:
    int length;
    char *sPtr;
    void setString(const char *s2);
    friend ostream &operator<<(ostream &os, const String &s)
    {
        return os << s.sPtr;
    }

    friend istream &operator>>(istream &is, String &s)
    {
        return is >> s.sPtr;
    }

public:
    String(const char * = "");
    const String &operator=(const String &R)
    {
        this->length = R.length;
        strcmp(this->sPtr, R.sPtr);
        return *this;
    }
    const String &operator+=(const String &R);
    bool operator==(const String &R);
    bool operator!=(const String &R);
    bool operator!();
    bool operator<(const String &R) const;
    bool operator>(const String &R);
    bool operator>=(const String &R);
    char &operator[](int);
    ~String(){};
};

const String &String::operator+=(const String &R)
{
    char *tmp = this->sPtr;
    this->length += R.length;
    this->sPtr = new char[this->length + 1];
    strcpy(this->sPtr, tmp);
    strcat(this->sPtr, R.sPtr);
    delete[] tmp;
    return *this;
}

String::String(const char *str)
{
    this->sPtr = new char[strlen(str) + 1];
    strcpy(this->sPtr, str);
    this->length = strlen(str);
}

bool String::operator==(const String &R)
{
    return strcmp(this->sPtr, R.sPtr) == 0;
}
bool String::operator!=(const String &R)
{
    return !(*this == R);
}
bool String::operator!()
{
    return this->length == 0;
}
bool String::operator<(const String &R) const
{
    return strcmp(this->sPtr, R.sPtr) < 0;
}
bool String::operator>(const String &R)
{
    return R < *this;
}
bool String::operator>=(const String &R)
{
    return !(*this < R);
}
char &String::operator[](int sub)
{
    return this->sPtr[sub];
}

int main()
{
    String s1("happy"), s2("new year"), s3;
    cout << "s1 is " << s1 << "\ns2 is " << s2 << "\ns3 is " << s3
         << "\n比较s2和s1:"
         << "\ns2 ==s1结果是 " << (s2 == s1 ? "true" : "false")
         << "\ns2 != s1结果是 " << (s2 != s1 ? "true" : "false")
         << "\ns2 >  s1结果是 " << (s2 > s1 ? "true" : "false")
         << "\ns2 <  s1结果是 " << (s2 < s1 ? "true" : "false")
         << "\ns2 >= s1结果是 " << (s2 >= s1 ? "true" : "false");
    cout << "\n\n测试s3是否为空: ";
    if (!s3)
    {
        cout << "s3是空串" << endl; // L3
        cout << "把s1赋给s3的结果是：";
        s3 = s1;
        cout << "s3=" << s3 << "\n"; // L5
    }
    cout << "s1 += s2 的结果是：s1="; // L6
    s1 += s2;
    cout << s1; // L7

    cout << "\ns1 +=  to you 的结果是："; // L8
    s1 += " to you";
    cout << "s1 = " << s1 << endl; // L9
    s1[0] = 'H';
    s1[6] = 'N';
    s1[10] = 'Y';
    cout << "s1 = " << s1 << "\n"; // L10

    /*
        s1 is happy
        s2 is new year
        s3 is
        比较s2和s1:
        s2 ==s1结果是 false
        s2 != s1结果是 true
        s2 >  s1结果是 true
        s2 <  s1结果是 false
        s2 >= s1结果是 true

        测试s3是否为空: s3是空串
        把s1赋给s3的结果是：s3=
        s1 += s2 的结果是：s1=happynew year
        s1 +=  to you 的结果是：s1 = happynew year to you
        s1 = HappynNw yYar to you
    */

    return 0;
}
