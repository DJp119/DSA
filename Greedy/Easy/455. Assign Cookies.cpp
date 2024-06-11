class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int left= 0 , right = 0 ;
        int n = g.size(), m = s.size();
        // m is the size of the cookies 
        while(left<n && right < m){
            if(g[left]<=s[right]) left++;
            right++;
        } 
        return left;
    }
};

https://leetcode.com/problems/assign-cookies/
