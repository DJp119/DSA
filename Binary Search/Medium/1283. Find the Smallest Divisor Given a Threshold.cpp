class Solution {
private:
int calThre(vector<int>nums,int k){
    int temp = 0;
    for(auto it:nums){
        temp += ceil((double)(it)/(double)(k));
    }
    return temp;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n>threshold) return -1;


            int maxi = *max_element(nums.begin(), nums.end());

        // for(int i=1;i<=maxi;i++){
        //     int value = calThre(nums,i);
        //     // if sum of div is less than thre
        //     if(value<= threshold) return i;
        // }
        int low = 1, high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(calThre(nums,mid)<=threshold)  ans = mid,high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
};


https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
