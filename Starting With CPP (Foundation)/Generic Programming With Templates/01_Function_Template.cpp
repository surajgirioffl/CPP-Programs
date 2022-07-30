#include <iostream>
using namespace std;

template <class type>
type sum(type a, type b)
{
    return a + b;
}

int main()
{
    cout << sum(3, 5) << endl;
    cout << sum(1.2, 5.2) << endl;
    return 0;
}