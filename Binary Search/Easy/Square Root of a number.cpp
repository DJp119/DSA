int floorSqrt(long long int N)
{
    long long low = 0;
    long long high = N;
    int ans = 0;
    while(low<=high){
        long long mid = high + (low-high)/2;
        if(mid*mid == N) return mid;
        else if(mid*mid > N) high = mid-1;
        else  low = mid+1,ans = mid;
    }
    return  ans;
}


https://www.codingninjas.com/studio/problems/square-root-integral_893351?leftPanelTab=0%3Futm_source%3Dstriver&leftPanelTabValue=PROBLEM
