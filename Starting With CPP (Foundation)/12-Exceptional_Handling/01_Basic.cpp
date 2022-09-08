/*Basic understanding of Exceptional Handling*/
#include <iostream>
using namespace std;
int main()
{
    short a, b;
    cout << "\033[2J\033[HFor finding a/b, write a and b : ";
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw b; /*throw exception when b==0 occurs*/
        else
            cout << "a/b = " << a / b << endl;
    }
    catch (short b)
    {
        cout << "It's not possible to divide by zero." << endl;
        cout << "a/b = Infinity..." << endl;
    }
}