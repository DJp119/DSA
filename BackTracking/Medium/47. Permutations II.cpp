class Solution {
    private:
    void fun(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i] || i>0 && nums[i]==nums[i-1] && !visited[i-1]) continue;
            visited[i]=true;
            temp.push_back(nums[i]);
            fun(nums,ans,temp,visited);
            temp.pop_back();
            visited[i]=false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>visited(nums.size(),0);
        sort(nums.begin(),nums.end());
        fun(nums,ans,temp,visited);
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
		
        vector<vector<int>> output;
        output.push_back(nums);
        while (next_permutation(begin(nums), end(nums))) {
            output.push_back(nums);
        }
        return output;
    }
};


https://leetcode.com/problems/permutations-ii/
