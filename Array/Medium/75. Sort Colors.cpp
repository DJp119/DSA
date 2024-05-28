class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x1 = 0 ;
        int x2 = 0 ; 
        int x3 = 0 ;
        for(int i = 0 ; i<nums.size();i++){
            if(nums[i]==0) x1++;
            if(nums[i]==1) x2++;
            if(nums[i]==2) x3++;
        }
        nums.clear();
        int i = 0;

            while(x1>0){
                nums.push_back(0);
                x1--;
            }
            while(x2>0){
                nums.push_back(1);
                x2--;
            }
            while(x3>0){
                nums.push_back(2);
                x3--;
            }
    }
};
class Solution{
    public:
    void sortColors(vector<int>& nums){
        int low = 0 ; 
        int mid = 0 ;
        int high = nums.size()-1;

        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0 , right = nums.size()-1,middle = nums.size()-1;
        while(left<=middle){
            if(nums[middle]==0) {
                swap(nums[middle],nums[left]);
                left++;
                // middle++;
            }
            else if(nums[middle]==2){
                swap(nums[middle],nums[right]);
                right--;
                middle--;
            }
            else middle--;
        }
    }
};
