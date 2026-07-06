#pragma once
#include "Board.h"
#include "View.h"

class Controller
{
public:
    void run();

private:
    Board board;
    View view;
};