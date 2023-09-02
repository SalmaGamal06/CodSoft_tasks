#include <iostream>
#include <limits>
using namespace std;
//function that takes input and checks whether its is valid or not and if it isn't it makes the user renter the input (n)
void check_valid_input(int& n) {
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT\nPlease reenter:";
    }
}


int main() {
    bool exit = true;
    cout<<"Welcome to the simple calculator app!\n";
    //while loop keeps going until the user presses 1
    while (exit) {
        int a, b, op;
        //menu
        cout << "\nChoose an operation:"
                "\n1- Addition"
                "\n2- Subtraction"
                "\n3- Multiplication"
                "\n4- Division\n";

        //enter option
        cin >> op;
        //function that checks op is valid or not and if it isn't it makes the user renter the op
        while (op != 1 && op != 2 && op != 3 && op != 4 ) {
            cout << "Please press 0, 1, 2, 3 or 4\n";
            cin >> op;
        }
        //switch expression that takes the users option and works accordingly
        switch (op) {

            //Addition
            //takes 2 numbers and adds them together
            case 1:
                cout << "Please enter the first number:" ;
                check_valid_input(a);
                cout << "Please enter the second number:";
                check_valid_input(b);
                cout << a << " + " << b << " = " << a + b;
                break;

            //Subtraction
            //takes 2 numbers and subtracts the first from the last
            case 2:
                cout << "Please enter the first number:" ;
                check_valid_input(a);
                cout << "Please enter the second number:";
                check_valid_input(b);
                cout << a << " - " << b << " = " << a - b;
                break;

            //Multiplication
            //takes 2 numbers and multiplies them
            case 3:
                cout << "Please enter the first number:" ;
                check_valid_input(a);
                cout << "Please enter the second number:";
                check_valid_input(b);
                cout << a << " x " << b << " = " << a * b;
                break;

            //Division
            //takes 2 numbers and divides the first by last
            case 4:
                cout << "Please enter the first number:" ;
                check_valid_input(a);
                cout << "Please enter the second number:";
                check_valid_input(b);
                //loop preventing the division by 0
                while (b==0) {
                    cout << "MATH ERROR\nPlease reenter b:";
                    cin >>  b;
                }
                cout << a << " / " << b << " = " << a / b;
                break;
        }
        cout << "\nTo continue, press 1\n";
        cin >> exit;
    }
    cout<<"Thank you for using our simple calculator!\n";
}
