#include <bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    int left  = 0 , right = 0 , n = str.size();
    unordered_map<char,int>mymap;
    int maxlen = 0;
    while(right<n){
        mymap[str[right]]++;
        if(mymap.size()>k){
            mymap[str[left]]--;
            if(mymap[str[left]]==0) mymap.erase(str[left]);
            left++;
        }
        else maxlen = max(maxlen,right-left + 1);
        right++;
    }
    return maxlen;
}

TC - O(N)
  SC - O(1)
https://www.naukri.com/code360/problems/longest-substring-with-at-most-k-distinct-characters_2221410?leftPanelTabValue=PROBLEM
