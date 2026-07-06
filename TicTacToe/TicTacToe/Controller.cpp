#include "Controller.h"

void Controller::run()
{
    char player = 'X';
    int x, y;

    board.reset();

    while (true)
    {
        view.showBoard(board);

        view.getInput(x, y, player);

        if (!board.place(x, y, player))
        {
            view.showMessage("非法落子，请重试");
            continue;
        }

        if (board.checkWin(player))
        {
            view.showBoard(board);
            view.showMessage("游戏结束！获胜者：");
            break;
        }

        // 换人
        player = (player == 'X') ? 'O' : 'X';
    }
}