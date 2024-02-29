// Brute
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                int itr = 0;
                for(int j = i;j<nums.size();j++){
                    if(nums[j]==1) itr++;
                    count = max(count,itr);
                    if(nums[j]==0) break;
                }
            }
        }
        return count;
    }
};
// optimised
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 , maxi = 0;
        int size = nums.size();
        for(int i = 0 ; i<size;i++){
            if(nums[i]==1){
                count++;
                maxi = max(maxi,count);
            }
            else count = 0;
        }
        return maxi;
    }
};

https://leetcode.com/problems/max-consecutive-ones/description/
