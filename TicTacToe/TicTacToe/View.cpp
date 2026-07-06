#include "View.h"
#include <iostream>

using namespace std;

void View::showBoard(const Board& board)
{
    cout << "-------------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board.get(i, j) << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

void View::showMessage(const std::string& msg)
{
    cout << msg << endl;
}

void View::getInput(int& x, int& y)
{
    while (true)
    {
        cout << "ÇëÒÀ´ÎÊäÈë×ø±ê (x y)£¬·¶Î§[0-2]£º";

        cin >> x >> y;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "ÊäÈë´íÎó£¬ÇëÊäÈëÊý×Ö£¡" << endl;
            continue;
        }

        if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
            break;

        cout << "·¶Î§´íÎó£¬ÇëÖØÐÂÊäÈë£¡" << endl;
    }
}