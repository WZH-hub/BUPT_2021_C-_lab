#include <iostream>
using namespace std;

class Array
{
private:
    int lines, rows;

public:
    int **array;                 //二维数组指针
    void init();                 //初始化函数
    void output();               //输出函数
    void plus(Array a, Array b); //矩阵相加函数
    void sub(Array a, Array b);  //矩阵相减函数

    Array(); //默认构造含糊，动态申请一个数组，不带参数，需要用户输入行列

    Array(int x, int y);       //构造函数，动态申请矩阵，以行列为参数
    Array(Array &a);           //拷贝构造函数，申请和复制数组
    ~Array();                  //析构函数，释放空间
    Array &operator=(Array &m) //重载运算符=
    {
        if (array != nullptr)
        {
            delete array;
            array = nullptr;
        }
        array = new int *[lines];
        int i = 0, j = 0;
        for (i = 0; i < lines; i++)
        {
            array[i] = new int[rows];
        }
        for (i = 0; i < lines; i++)
        {
            for (j = 0; j < rows; j++)
            {
                this->array[i][j] = m.array[i][j];
            }
        }
        return *this;
    }
};

void Array::init()
{
    cout << "请输入矩阵元素：" << endl;
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            cin >> this->array[i][j];
        }
    }
}

void Array::output()
{
    cout << "输出矩阵元素：" << endl;
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            cout << this->array[i][j] << " ";
        }
        cout << endl;
    }
}

void Array::plus(Array a, Array b)
{
    int i = 0, j = 0;
    cout << "~~~~~~~" << endl;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            this->array[i][j] = a.array[i][j] + b.array[i][j];
        }
    }
}

void Array::sub(Array a, Array b)
{
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            this->array[i][j] = a.array[i][j] - b.array[i][j];
        }
    }
}

Array::Array()
{
    cout << "请输入矩阵的行数和列数：" << endl;
    cin >> lines >> rows;
    this->lines = lines;
    this->rows = rows;
    this->array = new int *[lines];
    int i = 0;
    for (i = 0; i < lines; i++)
    {
        this->array[i] = new int[rows];
    }
}

Array::Array(int x, int y)
{
    this->lines = x;
    this->rows = y;
    this->array = new int *[lines];
    int i = 0;
    for (i = 0; i < lines; i++)
    {
        this->array[i] = new int[rows];
    }
}

Array::Array(Array &a)
{
    this->lines = a.lines;
    this->rows = a.rows;
    this->array = new int *[lines];
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        this->array[i] = new int[rows];
    }
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            this->array[i][j] = a.array[i][j];
        }
    }
}

Array::~Array()
{
    if (this->array != nullptr)
    {
        int i = 0;
        for (i = 0; i < this->lines; i++)
        {
            delete[] array[i];
        }
        delete[] array;
        this->array = nullptr;
    }
}

int main()
{
    int lines = 0, rows = 0;
    cout << "请输入行数：";
    cin >> lines;
    cout << endl;
    cout << "请输入列数：";
    cin >> rows;
    cout << endl;
    Array A1(lines, rows);
    Array A2(lines, rows);
    Array A3(lines, rows);

    cout << "请输入矩阵A1" << endl;
    A1.init();
    A1.output();
    cout << "请输入矩阵A2" << endl;
    A2.init();
    A2.output();

    A3.plus(A1, A2);
    cout << "矩阵A3=A1+A2：" << endl;
    A3.output();
    A3.sub(A1, A2);
    cout << "矩阵A3=pA1-pA2：" << endl;
    A3.output();

    //使用new动态创建三个矩阵类的对象
    Array *pA1 = new Array(lines, rows);
    Array *pA2 = new Array(lines, rows);
    Array *pA3 = new Array(lines, rows);
    cout << "请输入矩阵pA1" << endl;
    pA1->init();
    cout << "请输入矩阵pA2" << endl;
    pA2->init();

    pA3->plus(*pA1, *pA2);
    cout << "矩阵pA3=pA1+pA2：" << endl;
    pA3->output();
    pA3->sub(*pA1, *pA2);
    cout << "矩阵pA3=pA1-pA2：" << endl;
    pA3->output();

    //释放pA1,pA2,pA3
    delete pA1;
    delete pA2;
    delete pA3;

    return 0;
}