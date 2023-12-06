
#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	vector<int>sumStore;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+= arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(), sumStore.end());
    return sumStore[sumStore.size() - k];
}
TC- O(n2 log n)   SC - O(N2)

// Min Heap
  #include <queue>
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int,vector<int>,greater<int>>mini;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k) mini.push(sum);
            else{
                if(sum > mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    return  mini.top();
}
TC-O(n2) SC - O(k)
