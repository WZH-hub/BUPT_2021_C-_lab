/*
2.2 编写C++程序完成“矩阵”类以下功能：
（1） 用类来实现矩阵，定义一个矩阵的类，属性包括：
 矩阵大小，用 lines, rows（行、列来表示）；
 存贮矩阵的数组指针，根据矩阵大小动态申请（new）。
（2） 矩阵类的方法包括：
 构造函数，参数是矩阵大小，需要动态申请存贮矩阵的数组；
 析构函数，需要释放矩阵的数组指针；
 拷贝构造函数，需要申请和复制数组；
 输入，可以从 cin 中输入矩阵元素；
 输出，将矩阵格式化输出到 cout；
 矩阵相加的函数，实现两个矩阵相加的功能，结果保存在另一个矩阵类，
但必须矩阵大小相同；
 矩阵相减的函数，实现两个矩阵相减的功能，结果保存在另一个矩阵类，
但必须矩阵大小相同。
（3） 定义三个矩阵：A1、A2、A3；
（4） 初始化 A1、A2；2
（5） 计算并输出 A3 = A1 加 A2，A3=A1 减 A2；（要求及提示：最好能实现对赋值
操作符“=”的重载；注意检查“自赋值”、释放“旧元素”）
（6） 用 new 动态创建三个矩阵类的对象：pA1、pA1、pA3；
（7） 初始化 pA1、pA2；
（8） 计算并输出 pA3=pA1 加 pA2，pA3=pA1 减 pA2；
（9） 释放 pA1、pA2、pA3。
*/
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
//初始化矩阵，输入矩阵元素
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
//输出矩阵中的元素
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
//矩阵相加函数
void Array::plus(Array a, Array b)
{
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            this->array[i][j] = a.array[i][j] + b.array[i][j];
        }
    }
}
//矩阵相减函数
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
//Array类的构造函数
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
    cout << "这是Array类的构造函数" << endl;
}
//Array类的含参构造函数
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
    cout << "这是Array类的含参构造函数" << endl;
}
//拷贝构造函数
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
    cout << "这是Array类的拷贝构造函数" << endl;
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
    cout << "这是Array类的析构函数" << endl;
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

    //A3.plus(A1, A2);
    A3 = operator+(A1 + A2);
    cout << "矩阵A3=A1+A2：" << endl;
    A3.output();
    A3.sub(A1, A2);
    cout << "矩阵A3=pA1-pA2：" << endl;
    A3.output();
    A1.output();
    A2.output();

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