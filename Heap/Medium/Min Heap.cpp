#include <bits/stdc++.h> 
void insert(vector<int>&heap,int el){
    heap.push_back(el);
    int ci = heap.size()-1;
    while(ci > 1){
        int pi = ci/2;
        if(heap[ci]< heap[pi]){
            swap(heap[ci],heap[pi]);
        }
        else break;

        ci = pi;
    }
}
int remove(vector<int>&heap){
    if(heap.size() == 1) return -1;

    int el = heap[1];
    swap(heap[1],heap[heap.size()-1]);
    heap.pop_back();
    int pi = 1;
    int n = heap.size();
    int minind;

    while(pi<n){
        int ici = 2*pi;
        int rci = 2*pi+1;
        minind = pi;

        if(ici < n && heap[ici] < heap[minind]) minind = ici;
        if(rci < n && heap[rci] < heap[minind]) minind = rci;
        if(minind == pi) break;
        swap(heap[pi],heap[minind]);
        pi = minind;
    }
    return el;
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int>ans;
    vector<int>heap;
    heap.push_back(-1);

    for(int i=0;i<q.size();i++){
        if(q[i][0]==0) insert(heap,q[i][1]);
        else ans.push_back(remove(heap));
    }
    return ans;
}


https://www.naukri.com/code360/problems/min-heap_4691801
