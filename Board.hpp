#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

using namespace std;

class Board {
private:
  int width, height;
  char player1, player2;
  vector<int> board;
  char winner;
  bool gameOver;

public:
  bool player1Turn;

  Board(int w, int h, char p1, char p2);
  Board(const Board& b2);

  bool isInBounds(int n) const;
  bool isInBounds(int x, int y) const;

  int getPiece(int n) const;
  int getPiece(int x, int y) const;

  bool setPiece(int n, int player);
  bool setPiece(int x, int y, int player);

  bool isValidMove(int x, int y) const;
  bool isValidMove(int n) const;

  char getWinner() const;
  void setWinner(char w);

  virtual bool isGameOver();
  virtual void print() const;
};

#endif