#include <iostream>

using namespace std;

class BasicException
{
public:
    virtual string where()
    {
        return "Basic Exception";
    }
};

class FileSysException : public BasicException
{
public:
    virtual string where()
    {
        return "FileSysException";
    }
};

class FileNotFind : public FileSysException
{
public:
    virtual string where()
    {
        return "FileNotFind";
    }
};

class DiskNotFind : public FileSysException
{
public:
    virtual string where()
    {
        return "DiskNotFind";
    }
};

int main()
{
    try
    {
        FileNotFind err;
        // DiskNotFind err;
        throw &err;
    }
    catch (BasicException *p)
    {
        cout << p->where() << endl;
    }

    /*
        DiskNotFind
    */

    return 0;
}
