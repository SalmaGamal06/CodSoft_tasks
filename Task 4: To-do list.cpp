#include <iostream>
#include <limits>
#include "Task 4: To-Do list.h"

using namespace std;

//function that takes input and checks whether its is valid or not and if it isn't it makes the user renter the input (n)

void check_valid_input(int &n) {
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT\nPlease reenter:";
    }
}

//view function that prints the task list
void List::view(List &lst) {
    cout << "   " << "  Task    " << "     Status      " << endl;
    for (auto i = 0; i < lst.list.size(); i++) {
        cout << i + 1 << " -  " << lst.list[i].first << "         " << list[i].second << endl;
    }
}

//removes item from the task list
void List::remove(int x) {
    list.erase(list.begin() + x - 1);
}

//adds task to task list as well as its status(completed or pending )
void List::add(string &str) {
    pair<string, string> p1;
    p1.first = str;
    p1.second = "Pending";
    list.push_back(p1);
}

//changes the status of a task to completed
void List::task_completed(int x) {

    list[x - 1].second = "Completed";
}

//run function is the core of this code
void run(List &lst) {
    int op, n, x;
    string str;
    cout << "Welcome to to do list application!\n";
    bool exit = true;
    while (exit) {
        //menu
        cout << "\n1- Add Task\n"
                "2- Remove task\n"
                "3- View task list\n"
                "4- Mark task as done\n\n"
                "To exit the program press 0\n";
        check_valid_input(op);

        //while loop to check that opp is valid
        while (op != 0 && op != 1 && op != 2 && op != 3 && op != 4) {
            cout << "Please press 0, 1, 2, 3 or 4\n";
            check_valid_input(op);
        }
        //switch expression that takes the users option and works accordingly
        switch (op) {
            //exit
            case 0:
                exit = false;
                break;

                //add task/s to list
            case 1:
                cout << "How many tasks do you want to add?\n";
                check_valid_input(n);
                while (n--) {
                    cout << "Task " << lst.list.size() + 1 << " :";
                    cin >> str;
                    lst.add(str);
                    cout << "Task added successfully\n";
                }
                break;

                //remove task/s from list
            case 2:
                lst.view(lst);
                cout << "How many tasks do you want to remove?\n";
                check_valid_input(n);
                while (n--) {
                    cout << "Which task would you like to remove?\nTask";
                    check_valid_input(x);
                    lst.remove(x);
                    cout << "Task removed successfully\n";
                }
                break;

                //view task list
            case 3:
                lst.view(lst);
                break;

                //mark task as complete
            case 4:
                lst.view(lst);
                cout << "How many tasks have you completed?\n";
                check_valid_input(n);
                while (n--) {
                    cout << "Which task have you completed?\nTask";
                    check_valid_input(x);
                    lst.task_completed(x);
                    cout << "Task " << x << " completed successfully\n";
                }
                break;

        }

    }
}

//main function
int main() {

    List lst;
    run(lst);

}
