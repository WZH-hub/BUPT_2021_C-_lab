#include <iostream>
using namespace std;

class Array
{
private:
    int lines, rows;

public:
    int **array;                   //��ά����ָ��
    void init();                   //��ʼ������
    void output();                 //�������
    void plus(Array &a, Array &b); //������Ӻ���
    void sub(Array &a, Array &b);  //�����������

    Array();             //Ĭ�Ϲ��캬������̬����һ�����飬������������Ҫ�û���������
    Array(int x, int y); //���캯������̬�������������Ϊ����
};