#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    int maxnumber = INT_MIN;
    for(auto it:arr) maxnumber = max(maxnumber,it);
    return maxnumber;
}
https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?leftPanelTabValue=PROBLEM
