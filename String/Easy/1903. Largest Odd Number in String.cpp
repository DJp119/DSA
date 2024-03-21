class Solution {
public:
    string largestOddNumber(string num) {
        string ans;

        for(int i = num.size()-1 ; i>=0;i--){
            if(num[i] %2 & 1) {
                ans = num.substr(0,i+1);
                break;
            }
        }
        return ans;
    }
};


https://leetcode.com/problems/largest-odd-number-in-string/


if ((num[i] - '0') % 2 == 1)    this can be also done 
