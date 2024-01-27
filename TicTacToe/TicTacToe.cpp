

#include <iostream>
#include <cstdlib>
#include <limits>
#include "TicTacToe.h"

TicTacToeGame::TicTacToeGame() : turn(0) {
        pp_cGrid = new char*[3];

        for (int i = 0; i < 3; ++i) {
            pp_cGrid[i] = new char[3];
        }

        // Initialize the grid with '~'
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                pp_cGrid[i][j] = '~';
            }
        }

    }

TicTacToeGame::~TicTacToeGame() {
        // Deallocate the char arrays
        for (int i = 0; i < 3; ++i) {
            delete[] pp_cGrid[i];
        }

        // Deallocate the array of pointers
        delete[] pp_cGrid;
    }

void TicTacToeGame::displayGrid() const {
    std::cout << " --- --- ---\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << "| " << pp_cGrid[i][j] << " ";
        }
        std::cout << "|\n --- --- ---\n";
    }
}

    bool TicTacToeGame::isMoveValid(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && pp_cGrid[row][col] == '~');
    }

    void TicTacToeGame::getUserMove() {
        int row, col;

        do {
            std::cout << "Enter your move (row and column, e.g., '1 1'): ";
            std::cin >> row >> col;

            if (!std::cin.good()) {
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                std::cout << "Invalid input. Please enter integers for row and column.\n";
                continue;
            }

            if (!isMoveValid(row - 1, col - 1)) {
                std::cout << "Invalid move. Try again.\n";
            } else {
                break;
            }
        } while (true);

        pp_cGrid[row - 1][col - 1] = 'X';
    }

    void TicTacToeGame::play() {
        std::cout << "Welcome to Tic Tac Toe!\n";

        do {
            displayGrid();
            if (turn % 2 == 0) {
                std::cout << "Player X's turn\n";
                getUserMove();
            } else {
                std::cout << "Player O's turn\n";
                computerMove();
            }

            if (checkWin()) {
                displayGrid();
                if (turn % 2 == 0) {
                    std::cout << "Congratulations! You won!\n";
                } else {
                    std::cout << "Computer wins.! Good Game ;)\n";
                }
                break;
            } else if (isGridFull()) {
                displayGrid();
                std::cout << "It's a draw!\n";
                break;
            }

            turn++;
        } while (true);
    }

void TicTacToeGame::computerMove() {
    int row, col;

    // Try to win
    if (findWinningMove(row, col)) {
        std::cout << "Computer chooses: " << row + 1 << ' ' << col + 1 << " (winning)\n";
    }
        // Try to block the human player from winning
    else if (blockHumanWin(row, col)) {
        std::cout << "Computer chooses: " << row + 1 << ' ' << col + 1 << " (blocking)\n";
    }
        // Choose the center if available
    else if (isMoveValid(1, 1)) {
        row = col = 1;
        std::cout << "Computer chooses: " << row + 1 << ' ' << col + 1 << " (center)\n";
    }
        // Choose a random valid move
    else {
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (!isMoveValid(row, col));

        std::cout << "Computer chooses: " << row + 1 << ' ' << col + 1 << '\n';
    }

    pp_cGrid[row][col] = 'O';
}

bool TicTacToeGame::findWinningMove(int& row, int& col) const {
    // Check if the computer can win in the next move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (isMoveValid(i, j)) {
                pp_cGrid[i][j] = 'O';
                if (checkWin()) {
                    row = i;
                    col = j;
                    pp_cGrid[i][j] = '~'; // Undo the move
                    return true;
                }
                pp_cGrid[i][j] = '~'; // Undo the move
            }
        }
    }
    return false;
}
    bool TicTacToeGame::blockHumanWin(int& row, int& col) const {
        // Check if the human player is about to win and block that move
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (isMoveValid(i, j)) {
                    // Try the move and check if it blocks human win
                    pp_cGrid[i][j] = 'X';
                    if (checkWin()) {
                        row = i;
                        col = j;
                        pp_cGrid[i][j] = '~'; // Undo the move
                        return true;
                    }
                    pp_cGrid[i][j] = '~'; // Undo the move
                }
            }
        }

        return false;
    }

    bool TicTacToeGame::checkWin() const {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((pp_cGrid[i][0] == pp_cGrid[i][1] && pp_cGrid[i][1] == pp_cGrid[i][2] && pp_cGrid[i][0] != '~') ||
                (pp_cGrid[0][i] == pp_cGrid[1][i] && pp_cGrid[1][i] == pp_cGrid[2][i] && pp_cGrid[0][i] != '~')) {
                return true;
            }
        }

        // Check diagonals
        if ((pp_cGrid[0][0] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[2][2] && pp_cGrid[0][0] != '~') ||
            (pp_cGrid[0][2] == pp_cGrid[1][1] && pp_cGrid[1][1] == pp_cGrid[2][0] && pp_cGrid[0][2] != '~')) {
            return true;
        }

        return false;
    }

    bool TicTacToeGame::isGridFull() const {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (pp_cGrid[i][j] == '~') {
                    return false;
                }
            }
        }
        return true;
    }
