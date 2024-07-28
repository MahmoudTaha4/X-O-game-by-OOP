#ifndef X_O_GAMEBYOOP_GAMEBOARD_H
#define X_O_GAMEBYOOP_GAMEBOARD_H

#include "GameState.h"

class GameBoard {
private:
    char matrix[3][3];
public:
    GameBoard(){
        ClearGameBoard();
    }
    void ClearGameBoard();
    bool makePlayerMove(int col, int row, char symbol);
    void printGameBoard();
    GameState getGameState();
};


#endif //X_O_GAMEBYOOP_GAMEBOARD_H
