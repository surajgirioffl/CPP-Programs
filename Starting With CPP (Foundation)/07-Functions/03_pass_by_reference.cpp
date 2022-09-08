/*pass by reference*/
#include <iostream>
using namespace std;
void swap(int &, int &); // declaration
int main()
{
    system("cls");
    int a = 5;
    int b = 10;

    cout << "In function main()" << ends
         << "a = " << a << " & b = " << b << endl;

    swap(a, b);
    cout << "In function main() after return from swap()"
         << "a = " << a << " & b = " << b << endl;
    return 0;
}

void swap(int &x, int &y) // we can also use a,b because it's local variable.
{
    int temp = x;
    x = y;
    y = temp;
    cout << "In function swap()"
         << "a = " << x << " & b = " << y << endl;
}
