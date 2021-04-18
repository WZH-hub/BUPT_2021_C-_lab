#include <iostream>

#define pi 3.14
using namespace std;

class shape
{
public:
    float area() { return 0; }
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
    float length, wide;

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