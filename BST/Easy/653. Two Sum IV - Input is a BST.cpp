/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
Method 1:
using inorder traversal + applying two pointer approach :

Time Complexity : O(N)
Space Complexity : O(N)
class Solution {
    void inorder(TreeNode* root,vector<int>&ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        int i=0,j=n-1;
        bool value = false;
        while(i<j){
            if(ans[i] + ans[j]==k) {
                value = true; break;
            }
            if(ans[i]+ans[j] < k) i++;
            else j--;
        }
        return value;
    }
};


Inorder Traversal + Reverse Inorder Traversal :

Time Complexity : O(N)
Space Complexity : O(logN)
class Solution{
    public:
    bool findTarget(TreeNode* root,int k){
        stack<TreeNode*> inOrd,revOrd;
        TreeNode* root1=root;
        TreeNode* root2=root;
        while(true){
            while(root1){
                inOrd.push(root1);
                root1=root1->left;
            }
            while(root2){
                revOrd.push(root2);
                root2=root2->right;
            }
            if(inOrd.empty()||revOrd.empty()) return false;
            root1=inOrd.top();
            root2=revOrd.top();
            if(root1->val + root2->val == k){
                if(root1->val == root2->val) return false;
                else return true;
            }
            if(root1->val + root2->val <k){
                inOrd.pop();
                root1=root1->right;    
                root2=nullptr;
            }
            else{
                revOrd.pop();
                root2=root2->left;
                root1=nullptr;
            }
        }
        return false;
    }
};
