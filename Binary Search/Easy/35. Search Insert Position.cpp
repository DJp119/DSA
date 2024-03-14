class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
        }
        if(ans == -1) return nums.size();
        return ans;
    }
};

https://leetcode.com/problems/search-insert-position/
