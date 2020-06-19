/*
	for board spaces:
		-1 is invalid or does not exist
		 0 is empty
		 1 is player 1
		 2 is player 2
*/

#include <iostream>
#include <array>

#include "Board.hpp"

using namespace std;

class TicTacToeBoard : public Board {
public:
	// default constructor
	TicTacToeBoard() : Board{3, 3, 'X', 'O'} {
	}
 
	// copy constructor
	TicTacToeBoard(const TicTacToeBoard& b2) : Board(b2) {
		boardArr = b2.boardArr;
		x_turn = b2.x_turn;
		gameOver = b2.gameOver;
		winner = b2.winner;
	}

	bool isGameOver() {
		if (winner == -1) {
			if (find3Consecutive()) {
				return true;
			} else {
				return false;
			}
		}
		return true;
	}

private:
	bool find3Consecutive() {
		for (int row = 0; row < 3; row++) {
			if ((getPiece(row, 0) == getPiece(row, 1)) && (getPiece(row, 0) == getPiece(row, 2))) { 
				if (getPiece(row, 0) != 0) {
					winner = getPiece(row, 0);
					gameOver = true;
					return true;
				}
			}
		}

		for (int col = 0; col < 3; col++) {
			if ((getPiece(0, col) == getPiece(1, col)) && (getPiece(0, col) == getPiece(2, col))) { 
				if (getPiece(0, col) != 0) {
					winner = getPiece(0, col);
					gameOver = true;
					return true;
				}
			}
		}

		if ((getPiece(0, 0) == getPiece(1, 1)) && (getPiece(0, 0) == getPiece(2, 2))) {
			if (getPiece(0, 0) != 0) {
				winner = getPiece(0, 0);
				gameOver = true;
				return true;
			}
		}

		if ((getPiece(0, 2) == getPiece(1, 1)) && (getPiece(0, 2) == getPiece(2, 0))) {
			if (getPiece(0, 2) != 0) {
				winner = getPiece(0, 2);
				gameOver = true;
				return true;
			}
		}

		return false;
	}

public:
	char printPiece(int x, int y) const {
		int p = getPiece(x, y);
		if (p == 1) return 'X';
		else if (p == 2) return 'O';
		else if (p == -1) return 'I';
		else return ' ';
	}

	void print() const {
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "                 " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "  " << printPiece(0, 0) << "  |";
		cout << "  " << printPiece(1, 0) << "  |";
		cout << "  " << printPiece(2, 0) << "  " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "-----+-----+-----" << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "  " << printPiece(0, 1) << "  |";
		cout << "  " << printPiece(1, 1) << "  |";
		cout << "  " << printPiece(2, 1) << "  " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "-----+-----+-----" << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "  " << printPiece(0, 2) << "  |";
		cout << "  " << printPiece(1, 2) << "  |";
		cout << "  " << printPiece(2, 2) << "  " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "     |     |     " << endl;
		// for (int i = 0; i < leftBuffer; i++) cout << " ";
		cout << "                 " << endl;
	}
};