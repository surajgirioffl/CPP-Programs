#include <iostream>
using namespace std;
class Number
{
    int value;

public:
    void get()
    {
        cout << "Write value: ";
        cin >> value;
    }

    void displayOtherObjectContents(Number obj)
    {
        cout << "Value of current object: " << value << endl;
        cout << "Value of passed object: " << obj.value << endl;
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Number obj1, obj2;
    obj1.get();
    obj2.get();
    obj1.displayOtherObjectContents(obj2);
    return 0;
}