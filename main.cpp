char getPlayerPiece() {
    char playerPiece;
    while (true) {
        cout << "Would you like to be X or O? (X goes first)" << endl;
        cout << "       [x]        [o]       " << endl;

        cin >> playerPiece;

        if (playerPiece == 'x' || playerPiece == 'X' || playerPiece == 'o' || playerPiece == 'O') {
            break;
        } else {
            cout << "Error: Invalid Selection, Please Enter Again" << endl;
        }
    }
    return playerPiece;
}

char getPlayAgain() {
    char playAgain;
    while (true) {
        cout << "Would you like to play again?" << endl;
        cout << "        [y]       [n]        " << endl;

        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') {
            break;
        } else {
            cout << "Error: Invalid Selection, Please Enter Again" << endl;
        }
    }
    return playAgain;
}

int main() {
    cout << "\033[2JWelcome to TicTacToe\n" << endl;

    while (true) {
        char playerPiece = getPlayerPiece();

        TicTacToe game((playerPiece == 'O' || playerPiece == 'o'));

        while (!game.isGameOver()) {
            game.getNextMove();
        }

        game.printBoard();

        cout << "Game Over!" << endl;

        if (game.getWinner() == game.getAIPiece()) cout << "You Lost!" << endl;
        else if (game.getWinner() == game.getConsolePiece()) cout << "You Won!" << endl;
        else cout << "It was a Tie!\n" << endl;

        char playAgain = getPlayAgain();

        if (playAgain == 'n' || playAgain == 'N') break;
    }

    return 0;
}