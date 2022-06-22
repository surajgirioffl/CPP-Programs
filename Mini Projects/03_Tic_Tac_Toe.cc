/*Tic-Tac-Toe Game using C++*/
/**
 *author: Suraj Kumar Giri.
 *Date: 21-06-2022
 *Time: 23:54:27
 */

/**Tic-Tac-Toe playing board
 **For user
  1 2 3
  4 5 6
  7 8 9
 *user can enter 1,2,3... for select the the respective cell
 **For Developer
  00 01 02
  10 11 12
  20 21 22
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
class general
{
public:
    /*returns random number. Changes every second.*/
    int randomNumber()
    {
        time_t seed = time(NULL);
        srand(seed);
        return rand();
    }
};

class allMenu
{
public:
    /*welcome menu*/
    void welcomeMenu()
    {
        cout << "\e[2J\e[H";
        cout << "\e[1;31m************WELCOME TO TIC-TAC-TOE GAME.************" << endl;
        cout.width(63);
        cout << "\e[1;36mDeveloper: Suraj Kumar Giri\e[0m" << endl;
    }

    /*top block of gameRestartMenu which need to print repeatedly if user clear the screen*/
    void gameRestartMenuBlock()
    {
        cout << "\n\n\033[38;5;208m+++++++++++++++++++GAME RESTART MENU++++++++++++++++++++\033[0m" << endl;
        cout << "\033[38;5;201mDo you want to restart the game?" << endl
             << "\033[38;5;190m=> Press '1' or 'enter' to restart the game." << endl
             << "=> Press '#' to exit the game." << endl
             << "=> Press '@' to clear the display.\033[0m" << endl
             << "\033[38;5;159mWrite your choice:\033[0m" << endl;
        cout << "$ ";
    }

    /*display the requires command to user to restart the game. returns true if user wants to restart the game else false*/
    bool gameRestartMenu()
    {
        while (true)
        {
            gameRestartMenuBlock();
            fflush(stdin); // flushing the standard input stream's buffer
            char choice = cin.get();
            short choiceInInt = choice - 48; // converting character to integer using ASCII
            if (choiceInInt == 1 || choice == '\n')
                return true; // means user want to restart the game
            else if (choice == '@')
            {
                system("cls");
                continue;
            }
            else if (choice == '#')
                return false; // if user exits the game
            else
            {
                cout << "\033[1;31mFatal Error: Invalid choice." << endl;
                cout << "\033[2mPlease select a choice again.\033[0m" << endl;
            }
        }
    }

    void gameLevelMenuBlock()
    {
        cout << "\033[1;34m===============GAME LEVEL MENU================\033[0m" << endl;
        cout << "\033[38;5;82m=> Press '1' for Easy Level." << endl;
        cout << "=> Press '2' for Medium Level." << endl;
        cout << "=> Press '3' for Impossible Level." << endl;
        cout << "=> Press '#' for exit game." << endl;
        cout << "=> Press '@' for clear the display.\033[0m" << endl;
        cout << "\033[38;5;123mWrite your choice:\033[0m" << endl;
    }

    // /*take user input for menu displayed by called function. Returns userChoiceInInt if choice is correct and -1 if user wants to exit. I have defined this function user interaction in many menus are similar and it cold be defined in a function at one place*/
    // short interactWithUserInMenu()
    // {
    // }

    /*Menu to ask user for level of game he/she wants to play. returns the selected level (1-easy,2-medium,3-impossible) and returns -1 if user exits the game*/
    short gameLevelMenu()
    {
        while (true)
        {
            gameLevelMenuBlock();
            cout << "$ ";
            fflush(stdin); // flushing the standard input stream's buffer
            char choice = cin.get();
            short choiceInInt = choice - 48; // converting character to integer using ASCII
            if (choiceInInt >= 1 && choiceInInt <= 3)
                return choiceInInt;
            else if (choice == '\n' || choice == '@')
            {
                system("cls");
                welcomeMenu(); // because this is 2nd menu after welcome menu. So, welcome menu should be visible along with it.
                continue;
            }
            else if (choice == '#')
                return -1; // if user exits the game
            else
            {
                cout << "\033[1;31mFatal Error: Invalid choice." << endl;
                cout << "\033[2mPlease select a choice again.\033[0m" << endl;
            }
        }
    }
};

class ticTacToe : private allMenu
{
    char matrix[3][3]; // for matrix of Tic-Tac-Toe
    char computerChar; // for computer playing character like 'X' or 'O'. By default 'O'
    char userChar;     // for user playing character like 'X' or 'O'. By default 'X'
    short filledCells; // stores number of cells filled (by user & computer characters 'X'/'O). By default it is 0
    enum gameLevel
    {
        easy,
        medium,
        impossible
    } level;
    /*if user/computer won the game then the position of all three cells which are responsible for winning are following:*/
    //

    /*interact with user to select the playing character and also assign the respective character to variables 'computerChar' & 'userChar' on the basis of user input*/
    void playingCharacterSelector()
    {
        while (true)
        {
            cout << "\033[38;5;225m\nSelect your playing character." << endl;
            cout << "\033[38;5;214m=> Press '1' for 'X' " << endl;
            cout << "=> Press '2' for 'O' " << endl;
            cout << "=> Press 'enter' for default.\033[0m" << endl;
            char choice;
            cout << "$ ";
            fflush(stdin); // flushing the standard input stream's buffer
            choice = cin.get();

            if (choice == '\n') // if user has pressed 'enter' for default
                break;
            else
            {
                if (choice == '1') // means userChar='X' and by default it is same
                    break;
                else if (choice == '2')
                {
                    userChar = 'O';
                    computerChar = 'X';
                }
                else
                {
                    cout << "\033[1;31mFatal Error: Invalid Choice." << endl;
                    cout << "\033[1;32mPlease select your choice again.\033[0m" << endl;
                }
            }
        }
    }

    /*to display the instructions for input in cell of matrix/gamePad of ticTacToe*/
    void displayCellInputInstructions()
    {
        cout << "\n\033[38;5;200m=================READ BELOW CAREFULLY=================" << endl;
        cout << "\033[38;5;190m:: Enter the number filled below in cells to select your choice for that cell in game." << endl;
        cout << ":: Any other input rather than 1-9 is invalid." << endl;
        cout << ":: You can't select the filled cell again in the same game.\033[0m" << endl
             << endl;

        short number = 1; // for display the number that user will select in game to select the respective cell
        for (int i = 0; i < 3; i++)
        {
            cout << "\t";
            for (int j = 0; j < 3; j++)
            {
                if (j == 1)
                    cout << "\e[1;32m |   \e[1;0m";
                cout << number++ << "  ";
                // cout << matrix[i][j] << ends;
                if (j == 1)
                    cout << "\e[1;32m |  \e[1;0m";
            }
            cout << endl;
            if (i == 0 || i == 1)
                cout << "\e[1;32m--------------------------------\e[0m" << endl;
        }
    }

    /*returns true if cell is empty else false. Takes argument of rows and column*/
    bool isCellEmpty(short row, short col)
    {
        if (matrix[row][col] == ' ') // if cell filled with space then it will be empty
            return true;
        return false;
    }

    /*check if user/computer won the game or not
     *Call this function if at least total 5 cells are filled by user & computer. 3 cells by user & 2 by computer and vice versa (depends upon who started first)
     *At least 3 cells with same playingCharacter requires for fulfill the winning condition for the player of that playingCharacter
     **About this function:
     *Take argument of playingCharacter 'X' or 'O' and check all possible conditions (8 conditions) for winning the game.
     *If received playing character fulfill the winning conditions. Then it returns true else false.
     *If won then the one of user/computer won the game whose playingCharacter==received playingCharacter
     */
    bool isWonTheGame(char playingCharacter) // playingCharacter of player
    {
        /*at least 5 cells must be filled by user & computer to be in probability of winning (see above comment for details). We will first check the condition of filled cells and if it true as per desired then we will go forward else return false*/
        if (filledCells < 5)
            return false;

        /************************if(filledCells>=5)*****************************/
        /*total 8 conditions are winning conditions*/
        /**WINNING CONDITIONS
         **Row-Wise
         *1. 00,01,02
         *2. 10,11,12
         *3. 20,21,22
         **Column-Wise (just opposite index of Row-Wise)
         *4. 00,10,20
         *5. 01,11,21
         *6. 02,12,22
         **Diagonal
         *7. 00,11,22
         *8. 20,11,02
         */

        /*FIXING HUGE BUG
         *we must need to verify that the cell which are checking currently must have filled.
         *If any of the cell in 'winning condition' is empty then there will no option to win. If cell contains 'space' then it will empty And we will check the condition for empty
         *If we don't do so, there will always spaces which fulfill the winning conditions and user will win the match without fulfilling the winning conditions.
         *
         *
         */

        /**Row-Wise. for 1,2,3*/
        for (int i = 0; i < 3; i++)
        {
            /*we are checking the empty cell. If any of the cell in current row is empty then there will no any possibility of winning & we will continue the loop to next iteration.*/
            if (isCellEmpty(i, 0) || isCellEmpty(i, 1) || isCellEmpty(i, 2))
                continue;                                                          // if cell is empty then there is no any possibility of winning. So, continue the loop
            else if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) // it is like "if(a==b && b==c)"
                return true;
        }

        /**Column-Wise. for 4,5,6*/
        for (int i = 0; i < 3; i++)
        {
            /*we are checking the empty cell. If any of the cell in current column is empty then there will no any possibility of winning & we will continue the loop to next iteration.*/
            if (isCellEmpty(0, i) || isCellEmpty(1, i) || isCellEmpty(2, i))
                continue;                                                          // if cell is empty then there is no any possibility of winning. So, continue the loop
            else if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) // it is like "if(a==b && b==c)"
                return true;
        }

        /**Diagonal-Wise. for 7,8*/
        // we can simply write if(conditions) to do here. Because size is known 3x3. But if there will custom size of matrix then we must need to use loop. Currently, we are not using loop here. But we will use it later for further extension if required.
        /*we are checking the empty cell. If any of the cell in current diagonal is empty then there will no any possibility of winning & we will continue the loop to next iteration.*/
        if (isCellEmpty(0, 0) || isCellEmpty(1, 1) || isCellEmpty(2, 2))
        {
        } /*do nothing. Just we have to execute this block if condition satisfied that any of cell is empty. And it's not possible to win via this winning condition */ // we can't return false here because it may be possible that any below winning condition will satisfy.
        else if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])                                                                                          // it is like "if(a==b && b==c)"
            return true;

        /*we are checking the empty cell. If any of the cell in current diagonal is empty then there will no any possibility of winning & we will continue the loop to next iteration.*/
        if (isCellEmpty(0, 2) || isCellEmpty(1, 1) || isCellEmpty(2, 0))
        {
            // empty
            /*see above 2nd comment for details*/
        }
        else if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) // it is like "if(a==b && b==c)"
            return true;

        /*if all conditions fails means no any of 8 winning conditions satisfied. So, No winning & as expected we will return false*/
        return false;
    }

    /*when user input command 1...9 to select a cell then this function will take that cellNumber (number from 1-9) and give the real postion of the cell by giving row index in 'i' and column index in 'j'*/
    void
    commandInterpreter(short cellNumber, short &i, short &j)
    {
        switch (cellNumber)
        {
        case 1:
            i = 0;
            j = 0;
            break;
        case 2:
            i = 0;
            j = 1;
            break;
        case 3:
            i = 0;
            j = 2;
            break;
        case 4:
            i = 1;
            j = 0;
            break;
        case 5:
            i = 1;
            j = 1;
            break;
        case 6:
            i = 1;
            j = 2;
            break;
        case 7:
            i = 2;
            j = 0;
            break;
        case 8:
            i = 2;
            j = 1;
            break;
        case 9:
            i = 2;
            j = 2;
            break;
        }
    }

    /*to input 'X' or 'O' from user in game. On success returns true else false */
    bool userTurn()
    {
        char cellNumber;      // store cell number (command)
        short tempCellNumber; // store cell number in integer (by subtracting 48 from character)
        while (true)
        {
            cout << "\033[38;5;51m\nWrite you cell choice: \033[38;5;99m(Press '#' to exit & '@' to clear the screen.)\033[0m" << endl;
            cout << "$ ";
            fflush(stdin);
            cellNumber = cin.get();
            tempCellNumber = cellNumber - 48; // converting character to respective integer for testing. (typeCasting not working. why?)

            /*now checking the conditions*/
            if (cellNumber == '\n') // if user pressed enter
                continue;
            else if (cellNumber == '#')
                return false;
            else if (cellNumber == '@')
            {
                system("cls");
                displayGamePad();
                continue;
            }
            else if (tempCellNumber < 1 || tempCellNumber > 9) // cell number must be between 1 and 9
            {
                cout << "\033[1;31m\nFatal Error: Invalid Cell Choice." << endl;
                cout << "\033[1;32mPlease select your choice again.\033[0m" << endl;
            }
            else
            {
                /*now we have to interpret the command (cellNumber) to it's proper index to insert the playingCharacter in the matrix/GamePad*/
                short i, j; // for row and column of cell selected by user
                commandInterpreter(tempCellNumber, i, j);
                /*we will first check that if the given cell is empty or not. If cell is empty then good and If already filled then it will error and user need to re-input the cellNumber*/
                if (!isCellEmpty(i, j)) // returns true if empty else false
                {
                    cout << "\033[1;31m\nFatal Error: Invalid Cell Choice." << endl;
                    cout << "Selected cell '" << tempCellNumber << "' is already filled." << endl;
                    cout << "\033[1;32mPlease select your choice again.\033[0m" << endl;
                    continue;
                }
                matrix[i][j] = userChar; // assigning the userChar/playingCharacter in the selected cell
                break;
            }
        }
    }

    /*to input 'X' or 'O' from computer in game. On success returns true else false*/
    bool computerTurn()
    {
        short cellNumber; // to store the cellNumber selected by computer
        short i, j;       // for row and column of selected cell

        /*Three levels of game 1. easy, 2. Medium, 3. Impossible*/
        /************EASY LEVEL*************/
        /*We will not use any advanced logic here. We will simple use random number b/w 1-9 and fill the cell. */
        if (level == easy)
        {
            general object;
            int modifier = 21; // taking any random number (let 21) to modify cellNumber (because randomNumber() changes value every second. But loop may be go in next iteration within a second. If we don't modify the value then we will get same result) //no effect on logic
            while (true)
            {
                cellNumber = (modifier + object.randomNumber()) % 10; //%10 because if a number divided by x then remainder will be from 0 to x-1. And here we need value from 1 to 9
                /*now we have to interpret the command (cellNumber) to it's proper index to insert the playingCharacter in the matrix/GamePad*/
                commandInterpreter(cellNumber, i, j);
                if (isCellEmpty(i, j)) // returns true if cell is empty else false
                    break;
                else
                {
                    modifier *= 3; // multiplying by random number, let 3
                    continue;
                }
            }
        }
        else if (level == medium)
        {
        }
        else // if(level == impossible)
        {
        }

        /*============For All Levels==============*/
        matrix[i][j] = computerChar;
        return true;
    }

    /*To display the matrix/GamePad of Tic-Tac-Toe. This function can be used to display while playing and after won the game also. Pass 'true' in argument if you want to display after won else default argument is 'false' and no need to pass it.*/
    void displayGamePad(bool isWon = false)
    {
        short command = 1;
        for (int i = 0; i < 3; i++)
        {
            cout << "\t";
            for (int j = 0; j < 3; j++)
            {
                if (j == 1)
                    cout << "\e[1;32m |   \e[1;0m";

                /****cell character printing starts*/
                if (isCellEmpty(i, j))
                    cout << "\033[0m\033[38;5;234m\e[2m\e[3m" << command++ << "  \033[0m";
                // cout << matrix[i][j] << "\033[0m\e[2m" << command++ << "  \033[0m";//initially, this code is used above but it prints extra space which hamper the cells uniform area

                else // means cell is filled by user/computer input
                {
                    /*adding different color for 'X' and 'O'*/
                    if (matrix[i][j] == 'X')
                        cout << "\033[38;5;202m" << matrix[i][j] << "  \033[0m";
                    else if (matrix[i][j] == 'O')
                        cout << "\033[1;36m" << matrix[i][j] << "  \033[0m";
                    command++; // as cell traversal increases the command for user 1...9 will increases
                }
                /****cell character printing ends*/

                // cout << matrix[i][j] << ends;
                if (j == 1)
                    cout
                        << "\e[1;32m |  \e[1;0m";
            }
            cout << endl;
            if (i == 0 || i == 1)
                cout << "\e[1;32m--------------------------------\e[0m" << endl;
        }
    }

    /*supreme function to control all activities in the game. returns true on success else false on failure or exit without completion of game*/
    bool startGame()
    {
        /*0. first we need to ask the level of game user wants to play*/
        short returnedValue = gameLevelMenu(); // gameLevelMenu() returns -1 if user exits
        if (returnedValue == -1)
            return false;
        else if (returnedValue == 1)
            level = easy;
        else if (returnedValue == 2)
            level = medium;
        else // if(returnedValue==3)
            level = impossible;

        /*1. Now, we will ask user to select the playingCharacter 'X' or 'O'*/
        playingCharacterSelector();
        /*2. we need to display the command that will be used by user to select his/her cell to play*/
        displayCellInputInstructions();
        cout << endl;
        system("pause"); // pause the screen until user press any key
        // cout << "\e[2J\e[H"; // clear the display and placed to cursor to position (0,0)
        system("cls"); // clear the display

        /*now game started*/
        bool wonFlag = false; // this is a flag to mark if any one won the game or not. By default it is false
        while (filledCells <= 9)
        {
            displayGamePad();
            if (userTurn())
            {
                filledCells++;
                if (filledCells > 4)
                    if (isWonTheGame(userChar))
                    {
                        system("cls"); // clear the display
                        displayGamePad(true);
                        cout << "-_-_-_-_-_-_-_-_-_-_-_-_CONGRATULATION, YOU WON THE GAME-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
                        wonFlag = true;
                        break;
                    }
                    /*COMMENT CODE 1021
                     *actually the person who started the game will end the game. Means here user will end the game by selecting the last empty cell.
                     *So, when last cell is filled by user then there is no cell left for computer turn.
                     *So, when filledCells==9 we have to break the loop.
                     *Control will come in below elif only if neither user nor computer won the game. Means when DRAW condition occurs.
                     */
                    else if (filledCells == 9)
                    {
                        system("cls"); /*clearing the display after 1 round (1 turn for user and 1 turn for computer)*/
                        cout << "\n\033[38;5;190m********************\033[38;5;201m\033[1m\033[3mGamePad After '" << (filledCells / 2) + 1 << "' User Turn"
                             << " && '" << filledCells / 2 << "' Computer Turn\033[0m\033[38;5;190m*****************\033[0m" << endl;
                        displayGamePad(); // displaying the draw gamePad
                        break;            // breaking the loop because all cells are filled and no one won. (DRAW)
                    }
            }
            else
                return false; // user exit the game without completion

            // cout << "\n\033[38;5;190m******************************\033[38;5;201m\033[1m\033[3mGamePad After User Turn\033[0m\033[38;5;190m******************************\033[0m" << endl;
            if (computerTurn())
            {
                filledCells++;
                if (filledCells > 4)
                    if (isWonTheGame(computerChar))
                    {
                        system("cls");
                        displayGamePad();
                        cout << "COMPUTER WON THE GAME." << endl;
                        wonFlag = true;
                        break;
                    }
            }
            // displayGamePad();
            system("cls"); /*clearing the display after 1 round (1 turn for user and 1 turn for computer)*/
            cout << "\n\033[38;5;190m********************\033[38;5;201m\033[1m\033[3mGamePad After '" << filledCells / 2 << "' User Turn"
                 << " && '" << filledCells / 2 << "' Computer Turn\033[0m\033[38;5;190m*****************\033[0m" << endl;
        }             /*end of while*/
        if (!wonFlag) // if no one won the game then 'wonFlag' will be false and we have display the 'DRAW' status of the game
            cout << "No one won the game. **DRAW**" << endl;
        return true;
    }

public:
    /*constructor*/
    ticTacToe()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                matrix[i][j] = ' '; // adding space in each cell
        }

        computerChar = 'O'; // assigning by default value
        userChar = 'X';     // assigning by default value
        filledCells = 0;    // Initially, number of cells filled with 'X' or 'O' will by zero.
    }

    /*destructor*/
    ~ticTacToe() {}

    bool start()
    {
        return startGame();
    }
};

/*main() function*/
int main()
{
    while (true)
    {
        system("cls");
        {
            /*using block because after returning of control then object will be destroyed by destructor*/
            allMenu menuObject;
            menuObject.welcomeMenu();
            ticTacToe obj;
            if (!obj.start()) // start returns true after successful completion of game one times
                break;        // if start returns false means user want to exit the game.
        }
        allMenu menuObject;
        if (menuObject.gameRestartMenu())
            continue;
        else
            break;
    }
    cout << "\n\033[38;5;51mTHANKS FOR USING TIC-TAC-TOE." << endl
         << "\033[38;5;128mSee you soon!" << endl
         << "Bye Bye........." << endl;
    cout << "\033[1;32mExited from main() successfully.\e[0m" << endl;
    system("pause");
}