#include <iostream>
#include "Controller.h"
#include "Board.h"

using namespace std;

void Controller::run()
{
    Board board;
    board.reset();

    char player = 'X';
    int x, y;

    while (true)
    {
        board.print();

        cout << "玩家 " << player << " 输入坐标: ";
        cin >> x >> y;

        if (!board.place(x, y, player))
        {
            cout << "无效位置！" << endl;
            continue;
        }

        if (board.checkWin(player))
        {
            board.print();
            cout << "玩家 " << player << " 赢了！" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }
}