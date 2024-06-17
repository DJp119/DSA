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
Time Complexity : O(N!), In worst case when all element of Array(nums) will different then there will be N!
    permutations and N! function calls. Where N is the size of the array(nums) and ! stands for factorial. 

    Space Complexity: O(N!*N), In worst case when all element of Array(nums) will different, since we have to
    store all the possible solutions which are N! in size where N is the size of the array and ! stands for
    factorial.

    Solved using Array + BackTracking. 
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


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> output;
        sort(begin(nums), end(nums));
        generatePermutations(nums, output, 0);
        return output;
    }
private:
    void generatePermutations(vector<int> nums, vector<vector<int>>& output, int idx) {
        if (idx == size(nums)) {
            output.emplace_back(nums);
        }
        for (int i = idx; i < size(nums); ++i) {
            if (i != idx && nums[i] == nums[idx]) continue;
            swap(nums[i], nums[idx]);
            generatePermutations(nums, output, idx + 1);
        }
    }
};

https://leetcode.com/problems/permutations-ii/
