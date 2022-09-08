/*user verification using command line arguments*/
#include <iostream>
using namespace std;

int main(int argc, const char **argv)
{
    // let following are the desired username & password.
    string userName = "surajgirioffl";
    string password = "123";

    /*user needs to enter username and password in command line arguments*/
    if (argc < 3) // argc must be 3 (1st for filename, 2nd for username, 3rd for password).
        cout << "At least 2 arguments required (username and password)..." << endl;
    else if (userName == argv[1] && password == argv[2])
        cout << "User verified successfully........" << endl;
    else
        cout << "Invalid username and password.." << endl;
    return 0;
}
