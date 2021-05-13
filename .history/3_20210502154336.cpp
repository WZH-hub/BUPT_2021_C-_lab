/*
3���̳�������ʵ��
��дC++������ɡ���״�������¹��ܣ�
��1�� ����һ������ Shape����״�������а���һ�����������������
��2�� �� Shape ���������ࣺ�������Բ���ࣻ
��3�� �Ӿ����������������ࣻ
��4�� �ֱ�ʵ�������๹�캯������������������������
��5�� ����������Ķ��󣬹۲칹�캯���������������ô���
����ʾ��Ҫ��1����ͨ���ڹ��������������м��������ʾ��Ϣ�ķ�ʽ�۲�
��ص��ã�����ʹ�� system("pause")���г������ͣ��2���ܹ���Ⲣ˵��ÿ
һ�ι��������������������ĸ�����ĵ��ã����۲�ͽ�����ص���˳��
��ԭ��
��6�� �Բ�ͬ������������
*/
#include <iostream>

#define pi 3.14
using namespace std;

class shape
{
public:
    float area() { return 0; } //��������ĺ���
    shape()
    {
        cout << "����shape��Ĺ��캯��" << endl;
    }
    ~shape()
    {
        cout << "����shape�����������" << endl;
    }
};

class rectangle : public shape
{
private:
    float length, wide; //���Ϳ�

public:
    rectangle(float a, float b)
    {
        length = a;
        wide = b;
        cout << "����rectangle��Ĺ��캯��" << endl;
    }
    ~rectangle()
    {
        cout << "����rectangle�����������" << endl;
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
        cout << "����circle��Ĺ��캯��" << endl;
    }
    ~circle()
    {
        cout << "����circle�����������" << endl;
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
        cout << "����square��Ĺ��캯��" << endl;
    }
    ~square()
    {
        cout << "����square�����������" << endl;
    }
};

int main()
{
    cout << "�������ε��ࣺ" << endl;
    float a, b;
    cout << "������εĳ��Ϳ�" << endl;
    cin >> a >> b;
    rectangle R(a, b);
    cout << "���ε�����ǣ�" << R.area() << endl;

    cout << "����Բ�ε��ࣺ" << endl;
    float r;
    cout << "����Բ�İ뾶" << endl;
    cin >> r;
    circle C(r);
    cout << "Բ�ε�����ǣ�" << C.area() << endl;

    cout << "���������ε��ࣺ" << endl;
    float s;
    cout << "���������εı߳�" << endl;
    cin >> s;
    square S(s);
    cout << "�����ε�����ǣ�" << S.area() << endl;

    return 0;
}