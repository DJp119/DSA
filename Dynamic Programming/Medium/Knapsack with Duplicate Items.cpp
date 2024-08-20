class Solution{
    int t[1001][1001];
    int helper(int N,int W,int val[],int wt[]){
        if(N==0 || W == 0) return 0;
        if(t[N][W] != -1) return t[N][W];
        
        if(wt[N-1]<=W) 
            return t[N][W]=max(val[N-1]+helper(N,W-wt[N-1],val,wt),helper(N-1,W,val,wt));
        
        else return t[N][W]=helper(N-1,W,val,wt);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        memset(t,-1,sizeof(t));
        return helper(N,W,val,wt);
    }
};


class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int t[N+1][W+1];
        for(int i=0;i<=N;i++) t[i][0]=0;
        for(int j=0;j<=W;j++) t[0][j]=0;
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                if(wt[i-1] <= j) t[i][j] = max(val[i-1]+t[i][j-wt[i-1]], t[i-1][j]);    
                else t[i][j]=t[i-1][j];
            }
        }
    return t[N][W];
    }
};


https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
