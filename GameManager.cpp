#include "GameManager.h"

void GameManager::runGame() {
    setPlayers();
    int currPlayersIndex = 0;
    while(gameBoard.getGameState() == GameState::IN_PROGRESS_STATE){
        gameBoard.printGameBoard();
        cout << this->players[currPlayersIndex].getPlayerName() << " please enter your curr column :";
        int currCol;
        cin >> currCol;
        currCol--;
        cout <<this->players[currPlayersIndex].getPlayerName() << " please enter your curr row :";
        int currRow;
        cin >> currRow;
        currRow--;
        while(!gameBoard.makePlayerMove(currCol,currRow,players[currPlayersIndex].getPlayerSymbol())){
            cout << this->players[currPlayersIndex].getPlayerName() << " please enter your curr column again :";
            cin >> currCol;
            currCol--;
            cout <<this->players[currPlayersIndex].getPlayerName() << " please enter your curr row again :";
            cin >> currRow;
            currRow--;
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