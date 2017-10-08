#include <iostream>
#include <iomanip>
#include <stdlib.h>


#define N 7

int table[N][N] = {0};

const int row_move[8] = { 1, 1, -1, -1, 2, -2, 2, -2 };
const int col_move[8] = { 2, -2, 2, -2, 1, 1, -1, -1 };


bool is_traveled(size_t visited)
{
    return (visited >= N * N);
}

void print_table()
{
    for (int i = 0 ; i < N ; i++, std::cout << "\n"){
        for (int j = 0 ; j < N ; j++){
            std::cout << std::setw(3) << table[i][j];
        }
    }
//    std :: cout << std:: endl; // print all solutions

    exit(0);                    // print single solution
}

bool canStepOn(int row, int col)
{
    if (table[row][col] != 0 || col < 0 || row < 0 || row >= N || col >= N )
        return false;
    else
        return true;
}

void horseWalk(int row, int col, int &visited)
{
    visited++;
    table[row][col] = visited;

    if(is_traveled(visited)){
        print_table();
    }

    for (int i = 0 ; i < 8 ; i++){
        if (canStepOn(row + row_move[i], col + col_move[i])){
            horseWalk(row + row_move[i], col + col_move[i], visited);
        }
    }
    table[row][col] = 0;
    visited--;
}

int main()
{
    int visited = 0;

    horseWalk(N - 1,0,visited);

    return 0;
}
