class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(); //size of the array.
            //Edge cases:
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];
         int ans = 0;
         int low = 0;
         int high = nums.size();
         while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] != nums[mid-1] && (nums[mid] != nums[mid+1])) return nums[mid];

            else if ( (mid%2==0) && (nums[mid]==nums[mid-1])  ||(mid%2 != 0)&&(nums[mid]==nums[mid+1])){
                high = mid-1;
            }
            else low = mid+1;
         }
         return ans;
    }
};

https://leetcode.com/problems/single-element-in-a-sorted-array/
