#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char a[] = "hello world";
    cout << sizeof(a) << endl;
    cout << strlen(a) << endl;

    string str = "hello world";
    cout << strlen(str) << endl;
    return 0;
}