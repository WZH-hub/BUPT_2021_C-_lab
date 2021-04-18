#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    cout << "开始进入竞猜价格游戏" << endl;
    srand(time(NULL));
    int price = (1 + rand() % 1000);
    int input;
    cout << "请输入猜想的价格：";
    cin >> input;
    if (input > 1000 || input <= 0 || cin.fail())
    {
        if (cin.fail())
        {
            cin.clear(); //更改cin的状态标识符
            cin.sync();  //清除缓冲区的数据流
        }
        cout << "不正确输入，请输入[1,1000]的数字" << endl;
        cout << "请再次输入猜想的价格：";
        cin >> input;
    }
    while (input != price)
    {
        if (input > price)
            cout << "猜想的价格过高" << endl;
        else if (input < price)
            cout << "猜想的价格过低" << endl;

        cout << "请再次输入猜想的价格：";
        cin >> input;
        if (input > 1000 || input <= 0 || cin.fail())
        {
            if (cin.fail())
            {
                cin.clear(); //更改cin的状态标识符
                cin.sync();  //清除缓冲区的数据流
            }
            cout << "不正确输入，请输入[1,1000]的数字" << endl;
            cout << "请再次输入猜想的价格：";
            cin >> input;
        }
    }
    cout << "Congratulations！猜对了！" << endl;
    return 0;
}
