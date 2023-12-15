/*

    Time Complexity : O(N!)
    Space Complexity : O(N*N)
    
    Where N is the number of Queens.

*/
#include <bits/stdc++.h> 

void adding(vector<vector<int> > &ans,vector<vector<int> > &board,int n)
{
	vector<int> temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int> > &board,int n ){
	int x = row;
	int y = col;
	// chech for same row
	while(y>=0){
		if(board[x][y] ==1 )
			return false;
		y--;
	}


	 x = row;
	 y = col;
	// chech for upper left diagonal
	while(y>=0 && x>=0){
		if(board[x][y] ==1 )
			return false;
		y--;
		x--;
	}

	 x = row;
	 y = col;
	// chech for lower left diagonal
	while(x<n && y>=0){
		if(board[x][y] ==1 )
			return false;
		y--;
		x++;
	}

	return true;
}
void solve(int col,vector<vector<int> > &ans,vector<vector<int> > &board,int n){

	// all columns are filled
	if( col == n)
	{
		adding(ans,board,n);
		return;
	}

	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			// if placing queen is safe
			board[row][col] = 1;
			solve(col+1,ans,board,n);
			// backtracking
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int> > board(n,vector<int>(n,0));
	vector<vector<int> > ans;

	solve(0,ans,board,n);

	return ans;
	
}

The idea is to place queens one by one in different columns, starting from the leftmost column. When we place a queen in a column, we check if it’s safe to place the queen here, by checking for clashes with already placed queens. In the current column, if we find a row for which there is no clash, we mark this row and column as part of the solution. If we do not find such a row due to clashes then we backtrack.

Note: There could be the only one queen in a row and the only one queen in a column.
 

Algorithm: 

Create an output array that stores all the possible configurations of N - queen puzzle. 

Suppose we place the queens column-wise, and we start with the very first column.
If all the queens are placed, we have found a valid solution. Add it to the output array.
Iterate over all the rows in the current column:
Check if the queen can be placed safely in this square(row, column) or not. If yes, then recursively check if placing the queen here leads to a solution.
If placing the queen in the square(row, column) leads to a solution, then add the solution to the output array.
Unmark this square(row, column), i.e. remove the queen from this square and backtrack to check other rows.
If all rows have been tried and nothing worked, simply return from the function.
 
Checking if placing queen at square[row, col] is valid/safe:

For checking if no queen is present in row and column:
Iteratively check if there is a queen in any of the previous columns, i.e. (0, col - 1) for the current row ‘row’. If yes, this arrangement is not valid, return false.
For checking if no queen is present along the diagonals:
Iteratively check if there is a queen in the upper left diagonal and lower left diagonal. If yes, this arrangement is not valid, return false.
If reached here, return true as placement is safe.
 

At last, we will return the output array containing all the configurations in which we can successfully place the N queens.

Time Complexity
O(N!), where ‘N’ is the number of queens and ‘!’ represents factorial.

There are N possibilities to put the first queen, not more than N * (N - 2) to put the second one, not more than N* (N - 2) * (N - 4) for the third one, and so on. Also, checking if placing a queen at a particular cell is safe or not requires O(N * N) time. Thus, the final complexity is O(N!).

Space Complexity
O(N * N), where ‘N’ is the number of queens. 

Since we are using a 2-D array to store all the configuration in which we can successfully place the N queens. Thus, the space complexity is O(N * N).
