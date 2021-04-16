#include <iostream>

using namespace std;

void initial(int array_a[][5]);
void output(int array_b[][5]);
void find_sum(int array_a[][5], int array_b[][5], int array_c[][5]);
void find_sub(int array_a[][5], int array_b[][5], int array_c[][5]);

int main()
{
    int(*array_a)[5] = new int[4][5];
    int(*array_b)[5] = new int[4][5];
    int(*array_c)[5] = new int[4][5];

    cout << "initial array_a" << endl;
    initial(array_a);
    cout << "initial array_b" << endl;
    initial(array_b);

    cout << "find sum" << endl;
    find_sum(array_a, array_b, array_c);
    output(array_c);

    cout << "find sub" << endl;
    find_sub(array_a, array_b, array_c);
    output(array_c);

    delete[] array_a;
    array_a = nullptr;
    delete[] array_b;
    array_b = nullptr;
    delete[] array_c;
    array_c = nullptr;
}

void initial(int array_a[][5])
{
    int num;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> num;
            array_a[i][j] = num;
        }
    }
}

void output(int array_b[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout << array_b[i][j] << " ";
        }
        cout << "\n";
    }
}

void find_sum(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int num;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] + array_b[i][j];
        }
    }
}

void find_sub(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int num;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] - array_b[i][j];
        }
    }
}