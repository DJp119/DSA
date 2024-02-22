/*
    Time complexity: O(2^N)
    Space complexity: O(N) 

    Where 'N' reprents the "Nth" number .
*/

#include<bits/stdc++.h>
using namespace std;

int recur(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return recur(n - 1) + recur(n - 2);
}

int main()
{
    int n;
    cin>>n;
    
    cout<<recur(n)<<endl;
}

/*
    Time complexity: O(N)
    Space complexity: O(N) 

    Where 'N' reprents the "Nth" number .
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    // declaring an 'n' size array.
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout<<dp[n]<<endl;
}

/*
    Time complexity: O(N)
    Space complexity: O(1) 

    Where 1 represents the constant and 'N' reprents the "Nth" number .
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a = 0;
    int b = 1;
    int c;
    for(int i = 0; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    cout<<a<<endl;
}


https://www.codingninjas.com/studio/problems/nth-fibonacci-number_74156?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SOLUTION
