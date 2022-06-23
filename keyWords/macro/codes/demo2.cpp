#include <iostream>

using namespace std;

#define expA(s) printf("前缀加上后的字符串为:%s\n", gc_##s) // gc_s 必须存在
// 注意事项 2
#define expB(s) printf("前缀加上后的字符串为:%s\n", gc_##s) // gc_s 必须存在
// 注意事项 1
#define gc_hello1 "I am gc_hello1"

int main()
{
    // 注意事项1
    const char *gc_hello = "I am gc_hello";
    expA(hello);
    expB(hello1);
}