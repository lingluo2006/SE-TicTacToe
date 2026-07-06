#pragma once
#include "Board.h"
#include <string>

class View
{
public:
    void showBoard(const Board& board);
    void showMessage(const std::string& msg);
    void getInput(int& x, int& y);
};