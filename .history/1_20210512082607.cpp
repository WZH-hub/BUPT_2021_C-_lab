/*
��дC++������ɡ��������¹��ܣ�
��1�� �ٶ������СΪ 4��5�����ͣ���
��2�� ����ռ���� new ��̬���룬������ָ���У�
��3�� ��������ʼ�����������Դ� cin ���������Ԫ�أ�
��4�� �����������������������ʽ������� cout��
��5�� ���������ӵĺ�����ʵ������������ӵĹ��ܣ������������һ�������У�
��6�� �����������ĺ�����ʵ��������������Ĺ��ܣ������������һ�������У�
��7�� ��̬������������A1��A2��A3��
��8�� ��ʼ�� A1��A2��
��9�� ���㲢��� A3 = A1 �� A2��A3 = A1 �� A2��
��10�� �ͷž���ռ䡣
*/
#include <iostream>

using namespace std;

void initial(int array_a[][5]);                                      //��ʼ���������������Ԫ�ص���Ϣ
void output(const int array_b[][5]);                                       //�������ڵ�Ԫ�����
void find_sum(int array_a[][5], int array_b[][5], int array_c[][5]); //����������ĺͣ��������ڵ�����������
void find_sub(int array_a[][5], int array_b[][5], int array_c[][5]); //����������Ĳ�������ڵ�����������

int main()
{
    int(*array_a)[5] = new int[4][5];
    int(*array_b)[5] = new int[4][5];
    int(*array_c)[5] = new int[4][5];

    cout << "initial array_a(4*5)" << endl;
    initial(array_a);
    cout << "initial array_b(4*5)" << endl;
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

//��ʼ���������������Ԫ�ص���Ϣ
void initial(int array_a[][5])
{
    int num = 0;
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

//�������ڵ�Ԫ�����
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

//����������ĺͣ��������ڵ�����������
void find_sum(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] + array_b[i][j];
        }
    }
}

//����������Ĳ�������ڵ�����������
void find_sub(int array_a[][5], int array_b[][5], int array_c[][5])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            array_c[i][j] = array_a[i][j] - array_b[i][j];
        }
    }
}