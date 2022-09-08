/*user input from cin object istream class*/
#include <iostream>
using namespace std;
int main()
{
    int number;
    cout << "write number:" << endl;
    cin >> number;
    cout << "Entered Number is " << number << endl;

    char myString[30];
    cout << "Write your name:" << endl;
    /*cin >> myString;*/ // It will terminate when any whitespace encounters.
    fflush(stdin);
    cin.getline(myString, 30);
    cout << "Your name is " << myString << endl;

    string newString; // newString is the object of 'string' class
    cout << "write any string:" << endl;
    cin >> newString;
    cout << "Your string is " << newString << endl;
}