class A
{
public:
    // 类中定义了的函数是隐式内联函数,声明要想成为内联函数，必须在实现处(定义处)加 inline 关键字
    void fun1(int x);

    void foo(int x, int y){
        // 定义即隐式内联函数
    };
};