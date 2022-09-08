#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int b = 20;
    cout << "\033[2J\033[H";
    cout << a++ << " & " << a++ << endl;
    return 0;
}