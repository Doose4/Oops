#include <iostream>

using namespace std;

int main()
{
    int Userinput;
    cout << "Hello, Please enter a number 1 to 100\n";
    cin >> Userinput;
    
    while ((Userinput <= 0) || (Userinput >= 101)){
        cout << "The input wasn't correct, Please try again.\n";
        cin >> Userinput;
    }

    cout << "Your input was: " << Userinput;
    return 0;
}
