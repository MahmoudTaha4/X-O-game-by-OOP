#include <bits/stdc++.h>
using namespace std;

#include "GameBoard.h"

void GameBoard::ClearGameBoard() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            this->matrix[i][j] = ' ';
        }
    }
}

void GameBoard::printGameBoard() {
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "|" << this->matrix[i][j];
        }
        cout << "|" << endl << "-------" << endl;
    }
}

bool GameBoard::makePlayerMove(int col, int row, char symbol) {
    if(matrix[row][col] == ' ' && col < 3 && row < 3 && row >= 0 && col >= 0){
        matrix[row][col] = symbol;
        return true;
    }
    else {
        return false;
    }
}

GameState GameBoard::getGameState() {
    for(int i = 0; i < 3; i++){
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != ' '){
            return GameState::WIN_STATE;
        }
    }
    for(int i = 0, j = 0; i < 3; i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[0][i] != ' '){
            return GameState::WIN_STATE;
        }
    }
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' '){
        return GameState::WIN_STATE;
    }
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' '){
        return GameState::WIN_STATE;
    }
    int spacesSum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (matrix[i][j] == ' '){
                spacesSum++;
            }
        }
    }
    if(spacesSum == 0){
        return GameState::TIE_STATE;
    }
    return GameState::IN_PROGRESS_STATE;
}
