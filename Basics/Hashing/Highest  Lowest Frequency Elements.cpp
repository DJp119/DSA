#include <bits/stdc++.h>
using namespace std;
vector<int> getFrequencies(vector<int>& v) {
    map<int,int> hash;
    for(int num:v){
        hash[num]++;
    }
    int minFreq = INT_MAX , maxFreq = INT_MIN;
    int minNum , maxNum;
    for(auto it:hash){
        if(it.second<minFreq){
            minFreq=it.second;
            minNum = it.first;
        }
        if(it.second > maxFreq){
            maxFreq = it.second;
            maxNum=it.first;
        }
    }
    vector<int>ans;
    ans.push_back(maxNum);
    ans.push_back(minNum);
    return ans;
}
https://www.codingninjas.com/studio/problems/k-most-occurrent-numbers_625382?leftPanelTabValue=PROBLEM

