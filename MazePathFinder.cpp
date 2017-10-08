#include <iostream>
#include <iomanip>

using namespace std;

const int mazeSize = 8;

void markVisited (int maze[mazeSize][mazeSize], int row, int col, bool visited = true)
{
	if (visited)
  		maze[row][col] = 3;
  	else
  		maze[row][col] = 0;
}

bool CanStepOn (int maze[mazeSize][mazeSize] , int row, int col)
{
    if (maze[row][col] == 5)
        return true;
    if (row > mazeSize - 2 || col > mazeSize - 2)
        return false;
    if (row < 0 || col < 0)
        return false;
    if (maze[row][col] == 3 || maze[row][col] == 1)
        return false;
    if (maze[row][col] == 0)
        return true;
}

bool PathFinder (int maze[mazeSize][mazeSize] , int row, int col)
{
    if (maze[row][col] == 5)
        return true;

    markVisited(maze,row,col,true);

    if(CanStepOn(maze,row+1,col) && PathFinder(maze, row + 1, col))
    {
        return true;
    }
    if(CanStepOn(maze,row,col+1) && PathFinder(maze, row, col + 1))
    {
        return true;
    }
    if(CanStepOn(maze,row,col-1) && PathFinder(maze, row, col - 1))
    {
        return true;
    }
    if(CanStepOn(maze,row-1,col) && PathFinder(maze, row - 1, col))
    {
        return true;
    }

    markVisited(maze,row,col,false);
    return false;
}

int main ()
{
    /**       Legend:
    0 - Available position to step on
    1 - Hedge
    2 - Starting position
    3 - Visited
    5 - Exit
    */
    int maze[mazeSize][mazeSize] = {1 , 1 , 1 , 1 , 1 , 1 , 1 , 1,
                                    1 , 2 , 1 , 0 , 0 , 0 , 1 , 1,
                                    1 , 0 , 1 , 0 , 1 , 0 , 1 , 1,
                                    1 , 0 , 1 , 0 , 1 , 0 , 1 , 1,
                                    1 , 0 , 1 , 0 , 1 , 0 , 1 , 1,
                                    1 , 0 , 1 , 0 , 1 , 0 , 1 , 1,
                                    1 , 0 , 0 , 0 , 1 , 0 , 0 , 5,
                                    1 , 1 , 1 , 1 , 1 , 1 , 1 , 1};
    //---------------------------------------------------------------
    int startRow, startCol;

    for(int row = 0 ; row < mazeSize ; row++)
    {
        for (int col = 0 ; col < mazeSize ; col++)
        {
            if (maze[row][col] == 2)
            {
                startRow = row;
                startCol = col;
                maze[row][col] = 3;
            }
        }
    }

    if(PathFinder(maze, startRow, startCol))
    {
        maze[startRow][startCol] = 2;

        for(int row = 0 ; row < mazeSize ; row++)
        {
            for (int col = 0 ; col < mazeSize ; col++)
            {
                cout << setw(3) << maze[row][col];
            }
            cout << "\n";
        }
    }
    else
        cout << "There is not a path!\n";
return 0;
}
