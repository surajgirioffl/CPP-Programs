/*Question: print the following pattern:
 *1
 *4 6
 *9 11 13
 *17 19 21 23
 *....
 */

#include <bits/stdc++.h>
using namespace std;

void pattern(int rows)
{
    short n = 1;
    short firstElementOfCurrentRow;
    short adder = 3;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                firstElementOfCurrentRow = n;
            cout << n << " ";
            if (j != i)
                n += 2;
        }
        n = firstElementOfCurrentRow + adder;
        adder += i + 2;
        cout << endl;
    }
}

int main()
{
    short rows;
    cout << "\033[2J\033[HHow many rows do you want to print the pattern: ";
    cin >> rows;
    pattern(rows);
    return 0;
}