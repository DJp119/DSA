class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long y=0 ,k=x;
        while(k!=0){
            y=y*10+k%10;
            k=k/10;
        }
        // while(x!=0 || y!=0){
        //     if(y%10 != x%10) return false;
        //     y=y/10;
        //     x=x/10;
        // }
        return (x==y);
    }
};

Time Complexity: O(logN) for reversing N digits of input integer.
Space Complexity: O(1)
https://leetcode.com/problems/palindrome-number/
