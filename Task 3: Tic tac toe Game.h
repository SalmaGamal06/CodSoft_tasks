#include <iostream>
using namespace std;


#ifndef CODSOFT_TIC_TAC_TOE_GAME_H
#define CODSOFT_TIC_TAC_TOE_GAME_H

class Board {
public:
    char board[3][3];

    explicit Board();

    void printBoard();

    bool isFull();

    bool is_taken(int move);
};

class player {
private:
    string name;
    bool winner;
    char symbol;
    int move;
    bool current;
public:
    bool isCurrent() const;

    void setCurrent(bool current);

    int getMove() const;

    void setMove(int move);

    const string &getName() const;

    void setName(const string &name);

    bool isWinner(Board brd);

    player(const string &name, char symbol);

    void setWinner(bool winner);

    char getSymbol() const;

    void setSymbol(char symbol);


};

class gameManager {
public:
    player switchPlayer(player& plyr1, player& plyr2);

    void updateBoard(Board& brd, player plyr);


};

#endif //CODSOFT_TIC_TAC_TOE_GAME_H
