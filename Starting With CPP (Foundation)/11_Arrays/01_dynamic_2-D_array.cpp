#include <iostream>
using namespace std;
class myMatrix
{
public:
    void display(char **matrix)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "\t";
            for (int j = 0; j < 3; j++)
            {
                if (j == 1)
                    cout << "\e[1;32m |   \e[1;0m";
                cout << *(*(matrix + i) + j) << "  ";
                // cout << matrix[i][j] << ends;
                if (j == 1)
                    cout << "\e[1;32m |  \e[1;0m";
            }
            cout << endl;
            if (i == 0 || i == 1)
                cout << "\e[1;32m--------------------------------\e[0m" << endl;
        }
    }
};

int main()
{
    system("cls");
    char **matrix = (char **)calloc(3, sizeof(char *));
    for (int i = 0; i < 3; i++)
        matrix[i] = (char *)calloc(3, sizeof(char));

    // for matrix+0
    **matrix = 'x';
    *(*matrix + 1) = 'y';
    *(*matrix + 2) = 'z';

    // for matrix+1
    **(matrix + 1) = 'a';
    *(*(matrix + 1) + 1) = 'b';
    *(*(matrix + 1) + 2) = 'c';

    // for matrix+2
    **(matrix + 2) = 'm';
    *(*(matrix + 2) + 1) = 'n';
    *(*(matrix + 2) + 2) = 'o';

    myMatrix obj;
    // obj.display(matrix);

    cout << endl
         << *matrix << endl;

    for (int i = 0; i < 3; i++)
        free(*matrix + i); // freeing inner allocated memory
    free(matrix);          // freeing outer allocated memory
}