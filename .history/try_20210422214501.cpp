#include <iostream>
using namespace std;

class inc1
{
    int num;

public:
    inc1(int i) : num(i) { cout << "����inc1\n"; }
};

class inc2
{
    int num;

public:
    inc2(int i) : num(i) { cout << "����inc2\n"; }
};

class out_c
{
    inc1 c1;
    inc2 c2;

public:
    out_c(int i, int j) : c2(i), c1(j) { cout << "�вι���out_c\n"; }
};

int main()
{
    int x = 2, y = 2;
    printf("++x=%d \n", ++x);
    printf("x=%d\n",x);
    printf("y++=%d \n", y++);
    printf("y=%d\n",y);
    return 0;
}