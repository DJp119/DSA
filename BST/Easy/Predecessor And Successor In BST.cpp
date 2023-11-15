
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    //    find key
    int pred = -1;
    int succ = -1;

    TreeNode* temp=root;
    // TreeNode<int>* temp = root;
    while(temp&&temp->data != key){
        if(temp->data > key){
            succ=temp->data;
            temp=temp->left;
        }
         else{
            pred=temp->data;
            temp=temp->right;
        }
    }
// pred and succ
    if(temp){
        TreeNode* leftTree = temp->left;
        while(leftTree != NULL){
            pred=leftTree->data;
            leftTree=leftTree->right;
        }
        // succ
        TreeNode* rightTree=temp->right;
        while(rightTree != NULL){
                succ=rightTree->data;
                rightTree=rightTree->left;
        }
    }
return  {pred,succ};
