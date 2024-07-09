#include <iostream>

#include "TicTacToeBoard.hpp"
#include "Players.hpp"

using namespace std;

class TicTacToe {
public:
	bool aiTurn;

	TicTacToe(bool AI_is_X) 
	 : aiTurn(AI_is_X), computer(AI_is_X ? 1 : 2), human(AI_is_X ? 2 : 1) {}

	bool isGameOver() { return b.isGameOver(); }

	void printBoard() { b.print(); }

	void getNextMove() {
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

	int getWinner() { return b.getWinner(); }

	int getAIPiece() { return computer.getPiece(); }

	int getConsolePiece() { return human.getPiece(); }

private:
	AIPlayer computer;
	ConsolePlayer human;
	TicTacToeBoard b;
};

