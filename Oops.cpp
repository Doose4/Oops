#include <iostream>
#include <cassert>
#include <tuple>
#include <string>

using namespace std;

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

int check_input(int lower, int higher, int Userinput) {
    if ((Userinput < lower) || (Userinput > higher)) {
        cout << "The input wasn't correct, Please try again.\n";
        return 0;
    }
    else {
        cout << "Your input was: " << Userinput;
        return 1;
    }

}

void take_input(int lowerbound, int upperbound) {
    int Userinput, helper = 1;
    string stringinput;

    cout << "\nPlease enter a number " << lowerbound << " to " << upperbound << ":  ";
    cin >> stringinput;

    if (isdigit(stringinput[0])) {
        Userinput = stoi(stringinput);
        helper = check_input(lowerbound, upperbound, Userinput);
    }
    else {
        if (stringinput == "exit") {
            cout << "goodbye...";
        }
        else if (stringinput == "default") {
            helper = check_input(lowerbound, upperbound, 100);
        }
        else {
            helper = 0;
        }
    }

    if (helper == 0) {
        take_input(lowerbound, upperbound);
    }

}
 

void Driver() {
    
}

int main()
{
    int Userinput=1;
    char YorN;
    int upperbound,lowerbound;

    cout << "Do you want to enter a lower and upper bounds (Yes or No)?  ";
    cin >> YorN;
    cin.ignore(256, '\n');
    if (toupper(YorN) == 'Y') {
        tie(lowerbound, upperbound) = set_values(0);
    } else {
        tie(lowerbound, upperbound) = set_values(1);
    }
    
    take_input(lowerbound, upperbound);
    
    
    return 0;
}