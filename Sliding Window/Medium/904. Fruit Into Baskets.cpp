class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j++){
                st.insert(fruits[j]);
                if(st.size()<=2) maxlen = max(maxlen,j-i+1);
                else break;
            }
        }
        return maxlen;
    }
};
Tc - O(n^2)
SC - O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    int left = 0 , right = 0 , n = fruits.size() ;
    unordered_map<int,int>mymap;
    int maxlen = 0;
    while(right<n){
        mymap[fruits[right]]++;
        if(mymap.size()>2){
            while(mymap.size()>2){
                mymap[fruits[left]]--;
                if(mymap[fruits[left]]==0) mymap.erase(fruits[left]);
                left++;
            }
        }
        else maxlen = max(maxlen,right-left + 1);
        right++;
    }
    return maxlen;
    }
};
Tc - O(n) + o(n)
SC - O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0 , right = 0 , n = fruits.size() ;
        unordered_map<int,int>mymap;
        int maxlen = 0;
        while(right<n){
            mymap[fruits[right]]++;
            if(mymap.size()>2){
                mymap[fruits[left]]--;
                if(mymap[fruits[left]]==0) mymap.erase(fruits[left]);
                left++;
            }
            else maxlen = max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};

Tc - O(n)
SC - O(1)


  https://leetcode.com/problems/fruit-into-baskets/
