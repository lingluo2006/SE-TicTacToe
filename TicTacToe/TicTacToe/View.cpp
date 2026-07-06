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

void View::showMessage(const char* msg)
{
    cout << msg << endl;
}

void View::getInput(int& x, int& y, char player)
{
    cout << "Íæ¼Ò " << player << " ÊäÈë×ø±ê(x y)£º";
    cin >> x >> y;
}