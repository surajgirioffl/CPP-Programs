#include <iostream>
using std::cout;
using std::endl;

/*Basics of command line arguments*/
/*argc is automatic (number of arguments).
 *argv[0] is by default file name and argv[1,2...] are the arguments passed by user.
 *by default argc = 1.
 *if user enter one argument in command line then argc = 2. (one by default for fileName/Path & 2nd one by user).
 *So number of arguments = number of arguments user entered + 1.
 *On command line each argument is separated by a space.
 */
int main(int argc, char const *argv[])
{
    cout << "Number of arguments written in the command line: " << argc << endl;
    cout << "File name OR file path: " << argv[0] << endl; /*(by default first argument (at index 0) is the name of current file)*/
    if (argc > 1)                                          // if at least one argument is passed by user. (By default first argument is fileName.)
    {
        cout << "All arguments are following:" << endl;
        for (short i = 1; i < argc; i++)
            cout << "Argument " << i + 1 << " is \'" << argv[i] << "\'" << endl;
    }
    return 0;
}

/*we can also use parameter as following in main()..
 * int main(int argc, char const *argv[])
 * int main(int argc, char const **argv)
 * int main(int argc, char *argv[])
 * int main(int argc, const char *argv[])
 */