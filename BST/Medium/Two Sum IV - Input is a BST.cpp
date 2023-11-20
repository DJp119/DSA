void inorder(BinaryTreeNode<int>*root,vector<int> &inorderTrav){
    if(root==NULL) return;
    inorder(root->left, inorderTrav);
    inorderTrav.push_back(root->data);
    inorder(root->right, inorderTrav);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderTrav;
    inorder(root, inorderTrav);
    int i=0, j=inorderTrav.size()-1;
    while(i<j){
        int sum=inorderTrav[i]+inorderTrav[j];
        if(sum == target) return true;
        else if(sum>target) j--;
        else i++;
    }
    return false;
}
