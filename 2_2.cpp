#include <iostream>
using namespace std;

class Array
{
private:
    int lines, rows;

public:
    int **array;                   //二维数组指针
    void init();                   //初始化函数
    void output();                 //输出函数
    void plus(Array &a, Array &b); //矩阵相加函数
    void sub(Array &a, Array &b);  //矩阵相减函数

    Array();             //默认构造含糊，动态申请一个数组，不带参数，需要用户输入行列
    Array(int x, int y); //构造函数，动态申请矩阵，以行列为参数
};