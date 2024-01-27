
#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H
class TicTacToeGame {
private:
    char **pp_cGrid;
    int turn;

public:
    TicTacToeGame();
    ~TicTacToeGame();
    void displayGrid() const;
    bool isMoveValid(int row, int col) const;
    void getUserMove();
    void play();
    void computerMove();
    bool blockHumanWin(int& row, int& col) const;
    bool findWinningMove(int& row, int& col) const;
    bool checkWin() const;
    bool isGridFull() const;
};


#endif
