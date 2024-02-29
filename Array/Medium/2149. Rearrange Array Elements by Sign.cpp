class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> q1;
        queue<int> q2;
        for(auto it:nums){
            if(it<0) q1.push(it);
            else  q2.push(it);
        }
        nums.clear();
        while(!q1.empty() || !q2.empty()){
            if(!q2.empty()){
                int x = q2.front();
                q2.pop();
                nums.push_back(x);
            }
            if(!q1.empty()){
                int x = q1.front();
                q1.pop();
                nums.push_back(x);
            }
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        
        
        int pos=0,neg=1;
        

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos] = nums[i];
                pos+=2;
            }else{
                ans[neg] = nums[i];
                neg+=2;
            }
        }
        return ans;
    }
};

Must Read - https://leetcode.com/problems/rearrange-array-elements-by-sign/solutions/4723827/interview-approach-follow-up-question/
