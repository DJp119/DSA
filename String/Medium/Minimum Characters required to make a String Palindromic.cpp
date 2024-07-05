int Solution::solve(string A) {
    bool c = false;
    int count = 0;
    int maxi = 0;
    int i=0;
    int j = A.size()-1;
    
    while(i<j){
        if(A[i]==A[j]) i++,j--;
        else{
            if(c==false) count++;
            else{
                i=0;
                count = A.size()-j;
            }
            j--;
        }
        maxi = max(maxi,count);
        if(j<A.size()-1){
            if(A[j] != A[j+1]) c=true;
        }
    }
    return count;
}




https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/
