/*
2.2 ��дC++������ɡ����������¹��ܣ�
��1�� ������ʵ�־��󣬶���һ��������࣬���԰�����
 �����С���� lines, rows���С�������ʾ����
 �������������ָ�룬���ݾ����С��̬���루new����
��2�� ������ķ���������
 ���캯���������Ǿ����С����Ҫ��̬���������������飻
 ������������Ҫ�ͷž��������ָ�룻
 �������캯������Ҫ����͸������飻
 ���룬���Դ� cin ���������Ԫ�أ�
 ������������ʽ������� cout��
 ������ӵĺ�����ʵ������������ӵĹ��ܣ������������һ�������࣬
����������С��ͬ��
 ��������ĺ�����ʵ��������������Ĺ��ܣ������������һ�������࣬
����������С��ͬ��
��3�� ������������A1��A2��A3��
��4�� ��ʼ�� A1��A2��2
��5�� ���㲢��� A3 = A1 �� A2��A3=A1 �� A2����Ҫ����ʾ�������ʵ�ֶԸ�ֵ
��������=�������أ�ע���顰�Ը�ֵ�����ͷš���Ԫ�ء���
��6�� �� new ��̬��������������Ķ���pA1��pA1��pA3��
��7�� ��ʼ�� pA1��pA2��
��8�� ���㲢��� pA3=pA1 �� pA2��pA3=pA1 �� pA2��
��9�� �ͷ� pA1��pA2��pA3��
*/
#include <iostream>
using namespace std;

class Array
{
private:
    int lines, rows;

public:
    int **array;                 //��ά����ָ��
    void init();                 //��ʼ������
    void output();               //�������
    void plus(Array a, Array b); //������Ӻ���
    void sub(Array a, Array b);  //�����������

    Array(); //Ĭ�Ϲ��캬������̬����һ�����飬������������Ҫ�û���������

    Array(int x, int y);       //���캯������̬�������������Ϊ����
    Array(Array &a);           //�������캯��������͸�������
    ~Array();                  //�����������ͷſռ�
    Array &operator=(Array &m) //���������=
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
//��ʼ�������������Ԫ��
void Array::init()
{
    cout << "���������Ԫ�أ�" << endl;
    int i = 0, j = 0;
    for (i = 0; i < this->lines; i++)
    {
        for (j = 0; j < this->rows; j++)
        {
            cin >> this->array[i][j];
        }
    }
}
//��������е�Ԫ��
void Array::output()
{
    cout << "�������Ԫ�أ�" << endl;
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
//������Ӻ���
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
//�����������
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
//Array��Ĺ��캯��
Array::Array()
{
    cout << "����������������������" << endl;
    cin >> lines >> rows;
    this->lines = lines;
    this->rows = rows;
    this->array = new int *[lines];
    int i = 0;
    for (i = 0; i < lines; i++)
    {
        this->array[i] = new int[rows];
    }
    cout << "����Array��Ĺ��캯��" << endl;
}
//Array��ĺ��ι��캯��
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
    cout << "����Array��ĺ��ι��캯��" << endl;
}
//�������캯��
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
    cout << "����Array��Ŀ������캯��" << endl;
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
    cout << "����Array�����������" << endl;
}

int main()
{
    int lines = 0, rows = 0;
    cout << "������������";
    cin >> lines;
    cout << endl;
    cout << "������������";
    cin >> rows;
    cout << endl;
    Array A1(lines, rows);
    Array A2(lines, rows);
    Array A3(lines, rows);

    cout << "���������A1" << endl;
    A1.init();
    A1.output();
    cout << "���������A2" << endl;
    A2.init();
    A2.output();

    //A3.plus(A1, A2);
    A3 = operator+(A1 + A2);
    cout << "����A3=A1+A2��" << endl;
    A3.output();
    A3.sub(A1, A2);
    cout << "����A3=pA1-pA2��" << endl;
    A3.output();
    A1.output();
    A2.output();

    //ʹ��new��̬��������������Ķ���
    Array *pA1 = new Array(lines, rows);
    Array *pA2 = new Array(lines, rows);
    Array *pA3 = new Array(lines, rows);
    cout << "���������pA1" << endl;
    pA1->init();
    cout << "���������pA2" << endl;
    pA2->init();

    pA3->plus(*pA1, *pA2);
    cout << "����pA3=pA1+pA2��" << endl;
    pA3->output();
    pA3->sub(*pA1, *pA2);
    cout << "����pA3=pA1-pA2��" << endl;
    pA3->output();

    //�ͷ�pA1,pA2,pA3
    delete pA1;
    delete pA2;
    delete pA3;

    return 0;
}