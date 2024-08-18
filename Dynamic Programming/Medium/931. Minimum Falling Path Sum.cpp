class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftdiag = matrix[i][j];
                if(j-1>=0) leftdiag += dp[i-1][j-1];
                else leftdiag += 1e9;
                int rightdiag = matrix[i][j];
                if(j+1 <n) rightdiag += dp[i-1][j+1];
                else rightdiag += 1e9;
                dp[i][j]=min(up,min(leftdiag,rightdiag)); 
            }
        }
        int maxi = INT_MAX;
        for(int j=0;j<n;j++) maxi =min(maxi,dp[n-1][j]);
        return maxi;
    }
};

https://leetcode.com/problems/minimum-falling-path-sum/
