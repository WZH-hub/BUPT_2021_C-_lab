/*
4、I/O 流实验
编写 C++程序完成猜价格游戏的以下功能：
（1） 假定有一件商品，程序用随机数指定该商品的价格（1-1000 的整数）；
（2） 提示用户猜价格，并输入：若用户猜的价格比商品价格高或低，对用户作出
相应的提示；
（3） 直到猜对为止，并给出提示。
（提示及要求：1，要求使用 C++的输入输出方式（cin, cout），不能使用 C 语
言的 printf 等；2，注意检查输入的合法性）
*/
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
