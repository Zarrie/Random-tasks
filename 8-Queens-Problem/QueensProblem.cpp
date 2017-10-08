#include <iostream>

using namespace std;

int total = 0;
const int tableSize = 10;
bool table[tableSize][tableSize] = {0};

void print()
{
    for (int row = 0 ; row < tableSize ; row++)
    {
        for (int col = 0 ; col < tableSize ; col++)
        {
            cout << table[row][col] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

bool canStep(int row, int col)
{
    for (int counter = 0 ; counter < tableSize ; counter ++)
    {
        if (table [ row ][ counter ] || table [ counter ][ col ])
            return false;
    }
    int i = row, j = col;
    while(i >= 0 && j >= 0)
        {
            if (table[i][j])
                return false;
            i--; j--;
        }
    i = row, j = col;
    while(i < tableSize && j < tableSize )
        {
            if (table[i][j])
                return false;
            i++; j++;
        }
    i = row, j = col;
    while(i >= 0 && j < tableSize )
        {
            if (table[i][j])
                return false;
            i--; j++;
        }
    i = row, j = col;
    while(i < tableSize && j >= 0 )
        {
            if (table[i][j])
                return false;
            i++; j--;
        }

    return true ;
}

void placeQueen(int row, int col)
{
    table[row][col] = 1;
}

void removeQueen(int row, int col)
{
    table[row][col] = 0;
}

void queens(int row)
{
    if (row == 0)
    {
//        print();
        total++;
        return;
    }

    for (int col = 0 ; col < tableSize ; col++)
    {
        if (canStep(row - 1, col))
        {
            placeQueen(row - 1, col);
            queens(row - 1);
            removeQueen(row - 1, col);
        }
    }
}

int main ()
{
    int row = tableSize;

    queens(row);

    cout << total;
    return 0;
}
