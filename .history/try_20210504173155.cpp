#include <iostream>
#include <string.h>
using namespace std;

void fcn1(const int &i) {} // fcn1��֤�����޸�i��ֵ;
void fcn2(int &i) {}
int int main(int argc, const char** argv) {
    return 0;
}()
{
    int i;
    fcn1(i);
    fcn1(45);     //��ȷ�����԰�����ֵ���ݸ���������
    fcn1(45 * i); //��ȷ�����԰ѱ��ʽ��ֵ���ݸ���������
    //fcn2(45); //����
    //fcn2(45*i); //����
}