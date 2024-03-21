class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        priority_queue<pair<int,char>>maxheap;
        for(char c:s) freq[c]++;
        for(auto it:freq) maxheap.push({it.second,it.first});

        s="";
        while(!maxheap.empty()){
            s+=string(maxheap.top().first,maxheap.top().second);
            s+=string(maxheap.top().first,maxheap.top().second);
            maxheap.pop();
        }
        return s;
    }
};



class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        multimap<int,char> r;
        string ss="";

        for(auto a : s)
            mp[a]++;

        for(auto a : mp)
            r.insert({a.second, a.first});

        for(auto it = r.rbegin(); it != r.rend(); ++it)
            ss += string(it->first, it->second);

        return ss;
    }
};


class Solution {
public:
    string frequencySort(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        
        unordered_map<char, int> hm;
        
        for (char c : s) {
            hm[c]++;
        }
        
        for (const auto& entry : hm) {
            pq.push(make_pair(entry.first, entry.second));
        }
        
        string result = "";
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }
        
        return result;
    }
};

https://leetcode.com/problems/sort-characters-by-frequency/description/

