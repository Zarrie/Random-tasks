#include <iostream>

using namespace std;

char maze[10][10];

const int coins = 3;
int takenCoins = 0;

void markAvailability(int i, int j, char value) // '#' stands for unavailable '0'(ASCII) stands for available
{
    //if (maze[i][j] != '$')
    {
        maze[i][j] = value;
    }
}

bool canStepOn (int x,int y)
{
    if (x >= 0 && y >=0 && x < 10 && y < 10 && (maze[x][y] != '#')&& (maze[x][y] != '*'))
        return true;
    else
        return false;
}

bool pathFinder(int i, int j)
{
    if (i == 9 && j == 9 && takenCoins >= coins)
        return true;

    if (maze[i][j] == '$')
    {
        takenCoins++;
    }

    markAvailability(i,j,'*');

    if (canStepOn(i,j+1) && pathFinder(i,j+1))
    {
        return true;
    }
    if (canStepOn(i,j-1) && pathFinder(i,j-1))
    {
        return true;
    }
    if (canStepOn(i-1,j) && pathFinder(i-1,j))
    {
        return true;
    }
    if (canStepOn(i+1,j) && pathFinder(i+1,j))
    {
        return true;
    }
    markAvailability(i,j,'0');

    return false;
}

int main()
{
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            cin >> maze[i][j];
        }
    }

    cout << pathFinder(0,0) << endl;

    for (int i = 0 ; i < 10 ; i++)
    {
        for (int j = 0 ; j < 10 ; j++)
        {
            cout << maze[i][j];
        }
        cout << "\n";
    }
    return 0;
}

/*
0#########
0#$0000000
0#000#$000
0#0000#000
00000###00
000000$000
0000######
0000000000
0000000000
0000000000
*/
