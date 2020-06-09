#include <iostream>
#include <array>

using namespace std;

enum Piece { E = 0, X = 1, O = 2, I = -1, Invalid = I, Empty = E };

class Board {
private:
	array<int, 9> boardArr;
	bool x_turn;
	Piece winner;
	bool gameOver;

	char printPiece(int x, int y) const {
		Piece ret = getPiece(x, y);
		return (ret == E) ? ' ' : ((ret == X) ? 'X' : 'O');
	}

	bool outOfBounds(int x, int y) const { 
		return !(x >= 0 && x <= 2 && y >= 0 && y <= 2); 
	}

	bool find3Consecutive() {
		for (int row = 0; row < 3; row++) {
			if ((getPiece(row, 0) == getPiece(row, 1)) && (getPiece(row, 0) == getPiece(row, 2))) { 
				if (getPiece(row, 0) != E) {
					winner = getPiece(row, 0);
					gameOver = true;
					return true;
				}
			}
		}

		for (int col = 0; col < 3; col++) {
			if ((getPiece(0, col) == getPiece(1, col)) && (getPiece(0, col) == getPiece(2, col))) { 
				if (getPiece(0, col) != E) {
					winner = getPiece(0, col);
					gameOver = true;
					return true;
				}
			}
		}

		if ((getPiece(0, 0) == getPiece(1, 1)) && (getPiece(0, 0) == getPiece(2, 2))) {
			if (getPiece(0, 0) != E) {
				winner = getPiece(0, 0);
				gameOver = true;
				return true;
			}
		}

		if ((getPiece(0, 2) == getPiece(1, 1)) && (getPiece(0, 2) == getPiece(2, 0))) {
			if (getPiece(0, 2) != E) {
				winner = getPiece(0, 2);
				gameOver = true;
				return true;
			}
		}

		return false;
	}

public:
	// default constructor
	Board() {
		boardArr = { {E, E, E, E, E, E, E, E, E} };
		x_turn = true;
		gameOver = false;
		winner = I;
	}
 
	// copy constructor
	Board(const Board& b2) {
		boardArr = b2.boardArr;
		x_turn = b2.x_turn;
		gameOver = b2.gameOver;
		winner = b2.winner;
	}

	// high level setter for board pieces
	bool setPiece(int x, int y, Piece p) {
		if (!outOfBounds(x, y) && getPiece(x, y) == Empty) {
			if ((p == X) || (p == O)) {
				boardArr[x + (3 * y)] = p;
				return true;
			}
		}
		return false;
	}

	bool setPiece(int n, Piece p) { return setPiece((n - 1) % 3, (n - 1) / 3, p); }

	// high level getter for board pieces
	Piece getPiece(int x, int y) const {
		if (outOfBounds(x, y)) return Invalid;
		else return static_cast<Piece>(boardArr[x + (3 * y)]);
	}

	Piece getPiece(int n) const { return getPiece((n - 1) % 3, (n - 1) / 3); }

	bool isGameOver() { 
		if (gameOver || find3Consecutive()) return true;
		else {
			for (int col = 0; col < 3; col++) {
				for (int row = 0; row < 3; row++) {
					if (getPiece(col, row) == E) return false;
				}
			}
			return true;
		}
	}

	Piece getWinner() const { return winner; }

	void reset() {
		boardArr = {E, E, E, E, E, E, E, E, E};
		x_turn = true;
		gameOver = false;
		winner = I;
	}

	bool isValidMove(int x, int y) const { return getPiece(x, y) == E; }

	bool isValidMove(int n) const { return isValidMove((n - 1) % 3, (n - 1) / 3); }

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