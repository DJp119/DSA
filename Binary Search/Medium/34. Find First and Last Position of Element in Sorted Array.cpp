class Solution {
    private:
    int lowerbound(vector<int>nums,int target){
        int low = 0 , high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(nums[mid]==target) ans = mid,high = mid-1;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
    int upperbound(vector<int>nums,int target){
        int low = 0 , high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(nums[mid]==target) ans =  mid, low = mid+1;
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerbound(nums,target),upperbound(nums,target)};
    }
};


https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
