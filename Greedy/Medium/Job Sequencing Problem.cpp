//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // sorting the jobs according to their profits in dec order
        sort(arr,arr+n,comp);
        int maxDeadline = 0 ;
        for(int i=0;i<n;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        // Vector to keep track of free time slots
        vector<int>slot(maxDeadline+1,-1);
        // variables to store the count of jobs and total profit
        int countJobs = 0;
        int totalProfit = 0;
        // Iterate through all jobs
        for(int i=0;i<n;i++){
            // Finding a free slot for this jobbs startiong from the last possible slot
            for(int j = arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=arr[i].id;
                    countJobs++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs,totalProfit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends


https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1
