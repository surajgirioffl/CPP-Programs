#include <iostream>
using std::cout;
using std::endl;

template <class type1, class type2>
float sum(type1 a, type2 b)
{
    return a + b;
}

template <class type1, class type2, class type3>
float sum(type1 a, type2 b, type3 c)
{
    return a + b + c;
}

int main()
{
    cout << sum(4, 2) << endl;
    cout << sum(4, 2, 3.5) << endl;
    return 0;
}