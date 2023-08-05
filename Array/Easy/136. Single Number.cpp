class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1 ; i<nums.size();i+=2){
            if(nums[i] != nums[i-1]){
                return nums[i-1];
            }
        }
        return nums[nums.size()-1];
    }
};
// TC : O(NlogN)


class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   
       for(auto x:nums)
	        ans^=x;
	   
       return ans;
    }
};
// TC:O(N)
