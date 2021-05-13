#include <iostream>
#include <string.h>
using namespace std;

void fcn1(const int &i) {} // fcn1保证不会修改i的值;
void fcn2(int &i) {}
int int main(int argc, const char** argv) {
    return 0;
}()
{
    int i;
    fcn1(i);
    fcn1(45);     //正确，可以把字面值传递给常量引用
    fcn1(45 * i); //正确，可以把表达式的值传递给常量引用
    //fcn2(45); //错误
    //fcn2(45*i); //错误
}