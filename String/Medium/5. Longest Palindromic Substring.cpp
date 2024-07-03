class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans=s.substr(0,1);
        string temp;
        if(n<=1) return s;

        for(int i =0;i<s.size();i++){
            int left = i;
            int right = i;

            while(left >=  0 && right<n and s[left]==s[right] )  {
                temp = s.substr(left,right - left + 1);
                left--;
                right++;
            }
            if(temp.size()>ans.size()) ans = temp,temp="";
            // even
            left = i;
            right = i+1;
            while(left>=0  && right < n and s[left]==s[right]){
                temp = s.substr(left,right - left + 1);
                left--;
                right++;
            }
            if(temp.size()>ans.size()) ans = temp,temp="";
        }

    return ans;
    }
};
