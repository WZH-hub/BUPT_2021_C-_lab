#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Type
{
private:
    int num;

public:
    int getnum()
    {
        printf("  num:%d  ", num);
    }
    void change()
    {
        int now;
        cin >> now;
        num = now;
    }
};

int main()
{
    Type a;
    a.chane();
    a.getnum();
    a.
}