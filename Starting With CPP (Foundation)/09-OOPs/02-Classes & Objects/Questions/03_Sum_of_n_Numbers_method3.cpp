/*Program to find the sum of n numbers purely on objects*/
/*@method3*/
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

    Sum *obj = (Sum *)calloc(n, sizeof(Sum)); // pointer to array of objects of class Sum
    for (int i = 0; i < n; i++)
        (obj + i)->get();

    for (int i = 1; i < n; i++)
        *(obj + 0) = (obj + 0)->summation(obj[i]);

    obj[0].display();
    free(obj);
    return 0;
}