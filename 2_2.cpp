#include <iostream>
using namespace std;

class Array
{
private:
    int lines, rows;

public:
    Array(int xx = 0, int yy = 0)
    {
        lines = xx;
        rows = yy;
        int(*array_a)[rows] = new int[lines][rows       ];
    }
};