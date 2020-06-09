#include <iostream>

#include "Board.hpp"
#include "Players.hpp"

using namespace std;

class TicTacToe {
public:
	bool aiTurn;

	TicTacToe(bool AI_is_X) 
	 : aiTurn(AI_is_X), ai(AI_is_X ? X : O), human(AI_is_X ? O : X) {}

	bool isGameOver() { return b.isGameOver(); }

	void printBoard() { b.print(); }

	void getNextMove() {
		int move;
		if (aiTurn) {
			move = ai.getMove(b);
			if (b.isValidMove(move)) {
				b.setPiece(move, ai.getPiece());
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

private:
	AIPlayer ai;
	ConsolePlayer human;
	Board b;
};

int main() {
	cout << "\033[2JWelcome to TicTacToe\n" << endl;
	cout << "Would you like to be X or O? (X goes first)" << endl;
	cout << "       [X]        [O]       " << endl;

	char playerPiece;
	cin >> playerPiece;

	while (playerPiece != 'x' && playerPiece != 'X' && playerPiece != 'o' && playerPiece != 'O') {
		cout << "Error: Invalid Selection, Please Enter Again" << endl;
		cin >> playerPiece; 
	}

	TicTacToe game ((playerPiece == 'O' || playerPiece == 'o'));

	while (!game.isGameOver()) {
		game.getNextMove();
	}

	game.printBoard();

	cout << "Game Over!" << endl;

}