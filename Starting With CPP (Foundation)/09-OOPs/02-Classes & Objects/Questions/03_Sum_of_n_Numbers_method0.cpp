/*Program to find the sum of n numbers purely on objects*/
/*@method0*/
#include <iostream>
using namespace std;

class Sum
{
    int number;

public:
    void get()
    {
        cout << "Write number: ";
        cin >> number;
    }

    Sum summation(Sum obj1)
    {
        Sum obj2;
        obj2.number = number + obj1.number;
        return obj2;
    }

    void display()
    {
        cout << "Number: " << number << endl;
    }
};

int main()
{
    int n; // number of numbers to be added using OOPs
    cout << "Enter the number of numbers to be added: ";
    cin >> n;

    Sum obj, sum; // array of objects of class Sum
    for (int i = 0; i < n - 1; i++)
    {
        obj.get();
        if (i == 0)
            sum.get();
        sum = sum.summation(obj);
    }
    sum.display();
    return 0;
}