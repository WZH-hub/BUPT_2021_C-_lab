#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0, int aa = 0, int bb = 0)
    {
        x = xx;
        y = yy;
        a = aa;
        b = bb;
    }
    double distance()
    {
        double dx = x - a;
        double dy = y - b;
        return sqrt(dx * dx + dy * dy);
    }

private:
    int x, y, a, b;
};

class Circle
{
public:
    Circle(int xx = 0, int yy = 0, int rr = 0)
    {
        x = xx;
        y = yy;
        r = rr;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    int getR()
    {
        return r;
    }

private:
    int x, y, r;
};

int main()
{

    int x, y, a, b, r1, r2;
    cout << "please input the first circle's data:" << endl;
    cout << "The center is:" << endl;
    cin >> x >> y;
    cout << "The radius is:" << endl;
    cin >> r1;

    cout << "please input the second circle's data:" << endl;
    cout << "The center is:" << endl;
    cin >> a >> b;
    cout << "The radius is:" << endl;
    cin >> r2;

    Circle A(x, y, r1), B(a, b, r2);
    Point C(x, y, a, b);
    double distance = C.distance();
    if (distance < (r1 + r2) && distance > abs(r1 - r2))
        cout << "intersect" << endl;
    else
        cout << "not intersect" << endl;
    return 0;
}