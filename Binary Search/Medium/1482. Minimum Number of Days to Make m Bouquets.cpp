class Solution {
    private:
    bool possible(vector<int>bloomDay,int day,int m,int key){
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=day) cnt++;
            else noOfB += (cnt/key) ,cnt = 0;
        }
        noOfB  += cnt/key;
        return noOfB >= m;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = m * 1ll * k * 1ll;
        // 1ll long long int 64 bit 
        int n = bloomDay.size();
        if(val>n) return -1;
        int mini = INT_MAX, maxi = INT_MIN;
        for(auto it:bloomDay){
            mini = min(mini,it);
            maxi = max(maxi,it);
        }
        // for(int i=mini;i<=maxi;i++){
        //     if(possible(bloomDay,i,m,k)) return i;
        // }
        int low = mini , high = maxi;
        int ans =-1;
        while(low<=high){
            int mid = high + (low-high)/2;
            if(possible(bloomDay,mid,m,k)) ans = mid, high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
};

Time Complexity: O(log(max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
Reason: We are applying binary search on our answers that are in the range of [min(arr[]), max(arr[])]. For every possible answer ‘mid’, we will call the possible() function. Inside the possible() function, we are traversing the entire array, which results in O(N).

Space Complexity: O(1) as we are not using any extra space to solve this problem.


  https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
