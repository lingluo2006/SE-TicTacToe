#pragma once
#include "Board.h"

class View
{
public:
    void showBoard(const Board& board);
    void showMessage(const char* msg);
    void getInput(int& x, int& y, char player);
};