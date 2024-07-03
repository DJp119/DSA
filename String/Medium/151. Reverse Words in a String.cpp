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


class Solution {
public:
    string reverseWords(string s) {
     string ans ="";
     string temp="";
     int left = 0 ;
     int right = s.size()-1;
     while(s[left] == ' ') left++;    
     while(s[right] == ' ') right--;

     while(left<=right){
        if(s[left] != ' ') temp+=s[left];
        else{
            if(s[left-1] ==' ') {
                left++;
                continue;
            } 
            else ans = temp + " " + ans, temp ="";
        }
        left++;
     }    
     ans = temp + " "+ ans;
     ans.resize(ans.length()-1);
     return ans;
    }
};

