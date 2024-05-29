class Solution {
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
    map<int, int> mystack;
    for (int i = 0; i < intervals.size(); i++) {
        if (mystack.empty()) {
            mystack.insert({intervals[i][0], intervals[i][1]});
        } else {
            int min2 = intervals[i][0];
            int max2 = intervals[i][1];
            if (min2 <= mystack.rbegin()->second) {
                int min1 = mystack.rbegin()->first;
                int max1 = mystack.rbegin()->second;
                mystack.erase(min1);
                mystack.insert({min1, max(max1, max2)});
            } else {
                mystack.insert({min2, max2});
            }
        }
    }

    vector<vector<int>> ans;
    for (const auto& entry : mystack) {
        ans.push_back({entry.first, entry.second});
    }
    return ans;
}

};





//Comment and Upvote

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>> result;
        //base case when threr are no intervals
        if(interval.size()==0)return result;
        //sort takes O(nlogn) time
        sort(interval.begin(),interval.end());
        //insert the the the first interval in the result
        result.push_back(interval[0]);
        int j=0;
        //Traverse the whole vector .Takes O(n) time
        for(int i=1;i<interval.size();i++)
        {
            //if intevals are overlapping
            if(result[j][1]>=interval[i][0]) result[j][1]=max(result[j][1],interval[i][1]);
            //else they are not overlapping
            else
            {
                j++;
                result.push_back(interval[i]);
            }
        }
        return result;
    }
};




//Comment and Upvote

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //base case
        if(intervals.size()<=1) return intervals;
        //resultan vector
        vector<vector<int>> result;
        //sort takes O(nlogn) time
        sort(intervals.begin(), intervals.end()); 
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
         //Traverse the whole vector .Takes O(n) time
        for(int i=1; i<intervals.size(); i++) {
             //if intevals are overlapping
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1] , intervals[i][1]);
            //else they are not overlapping
            else result.push_back(intervals[i]); 
        }
        return result;
    }
};



https://leetcode.com/problems/merge-intervals/description/
