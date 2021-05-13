/*
5.2 ��Point�����أ����ͨD�D�����
 ��дC++����������¹��ܣ�
��1�� Point ������԰���������꣨x��y����
��2�� ʵ�� Point �����أ����ͨD�D�������
? ++p��--p��p++��p--��
? �����ͨD�D�ֱ��ʾ x��y ���ӻ���� 1
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
        cout << "����Point��Ĺ��캯��" << endl;
    }
    ~Point()
    {
        cout << "����Point�����������" << endl;
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