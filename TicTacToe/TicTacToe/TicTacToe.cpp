#include <iostream>

using namespace std;

char board[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

char currentPlayer = 'X';

// 打印棋盘
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

// 落子
bool placeMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
        return false;

    if (board[row][col] != ' ')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

// 切换玩家
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// 判断胜利
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

int main() {
    int row, col;
    int moves = 0;

    cout << "Tic Tac Toe Start!\n";

    while (true) {
        printBoard();

        cout << "Player " << currentPlayer
            << " enter row and col (0-2): ";
        cin >> row >> col;

        if (!placeMove(row, col)) {
            cout << "Invalid move, try again!\n";
            continue;
        }

        moves++;

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (moves == 9) {
            printBoard();
            cout << "Draw!\n";
            break;
        }

        switchPlayer();
    }

    return 0;
}