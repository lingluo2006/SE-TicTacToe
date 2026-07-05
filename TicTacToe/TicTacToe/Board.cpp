#include "Board.h"
#include <iostream>

using namespace std;


Board::Board()
{
    reset();
}

void Board::reset()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            grid[i][j] = ' ';
        }
    }
}
bool Board::place(int x, int y, char player)
{
    // 1. 检查范围是否合法
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
    {
        return false;
    }

    // 2. 检查位置是否已被占用
    if (grid[x][y] != ' ')
    {
        return false;
    }

    // 3. 落子
    grid[x][y] = player;

    return true;
}
bool Board::checkWin(char player)
{
    // 1. 行检查
    for (int i = 0; i < 3; i++)
    {
        if (grid[i][0] == player &&
            grid[i][1] == player &&
            grid[i][2] == player)
            return true;
    }

    // 2. 列检查
    for (int j = 0; j < 3; j++)
    {
        if (grid[0][j] == player &&
            grid[1][j] == player &&
            grid[2][j] == player)
            return true;
    }

    // 3. 对角线
    if (grid[0][0] == player &&
        grid[1][1] == player &&
        grid[2][2] == player)
        return true;

    if (grid[0][2] == player &&
        grid[1][1] == player &&
        grid[2][0] == player)
        return true;

    return false;
}
void Board::print()
{
    cout << "-------------" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "| ";

        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " | ";
        }

        cout << endl;
        cout << "-------------" << endl;
    }
}