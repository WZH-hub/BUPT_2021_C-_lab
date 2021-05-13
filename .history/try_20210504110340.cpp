#include <iostream>
using namespace std;

class Bird
{
public:
    void eat() { cout << "���ʳ��" << endl; }
    virtual void fly() { cout << "�����" << endl; }
};
class Penguin : public Bird
{ //is-a
public:
    virtual void fly() override { cout << "�������" << endl; }
};
void main()
{
    Penguin q;
    q.fly(); //�������
    Bird *b = &q;
    b->fly(); //�������
}