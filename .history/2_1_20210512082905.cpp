/*
2.1编写C++程序完成“圆形”以下功能：
（1） 定义一个 Point 类，其属性包括点的坐标，提供计算两点之间距离的方法；
（要求当用户不输入坐标数据时，能够默认为坐标原点（0，0））
（2） 定义一个圆形类，其属性包括圆心和半径；
（3） 创建两个圆形对象，提示用户输入圆心坐标和半径，判断两个圆是否相交，
并输出结果；
（4） 观察圆形对象以及 Point 类成员的构造函数与析构函数的调用。
（提示及要求：1，可通过在构造与析构函数中加入输出提示信息的方式观察
相关调用；可以使用 system("pause")进行程序的暂停；2，能够理解并说明每
一次构造与析构函数调用是哪个对象的调用，并观察和解释相关调用顺序及
其原因）
*/
#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    int x, y; //x,y为点的横纵坐标
    Point(int xx = 0, int yy = 0, int aa = 0, int bb = 0)
    {
        x = xx;
        y = yy;
        cout << "这是Point类的构造函数" << endl;
    }
    ~Point()
    {
        cout << "这Point类的析构函数" << endl;
    }
    double distance(const int x, const int y, int a, int b) //求两点之间的距离的函数
    {
        double dx = x - a;
        double dy = y - b;
        return sqrt(dx * dx + dy * dy);
    }
};

class Circle
{
public:
    Point z; //表示圆心坐标
    int r;   //表示圆的半径
    Circle(int xx = 0, int yy = 0, int rr = 0)
    {
        z.x = xx;
        z.y = yy;
        r = rr;
        cout << "这是Circle类的构造函数" << endl;
    }
    ~Circle()
    {
        cout << "这Circle类的析构函数" << endl;
    }
};

int main()
{

    Circle o1, o2;
    cout << "please input the first circle's data:" << endl;
    cout << "The center is:" << endl;
    cin >> o1.z.x >> o1.z.y;
    cout << "The radius is:" << endl;
    cin >> o1.r;

    cout << "please input the second circle's data:" << endl;
    cout << "The center is:" << endl;
    cin >> o2.z.x >> o2.z.y;
    cout << "The radius is:" << endl;
    cin >> o2.r;

    double distance = o1.z.distance(o1.z.x, o1.z.y, o2.z.x, o1.z.y);
    if (distance < (o1.r + o2.r) && distance > abs(o1.r - o2.r))
        cout << "intersect" << endl;
    else
        cout << "not intersect" << endl;
    return 0;
}