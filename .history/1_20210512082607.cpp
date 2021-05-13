/*
编写C++程序完成“矩阵”以下功能：
（1） 假定矩阵大小为 4×5（整型）；
（2） 矩阵空间采用 new 动态申请，保存在指针中；
（3） 定义矩阵初始化函数，可以从 cin 中输入矩阵元素；
（4） 定义矩阵输出函数，将矩阵格式化输出到 cout；
（5） 定义矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵中；
（6） 定义矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵中；
（7） 动态申请三个矩阵：A1、A2、A3；
（8） 初始化 A1、A2；
（9） 计算并输出 A3 = A1 加 A2，A3 = A1 减 A2；
（10） 释放矩阵空间。
*/
#include <iostream>

using namespace std;

void initial(int array_a[][5]);                                      //初始化矩阵，输入矩阵中元素的信息
void output(const int array_b[][5]);                                       //将矩阵内的元素输出
void find_sum(int array_a[][5], int array_b[][5], int array_c[][5]); //求两个矩阵的和，并保存在第三个矩阵中
void find_sub(int array_a[][5], int array_b[][5], int array_c[][5]); //求两个矩阵的差，并保存在第三个矩阵中

int main()
{
    int(*array_a)[5] = new int[4][5];
    int(*array_b)[5] = new int[4][5];
    int(*array_c)[5] = new int[4][5];

    cout << "initial array_a(4*5)" << endl;
    initial(array_a);
    cout << "initial array_b(4*5)" << endl;
    initial(array_b);

    cout << "find sum" << endl;
    find_sum(array_a, array_b, array_c);
    output(array_c);

    cout << "find sub" << endl;
    find_sub(array_a, array_b, array_c);
    output(array_c);

    delete[] array_a;
    array_a = nullptr;
    delete[] array_b;
    array_b = nullptr;
    delete[] array_c;
    array_c = nullptr;
}

//初始化矩阵，输入矩阵中元素的信息
void initial(int array_a[][5])
{
    int num = 0;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> num;
            array_a[i][j] = num;
        }
    }
}

//将矩阵内的元素输出
void output(int array_b[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << array_b[i][j] << " ";
        }
        cout << "\n";
    }
}

//求两个矩阵的和，并保存在第三个矩阵中
void find_sum(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] + array_b[i][j];
        }
    }
}

//求两个矩阵的差，并保存在第三个矩阵中
void find_sub(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] - array_b[i][j];
        }
    }
}