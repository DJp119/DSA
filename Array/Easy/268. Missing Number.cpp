268. Missing Number

https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,-1);
        for(int i=0;i<nums.size();i++){
            v[nums[i]]=nums[i];
        }
        for(int i=0;i<v.size();i++) if(v[i]==-1) return i;

        return 0;
    }
};
class Solution{
    public:
    int missingNumber(vector<int>&nums){
        int n = nums.size();
        int ans = 0;
        for(int i=1;i<=n;i++)  ans = ans^i;
        for(int i=0;i<nums.size();i++) ans = ans^nums[i];
        return ans;
    }
};
class Solution{
    public:
    int missingNumber(vector<int>&nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(nums[0] != 0) return 0;
        if(nums[n-1] != n) return n;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != i) return i;
        } 
        return 0;
     }
};
