class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        set<int> uniqueset;
        for(int i=0;i<size;i++){
            uniqueset.insert(nums[i]);
        }
        int ans = uniqueset.size();
        int i = 0;
        for(auto x:uniqueset){
            nums[i++]=x;
        }
        return ans;
    }
};

Brute - 
  TC -> N Log N + N
  SC -> O(N)

Optimised two pointer

class Solution{
    public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i] != nums[j]) {
                nums[++i]=nums[j];
            }
        }
        return i+1;
    }
};
Time complexity: Since we only traverse the array once, the time complexity of the algorithm is O(n).
Space complexity: The algorithm uses constant extra space, so the space complexity is O(1).
