/*native or traditional explicit typecasting*/
#include <iostream>
using namespace std;
class typeCasting
{
    int numInt;
    float numFloat;
    char ch;

public:
    void test()
    {
        numInt = 88;
        numFloat = 20.5400;
        ch = 'B';
        char ch2;
        cout << "write a character" << endl;
        cin.get(ch2);

        cout << (char)numInt << endl;
    }
};

int main()
{
    typeCasting obj;
    obj.test();
}