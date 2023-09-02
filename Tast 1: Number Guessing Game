#include <iostream>
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

//play function that runs the game
void play() {
    cout << "Enter your guess:";
    auto random = rand() % 1000 + 1;
    int guess;
    while (true) {
        check_valid_input(guess);

        //compare the players guess to the int random declared above
        if (guess == random) {

            //if the players guess is equal to the random number then it breaks out of the while loop
            cout << "\nYou got it right!\n";
            break;
        }

        //else if the players guess is incorrect then the program checks to see if it's greater than or less than
        // the number random, and it prints the appropriate message to let the player know if their guess was
        // greater than or less than the number
        else if (guess < random) cout << "\nToo low\nTry again:";
        else cout << "\nToo high\nTry again:";
    }
}

//main function
int main() {
    //op is the option chosen from the menu s is also option of y or n for the game to restart
    char op, s = ' ';

    //menu
    cout << "Welcome to the number guessing game!\n"
            "\nChoose from the menu:\n"
            "1- Play\n"
            "2- Game Rules\n"
            "3- Exit\n";

    //while loop that keeps going until the player presses 'n'
    while (true) {

        //if it enters the loop again its based on s and not op so the user doesn't have to enter both if they want to
        // play again
        if (tolower(s) == 'y')op = '1';
        else if (tolower(s) == 'n')op = '3';
        else cin >> op;


        //this while loop makes sure that the input of op is correct
        while (tolower(op) != '1' && tolower(op) != '2' && tolower(op) != '3') {
            cout << "Please press 1, 2 or 3\n";
            cin >> op;
        }

        //if the player presses 2 the rules are then printed on the screen
        if (op == '2') {
            cout << "\nThis is a game that generates a random number and asks the player "
                    "to guess it.\nIf the guess is incorrect the player will be given feedback "
                    "stating whether the guess was too high or too low until the player guesses the correct number\n\n";

            //asking the player if they would like to play the game
            cout << "Do you want to play?(y/n)";

            //enter player option
            cin >> s;

            //this while loop makes sure that the input of s is correct
            while ((tolower(s) != 'y' && tolower(s) != 'n')) {
                cout << "Please press \'y\' or \'n\'\n";
                cin >> s;
            }

        }
        //if the player presses 1 then the game starts to run
        if (op == '1' || tolower(s) == 'y') {
            play();
            cout << "\nPlay again?(y,n)";
            cin >> s;
            //this while loop makes sure that the input of s is correct
            while ((tolower(s) != 'y' && tolower(s) != 'n')) {
                cout << "Please press \'y\' or \'n\'\n";
                cin >> s;
            }
            //if s = 'y' then the game will start again
            continue;
        }

        //if s = 'n' then it will break out of the while loop and effectively ending the game
        if (op == '3') break;

    }
    cout << "\nOkay Bye!";

}
