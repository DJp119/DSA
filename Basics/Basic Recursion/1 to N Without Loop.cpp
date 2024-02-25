vector<int>helper(vector<int>&arr,int j,int x){
    if(j>x) return arr;
    arr.push_back(j);
    return helper(arr,j+1,x);
}
vector<int>printNos(int x){
    vector<int>arr;
    int j = 1;
    return helper(arr,j,x);
}
https://www.codingninjas.com/studio/problems/print-1-to-n_628290?leftPanelTabValue=PROBLEM
