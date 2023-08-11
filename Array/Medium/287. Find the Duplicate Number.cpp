class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // start hopping from Node_#0
        int slow=0, fast=0;
            
        int check = 0;
            
        // Step_#1
        // Cycle detection
        // Implement Tortoise and Hare algorithm
        while( true ){
            slow = nums[slow];
            fast = nums[ nums[fast] ];
            
            if( slow == fast ){
                break;
            }
        }
        
        
        // Step_#2
        // Locate the start node of cycle (i.e., the duplicate number)
        while( true ){
            slow = nums[slow];
            check = nums[check];
            
            if( slow == check ){
                break;
            }
        }
        
        return check;
    }
};
//   
//  CPP solution for the binary search 
class Solution{
    public:
    int findDuplicate(vector<int> &nums){
        int n = nums.size()-1;
        int low = 1;
        int high = n ;
        int mid;
        while(low<high){
            mid = (low+high)/2;
            int count = 0 ;
            for(int num:nums){
                if(num<=mid) count++;
            }
            if(count>mid) high=mid;
            else low = mid+1;
        }
        return low;
    }
};
//  Java solution for the binary Search 
    public static int findDuplicate_bs(int[] nums) {
        int len = nums.length;
        int low = 1;
        int high = len - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }

            if (cnt <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
