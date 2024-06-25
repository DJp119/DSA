// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>>>pq;
//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//         unordered_map<int,int>mymap;
//         for(int i=0;i<nums.size();i++){
//             mymap[nums[i]]++;
//         }
//         for(auto it:mymap){
//             pq.push({it.second,it.first});
//         }
//         vector<int>ans;
//         while(k--){
//             int top = pq.top().first;
//             pq.pop();
//             ans.push_back(top);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        vector<pair<int,int>>v;
        for(auto it : mp )
            v.push_back(make_pair(it.second,it.first));
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size() && k!=0 ;i++)
        {
            ans.push_back(v[i].second);
            k--;
        }       
        return ans; 
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        for( int it:nums){
            mpp[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

        for(auto it:mpp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
