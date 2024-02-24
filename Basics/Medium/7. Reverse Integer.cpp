class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while(x != 0){
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if(result > INT_MAX || result < INT_MIN) return 0;
        return result;
    }
};

Time Complexity: O(n), where n is the length of the given number
Space Complexity: O(1)
  
https://leetcode.com/problems/reverse-integer/
