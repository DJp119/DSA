void inorder(TreeNode<int> *root, vector<int> &inorderTrav) {
  if (root == NULL)
    return;
  inorder(root->left, inorderTrav);
  inorderTrav.push_back(root->data);
  inorder(root->right, inorderTrav);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
        vector<int> inorderTrav;

        inorder(root, inorderTrav);
        int n=inorderTrav.size();

        TreeNode<int>* newRoot=new TreeNode<int>(inorderTrav[0]);
        TreeNode<int>* curr = newRoot;

        for(int i=1;i<n;i++){
            TreeNode<int>* temp=new TreeNode<int>(inorderTrav[i]);
            curr->left = NULL ;
            curr->right = temp ;
            curr=temp;
        }
        curr->left = NULL;
        curr->right = NULL;
        return newRoot;
}
