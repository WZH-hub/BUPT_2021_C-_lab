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
