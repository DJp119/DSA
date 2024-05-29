class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>result;
            int j=0;
        for(int i=0;i<intervals.size();i++){
            if(result.empty()) result.push_back(intervals[i]);
            else{
                if(result[j][1] >= intervals[i][0]){
                    result[j][1]=max(intervals[i][1],result[j][1]);
                }
                else{
                    j++;
                    result.push_back(intervals[i]);
                }
            }
        }
        return result;
    }
};


https://leetcode.com/problems/insert-interval/
