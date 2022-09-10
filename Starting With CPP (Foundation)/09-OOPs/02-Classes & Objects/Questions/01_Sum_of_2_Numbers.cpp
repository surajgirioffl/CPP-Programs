/*To find sum of two number purely on objects*/
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

    Sum summation(Sum obj)
    {
        Sum obj2;
        obj2.number = number + obj.number;
        return obj2;
    }

    void display()
    {
        cout << "Number: " << number << endl;
    }
};

int main()
{
    Sum obj1, obj2;
    obj1.get();
    obj2.get();
    obj1.summation(obj2).display();
    return 0;
}