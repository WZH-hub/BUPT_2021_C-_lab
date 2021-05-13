/*
5.2 对Point类重载＋＋和――运算符
 编写C++程序完成以下功能：
（1） Point 类的属性包括点的坐标（x，y）；
（2） 实现 Point 类重载＋＋和――运算符：
? ++p，--p，p++，p--；
? ＋＋和――分别表示 x，y 增加或减少 1
*/
#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    void set(int a, int b)
    {
        x = a;
        y = b;
    }
    void out()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }

    Point()
    {
        cout << "这是Point类的构造函数" << endl;
    }
    ~Point()
    {
        cout << "这是Point类的析构函数" << endl;
    }

    Point operator++(int) //p++
    {
        Point z = *this;
        x += 1;
        y += 1;
        return z;
    }
    Point operator--(int) //p--
    {
        Point z = *this;
        x -= 1;
        y -= 1;
        return z;
    }
    Point operator++() //++p
    {
        x += 1;
        y += 1;
        return *this;
    }
    Point operator--() //--p
    {
        x -= 1;
        y -= 1;
        return *this;
    }
};

int main()
{
    Point p;
    int x, y, r;
    cout << "Please input the x and y:" << endl;
    cin >> x >> y;
    p.set(x, y);
    cout << "p(x,y)=";
    p.out();

    cout << "please input the flag(1,2,3,4):" << endl;
    cin >> r;
    switch (r)
    {
    case 1:
        cout << "p++(x,y)=";
        p++.out();
        // p.out();
        break;
    case 2:
        cout << "p--(x,y)=";
        p--.out();
        p.out();
        break;
    case 3:
        cout << "++p(x,y)=";
        (++p).out();
        break;
    case 4:
        cout << "--p(x,y)=";
        (--p).out();
        break;
    default:
        cout << "error" << endl;
        break;
    }
    return 0;
}