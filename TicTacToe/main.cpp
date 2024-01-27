#include <iostream>
#include "TicTacToe.h"

int main() {
    // Dynamically allocate the TicTacToeGame object
    TicTacToeGame* p_game = new TicTacToeGame();

    p_game->play();

    delete p_game;

    return 0;
}