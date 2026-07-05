#pragma once

class Board
{
public:
    Board();

    void reset();                // 初始化棋盘
    void print();               // 打印棋盘（控制台版）

    bool place(int x, int y, char player); // 下棋
    bool checkWin(char player);            // 判断胜利

private:
    char grid[3][3];
};