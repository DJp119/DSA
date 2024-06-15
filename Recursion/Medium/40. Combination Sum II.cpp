class Solution {
private:
    void func(vector<vector<int>>&ans,vector<int>&temp,vector<int>&candidates,int target,int index){
        // if(index == candidates.size()){
            if(target == 0) {
                ans.push_back(temp) ;
                return;
            } 
        // }
        // func(ans,temp,candidates,target,index+1);
  
        // if(candidates[index]<=target){
            for(int i= index ; i<candidates.size();i++){
                if(candidates[i]>target) break;
                if( i != index && candidates[i]==candidates[i-1]) continue;
                
                temp.push_back(candidates[i]);
                func(ans,temp,candidates,target-candidates[i],i+1);
                temp.pop_back();
            }
        // }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        func(ans,temp,candidates,target,0);
        return ans;        
    }
};


https://leetcode.com/problems/combination-sum-ii/
