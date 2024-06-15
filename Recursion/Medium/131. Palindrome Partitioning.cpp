class Solution {
private:
    bool checkPalindrome(string str,int startIndex,int lastIndex){
        while(startIndex <= lastIndex){
            if(str[startIndex] != str[lastIndex]) return false;
            startIndex++;
            lastIndex--;
        }
        return true;
    }
    void plaindromeParition(int index,vector<string>&temp,vector<vector<string>>&ans,string str){
        if(index == str.length()) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<str.length();i++){
            if(checkPalindrome(str,index,i)){
                temp.push_back(str.substr(index,i-index+1));
                plaindromeParition(i+1,temp,ans,str);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        plaindromeParition(0,temp,ans,s);
        return ans;
   }
};


https://leetcode.com/problems/palindrome-partitioning/
