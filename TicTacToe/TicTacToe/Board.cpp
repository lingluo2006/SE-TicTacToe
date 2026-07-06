#include "Board.h"

Board::Board()
{
    reset();
}

void Board::reset()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = ' ';
}

bool Board::place(int x, int y, char player)
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        return false;

    if (grid[x][y] != ' ')
        return false;

    grid[x][y] = player;
    return true;
}

bool Board::checkWin(char player)
{
    for (int i = 0; i < 3; i++)
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;

    for (int j = 0; j < 3; j++)
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == player)
            return true;

    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;

    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

bool Board::isFull()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] == ' ')
                return false;

    return true;
}

char Board::get(int x, int y) const
{
    return grid[x][y];
}