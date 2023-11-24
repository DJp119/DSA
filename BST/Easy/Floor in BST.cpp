int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int floorValue = -1;
    while(root){
        if(root->val==x) return x;
        else if(root->val>x) root=root->left;
        else{
            floorValue=root->val;
            root=root->right;
        } 
    }
    return floorValue;
}
