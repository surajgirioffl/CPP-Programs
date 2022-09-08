#include <iostream>
#include <fstream>
using namespace std;

/*command line arguments must be as follows:
 *To write in a file (newFile): exeFile <fileName> -w <data to write (without space)>
 *To read a file (existing File): exeFile <fileName> -r
 */
int main(int argc, char *argv[])
{
    if (argc < 3)
        cout << "At least two arguments required (except default)..." << endl;

    string fileName = argv[1]; /*argv[0] is the name of executable file by default */
    string mode = argv[2];

    if (mode == "-r") // read existing file
    {
        fstream fin;
        fin.open(fileName, ios::in);
        if (!fin)
            cout << "Couldn't open the file or file doesn't exist" << endl;
        else
        {
            while (!fin.eof())
            {
                char array[1000];
                fin.getline(array, sizeof(array));
                cout << array << endl;
            }
            fin.close();
        }
    }
    else if (mode == "-w") // write in a new file
    {
        fstream fout;
        fout.open(fileName, ios::out);
        if (!fout)
            cout << "Unable to create file...Unknown error occurred...." << endl;
        else
        {
            if (argc < 4) // means if user hasn't written any word to save directory in the new file.
            {
                // we will take data from user
                char data[1000];
                cout << "\033[1;36mWrite data to save in the file \"" << fileName << "\": \033[0m";
                cin.getline(data, 1000);
                fout << data;
                cout << "File created successfully with entered data..." << endl;
            }
            else
            {
                fout << argv[3];
                cout << "File created successfully with given word...." << endl;
            }
        }
        fout.close();
    }
    else
        cout << "Invalid mode (must be <-w> or <-r>)..." << endl;

    return 0;
}
