class Solution {
    private:
    void fun(vector<vector<int>>&ans,vector<int>&temp,int index,int k ,int n){
        if(n<0 || temp.size()>k) return;
        if(n==0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<=9;i++){
            temp.push_back(i);
            fun(ans,temp,i+1,k,n-i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(ans,temp,1,k,n);
        return ans;
    }
};


https://leetcode.com/problems/combination-sum-iii/
