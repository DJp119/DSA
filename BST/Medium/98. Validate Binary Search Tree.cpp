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
class Solution {
    bool helper(TreeNode* root,long long int low,long long int high){
        if(root == NULL) return true;
        if(root->val > low && root->val < high){
            bool left = helper(root->left,low,root->val);
            bool right = helper(root->right,root->val,high);
            return left&&right;
        }
        else return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        // long long int min=-1000000000,max=1000000000;
        long long int min = -1000000000000, max = 1000000000000;
       return helper(root,min,max);
    }
};
