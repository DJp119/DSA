#include <bits/stdc++.h>
void rev(string &str,int i,int j,bool &ans){
    if(i>j) return;
    if(str[i]!=str[j]){
        ans = false;
    }
    rev(str, ++i, --j, ans);
}
bool isPalindrome(string& str) {
    bool ans = true;
    rev(str,0,str.size()-1,ans);
    return ans;
}
https://www.codingninjas.com/studio/problems/check-palindrome-recursive_624386?leftPanelTabValue=PROBLEM
