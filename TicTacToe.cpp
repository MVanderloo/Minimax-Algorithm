#include "TicTacToe.hpp"
using namespace std;

TicTacToe::TicTacToe(bool AI_is_X) : aiTurn(AI_is_X), computer(AI_is_X ? 1 : 2), human(AI_is_X ? 2 : 1) {}

bool TicTacToe::isGameOver() {
    return b.isGameOver();
}

void TicTacToe::printBoard() {
    b.print();
}

void TicTacToe::getNextMove() {
    int move;
    if (aiTurn) {
        move = computer.getMove(b);
        if (b.isValidMove(move)) {
            b.setPiece(move, computer.getPiece());
            aiTurn = false;
        } else {
            cout << "Error: AI made Invalid Move" << endl;
        }
    } else {
        move = human.getMove(b);
        if (b.isValidMove(move)) {
            b.setPiece(move, human.getPiece());
            aiTurn = true;
        } else {
            cout << "Error: Invalid Move" << endl;
            getNextMove();
        }
    }
}

int TicTacToe::getWinner() {
    return b.getWinner();
}

int TicTacToe::getAIPiece() {
    return computer.getPiece();
}

int TicTacToe::getConsolePiece() {
    return human.getPiece();
}