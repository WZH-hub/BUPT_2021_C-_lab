/*
4��I/O ��ʵ��
��д C++������ɲ¼۸���Ϸ�����¹��ܣ�
��1�� �ٶ���һ����Ʒ�������������ָ������Ʒ�ļ۸�1-1000 ����������
��2�� ��ʾ�û��¼۸񣬲����룺���û��µļ۸����Ʒ�۸�߻�ͣ����û�����
��Ӧ����ʾ��
��3�� ֱ���¶�Ϊֹ����������ʾ��
����ʾ��Ҫ��1��Ҫ��ʹ�� C++�����������ʽ��cin, cout��������ʹ�� C ��
�Ե� printf �ȣ�2��ע��������ĺϷ��ԣ�
*/
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    cout << "��ʼ���뾺�¼۸���Ϸ" << endl;
    srand(time(NULL));
    int price = (1 + rand() % 1000);
    int input;
    cout << "���������ļ۸�";
    cin >> input;
    if (input > 1000 || input <= 0 || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear(); //����cin��״̬��ʶ��
            cin.sync();  //�����������������
        }
        cout << "����ȷ���룬������[1,1000]������" << endl;
        cout << "���ٴ��������ļ۸�";
        cin >> input;
    }
    while (input != price)
    {
        if (input > price)
            cout << "����ļ۸����" << endl;
        else if (input < price)
            cout << "����ļ۸����" << endl;

        cout << "���ٴ��������ļ۸�";
        cin >> input;
        if (input > 1000 || input <= 0 || cin.fail())
        {
            if (cin.fail())
            {
                cin.clear(); //����cin��״̬��ʶ��
                cin.sync();  //�����������������
            }
            cout << "����ȷ���룬������[1,1000]������" << endl;
            cout << "���ٴ��������ļ۸�";
            cin >> input;
        }
    }
    cout << "Congratulations���¶��ˣ�" << endl;
    return 0;
}
