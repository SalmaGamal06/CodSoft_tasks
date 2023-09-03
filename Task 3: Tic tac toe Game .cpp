#include <iostream>
#include "Task 3: Tic tac toe Game .h"
#include <limits>

using namespace std;

//function that takes input and checks whether its is valid or not and if it isn't it makes the user renter the input (n)
void check_valid_input(int &n) {
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT\nPlease reenter:";
    }
}

//player class functions

//constructor where basic player info is set
player::player(const string &name, char symbol) : name(name), winner(false), symbol(symbol) {};


//setters and getters

const string &player::getName() const {
    return name;
}

void player::setName(const string &name) {
    player::name = name;
}

void player::setWinner(bool winner) {
    player::winner = winner;
}

char player::getSymbol() const {
    return symbol;
}

void player::setSymbol(char symbol) {
    player::symbol = symbol;
}

int player::getMove() const {
    return move;
}

void player::setMove(int move) {
    player::move = move;
}

bool player::isCurrent() const {
    return current;
}

void player::setCurrent(bool current) {
    player::current = current;
}

//function to check for the winner
bool player::isWinner(Board brd) {

    // Checks for horizontal win
    for (auto &i: brd.board) {
        if (i[0] == i[1] && i[1] == i[2]) {
            if (i[0] == this->getSymbol()) {
                this->setWinner(true);
            }
        }
    }

    // Checks for vertical win
    for (int i = 0; i < 3; ++i) {
        if (brd.board[0][i] == brd.board[1][i] && brd.board[1][i] == brd.board[2][i])
            if (brd.board[0][1] == this->getSymbol()) {
                this->setWinner(true);
            }
    }
    // Check for diagonal win (upper left to bottom right)
    if (brd.board[0][0] == brd.board[1][1] && brd.board[1][1] == brd.board[2][2]) {
        if (brd.board[0][0] == this->getSymbol()) {
            this->setWinner(true);
        }
    }
    // Check for diagonal win (upper right to bottom left)
    if (brd.board[0][2] == brd.board[1][1] && brd.board[1][1] == brd.board[2][0]) {
        if (brd.board[1][1] == this->getSymbol()) {
            this->setWinner(true);

        }
    }
    return this->winner;
}





//board class functions

//constructor where the board is set and filled form 1 to 9 in a 2d array
Board::Board() {
    for (auto i = 0; i < 3; i++) {
        for (auto j = 0; j < 3; j++) {
            board[i][j] = char((2 * i) + (1 + i + j));
        }
    }
}

//function to print the board
void Board::printBoard() {
    int count = 1;
    cout << endl << "-------------" << endl;
    for (auto i = 0; i < 3; i++) {
        cout << "|";
        for (auto j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')cout << " " << int(board[i][j]) << " " << "|";
            else cout << " " << board[i][j] << " " << "|";
            count++;
        }
        cout << endl << "-------------" << endl;
    }
    cout << endl;

}

//function to check if the board is full
bool Board::isFull() {
    for (auto &i: board) {
        for (char j: i) {
            if (j != 'X' && j != 'O') return false;
        }
    }
    return true;
}

//function to check if a specific square is already taken
bool Board::is_taken(int move) {
    //translating the move(the square chosen by player) from an integer between 1 and 9 to index in the 2d array
    int i = (move - 1) / 3;
    int j = (move - 1) % 3;

    if (board[i][j] == 'X' || board[i][j] == 'O') return true;
    else return false;

}

//gamemanegaer class functions

//function to update board after every move
void gameManager::updateBoard(Board &brd, player plyr) {
    int move = plyr.getMove();

    //translating the move(the square chosen by player) from an integer between 1 and 9 to index in the 2d array
    int i = (move - 1) / 3;
    int j = (move - 1) % 3;
    brd.board[i][j] = plyr.getSymbol();

}

//function to switch players after every move
player gameManager::switchPlayer(player &plyr1, player &plyr2) {

    if (plyr1.isCurrent()) {
        plyr1.setCurrent(false);
        plyr2.setCurrent(true);
        return plyr2;
    } else if (plyr2.isCurrent()) {
        plyr2.setCurrent(false);
        plyr1.setCurrent(true);
        return plyr1;
    }
}

//game function
void run() {
    Board b1;
    gameManager g1;
    string name;
    char op;

    cout << "To choose the square enter its assigned number that will be printed on the screen"
            "\nDo you want to know the rules?(y/n)";

    //enter option
    cin >> op;
    //check that the input is valid and reenter if not
    while (tolower(op) != 'y' && tolower(op) != 'n') {
        cout << "Please enter \'y\' or \'n\':";
        cin >> op;
    }
    //if the input = y then the game rules are printed on screen
    if (tolower(op) == 'y') {
        cout
                << "\nThe game is played on a grid that's 3 squares by 3 square\nThe first player is X , the second player is O .\n"
                   "Players take turns putting their Symbols(X/O) in empty squares. The first player to get 3 of her marks in a\n"
                   "row (up, down, across, or diagonally) is the winner.\n";
    }

    //players enter name and have their symbols set(X/O)
    cout << "\nPlayer X please enter your name:";
    cin >> name;
    player X(name, 'X');
    cout << "Player O please enter your name:";
    cin >> name;
    player O(name, 'O');
    cout << "\nLet the game begin!\n";

    //board is printed
    b1.printBoard();

    //set current player to player X (the first player)
    auto current = X;
    X.setCurrent(true);
    O.setCurrent(false);

    //while the board is not full the game keeps going
    while (!b1.isFull()) {
        int move;
        //input of the move
        cout << current.getName() << "'s turn:";
        check_valid_input(move);

        //check to see if the chosen square(move) was already chosen or if it's out of bounds and reenter the move if it
        // is
        while (b1.is_taken(move) || move < 1 || move > 9) {
            try {
                throw (move);
            }
            catch (...) {

                if (move < 1 || move > 9)cout << "Please enter a number between 1 and 9:";
                else cout << "That square has already been chosen please choose again:";

                check_valid_input(move);

            }
        }
        //set the move for the  current player
        current.setMove(move);

        //update and print the updated board
        g1.updateBoard(b1, current);
        b1.printBoard();

        //check if there is a winner if there is then the game stops else it keeps going until there is a winner or the
        // board is full
        auto plyrx = X.isWinner(b1);
        auto plyro = O.isWinner(b1);
        if (plyrx) {
            cout << X.getName() << " is the winner!\n";
            break;
        } else if (plyro) {
            cout << O.getName() << " is the winner!\n";
            break;
        }

        //switching players
        current = g1.switchPlayer(X, O);
    }
    //if the while loop breaks because the board is full then it is a draw and there is no winner
    if (!X.isWinner(b1) && (!O.isWinner(b1)))cout << "Its a draw!\n";

}

//main function
int main() {
    //greeting
    cout << "Welcome to the Tic Tac Toe Game!\n";
    //while loop to keep playing when player presses 1
    bool exit = true;
    while (exit) {
        run();
        cout << "To play again press 1 ";
        cin >> exit;
    }

}
