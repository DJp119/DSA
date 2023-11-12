TC - O(N)
SC - O(N)
int solve(BinaryTreeNode<int>*root,int&i,int k){
    // base case
    if(root==NULL) return -1;
    int left = solve(root->left,i,k);
    if(left != -1) return left;
    i++;
    if(i==k) return root->data;
    return solve(root->right,i,k);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans = solve(root,i,k);
    return ans;
}


//  Morris Traversal 
int morrisTraversal(BinaryTreeNode<int>*root,int k){
    BinaryTreeNode<int>* curNode=root;
    while(curNode != NULL) {
        if(curNode->left == NULL){
            k=k-1;

            if(k==0) return curNode->data;
            curNode=curNode->right;
        }
…                if(k==0) return curNode->data;
                curNode=curNode->right;
            }
        }
    }
    return -1;
}
int kthSmallest(BinaryTreeNode<int>*root,int k){
    return morrisTraversal(root,k);
}
