#include <bits/stdc++.h>
bool isSafe(int newX, int newY, vector<vector<bool>> & isVisited, vector<vector<int>> & arr, int n) {
    if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && isVisited[newX][newY] == false && arr[newX][newY] != 0)
        return true;
    return false;
}
void solve(int x, int y, vector<vector<int>> & arr, int n, vector<string> & ans, vector<vector<bool>> & isVisited, string path) {
    if(x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    isVisited[x][y] = true;
    if(isSafe(x + 1, y, isVisited, arr, n))
        solve(x + 1, y, arr, n, ans, isVisited, path + 'D');
    if(isSafe(x, y - 1, isVisited, arr, n))
        solve(x, y - 1, arr, n, ans, isVisited, path + 'L');
    if(isSafe(x, y + 1, isVisited, arr, n))
        solve(x, y + 1, arr, n, ans, isVisited, path + 'R');
    if(isSafe(x - 1, y, isVisited, arr, n))
        solve(x - 1, y, arr, n, ans, isVisited, path + 'U');
    isVisited[x][y] = false;
}
vector<string> searchMaze(vector<vector<int>> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> isVisited(n, vector<bool>(n, 0));
    string path = "";
    if(arr[0][0] == 0)
        return ans;
    solve(0, 0, arr, n, ans, isVisited, path);
    return ans;
}
