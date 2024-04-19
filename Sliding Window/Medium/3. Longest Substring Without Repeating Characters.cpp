class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int left = 0 , right = 0;
        unordered_map<char,int>mymap;
        while(right<s.size()){
            if(mymap.find(s[right]) != mymap.end() && mymap[s[right]] >= left){
                maxlen = max(right-left,maxlen);
                left = mymap[s[right]]+1;
                // right++;
            }
                mymap[s[right]]=right;
                right++;
        }
                maxlen = max(right-left,maxlen);
        return maxlen;
    }
};


TC - O(N)
SC - O(256)

  https://leetcode.com/problems/longest-substring-without-repeating-characters/
