Using Extra Space

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> temp(nums.size(),0);
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp[k++]=nums[i];
            }
        }
        nums=temp;
    }
};

In-Place

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[k++]=nums[i];
            }
        }
        for(int i=k;i<nums.size();i++){
            nums[i]=0;
        }

In-Place using Two Pointers

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size() && j<nums.size()){
            if(nums[j]!=0){
                swap(nums[i++],nums[j++]);
            }
            else{
                j++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(auto it = nums.begin(); it != nums.end();){
            if(*it == 0){
                count++;
                nums.erase(it);
            } else {
                ++it;
            }
        }
        for(int i=0; i<count; i++){
            nums.push_back(0);
        }
    }
};


https://leetcode.com/problems/move-zeroes/
