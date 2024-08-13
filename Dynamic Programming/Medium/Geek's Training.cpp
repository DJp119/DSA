1. Recursive Approach : [O(2^n) & O(n)] (TLE ❌)

class Solution {
  public:
    int helper(int day, int last, vector<vector<int>>& points){
        if(day == 0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i != last){
                    maxi = max(maxi, points[0][i]);
                }
            }
            return maxi;
        }
        
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                int activity = points[day][i] + helper(day-1, i, points);
                maxi = max(maxi, activity);
            }
        }
        return maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        return helper(n-1, 3, points);
    }
};

 

2. DP - Memoization : [O(n) & O(n)]

class Solution {
  public:
    int helper(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
        
        if(dp[day][last] != -1) return dp[day][last];
        
        if(day == 0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i != last){
                    maxi = max(maxi, points[0][i]);
                }
            }
            return dp[day][last] = maxi;
        }
        
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i != last){
                int activity = points[day][i] + helper(day-1, i, points, dp);
                maxi = max(maxi, activity);
            }
        }
        return dp[day][last] = maxi;
    }
    
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return helper(n-1, 3, points, dp);
    }
};

 

3. DP - Tabulation : [O(n) & O(n)]

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (4, 0));
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                dp[day][last] = 0;
                for(int task=0;task<=2;task++){
                    if(task != last){
                        int activity = points[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n-1][3];
    }
};

 

4. Optimized - Iterative : [O(n) & O(1)]

class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<int>prev(4, 0);
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][0], points[0][1]);
        prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
        
        for(int day=1;day<n;day++){
            vector<int>temp(4, 0);
            for(int last=0;last<4;last++){
                temp[last] = 0;
                for(int task=0;task<=2;task++){
                    if(task != last){
                        temp[last] = max(temp[last], points[day][task]+prev[task]);
                    }
                }
            }
            prev = temp;
        }
        return prev[3];
    }
};







int maximumPoints(vector<vector<int>>& v, int n) {
        vector<int> dp = v[0];
        for(int i= 1;i<n;i++){
            vector<int> curr = v[i];
            curr[0]+=max(dp[1], dp[2]);
            curr[1]+= max(dp[0] , dp[2]);
            curr[2]+= max(dp[0] , dp[1]);
            dp = curr;   
        }
        return max(dp[0] , max(dp[1] , dp[2]));
}

https://www.geeksforgeeks.org/problems/geeks-training/1
