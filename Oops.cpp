#include <iostream>
#include <cassert>
#include <tuple>
#include <string>

using namespace std;

//creates upper and lower bounds
tuple<int, int> set_values(int YorN) {
    int upperbound;
    int lowerbound;

    if (toupper(YorN) == 0) {
        cout << "\nPlease enter an upper bound:  ";
        cin >> upperbound;
        cin.ignore(256, '\n');
        cout << "\nPlease enter an lower bound:  ";
        cin >> lowerbound;
        cin.ignore(256, '\n');
    }
    else {
        upperbound = 100;
        lowerbound = 1;
    }
    return make_tuple(lowerbound, upperbound);

}

//checks the input and returns if it is incorrect
int check_input(int lower, int higher, int Userinput) {
    if ((Userinput < lower) || (Userinput > higher)) {
        cout << "The input wasn't correct, Please try again.\n";
        return 2;
    }
    else {
        cout << "Your input was: " << Userinput;
        return 1;
    }

}

//Takes the users input and moves it to the correct case
void take_input(int lowerbound, int upperbound) {
    int Userinput, helper = 1;
    string stringinput;

    cout << "\nPlease enter a number " << lowerbound << " to " << upperbound << ", or type help for options.\n";
    cin >> stringinput;

    if (isdigit(stringinput[0])) {
        Userinput = stoi(stringinput);
        helper = check_input(lowerbound, upperbound, Userinput);
    }
    else {
        if (stringinput == "exit") {
            cout << "Exiting now. Goodbye...";
        }
        else if (stringinput == "default") {
            helper = check_input(lowerbound, upperbound, 100);
        }
        else if (stringinput == "help") {
            helper = 2;
            cout << "Type in a number to see if it is within the upper and lower bound\n"
                << "Type in a string to return a string.\n"
                << "Type in exit to leave program.\n"
                << "Type in default to put in a value of 100\n";
        }
        else {
            string idk;
            getline(cin, idk);
            cout << "The value chosen by the user is " << stringinput << idk;
        }
    }

    if (helper == 2) {
        take_input(lowerbound, upperbound);
    }

}

//tests the different functions
void Driver() {
    cout << "starting test..." << endl;
    cout << "\ttesting set values..." << endl;
    int value1 = 0, value2 = 0;
    tie(value1, value2) = set_values(1);
    assert(value1 == 1);
    assert(value2 == 100);

    cout << "\ttesting check input..." << endl;
    value1 = check_input(1, 10, 2);
    assert(value1 = 1);
    value1 = check_input(1, 10, 0);
    assert(value1 = 2);
    value1 = check_input(1, 10, 1);
    assert(value1 = 1);
    value1 = check_input(1, 10, -100);
    assert(value1 = 2);
    value1 = check_input(1, 10, 100);
    assert(value1 = 2);

    cout << "completed Test!" << endl;
}

//main program
int main()
{
    int Userinput = 1;
    char YorN;
    int upperbound, lowerbound;

    cout << "Do you want to enter a lower and upper bounds (Yes or No)?  ";
    cin >> YorN;
    cin.ignore(256, '\n');
    if (toupper(YorN) == 'Y') {
        tie(lowerbound, upperbound) = set_values(0);
    }
    else if (toupper(YorN) == 'T') {
        Driver();
        return 0;
    }
    else {
        tie(lowerbound, upperbound) = set_values(1);
    }

    take_input(lowerbound, upperbound);


    return 0;
}