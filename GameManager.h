
#ifndef X_O_GAMEBYOOP_GAMEMANAGER_H
#define X_O_GAMEBYOOP_GAMEMANAGER_H

#include "GameBoard.h"
#include "GameState.h"
#include "Player.h"

class GameManager {
private:
    GameBoard gameBoard;
    Player players[2];
public:
    GameManager(){}
    void runGame();
    void setPlayers();
};


#endif //X_O_GAMEBYOOP_GAMEMANAGER_H
