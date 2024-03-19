class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' && count == 0) count++;
            else if(s[i]=='(' && count >=1) count++,ans+=s[i];
            else if(s[i]==')' && count >1) count--,ans+=s[i];
            else if(s[i]==')' && count == 1) count--;
        }
        return ans;
    }
};

https://leetcode.com/problems/remove-outermost-parentheses/
