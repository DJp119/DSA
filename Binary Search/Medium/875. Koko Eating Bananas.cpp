875. Koko Eating Bananas




#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {
    int maxi = INT_MIN;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {
    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {
        int reqTime = calculateTotalHours(v, i);
        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}



Optimise
class Solution {
    private:
    int calmax(vector<int>piles){
        int maxi = INT_MIN;
        for(auto it:piles){
            maxi = max(maxi,it);
        }
        return maxi;
    }
    int calhour(vector<int>piles,int value){
        int hr = 0;
        for(auto it:piles){
            hr += ceil((double)(it)/(double)(value));
        }
        return hr;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // calculate maxi value from the array
        int maxi = calmax(piles);
        int low = 1; 
        int high = maxi;
        int ans = -1;
        while(low<=high){
            int mid = high + (low-high)/2;
            int numberofhour = calhour(piles,mid);
            if(numberofhour <= h) ans = mid,high = mid-1;
            else low = mid+1;
        }
        return ans;
        // for(int i = 1 ; i<=maxi;i++){
        //     int numberofhour = calhour(piles,i);
        //     if(numberofhour <= h) return i;
        // }
        // return maxi;
    }
};

Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.
Reason: We are applying Binary search for the range [1, max(a[])], and for every value of ‘mid’, we are traversing the entire array inside the function named calculateTotalHours().




https://leetcode.com/problems/koko-eating-bananas/
