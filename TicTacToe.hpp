#include <iostream>
#include "TicTacToeBoard.hpp"
#include "Players.hpp"

class TicTacToe {
public:
    TicTacToe(bool AI_is_X);
    bool isGameOver();
    void printBoard();
    void getNextMove();
    int getWinner();
    int getAIPiece();
    int getConsolePiece();

private:
    bool aiTurn;
    AIPlayer computer;
    ConsolePlayer human;
    TicTacToeBoard b;
};