https://www.geeksforgeeks.org/problems/introduction-to-dp/1

class Solution {
  private:
  int mod=1e9+7;
  long long int f(int n, vector<long long int> &dp){
      if(n<=1) return n;
      if(dp[n]!=-1) return dp[n];
      return (dp[n] = f(n-1,dp) + f(n-2,dp))%mod;
  }
  public:
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return f(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
       int pre2 = 0, pre = 1;
       for(int i=2;i<=n;i++){
           int curr = (pre + pre2)%mod;
           pre2 = pre;
           pre = curr;
       }
       return pre;
    }
};

https://www.geeksforgeeks.org/problems/introduction-to-dp/1
