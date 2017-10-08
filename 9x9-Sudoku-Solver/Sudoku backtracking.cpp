#include <iostream>

using namespace std;

int table[9][9] = {
                  {6,2,0,   9,0,0,   8,0,0},
                  {0,0,8,   2,0,0,   0,9,0},
                  {0,7,0,   6,0,8,   3,0,0},

                  {0,0,0,   0,0,2,   4,0,5},
                  {0,0,0,   0,0,0,   0,0,0},
                  {3,0,5,   0,0,0,   0,0,0},

                  {0,0,9,   3,0,7,   0,4,0},
                  {0,4,0,   0,0,9,   1,0,0},
                  {0,0,7,   0,0,4,   0,6,2},
                };

bool canUse(int number, int row, int col)
{
    for (int i = 0 ; i < 9 ; i++)
    {
        if (number == table[i][col] || number == table[row][i])
        {
            return false;
        }
    }
//    ================= subtable ===================
    int subtableRow = row / 3;
    int subtableCol = col / 3;

    for (int i = subtableRow * 3; i < subtableRow * 3 + 3 ; i++)
    {
        for (int j = subtableCol * 3; j < subtableCol * 3 + 3 ; j++)
        {
            if (number == table[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void print()
{
    cout << "  -------------------\n";
    for (int i = 0 ; i < 9 ; i++)
    {
        if (i % 3 == 0 && i > 0)
            cout << "  -------------------\n";
        cout << " |";
        for (int j = 0 ; j < 9 ; j++)
        {
            if (j % 3 == 0 && j > 0)
            cout << "|";
            cout << table[i][j];
            if (j < 8)
                cout << " ";
        }
        cout << "|";
        cout << "\n";
    }
    cout << "  -------------------\n";
}

void putNum(int num, int row, int col)
{
    table[row][col] = num;
}

void removeNum(int row, int col)
{
    table[row][col] = 0;
}

void sudoku(int row, int col)
{
    if (row == 9)
    {
        print();
        return;
    }

    if (table[row][col] == 0)
    {
        for (int num = 1 ; num <= 9 ; num++)
        {
            if(canUse(num,row,col))
            {
                putNum(num,row,col);
                {
                    if (col < 8)
                    {
                        sudoku(row,col + 1);
                    }
                    else
                        sudoku(row + 1,0);
                }
                removeNum(row,col);
            }
        }
    }
    else {
            if (col < 8)
            {
                sudoku(row,col + 1);
            }
                else
                    sudoku(row+1,0);
    }
}

int main()
{
    sudoku(0,0);

    return 0;
}

/*
{6,2,0,   9,0,0,   8,0,0},
{0,0,8,   2,0,0,   0,9,0},
{0,7,0,   6,0,8,   3,0,0},

{0,0,0,   0,0,2,   4,0,5},
{0,0,0,   0,0,0,   0,0,0},
{3,0,5,   4,0,0,   0,0,0},

{0,0,9,   3,0,7,   0,4,0},
{0,4,0,   0,0,9,   1,0,0},
{0,0,7,   0,0,4,   0,6,2},
*/
