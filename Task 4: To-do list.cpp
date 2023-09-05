#include <iostream>
#include <limits>
#include "Task 4: To-Do List.h"

using namespace std;

//function that takes input and checks whether its is valid or not and if it isn't it makes the user renter the input

void check_valid_input(int &n) {
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "INVALID INPUT\nPlease reenter:";
    }
}

void check_valid_input(char &ch) {
    cin >> ch;
    while (tolower(ch) != 'y' && tolower(ch) != 'n') {
        cout << "Please enter \'y\' or \'n\':";
        cin >> ch;
    }
}

//view function that prints the task list
void List::view() {

    cout << "       " << "   Task list   " << "       " << endl;
    cout << "===============================" << endl;
    for (auto i = 0; i < list.size(); i++) {
        cout << "  " << i + 1 << "-    " << list[i].first << "       " << list[i].second << endl;
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


//run function is the main of this code
void run(List &lst) {
    int op, n, x;
    string str;
    char ch;
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
                    cout << "Task added successfully\n\n";
                }
                break;

                //remove task/s from list
            case 2:
                //check that task list is not empty
                if (!lst.list.empty()) {

                    lst.view();
                    cout << "How many tasks do you want to remove?\n";
                    check_valid_input(n);

                    //if n is greater than the list size then a message is printed saying so and asking if the user
                    // would like to remove all list items
                    if (n >= lst.list.size()) {
                        while (n >= lst.list.size()) {
                            cout << "There are only " << lst.list.size()
                                 << " tasks in the list would you like to remove them all ?(y/n)\n";
                            check_valid_input(ch);

                            //clear the whole task list if the user enters 'y'
                            if (tolower(ch) == 'y') {
                                lst.list.clear();
                                cout << "All tasks removed successfully\n";
                            }
                            break;
                        }
                    } else {
                        //if n is less than the list size then the program will work as usual
                        while (n--) {
                            cout << "Which task would you like to remove?\nTask";
                            check_valid_input(x);
                            lst.remove(x);
                            cout << "Task removed successfully\n\n";
                        }
                    }

                }
                    //if the task list is empty then the user is asked to select a different function
                else {
                    cout << "The task list is empty, Please select a different function\n";

                }
                break;

                //view task list
            case 3:
                if (lst.list.empty())
                    cout << "\nTask list is empty\n";
                else
                    lst.view();
                break;

                //mark task as complete
            case 4:

                //check that task list is not empty
                if (!lst.list.empty()) {
                    lst.view();
                    cout << "How many tasks have you completed?\n";
                    check_valid_input(n);

                    //if n is greater than the list size then a message is printed saying so and asking if the user
                    // would like to remove all list items
                    if (n >= lst.list.size()) {
                        while (n >= lst.list.size()) {
                            cout << "There are only " << lst.list.size()
                                 << " tasks in the list would you like to mark them all as completed?(y/n)\n";
                            check_valid_input(ch);

                            //mark whole list as completed if the user enters 'y'
                            if (tolower(ch) == 'y') {
                                for (auto i = 1; i <= lst.list.size(); i++) {
                                    lst.task_completed(i);
                                }
                                cout << "All tasks completed successfully\n\n";

                            }
                            break;
                        }

                    } else {
                        //if n is less than the list size then the program will work as usual
                        while (n--) {
                            cout << "Which task have you completed?\nTask";
                            check_valid_input(x);
                            lst.task_completed(x);
                            cout << "Task " << x << " completed successfully\n";
                        }
                    }

                }
                    //if the task list is empty then the user is asked to select a different function

                else {
                    cout << "The task list is empty, Please select a different function\n";

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
