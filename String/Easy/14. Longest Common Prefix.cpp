class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        string ans;
        sort(strs.begin(),strs.end());
        string str1 = strs[0];
        string str2 = strs[size-1];
        for(int i=0;i<str1.size();i++){
            if(str1[i]==str2[i]) ans+=str1[i];
            else break;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans ;
        sort(strs.begin(),strs.end());
        for(int i = 0 ; i<strs.size();i++){
            cout<<strs[i];
        }
        int start = 0;
        int end = strs.size()-1;

        string start_string = strs[start];
        string end_string = strs[end];
        for(int i = 0 ; i<end_string.size();i++){
            if(start_string[i]==end_string[i]) ans+=start_string[i];
            else break;
        }
        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (string s : strs)
            while (s.find(prefix) != 0)
                prefix = prefix.substr(0, prefix.length() - 1);
        return prefix;

    }
};

https://leetcode.com/problems/longest-common-prefix/
