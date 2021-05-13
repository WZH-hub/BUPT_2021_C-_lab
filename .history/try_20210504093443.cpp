#include <iostream>
using namespace std;

class vBase
{
public:
    virtual char test();
};
class vExtend : public vBase
{
public:
    char test() override {}
    override;
};

int main()
{
    vExtend a;
}