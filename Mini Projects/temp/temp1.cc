#include <iostream>
using namespace std;

int isIt(int a, int b, int c...)
{
    // int sum += a + b + c...;
}

bool isInSumSeries(int element1, int element2, int element3...)
{
    if (element2 - element1 == element3 - element2)
        return true;
    return false;
}

int main()
{

    cout << "Is in sequence: " << isInSumSeries(1, 4, 9) << endl;
}