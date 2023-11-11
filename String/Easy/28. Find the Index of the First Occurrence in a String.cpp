class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = haystack.length();
        int length2 = needle.length();
        for(int temp1=0;temp1<length1-length2+1;temp1++){
            int temp2=0;
            while(temp2<length2){
                if(haystack[temp1+temp2]==needle[temp2]) temp2++;
                else break;
            }
            if(temp2 == length2) return temp1;
        }
        return -1;
    }
};
// TC- O(m*(n-m+1))
