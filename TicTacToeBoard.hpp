#ifndef TICTACTOEBOARD_HPP
#define TICTACTOEBOARD_HPP

#include <iostream>
#include <array>
#include "Board.hpp"

class TicTacToeBoard : public Board {
public:
    TicTacToeBoard();

    bool isGameOver();

    char printPiece(int x, int y) const;

    void print() const;

private:
    bool find3Consecutive();
};

#endif