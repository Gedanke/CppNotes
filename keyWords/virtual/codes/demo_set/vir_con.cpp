#include <iostream>

using namespace std;

//// LIBRARY SRART
class Base
{
public:
    Base()
    {
    }
    // Ensures to invoke actual object destructor
    virtual ~Base() {}
    virtual void ChangeAttributes() = 0;
    // The "Virtual Constructor"
    static Base *Create(int id);
    // The "Virtual Copy Constructor"
    virtual Base *Clone() = 0;
};

class Derived1 : public Base
{
public:
    Derived1()
    {
        cout << "Derived1 created" << endl;
    }
    Derived1(const Derived1 &rhs)
    {
        cout << "Derived1 created by deep copy" << endl;
    }
    ~Derived1()
    {
        cout << "~Derived1 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived1 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived1(*this);
    }
};

class Derived2 : public Base
{
public:
    Derived2()
    {
        cout << "Derived2 created" << endl;
    }
    Derived2(const Derived2 &rhs)
    {
        cout << "Derived2 created by deep copy" << endl;
    }
    ~Derived2()
    {
        cout << "~Derived2 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived2 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived2(*this);
    }
};

class Derived3 : public Base
{
public:
    Derived3()
    {
        cout << "Derived3 created" << endl;
    }
    Derived3(const Derived3 &rhs)
    {
        cout << "Derived3 created by deep copy" << endl;
    }
    ~Derived3()
    {
        cout << "~Derived3 destroyed" << endl;
    }
    void ChangeAttributes()
    {
        cout << "Derived3 Attributes Changed" << endl;
    }
    Base *Clone()
    {
        return new Derived3(*this);
    }
};

// We can also declare "Create" outside Base.
// But is more relevant to limit it's scope to Base
Base *Base::Create(int id)
{
    // Just expand the if-else ladder, if new Derived class is created
    // User need not be recompiled to create newly added class objects

    if (id == 1)
    {
        return new Derived1;
    }
    else if (id == 2)
    {
        return new Derived2;
    }
    else
    {
        return new Derived3;
    }
}
// LIBRARY END

// UTILITY SRART
class User
{
public:
    User() : pBase(0)
    {
        // Creates any object of Base heirarchey at runtime
        int input;
        cout << "Enter ID (1, 2 or 3): ";
        cin >> input;
        while ((input != 1) && (input != 2) && (input != 3))
        {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }

        // Create objects via the "Virtual Constructor"
        pBase = Base::Create(input);
    }

    ~User()
    {
        if (pBase)
        {
            delete pBase;
            pBase = 0;
        }
    }
    void Action()
    {
        // Duplicate current object
        Base *pNewBase = pBase->Clone();
        // Change its attributes
        pNewBase->ChangeAttributes();
        // Dispose the created object
        delete pNewBase;
    }

private:
    Base *pBase;
};

// UTILITY END
// Consumer of User (UTILITY) class
int main()
{
    User *user = new User();
    user->Action();
    delete user;
    /*
    Enter ID (1, 2 or 3): 1
    Derived1 created
    Derived1 created by deep copy
    Derived1 Attributes Changed
    ~Derived1 destroyed
    ~Derived1 destroyed

    Enter ID (1, 2 or 3): 2
    Derived2 created
    Derived2 created by deep copy
    Derived2 Attributes Changed
    ~Derived2 destroyed
    ~Derived2 destroyed

    Enter ID (1, 2 or 3):
    Derived3 created
    Derived3 created by deep copy
    Derived3 Attributes Changed
    ~Derived3 destroyed
    ~Derived3 destroyed
    */
}
