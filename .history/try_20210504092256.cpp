#include <iostream>
using namespace std;

class vBase
{
public:
    virtual char test() = 0;
};
class vExtend : public vBase
{
public:
    char test() { return 'c'; }
};
int main()
{
    vExtend a;
    a.test();
}