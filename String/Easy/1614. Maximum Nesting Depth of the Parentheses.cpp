class Solution {
public:
    int maxDepth(string s) {
        int  maxi = 0;
        int cnt=0;
        for(int i = 0 ;i<s.size();i++){
            if(s[i]=='(') cnt++ ,maxi=max(maxi,cnt);
            else if(s[i]==')') cnt--;
        }
        return maxi;
    }
};

https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
