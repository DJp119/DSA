class Solution {
    int helper(vector<int>&nums,int st,int end){
        int p1 = 0 , p2 = 0 , p3 =0;
        for(int i=st;i<end;i++){
            p3 = max(nums[i]+p2,p1);
            p2 = p1;
            p1 = p3;
        }
        return p3;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,0,n-1),helper(nums,1,n));
    }
};


https://leetcode.com/problems/house-robber-ii/submissions/1353434639/
