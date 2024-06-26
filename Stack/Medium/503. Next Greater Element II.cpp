// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         stack<int>st;
//         unordered_map<int,int>mymap;
//         int n = nums.size();

//         for(int i=0;i<2* nums.size();i++){
//             int element = nums[i%n];
//             while(!st.empty()  && st.top() < element){
//                 mymap[st.top()] = element;
//                 st.pop();
//             }
//             st.push(element);
//         }
//         vector<int>ans(n,-1);
//         for(int i=0;i<nums.size();i++){
//             int l = nums[i];
//             if(mymap.find(l) != mymap.end()){
//                 ans[i]= mymap[l];
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n, -1); // Initialize result array with -1
//         stack<int> st; // Stack to store indices of elements
//         unordered_map<int, int> nextGreater; // Hashmap to store next greater elements

//         // Duplicate the array to handle circularity
//         for (int i = 0; i < n * 2; ++i) {
//             int currNum = nums[i % n]; // Get the actual element from nums
//             while (!st.empty() && nums[st.top()] < currNum) {
//                 nextGreater[st.top()] = currNum; // Update next greater element
//                 st.pop();
//             }
//             if (i < n) // Only push indices from the first n elements
//                 st.push(i);
//         }

//         // Fill in the result array using the hashmap
//         for (int i = 0; i < n; ++i) {
//             if (nextGreater.count(i)) // Check if next greater exists
//                 ans[i] = nextGreater[i];
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Initialize result array with -1
        stack<int> st; // Stack to store indices of elements

        // Duplicate the array to handle circularity
        for (int i = 0; i < n * 2; ++i) {
            int currNum = nums[i % n]; // Get the actual element from nums
            while (!st.empty() && nums[st.top()] < currNum) {
                ans[st.top()] = currNum; // Update next greater element
                st.pop();
            }
            if (i < n) // Only push indices from the first n elements
                st.push(i);
        }

        return ans;
    }
};
https://leetcode.com/problems/next-greater-element-ii/
