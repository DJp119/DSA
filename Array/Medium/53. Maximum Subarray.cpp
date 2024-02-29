class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalMaxSum = nums[0] , currMaxSum = nums[0];
        for(int ind = 1 ; ind<nums.size();ind++){
            currMaxSum = max(currMaxSum + nums[ind],nums[ind]);
            globalMaxSum = max(globalMaxSum,currMaxSum);
        }
        return globalMaxSum;
    }
}; 


class Solution {
public:
    void maxSubArray(vector<int>& nums, int l, int r, int& mx, int& lmx, int& rmx, int& sum) {
        if (l == r) {
            mx = lmx = rmx = sum = nums[l];
        }
        else {
            int m = (l + r) / 2;
            int mx1, lmx1, rmx1, sum1;
            int mx2, lmx2, rmx2, sum2;
            maxSubArray(nums, l, m, mx1, lmx1, rmx1, sum1);
            maxSubArray(nums, m + 1, r, mx2, lmx2, rmx2, sum2);
            mx = max(max(mx1, mx2), rmx1 + lmx2);
            lmx = max(lmx1, sum1 + lmx2);
            rmx = max(rmx2, sum2 + rmx1);
            sum = sum1 + sum2;
        }
    }
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int mx, lmx, rmx, sum;
        maxSubArray(nums, 0, nums.size() - 1, mx, lmx, rmx, sum);
        return mx;
    }
};
