// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         for(int i = 0 ; i<nums.size();i++){
//             for(int j= i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };


class Solution{
    public:
    vector<int> twoSum(vector<int> &nums,int target){
        unordered_map<int,int> mp;

        for(int i = 0 ; i < nums.size();i++){
            if(mp.find(target-nums[i]) == mp.end() )     mp[nums[i]] = i;
            
            else return{mp[target-nums[i]],i};
        }
        return {-1,-1};
    }
};

// TC - O(N)   , SC - O(N) 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mymap;
        for(int i=0;i<nums.size();i++){
            int com = target-nums[i];
            if(mymap.count(com)) return {mymap[com],i};
            
            mymap[nums[i]]=i;
        }
    return {};
    }
};
