#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class Type
{
private:
    int num = 0;

public:
    int getnum()
    {
        printf("  num:%d  \n", num);
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
    a.change();
    a.getnum();
    a.change();
    a.getnum();
    return 0;
}