class Solution {
public:
    string reverseWords(string s) {
        string ans ;
        stack<string>mystack;
        string str;
        for(int i = 0 ; i<s.size();i++){
            if(s[i]==' ' && !str.empty()){
                mystack.push(str);
                str.clear();
            }  
            else if(s[i]!=' ') str+=s[i];
        }
        if(!str.empty()) mystack.push(str);
        while(!mystack.empty()){
            ans+=mystack.top();
            mystack.pop();
            if(!mystack.empty()) ans+=' ';
        }
        return ans;
    }
};

https://leetcode.com/problems/reverse-words-in-a-string/
