class Solution {
private:
    void func(vector<int>& candidates,vector<vector<int>>&ans,vector<int>&temp,int index,int sum){
        if(index == candidates.size()){
            if(sum == 0) ans.push_back(temp);
            return;
        }
        func(candidates,ans,temp,index+1,sum);
        
        if(candidates[index] <= sum){
            temp.push_back(candidates[index]);
            func(candidates,ans,temp,index,sum-candidates[index]);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum = target ;
        func(candidates,ans,temp,0,sum);
        return ans;
    }
};

https://leetcode.com/problems/combination-sum/
