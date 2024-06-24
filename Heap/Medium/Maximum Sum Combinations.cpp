bool rev(int &a , int &b) {
    return b<a;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
     priority_queue<int,vector<int>,greater<int>>myqueue;
     sort(A.begin(),A.end(),rev);
     sort(B.begin(),B.end(),rev);
     for(int i=0;i<C;i++) myqueue.push(A[i]+B[i]);
     for(int i=0;i<A.size();i++){
         for(int j = 0 ;j<B.size();j++){
             if(i==j) continue;
             int temp = A[i]+B[j];
             if(myqueue.top() <= temp) myqueue.pop(), myqueue.push(temp); 
             else break;
         }
     }
     vector<int>ans;
     for(int i=0;i<C;i++){
         ans.push_back(myqueue.top());
         myqueue.pop();
     }
     sort(ans.begin(),ans.end(),rev);
     return ans;
}
https://www.interviewbit.com/problems/maximum-sum-combinations/
