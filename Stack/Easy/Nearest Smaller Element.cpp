vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int>ans(A.size(),-1);
    stack<int>st;
    for(int i=0;i<A.size();i++){
        int element = A[i];
        while(!st.empty() && st.top()>= element){
            st.pop();
        }
        ans[i]=st.empty() ? -1 : st.top();
        st.push(element);
    }
    return ans;
}


https://www.interviewbit.com/problems/nearest-smaller-element/
