class A
{
};

class B
{
public:
    virtual ~B()
    {
    }
};

class D : public A
{
};

class E : private A
{
};

class F : private B
{
};
