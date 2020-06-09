//compiled with 'g++ -std=c++17 TicTacToe.cpp'

#include <iostream>
#include <array>
#include <vector>
#include <climits>

#include "Board.hpp"
#include "Timer.hpp"

using namespace std;

class AIPlayer {
/*
	The Game object will initialize an instance of the AIPlayer,
	giving it which piece it will play as. The Game will ask for 
	the move, which is to be returned as a Move struct. 
*/
public:
	AIPlayer(Piece p) : my_piece(p) {
		if (my_piece == X) opponent_piece = O;
		else opponent_piece = X;
	}

	int getMove(const Board& b) {
		int move, bestMove = -1; // if there are no valid moves, -1 is returned
		int score, maxScore = INT_MIN;
		for (int move : getValidMoves(b)) {
			Board b2 (b);
			b2.setPiece(move, my_piece);
			b2.print();
			score = minimax(b2, 10, false);
			cout << score << endl;
			if (score > maxScore) {
				maxScore = score;
				bestMove = move;
			}
		}

		return bestMove;
	}

private:
	Piece my_piece, opponent_piece;

	int minimax(Board b, int depth, bool maximizing) {
		if (depth == 0 || b.isGameOver()) {
			return scoreBoard(b);
		}

		int eval;

		if (maximizing) {
			int maxEval = INT_MIN;
			for (int move : getValidMoves(b)) {
				// cout << move << endl;
				Board b2 (b);
				b2.setPiece(move, my_piece);
				maxEval = minimax(b2, depth - 1, false);
				eval = max(eval, maxEval);
			}
			return maxEval;
		} else { // minimizing
			int minEval = INT_MAX;
			for (int move : getValidMoves(b)) {
				// cout << move << endl;
				Board b2 (b);
				b2.setPiece(move, opponent_piece);
				minEval = minimax(b2, depth - 1, true);
				eval = min(eval, minEval);
			}
			return minEval;
		}
	}

	vector<int> getUniqueMoves(const Board& b) {
		bool vertSym = true, horzSym = true;
		vector<int> moves;

		for (int i = 0; i < 3; i++) {
			if (vertSym) vertSym &= (b.getPiece(0, i) == b.getPiece(2, i));
			if (horzSym) horzSym &= (b.getPiece(i, 0) == b.getPiece(i, 2));
		}

		if (b.isValidMove(1))                         moves.push_back(1);
		if (b.isValidMove(2))                         moves.push_back(2);
		if (b.isValidMove(3) && !vertSym)             moves.push_back(3);
		if (b.isValidMove(4))                         moves.push_back(4);
		if (b.isValidMove(5))                         moves.push_back(5);
		if (b.isValidMove(6) && !vertSym)             moves.push_back(6);
		if (b.isValidMove(7) && !horzSym)             moves.push_back(7);
		if (b.isValidMove(8) && !horzSym)             moves.push_back(8);
		if (b.isValidMove(9) && !vertSym && !horzSym) moves.push_back(9);

		return moves;
	}

	vector<int> getValidMoves(const Board& b) {
		vector<int> moves;
		for (int i = 1; i <= 9; i++) {
			if (b.getPiece(i) == E) moves.push_back(i);
		}
		return moves;
	}

	int scoreBoard(const Board& b) {
		if (b.getWinner() == Invalid) {
			return 0;
		} else if (b.getWinner() == my_piece) {
			return 1;
		} else {
			return -1;
		}
	}
};

// new line 		- \n
// erase display 	- \033[2J
// erase line 		- \033[K
// cursor up 		- \033[<N>A
// cursor down 		- \033[<N>B
// cursor forwards 	- \033[<N>C
// cursor backwards - \033[<N>D
// position cursor  - \033[<L>;<C>H

int main() {
	Board b;
	AIPlayer pc (X);
	int n;

	while (!b.isGameOver()) {
		cout << "AI Thinking..." << endl;
		b.setPiece(pc.getMove(b), X);

		if (b.isGameOver()) break;

		b.print();
		cin >> n;
		b.setPiece(n, O);
		b.print();
	}

	cout << "Game Over!" << endl;

	b.print();
	

	return 0;
}