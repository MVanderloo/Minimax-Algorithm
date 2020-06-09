#include <iostream>

#include "Board.hpp"
#include "Players.hpp"

using namespace std;

class TicTacToe {
public:
	Game(bool AI_is_X) : AI_is_X(AI_turn) {

	}

private:
	AIPlayer ai;
	ConsolePlayer console;
	bool AI_turn;
};