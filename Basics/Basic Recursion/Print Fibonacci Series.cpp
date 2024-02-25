int rev(vector<int>&ans,int n){
    if(ans[n-1]!=-1) return ans[n-1];
    return ans[n-1]=rev(ans, n-1)+rev(ans,n-2);
}
vector<int> generateFibonacciNumbers(int n) {
    vector<int>ans(n,-1) ;
    ans[0]=0;
    ans[1]=1;

    rev(ans,n);
    return ans;
}

https://www.codingninjas.com/studio/problems/print-fibonacci-series_7421617?leftPanelTabValue=SOLUTION
