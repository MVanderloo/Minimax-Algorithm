#include "TicTacToeBoard.hpp"

using namespace std;

TicTacToeBoard::TicTacToeBoard() : Board{3, 3, 'X', 'O'} { }


bool TicTacToeBoard::isGameOver() {
    if (winner == -1) {
        if (find3Consecutive()) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}

bool TicTacToeBoard::find3Consecutive() {
    auto checkSequence = [](int a, int b, int c) {
        return (a == b) && (a == c) && (a != 0);
    };

    for (int i = 0; i < 3; i++) {
        if (checkSequence(getPiece(i, 0), getPiece(i, 1), getPiece(i, 2))) {
            winner = getPiece(i, 0);
            gameOver = true;
            return true;
        }
        if (checkSequence(getPiece(0, i), getPiece(1, i), getPiece(2, i))) {
            winner = getPiece(0, i);
            gameOver = true;
            return true;
        }
    }

    if (checkSequence(getPiece(0, 0), getPiece(1, 1), getPiece(2, 2))) {
        winner = getPiece(0, 0);
        gameOver = true;
        return true;
    }
    if (checkSequence(getPiece(0, 2), getPiece(1, 1), getPiece(2, 0))) {
        winner = getPiece(0, 2);
        gameOver = true;
        return true;
    }

    return false;
}

char TicTacToeBoard::printPiece(int x, int y) const {
    int p = getPiece(x, y);
    if (p == 1) return 'X';
    else if (p == 2) return 'O';
    else if (p == -1) return 'I';
    else return ' ';
}

void TicTacToeBoard::print() const {
    // Print an empty line for spacing
    cout << " " << endl;

    // Print the board rows with formatted pieces
    for (int row = 0; row < 3; ++row) {
        // Print the top/bottom of each row
        cout << " | | " << endl;
        cout << " " << printPiece(0, row) << " | " << printPiece(1, row) << " | " << printPiece(2, row) << " " << endl;
        cout << " | | " << endl;

        // Print horizontal divider except for the last row
        if (row < 2) {
            cout << "-----+-----+-----" << endl;
        }
    }

    // Print an empty line for spacing
    cout << " " << endl;
}