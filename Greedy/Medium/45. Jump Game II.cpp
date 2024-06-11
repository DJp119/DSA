class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0;
        int left = 0, right = 0;
        int jumps = 0;
        while(last < nums.size()-1) {
            jumps++;
            for(int i=left;i<=right;i++) {
                last = max(last, i+nums[i]);
            }
            left = right+1;
            right = last;
        }
        return jumps;
    }
};

https://leetcode.com/problems/jump-game-ii/
