#include "Board.hpp"

Board::Board(int w, int h, char p1, char p2) 
  : width(w), height(h), player1(p1), player2(p2) {
  winner = -1;
  gameOver = false;
  player1Turn = true;

  for(int i = 0; i < width * height; i++) board.push_back(0);
}

Board::Board(const Board& b2) {
  width = b2.width;
  height = b2.height;
  board = b2.board;
  winner = b2.winner;
  gameOver = b2.gameOver;
  player1Turn = b2.player1Turn;
}

bool Board::isInBounds(int n) const { 
  return (n >= 0 && n < width * height); 
}

bool Board::isInBounds(int x, int y) const { 
  return (x >= 0 && x < width && y >= 0 && y < height); 
}

int Board::getPiece(int n) const {
  if (isInBounds(n)) return board[n];
  else return -1;
}

int Board::getPiece(int x, int y) const { 
  return getPiece(x + (3 * y)); 
}

bool Board::setPiece(int n, int player) {
  if (isInBounds(n) && (player == 1 || player == 2)) {
    board[n] = player;
    return true;
  } else {
    return false;
  }
}

bool Board::setPiece(int x, int y, int player) { 
  return setPiece(x + (3 * y), player); 
}

bool Board::isValidMove(int x, int y) const { 
  return (getPiece(x, y) == 0); 
}

bool Board::isValidMove(int n) const { 
  return (getPiece(n) == 0); 
}

char Board::getWinner() const { 
  return winner; 
}

void Board::setWinner(char w) { 
  winner = w; 
}

bool Board::isGameOver() {
  // Implementation of game over logic
  return gameOver;
}

void Board::print() const {
  // Implementation of print logic
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      cout << getPiece(x, y) << " ";
    }
    cout << endl;
  }
}