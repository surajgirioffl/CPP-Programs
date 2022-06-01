/*To find the given number is odd or even*/
#include <iostream>
using namespace std;
class Maths
{
public:
    /*returns true if number is even else returns false*/
    bool isEven(int number)
    {
        if (number % 2 == 0)
            return true;
        return false;
    }
};

int main()
{
    system("cls");
    int number;
    cout << "write number:" << endl;
    cin >> number;
    Maths obj;
    if (obj.isEven(number))
        cout << number << " is an even number." << endl;
    else
        cout << number << " is an odd number." << endl;
    return 0;
}