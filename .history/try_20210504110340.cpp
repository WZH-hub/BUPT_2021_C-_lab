#include <iostream>
using namespace std;

class Bird
{
public:
    void eat() { cout << "鸟吃食物" << endl; }
    virtual void fly() { cout << "鸟飞行" << endl; }
};
class Penguin : public Bird
{ //is-a
public:
    virtual void fly() override { cout << "俺不会飞" << endl; }
};
void main()
{
    Penguin q;
    q.fly(); //俺不会飞
    Bird *b = &q;
    b->fly(); //俺不会飞
}