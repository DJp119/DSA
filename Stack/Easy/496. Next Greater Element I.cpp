O(n^3)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int i=0;
        for(int i=0;i<nums1.size();i++){
            int temp = nums1[i];
            int temp2 = -1;
            for(int j = 0 ; j<nums2.size();j++){
                if(temp == nums2[j]){
                    for(int k = j+1;j<nums2.size();j++){
                        if(nums2[j]>temp) {
                            temp2 = nums2[j];break;
                        }
                    }
                }
            }
            ans.push_back(temp2);
        }
    return ans;
    }
};

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int>mystack;
            unordered_map<int,int>mymap;
            vector<int>ans(nums1.size(),-1);
            for(int i=0;i<nums2.size();i++){
                int element = nums2[i];
                while(!mystack.empty() && element > mystack.top()){
                    mymap[mystack.top()]=element;
                    mystack.pop();
                }
                mystack.push(element);
            }
            for(int i=0;i<nums1.size();i++){
                int elementchecking = nums1[i];
                if(mymap.find(elementchecking) != mymap.end()){
                    ans[i]=mymap[elementchecking];
                }
            }
        return ans;
        }
};
Time complexity: O(m+n)
Space complexity: O(n)



  https://leetcode.com/problems/next-greater-element-i/description/
  
