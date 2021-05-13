#include <iostream>
using namespace std;

class vBase
{
public:
    virtual void test();
};
class vExtend : public vBase
{
public:
    void test() override;
};

int main()
{
    vExtend a;
    return 0;
}