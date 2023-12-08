#include <limits.h>
#include <queue>
class node{
    public:
    int data;
    int row;
    int col;
    node(int d,int r,int c){
        data = d;
        row=r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node,vector<node*>,compare>minHeap;
    // S-1 Create a min Heap for starting element of each list and tracking mini/maxi limits
    for(int i=0;i<k;i++){
        int element = a[i][0];
        mini = min(mini,element);
        maxi = max(maxi,element);
        minHeap.push(new node(element,i,0));
    }
    int start = mini,end=maxi;
    // process ranges 
    while(!minHeap.empty()){
        // mini fetch
        node* temp =minHeap.top();
        minHeap.pop();
        mini = temp->data;
        // range or answer updation
        if(maxi-mini<end-start){
            start=mini;
            end = maxi;
        }
        // next element exists
        if(temp->col+1<n) {
            maxi=max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            // next element does not exists
            break;
        }
    }
    // return the difference
    return end-start+1;
}



	Time Complexity: O(N*K*log(K))
	Space complexity: O(K)

/*
	Time Complexity: O(N*K*log(K))
	Space complexity: O(K)

	Where ‘N’ is the number of elements present in each list and ‘K’ is the number of lists.

*/

#include <limits.h>

#include <queue>
int kSorted(vector<vector<int>> &a, int k, int n) {
    int maxx = INT_MIN, minn = INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Insert the first element of each list in Min heap
    for (int i = 0; i < k; i++) {
        pq.push({a[i][0], {i, 0}});
        maxx = max(maxx, a[i][0]);
        minn = min(minn, a[i][0]);
    }

    // Initialize the answer using current min and max
    int ans = maxx - minn + 1;
    while (true) {
        // Remove the minimum element from Min heap
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int row = p.second.first;
        int col = p.second.second;
        minn = p.first;
        // Calculate new length of the range
        int len = maxx - minn + 1;
        // Update the answer with new range
        ans = min(ans, len);
        // Update the column number of new element to be inserted
        col++;
        // If this list is exhausted then we can not further improve our answer so will break the loop
        if (col == n) {
            break;
        }
        // Insert new element in Min heap
        pq.push({a[row][col], {row, col}});
        // Also update the maximum element
        maxx = max(maxx, a[row][col]);
    }

    return ans;
}
