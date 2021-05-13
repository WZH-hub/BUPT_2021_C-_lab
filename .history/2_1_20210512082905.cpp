/*
2.1��дC++������ɡ�Բ�Ρ����¹��ܣ�
��1�� ����һ�� Point �࣬�����԰���������꣬�ṩ��������֮�����ķ�����
��Ҫ���û���������������ʱ���ܹ�Ĭ��Ϊ����ԭ�㣨0��0����
��2�� ����һ��Բ���࣬�����԰���Բ�ĺͰ뾶��
��3�� ��������Բ�ζ�����ʾ�û�����Բ������Ͱ뾶���ж�����Բ�Ƿ��ཻ��
����������
��4�� �۲�Բ�ζ����Լ� Point ���Ա�Ĺ��캯�������������ĵ��á�
����ʾ��Ҫ��1����ͨ���ڹ��������������м��������ʾ��Ϣ�ķ�ʽ�۲�
��ص��ã�����ʹ�� system("pause")���г������ͣ��2���ܹ���Ⲣ˵��ÿ
һ�ι��������������������ĸ�����ĵ��ã����۲�ͽ�����ص���˳��
��ԭ��
*/
#include <iostream>
#include <math.h>

using namespace std;

class Point
{
public:
    int x, y; //x,yΪ��ĺ�������
    Point(int xx = 0, int yy = 0, int aa = 0, int bb = 0)
    {
        x = xx;
        y = yy;
        cout << "����Point��Ĺ��캯��" << endl;
    }
    ~Point()
    {
        cout << "��Point�����������" << endl;
    }
    double distance(const int x, const int y, int a, int b) //������֮��ľ���ĺ���
    {
        double dx = x - a;
        double dy = y - b;
        return sqrt(dx * dx + dy * dy);
    }
};

class Circle
{
public:
    Point z; //��ʾԲ������
    int r;   //��ʾԲ�İ뾶
    Circle(int xx = 0, int yy = 0, int rr = 0)
    {
        z.x = xx;
        z.y = yy;
        r = rr;
        cout << "����Circle��Ĺ��캯��" << endl;
    }
    ~Circle()
    {
        cout << "��Circle�����������" << endl;
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