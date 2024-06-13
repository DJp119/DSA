class Solution {
    static bool comp(vector<int>intervalsA , vector<int>intervalsB){
        return intervalsA[1]<intervalsB[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int n = intervals.size();
        int cnt = 1;
        int lastendTime=intervals[0][1];

        for(int i=1;i<n;i++){
            if(intervals[i][0]>=lastendTime) cnt++, lastendTime = intervals[i][1];
        }
        return n-cnt;
    }
};

https://leetcode.com/problems/non-overlapping-intervals/
