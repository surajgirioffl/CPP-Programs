/*Program to find the sum of three number purely on objects*/
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
    Sum obj1, obj2, obj3;
    obj1.get();
    obj2.get();
    obj3.get();
    obj3.summation(obj1.summation(obj2)).display();
    return 0;
}