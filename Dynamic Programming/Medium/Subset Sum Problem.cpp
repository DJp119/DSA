Memo 
class Solution{   
    private:
    bool helper(int n , vector<int>arr,vector<vector<int>>&dp,int sum){
        if(sum == 0) return true;
        if(n == 0 ) return arr[0]==sum;
        if(dp[n][sum] != -1) return dp[n][sum];
        bool notake = helper(n-1,arr,dp,sum);
        bool take = false;
        if(arr[n] <= sum){
            take = helper(n-1,arr,dp,sum-arr[n]);
        }
        return dp[n][sum]= notake || take;
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return helper(arr.size()-1,arr,dp,sum);
    }
};

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,false));
        int n = arr.size();
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int index = 1;index<n;index++){
            for(int target = 1;target <= sum;target++){
                bool notaken = dp[index-1][target];
                bool taken = false;
                if(arr[index] <= target) taken  = dp[index-1][target-arr[index]];
                
                dp[index][target] = notaken || taken;
            }
        }
        return dp[n-1][sum];
    }
};

https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
