https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int k)
    {   
        unordered_map<long long,int>mymap;
        int maxcount = 0;
        long long sum = 0;
        k = 0;
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(sum == k) maxcount = max(maxcount,i+1);
            long long rem = sum-k;
            if(mymap.find(rem) != mymap.end()){
                int len = i-mymap[rem];
                maxcount = max(maxcount,len);
            }
            if(mymap.find(sum)==mymap.end()){
                mymap[sum]=i;
            }
        } 
    
        return maxcount;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
