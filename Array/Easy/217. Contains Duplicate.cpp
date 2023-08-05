// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         for(int i = 0;i<nums.size()-1;i++){
//             if(nums[i] == nums[i+1])
//                 return true;            
//         }
//         return false;
//     }
// };
// class solution{
//     public:
//     bool containDuplicate(vector<int>& nums){
//         return nums.size() > set<int>(nums.begin(),nums.end()).size();
//     }
// }
// Contains Duplicate
  class Solution {
  public:
      bool containsDuplicate(vector<int>& nums) {
          unordered_map<int,int> mp;
          for(auto i : nums) mp[i]++;
          bool flag = false;
          for(auto i : mp){
              if(i.second >= 2) return true;
          }
          return flag;
      }
  };
