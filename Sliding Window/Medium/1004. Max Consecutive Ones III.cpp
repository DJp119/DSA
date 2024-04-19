class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 , right = 0 , zeros = 0 , maxlen = 0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0) zeros--;
                left++; 
            }
            if(zeros<=k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};
TC-O(N)
SC - O(1)

https://leetcode.com/problems/max-consecutive-ones-iii/description/
