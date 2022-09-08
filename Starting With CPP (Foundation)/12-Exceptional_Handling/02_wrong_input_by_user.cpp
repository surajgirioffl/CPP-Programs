/*Exceptional handling helps us to avoid the abnormal termination of the program.
 *Using it we use to handle the exception while execution of program to avoid the abnormal termination of program instantly.
 *Actually when any exception occurs while execution then program terminates immediately and it's abnormal termination of program.
 *We fix it by Exceptional handling and by this whenever any termination condition is encountered during execution then the control go in 'catch' block as specified by 'throw'.
 *And by this way, Abnormal termination handled and at the place of exception corresponding 'catch' block is executed.

 *dataType is use to execute the type of particular exception.
 */

/*Let user need to enter number but, he enters string then we need to handle this exception and continue the execution of program without abnormal termination.*/
#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "Write your number (Positive only): ";
    try
    {
        cin >> number;
        if (number < 0)
            throw 'a';
        else if ()
            throw 1.5;
    }
    catch (char) // specified exception to execute in case of negative number
    {
        cout << "Negative number is not allowed." << endl;
    }
    catch (...) /*Catch all statement*/
    {
        cout << "0 entered otherwise... " << endl;
        cout << "Unknown exception: Something went wrong" << endl;
    }
    cout << "\nExecuting next statements........." << endl;
    cout << "You number is " << number << endl;
    return 0;
}
