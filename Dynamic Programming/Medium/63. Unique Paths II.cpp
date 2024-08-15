class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        int up=solve(i-1,j,grid);
        int left=solve(i,j-1,grid);
        
        return up+left;
    }
    int solveMemo(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 || j<0 || grid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solveMemo(i-1,j,grid,dp);
        int left=solveMemo(i,j-1,grid,dp);
        
        return dp[i][j]=up+left;
    }
     int solveTabu(int m,int n,vector<vector<int>>&grid){
                vector<vector<int>>dp(m,vector<int>(n,0));
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(grid[i][j]==1) continue;
                 if(i==0 && j==0 ) dp[i][j]=1;
                 else{
                     int up=0,left=0;
                     if(i>0) up=dp[i-1][j];
                     if(j>0) left=dp[i][j-1];
                     
                     dp[i][j]=up+left;
                 }
             }
         }
         return dp[m-1][n-1];

    }
    int solveTabuSo(int m,int n,vector<vector<int>>&grid){
                vector<int>prev(n,0);
        
         for(int i=0;i<m;i++){
             vector<int>cur(n,0);
             for(int j=0;j<n;j++){
                 if(grid[i][j]==1) continue;
                 if(i==0 && j==0 ) cur[j]=1;
                 else{
                     int up=0,left=0;
                     if(i>0) up=prev[j];
                     if(j>0) left=cur[j-1];
                     
                    cur[j]=up+left;
                 }
             }
             prev=cur;
         }
         return prev[n-1];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // return solve(m-1,n-1,grid);
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solveMemo(m-1,n-1,grid,dp);
        // return solveTabu(m,n,grid);
        return solveTabuSo(m,n,grid);
    }
};


https://leetcode.com/problems/unique-paths-ii/description/
https://leetcode.com/problems/unique-paths-ii/solutions/2165962/c-dp-recursion-memoization-tabulation-space-optimization/
