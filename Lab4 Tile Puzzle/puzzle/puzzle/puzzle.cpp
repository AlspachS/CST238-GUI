#include <iostream>
#include <string>
#include <iomanip>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::setw;

#include "cpuzzle.h"

//**************************************************
void Display(cPuzzle & puzzle)
{
    for (int row=0; row<puzzle.Size(); row++)
    {
        for (int col=0; col<puzzle.Size(); col++)
        {
            if (puzzle.GetAt(row,col) == 0)
                cout << setw(4) << " ";
            else
                cout << setw(4) << puzzle.GetAt(row,col);
        }
        cout << endl;
    }
}
void ErrorFunc(const string &msg)
{
    cout << msg << endl;
}

int main()
{
    int row, col;
    cPuzzle puzzle(4);
    puzzle.SetErrorFunc(ErrorFunc);

    while (1)
    {
        Display(puzzle);
        cout << "Enter col: ";
        cin >> col;
        cout << "Enter row: ";
        cin >> row;
        puzzle.Move(row, col);
    }

    return 0;
}
