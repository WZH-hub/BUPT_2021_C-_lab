#include <iostream>
using namespace std;

class inc1
{
    int num;

public:
    inc1(int i) : num(i) { cout << "构造inc1\n"; }
};

class inc2
{
    int num;

public:
    inc2(int i) : num(i) { cout << "构造inc2\n"; }
};

class out_c
{
    inc1 c1;
    inc2 c2;

public:
    out_c(int i, int j) : c2(i), c1(j) { cout << "有参构造out_c\n"; }
};

int main()
{
    out_c aoc2(1, 2);
}