// Wrong Logic
// class Solution {
// public:
//     int romanToInt(string s) {
//         unordered_map<char,int>mymap;
//         for(char ch : s) mymap[ch]++;

//         int ans=0;
//         for(auto it:mymap){
//             if(it.first == 'I' && it.first=='V') ans-=4;
//             if(it.first == 'I' && it.first=='X') ans-=9;
//             if(it.first == 'X' && it.first=='C') ans-=90;
//             if(it.first == 'C' && it.first=='D') ans-=500;
//             if(it.first == 'C' && it.first=='M') ans-=900;
//             else if(it.first == 'I') ans+= 1*it.second;
            
//             else if(it.first == 'V') ans+= 5*it.second;
//             else if(it.first == 'X') ans+= 10*it.second;
//             else if(it.first == 'L') ans+= 50*it.second;
//             else if(it.first == 'C') ans+= 100*it.second;
//             else if(it.first == 'D') ans+= 500*it.second;
//             else if(it.first == 'M') ans+= 1000*it.second;
//         }
//         return ans;
//     }

// };
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            if(i + 1 < s.length() && values[s[i]] < values[s[i + 1]]) {
                sum -= values[s[i]];
            } else {
                sum += values[s[i]];
            }
        }

        return sum;
    }
};


https://leetcode.com/problems/roman-to-integer/description/
