#pragma once

class Board
{
public:
    Board();

    void reset();
    bool place(int x, int y, char player);
    bool checkWin(char player);
    bool isFull();

    char get(int x, int y) const;

private:
    char grid[3][3];
};