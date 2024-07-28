#ifndef X_O_GAMEBYOOP_PLAYERS_H
#define X_O_GAMEBYOOP_PLAYERS_H

#include <bits/stdc++.h>
#include <stdexcept>
using namespace std;

class Player {
private:
    string name;
    char symbol;
public:
    Player(string name, char symbol){
        this->name = name;
        this->symbol = symbol;
    }
    Player(){
        name = "unKnown";
        symbol = 'X';
    }
    char getPlayerSymbol();
    string getPlayerName();
};


#endif
