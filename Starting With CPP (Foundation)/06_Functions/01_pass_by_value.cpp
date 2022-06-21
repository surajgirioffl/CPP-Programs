#include <iostream>
using namespace std;
void swap(int, int); // declaration
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

void swap(int x, int y) // we can also use a,b because it's local variable.
{
    int temp = x;
    x = y;
    y = temp;
    cout << "In function swap()"
         << "a = " << x << " & b = " << y << endl;
}
/*
 *It is clear from above program that the value of a and b copied to x and y.
 *We swap the x and y in function swap() and it's doesn't affect the original value.
 *So,In pass by value the original data remains unaffected.
 */