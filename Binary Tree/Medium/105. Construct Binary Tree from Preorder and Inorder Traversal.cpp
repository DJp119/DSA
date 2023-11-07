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
    TreeNode* helper(vector<int>preorder,vector<int>inorder,int &idx,int left,int right){
        // base condition 
        if(left>right) return NULL;
        int pivot = left;
        while(inorder[pivot]!=preorder[idx]) pivot++;
        idx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = helper(preorder,inorder,idx,left,pivot-1);
        newNode->right = helper(preorder,inorder,idx,pivot+1,right);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // if(inorder.size()==0) return NULL;

        int n = inorder.size();
        int idx = 0;
        return helper(preorder,inorder,idx,0,n-1);
    }
};
