119. Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long temp = 1;
        rowIndex+=1;
        vector<int>ans;
        ans.push_back(temp);
        for(int i=1;i<rowIndex;i++){
            temp = temp*(rowIndex-i);
            temp = temp/i;
            ans.push_back(temp);
        }
        return ans;
    }
};
