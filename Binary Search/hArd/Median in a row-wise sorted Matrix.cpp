//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
    int upperBound(vector<int> &arr, int x, int n) {
        int low = 0, high = n - 1;
        int ans = n;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] > x) {
                ans = mid;
                //look for smaller index on the left
                high = mid - 1;
            }
            else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt += upperBound(matrix[i], x, n);
        }
        return cnt;
    }
    
public:
    int median(vector<vector<int>> &matrix, int R, int C){
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < R; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }

    int req = (R * C) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, R, C, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;    
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends




    int median(vector<vector<int>> &matrix, int R, int C){
       int lo = 1, hi = 2001;
       while(lo <= hi) {
           int mid = lo + (hi - lo) / 2;
           int cnt = 0;
           
           for(int i = 0; i < R; i++) {
               cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
           }
           
           if(cnt <= (R*C-1) / 2) lo = mid + 1;
           else hi = mid - 1;
       }
       
       return lo;
    }



class Solution{   
public:
    int solve(vector<int>A,int index)
    {   
        int count=0;
        
        count+=(upper_bound(A.begin(),A.end(),index)-A.begin());
    
        return count;
        
    }
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here  
        int high=2000;
        int low=1;
        int median=(r*c)/2;
        while(low<=high)
        {
            int cnt=0;
            int mid=(high+low)/2;
            for(int i=0;i<r;i++)
            {
                cnt+=solve(matrix[i],mid);
            }
            if(cnt<=median)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
};
