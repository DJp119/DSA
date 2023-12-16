#include <bits/stdc++.h> 

bool isSafe(int row,int col,vector<vector<int>>& sudoku,int val ){
    for(int i=0;i<sudoku.size();i++){
        // row check
        if(sudoku[row][i] == val){
            return false;
        }
        // col check
        if(sudoku[i][col] == val){
            return false;
        }

        // 3*3  mat check
        if(sudoku[ 3 * (row/3) + i/3 ][3 * (col/3) + i%3] == val){
            return false;
        }
    }
    return true;
}



bool solve(vector<vector<int>>& sudoku){

    int n = sudoku[0].size();

    for(int row =0;row<n;row++){
        for(int col=0;col<n;col++){

            if( sudoku[row][col] == 0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col, sudoku,val)){
                        sudoku[row][col] = val;

                        // recursive call
                        bool  aheadSolutionPossible = solve(sudoku);
                        if(aheadSolutionPossible){
                            return true;
                        }
                        else
                        {
                            // backtrack
                            sudoku[row][col] =0;
                        }              
                    }
                }
                return false;        
            }
        }
    }
    return true;
}








void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

    solve(sudoku);
}



Naive Backtracking
The naive or brute force approach will be to try every possible configuration of numbers from 1 to 9 for each of the empty cells. After filling all the empty cells in the matrix, we check that the matrix is a valid sudoku solution or not. If we don’t find it valid, we keep checking it for the next configurations recursively until we find one.

Time Complexity
O(9^K),  Where ‘K’ is the number of empty cells in the given 2d matrix.

 

As we are trying all the numbers from 1 to 9 for every empty cell, our time complexity is exponential and quite high.

Space Complexity
O(1), i.e., constant space complexity.

 

In the worst-case scenario, our recursion stack can grow maximum till size 9*9 = 81, which is constant.
/*
    Time Complexity - O(9^K)
    Space Complexity - O(1)

    where K is the number of empty cells in the sudoku.
*/

#include <map>

// Function to check if the current sudoku array is valid or not.
bool isSudokuValid(vector<vector<int>> &sudoku)
{
    map<int, bool> row[9], col[9];
    map<int, bool> subGrid[3][3];

    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (sudoku[r][c] == 0)
            {
                continue;
            }

            // If the current value of sudoku was present in the current column, row, and subgrid previously, return false.
            if (subGrid[r / 3][c / 3][sudoku[r][c]] || col[c][sudoku[r][c]] || row[r][sudoku[r][c]])
            {
                return false;
            }

            // Mark the current value of sudoku as true in the current column, row, and subgrid.
            subGrid[r / 3][c / 3][sudoku[r][c]] = true;
            row[r][sudoku[r][c]] = true;
            col[c][sudoku[r][c]] = true;
        }
    }
    return true;
}

// Function to try all the possible ways to solve the sudoku.
bool bruteForce(vector<vector<int>> &sudoku, int i, int j)
{
    if (j == 9)
    {
        if (i == 8)
        {
            if (isSudokuValid(sudoku))
            {
                return true;
            }
            return false;
        }

        j = 0;
        i++;
    }

    if (sudoku[i][j] != 0)
    {
        return bruteForce(sudoku, i, j + 1);
    }

    // Try all the values possible.
    for (int put = 1; put <= 9; put++)
    {

        sudoku[i][j] = put;

        if (bruteForce(sudoku, i, j + 1))
        {
            return true;
        }

        sudoku[i][j] = 0;
    }
    return false;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    bruteForce(sudoku, 0, 0);
    return;
}



Optimized Backtracking
Backtracking is a general algorithm for finding all (or some) solutions to a problem that incrementally builds candidates to the solution. As soon as it determines that a candidate can not possibly be the solution to the problem, it abandons it (“backtracks”). We can solve this problem using backtracking. 

Before we assign a number in an empty cell, we will check whether it is safe to assign. We will have an ‘isSafe’ function for it, which will check that the same number is not present in the current row, current column, and in the current sub-grid.
If it is safe to assign the number, we will assign it to the empty cell and recursively check whether this assignment leads to a solution or not.
If this assignment doesn’t lead to a solution, then we will try the next number for the current empty cell. And if none of the numbers from 1 to 9 leads to a solution, we will return false.
Time Complexity
O(9^K),  Where ‘K’ is the number of empty cells in the given 2d matrix.

 

The time complexity remains the same, but there will be some early pruning, so the time taken will be much less than the naive algorithm, but the upper bound time complexity remains the same.

Space Complexity
O(1), i.e., constant space complexity.

 

In the worst-case scenario, our recursion stack can grow maximum till size 9*9 = 81, which is constant.
/*
    Time Complexity - O(9^K)
    Space Complexity - O(1)

    where K is the number of empty cells in the sudoku.
*/

// Function to check whether we can put a particular value
// to a particular position or not.
bool canPut(vector<vector<int>> &sudoku, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][col] == num || sudoku[row][i] == num)
        {
            return false;
        }
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
        {
            return false;
        }
    }

    return true;
}

// Function to check all the valid way to solve the sudoku.
bool backTrack(vector<vector<int>> &sudoku, int i, int j)
{
    if (j == 9)
    {
        if (i == 8)
        {
            return true;
        }

        j = 0;
        i++;
    }

    if (sudoku[i][j] != 0)
    {
        return backTrack(sudoku, i, j + 1);
    }

    // Trying all possible values.
    for (int put = 1; put <= 9; put++)
    {
        if (canPut(sudoku, i, j, put))
        {
            sudoku[i][j] = put;

            if (backTrack(sudoku, i, j + 1))
            {
                return true;
            }

            sudoku[i][j] = 0;
        }
    }

    return false;
}

void solveSudoku(vector<vector<int>> &sudoku)
{
    backTrack(sudoku, 0, 0);
    return;
}
