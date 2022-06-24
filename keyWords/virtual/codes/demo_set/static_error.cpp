// 类声明外部的说明符无效

virtual static void fun()
{
}

// 非成员函数上不允许使用类型限定符
static void fun() const
{
}