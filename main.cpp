#include <iostream>

#include "TicTacToeBoard.hpp"

char getPlayerPiece() {
    char playerPiece;
    while (true) {
        std::cout << "Would you like to be X or O? (X goes first)" << std::endl;
        std::cout << "       [x]        [o]       " << std::endl;

        std::cin >> playerPiece;

        if (playerPiece == 'x' || playerPiece == 'X' || playerPiece == 'o' || playerPiece == 'O') {
            break;
        } else {
            std::cout << "Error: Invalid Selection, Please Enter Again" << std::endl;
        }
    }
    return playerPiece;
}

char getPlayAgain() {
    char playAgain;
    while (true) {
        std::cout << "Would you like to play again?" << std::endl;
        std::cout << "        [y]       [n]        " << std::endl;

        std::cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') {
            break;
        } else {
            std::cout << "Error: Invalid Selection, Please Enter Again" << std::endl;
        }
    }
    return playAgain;
}

int main() {
    std::cout << "\033[2JWelcome to TicTacToe\n" << std::endl;

    while (true) {
        char playerPiece = getPlayerPiece();

        TicTacToe game((playerPiece == 'O' || playerPiece == 'o'));

        while (!game.isGameOver()) {
            game.getNextMove();
        }

        game.printBoard();

        std::cout << "Game Over!" << std::endl;

        if (game.getWinner() == game.getAIPiece()) std::cout << "You Lost!" << std::endl;
        else if (game.getWinner() == game.getConsolePiece()) std::cout << "You Won!" << std::endl;
        else std::cout << "It was a Tie!\n" << std::endl;

        char playAgain = getPlayAgain();

        if (playAgain == 'n' || playAgain == 'N') break;
    }

    return 0;
}