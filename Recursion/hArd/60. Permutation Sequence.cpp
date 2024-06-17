class Solution {
public:
    string getPermutation(int n, int k) {
        string temp = "";
        for(int i=1; i<=n; i++){
            temp += to_string(i); // Convert int to string
        }
        for(int i=1; i<k; i++){
            next_permutation(temp.begin(), temp.end());
        }
        return temp; // temp now holds the k-th permutation
    }
};
class Solution{
    public:
        string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums;
        for(int i=1;i<n;i++){
            fact = fact * i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k = k-1;
        string ans="";
        while(true){
            ans = ans+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k = k%fact;
            fact = fact / nums.size();
        }
        return ans;
        }
};
