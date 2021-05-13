/*
3、继承与派生实验
编写C++程序完成“形状”的以下功能：
（1） 声明一个基类 Shape（形状），其中包含一个方法来计算面积；
（2） 从 Shape 派生两个类：矩形类和圆形类；
（3） 从矩形类派生正方形类；
（4） 分别实现派生类构造函数、析构函数和其他方法；
（5） 创建派生类的对象，观察构造函数、析构函数调用次序；
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察
相关调用；可以使用 system("pause")进行程序的暂停；2，能够理解并说明每
一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及
其原因）
（6） 对不同对象计算面积。
*/
#include <iostream>

#define pi 3.14
using namespace std;

class shape
{
public:
    float area() { return 0; } //计算面积的函数
    shape()
    {
        cout << "这是shape类的构造函数" << endl;
    }
    ~shape()
    {
        cout << "这是shape类的析构函数" << endl;
    }
};

class rectangle : public shape
{
private:
    float length, wide; //长和宽

public:
    rectangle(float a, float b)
    {
        length = a;
        wide = b;
        cout << "这是rectangle类的构造函数" << endl;
    }
    ~rectangle()
    {
        cout << "这是rectangle类的析构函数" << endl;
    }
    float area()
    {
        return length * wide;
    }
};

class circle : public shape
{
private:
    float r;

public:
    circle(float a)
    {
        r = a;
        cout << "这是circle类的构造函数" << endl;
    }
    ~circle()
    {
        cout << "这是circle类的析构函数" << endl;
    }
    float area()
    {
        return pi * r * r;
    }
};

class square : public rectangle
{
private:
    float side;

public:
    square(float a) : rectangle(a, a)
    {
        side = a;
        cout << "这是square类的构造函数" << endl;
    }
    ~square()
    {
        cout << "这是square类的析构函数" << endl;
    }
};

int main()
{
    cout << "创建矩形的类：" << endl;
    float a, b;
    cout << "输入矩形的长和宽：" << endl;
    cin >> a >> b;
    rectangle R(a, b);
    cout << "矩形的面积是：" << R.area() << endl;

    cout << "创建圆形的类：" << endl;
    float r;
    cout << "输入圆的半径" << endl;
    cin >> r;
    circle C(r);
    cout << "圆形的面积是：" << C.area() << endl;

    cout << "创建正方形的类：" << endl;
    float s;
    cout << "输入正方形的边长" << endl;
    cin >> s;
    square S(s);
    cout << "正方形的面积是：" << S.area() << endl;

    return 0;
}