long long sumFirstN(long long n) {
    // Write your code here.

    // //approach 1 - easiest way
    return n*(n+1)/2;

    //approach 2 - using loop - leads to TLE
    long long sum = 0;
    for(int i=0; i<=n; i++){
        sum += i;
    }
    return sum;


    // approach 3 - recursive solution - leads to TLE
    if(n==0){
        return 0;
    }
    return n + sumFirstN(n-1);

}
https://www.codingninjas.com/studio/problems/sum-of-first-n-numbers_8876068?leftPanelTabValue=PROBLEM
