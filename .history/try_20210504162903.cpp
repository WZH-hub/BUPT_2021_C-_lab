#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char a[] = "hello world";
    cout << sizeof(a) << endl;
    cout << strlen(a) << endl;

    string str = "hello world";
    cout << sizeof(str) << endl;
    return 0;
}