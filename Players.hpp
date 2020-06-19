#include <iostream>
#include <vector>

using namespace std;

class ConsolePlayer {
private:
	int myPiece;

public:
	ConsolePlayer(int piece) : myPiece(piece) {}

	int getPiece() { return myPiece; }

	int getMove(const TicTacToeBoard& b) {
		b.print();
		cout << "Where would you like to move?" << endl; // 29 characters

		vector<int> validMoves = getValidMoves(b);
		for (int i = 0; i < (9 - validMoves.size()); i++) cout << " ";
		for (int validMove : validMoves) {
			cout << "  " << validMove;
		}
		cout << "  " << endl << endl;

		int move;
		cin >> move;
		return move;
	}

	vector<int> getValidMoves(const TicTacToeBoard& b) {
		vector<int> moves;
		for (int i = 1; i <= 9; i++) {
			if (b.getPiece(i) == 0) moves.push_back(i);
		}
		return moves;
	}
};

class AIPlayer {
public:
	AIPlayer(int p, int searchDepth = 10) : myPiece(p), searchDepth(searchDepth) {
		if (myPiece == 1) opponent_piece = 2;
		else opponent_piece = 1;
	}

	/**
	 * given a board, this method scores a set of moves using the minimax algorithm 
	 * 
	 * it iterates through a container of the possible moves,
	 * creating a copy of the board for each and scoring it using the minimax algorithm
	 * 
	 * returns the highest scoring move 
	 */
	int getMove(const TicTacToeBoard& b, bool useABPruning = true) {
		int bestMove = -1;
		int score, bestScore = INT_MIN;

		for (int move : getUniqueMoves(b)) {
			TicTacToeBoard b2 (b);
			b2.setPiece(move, myPiece);
			
			score = (useABPruning ? minimaxABPruning(b2, searchDepth, INT_MIN, INT_MAX, false) : minimax(b2, searchDepth, false));

			if (score > bestScore) {
				bestScore = score;
				bestMove = move;
			}
		}
		return bestMove;
	}

	int getPiece() { return myPiece; }

private:
	int myPiece, opponent_piece;
	int searchDepth;

	/**
	 * the minimax algorithm is a standard algorithm for turn based games
	 * that uses a search tree to look ahead and determine the best move
	 * 
	 * it is abstracted by using a method scoreBoard() that returns a 
	 * static analysis of the board and a method that returns a container
	 * of the moves it can try (getValidMoves() or getUniqueMoves()) 
	 */
	int minimax(TicTacToeBoard b, int depth, bool maximizing) {
		if (depth == 0 || b.isGameOver()) {
			return scoreBoard(b);
		}

		int eval, curEval;

		if (maximizing) {
			eval = INT_MIN;
			for (int move : getUniqueMoves(b)) {
				TicTacToeBoard b2 (b);
				b2.setPiece(move, myPiece);
				curEval = minimax(b2, depth - 1, false);
				eval = max(eval, curEval);
			}
			return eval;
		} else { // minimizing
			eval = INT_MAX;
			for (int move : getValidMoves(b)) {
				TicTacToeBoard b2 (b);
				b2.setPiece(move, opponent_piece);
				curEval = minimax(b2, depth - 1, true);
				eval = min(eval, curEval);
			}
			return eval;
		}
	}

	/**
	 * This is an implementation of the minimax algorithm utilizing alpha
	 * beta pruning for optimization 
	 */
	int minimaxABPruning(TicTacToeBoard b, int depth, int alpha, int beta, bool maximizing) {
		if (depth == 0 || b.isGameOver()) {
			return scoreBoard(b);
		}

		int eval, curEval;

		if (maximizing) {
			eval = INT_MIN;
			for (int move : getUniqueMoves(b)) {
				TicTacToeBoard b2 (b);
				b2.setPiece(move, myPiece);
				curEval = minimaxABPruning(b2, depth - 1, alpha, beta, false);
				eval = max(eval, curEval);
				alpha = max(alpha, eval);
				if (beta <= alpha) break;
			}
			return eval;
		} else { // minimizing
			eval = INT_MAX;
			for (int move : getValidMoves(b)) {
				TicTacToeBoard b2 (b);
				b2.setPiece(move, opponent_piece);
				curEval = minimaxABPruning(b2, depth - 1, alpha, beta, true);
				eval = min(eval, curEval);
				beta = max(beta, eval);
				if (beta <= alpha) break;
			}
			return eval;
		}
	}

	/**
	 * returns a vector of all positions (1-9) that are a valid move i.e. empty
	 */
	vector<int> getValidMoves(const TicTacToeBoard& b) {
		vector<int> moves;
		for (int i = 1; i <= 9; i++) {
			if (b.getPiece(i) == 0) moves.push_back(i);
		}
		return moves;
	}

	/**
	 * tests a board for symmetry on the horizontal and vertical symmetry
	 * 
	 * This method can be used in place for the getValidMoves as it has the same param and return
	 *
	 * it is used to reduce score calculations on two tiles that are symmetrical
	 * and thus would return the same score.
	 * 
	 * returns a vector of all the unique valid moves.
	 */
	vector<int> getUniqueMoves(const TicTacToeBoard& b) {
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

	/** 
	 * used by the AIPLayer to get a static analysis of the board
	 */
	int scoreBoard(const TicTacToeBoard& b) {
		if (b.getWinner() == -1) { // means tie
			return 0;
		} else if (b.getWinner() == myPiece) {
			return 1;
		} else {
			return -1;
		}
	}
};