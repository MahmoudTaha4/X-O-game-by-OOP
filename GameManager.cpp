#include "GameManager.h"

void GameManager::runGame() {
    setPlayers();
    int currPlayersIndex = 0;
    while(gameBoard.getGameState() == GameState::IN_PROGRESS_STATE){
        gameBoard.printGameBoard();

        int col,row;
        cout << this->players[currPlayersIndex].getPlayerName() << " please enter the column that you want to play in :";
        cin >> col;
        cout <<this->players[currPlayersIndex].getPlayerName() << " please enter the row that you want to play in :";
        cin >> row;
        row--, col--;

        while(!gameBoard.makePlayerMove(col, row, players[currPlayersIndex].getPlayerSymbol())){
            cout << this->players[currPlayersIndex].getPlayerName() << " please enter the column that you want to play in :";
            cin >> col;
            cout << this->players[currPlayersIndex].getPlayerName() << " please enter the row that you want to play in :";
            cin >> row;
            col--, row--;
        }

        currPlayersIndex = (currPlayersIndex + 1) % 2;
    }
    
    if (gameBoard.getGameState() == GameState::TIE_STATE){
        cout << "Tie" << endl;
    }
    else {
        cout << this->players[(currPlayersIndex + 1) % 2].getPlayerName() << " is winner" << endl;
    }
}

void GameManager::setPlayers() {
    for(int i = 0; i < 2; i++){
        cout << "Player " << i + 1 << " Please enter your name :";
        string name;
        cin >> name;
        cout << "Player " << i + 1 << " Please enter your symbol :";
        char symbol;
        cin >> symbol;
        this->players[i] = Player(name, symbol);
    }
}