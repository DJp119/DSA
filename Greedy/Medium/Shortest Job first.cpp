//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
    sort(bt.begin(),bt.end());
    long long total_waiting_time = 0;
    long long current_time = 0;
    
    for(int i=0;i<bt.size();i++){
        total_waiting_time += current_time;
        current_time += bt[i];
    }
    return total_waiting_time / bt.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends


https://www.geeksforgeeks.org/problems/shortest-job-first/1
